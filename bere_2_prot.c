#include <stdio.h>
#include <stdlib.h>

void menuPrincipal(void);
void menuCategoria(int categoria);
void menuPagamento(void);
void PagamentoDinheiro(void);
void PagamentoCartao(void);

char *produtos[3][4] = {
    {"Detergente", "Sabão em Pó (1kg)", "Esponja", "Amaciante(1Lt)"},
    {"Café", "Leite (cx)", "Arroz (1kg)", "Feijão Preto (1kg)"},
    {"Pão de Forma", "Pão de Integral", "Pão Francês (Unid)", "Sonho"}};

float precos[3][4] = {
    {1.99, 8.99, 1.50, 15.00},
    {19.99, 5.90, 4.50, 8.00},
    {9.50, 12.50, 1.90, 8.50}};

float TotalCarrinho = 0;
float Totalcategoria[3] = {0, 0, 0};

int main(void)
{
    int opcao;
    menuPrincipal();
    return 0;
}

void menuPrincipal(void)
{
    int opcao;
    do
    {
        printf("   Mercearia da dona Bere   | Total no carrinho: R$%.2f\n", TotalCarrinho);
        printf("1. Material de Limpeza\n");
        printf("2. Venda de Alimentos\n");
        printf("3. Padaria\n");
        printf("4. Pagamento\n");
        printf("5. Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            menuCategoria(1);
            break;
        case 2:
            menuCategoria(2);
            break;
        case 3:
            menuCategoria(3);
            break;
        case 4:
            menuPagamento();
            break;
        case 5:
            printf("Obrigado por utilizar o sistema!\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 5);
}

void menuCategoria(int categoria)
{
    int opcao;
    do
    {
        switch (categoria)
        {
        case 1:
            printf(" Material de Limpeza   | Total na Categoria: R$%.2f \n", Totalcategoria[0]);
            printf("ID |  Preço  |  Produto\n");
            for (int i = 0; i < 4; i++)
            {
                printf("%d. | R$%.2f | %s\n", i + 1, precos[0][i], produtos[0][i]);
            }
            break;
        case 2:
            printf(" Venda de Alimentos    | Total na Categoria: R$%.2f \n", Totalcategoria[1]);
            printf("ID |  Preço  |  Produto\n");
            for (int i = 0; i < 4; i++)
            {
                printf("%d. | R$%.2f | %s\n", i + 1, precos[1][i], produtos[1][i]);
            }
            break;
        case 3:
            printf(" Padaria               | Total na Categoria: R$%.2f \n", Totalcategoria[2]);
            printf("ID |  Preço  |  Produto\n");
            for (int i = 0; i < 4; i++)
            {
                printf("%d. | R$%.2f | %s\n", i + 1, precos[2][i], produtos[2][i]);
            }
            break;
        }
        printf("5. | Voltar ao Menu Principal\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        if (opcao < 5) 
        {   
            int quantidade;
            printf("Produto: %s\n", produtos[categoria - 1][opcao - 1]);
            printf("Preço: R$%.2f\n", precos[categoria - 1][opcao - 1]);
            printf("Quanto desse produto?\n");
            scanf("%d", &quantidade);
            Totalcategoria[categoria - 1] += precos[categoria - 1][opcao - 1] * quantidade;
            printf("Total na Categoria: R$%.2f\n", Totalcategoria[categoria - 1]);
            TotalCarrinho += precos[categoria - 1][opcao - 1] * quantidade;
            printf("Total no Carrinho: R$%.2f\n", TotalCarrinho);
        }
        else if (opcao == 5)
        {
            break;
        }
        else
        {
            printf("Opção inválida!\n");
        }

    } while (opcao != 5);
}

void menuPagamento(void)
{
    int opcao;
    do
    {
        printf("\nTotal no Carrinho: R$%.2f\n", TotalCarrinho);
        printf("Total por Categoria\n");
        printf("   | Material de Limpeza: R$%.2f\n", Totalcategoria[0]);
        printf("   | Venda de Alimentos: R$%.2f\n", Totalcategoria[1]);
        printf("   | Padaria: R$%.2f\n", Totalcategoria[2]);
        printf("Qual sera a forma de Pagamento?\n");
        printf("1. | Dinheiro\n");
        printf("2. | Cartão\n");
        printf("3. | Voltar\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            PagamentoDinheiro();
            break;
        case 2:
            PagamentoCartao();
            break;
        case 3:
            printf("Voltando ao Menu Principal...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 3);
}

void PagamentoDinheiro(void)
{
    float valor;
    printf("Digite o valor recebido: ");
    scanf("%f", &valor);
    printf("Troco: R$%.2f\n", valor - TotalCarrinho);
}

void PagamentoCartao(void)
{
    int opcao;
    printf("Pagamento com cartão\n");
    printf("Total: R$%.2f\n", TotalCarrinho);
    printf("O cartão foi aprovado na maquininha?\n");
    printf("1. Sim  2. Nao\n");
    scanf("%d", &opcao);
    if (opcao == 1)
    {
        printf("Pagamento efetuado com sucesso!\n");
    }
    else
    {
        printf("Pagamento não aprovado!\n");
        printf("Deseja tentar novamente ou cancelar a operacao?\n");
        printf("1. Tentar novamente  2. Cancelar\n");
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            PagamentoCartao();
        }
        
    }
}