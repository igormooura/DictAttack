#ifndef READARQ_H
#define READARQ_H

#include <stdio.h>

#define MAX_USERS 100

typedef struct {
    char nomeCompleto[51];
    char dataNascimento[11];
    char login[21];
    char senhaCriptografada[65];
    char dataUltimaAlteracaoSenha[11];
    char senha[33];
} Usuario;

Usuario *read_user(FILE *users);
char **weak_password_lecture(FILE *weakpassword);

#endif