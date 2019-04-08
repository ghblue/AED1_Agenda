#include <stdio.h>
#include <stdlib.h>


//variasveis globais
void* pBuffer;

//elementos da agenda
struct pessoa{
    char nome[20];
    int idade;
    double telefone;
};


struct variaveis_usadas{
	int i, j, k;
	int aux, aux1, aux2, aux3;
	int contador_pessoas;
	struct pessoa* aux_pessoa;
	int seletor;
};



//funcao que realloca o tamanho do pBuffer
void change_size(struct variaveis_usadas* head){

    pBuffer = (void*)realloc(pBuffer, sizeof(struct variaveis_usadas)+(sizeof(struct pessoa)* head->contador_pessoas));
    printf("realocado com sucesso");
    
}

void insere_pessoa(struct variaveis_usadas* head){

	struct pessoa* aux;
	head->contador_pessoas = head->contador_pessoas + 1;
	change_size(head);
	// a linha abaixo é descrita por: o ponteiro aux_pessoa para preencher os dados a serem inseridos, esse ponteiro aponta para o inicio e a partir dessa linha ele vai apontar parao ultimo elemento do pBuffer;
	aux =  pBuffer + (sizeof(struct variaveis_usadas) + (sizeof(struct pessoa) * (head->contador_pessoas - 1 )));
	printf("\n insira o nome da pessoa: ");
	//getchar();
	scanf("%s", aux->nome);
	printf("\n insira o número de telefone: ");
	scanf("%lf", &aux->telefone);
}

void remove_pessoa(struct variaveis_usadas* head){






}

void lista_agenda(struct variaveis_usadas* head){

	struct pessoa* aux;
	aux = pBuffer + sizeof(struct variaveis_usadas);
	for (head->i = 0; head->i < head->contador_pessoas; head->i = head->i + 1)
	{
		printf("\nPessoa[%d]: %s", head->i, aux->nome);
		printf("\ntelefone[%d]: %.0lf", head->i, aux->telefone);
		aux++;
	}


}



int main(){


	struct variaveis_usadas* head;
    pBuffer = (void*)malloc(sizeof(struct variaveis_usadas));
	head = pBuffer;
	head->contador_pessoas = 0;

    while(1){
        printf("\n-----------AGENDA----------\n");
        printf("1-Adicionar\n2-Remover\n3-Salvar\n4-Listar\n5-Sair\nDigite a opcao desejada: ");
        scanf("%d", &head->seletor);
            if(head->seletor == 1){
               insere_pessoa(head);
            	printf("\n Pessoa adicionada com sucesso");
            }
            if(head->seletor == 2){
              //  remove_pessoa(head);
            }
            if(head->seletor == 3){
             //   change_size(head);
            }
            if(head->seletor == 4){
                lista_agenda(head);
            }
            if(head->seletor == 5){
                exit(1);
            }

    }


    return 0;
}
