# Definição das variáveis
CXX = g++
CXXFLAGS = -Wall -Wextra -Iinc -g -std=c++11
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin
EXECUTABLE = $(BIN_DIR)/main

# Lista de fontes e objetos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Alvo padrão (executar o projeto)
all: $(BIN_DIR) $(OBJ_DIR) $(EXECUTABLE)

# Criação dos diretórios obj/ e bin/
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compilação do executável
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilação dos objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar objetos e executável
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Executar o projeto
run: all
	$(EXECUTABLE)

.PHONY: all clean run