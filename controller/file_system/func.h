#ifndef FUNC_FILESYSTEM
#define FUNC_FILESYSTEM

#include <iostream>
#include <stdio.h>
#include <math.h> /* floor */
#include "../../model/structures.h"
#include "../partitions/func.h"
#include "../handler.h"

int searchFreeIndex(char bitmap[], int n);
int startByteSuperBloque(MOUNTED _mounted);
int GetFreePointer(int b_pointers[]);

int _number_inodos(int _part_size) // falta ext3
{
    return (int)floor((_part_size - sizeof(Superbloque) / (1 + 3 + sizeof(InodosTable) + 3 * 64)));
}

bool fileExists(InodosTable _inode, string _filename, FILE *_file, int _start_blocks)
{
    CarpetasBlock file_block;
    for (int i = 0; i < 12; i++) // falta indirectos
    {
        if (_inode.i_block[i] != -1)
        {
            fseek(_file, _start_blocks, SEEK_SET);
            fseek(_file, _inode.i_block[i] * 64, SEEK_CUR);
            fread(&file_block, 64, 1, _file);
            for (int j = 0; j < 4; j++)
            {
                if (string(file_block.b_content[j].b_name) == _filename)
                    return true;
            }
        }
    }
    return false;
}

FolderReference getFather(FolderReference _fr, string _folder, FILE *_file, int _start_inodes, int _start_blocks) // hacerlo recursivo, siempre verificará carpetasblock
{                                                                                                                 // Retorna el los índices de inodo y bloque de la carpeta padre
    InodosTable inode;
    // fseek(_file, _start_inodes, SEEK_SET);
    // fseek(_file, _fr.inode * sizeof(InodosTable), SEEK_CUR);
    // fread(&inode, sizeof(InodosTable), 1, _file);
    CarpetasBlock folder_block;
    fseek(_file, _start_blocks, SEEK_SET);
    fseek(_file, _fr.block * 64, SEEK_CUR);
    fread(&folder_block, 64, 1, _file);

    for (int i = 0; i < 4; i++)
    { // std::cout << folder_block.b_content[k].b_name << std::endl; revisar?
        if (string(folder_block.b_content[i].b_name) == _folder)
        {
            _fr.inode = folder_block.b_content[i].b_inodo;
            fseek(_file, _start_inodes, SEEK_SET);
            fseek(_file, folder_block.b_content[i].b_inodo * sizeof(InodosTable), SEEK_CUR);
            fread(&inode, sizeof(InodosTable), 1, _file);
            for (int j = 0; j < 12; j++)
            {
                if (inode.i_block[j] != -1)
                {
                    fseek(_file, _start_blocks, SEEK_SET);
                    fseek(_file, inode.i_block[j] * 64, SEEK_CUR);
                    fread(&folder_block, 64, 1, _file);
                    if (folder_block.b_content[0].b_inodo == _fr.inode)
                    {
                        _fr.block = inode.i_block[j];
                        return _fr;
                    }
                }
            }
        }
    }
    _fr.inode = -1;
    return _fr;
}

FolderReference getFatherReference(FolderReference _fr, string _folder, FILE *_file, int _start_inodes, int _start_blocks)
{
    // _fr = getFather(_fr, _folder, _file, _start_inodes, _start_blocks); // En caso de que esté en los primeros b_content de la raíz
    // if (_fr.inode != -1)
    //     return _fr;
    FolderReference fr;
    InodosTable inode;
    fseek(_file, _start_inodes, SEEK_SET);
    fseek(_file, _fr.inode * sizeof(InodosTable), SEEK_CUR);
    fread(&inode, sizeof(InodosTable), 1, _file);
    CarpetasBlock folder_block;
    fseek(_file, _start_blocks, SEEK_SET);
    fseek(_file, _fr.block * 64, SEEK_CUR);
    fread(&folder_block, 64, 1, _file);
    for (int i = 0; i < 12; i++)
    {
        if (inode.i_block[i] != -1)
        {
            fseek(_file, _start_blocks, SEEK_SET);
            fseek(_file, inode.i_block[i] * 64, SEEK_CUR);
            fread(&folder_block, 64, 1, _file);
            _fr.block = inode.i_block[i];
            fr = getFather(_fr, _folder, _file, _start_inodes, _start_blocks);
            if (fr.inode != -1)
                return fr;
            // _fr.inode = folder_block.b_content[0].b_inodo;
        }
    }
    fr.inode = -1;
    return fr;
}

