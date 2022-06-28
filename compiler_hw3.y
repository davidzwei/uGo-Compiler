/*	Definition section */
%{

#include "common.h" //Extern variables that communicate with lex
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdio.h>    

// #define YYDEBUG 1
    // int yydebug = 1;

extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

FILE *file;	//for test.j

void yyerror (char const *s)
    {
	printf("error:%d: %s\n", yylineno, s);
    }

/* Symbol table function - you can add new function if needed. */
 //   static void create_symbol();
    static void insert_symbol(char* name,char* types, int type_mode);
    int lookup_symbol(char *id, int flag, int check);
    void dump_symbol();
	static void assign_symbol(int id, double data);

	int is_array = 0;
	int address_num = 0;
	int var_num = 0;
	int scope_flag = 0;
	int print_mode = 0;
	char *string_value;
	char *bool_value;
	int array_mode = 0;
	int for_flag = 0;
	int now_id = 0;
	int declare = 0;
	int pre_id = 0;
	int next_id = 0;
	int mid = 0;

	int print_flag = 0;
	int bool_val;

	int label_num[20] = {0};
	int exit_num[20] = {0};
	//if,for
	int ftype = 0;
	int flabel_num[20] = {0};
	int fexit_num[20] = {0};	
	int fornum = 0;
	int error_count = 0;
//for table
struct data{
	int index;	//0,1,2,3
	char type[10];	//int, float,
	char name[10];	//x,y,z
	int address;
	int lineno;
	char element[10];
	int type_mode;	

//content
	int int_value;
	double dou_value;
	char *str_value[10];
	char bool_val[6];

	int assign_bit;
	int scope;
	int be_dumped;
	//int f_bit;
	}symbol_table[100];

%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    /* ... */
}

/* Token without return */
%token VAR 
%token INT FLOAT BOOL STRING VOID 
%token AND OR  LBRACE RBRACE
%token INC DEC
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN //assign
%token PRINT PRINTLN NEWLINE
%token IF ELSE FOR  
%token SEMICOLON COMMA

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <s_val> IDENT
%token <s_val> BOOL_LIT


/* Nonterminal with return, which need to sepcify type */
%type <i_val> Type INT FLOAT TypeName ArrayType 
%type <f_val> StatementList      
%type <f_val> DeclarationStmt PrintStmt IfStmt
%type <f_val> SimpleStmt IncDecStmt BLOCK AssignmentStmt ConversionExpr
%type <f_val> Expression PrimaryExpr UnaryExpr Forstmt Forclause FBLOCK Formid
%type <f_val> Literal Operand Condition IndexExpr


%left LOR
%left LAND
%left NEQ LSS LEQ GTR GEQ EQL
%left ADD SUB
%left MUL DIV REMAIN
%left NOT
%left LPAREN RPAREN
%left LBRACK RBRACK 



/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : StatementList {;}
;

StatementList
    : StatementList Statement{;}
    | Statement{;}
;

Statement
	:DeclarationStmt NEWLINE 
	|SimpleStmt NEWLINE 
	|BLOCK NEWLINE 
	|PrintStmt NEWLINE
	|IfStmt NEWLINE
	|Forstmt NEWLINE
	|NEWLINE 	
;

