/*****************************************************************************/
/*                                                                           */
/*         Rotary Cesar's Cypher Algorithm Header File                       */
/*                                                                           */
/*****************************************************************************/

#ifndef CESAR_CYPHER_H
#define CESAR_CYPHER_H


int cesarCypher(char *cypherText, char *plainText, int key);
int rotaryCesarCypher(char *cypherText, char *plainText, int key);
int cesarUnCypher(char *plainText, char *cypherText, int key);
int rotaryCesarUnCypher(char *plainText, char *cypherText, int key);

#endif

