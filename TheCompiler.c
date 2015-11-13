#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//------------------------------------------------------------------------------
// DECLARATION DES CLASSES DES TOKENS
//------------------------------------------------------------------------------
typedef enum{
true , false 
}boolean;


typedef enum{
PROGRAM_TOKEN , CONST_TOKEN , VAR_TOKEN , BEGIN_TOKEN , END_TOKEN , IF_TOKEN , THEN_TOKEN , WHILE_TOKEN , DO_TOKEN ,
READ_TOKEN , WRITE_TOKEN ,PV_TOKEN , PT_TOKEN , PLUS_TOKEN , MOINS_TOKEN , MULT_TOKEN , DIV_TOKEN , VIR_TOKEN , AFF_TOKEN ,
INF_TOKEN ,INFEG_TOKEN , SUP_TOKEN , SUPEG_TOKEN ,EOF_TOKEN , DIFF_TOKEN , PO_TOKEN , PF_TOKEN , FIN_TOKEN , ID_TOKEN , NUM_TOKEN , ERREUR_TOKEN , EG_TOKEN
}CODES_LEX;

typedef enum{
PROGRAM_ERROR , CONST_ERROR , VAR_ERROR , BEGIN_ERROR , ID_NUM_EXPR , END_ERROR , IF_ERROR , THEN_ERROR , WHILE_ERROR , DO_ERROR ,CONST_VAR_BEGIN_ERR,
READ_ERROR , WRITE_ERROR ,PV_ERROR , PT_ERROR , PLUS_ERROR , MOINS_ERROR , MULT_ERROR , DIV_ERROR , VIR_ERROR , AFF_ERROR ,VAR_BEGIN_ERR,
INF_ERROR ,INFEG_ERROR , FACT_ERROR  , CONDITION_ERROR , INSTR_ERROR , SUP_ERROR , SUPEG_ERROR ,EOF_ERROR , DIFF_ERROR , PO_ERROR , PF_ERROR , FIN_ERROR , ID_ERROR , NUM_ERROR ,EG_ERROR
}CODES_ERROR_LEX;


typedef struct{
CODES_LEX token_enum ; char mot_cle[25] ;
}mots_cle;



mots_cle tab_mots_cle[11] = {{PROGRAM_TOKEN , "program"} , {CONST_TOKEN , "const"} , {BEGIN_TOKEN , "begin"} , {END_TOKEN , "end"} , {IF_TOKEN , "if"} , {THEN_TOKEN , "then"} ,{VAR_TOKEN , "var"} , {WHILE_TOKEN , "while"} ,{DO_TOKEN , "do"} ,{READ_TOKEN , "read"} , {WRITE_TOKEN , "write"}};

/* Global Variablr */
FILE * source_code ;
int current_char ;
CODES_LEX symb_suiv();
CODES_LEX current_token ;
boolean follow_token = false ;
void si();
void tantque();
void ecrire();
void read();
void cond();
void vars();
void fact();
void term();
void expr();
void affec();
void inst();
void insts();
void consts();   
void block();
void program();
boolean Test_Symbole(CODES_LEX token_code , CODES_ERROR_LEX error_code);

