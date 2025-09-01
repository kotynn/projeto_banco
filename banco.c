#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int valor, total;
    int r100, r50, r20, r10, r5, r2, r1;
    char opc;
    int saldo = 1000;
    int limite = 2300;

    printf("===================\n");
    printf("      BANCO😄 \n");
    printf("===================\n");

    while (1) {
        printf("===========================\n");
        printf("Saldo disponível: %d\n", saldo);
        printf("Limite disponível: %d\n", limite);
        printf("===========================\n");

        printf("Que valor você quer sacar? ");
        scanf("%d", &valor);
        total = valor;
        printf("=========================\n");
        r100 = r50 = r20 = r10 = r5 = r2 = r1 = 0;

        if (valor <= 0){
            printf("Digite um valor válido...\n");
            continue;
        }

        if (valor <= saldo){
            saldo -= valor;
        }
        else if( valor <= (saldo + limite)){
            printf("Saldo insuficiente!!!\n");
            printf("Deseja usar o limite especial? [S/N] ");
            scanf(" %c", &opc);
            opc = toupper(opc);

            if (opc == 'S'){
                int falta = valor - saldo;
                printf("Será utilizado %d do seu limite especial.\n", falta);
                limite -= falta;
                saldo = 0;
            }
            else{
                printf("Saque cancelado. Voltando ao menu...\n");
                continue;
            }
        }
        else{
            printf("ERRO: Nem o saldo (%d) e nem o limite (%d) dão conta desse saque.\n", saldo, limite);
            continue;
        }

        while (total >= 100) {
            total -= 100;
            r100++;
        }
        while (total >= 50) {
            total -= 50;
            r50++;
        }
        while (total >= 20) {
            total -= 20;
            r20++;
        }
        while (total >= 10) {
            total -= 10;
            r10++;
        }
        while (total >= 5) {
            total -= 5;
            r5++;
        }
        while (total >= 2) {
            total -= 2;
            r2++;
        }
        while (total >= 1) {
            total -= 1;
            r1++;
        }

        if (r100 > 0) {
            printf("Total de %d cédulas de R$100\n", r100);
        }
        if (r50 > 0) {
            printf("Total de %d cédulas de R$50\n", r50);
        }
        if (r20 > 0) {
            printf("Total de %d cédulas de R$20\n", r20);
        }
        if (r10 > 0) {
            printf("Total de %d cédulas de R$10\n", r10);
        }
        if (r5 > 0) {
            printf("Total de %d cédulas de R$5\n", r5);
        }
        if (r2 > 0) {
            printf("Total de %d cédulas de R$2\n", r2);
        }
        if (r1 > 0) {
            printf("Total de %d cédulas de R$1\n", r1);
        }

        printf("===================================\n");
        printf("Saldo atual: R$ %d\n", saldo);
        printf("Limite restante: R$ %d\n", limite);
        printf("===================================\n");

        printf("Deseja continuar? [S/N] ");
        scanf(" %c", &opc);  
        opc = toupper(opc);

        if (opc == 'N') {
            printf("Volte sempre ao BANCO 😄!\n");
            break;
        }
    }

    return 0;
}
