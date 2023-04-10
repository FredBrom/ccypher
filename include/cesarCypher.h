/*****************************************************************************/
/*                                                                           */
/*         Rotary Cesar's Cypher Algorithm Header File                       */
/*                                                                           */
/*****************************************************************************/

#ifndef CESAR_CYPHER_H
#define CESAR_CYPHER_H


long int cesarCypher(char *cypherText, char *plainText,  long int key);
long int rotaryCesarCypher(char *cypherText, char *plainText, long int key);
long int cesarUnCypher(char *plainText, char *cypherText, long int key);
long int rotaryCesarUnCypher(char *plainText, char *cypherText, long int key);

#endif