void give_me_my_token(CODES_LEX code )
{

switch(code)
{
        case PROGRAM_TOKEN:
            printf("PROGRAM_TOKEN\n");
            break ;
        case NUM_TOKEN:
            printf("NUM_TOKEN\n") ;
            break ;
        case CONST_TOKEN:
            printf("%c\n",current_char);
            printf("CONST_TOKEN\n");
            break ;
        case VAR_TOKEN:
            printf("VAR_TOKEN\n");
            break ;
            case BEGIN_TOKEN:
            printf("BEGIN_TOKEN\n");
            break ;
        case END_TOKEN:
            printf("END_TOKEN\n");
            break ;
        case IF_TOKEN:
            printf("IF_TOKEN\n");
            break ;
        case THEN_TOKEN:
            printf("THEN_TOKEN\n");
            break ;
        case WHILE_TOKEN:
            printf("WHILE_TOKEN\n");
            break ;
        case DO_TOKEN:
            printf("DO_TOKEN\n");
            break ;
        case READ_TOKEN:
            printf("READ_TOKEN\n");
            break ;
        case WRITE_TOKEN:
            printf("WRITE_TOKEN\n");
            break ;
         case EOF_TOKEN:
            printf("EOF_TOKEN\n");
            break ;
          case ID_TOKEN:
            printf("ID_TOKEN\n");
            break ;
          case ERREUR_TOKEN :
            printf("ERREUR_TOKEN\n");
            break ;
         case PV_TOKEN :
            printf("PV_TOKEN\n");
            break;
         case PT_TOKEN:
            printf("PT_TOKEN\n");
            break ;
         case PLUS_TOKEN :
            printf("PLUS_TOKEN\n");
            break ;
         case MOINS_TOKEN:
            printf("MOINS_TOKEN\n");
            break ;
         case  MULT_TOKEN:
           printf("MULT_TOKEN\n");
           break ;
           case DIV_TOKEN :
           printf("DIV_TOKEN\n");
           break ;
           case VIR_TOKEN :
           printf("VIR_TOKEN\n");
           break;
           case AFF_TOKEN :
           printf("AFF_TOKEN\n");
           break ;
           case INF_TOKEN :
           printf("INF_TOKEN\n");
           break ;
           case INFEG_TOKEN:
           printf("INFEG_TOKEN\n");
           break;
           case SUP_TOKEN:
           printf("SUP_TOKEN\n");
           break;
           case SUPEG_TOKEN:
           printf("SUPEG_TOKEN\n");
           break;
           case DIFF_TOKEN :
           printf("DIFF_TOKEN\n");
           break ;
           case PO_TOKEN:
           printf("PO_TOKEN\n");
           break;
           case PF_TOKEN:
           printf("PF_TOKEN\n");
           break;
           case FIN_TOKEN:
            printf("FIN_TOKEN\n");
            break;
            case EG_TOKEN :
            printf("EG_TOKEN\n");
            break ;

}
}


                                                /**
                                                *
                                                *       Fonction recherche_error_msg
                                                *
                                                **/

void recherche_error_msg(CODES_ERROR_LEX code)
{
switch(code)
{
        case PROGRAM_ERROR:
                printf("PROGRAM_ERROR\n");
                break ;
        case NUM_ERROR:
                printf("NUM_ERROR\n") ;
                break ;
        case CONST_ERROR:
                printf("CONST_ERROR\n");
                break ;
        case VAR_ERROR:
                printf("VAR_ERROR\n");
                break ;
        case BEGIN_ERROR:
                printf("BEGIN_ERROR\n");
                break ;
        case END_ERROR:
                printf("END_ERROR\n");
                break ;
        case IF_ERROR:
                printf("IF_ERROR\n");
                break ;
        case THEN_ERROR:
                printf("THEN_ERROR\n");
                break ;
        case WHILE_ERROR:
                printf("WHILE_ERROR\n");
                break ;
        case DO_ERROR:
                printf("DO_ERROR\n");
                break ;
        case READ_ERROR:
                printf("READ_ERROR\n");
                break ;
        case WRITE_ERROR:
                printf("WRITE_ERROR\n");
                break ;
         case EOF_ERROR:
                printf("EOF_ERROR\n");
                break ;
          case ID_ERROR:
                printf("ID_ERROR\n");
                break ;
         case PV_ERROR :
                printf("PV_ERROR\n");
                break;
         case PT_ERROR:
                printf("PT_ERROR\n");
                break ;
         case PLUS_ERROR :
                printf("PLUS_ERROR\n");
                break ;
         case MOINS_ERROR:
                printf("MOINS_ERROR\n");
                break ;
         case  MULT_ERROR:
               printf("MULT_ERROR\n");
               break ;
           case DIV_ERROR :
               printf("DIV_ERROR\n");
               break ;
           case VIR_ERROR :
               printf("VIR_ERROR\n");
               break;
           case AFF_ERROR :
               printf("AFF_ERROR\n");
               break ;
           case INF_ERROR :
               printf("INF_ERROR\n");
               break ;
           case INFEG_ERROR:
               printf("INFEG_ERROR\n");
               break;
           case SUP_ERROR:
               printf("SUP_ERROR\n");
               break;
           case SUPEG_ERROR:
               printf("SUPEG_ERROR\n");
               break;
           case DIFF_ERROR :
               printf("DIFF_ERROR\n");
               break ;
           case PO_ERROR:
               printf("PO_ERROR\n");
               break;
           case PF_ERROR:
               printf("PF_ERROR\n");
               break;
           case FIN_ERROR:
                printf("FIN_ERROR\n");
                break;
            case EG_ERROR :
                printf("EG_ERROR\n");
                break ;
            case CONST_VAR_BEGIN_ERR :
                printf("CONST_VAR_BEGIN_ERR\n");
                break ;
            case VAR_BEGIN_ERR :
                printf("VAR_BEGIN_ERR\n");
                break ; 
            case FACT_ERROR :
                printf("FACT_ERROR\n");  
                break ; 
            case CONDITION_ERROR :
                printf("CONDITION_ERROR\n");
                break;    
            case INSTR_ERROR :
                printf("INSTR_ERROR\n");
                break ;    
}
}




                                                /**
                                                *
                                                *       Fonction recherche_enum
                                                *
                                                **/
