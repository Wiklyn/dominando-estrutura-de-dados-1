# Exercícios sobre Vetores e Alocação de Memória

## 1. Simule a memória, usando heap e stack, para o seguinte trecho de código:

```c
int i, n = 5;
int *v;
v = (int*)malloc(n * sizeof(int));

for (i = 0; i < 5; i++) {
    v[i] = i;
}
```

### Resolução

No trecho de código apresentado, temos a declaração das variáveis, de tipo
inteiro, `i` e `n`, e a declaração do ponteiro de inteiro `v`. Essas três
variáveis são armazenadas na memória **stack**, pois qualquer variável é
armazenada nessa memória.

Consideremos endereços de memória fictícios para fins didáticos, onde o primeiro
endereço de memória disponível na memória **stack** seja S0000, e, na memória
**heap** seja H0000.

Nas duas primeiras linhas do código, temos a alocação das variáveis `i` e `n` e
do ponteiro `v` na memória **stack**. Perceba que a diferença de bytes entre os
endereços alocados na memória é o tamanho do tipo de dado para qual o endereço
foi alocado. Portanto, como `i` é um valor inteiro, e o tamanho de um inteiro é
4 bytes, o próximo endereço de memória livre será 4 bytes a frente. Logo, o
próximo endereço de memória livre é S0004. O mesmo se aplica à `n`, e, portanto,
o próximo endereço de memória livre será S0008.

    Memória Heap:             |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       |
    Memória Stack:      S0008 |   #   | v
                        S0004 |   5   | n
                        S0000 |   #   | i

Note que há o número 5 no endereço de `n`, pois esse valor foi atribuído à `n`
no momento de sua locação. E há um # nos endereços de `i` e `v` representando um
lixo de memória, já que esses endereços foram alocados, mas nenhum valor foi
atribuído.

Lixo de memória é um valor aleatório que não tem sentido no nosso código. Por
isso estou representado por #.

Na terceira linha de código, a função `malloc` é chamada. Essa função reserva um
bloco de memória na memória **heap** de tamanho definido no argumento passado na
função. Como o argumento passado foi `n * sizeof(int)`, onde `n = 5` e
`sizeof(int) = 4`, a função `malloc` irá alocar um bloco de memória de tamanho
20B, que é capaz de conter 5 dados de tipo inteiro. Além disso, essa função
retorna o endereço de memória do primeiro elemento do bloco de memória alocado.
Temos esse retorno sendo armazenado no ponteiro `v`.

    Memória Heap:       H0016 |   #   | v[4]
                        H0012 |   #   | v[3]
                        H0008 |   #   | v[2]
                        H0004 |   #   | v[1]
                        H0000 |   #   | v[0]
                              |       |
    Memória Stack:      S0008 | H0000 | v
                        S0004 |   5   | n
                        S0000 |   #   | i

Nessa altura do código ainda não foi atribuído nenhum valor para o bloco de 
memória alocado na memória **heap**. Portanto, há # simbolizando lixos de
memória colocados naqueles endereços.

Na quarta linha do código, um loop for é usado para atribuir valores a cada
endereço da memória alocada na memória **heap**. A cada iteração nesse loop, o
valor de `i` é alterado um dos valores do bloco de memória alocado na memória
**heap** também é alterado.

1ª iteração:

    Memória Heap:       H0016 |   #   | v[4]
                        H0012 |   #   | v[3]
                        H0008 |   #   | v[2]
                        H0004 |   #   | v[1]
                        H0000 |   0   | v[0]
                              |       |
    Memória Stack:      S0008 | H0000 | v
                        S0004 |   5   | n
                        S0000 |   0   | i

2ª iteração:

    Memória Heap:       H0016 |   #   | v[4]
                        H0012 |   #   | v[3]
                        H0008 |   #   | v[2]
                        H0004 |   1   | v[1]
                        H0000 |   0   | v[0]
                              |       |
    Memória Stack:      S0008 | H0000 | v
                        S0004 |   5   | n
                        S0000 |   1   | i
3ª iteração:

    Memória Heap:       H0016 |   #   | v[4]
                        H0012 |   #   | v[3]
                        H0008 |   2   | v[2]
                        H0004 |   1   | v[1]
                        H0000 |   0   | v[0]
                              |       |
    Memória Stack:      S0008 | H0000 | v
                        S0004 |   5   | n
                        S0000 |   2   | i

