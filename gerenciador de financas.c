#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("\n");
    printf("Calculadora e gerenciador de financas\n");
    printf("[+][+][+][+][+][+][+][+][+][+][+][+][+][+][+][+][+][+]\n");
    printf("1. Prever suas financas em alguns meses\n");
    printf("2. Calcular seus gastos mensais\n");
    printf("3. Ver quantas parcelas faltam de uma compra\n");
    // printf("4. Conversor de moedas\n");
    printf("5. Sair\n");
}

void preverfinancas()
{
    float renda, despesas;
    int meses;

    printf("Insira aqui sua renda mensal: \n");
    scanf("%f", &renda);

    printf("Insira aqui sua despesa mensal: \n");
    scanf("%f", &despesas);

    printf("Insira o numero de meses para a previsao: \n");
    scanf("%d", &meses);

    float saldo = renda - despesas;
    float saldoFuturo = saldo * meses;

    printf("Saldo atual: %.2f\n", saldo);
    printf("Saldo em %d meses: %.2f\n", meses, saldoFuturo);
}

int main()
{
    int opcao;

    do
    {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            preverfinancas();
            break;
        case 2:
            calculargastos();
            break;
        case 3:
            verificarparcelafalta();
            break;
        case 5:
            printf("Saindo do programa. Obrigado!\n");
            break;
        default:
            printf("Opcao invalida escolha outra.\n");
        }
    } while (opcao != 5);
    return 0;
}

void calculargastos()
{
    float gastostotal = 0;
    int numerogastos;

    printf("quantos gastos deseja calcular? \n");
    scanf("%d", &numerogastos);

    for (int i = 0; i < numerogastos; i++)
    {
        float numerogastos;
        printf("informe o valor do gasto %d: ", i + 1);
        scanf("%f", &numerogastos);
        gastostotal += numerogastos;
    }
    printf("Seus gastos totais do mes sao: %.2f\n", gastostotal);
}

void verificarparcelafalta()
{
    int numeroparcelas, totalparcelas;
    float valorparcela, valorpago = 0.0f, valorfalta = 0.0f;

    printf("Informe o numero total de parcelas: ");
    scanf("%d", &totalparcelas);

    printf("Informe o valor de cada parcela: ");
    scanf("%f", &valorparcela);

    printf("Informe o numero de parcelas ja pagas: ");
    scanf("%d", &numeroparcelas);

    if (numeroparcelas > totalparcelas)
    {
        printf("Erro: O numero de parcelas pagas excede o numero total de parcelas.\n");
        return;
    }
    valorpago = numeroparcelas * valorparcela;
    valorfalta = (totalparcelas - numeroparcelas) * valorparcela;

    printf("Valor total que falta pagar: %.2f\n", valorfalta);
    printf("Número de parcelas pagas: %d\n", numeroparcelas);
    printf("Número de parcelas restantes: %d\n", totalparcelas - numeroparcelas);
}