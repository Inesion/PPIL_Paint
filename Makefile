TARGET = PPIL_client

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

CC = g++
CFLAGS = -I$(INC_DIR) -g

LFLAGS = -I$(INC_DIR) -g

SRC := $(wildcard $(SRC_DIR)/*.cpp)
INC := $(wildcard $(INC_DIR)/*.hpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
rm = rm -f

$(BIN_DIR)/$(TARGET): $(OBJ)
	@$(CC) $(OBJ) $(LFLAGS) -o $@
	@echo "Linking complete"

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully"

.PHONY: clean remove run

clean:
	@$(rm) $(OBJ)
	@echo "Cleanup complete"

remove: clean
	@$(rm) $(BIN_DIR)/$(TARGET)
	@echo "Executable removed"

run : remove $(BIN_DIR)/$(TARGET)
	@echo "Running..."
	@$(BIN_DIR)/$(TARGET)
