#include <ctype.h>

int main (void){
	return yyparse ();
}


int yylex(void){
	int c;
	while((c=getchar()) == ' ' || c == '\t') continue;
	if(c=='.' || isdigit(c)){
		ungetc(c, stdin);
		scanf("%lf", &yylval);
		return NUM;
	}
	if(c==EOF){
		return 0;
	}
	return c;
}
void yyerror (char const *s){
	fprintf (stderr, "%s\n", s);
}
