#ifndef BREAKER_H
#define BREAKER_H

#include "../include/readarq.h"
#include "../include/crypto.h"

void breakPasswords(Usuario **usuarios, int n_usuarios, char **senha_fraca, char **senha_fraca_cripto, int n_senhas);

#endif 