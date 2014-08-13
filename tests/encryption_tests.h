#ifndef STULIBC_ENCRYPTION_TESTS_H
#define STULIBC_ENCRYPTION_TESTS_H

#include "../encryption/vigenere.h"
#include "../encryption/isaac.h"
#include "../encryption/caesar.h"

void test_vigenere_cipher()
{
	const char *str = "Beware the Jabberwock, my son! The jaws that bite, "
	                    "the claws that catch!";
	        const char *cod, *dec;
	        char key[] = "VIGENERECIPHER";

	        printf("Text: %s\n", str);
	        printf("key:  %s\n", key);

	        cod = vigenere_encipher(str, key, 1); printf("Code: %s\n", cod);
	        dec = vigenere_encipher(cod, key, 0); printf("Back: %s\n", dec);

	        /* free(dec); free(cod); */ /* nah */
}

void test_isaac_cipher()
{
	int n,l;
		char *msg = "a Top Secret secret";
		char *key = "this is my secret key";
		char *xctx= "";
		char *xptx= "";
		l = strlen(msg);
		// xtcx: XOR ciphertext for decryption
		char xtcx[MAXMSG];
		memset(xtcx, '\0', sizeof(msg));
		// seed ISAAC with key
		iSeed(key,1);
		// Vernam XOR encrypt
		xctx = Vernam(msg);
		strcpy(xtcx, xctx);
		// Vernam XOR decrypt
		iSeed(key,1);
		xptx = Vernam(xtcx);
		// program output
		printf("Message: %s\n",msg);
		printf("Key    : %s\n",key);
		printf("XOR    : ");
		// Output ciphertext as a string of hex digits
		for (n=0; n<l; n++) printf("%02X",xtcx[n]);
		printf("\n");
		// Output decrypted plaintext
		printf("XOR dcr: %s\n",xptx);
}

void test_caesar_cipher()
{
	char str[] = "This is a top secret text message!";

		printf("Original: %s\n", str);
		caesar(str);
		printf("Encrypted: %s\n", str);
		decaesar(str);
		printf("Decrypted: %s\n", str);
}

#endif
