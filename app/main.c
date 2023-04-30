/*****************************************************************************/
/*                                                                           */
/*                   Rotary Cesar's Cypher                                   */
/*                                                                           */
/*****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cesarCypher.h"

#define SET_ROTARY 0x1
#define SET_DECYPHER 0x2
#define SET_KEY 0x4

int main(int argc, char **argv)
{
    //Parse command line arguments. 
    int clArg;
    char cFlags = 0;

    unsigned key;

    while ((clArg = getopt(argc, argv, "drk:")) != -1)
    {
        switch (clArg)
        {
            case 'r':
                cFlags = cFlags | SET_ROTARY;
                break;
            case 'd':
                cFlags = cFlags | SET_DECYPHER;
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

    //Verify if the Key is not Set
    if (!(cFlags & SET_KEY))
    {
        fprintf(stderr, "Key is missing.\nUse -k <key>.\n");
        return 1;
    }

    int ch;
    while ((ch = getc(stdin)) !=  EOF)
    {
        if ((cFlags & SET_DECYPHER))
        {
            putc(unCypher(ch, key), stdout);
            if ((cFlags & SET_ROTARY))
                key++;
        }
        else
        {
            putc(cypher(ch, key), stdout);
            if ((cFlags & SET_ROTARY))
                key++;
        }
    }
    return 0;
}