4ª iteração:

    Memória Heap:       H0016 |   #   | v[4]
                        H0012 |   3   | v[3]
                        H0008 |   2   | v[2]
                        H0004 |   1   | v[1]
                        H0000 |   0   | v[0]
                              |       |
    Memória Stack:      S0008 | H0000 | v
                        S0004 |   5   | n
                        S0000 |   3   | i
5ª iteração:

    Memória Heap:       H0016 |   4   | v[4]
                        H0012 |   3   | v[3]
                        H0008 |   2   | v[2]
                        H0004 |   1   | v[1]
                        H0000 |   0   | v[0]
                              |       |
    Memória Stack:      S0008 | H0000 | v
                        S0004 |   5   | n
                        S0000 |   4   | i

## 2. Simule a memória, usando heap e stack, para o seguinte trecho de código:

```c
int v1[5] = {0, 1, 2, 3, 4};
int *v2, *p;
int i;

p = v1;
p[3] = p[4] = 10;

v2 = (int*)malloc(5 * sizeof(int));

for (i = 0; i < 5; i++) {
    v2[i] = v1[i];
}

free(v2);
v2 = NULL;
```

### Resolução

No trecho de código apresentado, temos a declaração das variáveis, de tipo
inteiro, `v1` e `i`, e a declaração dos ponteiros de inteiro `v2` e `p`. Essas
quatro variáveis são armazenadas na memória **stack**, pois qualquer variável é
armazenada nessa memória.

A função `malloc` reserva um bloco de memória na memória **heap**, de tamanho
definido pelo argumento passado na sua chamada, e retorna o endereço de memória
do primeiro elemento desse bloco. No código acima, o retorno da função `malloc`
está armazenado no ponteiro `v2`. Apesar de o ponteiro `v2` estar alocado na
memória **stack**, ele aponta para um bloco de memória armazenado na memória
**heap**.

Consideremos endereços de memória fictícios para fins didáticos, onde o primeiro
endereço de memória disponível na memória **stack** seja S0000, e, na memória
**heap** seja H0000.

Na primeira linha do código, temos a declaração de um array de cinco dados
inteiros. Como essa declaração está sendo feita de forma direta, sem o uso das
função `malloc` ou `calloc`, por exemplo, o array é alocado na memóra **stack**.

Perceba que a diferença de bytes entre os endereços alocados na memória de cada
item do array é o tamanho do tipo de dado para qual o endereço foi alocado.
Portanto, como os elememtos da array são dados inteiros, e o tamanho de um
inteiro é 4 bytes, o próximo endereço de memória livre será 4 bytes a frente.

    Memória Heap:             |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
    Memória Stack:            |       | 
                              |       | 
                        S0020 |       | 
                        S0016 |   4   | v1[4]
                        S0012 |   3   | v1[3]
                        S0008 |   2   | v1[2]
                        S0004 |   1   | v1[1]
                        S0000 |   0   | v1[0]

Nas segunda e terceira linhas de código, são declarados os ponteiros de inteiro
`v2` e `p`, e o inteiro `i`.

    Memória Heap:             |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
    Memória Stack:      S0028 |   #   | i
                        S0024 |   #   | p
                        S0020 |   #   | v2
                        S0016 |   4   | v1[4]
                        S0012 |   3   | v1[3]
                        S0008 |   2   | v1[2]
                        S0004 |   1   | v1[1]
                        S0000 |   0   | v1[0]

Perceba que a diferença o tamanho de bytes ocupados por um ponteiro de inteiro
também é 4 bytes. Esses valores mudam de acordo com a arquitura do sistema
usado.

Note que como no momento da declaração do array `v1` houve também a atribuição
de valores para o array, o endereço alocado para cada elemento do array possui o
valor atribuído. Já no caso dos ponteiros `v2` e `p`, e do inteiro `i`, há um #
nos seus endereços representando um lixo de memória. Isso acontece porque, na
declaração dessas variáveis os endereços foram alocados, mas nenhum valor foi
atribuído.

Lixo de memória é um valor aleatório que não tem sentido no nosso código. Por
isso estou representado por #.

Na quarta linha do código, o valor de `v1` é atribuído ao ponteiro `p`. O que
acontece é que o valor que está sendo atribuído à `p` é o endereço de memória do
primeiro elemento do array `v1`. 

    Memória Heap:             |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
    Memória Stack:      S0028 |   #   | i
                        S0024 | S0000 | p
                        S0020 |   #   | v2
                        S0016 |   4   | v1[4]
                        S0012 |   3   | v1[3]
                        S0008 |   2   | v1[2]
                        S0004 |   1   | v1[1]
                        S0000 |   0   | v1[0]

