#include <stdio.h>

int soma_e_sub_com_uma_passagem_por_referencia(int x, int y, int *sub) {
    int z = x + y;

    puts("===> DENTRO DA FUNCAO SOMA COM UMA PASSAGEM POR REFERENCIA");
    printf("&x = %p, x = %d\n", &x, x);
    printf("&y = %p, y = %d\n", &y, y);
    printf("&z = %p, z = %d\n", &z, z);
    printf("sub = %p, *sub = %d\n\n", sub, *sub);

    *sub = x - y;

    printf("sub = %p, *sub = %d\n\n", &sub, *sub);

    return z;
}

void soma_e_sub_com_passagens_por_referencia(int x, int y, int *soma, int *sub) {
    puts("===> DENTRO DA FUNCAO SOMA COM PASSAGENS POR REFERENCIA");
    printf("&x = %p, x = %d\n", &x, x);
    printf("&y = %p, y = %d\n", &y, y);
    printf("soma = %p, *soma = %d\n", soma, *soma);
    printf("sub = %p, *sub = %d\n\n", sub, *sub);

    *soma = x + y;
    *sub = x - y;

    printf("soma = %p, *soma = %d\n", soma, *soma);
    printf("sub = %p, *sub = %d\n\n", sub, *sub);
}

int main() {
    int a = 10;
    int b = 20;
    int c;
    int d;

    // puts("### ANTES DE CHAMAR A FUNCAO SOMA COM UMA PASSAGEM POR REFERENCIA");
    // printf("&a = %p, a = %d\n", &a, a);
    // printf("&b = %p, b = %d\n", &b, b);
    // printf("&c = %p, c = %d\n", &c, c);
    // printf("&d = %p, d = %d\n\n", &d, d);

    // c = soma_e_sub_com_uma_passagem_por_referencia(a, b, &d);

    // puts("### DEPOIS DE CHAMAR A FUNCAO SOMA COM UMA PASSAGEM POR REFERENCIA");
    // printf("&a = %p, a = %d\n", &a, a);
    // printf("&b = %p, b = %d\n", &b, b);
    // printf("&c = %p, c = %d\n", &c, c);
    // printf("&d = %p, d = %d\n\n", &d, d);

    // -------------------------------------------------------------------------

    puts("### ANTES DE CHAMAR A FUNCAO SOMA COM PASSAGENS POR REFERENCIA");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);
    printf("&d = %p, d = %d\n\n", &d, d);

    soma_e_sub_com_passagens_por_referencia(a, b, &c, &d);

    puts("### DEPOIS DE CHAMAR A FUNCAO SOMA COM PASSAGENS POR REFERENCIA");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);
    printf("&d = %p, d = %d\n\n", &d, d);

    return 0;
}
