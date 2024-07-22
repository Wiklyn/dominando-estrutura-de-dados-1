# Exercícios sobre Ponteiros

## 1. Escreva os valores das variáveis para cada instrução do programa abaixo. Qual a saída do programa?

```c
int main(int argc, char *argv[]) {
    int a, b, *p1, *p2;

    a = 4;
    b = 3;
    p1 = &a;
    p2 = p1;
    *p2 = *p1 + 3;
    b = b * (*p1);
    (*p2)++;
    p1 = &b;

    printf("%d %d\n", *p1, *p2);
    printf("%d %d\n", a, b);
}
```

### Resolução

Vou explicar o que acontece linha por linha do corpo da função acima para chegar
na saída da função.

- Nas três primeiras linhas temos a declaração das variáveis presentes no corpo
da função e a atribuição de valores às variáveis `a` e `b`. 

```c
int a, b, *p1, *p2;

a = 4;
b = 3;
```

- Na quarta linha o endereço de `a` é atribuído à variável `p1`.

```c
p1 = &a;
```

- Na quinta linha o valor de `p1` é atribuído à `p2`. Como o valor de `p1` é o
endereço de `a`, o valor de `p2` também será o endereço de `a`.

```c
p2 = p1;
```

- Na sexta linha o conteúdo presente no endereço armazenado em `p2` é alterado.
Temos que o endereço armazenado em `p2` é o endereço de `a`. E o conteúdo desse
endereço é o valor de `a`. Portanto, o valor de `a` será alterado. O mesmo vale
para `p1`. Portanto, na sexta linha temos a expressão `a = 4 + 3`, o que resulta
em `a = 7`.

```c
*p2 = *p1 + 3;
```

- Na sétima linha o valor de `b` é alterado para ser o produto entre `b` e o
conteúdo do endereço de memória armazenado em `p1`, que já sabemos que é o valor
de `a`. Portanto, na sétima linha temos a expressão `b = 3 * 7`, o que resulta
em `b = 21`.

```c
b = b * (*p1);
```

- Na oitava linha o conteúdo do endereço de memória armazenado em `p2`, que já
sabemos que é o valor de `a`, é incrementado em uma unidade. Portanto, na oitava
linha temos a expressão `7++`, o que resulta em `8`. 

```c
(*p2)++;
```

- Na nona linha o endereço de `b` é armazenado em `p1`.

```c
p1 = &b;
```

- Na décima linha os valores dos conteúdos dos endereços de memória armazenados
em `p1` e `p2` são exibidos na tela. Portanto, o resultado é:

```c
printf("%d %d\n", *p1, *p2);

// 21 8
```

- Na décima primeira linha os valores de `a` e `b` são exibidos na tela.
Portanto, o resultado é:

```c
printf("%d %d\n", a, b);

// 8 21
```
