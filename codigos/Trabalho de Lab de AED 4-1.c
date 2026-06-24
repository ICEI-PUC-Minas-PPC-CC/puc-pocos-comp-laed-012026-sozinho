#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>


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

    printf("\n\nPESQUISAR VEÍCULO\n\n");

    printf("\n\n------------------------------------------------------\n\n");

    char PlacaVeil[10];

    printf("DIGITE A PLACA DO VEICULO => ");
    scanf(" %[^\n]s", PlacaVeil);

    printf("\n\n------------------------------------------------------\n\n");

        for (int j = 0; j < 20 ; j++) {

            if (Veil[j].ativo == 1 && strcmp(Veil[j].Placa, PlacaVeil) == 0) {

                printf("\n\nVEICULO ENCONTRADO COM SUCESSO NA POSIÇÃO %d => \n\n", j + 1);

                printf("\n\n------------------------------------------------------\n\n");

                printf("MODELO DO VEICULO => %s\n\n", Veil[j].Modelo);

                printf("PLACA DO VEICULO => %s\n\n", Veil[j].Placa);

                printf("VAGA OCUPADA PELO VEÍCULOS => %d\n\n", Veil[j].Vaga);

                printf("QUANTIDADE DE HORAS DE PERMANÊNCIA DO VEICULO => %d\n\n", Veil[j].Horas);

                printf("VALOR A SE PAGAR => %.2f\n\n", Veil[j].VH);

                VeiculoEnc = 1;

                break;
            }
        }

    if (!VeiculoEnc) {

        printf("\n\n------------------------------------------------------\n\n");

        printf("\nVEICULO COM A PLACA %s NÃO FOI ENCONTRADO.\n", PlacaVeil);

        printf("\n\n------------------------------------------------------\n\n");

    }
    system("pause");
}


void EditarUmVeiculo(struct Veiculo Veil[]) {

    system("cls");

    int VeiculoEnc = 0;

    printf("EDITAR VEÍCULO\n\n");

    printf("\n\n------------------------------------------------------\n\n");

    char PlacaVeil[10];

    printf("DIGITE A PLACA DO VEICULO QUE VOCÊ DESEJA EDITAR => ");
    scanf(" %[^\n]s", PlacaVeil);

    printf("\n\n------------------------------------------------------\n\n");


    for (int j = 0; j < 20 ; j++) {

        if (Veil[j].ativo == 1 && strcmp(Veil[j].Placa, PlacaVeil) == 0) {

            printf("\n\nVEICULO ENCONTRADO COM SUCESSO. INSIRA OS NOVOS DADOS => \n\n");

            printf("MODELO DO VEÍCULOS => ");
            scanf(" %[^\n]s", Veil[j].Modelo);

            printf("\n\n------------------------------------------------------\n\n");

            printf("PLACA DO VEÍCULOS => ");
            scanf (" %[^\n]s", Veil[j].Placa);
            printf("\n\n------------------------------------------------------\n\n");

            printf("VAGA OCUPADA PELO VEÍCULOS => ");
            scanf("%d",&Veil[j].Vaga);

            printf("\n\n------------------------------------------------------\n\n");

            printf("QUANTIDADE DE HORAS DE PERMANÊCIA DO VEÍCULOS => ");
            scanf("%d", &Veil[j].Horas);

            printf("\n\n------------------------------------------------------\n\n");

            printf("OS DADOS FORAM ATUALIZADOS COM SUCESSO.\n");
            VeiculoEnc = 1;

    system("pause");
            break;
        }
    }

    if (!VeiculoEnc) {

        printf("\n\n------------------------------------------------------\n\n");

        printf("\nNENHUM VEICULO ATIVO FOI ENCONTRADO. \n", PlacaVeil);

        printf("\n\n------------------------------------------------------\n\n");

        system("pause");
    }
}

