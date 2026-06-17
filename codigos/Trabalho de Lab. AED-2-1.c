#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


struct Veiculo {
    char Modelo[20];
    char Placa[10];
    float VH;
    int Vaga;
    int Horas;
    int ativo;
};


void PesquisarUmVeiculo(struct Veiculo Veil[]) {

    system("cls");

    int VeiculoEnc = 0;
    int QuantMaxVeic = 20;

    printf("\n\nPESQUISAR VEÍCULO\n\n");

    printf("\n\n------------------------------------------------------\n\n");

    char PlacaVeil[10];

    printf("DIGITE A PLACA DO VEICULO =\n\n");
    scanf(" %[^\n]s", PlacaVeil);

    for (int j = 0; j < QuantMaxVeic ; j++) {

        if (Veil[j].ativo == 1 && strcmp(Veil[j].Placa, PlacaVeil) == 0) {

            printf("VEICULO ENCONTRADO NA POSIÇÃO %d =\n\n", j + 1);

            printf("MODELO DO VEICULO = %s\n\n", Veil[j].Modelo);

            printf("PLACA DO VEICULO = %s\n\n", Veil[j].Placa);

            printf("VAGA OCUPADA PELO VEÍCULOS = %d\n\n", Veil[j].Vaga);

            printf("QUANTIDADE DE HORAS DE PERMANÊNCIA DO VEICULO = %d\n\n", Veil[j].Horas);
            printf("VALOR A SE PAGAR = %.2f\n\n", Veil[j].VH);

            VeiculoEnc = 1;

            break;
        }
    }
    if (!VeiculoEnc) {
        printf("\nVEICULO COM A PLACA %s NÃO FOI ENCONTRADO.\n", PlacaVeil);
    }
}


void EditarUmVeiculo(struct Veiculo Veil[],float Valor) {

    system("cls");

    int VeiculoEnc = 0;
    int QuantMaxVeic = 20;

    printf("EDITAR VEÍCULO\n\n");

    printf("\n\n------------------------------------------------------\n\n");

    char PlacaVeil[10];

    printf("DIGITE A PLACA DO VEICULO QUE VOCÊ DESEJA EDITAR =\n\n");
    scanf("%d", PlacaVeil);

    for (int j = 0; j < QuantMaxVeic ; j++) {

        if (Veil[j].ativo == 1 && Veil[j].Placa == PlacaVeil) {

            printf("\nVEICULO ENCONTRADO! INSIRA OS NOVOS DADOS =\n\n");

            printf("MODELO DO VEÍCULOS =\n\n");
            scanf(" %[^\n]s", Veil[j].Modelo);

            printf("\n\n------------------------------------------------------\n\n");

            printf("PLACA DO VEÍCULOS = \n\n");
            scanf (" %[^\n]s", Veil[j].Placa);

            printf("\n\n------------------------------------------------------\n\n");

            printf("VAGA OCUPADA PELO VEÍCULOS = \n\n");
            scanf("%d",&Veil[j].Vaga);

            printf("\n\n------------------------------------------------------\n\n");

            printf("QUANTIDADE DE HORAS DE PERMANÊCIA DO VEÍCULOS = \n\n");
            scanf("%d", &Veil[j].Horas);

            printf("\n\n------------------------------------------------------\n\n");

            printf("VALOR A SE PAGAR = %.2f\n\n", Veil[j].VH);



            printf("OS DADOS FORAM ATUALIZADOS !\n");
            VeiculoEnc = 1;

            break;
        }
    }
    if (!VeiculoEnc) {
        printf("\nNENHUM VEICULO ATIVO FOI ENCONTRADO \n", PlacaVeil);
    }
}