DeclarationStmt :
		VAR IDENT Type ASSIGN Expression {
		int temp = lookup_symbol($2, scope_flag, 1);
		if(for_flag > 0)//in f_block
		{
			if( $3 == 1){ 					
				insert_symbol($2, "int32", 1);
				assign_symbol(1, $5);
				//dump_symbol();
			}
			else if( $3 == 2){
				insert_symbol($2, "float32", 2); 
				assign_symbol(1, $5); 
				//dump_symbol();
			}
		}
		else{
		if(temp == -1){ //new value
			//insert_symbol($2, $3); 
			if( $3 == 1){ 					
				insert_symbol($2, "int32", 1);
				int index = lookup_symbol($2, scope_flag, 1);
				fprintf(file,"\tistore %d\n\n", index);
				//dump_symbol();
			}
			else if( $3 == 2){
				insert_symbol($2, "float32", 2); 
				int index = lookup_symbol($2, scope_flag, 1);
				fprintf(file,"\tfstore %d\n\n", index);
				//dump_symbol();
			}
			else if ($3 == 3){
					insert_symbol($2, "string", $3);
					int temp = lookup_symbol($2, scope_flag, 1);
					int index = lookup_symbol($2, scope_flag, 1);
					strcpy(symbol_table[temp].str_value, string_value); 
					//printf("%s\n", symbol_table[temp].str_value );
					fprintf(file,"\tastore %d\n", index);
			}

			else if ($3 == 4){
					insert_symbol($2, "bool", $3); 	
					int temp = lookup_symbol($2, scope_flag, 1);
					strcpy( symbol_table[temp].bool_val, bool_value); 
					symbol_table[temp].int_value = bool_val;
					fprintf(file,"\tistore %d\n\n", temp);
					//printf("%s\n", symbol_table[temp].bool_val );		
			}
/*
			else if( $3 == 1){ 					
				insert_symbol($2, "array", $3);
				assign_symbol(1, $5);
				//dump_symbol();
			}
			else if( $3 == 1){ 					
				insert_symbol($2, "array", $3);
				assign_symbol(1, $5);
				//dump_symbol();
			}
		*/	
		}
		else{
			printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno, $2, symbol_table[temp].lineno);
			error_count++;		
		}
		}
	}
		|VAR IDENT Type {

				int temp = lookup_symbol($2, scope_flag, 1);
				if(temp == -1){
				//error


//no error 
				if( $3 == 1){ 	//int				
					insert_symbol($2, "int32", $3);
					int a = lookup_symbol($2, scope_flag, 1);	
					fprintf(file, "\tldc 0\n"); 
					fprintf(file, "\tistore %d\n\n", a);
				}
				else if( $3 == 2){ //float
					insert_symbol($2, "float32", $3);
					int a = lookup_symbol($2, scope_flag, 1); 
					fprintf(file, "\tldc 0.000000\n");
					fprintf(file, "\tfstore %d\n\n", a);
				}
				else if ($3 == 3){
					insert_symbol($2, "string", $3);
					int a = lookup_symbol($2, scope_flag, 1); 
					fprintf(file, "\tldc \"\"\n");
					fprintf(file, "\tastore %d\n", a);
				}
				else if ($3 == 4){
					insert_symbol($2, "bool", $3);
				}
				else if( $3 == 5){
					insert_symbol($2, "array", $3);
					int a = lookup_symbol($2, scope_flag, 1);
					/*
					fprintf(file, "\tnewarray int\n");*/
					fprintf(file, "\tastore %d\n\n", a);
				}
				else if( $3 == 6){
					insert_symbol($2, "array", $3);
					int a = lookup_symbol($2, scope_flag, 1);
				//	fprintf(file, "\tnewarray float\n");
					fprintf(file, "\tastore %d\n\n", a); 
				}

				}

				else{ //error

				printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",
				yylineno, $2, symbol_table[temp].lineno);
				error_count++;
				}
	}
;

BLOCK:
     	LBRACE {
		scope_flag++ ; 
		//for_flag = 1; 
		} 
	StatementList{ } 
	RBRACE { 
		dump_symbol(); 
		scope_flag-- ; 
		//for_flag = 0; 
		}
;


StatementList : Statement
	      ;



SimpleStmt
	: Expression {;}
	| IncDecStmt {;}
	| AssignmentStmt 
;

