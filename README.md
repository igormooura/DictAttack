# DICT ATTACK

## Introdução

O ataque de dicionário é um método de força-bruta em que o atacante busca descobrir senhas criptografadas comparando-as com um banco de senhas fracas. Este projeto utiliza senhas criptografadas com SHA256 e um conjunto de senhas fracas para gerar um relatório de quebra de senhas.

## Especificação

Os caminhos dos arquivos de entrada e saída são fornecidos pela linha de comando, sendo:
- Primeiro argumento: caminho do arquivo de usuários.
- Segundo argumento: caminho do arquivo de senhas fracas.
- Terceiro argumento: caminho do arquivo de relatório de quebra.

### Arquivos de Entrada

#### Arquivo de Usuários (/text/users.txt)

O arquivo de usuários possui os dados dos usuários juntamente com as suas senhas criptografadas. Cada usuário é descrito por diversas linhas, contendo os seguintes dados:
- Nome completo (até 50 caracteres). Pode haver espaços no nome completo;
- Data de nascimento no formato DD/MM/AAAA (10 caracteres);
- Login (até 20 caracteres);
- Senha criptografada: (64 caracteres);
- Data da última alteração de senha no formato DD/MM/AAAA (10 caracteres).
- Após a descrição de cada usuário, há uma linha com o separador ---.

#### Arquivo de Senhas Fracas (/text/weakpassword.txt)

O arquivo de senhas fracas possui várias linhas, cada uma descrevendo uma provável senha. Estas senhas estão limitadas a 32 caracteres.

### Arquivo de Saída (/text/output.txt)

O arquivo de saída  imprime um relatório de quebra. Para cada usuário que teve a sua senha quebrada, é impresso, em uma linha:
- Login;
- Senha em claro;
- Nome Completo;
- Data de nascimento.
Após cada usuário que teve a senha quebrada, uma linha com o separador --- é impressa.

### Documentação

O código deve ser bem documentado, com presença de comentários explicando os trechos mais complexos do código. Além disso, um arquivo README deve ser providenciado com a devida identificação do autor descrevendo o projeto e instruindo como o código deve ser compilado.

### Modularização

- Módulo de leitura: efetua a leitura do arquivo de usuários e do arquivo de senhas fracas e armazena os dados na estrutura adequada.
- Módulo de saída: produz o relatório de quebras.
- Módulo criptográfico: aplica a função SHA256 nas strings.
- Módulo de quebra: responsável pela quebra das senhas.
- Módulo principal: contém a função main e realiza a chamada aos outros módulos.

### Criptografia

Para criptografar as senhas, o algoritmo SHA256 é utilizado. Ele é providenciado pela biblioteca OpenSSL no Linux.

### Considerações Finais

O projeto foi realizado por Igor de Oliveira Moura, cursando o 2° semestre de ciências da computação pelo Instituto Federal de Brasília para a matéria de programação de computadores 1, ministrada pelo professor Daniel Saad.