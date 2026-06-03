#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Veiculo {
    char Modelo[20];
    char Placa[10];
    float VH;
    int Vaga;
    int Horas;
    int ativo;
};


int main() {
    struct Veiculo Veil[20];
    float Valor = 12.00;
    int veiculosregistrado = 0;
    int t = 1;
    int i = 0;
    int VeiculoEnc = 0;
    int QuantMaxVeic = 20;
    int vagalivre = -1;

    for (int j=0; j<QuantMaxVeic ; j++) {

        Veil[j].ativo =0;
    }

     printf(" POR FAVOR, REGISTRE PELO MENOS 10 VEICULOS INICIALMENTE [%d/10]\n\n", i);

    for (i = 0; i < 10; i++) {
        printf(" [%d/10]\n\n", i);

            printf("MODELO DO VEICULO =");
            scanf("%s", Veil[i].Modelo);

            printf("\n\n------------------------------------------------------\n\n");

            printf("PLACA DO VEICULO = ");
            scanf ("%s", Veil[i].Placa);

            printf("\n\n------------------------------------------------------\n\n");

            printf("VAGA OCUPADA PELO VEICULO =");
            scanf("%d",&Veil[i].Vaga);

            printf("\n\n------------------------------------------------------\n\n");

            printf("QUANTIDADE DE HORAS DE PERMANECIA DO VEICULO =");
            scanf("%d", &Veil[i].Horas);

            printf("\n\n------------------------------------------------------\n\n");

            printf("CONFIRMACAO DE DADOS\n");

            printf("\n\n--------------------------------------------------------------------\n\n");

            printf("MODELO DO VEICULO =%s\n\n", Veil[i].Modelo);

            printf("PLACA DO VEICULO =%s\n\n", Veil[i].Placa);

            printf("VAGA OCUPADA PELO VEICULO =%d\n\n", Veil[i].Vaga);

            printf("QUANTIDADE DE HORAS DE PERMANECIA DO VEICULO = %d\n\n", Veil[i].Horas);

            Veil[i].VH = Valor * Veil[i].Horas;
            printf("VALOR A SE PAGAR =%.2f\n\n", Veil[i].VH);

            Veil[i].ativo = 1;

            veiculosregistrado++;


    }

    while(t != 4) {

        printf("MENU PRINCIPAL\n\n");

        printf("\n\n------------------------------------------------------\n\n");

        printf("1 --> REGISTRAR UM VEICULO DO ESTACIONAMENTO\n");

        printf("2 --> VEICULOS JA REGISTRADOS\n");

        printf("3 --> EXCLUIR UM VEICULO REGISTRADO\n");

        printf("4 --> SAIR DO PROGRAMA\n");

        printf("OPCAO DESEJADA = ");
        scanf("%d", &t);



        switch(t) {


            case 1:

                for(int j= 0; j <= QuantMaxVeic; j++) {

                    if(Veil[j].ativo == 0) {

                        vagalivre= j;

                        break;
                    }
                }

                if (vagalivre != -1) {
                    printf("\nREALIZAR O REGISTRO DE UM VEICULO\n");

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("MODELO DO VEICULO = ");
                    scanf("%s", Veil[vagalivre].Modelo);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("PLACA DO VEICULO = ");
                    scanf("%s", Veil[vagalivre].Placa);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("VAGA OCUPADA PELO VEICULO = ");
                    scanf("%d", &Veil[vagalivre].Vaga);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("QUANTIDADE DE HORAS = ");
                    scanf("%d", &Veil[vagalivre].Horas);

                    Veil[vagalivre].VH = Valor * Veil[vagalivre].Horas;

                    Veil[vagalivre].ativo = 1;

                    veiculosregistrado++;

                    printf("CONFIRMACAO DE DADOS\n");

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("MODELO: %s", Veil[vagalivre].Modelo);

                    printf("PLACA: %s", Veil[vagalivre].Placa);

                    printf("VAGA: %d", Veil[vagalivre].Vaga);

                    printf("HORAS: %d", Veil[vagalivre].Horas);

                    printf("VALOR A SE PAGAR = %.2f", Veil[vagalivre].VH);
                    }

                 else {
                    printf("\nESTACIONAMENTO LOTADO! LIMITE DE 20 VEICULOS ATINGIDO.\n");
                }

                break;

            case 2:
                for (int j = 0; j < QuantMaxVeic; j++) {
                    if (Veil[j].ativo == 1) {

                        printf(" VEICULOS JA REGISTRADOS\n");

                        printf("\n\n--------------------------------------------------------------------\n\n");

                        printf("POSICAO NO SISTEMA: %d\n", j + 1);

                        printf("QUANTIDADE DE VEICULOS JA REGISTRADOS =%d", veiculosregistrado);

                        printf("MODELO DO VEICULO = %s\n\n", Veil[j].Modelo);

                        printf("PLACA DO VEICULO =%s\n\n", Veil[j].Placa);

                        printf("VAGA OCUPADA PELO VEICULO =%d\n\n", Veil[j].Vaga);

                        printf("QUANTIDADE DE HORAS DE PERMANECIA DO VEICULO = %d\n\n", Veil[j].Horas);

                        Veil[j].VH = Valor * Veil[j].Horas;
                        printf("VALOR A SE PAGAR =%.2f\n\n", Veil[j].VH);
                    }
                }


                break;

            case 3:

                printf("EXCLUIR UM VEICULO REGISTRADO\n");

                printf("\n\n------------------------------------------------------\n\n");

                                printf("\n--- EXCLUIR UM VEICULO POR VAGA ---\n");
                int vagadoveic;
                printf("DIGITE O NUMERO DA VAGA QUE VS DESEJA LIBERAR =");
                scanf("%d", &vagadoveic);


                for (int j = 0; j < QuantMaxVeic; j++) {

                    if (Veil[j].ativo == 1 && Veil[j].Vaga == vagadoveic) {

                        Veil[j].ativo = 0;

                        veiculosregistrado--;

                        VeiculoEnc = 1;

                        printf("\nO VEICULO DA VAGA %d FOI REMOVIDO!\n", vagadoveic);
                break;
                    }
                }

                if (!VeiculoEnc) {
                    printf("\nNAO HA NENHUM VEICULO REGISTRADO NA VAGA %d.\n", vagadoveic);
                }

                break;
            case 4:

                printf("SAINDO DO PROGRAMA.");

                break;

        }
    }
}