AssignmentStmt: Expression { 	
				//int x = (int)$1;
				printf("$1: %f\n", $1);
				if( $1<= 4.0) { fprintf(file,"pop\n");  } 
				mid =1;				
			} 
			ASSIGN Expression 	  { 	
							//assign_symbol($1,0);
							if($1 == 1 ) fprintf(file,"\tistore %d\n\n", pre_id);
							else if($1 == 2) fprintf(file,"\tfstore %d\n\n", pre_id);
							else if($1 == 3) fprintf(file,"\tastore %d\n\n", now_id);
							else if($1 == 4) { fprintf(file,"\tistore %d\n\n", now_id); symbol_table[now_id].int_value = bool_val; }
							else if($1 == 5) fprintf(file,"\tiastore\n\n");
							else if($1 == 6) fprintf(file,"\tfastore\n\n");
//printf("%d %d\n",$1, $4 );
							if( ($1 == 1 && $4 == 2)||($1 == 7 && $4 == 8 )){ 
								printf("error:%d: invalid operation: ASSIGN (mismatched types int32 and float32)\n", yylineno); 
								error_count++;
							}
							printf("ASSIGN\n"); 
							pre_id = 0;
							mid = 0;
						}

		|Expression { mid = 1; } 
			ADD_ASSIGN Expression { 	
							if($1 == 1) 	{ fprintf(file,"\tiadd\n", pre_id); fprintf(file,"\tistore %d\n\n", pre_id);  }
							else if($1 == 2) { fprintf(file,"\tfadd\n", pre_id); fprintf(file,"\tfstore %d\n\n", pre_id); }
							//else if($1 == 3) { fprintf(file,"astore %d\n", pre_id);
							else if($1 == 5) { fprintf(file,"\tiadd\n"); fprintf(file,"\tastore\n\n"); }
							else if($1 == 6) { fprintf(file,"\tfadd\n"); fprintf(file,"\tastore\n\n"); }
							if($1 >6 && $4 ==1){
								printf("error:%d: cannot assign to int32\n", yylineno);
								error_count++;			
							} 
							printf("ADD_ASSIGN\n");
						 }
		|Expression { mid = 1; } 
			SUB_ASSIGN Expression { 	if($1 == 1) 	{ fprintf(file,"isub\n", pre_id); fprintf(file,"istore %d\n", pre_id);  }
							else if($1 == 2) { fprintf(file,"fsub\n", pre_id); fprintf(file,"fstore %d\n", pre_id); }
							//else if($1 == 3) { fprintf(file,"astore %d\n", pre_id);
							else if($1 == 5) { fprintf(file,"isub\n"); fprintf(file,"astore\n"); }
							else if($1 == 6) { fprintf(file,"fsub\n"); fprintf(file,"astore\n"); }
							printf("SUB_ASSIGN\n"); 
						}
		|Expression { mid = 1; }
			 MUL_ASSIGN Expression { if($1 == 1) 	{ fprintf(file,"imul\n", pre_id); fprintf(file,"istore %d\n", pre_id);  }
						else if($1 == 2) { fprintf(file,"fmul\n", pre_id); fprintf(file,"fstore %d\n", pre_id); }
						//else if($1 == 3) { fprintf(file,"astore %d\n", pre_id);
						else if($1 == 5) { fprintf(file,"imul\n"); fprintf(file,"astore\n"); }
						else if($1 == 6) { fprintf(file,"fmul\n"); fprintf(file,"astore\n"); }
						printf("MUL_ASSIGN\n"); 
						}
		|Expression  { mid = 1; }
			QUO_ASSIGN Expression { if($1 == 1) 	{ fprintf(file,"idiv\n", pre_id); fprintf(file,"istore %d\n", pre_id);  }
						else if($1 == 2) { fprintf(file,"fdiv\n", pre_id); fprintf(file,"fstore %d\n", pre_id); }
						//else if($1 == 3) { fprintf(file,"astore %d\n", pre_id);
						else if($1 == 5) { fprintf(file,"idiv\n"); fprintf(file,"astore\n"); }
						else if($1 == 6) { fprintf(file,"fdiv\n"); fprintf(file,"astore\n"); }
						printf("QUO_ASSIGN\n"); 
						}
		|Expression { mid = 1; }
			REM_ASSIGN Expression { if($1 == 1) 	{ fprintf(file,"irem\n", pre_id); fprintf(file,"istore %d\n", pre_id);  }
						else if($1 == 2) { fprintf(file,"frem\n", pre_id); fprintf(file,"fstore %d\n", pre_id); }
						//else if($1 == 3) { fprintf(file,"astore %d\n", pre_id);
						else if($1 == 5) { fprintf(file,"irem\n"); fprintf(file,"astore\n"); }
						else if($1 == 6) { fprintf(file,"frem\n"); fprintf(file,"astore\n"); }
						printf("REM_ASSIGN\n"); 
						}
;