void EstatisticasDosVeiculos(struct Veiculo Veil[]) {

    int j;
    float FaturamentoTotal = 0;
    int VagasEmUso = 0;
    int VagasLivres = 0;
    int TotalDeHoras = 0;
    float MaiorValor = 0;
    float MenorValor = 999999.0;
    char PlacaMaior[10];
    char PlacaMenor[10];


    for (j = 0; j < 20; j++) {

        if (Veil[j].ativo == 1) {

            VagasEmUso++;

            FaturamentoTotal += Veil[j].VH;

            TotalDeHoras += Veil[j].Horas;

            if (Veil[j].VH > MaiorValor) {

                MaiorValor = Veil[j].VH;

                strcpy(PlacaMaior, Veil[j].Placa);
            }

            if (Veil[j].VH < MenorValor) {

                MenorValor = Veil[j].VH;

                strcpy(PlacaMenor, Veil[j].Placa);
            }

            else {
            VagasLivres++;
            }

        }
    }


            if (VagasEmUso > 0) {

        float MediaHoras = (float)TotalDeHoras / VagasEmUso;

        printf("6 --> RESUMO/ESTATÍSTICAS DOD VEICULOS DO ESTACIONAMENTO\n\n");

        printf("\n\n------------------------------------------------------\n\n");

        printf("TEMPO MÉDIO DE PERMANÊNCIA => %.1f HORAS\n\n", MediaHoras);

        printf("\n\n------------------------------------------------------\n\n");

        printf("VEÍCULO COM MAIOR VALOR A SE PAGAR =>  PLACA => %s / VALOR => %.2f\n\n",PlacaMaior, MaiorValor);

        printf("VEÍCULO COM MENOR VALOR A SE PAGAR =>  PLACA => => %s / VALOR => %.2f\n",PlacaMenor, MenorValor);

        printf("\n\n------------------------------------------------------\n\n");
    }
     else {
        printf("NENHUM VEICULO EMCONTRADO PARA FAZER O RESUMO.\n");

        printf("\n\n------------------------------------------------------\n");
    }



    printf("  OCUPAÇÃO DAS VAGAS\n");

    printf("------------------------------------------------------\n\n");

    printf("VAGAS OCUPADAS =>  %d / 20\n\n", VagasEmUso);

    printf("VAGAS LIVRES =>   %d / 20\n\n", VagasLivres);

    printf("FATURAMENTO ATUAL =>  %.2f\n\n", FaturamentoTotal);

    printf("\n\n------------------------------------------------------\n\n");

    system("pause");

}



