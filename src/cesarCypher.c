/*****************************************************************************/
/*                                                                           */
/*        Implementation of a Rotary Cesar's Cypher Algorithm                */
/*                                                                           */
/*****************************************************************************/

#include <ctype.h>
#include <stdio.h>
#include "cesarCypher.h"

char cypher(char chr, long int shift)
{
    long int shift_n;
    shift_n = shift % 26;
    if (isupper(chr))
    {
        return (((chr - 'A') + shift_n) % 26) + 'A';
    }
    else if (islower(chr))
    {
        return (((chr - 'a') + shift_n) % 26) + 'a';
    }
    else if (isdigit(chr))
    {
        long int shift_d = shift_n % 10;
        return (((chr - '0') + shift_d) % 10) + '0';
    }
    else return chr;
}

char unCypher(char chr, long int shift)
{
    long int shift_n;
    shift_n = shift % 26;
    if (isupper(chr))
    {
        return ((((chr - 'A') - shift_n) + 26) % 26) + 'A';
    }
    if (islower(chr))
    {
        return ((((chr - 'a') - shift_n) + 26) % 26) + 'a';
    }
    if (isdigit(chr))
    {
        long int shift_d = shift_n % 10;
        return ((((chr - '0') - shift_d) + 10) % 10) + '0';
    }
    else return chr;
}
    
long int cesarCypher(char *cypherText, char *plainText, long int key)
{
    long int i=0;
    while (plainText[i] != '\0')
    {
        cypherText[i] = cypher(plainText[i], key);
        i++;
        
    }
    return i;
}

long int rotaryCesarCypher(char *cypherText, char *plainText, long int key)
{
    long int i=0;
    long int shift_n;
    shift_n = key;
    while (plainText[i] != '\0')
    {
        cypherText[i] = cypher(plainText[i], shift_n);
        i++;
        shift_n++;
    }
    return i;
}

long int cesarUnCypher(char *plainText, char *cypherText, long int key)
{
    long int i=0;
    while (cypherText[i])
    {
        plainText[i] = unCypher(cypherText[i], key);
        i++;
        
    }
    return i;
}

long int rotaryCesarUnCypher(char *plainText, char *cypherText, long int key)
{
    long int i=0;
    long int shift_n;
    shift_n = key;
    while (cypherText[i])
    {
        plainText[i] = unCypher(cypherText[i], shift_n);
        shift_n++;
        i++;
    }
    return i;
}


