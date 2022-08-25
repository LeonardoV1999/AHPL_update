#include "module.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define char_long 50

char *copyArray(ModuleFlag* MF ,char *array, Mcom* Module, int row, int col, char *idVal)
{  
   char* copyA = 0;                 //se crea siempre que se usa la funcion
   int copyNum = 0; 
   /* copiar y llenar los arreglos con las cualidades de las entradas */
   if(MF->inputF == true)
   {
   	if(MF->rowF==false && MF->colF ==false)
   	{
	  Module->inputsE = true; 
	  copyA = idVal;
	  Module->inputs[Module->inputsNum] = copyA;
	  printf("\n%s\n", Module->inputs[Module->inputsNum]);
	  printf("\nrows = %d ; col = %d\n", row, col);
	  array = copyA;
	  //
	  Module->inputsNum++;
	  MF->inputF = false;
        }else if(MF->rowF==true && MF->colF ==false)
   	      {
	        Module->inputsE = true;
	        copyA = idVal;
	        Module->inputs[Module->inputsNum] = copyA;
	        printf("\n%s\n", Module->inputs[Module->inputsNum]);
	        printf("\nrows = %d ; col = %d\n", row, col);
	        array = copyA;
	        Module->RowCol_inputs[Module->inputsNum][0] = row;
	        Module->RowCol_inputs[Module->inputsNum][1] = col;
	        Module->inputsNum++;
	        MF->inputF = false;
              }else if(MF->rowF==true && MF->colF ==true)
   	            {
	              Module->inputsE = true;
	              copyA = idVal;
	              Module->inputs[Module->inputsNum] = copyA;
	              printf("\n%s\n", Module->inputs[Module->inputsNum]);
	              printf("\nrows = %d ; col = %d\n", row, col);
	              array = copyA;
	              Module->RowCol_inputs[Module->inputsNum][0] = row;
	              Module->RowCol_inputs[Module->inputsNum][1] = col;
	              Module->inputsNum++;
	              MF->inputF = false;
                    }
      MF->inputF = false;
    }/* copiar y llenar los arreglos con las cualidades de las entradas externas */
     /*else if(MF->exinputF == true)
           {
	       if(MF->rowF==false && MF->colF ==false)
	   	{
		  Module->exinputsE = true; 
		  copyA = idVal;
		  Module->exinputs[Module->exinputsNumR][Module->exinputsNumC] = copyA;
		  printf("\n%s\n", Module->exinputs[Module->exinputsNumR][Module->exinputsNumC]);
		  printf("\nrows = %d ; col = %d\n", row, col);
		  array = copyA;
		  Module->exinputsNumR++;
		  MF->exinputF = false;
		}else if(MF->rowF==true && MF->colF ==false)
	   	      {
			Module->exinputsE = true;
			copyA = idVal;
			Module->exinputs[Module->exinputsNum][0] = copyA;
			printf("\n%s\n", Module->exinputs[Module->exinputsNum][0]);
			printf("\nrows = %d ; col = %d\n", row, col);
			array = copyA;
			Module->RowCol_exinputs[Module->exinputsNum][0] = row;
			Module->RowCol_exinputs[Module->exinputsNum][1] = col;
			Module->exinputsNum++;
			MF->outputF = false;
		      }
	  MF->exinputF = false;	      
         }*//* copiar y llenar los arreglos con las cualidades de las salidas */
          else  if(MF->outputF == true)
           {
	   	if(MF->rowF==false && MF->colF ==false)
	   	{
		  Module->outputsE = true; 
		  copyA = idVal;
		  Module->outputs[Module->outputsNum] = copyA;
		  printf("\n%s\n", Module->outputs[Module->outputsNum]);
		  printf("\nrows = %d ; col = %d\n", row, col);
		  array = copyA;
		  //
		  Module->outputsNum++;
		  MF->outputF = false;
		}else if(MF->rowF==true && MF->colF ==false)
	   	      {
			Module->outputsE = true;
			copyA = idVal;
			Module->outputs[Module->outputsNum] = copyA;
			printf("\n%s\n", Module->outputs[Module->outputsNum]);
			printf("\nrows = %d ; col = %d\n", row, col);
			array = copyA;
			Module->RowCol_outputs[Module->outputsNum][0] = row;
			Module->RowCol_outputs[Module->outputsNum][1] = col;
			Module->outputsNum++;
			MF->outputF = false;
		      }else if(MF->rowF==true && MF->colF ==true)
	   	            {
			      Module->outputsE = true;
			      copyA = idVal;
			      Module->outputs[Module->outputsNum] = copyA;
			      printf("\n%s\n", Module->outputs[Module->outputsNum]);
			      printf("\nrows = %d ; col = %d\n", row, col);
			      array = copyA;
			      Module->RowCol_outputs[Module->outputsNum][0] = row;
			      Module->RowCol_outputs[Module->outputsNum][1] = col;
			      Module->outputsNum++;
			      MF->outputF = false;
		            }
		MF->outputF = false;
         }
  return (char*)array;
}