Na quinta linha do código, temos que `p[4] = 10` e `p[3] = 10`. Como `p` é um
ponteiro para o primeiro elemento do array `v1`, alterar os elementos "de `p`"
também altera os elementos de `v1`.

    Memória Heap:             |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
                              |       | 
    Memória Stack:      S0028 |   #   | i
                        S0024 | S0000 | p
                        S0020 |   #   | v2
                        S0016 |   10  | v1[4]
                        S0012 |   10  | v1[3]
                        S0008 |   2   | v1[2]
                        S0004 |   1   | v1[1]
                        S0000 |   0   | v1[0]

Na sexta linha do código a função `malloc` é chamada. Essa função reserva um
bloco de memória na memória **heap** de tamanho definido no argumento passado na
função. Como o argumento passado foi `5 * sizeof(int)`, onde `sizeof(int) = 4`,
a função `malloc` irá alocar um bloco de memória de tamanho 20B, que é capaz de
conter 5 dados de tipo inteiro. Além disso, essa função retorna o endereço de
memória do primeiro elemento do bloco de memória alocado. Temos esse retorno
sendo armazenado no ponteiro `v2`.

    Memória Heap:       H0016 |   #   | v2[4]
                        H0012 |   #   | v2[3]
                        H0008 |   #   | v2[2]
                        H0004 |   #   | v2[1]
                        H0000 |   #   | v2[0] 
                              |       | 
                              |       | 
                              |       | 
    Memória Stack:      S0028 |   #   | i
                        S0024 | S0000 | p
                        S0020 | H0000 | v2
                        S0016 |   10  | v1[4]
                        S0012 |   10  | v1[3]
                        S0008 |   2   | v1[2]
                        S0004 |   1   | v1[1]
                        S0000 |   0   | v1[0]

Na sétima linha de código um loop for é iniciado para atribuir valores aos
elementos do bloco de memória alocado na memória **heap**. A cada iteração, cada
elemento desse bloco de memória recebe o valor do elemento equivalente
pertencente ao array `v1`.

1ª iteração:

    Memória Heap:       H0016 |   #   | v2[4]
                        H0012 |   #   | v2[3]
                        H0008 |   #   | v2[2]
                        H0004 |   #   | v2[1]
                        H0000 |   0   | v2[0] 
                              |       | 
                              |       | 
                              |       | 
    Memória Stack:      S0028 |   0   | i
                        S0024 | S0000 | p
                        S0020 | H0000 | v2
                        S0016 |   10  | v1[4]
                        S0012 |   10  | v1[3]
                        S0008 |   2   | v1[2]
                        S0004 |   1   | v1[1]
                        S0000 |   0   | v1[0]

1ª iteração:

    Memória Heap:       H0016 |   #   | v2[4]
                        H0012 |   #   | v2[3]
                        H0008 |   #   | v2[2]
                        H0004 |   1   | v2[1]
                        H0000 |   0   | v2[0] 
                              |       | 
                              |       | 
                              |       | 
    Memória Stack:      S0028 |   1   | i
                        S0024 | S0000 | p
                        S0020 | H0000 | v2
                        S0016 |   10  | v1[4]
                        S0012 |   10  | v1[3]
                        S0008 |   2   | v1[2]
                        S0004 |   1   | v1[1]
                        S0000 |   0   | v1[0]

1ª iteração:

    Memória Heap:       H0016 |   #   | v2[4]
                        H0012 |   #   | v2[3]
                        H0008 |   2   | v2[2]
                        H0004 |   1   | v2[1]
                        H0000 |   0   | v2[0] 
                              |       | 
                              |       | 
                              |       | 
    Memória Stack:      S0028 |   2   | i
                        S0024 | S0000 | p
                        S0020 | H0000 | v2
                        S0016 |   10  | v1[4]
                        S0012 |   10  | v1[3]
                        S0008 |   2   | v1[2]
                        S0004 |   1   | v1[1]
                        S0000 |   0   | v1[0]

1ª iteração:

    Memória Heap:       H0016 |   #   | v2[4]
                        H0012 |   10  | v2[3]
                        H0008 |   2   | v2[2]
                        H0004 |   1   | v2[1]
                        H0000 |   0   | v2[0] 
                              |       | 
                              |       | 
                              |       | 
    Memória Stack:      S0028 |   3   | i
                        S0024 | S0000 | p
                        S0020 | H0000 | v2
                        S0016 |   10  | v1[4]
                        S0012 |   10  | v1[3]
                        S0008 |   2   | v1[2]
                        S0004 |   1   | v1[1]
                        S0000 |   0   | v1[0]

