%{
#define YYSTYPE int
#include <iostream>
#include <string>
#include <stack>
#include "GF.hpp"
#include "GF_r.hpp"
#define P 1234577

using namespace std;

extern int yylex();
extern int yyparse();
int yyerror(string s);
//tack<string> s;
string s = "";
%}

%token NUM
%token ERR
%left '+' '-'
%left '*' '/'
%precedence NEG
%nonassoc '^'

%%
input:
    | input line
;
line: 
    expr '\n'           {cout << s << endl; cout << $1 << endl; s="";}
    | error '\n' {
        //yyerrok;
        s="";
    }
    
expr:
    NUM                 {$$ = GF($1).GF_to_int(); s+=to_string($1) + " ";}
    | '(' expr ')'      {$$ = $2;}
    | expr '+' expr     {s+='+'; $$ = (GF($1) + GF($3)).GF_to_int();}
    | expr '-' expr     {s+='-'; $$ = (GF($1) - GF($3)).GF_to_int();}
    | expr '^' exp      {s+='^'; $$ = (GF($1) ^ GF($3)).GF_to_int();}
    | expr '/' expr     {
        try {
            s+='/'; $$ = (GF($1) / GF($3)).GF_to_int();
        } catch (const char* msg) {
            cerr << msg << endl;
            YYERROR;
        }
    }
    | expr '*' expr     {s+='*'; $$ = (GF($1) * GF($3)).GF_to_int();}
    | '-' expr          {s+='~' + to_string($2); $$ = (GF(0-$2)).GF_to_int();}
    
;
exp:
    NUM                 {$$ = GF_r($1).GF_r_to_int(); s+=to_string($1) + " ";}
    | '(' exp ')'       {$$ = $2;}
    | exp '+' exp       {s+='+'; $$ = (GF_r($1) + GF_r($3)).GF_r_to_int();}
    | exp '-' exp       {s+='-'; $$ = (GF_r($1) - GF_r($3)).GF_r_to_int();}
    | '-' exp           {s+='~' + to_string($2); $$ = (GF_r(0-$2)).GF_r_to_int();}
    | exp '/' exp       {
        try {
            s+='/'; $$ = (GF_r($1) / GF_r($3)).GF_r_to_int();
        } catch (const char* msg) {
            cerr << msg << endl;
            YYERROR;
        
        }
    }
    | exp '*' exp       {s+='*'; $$ = (GF_r($1) * GF_r($3)).GF_r_to_int();}
;

%%

int yyerror(string s) {	
    return 0;
}

int main()
{
    yyparse();
    return 0;
}