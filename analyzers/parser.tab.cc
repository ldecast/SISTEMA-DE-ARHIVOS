// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 24 "parser.yy"

#include "driver.h"
#include "../model/builder.h"
#include "../controller/bloque.cpp"
#include <iostream>
#include <vector>

std::vector<parametro> parametros;
struct command x;


#line 57 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "parser.yy"
namespace yy {
#line 149 "parser.tab.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  class_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  class_parser::class_parser (parser_driver& driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  class_parser::~class_parser ()
  {}

  class_parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  class_parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  class_parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  class_parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  class_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  class_parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  class_parser::symbol_number_type
  class_parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  class_parser::stack_symbol_type::stack_symbol_type ()
  {}

  class_parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 3: // "tk_EQUAL"
      case 4: // "pr_FIT"
      case 5: // "pr_UNIT"
      case 6: // "pr_PATH"
      case 7: // "pr_SIZE"
      case 8: // "pr_TYPE"
      case 9: // "pr_DELETE"
      case 10: // "pr_NAME"
      case 11: // "pr_ADD"
      case 12: // "pr_ID"
      case 13: // "pr_FS"
      case 14: // "pr_login"
      case 15: // "pr_logout"
      case 16: // "pr_MKGRP"
      case 17: // "pr_RMGRP"
      case 18: // "pr_MKUSR"
      case 19: // "pr_RMUSR"
      case 20: // "pr_USER"
      case 21: // "pr_PWD"
      case 22: // "pr_GRP"
      case 23: // "pr_TOUCH"
      case 24: // "pr_CHMOD"
      case 25: // "pr_CAT"
      case 26: // "pr_RM"
      case 27: // "pr_EDIT"
      case 28: // "pr_REN"
      case 29: // "pr_MV"
      case 30: // "pr_CP"
      case 31: // "pr_MKDIR"
      case 32: // "pr_FIND"
      case 33: // "pr_LOSS"
      case 34: // "pr_RECOVERY"
      case 35: // "pr_R"
      case 36: // "pr_FILEN"
      case 37: // "pr_DEST"
      case 38: // "pr_P"
      case 39: // "pr_CONT"
      case 40: // "pr_UGO"
      case 41: // "pr_STDIN"
      case 42: // "pr_RUTA"
      case 43: // "pr_ROOT"
      case 44: // "pr_MKDISK"
      case 45: // "pr_RMDISK"
      case 46: // "pr_FDISK"
      case 47: // "pr_MOUNT"
      case 48: // "pr_UMOUNT"
      case 49: // "pr_MKFS"
      case 50: // "tk_string_d"
      case 51: // "tk_string_s"
      case 52: // "tk_path"
      case 53: // "pr_exec"
      case 54: // "pr_rep"
      case 55: // "tk_identifier"
      case 56: // "tk_pattern"
      case 57: // "tk_number"
      case 60: // STRING
      case 61: // DATA
      case 69: // PARAM
      case 70: // BOOLEAN_PARAM
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  class_parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 3: // "tk_EQUAL"
      case 4: // "pr_FIT"
      case 5: // "pr_UNIT"
      case 6: // "pr_PATH"
      case 7: // "pr_SIZE"
      case 8: // "pr_TYPE"
      case 9: // "pr_DELETE"
      case 10: // "pr_NAME"
      case 11: // "pr_ADD"
      case 12: // "pr_ID"
      case 13: // "pr_FS"
      case 14: // "pr_login"
      case 15: // "pr_logout"
      case 16: // "pr_MKGRP"
      case 17: // "pr_RMGRP"
      case 18: // "pr_MKUSR"
      case 19: // "pr_RMUSR"
      case 20: // "pr_USER"
      case 21: // "pr_PWD"
      case 22: // "pr_GRP"
      case 23: // "pr_TOUCH"
      case 24: // "pr_CHMOD"
      case 25: // "pr_CAT"
      case 26: // "pr_RM"
      case 27: // "pr_EDIT"
      case 28: // "pr_REN"
      case 29: // "pr_MV"
      case 30: // "pr_CP"
      case 31: // "pr_MKDIR"
      case 32: // "pr_FIND"
      case 33: // "pr_LOSS"
      case 34: // "pr_RECOVERY"
      case 35: // "pr_R"
      case 36: // "pr_FILEN"
      case 37: // "pr_DEST"
      case 38: // "pr_P"
      case 39: // "pr_CONT"
      case 40: // "pr_UGO"
      case 41: // "pr_STDIN"
      case 42: // "pr_RUTA"
      case 43: // "pr_ROOT"
      case 44: // "pr_MKDISK"
      case 45: // "pr_RMDISK"
      case 46: // "pr_FDISK"
      case 47: // "pr_MOUNT"
      case 48: // "pr_UMOUNT"
      case 49: // "pr_MKFS"
      case 50: // "tk_string_d"
      case 51: // "tk_string_s"
      case 52: // "tk_path"
      case 53: // "pr_exec"
      case 54: // "pr_rep"
      case 55: // "tk_identifier"
      case 56: // "tk_pattern"
      case 57: // "tk_number"
      case 60: // STRING
      case 61: // DATA
      case 69: // PARAM
      case 70: // BOOLEAN_PARAM
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  class_parser::stack_symbol_type&
  class_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 3: // "tk_EQUAL"
      case 4: // "pr_FIT"
      case 5: // "pr_UNIT"
      case 6: // "pr_PATH"
      case 7: // "pr_SIZE"
      case 8: // "pr_TYPE"
      case 9: // "pr_DELETE"
      case 10: // "pr_NAME"
      case 11: // "pr_ADD"
      case 12: // "pr_ID"
      case 13: // "pr_FS"
      case 14: // "pr_login"
      case 15: // "pr_logout"
      case 16: // "pr_MKGRP"
      case 17: // "pr_RMGRP"
      case 18: // "pr_MKUSR"
      case 19: // "pr_RMUSR"
      case 20: // "pr_USER"
      case 21: // "pr_PWD"
      case 22: // "pr_GRP"
      case 23: // "pr_TOUCH"
      case 24: // "pr_CHMOD"
      case 25: // "pr_CAT"
      case 26: // "pr_RM"
      case 27: // "pr_EDIT"
      case 28: // "pr_REN"
      case 29: // "pr_MV"
      case 30: // "pr_CP"
      case 31: // "pr_MKDIR"
      case 32: // "pr_FIND"
      case 33: // "pr_LOSS"
      case 34: // "pr_RECOVERY"
      case 35: // "pr_R"
      case 36: // "pr_FILEN"
      case 37: // "pr_DEST"
      case 38: // "pr_P"
      case 39: // "pr_CONT"
      case 40: // "pr_UGO"
      case 41: // "pr_STDIN"
      case 42: // "pr_RUTA"
      case 43: // "pr_ROOT"
      case 44: // "pr_MKDISK"
      case 45: // "pr_RMDISK"
      case 46: // "pr_FDISK"
      case 47: // "pr_MOUNT"
      case 48: // "pr_UMOUNT"
      case 49: // "pr_MKFS"
      case 50: // "tk_string_d"
      case 51: // "tk_string_s"
      case 52: // "tk_path"
      case 53: // "pr_exec"
      case 54: // "pr_rep"
      case 55: // "tk_identifier"
      case 56: // "tk_pattern"
      case 57: // "tk_number"
      case 60: // STRING
      case 61: // DATA
      case 69: // PARAM
      case 70: // BOOLEAN_PARAM
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  class_parser::stack_symbol_type&
  class_parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 3: // "tk_EQUAL"
      case 4: // "pr_FIT"
      case 5: // "pr_UNIT"
      case 6: // "pr_PATH"
      case 7: // "pr_SIZE"
      case 8: // "pr_TYPE"
      case 9: // "pr_DELETE"
      case 10: // "pr_NAME"
      case 11: // "pr_ADD"
      case 12: // "pr_ID"
      case 13: // "pr_FS"
      case 14: // "pr_login"
      case 15: // "pr_logout"
      case 16: // "pr_MKGRP"
      case 17: // "pr_RMGRP"
      case 18: // "pr_MKUSR"
      case 19: // "pr_RMUSR"
      case 20: // "pr_USER"
      case 21: // "pr_PWD"
      case 22: // "pr_GRP"
      case 23: // "pr_TOUCH"
      case 24: // "pr_CHMOD"
      case 25: // "pr_CAT"
      case 26: // "pr_RM"
      case 27: // "pr_EDIT"
      case 28: // "pr_REN"
      case 29: // "pr_MV"
      case 30: // "pr_CP"
      case 31: // "pr_MKDIR"
      case 32: // "pr_FIND"
      case 33: // "pr_LOSS"
      case 34: // "pr_RECOVERY"
      case 35: // "pr_R"
      case 36: // "pr_FILEN"
      case 37: // "pr_DEST"
      case 38: // "pr_P"
      case 39: // "pr_CONT"
      case 40: // "pr_UGO"
      case 41: // "pr_STDIN"
      case 42: // "pr_RUTA"
      case 43: // "pr_ROOT"
      case 44: // "pr_MKDISK"
      case 45: // "pr_RMDISK"
      case 46: // "pr_FDISK"
      case 47: // "pr_MOUNT"
      case 48: // "pr_UMOUNT"
      case 49: // "pr_MKFS"
      case 50: // "tk_string_d"
      case 51: // "tk_string_s"
      case 52: // "tk_path"
      case 53: // "pr_exec"
      case 54: // "pr_rep"
      case 55: // "tk_identifier"
      case 56: // "tk_pattern"
      case 57: // "tk_number"
      case 60: // STRING
      case 61: // DATA
      case 69: // PARAM
      case 70: // BOOLEAN_PARAM
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  class_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  class_parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  class_parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  class_parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  class_parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  class_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  class_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  class_parser::debug_level_type
  class_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  class_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  class_parser::state_type
  class_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  class_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  class_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  class_parser::operator() ()
  {
    return parse ();
  }