5ª iteração:

    Memória Heap:       H0016 |   10  | v2[4]
                        H0012 |   10  | v2[3]
                        H0008 |   2   | v2[2]
                        H0004 |   1   | v2[1]
                        H0000 |   0   | v2[0] 
                              |       | 
                              |       | 
                              |       | 
    Memória Stack:      S0028 |   4   | i
                        S0024 | S0000 | p
                        S0020 | H0000 | v2
                        S0016 |   10  | v1[4]
                        S0012 |   10  | v1[3]
                        S0008 |   2   | v1[2]
                        S0004 |   1   | v1[1]
                        S0000 |   0   | v1[0]

Na penúltima linha de código, o espaço alocado pela função `malloc` é liberado.

    Memória Heap:       H0016 |   #   |
                        H0012 |   #   |
                        H0008 |   #   |
                        H0004 |   #   |
                        H0000 |   #   |
                              |       |
                              |       |
                              |       |
    Memória Stack:      S0028 |   0   | i
                        S0024 | S0000 | p
                        S0020 | H0000 | v2
                        S0016 |   10  | v1[4]
                        S0012 |   10  | v1[3]
                        S0008 |   2   | v1[2]
                        S0004 |   1   | v1[1]
                        S0000 |   0   | v1[0]

Note que fica um lixo de memória nos endereços que estavam alocados na memória
**heap**.

Na última linha de código, o valor do ponteiro `v2` é alterado para `NULL`.

    Memória Heap:       H0016 |   #   |
                        H0012 |   #   |
                        H0008 |   #   |
                        H0004 |   #   |
                        H0000 |   #   |
                              |       |
                              |       |
                              |       |
    Memória Stack:      S0028 |   0   | i
                        S0024 | S0000 | p
                        S0020 |  NULL | v2
                        S0016 |   10  | v1[4]
                        S0012 |   10  | v1[3]
                        S0008 |   2   | v1[2]
                        S0004 |   1   | v1[1]
                        S0000 |   0   | v1[0]

## 3. Qual o problema do trecho de código abaixo:

```c
int v1[5] = {0, 1, 2, 3, 4};
int *v2;

v2 = (int*)malloc(5 * sizeof(int));
v2 = v1;

free(v2);
```

### Resolução

O erro ocorre na quarta linha de código. Vamos passo a passo:

Na primeira linha de código há a declaração de um vetor estático `v1`. Ao mesmo
instante há a atribuição de valores para esse vetor.

Na segunda linha de código há a declaração de um ponteiro de inteiro `v2`.

Na terceira linha de código é alocado um bloco de memória de tamanho 20B na
memória **heap** através da função `malloc`. Essa função retorna o endereço de
memória base do bloco de memória alocado. Esse endereço está sendo armazenado
no ponteiro `v2`.

Na quarta linha, é atribuído ao ponteiro `v2` o endereço base do vetor `v1`. Ou
seja, nesse momento a referência ao bloco de memória alocado na memória **heap**
é perdido. O que é um problema, já que a única forma de acessar a memória é
através de referências em ponteiros. Portanto, aquele bloco de memória ficará
ocupado e inacessível até o fim da execução do programa. Além disso, na quinta
linha ocorre a tentativa de liberar o espaço referenciado pelo ponteiro `v2` com
o uso da função `free`. Porém a função `free` só funciona para espaços de
memória **heap** e atualmente o ponteiro `v2` está referenciando um espaço de
memória na memória **stack**. Isso causará um erro de execução.

## 4. Qual o problema do trecho de código abaixo:

```c
int main() {
    int i;
    char *v;

    for (i = 0; i < 9999999; i++>) {
        v = (char*) malloc(5000 * sizeof(char)); 
    }

    return 0;
}
```

### Resolução

Sabendo que `sizeof(char) = 1 byte`, o código acima está alocando um espaço de
5000 bytes na memória **heap** a cada iteração e está atribuindo o endereço de
memória base desse bloco ao ponteiro `v`. A cada iteração o valor armazenado no
ponteiro `v` é alterado. Ou seja, a cada iteração a referência ao bloco de
memória alocado anteriormente é perdida. Supondo que a máquina tenha muita
memória livre, ao final do loop o programa terá alocado, aproximadamente, 46,57
GB de memória, da qual ele só tem referência a cerca de 5KB. Além disso, em
nenhum momento do código a memória alocada está sendo liberada. Isso causará
vazamento de memória.