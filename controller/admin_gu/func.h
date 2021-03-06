#ifndef FUNC_ADMIN_USERS_GROUPS
#define FUNC_ADMIN_USERS_GROUPS

#include <iostream>
#include <string.h>
#include "../../model/structures.h"
#include "../../model/users_groups.h"
#include "../../model/filesystem.h"
#include "../file_system/func.h"

std::string GetAllFile(InodosTable _inode, int _s_block_start, string _path)
{
    FILE *_file = fopen(_path.c_str(), "rb");
    std::string content = "";
    for (int i = 0; i < 12; i++) //agregar indirectos
    {
        if (_inode.i_block[i] != -1)
        {
            ArchivosBlock src;
            fseek(_file, _s_block_start + _inode.i_block[i] * 64, SEEK_SET);
            fread(&src, 64, 1, _file);
            content += std::string(src.b_content);
            // std::cout << _inode.i_block[i] << std::endl;
        }
    }
    fclose(_file);
    _file = NULL;
    return content;
}

int ByteLastFileBlock(InodosTable _inode)
{
    for (int i = 0; i < 15; i++) //falta indirecto
    {
        // std::cout << "\033[1;32m" + std::to_string(_inode.i_block[i]) + "\033[0m\n";
        if (_inode.i_block[i] == -1)
            return _inode.i_block[i - 1] * 64;
    }
    return -1;
}

int numberOfFileBlocks(int _size)
{
    float tmp = static_cast<float>(_size) / 64.0;
    return (int)ceil(tmp);
}

std::vector<std::string> Separate64Chars(std::string _content)
{
    std::vector<std::string> vector_s;
    while (_content.length() >= 64)
    {
        std::string tmp = _content.substr(0, 64);
        vector_s.push_back(tmp);
        _content = _content.substr(64);
    }
    if (_content.length() > 0)
        vector_s.push_back(_content);
    return vector_s;
}

void writeBlocks(std::string _content, int _number_inode)
{
    std::vector<std::string> chars = Separate64Chars(_content);
    for (int i = 0; i < chars.size(); i++) // Por cada iteración crear un bloque de contenido
    {
        int block_written = writeBlock(0, chars[i], -1);
        UpdateInode(_number_inode, block_written);
    }
}

Groups getGroupByName(string _name, InodosTable users_inode, int s_block_start, string _path)
{
    /* Obtener todo el archivo concatenado */
    string content_file = GetAllFile(users_inode, s_block_start, _path);
    Groups group_tmp;
    /* LEER LÍNEA POR LÍNEA EL ARCHIVO USERS.TXT */
    std::istringstream f(content_file);
    string line;
    while (getline(f, line))
    {
        int count = 0;
        for (int i = 0; (i = line.find(',', i)) != std::string::npos; i++)
            count++;
        switch (count)
        {
        case 2:
            group_tmp.GID = std::stoi(line.substr(0, line.find_first_of(',')));
            line = line.substr(line.find_first_of(',') + 1);

            group_tmp.tipo = line.substr(0, line.find_first_of(','))[0];
            line = line.substr(line.find_first_of(',') + 1);

            group_tmp.nombre = line.substr(0, line.find_first_of('\n'));

            if (group_tmp.nombre == _name && group_tmp.GID != 0)
            {
                return group_tmp;
            }
            break;
        default:
            break;
        }
    }
    return group_tmp;
}

Users getUserByName(string _name, int _index_inode, int _s_inode_start, int _s_block_start, string _path)
{
    /* Obtener todo el archivo concatenado */
    string content_file = ReadFile(_index_inode, _s_inode_start, _s_block_start, _path);
    Users user_tmp;
    /* LEER LÍNEA POR LÍNEA EL ARCHIVO USERS.TXT */
    std::istringstream f(content_file);
    string line;
    while (getline(f, line))
    {
        int count = 0;
        for (int i = 0; (i = line.find(',', i)) != std::string::npos; i++)
            count++;
        switch (count)
        {
        case 4:
            user_tmp.UID = std::stoi(line.substr(0, line.find_first_of(',')));
            line = line.substr(line.find_first_of(',') + 1);

            user_tmp.tipo = line.substr(0, line.find_first_of(','))[0];
            line = line.substr(line.find_first_of(',') + 1);

            user_tmp.grupo = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(',') + 1);

            user_tmp.nombre = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(',') + 1);

            user_tmp.contrasena = line.substr(0, line.find_first_of('\n'));

            if (user_tmp.nombre == _name && user_tmp.UID != 0)
            {
                return user_tmp;
            }
            break;
        }
    }
    user_tmp.UID = -1;
    return user_tmp;
}

bool HasPermission(Users _user, InodosTable _inode, int _req)
{
    char u;
    // std::cout << ctime(&_inode.i_ctime) << std::endl;
    /* Usuario root */
    if (_user.nombre == "root")
        return true;
    /* Propietario */
    if (_user.UID == _inode.i_uid)
        u = std::to_string(_inode.i_perm)[0];
    /* Grupo */
    else if (_user.GID == _inode.i_gid)
        u = std::to_string(_inode.i_perm)[1];
    /* Otros */
    else
        u = std::to_string(_inode.i_perm)[2];

    if (u == '7' || u == '0')
        return u == '7';
    switch (_req)
    {
    case 1: // Ejecución
        return u == '1' || u == '3' || u == '5' || u == '7';
    case 2: // Escritura
        return u == '2' || u == '3' || u == '6' || u == '7';
    case 3: // Escritura y ejecución
        return u == '3' || u == '7';
    case 4: // Lectura
        return u == '4' || u == '5' || u == '6' || u == '7';
    case 5: // Lectura y ejecución
        return u == '5' || u == '7';
    case 6: // Lectura y escritura
        return u == '6' || u == '7';
    case 7: // Escritura, lectura y ejecución
        return u == '7';
    default:
        return false;
    }
}

#endif