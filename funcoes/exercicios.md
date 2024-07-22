# Exercícios sobre Funções

## 1. Mostre todos os passos (teste de mesa) do programa abaixo e identifique o que é impresso pelo programa.

```c
void func(int *px, int *py) {
    px = py;
    *py = (*py) * (*px);
    *px = *px + 2;
}

int main() {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    func(&x, &y);

    printf("x = %d, y = %d\n", x, y);
    
    return 0;
}
```

### Resolução

Vou explicar o que acontece linha por linha do corpo da função `main` acima para
chegar na saída da função.

Na primeira linha temos a declaração das variáveis `x` e `y`.

```c
int x, y;
```

Nas segunda e terceira linhas o programa pede a entrada de dois valores inteiros
ao usuário e atribui esses valores às variáveis `x` e `y` respectivamente.

```c
scanf("%d", &x);
scanf("%d", &y);
```

Na quarta linha a função `func` é chamada recebendo como argumentos os endereços
de memória das variáveis `x` e `y`, respectivamente.

```c
func(&x, &y);
```

- A função `func` tem como parâmetros dois ponteiros para valores inteiros
(`func(int *px, int *py)`). Ou seja, esses parâmetros irão apontar para os
endereços de memória passados como argumentos.

- Na  primeira linha da função `func`, o parâmetro `px` recebe o valor de `py`.
Usando os argumentos passados, isso quer dizer `px` recebe o endereço de memória
de `y`. O valor de `py` é o endereço de memória de `y`.

    ```c
    px = py;
    // px = &y;
    ```

- Na segunda linha da função `func` o conteúdo do endereço de memória armazenado
em `py` é alterado para o valor do produto entre os conteúdos de memória
armazenados em `py` e `px`. Como `py` e `px` armazenam o mesmo endereço de
memória, será um produto entre dois valores iguais.

    ```c
    *py = (*py) * (*px);
    // py = &y;
    // px = &y;
    ```

- Na terceira linha da função `func` o conteúdo armazenado em `px` é
incrementado em duas unidades.

    ```c
    *px = *px + 2;
    // py = &y;
    ```

Na quinta linha os valores de `x` e `y` são exibidos na tela.

```c
printf("x = %d, y = %d\n", x, y);
```

### Teste de Mesa

Consideremos que:

- Os endereços de memória de `x` e `y` são 5000 e 5004, respectivamente.
- Os valores inseridos para `x` e `y` são são 10 e 20, respectivamente.

```
x      y      px      *px      py      *py
#      #      --      ---      --      ---
10     #      --      ---      --      ---
10     20     --      ---      --      ---
10     20     5000    10       5004    20
10     20     5004    20       5004    20
10     400    5004    400      5004    400
10     402    5004    402      5004    402
```
