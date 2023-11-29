#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include "../include/crypto.h"


// Faz o calculo pra sha256
void sha256(const char *text, unsigned char hash[SHA256_DIGEST_LENGTH]) {
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    const EVP_MD *md = EVP_sha256();

    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, text, strlen(text));
    EVP_DigestFinal_ex(mdctx, hash, NULL);

    EVP_MD_CTX_free(mdctx);
}

// Transforma de sha256 pra hex
char* sha256_hex(const char *text) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    sha256(text, hash);

    char *hex_digest = malloc(sizeof(char) * (2 * SHA256_DIGEST_LENGTH + 1));

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hex_digest[i * 2], "%02x", hash[i]);
    }

    hex_digest[2 * SHA256_DIGEST_LENGTH] = '\0'; 

    return hex_digest;
}

// Encriptar as senhas consideradas fracas
char** crypto_weak_passwords(char **weakpasswords, int size) {
    char** encryption_password = (char**)malloc(sizeof(char*) * (size_t)size);

    for (int i = 0; i < size; i++) {
        encryption_password[i] = sha256_hex(weakpasswords[i]);
    }

    return encryption_password;
}