Expression : UnaryExpr
	   | Expression ADD Expression	{ 
					  if( ($1 == 1 && $3 == 2)||($1 == 7 && $3 == 8 )){ 
						printf("error:%d: invalid operation: ADD (mismatched types int32 and float32)\n", yylineno); 
						error_count++;
					}
					else if($1 ==2 && $3 == 1){
						printf("error:%d: invalid operation: ADD (mismatched types int32 and float32)\n", yylineno); 
						error_count++;					
					}
					if( $1 == 1 || $1 == 7 || $1 == 5){
						fprintf(file,"\tiadd\n");
					}
					if( $1 == 2 || $1 == 8 || $1 == 6){
						fprintf(file,"\tfadd\n");
					}

printf("ADD\n"); 
					$$ = $1;
					}
	| Expression SUB Expression	{ 
					if($1 == 1 && $3 == 2){ 
						printf("error:%d: invalid operation: SUB (mismatched types int32 and float32)\n", yylineno); 
						error_count++;
					}
					else if($1 ==2&&$3 == 1){
						printf("error:%d: invalid operation: SUB (mismatched types float32 and int32)\n", yylineno); 
						error_count++;
					}
					if( $1 == 1 || $1 == 7 || $1 == 5){
						fprintf(file,"\tisub\n");
					}
					if( $1 == 2 || $1 == 8 || $1 == 6){
						fprintf(file,"\tfsub\n");
					}
					printf("SUB\n");
					$$ = $1;
					}
	| Expression MUL Expression	{ printf("MUL\n");
					//printf("%f\n", $1);
					//printf("%f\n", $3);
					int a = (int)($1*$3);
					//printf("%d\n", a);
					a = a%2;
					if( a == 1 ){//int
						fprintf(file,"\timul\n");
						$$ = 1;		
					}
					if( a == 0 ){ //float
						fprintf(file,"\tfmul\n");
						$$ = 2;
					} 

}
	| Expression DIV Expression	{ 
					printf("QUO\n"); 
					int a = (int)($1*$3);
					$$ = $1;
					//printf("%d\n", a);
					a = a%2;
					
						if( a == 1 ){
						fprintf(file,"\tidiv\n");
						}
						else if( a == 0){
						fprintf(file,"\tfdiv\n");
						}
					
					}
	| Expression REMAIN Expression	{ 
					if( ($1 == 2 || $3 == 2)){ 
						printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno); 
						error_count++;
						}
					fprintf(file,"\tirem\n");
					printf("REM\n");  }

	| Expression EQL Expression	{ 
					printf("EQL\n"); 
					$$ = 10; 
					print_mode = 10;
					if($1==1|$1==5|$1==7) fprintf(file,"\tisub\n");
					else if($1==2|$1==6|$1==8) { fprintf(file,"\tfsub\n"); fprintf(file,"\tf2i\n"); }

					fprintf(file,"\tifeq Label_%d%d\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_0\n");
					fprintf(file,"\tgoto Exit_%d%d\n", scope_flag, exit_num[scope_flag]);
					fprintf(file,"Label_%d%d:\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_1\n");
					fprintf(file,"Exit_%d%d:\n\n", scope_flag, exit_num[scope_flag]);
					label_num[scope_flag]++;
					exit_num[scope_flag]++;
					}
	| Expression NEQ Expression	{ 
					printf("NEQ\n"); 
					$$ = 10;
					print_mode = 10;
					fprintf(file,"\tisub\n");
					fprintf(file,"\tifne L_cmp_0\n");
					fprintf(file,"\ticonst_0\n");
					fprintf(file,"\tgoto L_cmp_1\n");
					fprintf(file,"L_cmp_0:\n");
					fprintf(file,"\ticonst_1\n");
					fprintf(file,"L_cmp_1:\n\n");
					}
	| Expression GTR Expression	{ printf("GTR\n"); 
					$$ = 10;
					print_mode = 10;
				//	if($1 == 1.0 || $1 == 7.0 ){
					if($1==1|$1==5|$1==7) fprintf(file,"\tisub\n");
					else if($1==2|$1==6|$1==8) { fprintf(file,"\tfsub\n"); fprintf(file,"\tf2i\n"); }
					fprintf(file,"\tifgt Label_%d%d\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_0\n");
					if(fornum) fprintf(file,"\tgoto For_exit%d\n", fornum);
					else fprintf(file,"\tgoto Exit_%d%d\n", scope_flag, exit_num[scope_flag]);
					fprintf(file,"Label_%d%d:\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_1\n");
					fprintf(file,"Exit_%d%d:\n\n", scope_flag, exit_num[scope_flag]);
					label_num[scope_flag]++;
					exit_num[scope_flag]++;
				//	}
					}
	| Expression LSS Expression	{ printf("LSS\n"); 
					$$ = 10;
					print_mode = 10;
				//	if($1 == 1.0 || $1 == 7.0 ){
					if($1==1|$1==5|$1==7) fprintf(file,"\tisub\n");
					else if($1==2|$1==6|$1==8) { fprintf(file,"\tfsub\n"); fprintf(file,"\tf2i\n"); }
					fprintf(file,"\tiflt Label_%d%d\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_0\n");
					fprintf(file,"\tgoto Exit_%d%d\n", scope_flag, exit_num[scope_flag]);
					fprintf(file,"Label_%d%d:\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_1\n");
					if( !fornum )fprintf(file,"Exit_%d%d:\n\n", scope_flag, exit_num[scope_flag]);
					label_num[scope_flag]++;
					exit_num[scope_flag]++;	
					}
	| Expression LEQ Expression	{ printf("LEQ\n"); 
					$$ = 10;
					print_mode = 10;
				//	if($1 == 1.0 || $1 == 7.0 ){
					if($1==1|$1==5|$1==7) fprintf(file,"\tisub\n");
					else if($1==2|$1==6|$1==8) { fprintf(file,"\tfsub\n"); fprintf(file,"\tf2i\n"); }
					fprintf(file,"\tifle Label_%d%d\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_0\n");
					fprintf(file,"\tgoto Exit_%d%d\n", scope_flag, exit_num[scope_flag]);
					fprintf(file,"Label_%d%d:\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_1\n");
					if( !fornum ) fprintf(file,"Exit_%d%d:\n\n", scope_flag, exit_num[scope_flag]);
					label_num[scope_flag]++;
					exit_num[scope_flag]++;	
					}
	| Expression GEQ Expression	{ printf("GTR\n"); 
					$$ = 10;
					print_mode = 10;
				//	if($1 == 1.0 || $1 == 7.0 ){
					if($1==1|$1==5|$1==7) fprintf(file,"\tisub\n");
					else if($1==2|$1==6|$1==8) { fprintf(file,"\tfsub\n"); fprintf(file,"\tf2i\n"); }
					fprintf(file,"\tifge Label_%d%d\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_0\n");
					if(fornum) fprintf(file,"\tgoto For_exit%d\n", fornum);
					else fprintf(file,"\tgoto Exit_%d%d\n", scope_flag, exit_num[scope_flag]);
					fprintf(file,"Label_%d%d:\n", scope_flag, label_num[scope_flag]);
					fprintf(file,"\ticonst_1\n");
					fprintf(file,"Exit_%d%d:\n\n", scope_flag, exit_num[scope_flag]);
					label_num[scope_flag]++;
					exit_num[scope_flag]++;
				//	}
					}
	| Expression LAND Expression	{ if($1 == 1 || $3 == 1 || $1 == 7 || $3 == 7){ 
						printf("error:%d: invalid operation: (operator LAND not defined on int32)\n", yylineno); 
						error_count++;
						}
					if($1 == 2 || $3 == 2 || $1 == 8 || $3 == 8){ 
						printf("error:%d: invalid operation: (operator LAND not defined on float32)\n", yylineno); 
						error_count++;				
					}
					//printf("%f  %f\n",$1,$3);
					$$ = 10;					
					print_mode = 10;					
					printf("LAND\n");
					
					fprintf(file, "\tiand\n");
					 }
	| Expression LOR Expression	{ if($1 == 1 || $3 == 1  || $1 == 7 || $3 == 7){ 
						printf("error:%d: invalid operation: (operator LOR not defined on int32)\n", yylineno);
						error_count++;
					 }
					if($1 == 2 || $3 == 2  || $1 == 8 || $3 == 8){ 
						printf("error:%d: invalid operation: (operator LOR not defined on float32)\n", yylineno); 
						error_count++;
					}
					//printf("%f  %f\n",$1,$3);
					$$ = 10;					
					print_mode = 10;
					printf("LOR\n"); 
					
					fprintf(file, "\tior\n");
					}
	| LPAREN Expression RPAREN 	{ $$ = $2;}
