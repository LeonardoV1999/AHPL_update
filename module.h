#ifndef MODULE_H
#define MODULE_H

#define char_long 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*typedef struct mod
{
	int modsize;
	int other;
}Mod;
*/

typedef struct Module_Composition /*se encarga de copiar */
    { int   moduleNum;
      char *moduleName;          /**/
      
      int  inputsNum;
      char *inputs[char_long];
      char *inputsArray[char_long];
      int  RowCol_inputs[char_long][2];
      bool inputsE;                       /*existen entradas*/
      
      int  exinputsNumR;
      int  exinputsNumC;
      int  exinputsStore[char_long];    /* cada fila indica el numero de variables que  *
                                           se almacenan dentro de un arreglo de exinputs*/
                                              
      char *exinputs[char_long][char_long][3];/* almacena los nombres de cada entrada externa *
                                               * y lo de cada uno de sus miembros             *
                                               * (ver si se puede modificar para guardar      *
                                               *  tambien los valores entre los arreglos como *
                                               *  filas y columnas)*/
        
      bool exinputsl[char_long][2];
      bool exinputsE;                         
      char *exinputsArray[char_long];
      int RowCol_exinputs[char_long][2];
      int exinputsMembers;
                         
      
      int  outputsNum;
      char *outputs[char_long];
      char *outputsArray[char_long];
      int RowCol_outputs[char_long][2];
      bool outputsE;                         /* probablemente no se use */
      
      int  busesNum;
      char *buses[char_long];
      char *busesArray[char_long];
      int RowCol_buses[char_long][2];
      bool busesE;
      
      int  exbusesNum;
      char *exbuses[char_long];
      char *exbusesArray[char_long];
      int RowCol_exbuses[char_long][2];
      bool exbusesE;
      
      int  memoryNum;
      char *memory[char_long];
      char *memoryArray[char_long];
      int RowCol_memory[char_long][2];
      bool memoryE;
      
      int  ClunitsNumR;
      int  ClunitsNumC;
      int  ClunitsStore[char_long];
      char *Clunits[char_long][char_long][2];
      char *ClunitsArray[char_long];
      int RowCol_Clunits[char_long][2]; /*en las filas se almacena una linea individual y en las *
      					  columnas se almacenan todos los carateres que dicha    *
      					  linea tiene, pero traducidos                           */
      bool ClunitsE;
      
     }Mcom;
     
typedef struct mod_flags
    {
      bool inputF;
      bool exinputF;
      bool outputF;
      bool busesF;
      bool exbusesF;
      bool memoryF;
      bool clunitF;
      
      bool rowF;
      bool colF;
    }ModuleFlag;
    
void AHPL_translate(Mcom input, char *array[]);
void ModuleDclr(Mcom input, char *array[]);
void externalUnits(Mcom exinput);
void CombLogicUnits(Mcom clunit);
char *copyArray(ModuleFlag* MF ,char *array, Mcom* Module, int row, int col, char *idVal);


#endif


