/* Infix notation calculator.  */

%{
    #include <math.h>
    #include <stdio.h>
    int yylex (void);
    void yyerror (char const *);
%}
%define api.value.type {double}
%token NUM
%% /* The grammar follows.  */



input:
     %empty
|    input line
;
line:
    '\n'
|  exp '\n'	{printf("%.10g", $1);}
;
exp:
    NUM             { $$ = $1;           }
    | exp exp '+'   { $$ = $1 + $2;      }
    | exp exp '-'   { $$ = $1 - $2;      }
    | exp exp '*'   { $$ = $1 * $2;      }
    | exp exp '/'   { $$ = $1 / $2;      }
    | exp exp '^'   { $$ = pow ($1, $2); }  /* Exponentiation */
    | exp 'n'       { $$ = -$1;          }  /* Unary minus    */
    ;
%%