;

UnaryExpr : PrimaryExpr { $$ = $1; }
	  |ADD UnaryExpr	{ printf("POS\n"); $$ = $2;}
	|SUB UnaryExpr	{ printf("NEG\n"); $$ = $2; 
			printf("%f\n", $2); 
			if((int)$2 == 1 | (int)$2 == 7) { fprintf(file, "\tineg\n"); }
			if((int)$2 == 2 | (int)$2 == 8 ) { fprintf(file, "\tfneg\n"); }
			}
	|NOT UnaryExpr	{ printf("NOT\n"); $$ = $2; 
			 fprintf(file, "\ticonst_1\n");
			fprintf(file, "\tixor\n"); }
;

PrimaryExpr : Operand 	{ $$ = $1; }
	    | ConversionExpr { $$ = $1; }
		| IndexExpr	
;
IndexExpr :PrimaryExpr LBRACK Expression RBRACK { $$ = $1;
		if(mid == 1 ){
			if($1 == 5) fprintf(file, "\tiaload\n");
			if($1 == 6) fprintf(file, "\tfaload\n"); 
		}
	 }
	  ;

Operand : Literal 	{ $$ = $1;}
	| IDENT		{//printf("enter ident"); 
				int temp = lookup_symbol($1, scope_flag, 2);
				now_id = temp;
				if(mid == 0)	pre_id = now_id;			

				if(temp == -1){
					printf("error:%d: undefined: %s\n", yylineno+1, $1);
					error_count++;				
				}

			else{

				if(symbol_table[temp].type_mode == 1){
					//printf("xcvxcv\n");
					//$$ = symbol_table[temp].int_value;
					$$ = 1;
					printf("IDENT (name=%s, address=%d)\n", symbol_table[temp].name, symbol_table[temp].address);
					print_mode = 1;
					fprintf(file, "\tiload %d\n", temp);                	  	
				}
				else if(symbol_table[temp].type_mode == 2){
					printf("IDENT (name=%s, address=%d)\n", symbol_table[temp].name, symbol_table[temp].address);

					$$ = 2;
					print_mode = 2;
					fprintf(file, "\tfload %d\n", temp);                	  	
				}
				else if(symbol_table[temp].type_mode == 3){
					printf("IDENT (name=%s, address=%d)\n", symbol_table[temp].name, symbol_table[temp].address);
					$$ = 3;
					print_mode = 3;
					fprintf(file, "\taload %d\n", temp);
				}
				else if(symbol_table[temp].type_mode == 4){
					printf("IDENT (name=%s, address=%d)\n", symbol_table[temp].name, symbol_table[temp].address);
					$$ = 4;
					print_mode = 4;
					if(print_flag) { 
						if(symbol_table[temp].int_value == 1) fprintf(file, "\ticonst_1\n");
						else fprintf(file, "\ticonst_0\n");
					}
					else{ fprintf(file, "\tiload %d\n", temp); }
				}
				else if(symbol_table[temp].type_mode == 5){
					printf("IDENT (name=%s, address=%d)\n", symbol_table[temp].name, symbol_table[temp].address);
					$$ = 5;
					print_mode = 5; 
					array_mode = 1; 
					fprintf(file, "\taload %d\n", temp);
					//fprintf(file, "swap\n");
					//fprintf(file, "\tiaload\n");              	  	
				}
				else if(symbol_table[temp].type_mode == 6){
					printf("IDENT (name=%s, address=%d)\n", symbol_table[temp].name, symbol_table[temp].address);
					$$ = 6;
					print_mode = 6;                	  	
					array_mode = 2;	
					fprintf(file, "\taload %d\n", temp);
			
				}
				}

}
;

