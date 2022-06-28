/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    INT = 259,
    FLOAT = 260,
    BOOL = 261,
    STRING = 262,
    VOID = 263,
    AND = 264,
    OR = 265,
    LBRACE = 266,
    RBRACE = 267,
    INC = 268,
    DEC = 269,
    ASSIGN = 270,
    ADD_ASSIGN = 271,
    SUB_ASSIGN = 272,
    MUL_ASSIGN = 273,
    QUO_ASSIGN = 274,
    REM_ASSIGN = 275,
    PRINT = 276,
    PRINTLN = 277,
    NEWLINE = 278,
    IF = 279,
    ELSE = 280,
    FOR = 281,
    SEMICOLON = 282,
    COMMA = 283,
    INT_LIT = 284,
    FLOAT_LIT = 285,
    STRING_LIT = 286,
    IDENT = 287,
    BOOL_LIT = 288,
    LOR = 289,
    LAND = 290,
    NEQ = 291,
    LSS = 292,
    LEQ = 293,
    GTR = 294,
    GEQ = 295,
    EQL = 296,
    ADD = 297,
    SUB = 298,
    MUL = 299,
    DIV = 300,
    REMAIN = 301,
    NOT = 302,
    LPAREN = 303,
    RPAREN = 304,
    LBRACK = 305,
    RBRACK = 306
  };
#endif
/* Tokens.  */
#define VAR 258
#define INT 259
#define FLOAT 260
#define BOOL 261
#define STRING 262
#define VOID 263
#define AND 264
#define OR 265
#define LBRACE 266
#define RBRACE 267
#define INC 268
#define DEC 269
#define ASSIGN 270
#define ADD_ASSIGN 271
#define SUB_ASSIGN 272
#define MUL_ASSIGN 273
#define QUO_ASSIGN 274
#define REM_ASSIGN 275
#define PRINT 276
#define PRINTLN 277
#define NEWLINE 278
#define IF 279
#define ELSE 280
#define FOR 281
#define SEMICOLON 282
#define COMMA 283
#define INT_LIT 284
#define FLOAT_LIT 285
#define STRING_LIT 286
#define IDENT 287
#define BOOL_LIT 288
#define LOR 289
#define LAND 290
#define NEQ 291
#define LSS 292
#define LEQ 293
#define GTR 294
#define GEQ 295
#define EQL 296
#define ADD 297
#define SUB 298
#define MUL 299
#define DIV 300
#define REMAIN 301
#define NOT 302
#define LPAREN 303
#define RPAREN 304
#define LBRACK 305
#define RBRACK 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 87 "compiler_hw3.y" /* yacc.c:1909  */

    int i_val;
    float f_val;
    char *s_val;
    /* ... */

#line 163 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
