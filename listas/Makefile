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
	$(OBJ)/linked_list.o \
	$(OBJ)/doubly_linked_list.o
	ar -rcs $(LIB)/libed.a $(OBJ)/*.o

my_apps: clean_apps \
	$(BIN)/linked_list_app \
	$(BIN)/doubly_linked_list_app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

run:
	$(BIN)/doubly_linked_list_app

clean:
	rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*

clean_apps:
	rm -rf $(BIN)/*