Literal : 
	INT_LIT 	{ $$ = 7; printf("INT_LIT %d\n", $1); 
				print_mode = 1; 
				fprintf(file, "\tldc %d\n", (int)$1); }

| FLOAT_LIT 	{ $$ = 8; printf("FLOAT_LIT %.6f\n", $1); 	
				print_mode = 2; 	
				fprintf(file, "\tldc %f\n", $1); }
	| STRING_LIT	{ $$ = 9; printf("STRING_LIT %s\n", $1); 
			string_value = strdup($1); 
			print_mode = 3; 
			fprintf(file, "\tldc \"%s\"\n", string_value);
			}
	| BOOL_LIT 	{ $$ = 10; print_mode = 4; 

//printf("%s\n", $1);
			bool_value = strdup($1);
			if(strcmp($1,"true") == 0) { fprintf(file, "\ticonst_1\n"); bool_val =1; }
			else if( strcmp($1,"false") == 0) { fprintf(file, "\ticonst_0\n"); bool_val = 0; }
			}
;

ConversionExpr:Type LPAREN Expression RPAREN	{
	     				 	if($1 == 1) {
							if(print_mode == 2){
								printf("F to I\n");
								fprintf(file, "\tf2i\n");
							}
						} 
						else if($1 == 2) {
							if(print_mode == 1 ){
								printf("I to F\n"); 
								fprintf(file, "\ti2f\n");
							}
						}
						$$ = $1;
					}
;

Condition:
	Expression { 
	if($1 == 1 || $1 == 7) { printf("error:%d: non-bool (type int32) used as for condition\n", yylineno+1); error_count++; }
	if($1 == 2 || $1 == 8) { printf("error:%d: non-bool (type float32) used as for condition\n", yylineno+1);  error_count++;}
}
;

FBLOCK:
      	LBRACE { 
		scope_flag++ ; for_flag++;  
		if( ftype == 1) {
			fprintf(file,	"\tifeq FExit_%d%d\n", scope_flag, fexit_num[for_flag]);
			//fprintf(file,	"\tgoto FExit_%d%d\n", for_flag, fexit_num[for_flag]);
		}
		if( ftype == 2) {
			fprintf(file,	"\tifeq FLable_%d%d\n", for_flag, flabel_num[for_flag]);
			//fprintf(file,	"\tgoto FExit_%d%d\n", for_flag, fexit_num[for_flag]);
		}
		/*
		if( fornum ) {
			fprintf(file,	"\tifeq For_exit%d\n", fornum);
		}
		*/
			
	} 
	StatementList 
	RBRACE {
		if( ftype == 1) { 
		fprintf(file,	"FExit_%d%d:\n", for_flag, exit_num[for_flag]);
		}
		if( ftype == 2) {
			//fprintf(file,	"\tifeq FLable_%d%d\n", for_flag, flabel_num[for_flag]);
			//fprintf(file,	"\tgoto FExit_%d%d\n", for_flag, fexit_num[for_flag]);
		}
		exit_num[for_flag]++;
		dump_symbol(); scope_flag-- ; for_flag--; 
	}
;


IfStmt:IF Condition { ftype = 1; } FBLOCK {
		//fprintf(file,	"\tifeq FLabel_%d%d\n", scope_flag, label_num[scope_flag]);
		
		
		printf("%d\n", ftype);	
		//fprintf(file,	"FLabel_%d%d:\n", scope_flag, label_num[scope_flag]);
		

	//	fprintf(file,	"FExit_%d%d:\n", for_flag, exit_num[for_flag]);
	//	exit_num[for_flag]++;
	}
      	| IF Condition { ftype = 21; } FBLOCK ELSE  { ftype = 22; } FBLOCK  { printf("%d\n", ftype); }
	| IF Condition { ftype = 3; } FBLOCK ELSE IfStmt  { printf("%d\n", ftype); }
;

Forstmt: 
	|FOR 
	{
		printf("hi\n"); 
	
		fornum++;
		fprintf(file,	"For_begin%d:\n", fornum);
		printf("%d\n", fornum); 
	} 
	Formid

