%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
   
    void yyerror(char *s);
    int yylex();
    
    
    #include "y.tab.c"
    
    int lineno = 1;
    
    


%}
id       [a-zA-Z]+[0-9]*
integer  [0-9]+
hex	 "'"[A-F]?[0-9A-F]+			
%%
EOF       {return EOF_STMT;}      /* end of file */
na        {return ERROR_STMT;}    /* error */
"'1'"       {return ONE;}		/* one '1'  !! puede traer problemas !!*/
"'0'"	  {return ZERO;}	/* zero '0' !! puede traer problemas !!*/
{integer} {numVal = strdup(yytext);
	   return NUMBER;}	/* string of digits */
{hex}     {return HEX;}		/* !! Revisar los HEX !!*/

 /* keywords */
AHPLMODULE   {return AHPLMODULE;}
INPUTS       {return INPUTS;}
EXINPUTS     {return EXINPUTS;}
BUSES        {return BUSES;}
EXBUSES      {return EXBUSES;}
OUTPUTS      {return OUTPUTS;}
MEMORY       {return MEMORY;}
LABELS       {return LABELS;}
CLUNITS      {return CLUNITS;}
BODY         {return BODY;}
NULL         {return NULLSTMT;}
NODELAY      {return NODELAY;}
DEADEND      {return DEADEND;}
ENDSEQUENCE  {return ENDSEQUENCE;}
CONTROLRESET {return CONTROLRESET;}
END          {return END;}
OPTION       {return OPTION;}
CLOCKLIMIT   {return CLOCKLIMIT;}
INITIALIZE   {return INITIALIZE;}
EXLINES      {return EXLINES;}
SUPPRESS     {return SUPPRESS;}
DUMP         {return DUMP;}
ALL          {return ALL;}
REPEAT       {return REPEAT;}
ADD          {return ADD;}
ADDC         {return ADDC;}
INC          {return INC;}
MEMFN        {return MEMFN;}
DCD          {return DCD;}
DEC          {return DEC;}
CMP          {return CMP;}
ASSOC        {return ASSOC;}
 /* end of keywords */



 /* test keywords */
buses    {return buses;}
exbuses  {return exbuses;}
clunits  {return clunits;}


mend         {return mend;}
comsec	     {return comsec;}
 /* end of test keywords*/

 /* operators */
"^"       {clVal = strdup(yytext);
           return NOT;}		/* inverter */
"&"    	  {clVal = strdup(yytext);
           return AND;}		/* and */
"^&"      {clVal = strdup(yytext);
           return NAND;}	/* nand */
"+"	  {clVal = strdup(yytext);
           return OR;}		/* or */
"^+"	  {clVal = strdup(yytext);
           return NOR;}		/* nor */
"@" 	  {clVal = strdup(yytext);
           return XOR;}  	/* xor */
"^@"	  {clVal = strdup(yytext);
           return XNOR;}	/* xnor */
           
"&/"	  {return ANDCR;}	/* and col reduction */
"^&/"	  {return NANDCR;}	/* nand col reduction */
"+/" 	  {return ORCR;}	/* or col reduction */
"^+/"	  {return NORCR;}       /* nor col reduction */
"@/"      {return XORCR;}	/* xor col reduction */
"^@/"	  {return XNORCR;}	/* xnor col reduction */
"&//"	  {return ANDRR;}	/* and row reduction */
"^&//"	  {return NANDRR;}      /* nand row reduction */
"+//"	  {return ORRR;}	/* or row reduction */
"^+//"    {return NORRR;}	/* nor row reduction */
"@//"	  {return XORRR;} 	/* xor row reduction */
"^@//"	  {return XNORRR;} 	/* xnor row reduction */
","       {return COLCAT;}      /* colum catenation */
"*" 	  {return CONDITION;}	/* condition */
"/"	  {return SLASH;}	/* slash */
"=>"	  {return JUMP;}	/* jump */
"="       {return EQUAL;}	/* equal */
"<="      {return TRANSFER;}	/* transfer */
"("       {return LPARENTESIS;} /* left parentesis */
")"	  {return RPARENTESIS;} /* right parentesis */
"[" 	  {return LSQBRACKET;}  /* left square bracket */
"]"	  {return RSQBRACKET;}  /* right square bracket */
"<"	  {return  LABRACKET;}  /* left angle bracket */
">"	  {return  RABRACKET;}  /* right angle bracket */
"{" 	  {return LCBRACE;}     /* left curly brace */
"}"	  {return RCBRACE;}     /* right curly brace */
";"	  {return SEMICOLON;}	/* semicolon */
"$"	  {return ENCODE;}	/* encode */ 
"."	  {return PERIOD;}	/* period */ 
":"	  {return COLON;}	/* colon */
"\\"	  {return BSLASH;}	/* back slash */ 
"!"	  {return option;}	/* option */
"#"	  {return MTIMES;}	/* multiple times */
 /* end of operators */
 
{id}    {idVal = strdup(yytext);
         return id;}            /* string of chars */

 /* white spaces */
\n      lineno++;
[ \t\r]+ ;                      /* ignore whitespaces */
 /* end of white spaces*/

 /* anything else */
.                            yyerror("invalid character");

%%
void yyerror(char *s )
{
	printf("\n%d: %s at %s\n", lineno, s, yytext);
} /* error */
int main(int argc, char **argv)
{
  if(argc > 1 && (yyin = fopen(argv[1], "r")) == NULL)
  {
  	perror(argv[1]);
  	exit(1);
  }
  
  if(!yyparse())
  {
  	printf("\n--AHPL parse Worked\n");
  	AHPL_translate(Module, Module.inputsArray);
  
  }
  else
  { 
  	printf("\nAHPL parse failed\n");
  }
} /*main*/

