# Dominando Estruturas de Dados 1

Esse repositório possui minhas anotações e resoluções dos exercícios desse curso
ministrado pelo professor [Samuel Martins](https://samucoding.com/), na playlist
[Curso: Dominando Estruturas de Dados 1](https://youtube.com/playlist?list=PL3ZslI15yo2r-gHJtjORRMRKMSNRpf7u5&si=qsr2zwmTDhn-o_yK)
em seu canal no Youtube [xavecoding](https://www.youtube.com/@xavecoding).

## Importante

- O compilador utilizado foi o ***gcc***

---

</br>

Na primeira parte do curso, dos vídeos 1 ao 38, o comando usado para compilar os
arquivos C foi:

```shell
gcc ./nome_do_arquivo.c -o ./nome_desejado_do_arquivo_compilado
```

O comando utilizado para executar o arquivo executável (arquivo compilado) foi:

```shell
./nome_do_arquivo_compilado
```

O comando para criar um arquivo `.o` foi:

```shell
gcc -c ./nome_do_arquivo_a_ser_compilado_em_um_arquivo_o.c
```

Quando se cria um arquivo `.o`, é necessário incluí-lo no comando de compilação
do arquivo C do qual se quer gerar o arquivo executável. O comando usado foi:

```shell
gcc ./nome_do_arquivo.c ./nome_do_arquivo.o -o ./nome_desejado_do_arquivo_compilado
```

## Compilando códigos C

Como mostrado anteriormente, os comandos usados para compilar os arquivos C
foram:

```shell
gcc ./nome_do_arquivo.c -o ./nome_desejado_do_arquivo_compilado
```

e

```shell
gcc -c ./nome_do_arquivo_a_ser_compilado_em_um_arquivo_o.c
```

O segundo comando mostrado acima não especifica nenhum nome de saída ao
compilador. Portanto, o compilador, por padrão, dá ao arquivo gerado o mesmo
nome do arquivo de origem, mudando somente a extensão para `.o`. Mas, assim como
no comando de compilar um arquivo executável, é possível dar um outro nome
qualquer ao objeto compilado com o comando:

```shell
gcc -c ./nome_do_arquivo_a_ser_compilado_em_um_arquivo_o.c -o ./nome_qualquer.o
```

A estrutura desses comandos é a mais simples, pois nesses comandos todos os
arquivos usados na compilação devem estar no mesmo diretório, e os arquivos
gerados serão gerados no mesmo diretório. Mas tanto os arquivos utilizados na
compilação quanto os arquivos gerados pela compilação podem estar em diretórios
diferentes.

No caso de ser desejado que os arquivos compilados sejam gerados em outro
diretório, basta passar o caminho do diretório no output, no comando de
compilação:

```shell
gcc -c ./nome_do_arquivo_a_ser_compilado_em_um_arquivo_o.c -o ./diretorio-destino/nome_qualquer.o
```

Caso os cabeçalhos, os arquivos de extensão `.h`, estejam em um diretório
diferente do arquivo a ser compilado, basta usar a flag `-I` no comando passando
o diretório dos arquivos `.h` onde o compilador deve procurar os cabeçalhos:

```shell
gcc -c ./nome_do_arquivo_a_ser_compilado_em_um_arquivo_o.c -I ./diretorio-de-dependencias/ -o ./diretorio-destino/nome_qualquer.o
```

Dos vídeos 39 ao 46, há conteúdo sobre organização de projetos C e compilação de
códigos C. Portanto, do vídeo 39 em diante a compilação será feita de acordo com
a forma e a estrutura de projeto apresentadas a seguir.

## Organização de projetos em C

Nesse curso a organização padrão usada será a seguinte:

```shell
.
├── apps
│   └── app.c
├── bin
│   └── app
├── include
│   └── float_vector.h
├── lib
│   └── libed.a
├── obj
│   └── float_vector.o
└── src
    └── float_vector.c
```

, onde teremos:

- o diretório `apps` para os arquivos fontes dos *executáveis*;
- o diretório `bin` para os arquivos *executáveis*;
- o diretório `include` para os arquivos de cabeçalho;
- o diretório `lib` para o arquivo de biblioteca estática;
- o diretório `obj` para os arquivos *objetos*;
- e o diretório `src` um para os arquivos de implementação dos cabeçalhos.

O comando para compilar o arquivo `float_vector.c` em um arquivo
`float_vector.o` e armazenar esse objeto no diretório `./obj` é:

```shell
gcc -c ./src/float_vector.c -I ./include -o ./obj/float_vector.o
```

O comando para compilar o arquivo `app.c` em um executável e armazenar esse
executável no diretório `./bin` é:

```shell
gcc ./apps/app.c ./obj/float_vector.o -I ./include -o ./bin/app
```

## Compilando arquivos em C com Makefile

Makefile é um arquivo utilizado pelo utilitário ***make***, em sistemas Unix e
Unix-like, para automatizar a execução de comandos no shell.

Nesse curso são apresentados três targets principais: ***all***, ***run*** e
***clean***.

- O target ***all*** será usado para executar os comandos de compilação de
*objetos* e *executáveis*. Para usar esse target basta usar o comando `make` no
terminal.
- O target ***run*** será usado para executar o arquivo *executável*. Para usar
esse target basta usar o comando `make run` no terminal.
- O target ***clean*** será usado para remover os arquivos *objetos*,
*executáveis* e *bibliotecas estáticas*. Para usar esse target basta usar o
comando `make clean` no terminal.

Considerando o exemplo de organização de projeto apresentado acima, o arquivo
Makefile terá os seguintes comandos:

```makefile
all:
    gcc -c ./src/float_vector.c -I ./include -o ./obj/float_vector.o
    gcc ./apps/app.c ./obj/float_vector.o -I ./include -o ./bin/app

run:
    ./bin/app

clean:
    rm -rf ./bin/app ./obj/float_vector.o
```

Como uma forma de deixar o código mais organizado, caso seja necessária a
compilação de vários objetos para o programa principal, e/ou a renomeação de
diretórios do projeto, podemos criar variáveis e usar o operador `*` para que
seja selecionado todo o conteúdo de um diretório, ou todo o conteúdo de um
diretório que siga determinado padrão de nomenclatura.

```makefile
APPS = ./apps
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src


all:
    gcc -c $(SRC)/float_vector.c -I $(INCLUDE) -o $(OBJ)/float_vector.o
    gcc $(APPS)/app.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app

run:
    $(BIN)/app

clean:
    rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*
```

Agora, para dividir de forma mais clara as funções dos targets e não
"sobrecarregar" o target ***all***, serão criados dois novos targets sendo um
para a compilação dos *objetos* e um para a compilação dos *executáveis*.

```makefile
libed:
    gcc -c $(SRC)/float_vector.c -I $(INCLUDE) -o $(OBJ)/float_vector.o

my_apps:
    gcc $(APPS)/app.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app
```

Para vincular esses dois novos targets ao target ***all***, basta adicioná-los
como dependência de ***all*** colocando-os na mesma linha, logo após o sinal de
dois pontos:

```makefile
APPS = ./apps
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src


all: libed my_apps

libed:
    gcc -c $(SRC)/float_vector.c -I $(INCLUDE) -o $(OBJ)/float_vector.o

my_apps:
    gcc $(APPS)/app.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app

run:
    $(BIN)/app

clean:
    rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*
```

Dessa forma, os comandos serão executados na ordem que foram escritos em cada
target e na ordem em que foram adicionados como dependência ao target ***all***.

Agora vamos supor um cenário em que há vários arquivos C que devem ser
compilados em arquivos *executáveis*. Seria necessário a seguinte alteração no
target `libed`:

```makefile
libed:
    gcc -c $(SRC)/float_vector.c   -I $(INCLUDE) -o $(OBJ)/float_vector.o
    gcc -c $(SRC)/outro_arquivo1.c -I $(INCLUDE) -o $(OBJ)/outro_arquivo1.o
    gcc -c $(SRC)/outro_arquivo2.c -I $(INCLUDE) -o $(OBJ)/outro_arquivo2.o
    gcc -c $(SRC)/outro_arquivo3.c -I $(INCLUDE) -o $(OBJ)/outro_arquivo3.o
    gcc -c $(SRC)/outro_arquivo4.c -I $(INCLUDE) -o $(OBJ)/outro_arquivo4.o
    gcc -c $(SRC)/outro_arquivo5.c -I $(INCLUDE) -o $(OBJ)/outro_arquivo5.o
```

Note que todos os comandos são iguais, exceto por duas coisas: o nome do arquivo
de origem e o nome desejado para o arquivo compilado. É possível usar o nome
desejado do arquivo compilado como um novo target, colocar o comando de
compilação nesse target e colocar esse target como dependência de ***libed***.
Fazendo isso não será mais necessário repetir o mesmo comando várias vezes.
Basta colocar os nomes desejados dos arquivos compilados como dependências de
***libed***. Mas como os nomes dos arquivos serão todos diferentes, com excessão
da extensão `.o`, uma forma de generalizar o nome desse target é usando o
operador `%`, que, para o ***make***, é equivalente ao operador `*` em sistemas
unix.

```makefile
%.o:
    gcc -c $< -I $(INCLUDE) -o $(OBJ)/$@
```

Além disso, também usaremos o arquivo de origem e suas dependências como
dependências do target ***%.o***. Dessa forma, o ***make*** irá checar se esses
arquivos existem, em seus respectivos diretórios, antes de executar o comando de
compilação.

```makefile
%.o: $(SRC)/%.c $(INCLUDE)/%.h
    gcc -c $< -I $(INCLUDE) -o $(OBJ)/$@
```

Utilizando como exemplo o arquivo `float_vector` temos que quando o target
***%.o*** for chamado,  o ***make*** checará pela existência dos arquivos
`float_vector.c` no diretório `./src` e `float_vector.h` no diretório
`./include`. Após isso, irá executar o comando de compilação passando
`float_vector.c` como arquivo fonte; `./include` como diretório onde o ***gcc***
deve buscar cabeçalhos; `./obj` como diretório de destino do arquivo *objeto*; e
o nome do target como nome do arquivo *objeto*.

O target ***%.o*** será "traduzido" em:

```makefile
float_vector.o: ./src/float_vector.c ./include/float_vector.h
    gcc -c ./src/float_vector.c -I ./include -o ./obj/float_vector.o
```

Portanto, para usar esse target genérico na chamada `make` do cenário imaginado,
podemos atualizar o target `libed` para:

```makefile
libed: /
    float_vector.o /
    outro_arquivo1.o /
    outro_arquivo2.o /
    outro_arquivo3.o /
    outro_arquivo4.o /
    outro_arquivo5.o /
```

Dessa forma, o arquivo fica mais limpo.

O caractere `\` permite uma quebra de linha, mas o ***make*** lê como se todas
as dependências estivessem na mesma linha.

Voltando ao exemplo anterior, o arquivo Makefile, a esta altura, está com a
seguinte estrutura:

```makefile
APPS = ./apps
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src


all: libed my_apps

libed: float_vector.o

my_apps:
    gcc $(APPS)/app.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app

%.o: $(SRC)/%.c $(INCLUDE)/%.h
    gcc -c $< -I $(INCLUDE) -o $(OBJ)/$@

run:
    $(BIN)/app

clean:
    rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*
```

Desta forma, basta usar o comando `make` no terminal, que ele chamará o target
`libed`, que chamará o target `%.o` passando o nome de cada dependência,
e depois chamará o target `my_apps`.

Mas há um problema com essa estrutura. Caso o projeto possua vários arquivos a
serem compilados e seja necessário fazer alteração em apenas um desses arquivos,
na hora que o comando `make` for executado no terminal todos os arquivos serão
(re)compilados. Independente de terem sido alterados ou não. Para evitar isso,
podemos usar como target o caminho relativo dos arquivos *objetos*. Fazendo
isso e considerando que já estamos passando como dependências do target
***%.o*** o seu arquivo de origem e suas dependências, o comando de compilação
só será executado se alguma alteração tiver sido feita nos arquivos de suas
dependências entre a última execução desse comando e a execução atual.

Faremos então a alteração na target genérica ***%.o*** e nas dependências de
***libed***.

```makefile
APPS = ./apps
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src


all: libed my_apps

libed: $(OBJ)/float_vector.o

my_apps:
    gcc $(APPS)/app.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
    gcc -c $< -I $(INCLUDE) -o $@

run:
    $(BIN)/app

clean:
    rm -rf $(BIN)/* $(OBJ)c/*
```

De forma semelhante, vamos escrever um target genérico para a compilação de
arquivos *executáveis*, usando como nome do target o caminho relativo com o nome
desejado do arquivo, e colocando como dependência desse novo target o arquivo
fonte do arquivo *executável*. Além disso, iremos colocar esse novo target como
dependência de ***my_apps***.

```makefile
$(BIN)/%: $(APPS)/%.c
    gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@
```

Utilizando como exemplo o arquivo executável `app` temos que quando o target
***$(BIN)\/%*** for chamado, o ***make*** checará pela existência do arquivo
`app.c` no diretório `./apps`. Após isso, irá executar o comando de compilação
passando `app.c` como arquivo fonte; todos os arquivos que possuem extensão `.o`
e estão no diretório `./obj` como dependências; `./include` como diretório onde
o ***gcc*** deve buscar cabeçalhos; e o caminho `./bin/app` como destino e nome
do arquivo *executável*.

O target acima será "traduzido" em:

```makefile
./bin/app: ./apps/app.c
    gcc ./apps/app.c ./obj/*.o -I ./include -o ./bin/app
```

Atualizando o código do arquivo Makefile, temos:

```makefile
APPS = ./apps
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src


all: libed my_apps

libed: $(OBJ)/float_vector.o

my_apps: $(BIN)/app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
    gcc -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
    gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@

run:
    $(BIN)/app

clean:
    rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*
```

Nessa última target criada, a única dependência que lhe foi atribuída foi a
dependência da existência do arquivo de origem do arquivo *executável*. Porém,
caso alguma alteração seja feita em uma das dependências do arquivo de origem,
seria necessário que a execução desse target fosse impedida para evitar que o
arquivo executável seja compilado com código defasado. Mas isso não está sendo
feito. Uma forma de prevenir que o arquivo *executável* seja compilado com
código defasado, é criando um novo target para limpar todos os arquivos do
diretório **bin**, e somente do diretório **bin**, antes da compilação dos
arquivos *executáveis*:

```makefile
clean_apps:
    rm -rf $(BIN)/*
```

Vamos colocar esse novo target como primeira dependência do target
***my_apps***:

```makefile
APPS = ./apps
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src


all: libed my_apps

libed: $(OBJ)/float_vector.o

my_apps: \
    clean_apps \
    $(BIN)/app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
    gcc -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
    gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@

run:
    $(BIN)/app

clean:
    rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*

clean_apps:
    rm -rf $(BIN)/*
```

Dessa forma, antes de executar o target que possui o comando de compilação dos
arquivos *executáveis*, o ***make*** executará o target ***clean_apps***.

Vamos também adicionar algumas flags do ***gcc*** aos comandos criados no
arquivo Makefile. A primeira é a flag `-O3`, que tenta otimizar o código fonte
antes da compilação, e a segunda é a flag `-Wall`, que mostra todos os warnings
gerados. Colocaremos essas flags em uma variável e adicionaremos essa variável
aos comandos desejados. No nosso caso, serão os comandos de compilação dos
arquivos *executáveis* e dos arquivos *objetos*. Adicionaremos a variável das
flags logo no início dos comandos.

```makefile
APPS = ./apps
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

FLAGS = -O3 -Wall

all: libed my_apps

libed: $(OBJ)/float_vector.o

my_apps: clean_apps \
    $(BIN)/app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
    gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
    gcc $(FLAGS) $< $(OBJ)/*.o -I $(INCLUDE) -o $@

run:
    $(BIN)/app

clean:
    rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*

clean_apps:
    rm -rf $(BIN)/*
```

Além disso vamos adicionar um comando ao target ***libed*** para criar uma
biblioteca estática com todos os arquivos *objetos* que estiverem no diretório
`./obj` em um único arquivo de extensão `.a` no diretório `./lib`. O arquivo de
extensão `.a` deve ter o nome iniciado com "lib".

```makefile
APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
LIB = ./lib
SRC = ./src

FLAGS = -O3 -Wall

all: libed my_apps

libed: $(OBJ)/float_vector.o
    ar -rcs $(LIB)/libed.a $(OBJ)/*.o

my_apps: clean_apps \
    $(BIN)/app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
    gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
    gcc $(FLAGS) $< $(OBJ)/*.o -I $(INCLUDE) -o $@

run:
    $(BIN)/app

clean:
    rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*

clean_apps:
    rm -rf $(BIN)/*
```

Agora que estamos criando um único arquivo que contém todos os arquivos
*objetos*, podemos alterar o comando de compilação de arquivos *executáveis*
substituindo a passagem de todos os arquivos de extensão `.o` pela passagem do
arquivo de extensão `.a`. Podemos fazer isso passando o caminho relativo
diretamente ao comando ou podemos usar a flag `-l`, que procura uma biblioteca
com o nome desejado em um diretório desejado. A flag `-l` nos dá a possibilidade
de usarmos bibliotecas mesmo que estejam fora do projeto. Basta passarmos o
diretório onde a biblioteca pode ser encontrada. Por conta disso, usaremos a
opção com a flag.

Ao utilizar essa flag, não podemos passar o nome da biblioteca estática com a
palavra "lib". Portanto, ao invés de passarmos "-llibed", usaremos "-led":

```makefile
APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
LIB = ./lib
SRC = ./src

FLAGS = -O3 -Wall

all: libed my_apps

libed: $(OBJ)/float_vector.o
    ar -rcs $(LIB)/libed.a $(OBJ)/*.o

my_apps: clean_apps \
    $(BIN)/app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
    gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
    gcc $(FLAGS) $< -led -L $(LIB) -I $(INCLUDE) -o $@

run:
    $(BIN)/app

clean:
    rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*

clean_apps:
    rm -rf $(BIN)/*
```

Por motivos de organização, iremos colocar a inclusão de bibliotecas estáticas
em uma variável chamada `LIBS`, e usar a variável no comando. Dessa forma, caso
seja necessária a inclusão de várias bibliotecas, o comando não fica poluído.

```makefile
APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
LIB = ./lib
SRC = ./src

FLAGS = -O3 -Wall
LIBS = -led -L $(LIB)

all: libed my_apps

libed: $(OBJ)/float_vector.o
    ar -rcs $(LIB)/libed.a $(OBJ)/*.o

my_apps: clean_apps \
    $(BIN)/app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
    gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
    gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

run:
    $(BIN)/app

clean:
    rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*

clean_apps:
    rm -rf $(BIN)/*
```

Esta é a estrutura final do arquivo Makefile utilizado no curso.
