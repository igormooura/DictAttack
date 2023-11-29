PROGRAM_NAME = dict_attack
CC = gcc
CC_FLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wshadow -Wsign-conversion -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused
LIBS = -lssl -lcrypto
H_SOURCE = $(wildcard include/*.h)
C_SOURCE = $(wildcard src/*.c)
TARGET_FOLDER = bin
OBJ = $(patsubst src/%.c,$(TARGET_FOLDER)/%.o,$(C_SOURCE))

$(TARGET_FOLDER)/%.o: src/%.c $(H_SOURCE)
	@ echo ' '
	@ echo 'Compilando o arquivo: $<'
	$(CC) $(CC_FLAGS) -c $< -o $@
	@ echo ' '
	@ echo 'Compilação concluída: $@'
	@ echo ' '

build: $(TARGET_FOLDER) $(OBJ)
	@ echo ' '
	@ echo 'Criando binário dos arquivos objetos'
	$(CC) $(OBJ) -o $(PROGRAM_NAME) $(LIBS)
	@ echo ' '

$(TARGET_FOLDER):
	mkdir -p $(TARGET_FOLDER)

run: build
	@ ./$(PROGRAM_NAME)

clean:
	@ echo "Cleaning up..."
	rm -rvf $(wildcard $(TARGET_FOLDER)/*.o) $(PROGRAM_NAME) text/output.txt

debug: $(TARGET_FOLDER) $(OBJ)
	@ echo ' '
	@ echo 'Criando binário dos arquivos objetos em modo de depuração'
	$(CC) -g $(OBJ) -o $(PROGRAM_NAME) $(LIBS)
	@ echo ' '

crypto: $(TARGET_FOLDER) $(TARGET_FOLDER)/crypto.o

$(TARGET_FOLDER)/crypto.o: src/crypto.c include/crypto.h
	@ echo ' '
	@ echo 'Compilando o arquivo crypto.c'
	$(CC) $(CC_FLAGS) -c $< -o $@ $(LIBS)
	@ echo ' '
	@ echo 'Compilação concluída: $@'
	@ echo ' '
