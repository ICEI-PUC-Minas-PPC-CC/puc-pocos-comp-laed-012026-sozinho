#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>


struct Veiculo {
    char Modelo[20];
    char Placa[10];
    float VH;               //STRUCT PRINCIPAL
    int Vaga;
    int Horas;
    int ativo;
};


void PesquisarUmVeiculo(struct Veiculo Veil[]) {

    system("cls");

    int veiculosregistrado = 0;
    int VeiculoEnc = 0;
    int j;



    printf("\n\n------------------------------------------------------\n\n");

    printf("   PESQUISAR VEÍCULO\n");

    printf("\n------------------------------------------------------\n\n");

    char PlacaVeil[10];

    printf("DIGITE A PLACA DO VEICULO => ");
    scanf(" %[^\n]s", PlacaVeil);

    printf("\n\n------------------------------------------------------\n\n");

        for (int j = 0; j < 30 ; j++) {


            if (Veil[j].ativo == 1 && strcmp(Veil[j].Placa, PlacaVeil) == 0) {    //APENAS ATIVOS E COMPARAR O QUE FOI DIGITADO PELO USUARIO COM AS POSSIVEIS PLACAS REGISTRADAS


                printf("   VEICULO ENCONTRADO COM SUCESSO NA POSIÇÃO %d => \n", j + 1);

                printf("\n------------------------------------------------------------\n\n");

                printf("MODELO DO VEICULO => %s\n\n", Veil[j].Modelo);

                printf("PLACA DO VEICULO => %s\n\n", Veil[j].Placa);

                printf("VAGA OCUPADA PELO VEÍCULOS => %d\n\n", Veil[j].Vaga);

                printf("QUANTIDADE DE HORAS DE PERMANÊNCIA DO VEICULO => %d\n\n", Veil[j].Horas);

                printf("VALOR A SE PAGAR => %.2f\n\n", Veil[j].VH);

                system("pause");

                VeiculoEnc = 1;     //INCDICAR QUE O VEICULO FOI ENCONTRADO

                break;
            }
        }

    if (!VeiculoEnc) {


        printf("  VEICULO COM A PLACA %s NÃO FOI ENCONTRADO.\n", PlacaVeil);

        printf("\n------------------------------------------------------\n\n");

        system("pause");
    }
}


void EditarUmVeiculo(struct Veiculo Veil[]) {

     system("cls");

    int veiculosregistrado = 0;
    int VeiculoEnc = 0;
    int j;


    printf("\n\n------------------------------------------------------\n\n");

    printf("   EDITAR VEÍCULO\n");

    printf("\n------------------------------------------------------\n\n");

    char PlacaVeil[10];

    printf("DIGITE A PLACA DO VEICULO QUE VOCÊ DESEJA EDITAR => ");
    scanf(" %[^\n]s", PlacaVeil);

    printf("\n\n------------------------------------------------------\n\n");


    for (int j = 0; j < 30 ; j++) {         //LOOP DAS VAGAS


        if (Veil[j].ativo == 1 && strcmp(Veil[j].Placa, PlacaVeil) == 0) {      //VAGAS REGISTRADAS E EM USO E COMPARA PLACA DITA PELO USUARIO A AS REGISTRADAS


            printf("  VEICULO ENCONTRADO COM SUCESSO. INSIRA OS NOVOS DADOS => \n");

            printf("\n------------------------------------------------------\n\n");

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

            Veil[j].VH = 12.00 * Veil[j].Horas;

            printf("\n\n------------------------------------------------------\n\n");

            printf("OS DADOS FORAM ATUALIZADOS COM SUCESSO.\n");

            printf("\n\n------------------------------------------------------\n\n");

            system("pause");

            VeiculoEnc = 1;

            break;
        }
    }

    if (!VeiculoEnc) {


        printf("\nNENHUM VEICULO FOI COM PLACA %s ENCONTRADO.\n", PlacaVeil);

        printf("\n------------------------------------------------------\n\n");

        system("pause");
    }

}