CODES_LEX recherche_enum(CODES_LEX code )
{

switch(code)
{
        case PROGRAM_TOKEN:
            //give_me_my_token(current_token);
            return PROGRAM_TOKEN ;
            break ;
        case NUM_TOKEN:
            //give_me_my_token(current_token);
            return NUM_TOKEN ;
            break ;
        case CONST_TOKEN:
            //give_me_my_token(current_token);
            return CONST_TOKEN ;
            break ;
        case VAR_TOKEN:
            //give_me_my_token(current_token);
            return VAR_TOKEN ;
            break ;
        case BEGIN_TOKEN:
            //give_me_my_token(current_token);
            return BEGIN_TOKEN ;
            break ;
        case END_TOKEN:
            //give_me_my_token(current_token);
            return END_TOKEN ;
            break ;
        case IF_TOKEN:
            //give_me_my_token(current_token);
            return IF_TOKEN ;
            break ;
        case THEN_TOKEN:
            //give_me_my_token(current_token);
            return THEN_TOKEN ;
            break ;
        case WHILE_TOKEN:
            //give_me_my_token(current_token);
            return WHILE_TOKEN ;
            break ;
        case DO_TOKEN:
            //give_me_my_token(current_token);
            return DO_TOKEN ;
            break ;
        case READ_TOKEN:
            //give_me_my_token(current_token);
            return READ_TOKEN ;
            break ;
        case WRITE_TOKEN:
            //give_me_my_token(current_token);
            return WRITE_TOKEN ;
            break ;
         case EOF_TOKEN:
            //give_me_my_token(current_token);
            return EOF_TOKEN ;
            break ;
         case ID_TOKEN:
            //give_me_my_token(current_token);
            return ID_TOKEN ;
            break ;
         case ERREUR_TOKEN :
            //give_me_my_token(current_token);
            return ERREUR_TOKEN ;
            break ;
         case PV_TOKEN :
            //give_me_my_token(current_token);
            return PV_TOKEN ;
            break;
         case PT_TOKEN:
            //give_me_my_token(current_token);
            return PT_TOKEN ;
            break ;
         case PLUS_TOKEN :
            //give_me_my_token(current_token);
            return PLUS_TOKEN ;
            break ;
         case MOINS_TOKEN:
            //give_me_my_token(current_token);
            return MOINS_TOKEN ;
            break ;
         case  MULT_TOKEN:
            //give_me_my_token(current_token);
            return MULT_TOKEN ;
            break ;
           case DIV_TOKEN :
            //give_me_my_token(current_token);
            return DIV_TOKEN ;
            break ;
           case VIR_TOKEN :
            //give_me_my_token(current_token);
            return VIR_TOKEN ;
            break;
           case AFF_TOKEN :
            //give_me_my_token(current_token);
            return AFF_TOKEN ;
            break ;
           case INF_TOKEN :
                //give_me_my_token(current_token);
             return INF_TOKEN ;
             break ;
           case INFEG_TOKEN:
                //give_me_my_token(current_token);
                return INFEG_TOKEN ;
                break;
           case SUP_TOKEN:
                //give_me_my_token(current_token);
              return SUP_TOKEN ;
           break;
           case SUPEG_TOKEN:
                //give_me_my_token(current_token);
               return SUPEG_TOKEN ;
           break;
           case DIFF_TOKEN :
                //give_me_my_token(current_token);
              return DIFF_TOKEN ;
           break ;
           case PO_TOKEN:
                //give_me_my_token(current_token);
              return PO_TOKEN ;
           break;
           case PF_TOKEN:
                //give_me_my_token(current_token);
              return PF_TOKEN ;
           break;
           case FIN_TOKEN:
                //give_me_my_token(current_token);
               return FIN_TOKEN ;
            break;
            case EG_TOKEN :
                //give_me_my_token(current_token);
               return EG_TOKEN ;
            break ;

}
}



                                                        /**
                                                        *
                                                        *       Fonction rechercher_token
                                                        *
                                                        **/
