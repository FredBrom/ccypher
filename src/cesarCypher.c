/*****************************************************************************/
/*                                                                           */
/*        Implementation of a Rotary Cesar's Cypher Algorithm                */
/*                                                                           */
/*****************************************************************************/

#include <ctype.h>
#include "cesarCypher.h"

char cypher(char chr, int shift)
{
    int shift_n;
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
        int shift_d = shift_n % 10;
        return (((chr - '0') + shift_d) % 10) + '0';
    }
    else return chr;
}

char unCypher(char chr, int shift)
{
    int shift_n;
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
        int shift_d = shift_n % 10;
        return ((((chr - '0') - shift_d) + 10) % 10) + '0';
    }
    else return chr;
}
    
int cesarCypher(char *cypherText, char *plainText, int key)
{
    int i=0;
    while (plainText[i])
    {
        cypherText[i] = cypher(plainText[i], key);
        i++;
        
    }
    cypherText[i] = '\0'; 
    return i-1;
}

int rotaryCesarCypher(char *cypherText, char *plainText, int key)
{
    int i=0;
    int shift_n;
    shift_n = key;
    while (plainText[i])
    {
        cypherText[i] = cypher(plainText[i], shift_n);
        i++;
        shift_n++;
    }
    cypherText[i] = '\0';
    return i-1;
}

int cesarUnCypher(char *plainText, char *cypherText, int key)
{
    int i=0;
    while (cypherText[i])
    {
        plainText[i] = unCypher(cypherText[i], key);
        i++;
        
    }
    plainText[i] = '\0'; 
    return i-1;
}

int rotaryCesarUnCypher(char *plainText, char *cypherText, int key)
{
    int i=0;
    int shift_n;
    shift_n = key;
    while (cypherText[i])
    {
        plainText[i] = unCypher(cypherText[i], shift_n);
        shift_n++;
        i++;
    }
    plainText[i] = '\0';
    return i-1;
}