void EstatisticasDosVeiculos(struct Veiculo Veil[]) {

    system("cls");

    int veiculosregistrado = 0;
    int j;
    float FaturamentoTotal = 0;
    int VagasEmUso = 0;
    int VagasLivres = 0;
    float TotalDeHoras = 0;
    float MaiorValor = -1.0;
    float MenorValor = 999999.0;           //É NECESSARIO QUE O MENOR VALOR TENHA VALOR ALTO INICIALMENTE PARA QUE
    char PlacaMaior[10];
    char PlacaMenor[10];





    for (j = 0; j < 30; j++) {

        if (Veil[j].ativo == 1) {

            VagasEmUso++;       //SE TA ATIVO É PORQUE TA OCUPANDO VAGAS

            FaturamentoTotal += Veil[j].VH;     //VAI SOMANDO OS VALORES A SE PAGAR PELOS CLIENTES DO ESTACIONAMENTO

            TotalDeHoras += Veil[j].Horas;      //SOMA AS HORAS DE PERMANÊNCIA DE TODOS OS CLIENTES

            if (Veil[j].VH > MaiorValor) {

                MaiorValor = Veil[j].VH;                //MaiorValor COMEÇA 0 E DEPOIS VAI RODANDO ATÉ ACHAR O MAIOR VALOR

                strcpy(PlacaMaior, Veil[j].Placa);      //PLACA DO RESPECTIVO VEICULO É REGISTRADA
            }

            if (Veil[j].VH < MenorValor) {

                MenorValor = Veil[j].VH;            //MESMO FUNCIONAMENTO DOS MAIORVALOR E PLACA SÓ QUE AL CONTRARIO

                strcpy(PlacaMenor, Veil[j].Placa);
            }
        }
    }

    VagasLivres = 30 - VagasEmUso;

            if (VagasEmUso > 0) {

                float MediaHoras = TotalDeHoras / VagasEmUso;     //MÉDIA NORMAL

                printf("\n\n------------------------------------------------------\n\n");

                printf("  RESUMO|ESTATÍSTICAS DOS VEICULOS DO ESTACIONAMENTO\n");

                printf("\n\n------------------------------------------------------\n\n");

                printf("TEMPO MÉDIO DE PERMANÊNCIA => %.1f HORAS\n\n", MediaHoras);

                printf("VEÍCULO COM MAIOR VALOR A SE PAGAR =>  PLACA => %s | VALOR => %.2f\n\n",PlacaMaior, MaiorValor);

                printf("VEÍCULO COM MENOR VALOR A SE PAGAR =>  PLACA => => %s | VALOR => %.2fz\n\n",PlacaMenor, MenorValor);


                printf("VAGAS OCUPADAS =>  %d | 30\n\n", VagasEmUso);

                printf("VAGAS LIVRES =>   %d | 30\n\n", VagasLivres);

                printf("FATURAMENTO ATUAL =>  %.2f\n", FaturamentoTotal);

                printf("\n------------------------------------------------------\n\n");

                system("pause");

            }

     else {
         printf("\n\n------------------------------------------------------\n\n");

        printf("NENHUM VEICULO FOI REGISTRADO AINDA.POR FAVOR, REGISTRE PELO MENOS 1 VEICULOS.\n");

        printf("\n------------------------------------------------------\n\n");

        system("pause");
    }

}


