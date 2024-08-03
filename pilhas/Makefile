APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
LIB = ./lib
SRC = ./src

FLAGS = -O3 -Wall
LIBS = -led -L $(LIB)

all: libed my_apps

libed: \
	$(OBJ)/static_stack.o \
	$(OBJ)/dynamic_stack.o 
	ar -rcs $(LIB)/libed.a $(OBJ)/*.o

my_apps: clean_apps \
	$(BIN)/static_stack_app \
	$(BIN)/dynamic_stack_app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

run:
	$(BIN)/dynamic_stack_app

clean:
	rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*

clean_apps:
	rm -rf $(BIN)/*