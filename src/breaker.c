#include "../include/breaker.h"
#include "../include/crypto.h"
#include "../include/readarq.h"
#include <string.h>
#include <stdio.h>

void breakPasswords(Usuario **usuarios, int n_usuarios, char **senha_fraca, char **senha_fraca_cripto, int n_senhas) {
    for (int i = 0; i < n_senhas; ++i) {
        for (int j = 0; j < n_usuarios; ++j) {
            if (strcmp(usuarios[j]->senhaCriptografada, senha_fraca_cripto[i]) == 0) {
                strcpy(usuarios[j]->senha, senha_fraca[i]);
            }
        }
    }
}