int main() {
    struct Veiculo Veil[20];
    float Valor = 12.00;
    int Alternativa = 0;
    int veiculosregistrado = 0;
    int t = 1;
    int i = 0;
    int j;
    int DezPrimeirosVeiculos = 0;
    int vagaLivre = -1;
    int VeiculoEnc = 0;
    int QuantMaxVeic = 20;


    setlocale(LC_ALL, "Portuguese");


    for (j =0; j<QuantMaxVeic ; j++) {
        Veil[j].ativo =0;
    }


        while(t != 4) {

            printf("MENU PRINCIPAL\n\n");

            printf("\n\n------------------------------------------------------\n\n");

            printf("1 --> REGISTRAR UM VEÍCULO DO ESTACIONAMENTO\n");

            printf("2 --> VEÍCULOS JÁ REGISTRADOS\n");

            printf("3 --> EXCLUIR UM VEÍCULO REGISTRADO\n");

            printf("4 --> PESQUISAR VEÍCULO POR PLACA\n");

            printf("5 --> EDITAR DADOS DE UM VEÍCULO\n");

            printf("6 --> SAIR DO PROGRAMA\n");

            printf("OPÇÃO DESEJADA = ");
            scanf("%d", &t);




        switch(t) {


            case 1:

    if (DezPrimeirosVeiculos == 0){

        printf("\n POR FAVOR, REGISTRE PELO MENOS 10 VEÍCULOS INICIALMENTE [%d/10]\n\n", i);

        for (i = 0; i < 10; i++) {
            printf(" [%d/10]\n\n", i);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("MODELO DO VEÍCULOS =");
                    scanf(" %[^\n]s", Veil[i].Modelo);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("PLACA DO VEÍCULOS = ");
                    scanf (" %[^\n]s", Veil[i].Placa);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("VAGA OCUPADA PELO VEÍCULOS =");
                    scanf("%d",&Veil[i].Vaga);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("QUANTIDADE DE HORAS DE PERMANÊCIA DO VEÍCULOS =");
                    scanf("%d", &Veil[i].Horas);

                    printf("\n\n------------------------------------------------------\n\n");



                    printf("\nCONFIRMAÇÃO DE DADOS\n");

                    printf("\n\n--------------------------------------------------------------------\n\n");

                    printf("MODELO DO VEÍCULOS =%s\n\n", Veil[i].Modelo);

                    printf("PLACA DO VEÍCULOS =%s\n\n", Veil[i].Placa);

                    printf("VAGA OCUPADA VEÍCULOS =%d\n\n", Veil[i].Vaga);

                    printf("QUANTIDADE DE HORAS DE PERMANÊCIA DO VEÍCULOS = %d\n\n", Veil[i].Horas);

                    Veil[i].VH = Valor * Veil[i].Horas;
                    printf("VALOR A SE PAGAR = %.2f\n\n", Veil[i].VH);


                    Veil[i].ativo = 1;
                    veiculosregistrado++;

        }

        DezPrimeirosVeiculos = 1;
    }

    else {
                for (j = 0; j < QuantMaxVeic; j++) {

                    if (Veil[j].ativo == 0) {

                        vagaLivre = j;

                        break;
                    }
                }

                if (vagaLivre != -1) {

                    system("cls");

                    printf("\nREALIZAR O REGISTRO DE UM VEÍCULO\n");

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("MODELO DO VEÍCULO = ");
                    scanf(" %[^\n]s", Veil[vagaLivre].Modelo);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("PLACA DO VEÍCULO = ");
                    scanf(" %[^\n]s", Veil[vagaLivre].Placa);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("VAGA OCUPADA PELO VEÍCULO = ");
                    scanf("%d", &Veil[vagaLivre].Vaga);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("QUANTIDADE DE HORAS = ");
                    scanf("%d", &Veil[vagaLivre].Horas);

                    Veil[vagaLivre].VH = Valor * Veil[vagaLivre].Horas;

                    Veil[vagaLivre].ativo = 1;

                    veiculosregistrado++;

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("CONFIRMAÇÃO DE DADOS\n");

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("MODELO = %s\n\n", Veil[vagaLivre].Modelo);

                    printf("PLACA = %s\n\n", Veil[vagaLivre].Placa);

                    printf("VAGA = %d\n\n", Veil[vagaLivre].Vaga);

                    printf("HORAS = %d\n\n", Veil[vagaLivre].Horas);

                    printf("VALOR A SE PAGAR = %.2f\n\n", Veil[vagaLivre].VH);
                    }

                 else {
                    printf("\nO ESTACIONAMENTO ESTÁ LOTADO! O LIMITE DE 20 VEÍCULOS FOI ATINGIDO.\n");
                }
    }
                break;

            case 2:
                for (j = 0; j < QuantMaxVeic; j++) {

                    if (Veil[j].ativo == 1) {

                        system("cls");

                        printf("\n VEÍCULOS JÁ REGISTRADOS\n");

                        printf("\n\n--------------------------------------------------------------------\n\n");

                        printf("POSIÇÃO NO SISTEMA: %d\n\n", j + 1);

                        printf("QUANTIDADE DE VEÍCULOS JÁ REGISTRADOS =%d\n\n", veiculosregistrado);

                        printf("MODELO DO VEÍCULO = %s\n\n", Veil[j].Modelo);

                        printf("PLACA DO VEÍCULO =%s\n\n", Veil[j].Placa);

                        printf("VAGA OCUPADA PELO VEÍCULO =%d\n\n", Veil[j].Vaga);

                        printf("QUANTIDADE DE HORAS DE PERMANÊCIA DO VEÍCULO = %d\n\n", Veil[j].Horas);

                        Veil[j].VH = Valor * Veil[j].Horas;
                        printf("VALOR A SE PAGAR =%.2f\n\n", Veil[j].VH);
                    }
                }


                break;

            case 3:
                system("cls");

                printf("\nEXCLUIR UM VEÍCULO REGISTRADO\n");

                printf("\n\n------------------------------------------------------\n\n");

                printf(" EXCLUIR UM VEÍCULO POR VAGA \n\n");

                int vagadoveic;
                printf("DIGITE O NÚMERO DA VAGA QUE VÔCE DESEJA LIBERAR =");
                scanf("%d", &vagadoveic);


                for (j = 0; j < QuantMaxVeic; j++) {

                    if (Veil[j].ativo == 1 && Veil[j].Vaga == vagadoveic) {

                        Veil[j].ativo = 0;

                        veiculosregistrado--;

                        VeiculoEnc = 1;

                        printf("\nO VEÍCULO DA VAGA %d FOI REMOVIDO!\n", vagadoveic);
                break;
                    }
                }

                if (!VeiculoEnc) {
                    printf("\nNÃO HÁ NENHUM VEÍCULO REGISTRADO NA VAGA %d.\n", vagadoveic);
                }

            case 4:

                PesquisarUmVeiculo(Veil);

            break;

            case 5:

                EditarUmVeiculo(Veil, Valor);

            break;

                break;
            case 6:

                printf("SAINDO DO PROGRAMA.");

                break;

        }
    }
}