int writeBlock(int _type, string _content, int _block_reference)
{
    FILE *file = fopen((_user_logged.mounted.path).c_str(), "rb+");
    int start_byte_sb = startByteSuperBloque(_user_logged.mounted);
    /* Lectura del superbloque */
    Superbloque super_bloque;
    fseek(file, start_byte_sb, SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);
    /* Lectura del bitmap de bloques */
    char bm_block[3 * super_bloque.s_inodes_count];
    fseek(file, super_bloque.s_bm_block_start, SEEK_SET);
    fread(&bm_block, sizeof(3 * super_bloque.s_inodes_count), 1, file);
    /* Posicionarse en el espacio del bloque disponible */
    int block_free = super_bloque.s_first_blo;
    int seek_free = super_bloque.s_block_start + (block_free * 64);
    fseek(file, seek_free, SEEK_SET);
    ArchivosBlock archivo;
    ApuntadoresBlock apuntadores;
    // const char *tmp = _content.c_str();
    char tmp[64];
    switch (_type)
    {
    case 0: //_inode = UpdateInode(super_bloque, _inode, block_free);
        strcpy(tmp, _content.c_str());
        fwrite(&tmp, 64, 1, file);
        // std::cout << "\033[1;33m¿" + string(tmp) + "?\033[0m\n" << seek_free << std::endl;
        break;
    case 1:
        apuntadores.b_pointers[0] = _block_reference; // Apunta a bloque de archivo o carpeta
        fwrite(&apuntadores, 64, 1, file);
        // _inode.i_block[12] = block_free;
        break;
    case 2:
        break;
    case 3:
        break;
    }
    bm_block[block_free] = '1';
    super_bloque.s_first_blo = searchFreeIndex(bm_block, 3 * super_bloque.s_inodes_count);
    super_bloque.s_free_blocks_count--;
    // std::cout << "!" << super_bloque.s_first_blo << "!" << block_free << std::endl;
    fseek(file, start_byte_sb, SEEK_SET);
    fwrite(&super_bloque, sizeof(Superbloque), 1, file);

    fseek(file, super_bloque.s_bm_block_start, SEEK_SET);
    fwrite(&bm_block, 3 * super_bloque.s_inodes_count, 1, file);

    fclose(file);
    file = NULL;

    return block_free; // Retornamos el número de bloque creado
}

void UpdateInode(InodosTable _inode, int _inode_index, int _block_written)
{
    FILE *file = fopen((_user_logged.mounted.path).c_str(), "rb+");
    /* Lectura del superbloque */
    Superbloque super_bloque;
    fseek(file, startByteSuperBloque(_user_logged.mounted), SEEK_SET);
    fread(&super_bloque, sizeof(Superbloque), 1, file);

    bool updated = false;
    int free_pointer = -1;

    for (int i = 0; i < 12; i++)
    {
        if (_inode.i_block[i] == -1)
        {
            _inode.i_block[i] = _block_written;
            updated = true;
            // std::cout << "i:" << i << "block:" << _block_written << std::endl;
            break;
        }
    }
    if (!updated)
    {
        int type = 1;
        for (int i = 12; i < 15; i++)
        {
            if (_inode.i_block[i] == -1)
            {
                _inode.i_block[i] = writeBlock(type, "", _block_written);
                updated = true;
                break;
            }
            else
            { // Falta validar el tipo de apuntador
                ApuntadoresBlock apuntadores;
                fseek(file, super_bloque.s_block_start, SEEK_SET);
                fseek(file, _inode.i_block[i] * 64, SEEK_CUR);
                fread(&apuntadores, sizeof(ApuntadoresBlock), 1, file);
                free_pointer = GetFreePointer(apuntadores.b_pointers);
                if (free_pointer > -1)
                {
                    _inode.i_block[i] = free_pointer;
                    updated = true;
                    break;
                }
            }
            type++;
        }
    }
    if (!updated)
        coutError("Error: no se encontró ningún inodo libre para guardar el contenido", NULL);

    _inode.i_mtime = getCurrentTime();
    // std::cout << "\033[1;31m" + string(ctime(&_inode.i_mtime)) + "\033[0m\n";
    /* Sobreescribir el inodo */
    fseek(file, super_bloque.s_inode_start, SEEK_SET);
    fseek(file, _inode_index * sizeof(InodosTable), SEEK_CUR);
    fwrite(&_inode, sizeof(InodosTable), 1, file);

    fclose(file);
    file = NULL;
}

int startByteSuperBloque(MOUNTED _mounted)
{
    int sb_start;
    switch (_mounted.type)
    {
    case 'P':
        sb_start = _mounted.particion.part_start;
        break;
    case 'L':
        sb_start = _mounted.logica.part_start;
        break;
    default:
        break;
    }
    return sb_start;
}

int GetFreePointer(int b_pointers[]) // Agregar si es un bloque de apuntadores de tipo 1,2,3
{
    for (int i = 0; i < 16; i++)
    {
        if (b_pointers[i] == -1)
            return i;
    }
    return -1;
}

int searchFreeIndex(char bitmap[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (bitmap[i] == '0')
            return i;
    }
    return -1;
}

char charFormat(std::string _format)
{
    char nformat = 'N';
    transform(_format.begin(), _format.end(), _format.begin(), ::tolower);
    if (_format == "fast")
        nformat = 'R'; //rápida
    else if (_format == "full" || _format == "")
        nformat = 'C'; //completa
    else
        std::cout << "Error: parámetro -type no válido: " + std::to_string(nformat) << std::endl;
    return nformat;
}

int _2_or_3fs(std::string _fs)
{
    int nfs = 2;
    transform(_fs.begin(), _fs.end(), _fs.begin(), ::tolower);
    if (_fs == "3fs")
        nfs = 3; //ext3
    return nfs;
}

std::vector<std::string> SplitPath(std::string _path)
{
    std::vector<std::string> spl;
    size_t pos = 0;
    std::string tmp;
    // spl.push_back("/");
    while ((pos = _path.find("/")) != std::string::npos)
    {
        tmp = _path.substr(0, pos);
        if (tmp != "")
            spl.push_back(tmp);
        _path.erase(0, pos + 1);
    }
    if (_path != "")
        spl.push_back(_path);
    return spl;
}

#endif