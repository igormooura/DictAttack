#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/output.h"

void print_report(FILE *users, Usuario *usuario) {
    if (usuario->senhaCriptografada[0] != '\0') {
        fprintf(users, " %s\n", usuario->login);
        fprintf(users, " %s\n", usuario->senha);
        fprintf(users, " %s\n", usuario->nomeCompleto);
        fprintf(users, " %s\n", usuario->dataNascimento);
        fprintf(users, " ---");
    }
}
