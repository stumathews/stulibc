#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libstring.h"

//Implement a Vigen�re cypher, both encryption and decryption
char* vigenere_encipher(const char *src, char *key, int is_encode);
