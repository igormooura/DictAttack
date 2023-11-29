#include <stdio.h>
#include <stdlib.h>
#include "../include/readarq.h"

Usuario *read_user(FILE *users) {
    Usuario *user = malloc(sizeof(Usuario));

    if (user == NULL) {
        fprintf(stderr, "Erro de alocação de memória para o usuário.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(users, " %[^\n]", user->nomeCompleto);
    fscanf(users, " %s", user->dataNascimento);
    fscanf(users, " %s", user->login);
    fscanf(users, " %s", user->senhaCriptografada);
    fscanf(users, " %s", user->dataUltimaAlteracaoSenha);
    fscanf(users, " ---");

    return user;
}

char **weak_password_lecture(FILE *weakpassword) {
    int i;
    char **weakpasswordsFile = malloc(sizeof(char*) * 33);

    for (i = 0; i < 32; i++) {
        weakpasswordsFile[i] = malloc(sizeof(char) * 33);
        fscanf(weakpassword, "%s", weakpasswordsFile[i]);
    }

    return weakpasswordsFile;
}