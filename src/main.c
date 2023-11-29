#include <stdio.h>
#include <stdlib.h>
#include "../include/readarq.h"
#include "../include/crypto.h"
#include "../include/output.h"
#include "../include/breaker.h"

const char FILE_WEAKPASSWORD[] = "./text/weakpassword.txt";
const char FILE_USERS[] = "./text/users.txt";
const char FILE_OUTPUT[] = "./text/output.txt";

int main()
{
    // Ler as senhas fracas
    FILE *weakpassword = fopen(FILE_WEAKPASSWORD, "r");
    if (weakpassword == NULL)
    {
        perror("File ./text/weakpassword.txt does not exists");
        return EXIT_FAILURE;
    }
    
    char **weakpasswords = weak_password_lecture(weakpassword);
    

    // Considerando a quantidade de senhas fracas
    int n_weakpasswords = 0;
    while (weakpasswords[n_weakpasswords] != NULL)
    {
        n_weakpasswords++;
    }

    // Vendo os perfis e considerando a quantidade de perfis
    FILE *usersFile = fopen(FILE_USERS, "r");
    if (usersFile == NULL)
    {
        perror("File ./text/users.txt does not exists");
        return EXIT_FAILURE;
    }
    Usuario **users = NULL;
    int n_users = 0;

    // Leitura de usuários até o final do arquivo (usersFile é um ponteiro de arquivo FILE*)
    while (!feof(usersFile))
    {
        // Realocação de memória pra colocar "mais espaço" na memoria
        users = realloc(users, (size_t)(n_users + 1) * sizeof(Usuario *));
        users[n_users] = read_user(usersFile);

        if (users[n_users] != NULL)
        {
            n_users++;
        }
    }


    // Decodificando as senhas fracas
    char **weakpasswords_crypto = crypto_weak_passwords(weakpasswords, n_weakpasswords);
    breakPasswords(users, n_users, weakpasswords, weakpasswords_crypto, n_weakpasswords);

    // Printando os perfis que têm senhas consideradas fracas
    FILE *outputFile = fopen(FILE_OUTPUT, "w");

    for (int i = 0; i < n_users; i++)
    {
        // verifica se a ta decriptada e o perfil nao ta vazio
        if (users[i]->login[0] != '\0' && users[i]->senhaCriptografada[0] != '\0' && users[i]->senha != NULL && users[i]->senha[0] != '\0')
        {
            print_report(outputFile, users[i]);
            fprintf(outputFile, "\n");
        }
    }
    
    free(weakpasswords);
    free(weakpasswords_crypto);

    fclose(usersFile);
    fclose(outputFile);
    fclose(weakpassword);

    return EXIT_SUCCESS;
}
