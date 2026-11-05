#include <stdio.h>

// Aqui é a estrutura para armazenar os dados de um produto
struct Produto {
    int codigo;
    char nome[50];
    char categoria[30];
    char marca[30];
    float preco;
};

int main() {
 struct Produto produtos[100];

    int opcao;
    int quantidade = 0;
    int i;
    int codigorepetido;

    do {
        printf("\n==================================\n");
        printf("   CATALOGO DE ELETRONICOS\n");
        printf("==================================\n");

        printf("1 - Cadastrar um produto\n");
        printf("2 - Listar produto\n");
        printf("3 - Pesquise por codigo\n");
        printf("4 - Pesquise por nome\n");
        printf("5 - Consulte por categoria\n");
        printf("6 - Altere produto\n");
        printf("7 - Exclua produto\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
              if (quantidade >= 100) {
                    printf("\no limite de produtos foi atingido!\n");
                    break;
                }

                printf("\n===== CADASTRAR PRODUTO =====\n");

                printf("qual é o codigo do produto? ");
                scanf("%d", &produtos[quantidade].codigo);

                codigorepetido = 0;

                for (i = 0; i < quantidade; i++) {

                    if (produtos[i].codigo ==
                        produtos[quantidade].codigo) {

                        codigorepetido = 1;
                    }
                }

                if (codigorepetido == 1) {

                    printf("\nErro! Esse codigo ja existe.\n");

                } else {

                    printf("Digite o nome: ");
                    scanf(" %49[^\n]", produtos[quantidade].nome);

                    printf("Digite a categoria: ");
                    scanf(" %29[^\n]", produtos[quantidade].categoria);

                    printf("Digite a marca: ");
                    scanf(" %29[^\n]", produtos[quantidade].marca);

                    printf("Digite o preco: ");
                    scanf("%f", &produtos[quantidade].preco);

                    if (produtos[quantidade].preco <= 0) {

                        printf("\nErro! O preco tem que ser maior que zero.\n");

                    } else {

                        quantidade++;

                        printf("\nProduto cadastrado com sucesso!\n");
                    }
                }

                break;

            case 2:

                printf("\n===== PRODUTOS CADASTRADOS =====\n");

                if (quantidade == 0) {

                    printf("Nao ha produto cadastrado.\n");

                } else {

                    for (i = 0; i < quantidade; i++) {

                        printf("\n--------------------------\n");

                        printf("Codigo: %d\n", produtos[i].codigo);

                        printf("Nome: %s\n", produtos[i].nome);

                        printf("Categoria: %s\n", produtos[i].categoria);

                        printf("Marca: %s\n", produtos[i].marca);

                        printf("Preco: R$ %.2f\n", produtos[i].preco);
                    }
                }

                
            
    } while (opcao != 0);

    return 0;
}