CODES_LEX rechercher_token(char mot_courant[25])
{
int j = 0 ;
while(j <= 10)
{
	if(strcmp(mot_courant ,tab_mots_cle[j].mot_cle) == 0)
		{
            return recherche_enum(tab_mots_cle[j].token_enum);
		}

	else
		{
			j++ ;
		}
}
return recherche_enum(ID_TOKEN) ;
}


 														/**
                                                        *
                                                        *       Fonction lire_mot()
                                                        *
                                                        **/
CODES_LEX lire_mot()
{
	char mot[25] ;
	int indice = 0 ;
	mot[indice] = (char)current_char ;
	indice++ ;

	current_char = fgetc(source_code);
	while(1)
	{
			if((current_char >= 65 && current_char <= 90) ||  (current_char <= 122 && current_char >= 97) ||  (current_char <= 57 && current_char >= 48))		
			{			
						mot[indice] = (char)current_char ;
						indice++ ;
						current_char = fgetc(source_code);
			}
			else
			{			
                        mot[indice] = '\0';
                        fseek(source_code, -1, SEEK_CUR);
                        return rechercher_token(mot);
                        break ;
			}

	}
}


 														/**
                                                        *
                                                        *       Fonction lire_nombre()
                                                        *
                                                        **/
CODES_LEX lire_nombre()
{


	while(current_char <= 57 && current_char >= 48)
    {
        current_char = fgetc(source_code);
    }

    if((char)current_char != ')' && (char)current_char != ')' && (char)current_char != ' ' &&(char)current_char != '{' && (char)current_char != '+' && (char)current_char != '-' && (char)current_char != '*' && (char)current_char != '/' && (char)current_char != ' '  && (char)current_char != 0  && (char)current_char != '\t' && (char)current_char != '\n' && (char)current_char != '<' && (char)current_char != '>' && (char)current_char != '=' && current_char != 13 && (char)current_char != ';')
    {	 
        return recherche_enum(ERREUR_TOKEN);
        /*
        Skip Current Token .
        */
        while((char)current_char != ' ' && (char)current_char != '\t' && (char)current_char != '\n')
        {
            current_char = fgetc(source_code);
        }

      /* In the case  , u want to exit the program .
        exit(0);
      */

    }
    else
    {   fseek(source_code, -1, SEEK_CUR);
        return recherche_enum(NUM_TOKEN);
        return ;
    }

}
 														/**
                                                        *
                                                        *       Fonction symb_suiv()
                                                        *
                                                        **/