  int
  class_parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 3: // "tk_EQUAL"
      case 4: // "pr_FIT"
      case 5: // "pr_UNIT"
      case 6: // "pr_PATH"
      case 7: // "pr_SIZE"
      case 8: // "pr_TYPE"
      case 9: // "pr_DELETE"
      case 10: // "pr_NAME"
      case 11: // "pr_ADD"
      case 12: // "pr_ID"
      case 13: // "pr_FS"
      case 14: // "pr_login"
      case 15: // "pr_logout"
      case 16: // "pr_MKGRP"
      case 17: // "pr_RMGRP"
      case 18: // "pr_MKUSR"
      case 19: // "pr_RMUSR"
      case 20: // "pr_USER"
      case 21: // "pr_PWD"
      case 22: // "pr_GRP"
      case 23: // "pr_TOUCH"
      case 24: // "pr_CHMOD"
      case 25: // "pr_CAT"
      case 26: // "pr_RM"
      case 27: // "pr_EDIT"
      case 28: // "pr_REN"
      case 29: // "pr_MV"
      case 30: // "pr_CP"
      case 31: // "pr_MKDIR"
      case 32: // "pr_FIND"
      case 33: // "pr_LOSS"
      case 34: // "pr_RECOVERY"
      case 35: // "pr_R"
      case 36: // "pr_FILEN"
      case 37: // "pr_DEST"
      case 38: // "pr_P"
      case 39: // "pr_CONT"
      case 40: // "pr_UGO"
      case 41: // "pr_STDIN"
      case 42: // "pr_RUTA"
      case 43: // "pr_ROOT"
      case 44: // "pr_MKDISK"
      case 45: // "pr_RMDISK"
      case 46: // "pr_FDISK"
      case 47: // "pr_MOUNT"
      case 48: // "pr_UMOUNT"
      case 49: // "pr_MKFS"
      case 50: // "tk_string_d"
      case 51: // "tk_string_s"
      case 52: // "tk_path"
      case 53: // "pr_exec"
      case 54: // "pr_rep"
      case 55: // "tk_identifier"
      case 56: // "tk_pattern"
      case 57: // "tk_number"
      case 60: // STRING
      case 61: // DATA
      case 69: // PARAM
      case 70: // BOOLEAN_PARAM
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 120 "parser.yy"
                  {return bloque(x);}
#line 886 "parser.tab.cc"
    break;

