#include <stdio.h>
#include <stdlib.h>

/*      Gerenciamento de Impressoras em Rede
A empresa PrintTech administra um parque de impressoras em diferentes departamentos de um centro de tecnologia. Para facilitar o controle e a manutenção desses dispositivos, a equipe de TI precisa de um sistema para registrar cada impressora da rede. As informações incluem um ID único, a marca do equipamento, e o número total de impressões realizadas até o momento. O sistema deve exibir um relatório com o resumo das impressoras cadastradas e identificar a impressora que mais realizou impressões, auxiliando no planejamento de reposição de insumos.

Atividades a serem realizadas:

Criar uma struct chamada Impressora contendo ID, marca e total de impressões.
Implementar uma função para o cadastro de N impressoras, onde o usuário informará os dados de cada uma.
Criar uma função que exiba a lista com os dados de todas as impressoras registradas.
Criar uma função que identifique e exiba a impressora com o maior número de impressões realizadas.
*/

struct Impressora{
    int id;
    char marca[20];
    int totalImpressoes;
};

void cadastrar(struct Impressora *ip, int n){
    int i=0;

    for(i=0;i<n;i++){
        printf("Digite o ID da %da impressora: ", i+1);
        scanf("%d", &ip[i].id);
        fflush(stdin);

        printf("Digite a marca da %da impressora: ", i+1);
        scanf("%s", &ip[i].marca);
        fflush(stdin);
        
        printf("Digite o total de impressoes da %da impressora: ", i+1);
        scanf("%d", &ip[i].totalImpressoes);
        fflush(stdin);
    }

}
void listar(struct Impressora *ip, int n){
    int i=0;

    system("cls");
    
    for(i=0;i<n;i++){
        printf("\nID da %da impressora: %d",i+1, ip[i].id);

        printf("\nMarca da %da impressora: %s",i+1, ip[i].marca);

        printf("\nTotal de impressoes da %da impressora: %d\n", i+1, ip[i].totalImpressoes);
    }
    system("pause");

}

void calculaTotalImpressao(struct Impressora *ip, int n){
    system("cls");
    int i=0;
    int maior=-1;

    for(i=0;i<n;i++){
        if(ip[i].totalImpressoes > ip[i+1].totalImpressoes){
            maior=i;
        }
    }

    printf("\nA impressora que teve mais impressoes foi a impressora ID: %d\n", ip[maior].id);

    system("pause");
}


int main(){

    int escolha;
    
    printf("Digite a quantidade de impressoras: ");
    scanf("%d", &escolha);

    struct Impressora ip[escolha];

    cadastrar(ip, escolha);
    listar(ip, escolha);
    calculaTotalImpressao(ip, escolha);
}