;
Formid:
	Condition 
	FBLOCK 	{ 
		fprintf(file,	"\tgoto For_begin%d\n", fornum); 
		fprintf(file,	"For_exit%d:\n", fornum);
		fornum--;
		}
	
	|Forclause { fprintf(file, "Fblock_%d:\n", fornum); }
	FBLOCK
	{
		fprintf(file,	"\tgoto For_action%d\n", fornum); 
		fprintf(file,	"Exit_%d%d:\n", scope_flag, exit_num[scope_flag]-1);
		fornum--;
		exit_num[scope_flag]++;
	}
;

Forclause : 
	SimpleStmt SEMICOLON { fprintf(file, "For_semi%d:\n", fornum); } 
	Condition { } SEMICOLON 
	{
	fprintf(file, "\tgoto Fblock_%d\n", fornum);
	fprintf(file, "For_action%d:\n", fornum); 
	} 
	SimpleStmt { fprintf(file, "\tgoto For_semi%d\n", fornum); }
; 

PrintStmt: PRINT LPAREN { print_flag++; mid = 1; } 
		Expression RPAREN {
						 	
					if(print_mode == 1)	{ 
	 						if(array_mode == 2){ printf("PRINT float32\n"); 
							fprintf(file,   "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/print(F)V\n" );
							}						
							else{
							printf("PRINT int32\n");
							fprintf(file,   "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/print(I)V\n" );	

} 
						}
					else if(print_mode == 2){
							printf("PRINT float32\n"); 
							fprintf(file,   "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/print(F)V\n" );	
							} 

					else if(print_mode == 3 | print_mode ==9){ printf("PRINT string\n"); }
					else if(print_mode == 4 | print_mode == 10){ 
						printf("PRINT bool\n"); 
						
						fprintf(file,	"\tifne Label_%d%d\n", scope_flag, label_num[scope_flag]);
						fprintf(file,	"\tldc \"false\"\n" );
						fprintf(file,	"\tgoto Exit_%d%d\n", scope_flag, exit_num[scope_flag]);
						
						fprintf(file,	"Label_%d%d:\n", scope_flag, label_num[scope_flag]);
						fprintf(file,	"\tldc \"true\"\n");

						fprintf(file,	"Exit_%d%d:\n", scope_flag, exit_num[scope_flag]);
						fprintf(file,	"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
						fprintf(file,	"\tswap\n");
						fprintf(file,	"\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n\n");									
						
						label_num[scope_flag]++;
						exit_num[scope_flag]++;					
						}
						print_flag--;
						mid = 0; 
					;
			}
|PRINTLN LPAREN { print_flag++; mid = 1; } Expression RPAREN { printf("print_mode: %d\n", print_mode);	
						if(print_mode == 1)	{ 
							if(array_mode == 2){ 
								printf("PRINTLN float32\n"); 
								fprintf(file,   "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
										"\tswap\n"
										"\tinvokevirtual java/io/PrintStream/println(F)V\n\n" );
							}						
							else{ printf("PRINTLN int32\n");
								fprintf(file,   "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
										"\tswap\n"
										"\tinvokevirtual java/io/PrintStream/println(I)V\n\n" );	
							} 
						}
						else if(print_mode == 2){ 
							printf("PRINTLN float32\n");
							fprintf(file,   "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									 "\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(F)V\n\n" );
						 }
						else if(print_mode == 3 | print_mode == 9){ 
							printf("PRINTLN string\n"); 
							fprintf(file,   "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
									"\tswap\n"
									"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n\n" );
						}
						else if(print_mode == 4 | print_mode == 10){ printf("PRINTLN bool\n");
							fprintf(file,	"\tifne Label_%d%d\n", scope_flag, label_num[scope_flag]);
							fprintf(file,	"\tldc \"false\"\n" );
							fprintf(file,	"\tgoto Exit_%d%d\n", scope_flag, exit_num[scope_flag]);
						
							fprintf(file,	"Label_%d%d:\n", scope_flag, label_num[scope_flag]);
							fprintf(file,	"\tldc \"true\"\n");
	
							fprintf(file,	"Exit_%d%d:\n", scope_flag, exit_num[scope_flag]);
							fprintf(file,	"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
							fprintf(file,	"\tswap\n");
							fprintf(file,	"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n\n");									
						
						label_num[scope_flag]++;
						exit_num[scope_flag]++;				
						 }
						print_flag--;
						mid  = 0 ;
					;}
;
IncDecStmt : Expression INC	{ printf("INC\n");  //has error

if($1 == 1 || $1 == 7){

fprintf(file, "\tldc 1\n");
				fprintf(file, "\tiadd\n");
				fprintf(file, "\tistore %d\n", now_id);               			
				}
				else if($1 == 2 || $1 == 8){

fprintf(file, "\tldc 1.000000\n");
				fprintf(file, "\tfadd\n");
				fprintf(file, "\tfstore %d\n", now_id);
				}


} 
	   | Expression DEC	{ printf("DEC\n"); 
				if($1 == 1 || $1 == 7){

fprintf(file, "\tldc 1\n");
				fprintf(file, "\tisub\n");
				fprintf(file, "\tistore %d\n", now_id);      
				}
				else if($1 == 2 || $1 == 8){

fprintf(file, "\tldc 1.000000\n");
				fprintf(file, "\tfsub\n");
				fprintf(file, "\tfstore %d\n", now_id);      
				}		
			}
;
Type : TypeName 	{ $$ = $1; }
     |ArrayType	{ $$ = $1; }
;

TypeName 
	: INT 		{ $$ = 1; }
	| FLOAT 	{ $$ = 2; }
	| STRING 	{ $$ = 3; }
	| BOOL		{ $$ = 4; }
;

ArrayType: LBRACK Expression RBRACK Type { 
					if($4 == 1) {
					$$ = 5 ;
			 		fprintf(file, "\tnewarray int\n");
					}

					if($4 == 2) {
					$$ = 6; 
					fprintf(file, "\tnewarray float\n");
					}
}
%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
	yyin = fopen(argv[1], "r");
    } else {
	yyin = stdin;
    }

	file = fopen("hw3.j","w");
	fprintf(file,   
		    ".source hw3.j\n"  
		    ".class public Main\n"
		    ".super java/lang/Object\n"
		    ".method public static main([Ljava/lang/String;)V\n"
		    ".limit stack %d\n"
		    ".limit locals %d\n", 100, 100);


	yylineno = 0;
    	yyparse();

	dump_symbol();
	printf("Total lines: %d\n", yylineno);


	fprintf(file,   "\treturn\n"
			    ".end method\n");
	fclose(file);
    	fclose(yyin);
    	
	if(error_count>0){
		remove("hw3.j");
	}
	return 0;
}
/*
static void create_symbol() {
}
*/
static void assign_symbol(int type, double data)
{/*
    if(type == 1){        

fprintf(file,"\tistore %d\n", id);
    }

else if(type == 2){


fprintf(file,"\tistore %d\n", id);

}
	else if(type == 5){


fprintf(file,"\tiastore %d\n", id);

}
	else if(type == 6){


fprintf(file,"\tfastore %d\n", id);

}
	*/

}
//inset
static void insert_symbol(char* name, char* types, int type_modes) {
	printf("> Insert {%s} into symbol table (scope level: %d)\n", name, scope_flag);
	strcpy(symbol_table[var_num].type, types);
	strcpy(symbol_table[var_num].name, name);
	strcpy(symbol_table[var_num].element, "-");
	symbol_table[var_num].address = address_num;
	symbol_table[var_num].lineno = yylineno;

symbol_table[var_num].type_mode = type_modes;

//	symbol_table[var_num].assign_bit = 0;
	symbol_table[var_num].scope = scope_flag;

if(type_modes == 5) { strcpy(symbol_table[var_num].type, "array"); strcpy(symbol_table[var_num].element,"int32");} 

if(type_modes == 6) { strcpy(symbol_table[var_num].type, "array"); strcpy(symbol_table[var_num].element,"float32");}
	//printf("insert completion");
	address_num++;
	var_num++;
	//f_bit = for_flag;
}

//lookup symbol
int lookup_symbol(char* id, int flag, int check) {
	int i;
	int temp = flag;
	
	if(for_flag == 0 ){ 
		if(check == 1){//when declare
			for(i = 0; i < var_num; i++){
			if(strcmp(symbol_table[i].name, id) == 0 && symbol_table[i].scope == temp && symbol_table[i].be_dumped == 0){//same scope
			//printf("%d",i);
			return i;
			}
			}
		}
		if(check == 2){ //normal
			for(i = var_num-1 ; i >=0; i--){
			if(strcmp(symbol_table[i].name, id) == 0 && symbol_table[i].scope <= temp && symbol_table[i].be_dumped == 0 ){
			//printf("%d",i);
			return i;
			}
			}
		}
		
	}
	else if(for_flag > 0){//fblock
		for(i = var_num-1 ; i >=0; i--){
			if(strcmp(symbol_table[i].name, id) == 0 && symbol_table[i].scope <= temp && symbol_table[i].be_dumped == 0 ){
			//printf("%d",i);
			return i;
			}
		}
	}

	return -1;
}

void dump_symbol() {
	int i, index = 0;
    printf("> Dump symbol table (scope level: %d)\n", scope_flag);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
	   "Index", "Name", "Type", "Address", "Lineno", "Element type");
	for(i = 0; i < var_num; i++){
		if(symbol_table[i].scope == scope_flag && symbol_table[i].be_dumped == 0){

printf("%-10d%-10s%-10s%-10d%-10d%s\n",
			index, symbol_table[i].name, symbol_table[i].type, symbol_table[i].address, symbol_table[i].lineno, symbol_table[i].element);
		index++;
		symbol_table[i].be_dumped = 1;		
		}	
	}
}