  case 4:
#line 124 "parser.yy"
                      {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ().substr(1, yystack_[0].value.as < std::string > ().size() - 2);}
#line 892 "parser.tab.cc"
    break;

  case 5:
#line 125 "parser.yy"
                      {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ().substr(1, yystack_[0].value.as < std::string > ().size() - 2);}
#line 898 "parser.tab.cc"
    break;

  case 6:
#line 128 "parser.yy"
             {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 904 "parser.tab.cc"
    break;

  case 7:
#line 129 "parser.yy"
                  {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 910 "parser.tab.cc"
    break;

  case 8:
#line 130 "parser.yy"
                {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 916 "parser.tab.cc"
    break;

  case 9:
#line 131 "parser.yy"
                      {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 922 "parser.tab.cc"
    break;

  case 10:
#line 132 "parser.yy"
                   {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 928 "parser.tab.cc"
    break;

  case 16:
#line 142 "parser.yy"
                       {x = newCommand("__EXEC",parametros);}
#line 934 "parser.tab.cc"
    break;

  case 17:
#line 145 "parser.yy"
                           {x = newCommand("__MKDISK",parametros);}
#line 940 "parser.tab.cc"
    break;

  case 18:
#line 146 "parser.yy"
                           {x = newCommand("__RMDISK",parametros);}
#line 946 "parser.tab.cc"
    break;

  case 19:
#line 147 "parser.yy"
                          {x = newCommand("__FDISK",parametros);}
#line 952 "parser.tab.cc"
    break;

  case 20:
#line 148 "parser.yy"
                          {x = newCommand("__MOUNT",parametros);}
#line 958 "parser.tab.cc"
    break;

  case 21:
#line 149 "parser.yy"
                           {x = newCommand("__UMOUNT",parametros);}
#line 964 "parser.tab.cc"
    break;

  case 22:
#line 150 "parser.yy"
                         {x = newCommand("__MKFS",parametros);}
#line 970 "parser.tab.cc"
    break;

  case 23:
#line 153 "parser.yy"
                                      {x = newCommand("__LOGIN",parametros);}
#line 976 "parser.tab.cc"
    break;

  case 24:
#line 154 "parser.yy"
                                {x = newCommand("__LOGOUT",parametros);}
#line 982 "parser.tab.cc"
    break;

  case 25:
#line 155 "parser.yy"
                                      {x = newCommand("__MKGRP",parametros);}
#line 988 "parser.tab.cc"
    break;

  case 26:
#line 156 "parser.yy"
                                      {x = newCommand("__RMGRP",parametros);}
#line 994 "parser.tab.cc"
    break;

  case 27:
#line 157 "parser.yy"
                                      {x = newCommand("__MKUSR",parametros);}
#line 1000 "parser.tab.cc"
    break;

  case 28:
#line 158 "parser.yy"
                                      {x = newCommand("__RMUSR",parametros);}
#line 1006 "parser.tab.cc"
    break;

  case 29:
#line 161 "parser.yy"
                              {x = newCommand("__CHMOD",parametros);}
#line 1012 "parser.tab.cc"
    break;

  case 30:
#line 162 "parser.yy"
                                {x = newCommand("__TOUCH",parametros);}
#line 1018 "parser.tab.cc"
    break;

  case 31:
#line 163 "parser.yy"
                              {x = newCommand("__CAT",parametros);}
#line 1024 "parser.tab.cc"
    break;

  case 32:
#line 164 "parser.yy"
                             {x = newCommand("__RM",parametros);}
#line 1030 "parser.tab.cc"
    break;

  case 33:
#line 165 "parser.yy"
                               {x = newCommand("__EDIT",parametros);}
#line 1036 "parser.tab.cc"
    break;

  case 34:
#line 166 "parser.yy"
                                {x = newCommand("__MKDIR",parametros);}
#line 1042 "parser.tab.cc"
    break;

  case 35:
#line 167 "parser.yy"
                              {x = newCommand("__REN",parametros);}
#line 1048 "parser.tab.cc"
    break;

  case 36:
#line 168 "parser.yy"
                             {x = newCommand("__CP",parametros);}
#line 1054 "parser.tab.cc"
    break;

  case 37:
#line 169 "parser.yy"
                             {x = newCommand("__MV",parametros);}
#line 1060 "parser.tab.cc"
    break;

  case 38:
#line 170 "parser.yy"
                               {x = newCommand("__FIND",parametros);}
#line 1066 "parser.tab.cc"
    break;

  case 39:
#line 171 "parser.yy"
                               {x = newCommand("__LOSS",parametros);}
#line 1072 "parser.tab.cc"
    break;

  case 40:
#line 172 "parser.yy"
                                   {x = newCommand("__RECOVERY",parametros);}
#line 1078 "parser.tab.cc"
    break;

  case 41:
#line 175 "parser.yy"
                        {x = newCommand("__REP",parametros);}
#line 1084 "parser.tab.cc"
    break;

  case 42:
#line 178 "parser.yy"
                                     {parametros.push_back({yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()});}
#line 1090 "parser.tab.cc"
    break;

  case 43:
#line 179 "parser.yy"
                             {parametros.push_back({yystack_[0].value.as < std::string > (), "true"});}
#line 1096 "parser.tab.cc"
    break;

  case 44:
#line 180 "parser.yy"
                              {parametros.clear(); parametros.push_back({yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()});}
#line 1102 "parser.tab.cc"
    break;

  case 45:
#line 181 "parser.yy"
                      {parametros.clear(); parametros.push_back({yystack_[0].value.as < std::string > (), "true"});}
#line 1108 "parser.tab.cc"
    break;

  case 46:
#line 184 "parser.yy"
                 {yylhs.value.as < std::string > () = "__SIZE";}
#line 1114 "parser.tab.cc"
    break;

  case 47:
#line 185 "parser.yy"
                 {yylhs.value.as < std::string > () = "__FIT";}
#line 1120 "parser.tab.cc"
    break;

  case 48:
#line 186 "parser.yy"
                  {yylhs.value.as < std::string > () = "__UNIT";}
#line 1126 "parser.tab.cc"
    break;

  case 49:
#line 187 "parser.yy"
                  {yylhs.value.as < std::string > () = "__PATH";}
#line 1132 "parser.tab.cc"
    break;

  case 50:
#line 188 "parser.yy"
                  {yylhs.value.as < std::string > () = "__TYPE";}
#line 1138 "parser.tab.cc"
    break;

  case 51:
#line 189 "parser.yy"
                    {yylhs.value.as < std::string > () = "__DELETE";}
#line 1144 "parser.tab.cc"
    break;

  case 52:
#line 190 "parser.yy"
                  {yylhs.value.as < std::string > () = "__NAME";}
#line 1150 "parser.tab.cc"
    break;

  case 53:
#line 191 "parser.yy"
                 {yylhs.value.as < std::string > () = "__ADD";}
#line 1156 "parser.tab.cc"
    break;

  case 54:
#line 192 "parser.yy"
                {yylhs.value.as < std::string > () = "__ID";}
#line 1162 "parser.tab.cc"
    break;

  case 55:
#line 193 "parser.yy"
                {yylhs.value.as < std::string > () = "__FS";}
#line 1168 "parser.tab.cc"
    break;

  case 56:
#line 194 "parser.yy"
                  {yylhs.value.as < std::string > () = "__RUTA";}
#line 1174 "parser.tab.cc"
    break;

  case 57:
#line 195 "parser.yy"
                  {yylhs.value.as < std::string > () = "__ROOT";}
#line 1180 "parser.tab.cc"
    break;

  case 58:
#line 196 "parser.yy"
                  {yylhs.value.as < std::string > () = "__USER";}
#line 1186 "parser.tab.cc"
    break;

  case 59:
#line 197 "parser.yy"
                 {yylhs.value.as < std::string > () = "__PWD";}
#line 1192 "parser.tab.cc"
    break;

  case 60:
#line 198 "parser.yy"
                 {yylhs.value.as < std::string > () = "__GRP";}
#line 1198 "parser.tab.cc"
    break;

  case 61:
#line 199 "parser.yy"
                 {yylhs.value.as < std::string > () = "__UGO";}
#line 1204 "parser.tab.cc"
    break;

  case 62:
#line 200 "parser.yy"
                  {yylhs.value.as < std::string > () = "__CONT";}
#line 1210 "parser.tab.cc"
    break;

  case 63:
#line 201 "parser.yy"
                   {yylhs.value.as < std::string > () = "__FILEN";}
#line 1216 "parser.tab.cc"
    break;

  case 64:
#line 202 "parser.yy"
                  {yylhs.value.as < std::string > () = "__DEST";}
#line 1222 "parser.tab.cc"
    break;

  case 65:
#line 205 "parser.yy"
                      {yylhs.value.as < std::string > () = "__R";}
#line 1228 "parser.tab.cc"
    break;

  case 66:
#line 206 "parser.yy"
                     {yylhs.value.as < std::string > () = "__R";}
#line 1234 "parser.tab.cc"
    break;

  case 67:
#line 207 "parser.yy"
                         {yylhs.value.as < std::string > () = "__STDIN";}
#line 1240 "parser.tab.cc"
    break;


#line 1244 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  class_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  class_parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char class_parser::yypact_ninf_ = -79;

  const signed char class_parser::yytable_ninf_ = -1;

  const signed char
  class_parser::yypact_[] =
  {
       0,   -79,    51,   -79,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,     4,     5,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,    51,     6,   -79,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,   -79,   -79,     7,   -79,   -49,   -49,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79
  };

  const signed char
  class_parser::yydefact_[] =
  {
       0,     3,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    47,    48,    49,    46,    50,
      51,    52,    53,    54,    55,    58,    59,    60,    65,    63,
      64,    66,    62,    61,    67,    56,    57,    23,     0,    45,
      25,    26,    27,    28,    30,    29,    31,    32,    33,    35,
      37,    36,    34,    38,    39,    40,    17,    18,    19,    20,
      21,    22,    16,    41,     1,     2,     0,    43,     0,     0,
       4,     5,     8,     9,    10,     7,     6,    44,    42
  };

  const short
  class_parser::yypgoto_[] =
  {
     -79,   -79,   -79,   -78,   -79,   -79,   -79,   -79,   -79,   -79,
     145,    38,    65
  };

  const signed char
  class_parser::yydefgoto_[] =
  {
      -1,    28,    96,    97,    29,    30,    31,    32,    33,    34,
      57,    58,    59
  };

  const signed char
  class_parser::yytable_[] =
  {
       1,    90,    91,    92,    84,    85,    93,    94,    95,    88,
      89,    98,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
       0,     0,     0,    26,    27,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,     0,     0,     0,     0,
       0,    45,    46,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    86,     0,     0,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    87,     0,     0,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83
  };

  const signed char
  class_parser::yycheck_[] =
  {
       0,    50,    51,    52,     0,     0,    55,    56,    57,     3,
       3,    89,    -1,    -1,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    53,    54,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    57,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    57,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27
  };

  const signed char
  class_parser::yystos_[] =
  {
       0,     0,    14,    15,    16,    17,    18,    19,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      44,    45,    46,    47,    48,    49,    53,    54,    59,    62,
      63,    64,    65,    66,    67,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    20,    21,    22,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    68,    69,    70,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,     0,     0,    69,    70,     3,     3,
      50,    51,    52,    55,    56,    57,    60,    61,    61
  };

  const signed char
  class_parser::yyr1_[] =
  {
       0,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    62,    62,    62,    62,    62,    63,    64,    64,    64,
      64,    64,    64,    65,    65,    65,    65,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    68,    68,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    70
  };

  const signed char
  class_parser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const class_parser::yytname_[] =
  {
  "\"eof\"", "error", "$undefined", "\"tk_EQUAL\"", "\"pr_FIT\"",
  "\"pr_UNIT\"", "\"pr_PATH\"", "\"pr_SIZE\"", "\"pr_TYPE\"",
  "\"pr_DELETE\"", "\"pr_NAME\"", "\"pr_ADD\"", "\"pr_ID\"", "\"pr_FS\"",
  "\"pr_login\"", "\"pr_logout\"", "\"pr_MKGRP\"", "\"pr_RMGRP\"",
  "\"pr_MKUSR\"", "\"pr_RMUSR\"", "\"pr_USER\"", "\"pr_PWD\"",
  "\"pr_GRP\"", "\"pr_TOUCH\"", "\"pr_CHMOD\"", "\"pr_CAT\"", "\"pr_RM\"",
  "\"pr_EDIT\"", "\"pr_REN\"", "\"pr_MV\"", "\"pr_CP\"", "\"pr_MKDIR\"",
  "\"pr_FIND\"", "\"pr_LOSS\"", "\"pr_RECOVERY\"", "\"pr_R\"",
  "\"pr_FILEN\"", "\"pr_DEST\"", "\"pr_P\"", "\"pr_CONT\"", "\"pr_UGO\"",
  "\"pr_STDIN\"", "\"pr_RUTA\"", "\"pr_ROOT\"", "\"pr_MKDISK\"",
  "\"pr_RMDISK\"", "\"pr_FDISK\"", "\"pr_MOUNT\"", "\"pr_UMOUNT\"",
  "\"pr_MKFS\"", "\"tk_string_d\"", "\"tk_string_s\"", "\"tk_path\"",
  "\"pr_exec\"", "\"pr_rep\"", "\"tk_identifier\"", "\"tk_pattern\"",
  "\"tk_number\"", "$accept", "INICIO", "STRING", "DATA", "E", "EXEC",
  "DISCOS", "ADMIN_USERS_GROUPS", "FILESYSTEM", "REPORT", "PARAMS",
  "PARAM", "BOOLEAN_PARAM", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  class_parser::yyrline_[] =
  {
       0,   120,   120,   121,   124,   125,   128,   129,   130,   131,
     132,   135,   136,   137,   138,   139,   142,   145,   146,   147,
     148,   149,   150,   153,   154,   155,   156,   157,   158,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   175,   178,   179,   180,   181,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   205,   206,   207
  };

  // Print the state stack on the debug stream.
  void
  class_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  class_parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 6 "parser.yy"
} // yy
#line 1718 "parser.tab.cc"

#line 210 "parser.yy"

void yy::class_parser::error(const location_type& lugar, const std::string& lexema)
{
  std::cout << "ERROR SINT??CTICO: " << lexema << std::endl;
  exit(EXIT_FAILURE);
}
