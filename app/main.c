/*****************************************************************************/
/*                                                                           */
/*                   Rotary Cesar's Cypher                                   */
/*                                                                           */
/*****************************************************************************/

/* This Version will cypher and uncypher only files, no more stdin           */
/* if no output file is provided, the srdout will be used as output          */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "cesarCypher.h"

#define SET_ROTARY 0x1
#define SET_DECYPHER 0x2
#define SET_KEY 0x4

int main(int argc, char **argv)
{
    //Parse command line arguments. 
    int clArg;
    char *inputFileName = NULL;
    char *outputFileName = NULL;
    char cFlags = 0;
    long int key;

    while ((clArg = getopt(argc, argv, "dro:i:k:")) != -1)
    {
        switch (clArg)
        {
            case 'r':
                cFlags = cFlags | SET_ROTARY;
                break;
            case 'd':
                cFlags = cFlags | SET_DECYPHER;
                break;
            case 'i':
                inputFileName = optarg;
                break;
            case 'o':
                outputFileName = optarg;
                break;
            case 'k':
                key = strtol(optarg, NULL, 10);
                cFlags = cFlags | SET_KEY;
                break;
            case '?':
                fprintf(stderr, "Unknow Option '-%c'\n", optopt);
                return 1;
        }
    }

    //Verify if the input file is set
    if (inputFileName == NULL)
    {
        fprintf(stderr, "Input file missing.\nUse -i <file>.\n");
        return 1;
    }
    //Verify if the Key is not Set
    if (!(cFlags & SET_KEY))
    {
        fprintf(stderr, "Key is missing.\nUse -k <key>.\n");
        return 1;
    }

    // Test input
    /*
    printf("cflags = %08b\n", cFlags);
    printf("Input Name = %s\n", inputFileName);
    printf("Output Name = %s\n", outputFileName);
    printf("Key = %d\n", key);
    */    
    //Try to Open the input file
    FILE *inputFilePtr;
    size_t fileSize;
    
    inputFilePtr = fopen(inputFileName, "r");
    
    if (inputFilePtr == NULL)
    {
        fprintf(stderr, "The file '%s' can't be opened or don't exist.\n", inputFileName);
        return 1;
    }

    fseek(inputFilePtr, 0L, SEEK_END);
    fileSize = ftell(inputFilePtr);
    fseek(inputFilePtr, 0L, SEEK_SET);

    //Copy the content of input file to the input buffer
    char *inputBuffer;
    inputBuffer = malloc(fileSize);

    if (inputBuffer == NULL)
    {
        fprintf(stderr, "No more memory.\n Execution Terminated.\n");
        return 1;
    }

    if (fread(inputBuffer, sizeof(char), fileSize, inputFilePtr) != fileSize)
    {
        fprintf(stderr, "Error while file reading.\n");
        return 1;
    }
    fclose(inputFilePtr);

    //Create a output buffer
    char *outputBuffer;
    outputBuffer = malloc(fileSize);

    if (outputBuffer == NULL)
    {
        fprintf(stderr, "No more memory.\nExecution Terminated.\n");
        return 1;
    }

    //Encrypt Buffer
    if (cFlags & SET_DECYPHER)
    {
        if (cFlags & SET_ROTARY)
        {
            if (rotaryCesarUnCypher(outputBuffer, inputBuffer, key) != fileSize)
            {
                fprintf(stderr, "Failure in decryption.\n");
                return 1;
            }
        }
        else
        {
            if (cesarUnCypher(outputBuffer, inputBuffer, key) != fileSize)
            {
                fprintf(stderr, "Failure in Decryption.\n");
                return 1;
            }
        }
    }
    else
    {
        if (cFlags & SET_ROTARY)
        {
            if (rotaryCesarCypher(outputBuffer, inputBuffer, key) != fileSize)
            {
                fprintf(stderr, "Failure in Encryption.\n");
                return 1;
            }
        }
        else
        {
            if (cesarCypher(outputBuffer, inputBuffer, key) != fileSize)
            {
                fprintf(stderr, "Failure in Encryption.\n");
                return 1;
            }
        }
    }
           
    if (outputFileName == NULL)
    {
        fprintf(stdout, "%s", outputBuffer);
        return 0;
    }
    else
    {
        FILE *outputPtr;
        outputPtr = fopen(outputFileName, "w");

        if (outputPtr == NULL)
        {
            fprintf(stderr, "The file '%s' cannot be created.\n", outputFileName);
            return 1;
        }

        if (fwrite(outputBuffer, sizeof(char), fileSize, outputPtr) != fileSize)
        {
            fprintf(stderr, "Failure on writing on file '%c'.\n", outputFileName);
            return 1;
        }
        return 0;

    }
}
