#ifndef STULIBC_CAESAR_H
#define STULIBC_CAESAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Caesar cipher is identical to Vigen�re cipher with key of length 1. Also, Rot-13 is identical to Caesar cipher with key 13.
/*
 * Caesar's cipher, the shift cipher, Caesar's code or Caesar shift, is one of the simplest and most widely known encryption techniques. It is a type of substitution cipher in which each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet. For example, with a left shift of 3, D would be replaced by A, E would become B, and so on. The method is named after Julius Caesar, who used it in his private correspondence.

The encryption step performed by a Caesar cipher is often incorporated as part of more complex schemes, such as the Vigen�re cipher, and still has modern application in the ROT13 system. As with all single alphabet substitution ciphers, the Caesar cipher is easily broken and in modern practice offers essentially no communication security.
 * */
#define caesar(x) rot(13, x)
#define decaesar(x) rot(13, x)
#define decrypt_rot(x, y) rot((26-x), y)
void rot(int c, char *str);

#endif
