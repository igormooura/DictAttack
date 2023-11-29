#ifndef CRYPTO_H
#define CRYPTO_H

#include <openssl/sha.h>

void sha256(const char *text, unsigned char hash[SHA256_DIGEST_LENGTH]);
char* sha256_hex(const char *text);
char** crypto_weak_passwords(char **weakpasswords, int size);

#endif // CRYPTO_H
