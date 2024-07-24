# Dominando Estruturas de Dados 1

Esse repositório possui minhas anotações e resoluções dos exercícios desse curso
ministrado pelo professor [Samuel Martins](https://samucoding.com/), na playlist
[Curso: Dominando Estruturas de Dados 1](https://youtube.com/playlist?list=PL3ZslI15yo2r-gHJtjORRMRKMSNRpf7u5&si=qsr2zwmTDhn-o_yK)
em seu canal no Youtube [xavecoding](https://www.youtube.com/@xavecoding).

Importante
---

- O Sistema Operacional utilizado foi Windows 11,
- O compilador utilizado foi o ***gcc***
---

</br>

Na primeira parte do curso, dos vídeos 1 ao 38, o comando usado para compilar os
arquivos C foi:

```shell
gcc .\nome_do_arquivo.c -o .\nome_desejado_do_arquivo_compilado
```

O comando utilizado para executar o arquivo executável (arquivo compilado) foi:

```shell
.\nome_do_arquivo_compilado
```

O comando para criar um arquivo `.o` foi:

```shell
gcc -c .\nome_do_arquivo_a_ser_compilado_em_um_arquivo_o.c
```

Quando se cria um arquivo `.o`, é necessário incluí-lo no comando de compilação
do arquivo C do qual se quer gerar o arquivo executável. O comando usado foi:

```shell
gcc .\nome_do_arquivo.c .\nome_do_arquivo.o -o .\nome_desejado_do_arquivo_compilado
```

## Compilando códigos C

Dos vídeos 39 ao 46, há conteúdo sobre organização de projetos C e compilação de
códigos C. Daqui para frente a compilação será feita de forma diferente.

Como mostrado anteriormente, os comandos usados para compilar os arquivos C
foram:

```shell
gcc .\nome_do_arquivo.c -o .\nome_desejado_do_arquivo_compilado
```

e

```shell
gcc -c .\nome_do_arquivo_a_ser_compilado_em_um_arquivo_o.c
```

O segundo comando mostrado acima não especifica nenhum nome de saída ao
compilador. Portanto, o compilador, por padrão, dá ao arquivo gerado o mesmo
nome do arquivo de origem, mudando somente a extensão para `.o`. Mas, assim como
no comando de compilar um arquivo executável, é possível dar um outro nome
qualquer ao objeto compilado com o comando:

```shell
gcc -c .\nome_do_arquivo_a_ser_compilado_em_um_arquivo_o.c -o .\nome_qualquer.o
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
gcc -c .\nome_do_arquivo_a_ser_compilado_em_um_arquivo_o.c -o .\diretorio-destino\nome_qualquer.o
```

Caso os cabeçalhos, os arquivos de extensão `.h`, estejam em um diretório
diferente do arquivo a ser compilado, basta usar a flag `-I` no comando passando
o diretório dos arquivos `.h` onde o compilador deve procurar os cabeçalhos:

```shell
gcc -c .\nome_do_arquivo_a_ser_compilado_em_um_arquivo_o.c -I .\diretorio-de-dependencias\ -o .\diretorio-destino\nome_qualquer.o
```

## Organização de projetos em C

Nesse curso a organização padrão usada será a seguinte:

```shell
.
├───apps
│   └───app.c
│
├───bin
│   └───app.exe
│
├───include
│   └───float_vector.h
│
├───lib
│   └───libed.a
│
├───obj
│   └───float_vector.o
│
└───src
    └───float_vector.c
```

, onde teremos:

- o diretório `apps` para os arquivos fontes dos executáveis;
- o diretório `bin` para os arquivos executáveis;
- o diretório `include` para os arquivos de cabeçalho;
- o diretório `lib` para o arquivo de biblioteca estática;
- o diretório `obj` para os arquivos de objetos;
- e o diretório `src` um para os arquivos de implementação dos cabeçalhos.

O comando para compilar o arquivo `float_vector.c` em um arquivo
`float_vector.o` e armazenar esse objeto no diretório `obj` é:

```shell
gcc -c .\src\float_vector.c -I .\include -o .\obj\float_vector.o
```

O comando para compilar o arquivo `app.c` em um executável e armazenar esse
executável no diretório `bin` é:

```shell
gcc .\apps\app.c .\obj\float_vector.o -I .\include -o .\bin\app
```

## Compilando arquivos em C com Makefile

Makefile é um arquivo utilizado pelo utilitário ***make***, em sistemas Unix e
Unix-like, para automatizar a compilação de arquivos e execução de comandos no
shell.

Nesse curso são apresentados três targets principais: ***all***, ***run*** e
***clean***.

- O target ***all*** será usado para executar os comandos de compilação de
*objetos* e *executáveis*. Para usar esse target basta usar o comando `make` no
terminal.
- O target ***run*** será usado para executar o arquivo *executável*. Para usar
esse target basta usar o comando `make run` no terminal.
- O target ***clean*** será usado para remover os arquivos *objetos* e
*executáveis*. Para usar esse target basta usar o comando `make clean` no
terminal.

Considerando o exemplo de organização de projeto apresentado acima, o arquivo
Makefile terá os seguintes comandos:

```makefile
all:
    gcc -c .\src\float_vector.c -I .\include -o .\obj\float_vector.o
    gcc .\apps\app.c .\obj\float_vector.o -I .\include -o .\bin\app

run:
    .\bin\app

clean:
    rm -rf .\bin\app .\obj\float_vector.o
```

Como uma forma de deixar o código mais organizado, caso sejam necessários a
compilação de vários objetos para o programa principal, e de renomear as pastas,
podemos criar variáveis e usar o operador `*` para que seja selecionado todo o
conteúdo de uma pasta, ou todo o conteúdo de uma pasta que siga determinado
padrão de nome.

```makefile
APPS = APPS
BIN = .\bin
INCLUDE = .\include
OBJ = .\obj
SRC = .\src


all:
    gcc -c $(SRC)\float_vector.c -I $(INCLUDE) -o $(OBJ)\float_vector.o
    gcc $(APPS)\app.c $(OBJ)\*.o -I $(INCLUDE) -o $(BIN)\app

run:
    $(BIN)\app

clean:
    rm -rf $(BIN)\* $(OBJ)\*
```

Agora, para dividir de forma mais clara as funções dos targets e não
"sobrecarregar" o arget ***all***, serão criados dois novos targets sendo um
para a compilação dos *objetos* e um para a compilação dos *executáveis*.

```makefile
libed:
    gcc -c $(SRC)\float_vector.c -I $(INCLUDE) -o $(OBJ)\float_vector.o

myapps:
    gcc $(APPS)\app.c $(OBJ)\*.o -I $(INCLUDE) -o $(BIN)\app
```

Para vincular esses dois novos targets ao target ***all***, basta adicioná-los
como dependência do ***all*** da seguinte forma:

```makefile
APPS = APPS
BIN = .\bin
INCLUDE = .\include
OBJ = .\obj
SRC = .\src


all: libed myapps

libed:
    gcc -c $(SRC)\float_vector.c -I $(INCLUDE) -o $(OBJ)\float_vector.o

myapps:
    gcc $(APPS)\app.c $(OBJ)\*.o -I $(INCLUDE) -o $(BIN)\app

run:
    $(BIN)\app

clean:
    rm -rf $(BIN)\* $(OBJ)\*
```

Dessa forma, os comandos serão executados na ordem que foram escritos em cada
target e na ordem em que forma adicionados ao target ***all***.

Agora vamos supor um cenário em que há vários arquivos C que devem ser
compilados em arquivos *executáveis*. Seria necessário a seguinte alteração no 
arget `libed`:

```makefile
libed:
    gcc -c $(SRC)\float_vector.c   -I $(INCLUDE) -o $(OBJ)\float_vector.o
    gcc -c $(SRC)\outro_arquivo1.c -I $(INCLUDE) -o $(OBJ)\outro_arquivo1.o
    gcc -c $(SRC)\outro_arquivo2.c -I $(INCLUDE) -o $(OBJ)\outro_arquivo2.o
    gcc -c $(SRC)\outro_arquivo3.c -I $(INCLUDE) -o $(OBJ)\outro_arquivo3.o
    gcc -c $(SRC)\outro_arquivo4.c -I $(INCLUDE) -o $(OBJ)\outro_arquivo4.o
    gcc -c $(SRC)\outro_arquivo5.c -I $(INCLUDE) -o $(OBJ)\outro_arquivo5.o
```

Note que todos os comandos são iguais, exceto por duas coisas: o nome do arquivo
de origem e o nome do arquivo compilado. É possível escrever um comando que faça
toda a montagem da estrutura do comando de compilação passando somente o nome do
arquivo:

```makefile
%.o: $(SRC)\%.c $(INCLUDE)\%.h
    gcc -c $< -I $(INCLUDE) -o $(OBJ)\%@
```

Utilizaremos como exemplo o arquivo `float_vector` como exemplo. O comando acima
deve ser usado, por exemplo, digitando `make float_vector.o` no terminal.
Fazendo isso, teremos que a primeira linha do comando checará pela existência
das dependências `float_vector.c` no diretório `.\src` e `float_vector.h` no
diretório `.\include`.

```makefile
%.o: .\src\float_vector.c .\include\float_vector.h
```

Caso esses arquivos existam nesses diretórios, a segunda linha do target será
executada. A segunda linha se "traduz" em:

```makefile
gcc -c .\src\float_vector.c -I .\include -o .\obj\float_vector.o
```

Para usar esse target genérico na chamada `make`, podemos atualizar o target
`libed` para:

```makefile
libed: \
    float_vector.o \
    outro_arquivo1.o \
    outro_arquivo2.o \
    outro_arquivo3.o \
    outro_arquivo4.o \
    outro_arquivo5.o \
```

Dessa forma, o arquivo fica mais limpo.

Voltando ao exemplo anterior, o arquivo Makefile, a esta altura, está com a
seguinte estrutura:

```makefile
APPS = APPS
BIN = .\bin
INCLUDE = .\include
OBJ = .\obj
SRC = .\src


all: libed myapps

libed: float_vector.o

myapps:
    gcc $(APPS)\app.c $(OBJ)\*.o -I $(INCLUDE) -o $(BIN)\app

%.o: $(SRC)\%.c $(INCLUDE)\%.h
    gcc -c $< -I $(INCLUDE) -o $(OBJ)\%@

run:
    $(BIN)\app

clean:
    rm -rf $(BIN)\* $(OBJ)\*
```

Desta forma, basta usar o comando `make` no terminal, que ele chamará o target
`libed`, que chamará o target `%.o`, e depois o target `myapps`. 

Há um problema com essa estrutura. Caso o projeto possua vários arquivos a serem
compilados e seja necessário fazer a alteração em apenas um, na hora que o
comando `make` for executado no terminal, o arquivo alterado será compilado e
todos os arquivos não alterados serão recompilados. Para evitar isso, podemos
usar como target o nome completo dos arquivos *objetos* e passar como
dependência os arquivos necessários para que o *objeto* seja compilado. Fazendo
isso os arquivos só serão compilados se alguma alteração tiver sido feita nos
arquivos de suas dependências entre a última execução desse comando e a execução
atual.

Teremos então:

```makefile
APPS = APPS
BIN = .\bin
INCLUDE = .\include
OBJ = .\obj
SRC = .\src


all: libed myapps

libed: $(OBJ)\float_vector.o

myapps:
    gcc $(APPS)\app.c $(OBJ)\*.o -I $(INCLUDE) -o $(BIN)\app

$(OBJ)\%.o: $(SRC)\%.c $(INCLUDE)\%.h
    gcc -c $< -I $(INCLUDE) -o %@

run:
    $(BIN)\app

clean:
    rm -rf $(BIN)\* $(OBJ)c\*
```

Agora vamos escrever um target genérico para a compilação de arquivos
*executáveis*:

```makefile
$(BIN)\%: $(APPS)\%.c
    gcc $< $(OBJ)\*.o -I $(INCLUDE) -o %@
```

O target cima será "traduzido" em:

```makefile
.\bin\app: .\apps\app.c
    gcc $< .\obj\*.o -I .\include -o .\bin\app
```

Atualizando o código do arquivo Makefile, temos:

```makefile
APPS = APPS
BIN = .\bin
INCLUDE = .\include
OBJ = .\obj
SRC = .\src


all: libed myapps

libed: $(OBJ)\float_vector.o

myapps: $(BIN)\app

$(OBJ)\%.o: $(SRC)\%.c $(INCLUDE)\%.h
    gcc -c $< -I $(INCLUDE) -o %@

$(BIN)\%: $(APPS)\%.c
    gcc $< $(OBJ)\*.o -I $(INCLUDE) -o %@

run:
    $(BIN)\app

clean:
    rm -rf $(BIN)\* $(OBJ)\*
```

Na última target criada, a única dependência que foi colocada nela foi a
dependência da existência do arquivo de origem do arquivo *executável*. Porém,
caso alguma alteração seja feita em um dos outros arquivos necessários para o
funcionamento desse arquivo de origem, a execução dessa target não será
impedida. Para prevenir que o arquivo *executável* seja compilado sem uma
possível atualização dos outros arquivos, um novo target será criado para limpar
todos os arquivos somente da pasta **bin** antes da compilação dos arquivos
*executáveis*.

```makefile
clean_apps:
    rm -rf $(BIN)\*
```

Agora podemos atualizar as dependências do target ***myapps***:

```makefile
APPS = APPS
BIN = .\bin
INCLUDE = .\include
OBJ = .\obj
SRC = .\src


all: libed  myapps

libed: $(OBJ)\float_vector.o

myapps: clean_apps \
    $(BIN)\app

$(OBJ)\%.o: $(SRC)\%.c $(INCLUDE)\%.h
    gcc -c $< -I $(INCLUDE) -o %@

$(BIN)\%: $(APPS)\%.c
    gcc $< $(OBJ)\*.o -I $(INCLUDE) -o %@

run:
    $(BIN)\app

clean:
    rm -rf $(BIN)\* $(OBJ)\*

clean_apps:
    rm -rf $(BIN)\*
```

Dessa forma, antes de compilar os arquivos *executáveis*, o target
***clean_apps*** será executado.

Vamos adicionar algumas flags do ***gcc*** aos comandos criados no arquivo
Makefile. A primeira é a flag `-O3`, que tenta otimizar o código fonte antes da
compilação, e a segunda é a flag `-Wall`, que mostra todos os warnings gerados.

```makefile
APPS = APPS
BIN = .\bin
INCLUDE = .\include
OBJ = .\obj
SRC = .\src

FLAGS = -O3 -Wall

all: libed  myapps

libed: $(OBJ)\float_vector.o

myapps: clean_apps \
    $(BIN)\app

$(OBJ)\%.o: $(SRC)\%.c $(INCLUDE)\%.h
    gcc $(FLAGS) -c $< -I $(INCLUDE) -o %@

$(BIN)\%: $(APPS)\%.c
    gcc $(FLAGS) $< $(OBJ)\*.o -I $(INCLUDE) -o %@

run:
    $(BIN)\app

clean:
    rm -rf $(BIN)\* $(OBJ)\*

clean_apps:
    rm -rf $(BIN)\*
```

Agora vamos adicionar um comando ao target ***libed*** para criar uma biblioteca
estática com todos os arquivos *objetos* em um único arquivo de extensão `.a`. O
arquivo de extensão `.a` deve ter o nome iniciado com "lib". Vamos criar também
uma pasta de destino chamada lib para esse arquivo. Além disso vamos atualizar
o target ***clean*** para remover todos os arquivos dessa nova pasta quando for
chamado.

```makefile
APPS = APPS
BIN = .\bin
INCLUDE = .\include
OBJ = .\obj
LIB = .\lib
SRC = .\src

FLAGS = -O3 -Wall

all: libed  myapps

libed: $(OBJ)\float_vector.o
    ar -rcs $(LIB)\libed.a $(OBJ)\*.o

myapps: clean_apps \
    $(BIN)\app

$(OBJ)\%.o: $(SRC)\%.c $(INCLUDE)\%.h
    gcc $(FLAGS) -c $< -I $(INCLUDE) -o %@

$(BIN)\%: $(APPS)\%.c
    gcc $(FLAGS) $< $(OBJ)\*.o -I $(INCLUDE) -o %@

run:
    $(BIN)\app

clean:
    rm -rf $(BIN)\* $(LIB)\* $(OBJ)\*

clean_apps:
    rm -rf $(BIN)\*
```

O target compilação de arquivos *executáveis* está recebendo todos os arquivos
*objetos* no seu comando. Podemos substituir essa lista de arquivos pelo arquivo
da biblioteca estática gerada. Para fazer isso, vamos adicionar a flag `-l` que
procura uma biblioteca com o nome desejado em um diretório desejado. Fazendo
isso ao invés de passar a biblioteca `libed.a` diretamente temos a liberdade de
ter essa biblioteca fora do projeto.

```makefile
APPS = APPS
BIN = .\bin
INCLUDE = .\include
OBJ = .\obj
LIB = .\lib
SRC = .\src

FLAGS = -O3 -Wall

all: libed  myapps

libed: $(OBJ)\float_vector.o
    ar -rcs $(LIB)\libed.a $(OBJ)\*.o

myapps: clean_apps \
    $(BIN)\app

$(OBJ)\%.o: $(SRC)\%.c $(INCLUDE)\%.h
    gcc $(FLAGS) -c $< -I $(INCLUDE) -o %@

$(BIN)\%: $(APPS)\%.c
    gcc $(FLAGS) $< -led -L $(LIB) -I $(INCLUDE) -o %@

run:
    $(BIN)\app

clean:
    rm -rf $(BIN)\* $(LIB)\* $(OBJ)\*

clean_apps:
    rm -rf $(BIN)\*
```

Para evitar que o comando fique mutio grande caso seja necessário a inclusão de
várias bibliotecas, vamos criar a variável `LIBS` onde podemos colocar todas as
bibliotecas, e usar essa variável no comando.

```makefile
APPS = APPS
BIN = .\bin
INCLUDE = .\include
OBJ = .\obj
LIB = .\lib
SRC = .\src

FLAGS = -O3 -Wall
LIBS = -led -L $(LIB)

all: libed  myapps

libed: $(OBJ)\float_vector.o
    ar -rcs $(LIB)\libed.a $(OBJ)\*.o

myapps: clean_apps \
    $(BIN)\app

$(OBJ)\%.o: $(SRC)\%.c $(INCLUDE)\%.h
    gcc $(FLAGS) -c $< -I $(INCLUDE) -o %@

$(BIN)\%: $(APPS)\%.c
    gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o %@

run:
    $(BIN)\app

clean:
    rm -rf $(BIN)\* $(LIB)\* $(OBJ)\*

clean_apps:
    rm -rf $(BIN)\*
```