CODES_LEX symb_suiv()
{
while((char )current_char == ' ' || (char )current_char == '\n' || (char )current_char == '\t' || current_char == 13)
{	  
    current_char = fgetc(source_code);
}

int ch1 = current_char ;
int i = 0 ;
int ch2 = fgetc(source_code);
if((char)ch1 == '{' && (char)ch2 == '*')
                {   
                    ch1 = fgetc(source_code);
                    ch2 = fgetc(source_code);
                    while(1)
                    {   
                        if((char)ch1 == '*' && (char)ch2 == '}')
                        {
                            current_char =  fgetc(source_code);
                            break;                          
                        }
                        else
                        {   i++;

                            ch1 = ch2 ;
                            ch2 = fgetc(source_code);                            
                        }
                    }   
                }
else
{
    fseek(source_code, -1, SEEK_CUR);
}                    




if((char)current_char == EOF)
{
	return recherche_enum(EOF_TOKEN);
	exit(1);
}
if((current_char >= 65 && current_char <= 90) || (current_char <= 122 && (int)current_char>= 97))
{	
	return lire_mot();
}
else {
	if(current_char <= 57 && current_char >= 48)
            {
                return lire_nombre();
            }

	else{
            /** Special char **/
            switch((char)current_char)
            {
                case  ';':
                {
                return recherche_enum(PV_TOKEN);
                break ;
                }
                case  '.':
                {
                return recherche_enum(PT_TOKEN);
                break ;
                }
                case '+':
                {
                return recherche_enum(PLUS_TOKEN);
                break ;
                }
                case '-':
                {
                return recherche_enum(MOINS_TOKEN);
                break ;
                }
                case '*':
                {
                return recherche_enum(MULT_TOKEN);
                break ;
            	}
                case '/':
                {
                return recherche_enum(DIV_TOKEN);
                break ;
            	}
                case ':':
                {
                current_char = fgetc(source_code);
                if((char)current_char == '=' )
                {
                return recherche_enum(AFF_TOKEN);
                }
                else
                return recherche_enum(ERREUR_TOKEN);
                break;
                }
                case '=':
                {
                return recherche_enum(EG_TOKEN);
                break ;
                }
                case ',':
                {
                return recherche_enum(VIR_TOKEN);
                break ;}
                case '<':
                {
                current_char = fgetc(source_code);
                if((char)current_char == '=' )
                {
                return recherche_enum(INFEG_TOKEN);
                }
                else if((char)current_char == '>')
                {
                fseek(source_code, -1, SEEK_CUR);
                return recherche_enum(DIFF_TOKEN);
                break;
            	}
                else
                return recherche_enum(INF_TOKEN);
                break ;
                }
                case '>':
                {
                current_char = fgetc(source_code);
                if((char)current_char == '=' )
                {
                return recherche_enum(SUPEG_TOKEN);                
                }
                else
                {
                fseek(source_code, -1, SEEK_CUR);
                return recherche_enum(SUP_TOKEN);
                }
                break ;
                }
                case ')':
                {
                return recherche_enum(PF_TOKEN);
                break;
                }
                case '(':
                {
                return recherche_enum(PO_TOKEN);
                break ;
                }
                default:
                return recherche_enum(ERREUR_TOKEN);
       }}
    }   

}



