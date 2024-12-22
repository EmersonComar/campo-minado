# Configuração do compilador
GCC				= gcc
CFLAGS			= -Wall -Wextra
INCLUDE_FLAG	= -I $(INCLUDE)

# Diretórios padrões
APP				= ./app
BIN				= ./bin
INCLUDE			= ./include
OBJ				= ./obj
SRC				= ./src
VAL				= ./val

# Automação criação diretórios
DIRS			= $(BIN) $(OBJ) $(VAL)

# Executável
TARGET			= $(BIN)/main

# Arquivos fontes
SRCS			=	$(APP)/main.c		\
					$(SRC)/tabuleiro.c	\
					$(SRC)/bombas.c

# Arquivos objetos
OBJS			=	$(BIN)/main.o			\
					$(OBJ)/tabuleiro.o		\
					$(OBJ)/bombas.o

# Padrão
all: $(BIN) $(OBJ) $(TARGET)

# Criando diretórios
$(DIRS):
	@echo "Criando $@"
	@mkdir -p $@

# Compilando objetos
$(BIN)/main.o: $(APP)/main.c $(INCLUDE)/campo_minado.h
	@echo "Compilando $@"
	@$(CC) $(CFLAGS) $(INCLUDE_FLAG) -c $< -o $@

$(OBJ)/tabuleiro.o: $(SRC)/tabuleiro.c $(INCLUDE)/campo_minado.h
	@echo "Compilando $@"
	@$(CC) $(CFLAGS) $(INCLUDE_FLAG) -c $< -o $@

$(OBJ)/bombas.o: $(SRC)/bombas.c $(INCLUDE)/campo_minado.h
	@echo "Compilando $@"
	@$(CC) $(CFLAGS) $(INCLUDE_FLAG) -c $< -o $@


# Linkando aplicativo
$(TARGET): $(OBJS)
	@echo "Linkando aplicativo"
	@$(CC) $(CFLAGS) $^ -o $@

# Executando
run: $(TARGET)
	@echo "Executando aplicativo"
	@$(TARGET)

valgrind: $(VAL) $(TARGET)
	@echo "Analisando com valgrind"
	@valgrind --leak-check=full 						\
			  --show-leak-kinds=all 					\
			  --track-origins=yes						\
			  --log-file=$(VAL)/valgrind_output.log		\
			  $(TARGET)

# Limpeza
clean: 
	@echo "Removendo arquivos compilados"
	@rm -rf $(BIN)/* $(OBJ)/*

rebuild: clean all