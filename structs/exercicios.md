# Exercícios sobre Structs

Para os exercícios abaixo, simule a alocação e o comportamento das variáveis na
memória *RAM*. Divida-a em memória *Stack* ou *Heap* se necessário.

Considere que o primeiro endereço de memória *Stack* disponível é ***S000***, e
de memória *Heap* ***H000***.

Considere os seguintes tamanhos para cada tipo primário:

- ***char*** = 1 byte
- ***int*** = 4 bytes
- ***long*** = 8 bytes
- ***float*** = 4 bytes
- ***double*** = 8 bytes
- ***ponteiros*** = 8 bytes

Considere a *struct* abaixo:

```c
typedef struct _livro {
    char titulo[100];
    float preco;
    int n_paginas;
} Livro;
```

Considere também a seguinte função:

```c
Livro *CriaLivro(char titulo[], float preco, int n_paginas) {
    Livro *livro = (Livro*) calloc(1, sizeof(Livro));
    strcpy(livro->titulo, titulo);
    livro->preco = preco;
    livro->n_paginas = n_paginas;

    return livro;
}
```

## 1. Qual a saída do programa abaixo que imprime o tamanho das variáveis? Explique sua resposta.

```c
int main() {
    Livro livro1;
    Livro *livro2 = (Livro*) calloc(1, sizeof(Livro));

    printf("Tamanho livro: %ld bytes\n", sizeof(livro1));
    printf("Tamanho livro: %ld bytes\n", sizeof(livro2));

    return 0;
}
```

### Resolução

Na primeira linha de código há a declaração da variável `livro1`, do tipo
`Livro`. Ela é alocada na memória ***Stack***. Como não lhe foi atribuído nenhum
valor, o espaço de memória ocupado por essa variável possui lixo de memória.

Para saber quanto de memória essa variável ocupa, temos que analisar e somar o
quanto de memória cada campo da *struct* `Livro` ocupa. A *struct* é composta
pelos seguintes campos:

- ***char titulo[100];***

    Temos que o tipo ***char*** possui tamanho de 1 byte. Como o campo `titulo`
    possui 100 chars, esse campo ocupa 100 bytes.

- ***float preco;***

    Temos que o tipo ***float*** possui tamanho de 4 bytes. 

- ***int n_paginas;***

    Temos que o tipo ***int*** possui tamanho de 4 bytes.

Portanto, uma variável do tipo `Livro` ocupa 108 bytes. Logo, a variável
`livro1` ocupa 108 bytes de memória.

Na segunda linha de código há a declaração do ponteiro `livro2`, que é alocado
na memória ***Stack***, pois toda e qualquer variável declarada é alocada na
memória ***Stack***, e há a alocação de memória ***Heap*** através da função
`calloc`.

A função `calloc` aloca na memória ***Heap*** uma quantidade de espaço definido
nos argumentos que lhe são passados. Os argumentos passados na sua chamada são
`(1, sizeof(Livro))`, o que resulta em uma alocação de memória equivalente a 1
vez o tamanho de uma variável do tipo `Livro`. Ou seja, o espaço alocado na
memória ***Heap*** nessa chamada da função `calloc` é de 108 bytes. Após fazer
a alocação, a função `calloc` retorna o endereço de memória do bloco de memória
alocado. Portanto, no nosso caso, esse endreço é armazenado no ponteiro
`livro2`.

Na terceira linha de código é chamada uma função para exibição de valores. Nesta
chamada, passasse como argumento a função `sizeof(livro1)`, que retorna o
tamanho da variável `livro1`. Já sabemos que esse valor é de 108 bytes.
Portanto, esta chamada dessa função exibirá: "Tamanho livro: 108 bytes".

Na quarta linha de código, a mesma função é chamada, mas agora é passado como
argumento a função `sizeof(livro2)`, que agora retorna o tamanho da variável
`livro2`, que é um ponteiro. Apesar de essa variável apontar para um endereço de
memória que aloca o tipo `Livro`, por ela ser um ponteiro o espaço de memória
que ela ocupa é 8 bytes. Portanto, esta chamada dessa função exibirá: "Tamanho
livro: 8 bytes".

## 2. Analise o trecho de código abaixo e explique se os itens propostos funcionam ou não. Utiliza a representação de memória se necessário.

```c
Livro livro1 = {.titulo = "Harry Potter 1", .preco = 30.0, .n_paginas = 250};
Livro *livro2 = CriaLivro("O Segredis de Cacildis", 10.0, 100);
```

- **printf("titulo1 = %s\n", livro1.titulo);**

    Funciona. Como `livro1` é um objeto do tipo `Livro`, o acesso aos seus
    campos é direto por meio do ponto. Logo. `livro1.titulo` retorna o valor
    desse campo.

- **printf("titulo1 = %s\n", livro1->titulo);**

    Não funciona. O acesso por meio da seta funciona em variáveis tipo ponteiro.
    `livro1` não é uma variável ponteiro, portanto essa sintaxe está errada.

- **printf("titulo1 = %s\n", &livro1->titulo);**

    Não funciona. A sintaxe C não considera `&livro1` como um ponteiro.

- **printf("titulo1 = %s\n", (&livro1)->titulo);**

    Funciona. A sintaxe C considera `(&livro1)` como um ponteiro para a variável
    `livro1`, e a forma de acessar os campos de uma *struct* através de um
    ponteiro é com o uso da seta.

- **printf("titulo2 = %s\n", livro2.titulo);**

    Não funciona. O acesso por ponto funciona em variáveis que sejam do tipo
    *struct*. Como `livro2` é um ponteiro, essa sintaxe está errada.

- **printf("titulo2 = %s\n", livro2->titulo);**

    Funciona. Como `livro2` é um ponteiro, a sintaxe da seta é a sintaxe correta
    para acessar os campos da *struct* via ponteiro.

- **printf("titulo2 = %s\n", \*livro2.titulo);**

    Não funciona. A sintaxe C não considera `*livro2` como uma forma válida de
    ter acesso ao conteúdo da *struct* referenciada pelo ponteiro `livro2`.

- **printf("titulo2 = %s\n", (\*livro2).titulo);**

    Funciona. A sintaxe C considera `(*livro2)` como uma forma válida de ter
    acesso ao conteúdo do ponteiro `livro2`, e como o conteúdo do ponteiro
    `livro2` é uma *struct*, o acesso aos seus campos é feito através do ponto.

- **printf("titulo2 = %s\n", livro2[0].titulo);**

    Funciona. Na alocação de memória utilizando `calloc`, ou `malloc`, o bloco
    de memória pode ser acessado como se fosse um vetor. Nesse caso, `livro2[0]`
    estaria acessando o único elemento do vetor alocado na memória ***Heap***.
    Como esse elemento é uma *struct*, o acesso por ponto aos seus campos é
    válido.