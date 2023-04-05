/*****************************************************************************/
/*                                                                           */
/*                   Rotary Cesar's Cypher                                   */
/*                                                                           */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cesarCypher.h"
 
#define SET_ROTARY 0x1 
#define SET_OUTPUT 0x2 
#define SET_INPUT 0x4
#define SET_DECYPH 0x8
#define SET_KEY 0x10

int key;
FILE *inputFilePtr;
FILE *outputFilePtr;
char *input_file;
char *output_file;
int cflag;  // Control Flags


/*  0 0 0 K D I O R
 *
 *  R - 0 - Simple
 *      1 - Rotary
 *  O - 0 - Output standard
 *      1 - Output on file
 *  I - 0 - Standard Input
 *      1 - Input from a file
 *  D - 0 - Cypher
 *      1 - Uncypher
 *  K - 0 - Key Unset
 *      1 - Key Set           */

void get_help();

int main(int argc, char **argv)
{
    cflag = 0;
    //Read the control vector and set flags
    int i;
    for (i=0; i<argc; i++)
    {
        if (strcmp(argv[i], "-i") == 0)
        {
            cflag = (cflag | SET_INPUT);
            input_file = argv[i+1];
            if (input_file == NULL)
            {
                printf("input file name missing\n");
                return EXIT_FAILURE;
            }
        }
        if (strcmp(argv[i], "-o") == 0)
        {
            cflag = (cflag | SET_OUTPUT);
            output_file = argv[i+1];
            if (output_file == NULL)
            {
                printf("output file name missing\n");
                return EXIT_FAILURE;
            }
        }
        if (strcmp(argv[i], "-d") == 0)
        {
            cflag = (cflag | SET_DECYPH);
        }
        if (strcmp(argv[i], "-r") == 0)
        {
            cflag = (cflag | SET_ROTARY);
        }
        if (strcmp(argv[i], "-k") == 0)
        {
            cflag = (cflag | SET_KEY);
            if (argv[i+1] == NULL)
            {
                printf("key is missing\n");
                return EXIT_FAILURE;
            }
            key = atoi(argv[i+1]);
        }
        if (strcmp(argv[i], "-h") == 0)
        {
            get_help();
            return EXIT_FAILURE;
        }
    }
    
    //Verify if no argument is presented
    if ((argc < 2) | (cflag == 0))
    {
        printf("Cesar Cypher Version 1.0\n");
        printf("to get help, use -h\n");
        return EXIT_FAILURE;
    }
    //Verify if the key is set
    if ((cflag & SET_KEY) == 0) //Verify if the key flag is unset
    {
        printf ("The key is missing\n");
        return EXIT_FAILURE;
    }
    //Cypher or Uncypher
    if ((cflag & SET_DECYPH))
    {
        //Uncypher
        if ((cflag & SET_INPUT) == 0) // Verify if the input is stdin
        {
            // input from stdin
            char *line = NULL;
            size_t len = 0;
            char *text;
            while (getline(&line, &len, stdin) != -1)        
            {
                if ((cflag & SET_ROTARY)) // Verify if the rotary flag is set
                {
                    rotaryCesarUnCypher(text, line, key);
                }
                else
                {
                    cesarUnCypher(text, line, key);
                }
                if ((cflag & SET_OUTPUT) == 0) // Verify if the output is stdin
                {
                    //output stdin
                    printf("%s", text);
                }
                else
                {
                    //output to file
                    outputFilePtr = fopen(output_file, "a");
                    if (outputFilePtr == NULL)
                    {
                        printf("Can't Open output file\n");
                        return EXIT_FAILURE;
                    }
                    fseek(outputFilePtr, 0L, SEEK_END);
                    fprintf(outputFilePtr, "%s", text); 
                    fclose(outputFilePtr);

                }
            }
        
            // End input from stdin
        }
        else
        {
            //input from file
            inputFilePtr = fopen(input_file, "r");
            if (inputFilePtr == NULL)
            {
                printf("Cant open the file %s\n", input_file);
                return EXIT_FAILURE;
            }
            char *line = NULL;
            size_t len = 0;
            char *text;
            while (getline(&line, &len, inputFilePtr) != -1)
            {
                if ((cflag & SET_ROTARY)) // Verify if the rotary flag is set
                {
                    rotaryCesarUnCypher(text, line, key);
                }
                else
                {
                    cesarUnCypher(text, line, key);
                }
                if ((cflag & SET_OUTPUT) == 0) // Verify if the output is stdin
                {
                    //output stdin
                    printf("%s", text);
                }
                else
                {
                   //output to file
                    outputFilePtr = fopen(output_file, "a");
                    if (outputFilePtr == NULL)
                    {
                        printf("Can't Open output file\n");
                        return EXIT_FAILURE;
                    }
                    fseek(outputFilePtr, 0L, SEEK_END);
                    fprintf(outputFilePtr, "%s", text); 
                    fclose(outputFilePtr);
                }
            }
            //end input from file
        }
    }
    else
    {
        // Cypher
        if ((cflag & SET_INPUT) == 0) // Verify if the input is stdin
        {
            // input from stdin
            char *line = NULL;
            size_t len = 0;
            char *cyphered;
            while (getline(&line, &len, stdin) != -1)        
            {
                if ((cflag & SET_ROTARY)) // Verify if the rotary flag is set
                {
                    rotaryCesarCypher(cyphered, line, key);
                }
                else
                {
                    cesarCypher(cyphered, line, key);
                }
                if ((cflag & SET_OUTPUT) == 0) // Verify if the output is stdin
                {
                    //output stdin
                    printf("%s", cyphered);
                }
                else
                {
                    //output to file
                    outputFilePtr = fopen(output_file, "a");
                    if (outputFilePtr == NULL)
                    {
                        printf("Can't Open output file\n");
                        return EXIT_FAILURE;
                    }
                    fseek(outputFilePtr, 0L, SEEK_END);
                    fprintf(outputFilePtr, "%s", cyphered); 
                    fclose(outputFilePtr);

                }
            }
        
            // End input from stdin
        }
        else
        {
            //input from file
            inputFilePtr = fopen(input_file, "r");
            if (inputFilePtr == NULL)
            {
                printf("Cant open the file %s\n", input_file);
                return EXIT_FAILURE;
            }
            char *line = NULL;
            size_t len = 0;
            char *cyphered;
            while (getline(&line, &len, inputFilePtr) != -1)
            {
                if ((cflag & SET_ROTARY)) // Verify if the rotary flag is set
                {
                    rotaryCesarCypher(cyphered, line, key);
                }
                else
                {
                    cesarCypher(cyphered, line, key);
                }
                if ((cflag & SET_OUTPUT) == 0) // Verify if the output is stdin
                {
                    //output stdin
                    printf("%s", cyphered);
                }
                else
                {
                   //output to file
                    outputFilePtr = fopen(output_file, "a");
                    if (outputFilePtr == NULL)
                    {
                        printf("Can't Open output file\n");
                        return EXIT_FAILURE;
                    }
                    fseek(outputFilePtr, 0L, SEEK_END);
                    fprintf(outputFilePtr, "%s", cyphered); 
                    fclose(outputFilePtr);
                }
            }
            //end input from file
        }
    }
    return EXIT_SUCCESS;
}

void get_help()
{
    printf("Cesar Cypher is a Cypher and Decypher that uses cesar's algorithm of encyptation of text\n");
    printf("This program was writed on Apr 2023 by Fred Brom\n");
    printf("The Options are:\n");
    printf("-d - Set the decode mode, the standard mode is encode.\n");
    printf("-r - set the rotary mode, the standard mode is static key.\n");
    printf("-k {key} - Set the key of encriptation and decriptation.\n");
    printf("-i {fileName} - Define the Input from fileName.\n");
    printf("-o {fileName} - Define Output to fileName.\n");
    printf("if no input or output file is defined, the terminal is defined to both input and output\n");
 }