void ModuleDclr(Mcom input, char *array[])
{
  /*imprimir entradas*/
  
  for(int i = 0
          ;i < (input.inputsNum) 
          ;i++)
	{
	  if((input.RowCol_inputs[i][0] == 0) && (input.RowCol_inputs[i][1] == 0))
	  {
	  printf("\n\t%s :in std_logic",(char*)array[i]);
	  if(i < input.inputsNum-1)
	  {printf(";\n");}
	  else if((i == input.inputsNum-1)&& (input.outputsE == false))
	  {printf("\n");}	
	  else
	  {printf(";\n");}
	  }else if((input.RowCol_inputs[i][0] != 0) && (input.RowCol_inputs[i][1] == 0))
	        { 
	          printf("\n\t%s :in std_logic_vector(%d downto 0)",
	          (char*)array[i], input.RowCol_inputs[i][0]-1);
		    if(i < input.inputsNum-1)
		     {printf(";\n");}
		    else if((i == input.inputsNum-1)&& (input.outputsE == false))
			 {printf("\n");}	
			 else
			 {printf(";\n");}
	        }
	}
   
  /*imprimir salidas*/
  for(int i = 0
          ;i < (input.outputsNum) 
          ;i++)
	{
	  if((input.RowCol_outputs[i][0] == 0) && (input.RowCol_outputs[i][1] == 0))
	  {
	  printf("\n\t%s :out std_logic",input.outputsArray[i]);
		  if(i < input.outputsNum-1)
		  {printf(";\n");}
		  else if((i == input.outputsNum-1)&& (input.memoryE == false))
		  {printf("\n");}	
		  else
		  {printf(";\n");}
	  }else if((input.RowCol_outputs[i][0] != 0) && (input.RowCol_outputs[i][1] == 0))
	        { 
	          printf("\n\t%s :out std_logic_vector(%d downto 0)",
	          input.outputsArray[i], input.RowCol_outputs[i][0]-1);
	  	  if(i < input.outputsNum-1)
		  {printf(";\n");}
		  else if((i == input.outputsNum-1)&& (input.memoryE == false))
		  {printf("\n");}	
		  else
		  {printf(";\n");}
	        }
	}
}
void externalUnits(Mcom exinput)
{
  /* imprimir unidades externas     * 
   * (exinputs, exclunits y exbuses)*/
  
  if((exinput.exinputsE == true) || (exinput.exbusesE == true))
  {
    for(int  i = 0; i< exinput.exinputsNumR; i++)
    {
     int a  =1;
     
 printf("\nexinputs_%s : entity work.%s\n",exinput.exinputs[i][0][0],exinput.exinputs[i][0][0]);
      printf("port map (\n");
	for(int j = 1; j <= exinput.exinputsStore[i]/2;j++)
	{
	 
	 printf("\n%s => %s",(char*)exinput.exinputs[i][a][0],(char*)exinput.exinputs[i][a+1][0]);
	 if(((char*)exinput.exinputs[i][a+1][1] !=(char*)'0')&&((char*)exinput.exinputs[i][a+1][2] ==(char*)'0'))
	 {
	  printf("(%s)",(char*)exinput.exinputs[i][a+1][1]);
	 }
	 else if(((char*)exinput.exinputs[i][a+1][1] !=(char*)'0')&&((char*)exinput.exinputs[i][a+1][2] !=(char*)'0'))
	 {
	  printf("(%s downto %s)",exinput.exinputs[i][a+1][1],exinput.exinputs[i][a+1][2]);
	 }
	 a = a+ 2;
	 if(j < exinput.exinputsStore[i]/2)
	 {
	  printf(",\n");
	 }
	 
	}      
      printf("\n);\n");
    }
  }
}

void CombLogicUnits(Mcom clunit)
{
  for(int i = 0; i < clunit.ClunitsNumR; i++)
  {
	  for (int j = 0; j < clunit.ClunitsStore[i] ; j++)
	  {
	          
	          printf("%s ",(char*)clunit.Clunits[i][j][0]);
		   
 if((char*)clunit.Clunits[i][j][1] != (char*)'0' &&j != 0)
	   	   {printf("(%s) ",(char*)clunit.Clunits[i][j][1]);
	   	    }
	   	   
		   if (j == 0)
		   {
		    if((char*)clunit.Clunits[i][j][1] != (char*)'0')
	   	   {
	   	    printf("(%s) ",(char*)clunit.Clunits[i][j][1]);
	   	   }
		    printf(" <= ");
		   }
		   
		   if (j == clunit.ClunitsStore[i] -1)
		   { printf(";\n");}
	    	  
  	   }
  }
}

void AHPL_translate(Mcom input, char *array[])
{
	printf("\n\nlibrary ieee;\n");
	printf("use ieee.std_logic_1164.all;\n");
	printf("\nentity %s is\n", input.moduleName);
	/*inicio de entradas y salidas*/
	printf("port(");
	/*entradas*/
	ModuleDclr(input,array);
	/*fin de entradas*/
	printf(");");
	/*fin de entradas y salidas*/
	printf("\nend entity %s;\n",input.moduleName);
	
	/*arquitectura*/
	printf("\narchitecture ARC%s of %s is",input.moduleName,input.moduleName);
	/*señales o estados*/
	
	/*fin de señales o estados*/
	printf("\nbegin\n");
	/* maquinas de estado */
	
	/*unidades logicas combinacionales*/
	CombLogicUnits(input);
	
	/* entradas externas */
	externalUnits(input);
	
	printf("\nend architecture ARC%s;\n", input.moduleName);
	/*fin de arquitectura*/
	
	/*textos para ir probando el diseño*/
	printf("\n\n\n--***texto de prueba***\n\n\n");
	for (int i = 0; i < input.exinputsNumR;i++)
	{
	 for (int j = 0; j <= input.exinputsStore[input.exinputsNumR]; j++)
	 {
           printf("\n--%s\n", input.exinputs[i][j][0]);
           
         }	
	}
        printf("\n%d\n", input.exinputsNumR);
        printf("\n%s\n", input.exinputs[3][4][0]);
	return ;
}
