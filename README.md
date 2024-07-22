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

O comando usado para compilar os arquivos C é:

```shell
gcc .\nome_do_arquivo.c -o .\nome_desejado_do_arquivo_compilado
```

O comando utilizado para executar o arquivo executável (arquivo compilado) é:

```shell
.\nome_do_arquivo_compilado
```

O comando para criar um arquivo `.o` é:

```shell
gcc -c .\nome_do_arquivo_a_ser_compilado_em_um_arquivo_o.c
```

Quando se cria um arquivo `.o`, é necessário incluí-lo no comando de compilação
do arquivo C do qual se quer gerar o arquivo executável. O comando usado é:

```shell
gcc .\nome_do_arquivo.c .\nome_do_arquivo.o -o .\nome_desejado_do_arquivo_compilado
```

Se tiver que criar um executável que utiliza mais de um arquivo `.o`, basta
adicionar todos os arquivos `.o` no comando de compilação, da seguinte forma:

```shell
gcc .\nome_do_arquivo.c .\nome_do_arquivo1.o .\nome_do_arquivo2.o -o .\nome_desejado_do_arquivo_compilado
```