/******************* SI ::= if COND then INST ******************/
void si()
{
    Test_Symbole(IF_TOKEN , IF_ERROR);
    cond();
    Test_Symbole(THEN_TOKEN , THEN_ERROR);
    inst();
}
/**************** TANTQUE ::= while COND do INST ***************/
void tantque()
{
    Test_Symbole(WHILE_TOKEN , WHILE_ERROR);
    cond();
    Test_Symbole(DO_TOKEN , DO_ERROR);
    inst();
}
/****************** ECRIRE : write ( EXPR { , EXPR } ) **************/
void write()
{
    Test_Symbole(WRITE_TOKEN , WRITE_ERROR);
    Test_Symbole(PO_TOKEN , PO_ERROR);
    expr();
    while(current_token == VIR_TOKEN)
    {   
      current_char = fgetc(source_code);
      current_token = symb_suiv();
        expr();
    }
    Test_Symbole( PF_TOKEN ,PF_ERROR);
}
/******************** LIRE ::= read ( ID { , ID } ) ***********/
void read()
{   
    Test_Symbole(READ_TOKEN , READ_ERROR);
    Test_Symbole(PO_TOKEN , PO_ERROR) ;
    Test_Symbole(ID_TOKEN , ID_ERROR); 
    while( current_token == VIR_TOKEN)
    {   
        current_char = fgetc(source_code);
        current_token = symb_suiv();
        Test_Symbole(ID_TOKEN , ID_ERROR);       
    }
    Test_Symbole(PF_TOKEN , PF_ERROR) ;
}
/*************** COND : EXPR [= | <> | < | > | <= | >=] EXPR **********/
void cond()
{
    expr();
    if(current_token  == EG_TOKEN || current_token  ==  DIFF_TOKEN || current_token  ==  INF_TOKEN || current_token  ==  INFEG_TOKEN || current_token  == SUP_TOKEN   || current_token  == SUPEG_TOKEN)
    {   
        current_char = fgetc(source_code);
        current_token = symb_suiv();
        expr();
    }
    else
    {
        recherche_error_msg(CONDITION_ERROR);
        exit(1);
    }
}
/********************* VARS :=var ID { , ID } ; | epsilon *******************/
void vars()
{
 /*   if(follow_token == true) // IF VAR_TOKEN IS NOT READ BEFORE 
    {
        current_token = VAR_TOKEN ;
        follow_token = false ;
    }
*/
    switch(current_token)
    {   
        case (VAR_TOKEN):
            current_char = fgetc(source_code);
            current_token = symb_suiv();
            Test_Symbole(ID_TOKEN , ID_ERROR) ;
            while(current_token == VIR_TOKEN)
            {
                current_char = fgetc(source_code);
                current_token = symb_suiv();
                Test_Symbole(ID_TOKEN , ID_ERROR);
            }
            Test_Symbole(PV_TOKEN , PV_ERROR);
            break ;
        case (BEGIN_TOKEN):
            break ;
        default:
            recherche_error_msg(VAR_ERROR);
            exit(1);
    }
}
/*** FACT ::= ID | NUM | ( EXPR ) **************/
void fact()
{
    switch (current_token)
    {   
        case ID_TOKEN :
            current_char = fgetc(source_code);
            current_token = symb_suiv();
            //give_me_my_token(current_token);
            break;
        case NUM_TOKEN :
            current_char = fgetc(source_code);
            current_token = symb_suiv();
            break ;
        case PO_TOKEN :
            current_char = fgetc(source_code);
            current_token = symb_suiv();
            expr();
            Test_Symbole(PF_TOKEN , PF_ERROR);
            break ;
        default :
            //give_me_my_token(current_token);
            //printf("----%c",current_char);
            recherche_error_msg(FACT_ERROR);
            exit(1); 
    }             
}
/****************** TERM ::= FACT { [* | /] FACT } ************/
void term()
{   //give_me_my_token(current_token);
    fact();
    while(current_token == MULT_TOKEN || current_token == DIV_TOKEN)
    {   
        current_char = fgetc(source_code);
        current_token = symb_suiv();
        fact();            
    }
}
/*************** EXPR ::= TERM { [+ | -] TERM }**************/
void expr()
{
    term();
    while(current_token == PLUS_TOKEN || current_token == MOINS_TOKEN)
    {
        current_char = fgetc(source_code);
        current_token = symb_suiv();
        term();            
    }
}
/********************* AFFEC ::= ID := EXPR *************/
void affec()
{   
    Test_Symbole(AFF_TOKEN , AFF_ERROR);
    expr();
}
/**************** INST ::= INSTS | AFFEC | SI | TANTQUE | ECRIRE | LIRE | epsilon *******/
void inst()
{
    switch(current_token)
    {
        case BEGIN_TOKEN :
            follow_token = true ;
            current_char = fgetc(source_code);
            current_token = symb_suiv();
            insts();
            break ;
        case ID_TOKEN :
            current_char = fgetc(source_code);
            current_token = symb_suiv();
            affec();
            break ;
        case IF_TOKEN :
            si();
            break ;
        case WHILE_TOKEN :
            tantque();
            break ;
        case WRITE_TOKEN :
            write();
            break ;
        case READ_TOKEN :
            read();
        case END_TOKEN :
            break ; 
        case PV_TOKEN :
            break ;
        default :
            //give_me_my_token(current_token);
            recherche_error_msg(INSTR_ERROR);
            exit(1);
    }
}
/************** INSTS := begin INST { ; INST }end ************/
void insts()
{
    if(follow_token == false)
    {
        Test_Symbole(BEGIN_TOKEN , BEGIN_ERROR);
        follow_token = true ;
    }
    inst();
    while(current_token == PV_TOKEN)
    { 
        current_char = fgetc(source_code);
        current_token = symb_suiv();  
        inst();
    }
    //give_me_my_token(current_token);
    //printf("----%c\n",current_char);
    Test_Symbole(END_TOKEN , END_ERROR);
}
/****************** CONSTS ::= const ID = NUM ; { ID = NUM ; } | epsilon **************/
void consts()   
{
    switch(current_token)
    {
        case CONST_TOKEN :
                current_char = fgetc(source_code);
                current_token = symb_suiv();
                Test_Symbole(ID_TOKEN , ID_ERROR);
                Test_Symbole(EG_TOKEN , EG_ERROR );
                Test_Symbole(NUM_TOKEN , NUM_ERROR);
                Test_Symbole(PV_TOKEN , PV_ERROR) ;
                while( current_token == ID_TOKEN)
                {    
                    current_char = fgetc(source_code);
                    current_token = symb_suiv();
                    Test_Symbole(EG_TOKEN , EG_ERROR );
                    Test_Symbole(NUM_TOKEN , NUM_ERROR);                    
                    Test_Symbole(PV_TOKEN , PV_ERROR) ;
                }                            
                break ;
        case VAR_TOKEN :
                //follow_token = true ;
                break ;
        case BEGIN_TOKEN :
                //follow_token  = false ;
                break ; 
        default :
                recherche_error_msg(CONST_VAR_BEGIN_ERR);
                exit(1);
    }
}
/************************ BLOCK  ::= CONSTS VARS INSTS  ********************/
void block()
{

    consts();
    vars();
    insts();
}
/************************ PROGRAM ::= program ID ; BLOCK. ********************/
void program()
{
    Test_Symbole(PROGRAM_TOKEN , PROGRAM_ERROR);
    Test_Symbole(ID_TOKEN , ID_ERROR);
    Test_Symbole(PV_TOKEN , PV_ERROR) ;
    block();
    Test_Symbole(PT_TOKEN , PT_ERROR);
}

/**************** TestSymbole **************/
boolean Test_Symbole(CODES_LEX token_code , CODES_ERROR_LEX error_code)
{
    if(token_code == current_token)
    {
        current_char = fgetc(source_code);
        current_token = symb_suiv();
        return true ;
    }
    else
    {   
        recherche_error_msg(error_code);
        exit(1);
    }
}


int main(int argc , char *argv[])
{     
  	source_code = fopen(argv[1] , "r");
  	if(source_code == NULL)
  	{
  	    printf("Oops , Error opening the file .\n");
  	    return(-1);
  	}
        current_char = fgetc(source_code);
        current_token = symb_suiv();	    
        
        program(); // Start
        if(current_token == EOF_TOKEN)
        {
            printf("Bravo,Votre Programme Est Correct !!\n");
        }    	

        // recherche_enum(EOF_TOKEN);*/
    	fclose(source_code);
    	return 0;
}