int main() {
    struct Veiculo Veil[20];
    int Alternativa = 0;
    int veiculosregistrado = 0;
    int t = 1;
    int i = 0;
    int j;
    int DezPrimeirosVeiculos = 0;
    int vagaLivre = -1;
    int VeiculoEnc = 0;
    int QuantMaxVeic = 20;

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    setlocale(LC_ALL, "Portuguese");


    for (j =0; j<QuantMaxVeic ; j++) {
        Veil[j].ativo =0;
    }


        while(t != 7) {

            system("cls");

            printf("MENU PRINCIPAL\n\n");

            printf("\n\n------------------------------------------------------\n\n");

            printf("1 --> REGISTRAR UM VEÍCULO DO ESTACIONAMENTO\n\n");

            printf("2 --> VEÍCULOS JÁ REGISTRADOS\n\n");

            printf("3 --> EXCLUIR UM VEÍCULO REGISTRADO\n\n");

            printf("4 --> PESQUISAR VEÍCULO POR PLACA\n\n");

            printf("5 --> EDITAR DADOS DE UM VEÍCULO\n\n");

            printf("6 --> RESUMO/ESTATÍSTICAS DOD VEICULOS DO ESTACIONAMENTO\n\n");

            printf("7 --> SAIR DO PROGRAMA\n\n");

            printf("      OPÇÃO DESEJADA = ");
            scanf("%d", &t);




        switch(t) {


            case 1:

    if (DezPrimeirosVeiculos == 0){

        system("cls");

        printf("\n POR FAVOR, REGISTRE PELO MENOS 10 VEÍCULOS INICIALMENTE [%d | 10]\n\n", i);

        for (i = 1; i < 10; i++) {

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("MODELO DO VEÍCULOS =>");
                    scanf(" %[^\n]s", Veil[i].Modelo);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("PLACA DO VEÍCULOS => ");
                    scanf (" %[^\n]s", Veil[i].Placa);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("VAGA OCUPADA PELO VEÍCULOS =>");
                    scanf("%d",&Veil[i].Vaga);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("QUANTIDADE DE HORAS DE PERMANÊCIA DO VEÍCULOS =>");
                    scanf("%d", &Veil[i].Horas);

                    printf("\n\n------------------------------------------------------\n\n");

                    Veil[i].ativo = 1;
                    veiculosregistrado++;


                    printf("\nCONFIRMAÇÃO DE DADOS\n");

                    printf("\n\n--------------------------------------------------------------------\n\n");

                    printf("MODELO => %s\n\n", Veil[i].Modelo);

                    printf("PLACA  => %s\n\n", Veil[i].Placa);

                    printf("VAGA => %d\n\n", Veil[i].Vaga);

                    printf("HORAS => %d\n\n", Veil[i].Horas);

                    Veil[i].VH = 12.00 * Veil[i].Horas;
                    printf("VALOR A SE PAGAR => %.2f\n\n", Veil[i].VH);

                    printf("POSIÇÃO [%d/10].\n\n", i);

                    printf("\n\n------------------------------------------------------\n\n");


                    system("pause");

        }

        DezPrimeirosVeiculos = 1;

    }

    else {
                for (j = 0; j < QuantMaxVeic; j++) {

                    if (Veil[j].ativo == 0) {

                        vagaLivre = j;

                        break;
                    }

    system("pause");
                }

                if (vagaLivre != -1) {

                    system("cls");

                    printf("\nREALIZAR O REGISTRO DE UM VEÍCULO\n");

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("MODELO DO VEÍCULO => ");
                    scanf(" %[^\n]s", Veil[vagaLivre].Modelo);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("PLACA DO VEÍCULO => ");
                    scanf(" %[^\n]s", Veil[vagaLivre].Placa);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("VAGA OCUPADA PELO VEÍCULO => ");
                    scanf("%d", &Veil[vagaLivre].Vaga);

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("QUANTIDADE DE HORAS => ");
                    scanf("%d", &Veil[vagaLivre].Horas);

                    Veil[vagaLivre].VH = 12.00 * Veil[vagaLivre].Horas;

                    Veil[vagaLivre].ativo = 1;

                    veiculosregistrado++;

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("CONFIRMAÇÃO DE DADOS\n");

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("MODELO => %s\n\n", Veil[vagaLivre].Modelo);

                    printf("PLACA => %s\n\n", Veil[vagaLivre].Placa);

                    printf("VAGA => %d\n\n", Veil[vagaLivre].Vaga);

                    printf("HORAS => %d\n\n", Veil[vagaLivre].Horas);

                    printf("VALOR A SE PAGAR => %.2f\n\n", Veil[vagaLivre].VH);

                    printf("POSIÇÃO [%d/10].\n\n", i);

                     printf("\n\n------------------------------------------------------\n\n");

                    system("pause");
                    }

                 else {

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("\nO ESTACIONAMENTO ESTÁ LOTADO. O LIMITE DE 20 VEÍCULOS FOI ATINGIDO.\n");

                    printf("\n\n------------------------------------------------------\n\n");

                    system("pause");
                }
    }
                break;

            case 2:

                system("cls");

                for (j = 0; j < QuantMaxVeic; j++) {

                    if (Veil[j].ativo == 1) {


                        printf("\n VEÍCULOS JÁ REGISTRADOS\n");

                        printf("\n\n--------------------------------------------------------------------\n\n");

                        printf("POSIÇÃO NO SISTEMA => %d\n\n", j + 1);

                        printf("QUANTIDADE DE VEÍCULOS JÁ REGISTRADOS =>%d\n\n", veiculosregistrado);

                        printf("MODELO DO VEÍCULO => %s\n\n", Veil[j].Modelo);

                        printf("PLACA DO VEÍCULO => %s\n\n", Veil[j].Placa);

                        printf("VAGA OCUPADA PELO VEÍCULO => %d\n\n", Veil[j].Vaga);

                        printf("QUANTIDADE DE HORAS DE PERMANÊCIA DO VEÍCULO => %d\n\n", Veil[j].Horas);

                        Veil[j].VH = 12.00 * Veil[j].Horas;
                        printf("VALOR A SE PAGAR => %.2f\n\n", Veil[j].VH);

                        system("pause");
                    }

                else
                    {

                    printf("\n\n--------------------------------------------------------------------\n\n");

                    printf("  NENHUM VEICULO REGISTRADO AINDA, POR FAVOR, REGISTRAR NO MINIMO 10 VEICULOS.\n");

                    printf("\n\n--------------------------------------------------------------------\n\n");

                    system("pause");

                }
            }


                break;

            case 3:

                system("cls");

                printf("\nEXCLUIR UM VEÍCULO REGISTRADO\n");

                printf("\n\n------------------------------------------------------\n\n");

                printf(" EXCLUIR UM VEÍCULO POR VAGA \n\n");

                printf("------------------------------------------------------\n\n");

                int vagadoveic;
                printf("DIGITE O NÚMERO DA VAGA QUE VÔCE DESEJA LIBERAR => ");
                scanf("%d", &vagadoveic);


                for (j = 0; j < QuantMaxVeic; j++) {

                    if (Veil[j].ativo == 1 && Veil[j].Vaga == vagadoveic) {

                        Veil[j].ativo = 0;

                        veiculosregistrado--;

                        VeiculoEnc = 1;

                        printf("\nO VEÍCULO DA VAGA %d FOI REMOVIDO COM SUCESSO.\n", vagadoveic);

                    }
                }

                if (!VeiculoEnc) {

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("\nNÃO HÁ NENHUM VEÍCULO REGISTRADO NA VAGA. %d.\n", vagadoveic);

                    printf("\n\n------------------------------------------------------\n\n");

                    system("pause");
                }


                break;
            case 4:

                PesquisarUmVeiculo(Veil);

            break;

            case 5:

                EditarUmVeiculo(Veil);

            break;

                break;

            case 6:

                EstatisticasDosVeiculos(Veil);

                break;

            case 7:

                printf("\n\n------------------------------------------------------\n\n");

                printf("SAINDO DO PROGRAMA.");

                printf("\n\n------------------------------------------------------\n\n");

                break;

        }
    }
}
