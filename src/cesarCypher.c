/*****************************************************************************/
/*                                                                           */
/*        Implementation of a Rotary Cesar's Cypher Algorithm                */
/*                                                                           */
/*****************************************************************************/

#include <ctype.h>
#include "cesarCypher.h"

int cypher(int chr, unsigned int shift)
{
    unsigned int shift_n;
    shift_n = shift % 26;
    if (!shift_n)
        shift_n++;

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
        shift_n = shift_n % 10;
        if (!shift_n)
            shift_n++;
        return (((chr - '0') + shift_n) % 10) + '0';
    }

    else return chr;
}

int unCypher(int chr, unsigned int shift)
{
    unsigned int shift_n;
    shift_n = shift % 26;
    if (!shift_n)
        shift_n++;

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
        shift_n = shift_n % 10;
        if (!shift_n)
            shift_n++;
        return ((((chr - '0') - shift_n) + 10) % 10) + '0';
    }
    
    else return chr;
}