int main() {
    struct Veiculo Veil[30];
    int Alternativa = 0;
    int veiculosregistrado = 0;
    int t = 1;
    int j;
    int VagaLivre = -1;
    int VeiculoEnc = 0;
    int k;

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);                //PERMITIR QUE EU POSSA USAR SINAIS COMO ´, ^, ~, ETC...
    setlocale(LC_ALL, "Portuguese");


    for (j =0; j< 30 ; j++) {
        Veil[j].ativo =0;       //CONDIÇÃO INICIAL DO ATIVO
    }


    while(t!= 7){           //ENQUANTO A OPÇÃO DE SAIR DO PROGRAMA NÃO FOR ACIONADA SEMPRE VOLTARÁ PARA O MENU PRINCIPAL

        system("cls");

        printf("\n\n------------------------------------------------------\n\n");

        printf("   MENU PRINCIPAL\n");

        printf("\n------------------------------------------------------\n\n");

        printf("  1 --> REGISTRAR UM VEÍCULO DO ESTACIONAMENTO\n\n");

        printf("  2 --> VEÍCULOS JÁ REGISTRADOS\n\n");

        printf("  3 --> EXCLUIR UM VEÍCULO REGISTRADO\n\n");

        printf("  4 --> PESQUISAR VEÍCULO POR PLACA\n\n");

        printf("  5 --> EDITAR DADOS DE UM VEÍCULO\n\n");

        printf("  6 --> RESUMO|ESTATÍSTICAS DOD VEICULOS DO ESTACIONAMENTO\n\n");

        printf("  7 --> SAIR DO PROGRAMA\n\n");

        printf("      OPÇÃO DESEJADA = ");
        scanf("%d", &t);                    //SELECIONAR O CASE


        int VagaLivre = -1;
        int VeiculoEnc = 0;

        switch(t) {


            case 1: {
{
                int DezpPrimeirasvVagas;

                if (veiculosregistrado < 10) {                      //OS 10 PRIMEIROS VEICULOS TEM QUE SER REGISTRADOS (COMO FOI PEDIDO NA ETAPA 1 DO TRABALHO)
                    DezpPrimeirasvVagas = 10 - veiculosregistrado;
                }
                else {
                    DezpPrimeirasvVagas = 1;
                }

                for (int c = 0; c < DezpPrimeirasvVagas; c++) {
                    VagaLivre = -1;


                    for (j = 0; j < 30 ; j++) {     //BUSCA VAGAS VAZIAS

                        if (Veil[j].ativo == 0) {       //SOMENTE SE NÃO TIVER ATIVO, OU SEJA, COM VAGA OCUPADA

                            VagaLivre = j;      //REGISTRA AS VAGAS VAZIAS EM "VagaLivre"

                            break;
                        }
                    }

                    if (VagaLivre != -1) {

                        system("cls");

                        printf("\n\n------------------------------------------------------\n\n");

                        if (veiculosregistrado < 10) {

                            printf("   CADASTRO OBRIGATÓRIO DOS 10 PRIMEIROS VEÍCULOS. %d | 10 VEICULOS REGISTRADOS \n", veiculosregistrado + 1);

                        }
                        else {
                            printf("   REALIZAR O REGISTRO DE UM VEÍCULO\n");
                        }
                        printf("\n------------------------------------------------------\n\n");

                        printf("MODELO DO VEÍCULO => ");
                        scanf(" %[^\n]s", Veil[VagaLivre].Modelo);

                        printf("\n\n------------------------------------------------------\n\n");
                        printf("PLACA DO VEÍCULO => ");
                        scanf(" %[^\n]s", Veil[VagaLivre].Placa);

                        printf("\n\n------------------------------------------------------\n\n");
                        printf("VAGA OCUPADA PELO VEÍCULO => ");
                        scanf("%d", &Veil[VagaLivre].Vaga);

                        printf("\n\n------------------------------------------------------\n\n");
                        printf("QUANTIDADE DE HORAS => ");
                        scanf("%d", &Veil[VagaLivre].Horas);

                        Veil[VagaLivre].VH = 12.00 * Veil[VagaLivre].Horas;
                        Veil[VagaLivre].ativo = 1;
                        veiculosregistrado++;

                        printf("\n\n------------------------------------------------------\n\n");

                        printf("CONFIRMAÇÃO DE DADOS\n");

                        printf("\n------------------------------------------------------\n\n");

                        printf("POSIÇÃO NO SISTEMA => %d\n\n", VagaLivre + 1);

                        printf("MODELO => %s\n\n", Veil[VagaLivre].Modelo);

                        printf("PLACA => %s\n\n", Veil[VagaLivre].Placa);

                        printf("VAGA => %d\n\n", Veil[VagaLivre].Vaga);

                        printf("HORAS => %d\n\n", Veil[VagaLivre].Horas);

                        printf("VALOR A SE PAGAR => %.2f\n\n", Veil[VagaLivre].VH);
                        system("pause");

                    }

                    else {
                        printf("\n\n------------------------------------------------------\n\n");

                        printf("\nO ESTACIONAMENTO ESTÁ LOTADO. O LIMITE DE 30 VEÍCULOS FOI ATINGIDO.\n");

                        printf("\n------------------------------------------------------\n\n");
                        system("pause");
                        break;
                    }
                }
                break;
            }

            case 2:

                system("cls");


                for (j = 0; j < 30 ; j++) {

                    if (Veil[j].ativo == 1) {           //VAGAS EM USO E ATIVA A VARIAVEL "VeiculoEnc"

                        VeiculoEnc = 1;

                        printf("\n\n-------------------------------------------------------------------\n\n");

                        printf("   VEÍCULOS JÁ REGISTRADOS\n");

                        printf("\n--------------------------------------------------------------------\n\n");

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
                }




                break;

            case 3:

                system("cls");



                printf("\n\n------------------------------------------------------\n\n");

                printf("   EXCLUIR UM VEÍCULO REGISTRADO\n");

                printf("\n------------------------------------------------------\n\n");

                printf("   EXCLUIR UM VEÍCULO POR VAGA\n\n");


                int vagadoveic;
                printf("DIGITE O NÚMERO DA VAGA QUE VÔCE DESEJA LIBERAR => ");
                scanf("%d", &vagadoveic);

                VeiculoEnc = 0;

                for (j = 0; j < 30 ; j++) {

                    if (Veil[j].ativo == 1 && Veil[j].Vaga == vagadoveic) {   //APENAS VEICULOS ATIVOS E REGISTRADOS E ENCONTRAR VEICULO PELA PLACA

                        Veil[j].ativo = 0;          //VEICULO PASSA A ESTAR INATIVO

                        veiculosregistrado--;          //VARIAVEL QUE CONTABILIZA O TOTAL DE VEICULOS REGISTRADOS -1

                        VeiculoEnc = 1;

                        for (k = j; k < 29; k++) {      //K COMEÇA NA VAGA DO VEICULO EXCLUIDO E VAI ATÉ A POSIÇÃO 28
                            Veil[k] = Veil[k + 1];      //JOGA O CARRO DA FRENTE PARA A POSIÇÃO DE TRAS
                        }


                        Veil[29].ativo = 0;         //A VAGA VAZIA QUE PASSOU A SER A ULTIMA É INATIVADA

                        printf("\n\n------------------------------------------------------\n\n");

                        printf("\nO VEÍCULO DA VAGA %d FOI REMOVIDO COM SUCESSO.\n", vagadoveic);

                        printf("\n------------------------------------------------------\n\n");

                        system("pause");

                        break;

                    }
                }

                if (!VeiculoEnc) {

                    printf("\n\n------------------------------------------------------\n\n");

                    printf("\nNÃO HÁ NENHUM VEÍCULO REGISTRADO NA VAGA %d.\n", vagadoveic);

                    printf("\n------------------------------------------------------\n\n");

                    system("pause");

                    break;

                }


                break;


            case 4:


                PesquisarUmVeiculo(Veil);

            break;



            case 5:


                EditarUmVeiculo(Veil);


                break;

            case 6:


                EstatisticasDosVeiculos(Veil);

                break;

            case 7:

                system("cls");

                printf("\n\n------------------------------------------------------\n\n");

                printf("SAINDO DO PROGRAMA.\n");

                printf("\n------------------------------------------------------\n\n");

                break;

            }
        }
    }
}

