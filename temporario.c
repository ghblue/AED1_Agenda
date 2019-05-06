#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//variasveis globais
void* pBuffer;
void* auxpBuffer;

//elementos da agenda
struct pessoa{
	int tam_nome;
    char *nome;
    int idade;
    double telefone;
};


struct variaveis_usadas{
	int i, j, k;
	int aux, aux1, aux_idade, tam_nomes_total, tam_nomes_parcial, tam_printar;
	double telefone_remove;
	char nome_aux[20];
	int contador_pessoas;
	int contador_pessoas2;
	struct pessoa* aux_pessoa;
	int seletor, seletor2;
};



//funcao que realloca o tamanho do pBuffer
void change_size(struct variaveis_usadas* head){

    pBuffer = (void*)realloc(pBuffer, sizeof(struct variaveis_usadas)+(sizeof(struct pessoa)* head->contador_pessoas) + (head->tam_nomes_total * sizeof(char)));
    //printf("changed size\n");
    
}


/*void insetion_sort(struct variaveis_usadas* head){

	struct pessoa* aux;
	struct pessoa* aux_do_aux;
	struct pessoa* aux_temp = (struct pessoa*)malloc(sizeof(struct pessoa));
	head->i = 0;
	head->j = 0;
	head->aux_idade = 0;
	aux = pBuffer + sizeof(struct variaveis_usadas);
	aux_do_aux = aux + (1*sizeof(struct pessoa));
		for (head->i = head->i+1; head->i < head->contador_pessoas; head->i = head->i + 1)
		{
			head->j = head->i - 1;


		}



}
void ordena(struct variaveis_usadas* head){

    while(1){
        printf("\n-----------Algoritmos de ordenação----------\n");
        printf("1-Insertion_sort\n2-Bubble_sort\n3-merge_sort\n4-bobo_sorte\n5-sair\nDigite a opcao desejada: ");
        scanf("%d", &head->seletor2);
            if(head->seletor2 == 1){
				printf("\ninsertion_sort selecionado");
				//Insertion_sort(head);
				printf("\ninsertion_sort concluido");
            }
            if(head->seletor2 == 2){
            }
            if(head->seletor2 == 3){
            }
            if(head->seletor2 == 4){
            }
            if(head->seletor2 == 5){
            }

    }



}*/

void insere_pessoa(struct variaveis_usadas* head){

	void* aux;

	head->contador_pessoas = head->contador_pessoas + 1;
	printf("insira o nome da pessoa: ");
	scanf("%s", head->nome_aux);
	head->tam_nomes_total = head->tam_nomes_total + ((strlen(head->nome_aux)+1)*sizeof(char));
	head->tam_nomes_parcial = head->tam_nomes_total;
	change_size(head);//reallocando o novo de acordo com o nome da pessoa inserida
	if ((head->contador_pessoas - 1 ) == 0)
	{
	aux = pBuffer + (sizeof(struct variaveis_usadas));
	}else{
	aux = pBuffer + (sizeof(struct variaveis_usadas) + (sizeof(struct pessoa) * (head->contador_pessoas - 1 )) + ((head->tam_nomes_parcial) * sizeof(char)));
	}
	//aux = pBuffer + (sizeof(struct variaveis_usadas) + (sizeof(struct pessoa) * (head->contador_pessoas - 1 )) );
	
	((struct pessoa*)aux)->nome = (char*)(pBuffer + (sizeof(struct variaveis_usadas) + (sizeof(struct pessoa)*(head->contador_pessoas )) ));
	strcpy(((struct pessoa*)aux)->nome,head->nome_aux);
	((struct pessoa*)aux)->tam_nome = (strlen(head->nome_aux)+1);
	printf("insira a idade da pessoa: ");
	scanf("%d", &((struct pessoa*)aux)->idade);
	printf("insira o número de telefone: ");
	scanf("%lf", &((struct pessoa*)aux)->telefone);
	printf("Pessoa adicionada com sucesso");
	head->tam_nomes_parcial = head->tam_nomes_total;

}
/*
void* find_person(struct variaveis_usadas* head){

	head->contador_pessoas2 = 0;
	struct pessoa* aux;
	aux = pBuffer + sizeof(struct variaveis_usadas);
	for (head->i = 0; head->i < head->contador_pessoas; head->i = head->i + 1)
	{
		if (aux->telefone == head->telefone_remove )
		{
			return aux;
		}
		head->contador_pessoas2++;
		aux++;
	}
	return NULL;

}

void remove_pessoa(struct variaveis_usadas* head){

	struct pessoa* aux;
	struct pessoa* aux_cursor;
	struct pessoa* aux_encontra_pessoa;
	printf("digite o telefone da pessoa que quer remover: ");
	scanf("%lf", &head->telefone_remove);
	//chamada da função find_person para chegar na pessoa desejada
	if((aux_encontra_pessoa = (struct pessoa*)find_person(head)) == NULL){
		printf("PESSOA NAO ENCONTRADA\n");
	}else{
	//aux agora está na pessoa desejada e pronto para excluir-a
	aux = pBuffer + sizeof(struct variaveis_usadas) + (head->contador_pessoas2 * sizeof(struct pessoa));
			for (head->i = head->contador_pessoas2; head->i < head->contador_pessoas; head->i = head->i + 1)
			{
					aux_cursor = (struct pessoa*) aux + 1;
					if(aux_cursor == NULL){}
					else{
					strcpy(aux->nome, aux_cursor->nome);
					aux->idade = aux_cursor->idade;
					aux->telefone = aux_cursor->telefone;
					aux + (1 * sizeof(struct pessoa));
				}
			}
		head->contador_pessoas--;
		printf("Pessoa removida com sucesso");
		change_size(head);
		}
}

*/



void lista_agenda(struct variaveis_usadas* head){

	struct pessoa* aux;
	aux = (void*)pBuffer + sizeof(struct variaveis_usadas);
	aux->nome = (void*)pBuffer + sizeof(struct variaveis_usadas) + (1 * sizeof(struct pessoa));
	for (head->i = 0; head->i < head->contador_pessoas; head->i = head->i + 1)
	{
		printf("\nPessoa  [%d]: %s", head->i, aux->nome);
		//printf("\ntam nome: %d", aux->tam_nome - 1);
		//aux->nome = aux->nome + (sizeof(struct pessoa)) + (aux->tam_nome * sizeof(char*));
		printf("\nIdade   [%d]: %d", head->i, aux->idade);
		printf("\ntelefone[%d]: %.0lf", head->i, aux->telefone);
		aux = (void*)aux + (sizeof(struct pessoa*) * (head->contador_pessoas - 1) + (sizeof(char) * aux->tam_nome));
		//aux->nome = (void*)aux + sizeof(struct pessoa);
		//aux->nome = aux->nome + (aux->tam_nome * sizeof(char)) + sizeof(struct pessoa);
	}

}



int main(){


	struct variaveis_usadas* head;
    pBuffer = (void*)malloc(sizeof(struct variaveis_usadas));
	head = pBuffer;
	head->contador_pessoas = 0;
	head->tam_nomes_total = 0;
	head->tam_nomes_parcial = 0;
  	memset(head->nome_aux, 0, 20);

    while(1){
        printf("\n-----------AGENDA----------\n");
        printf("1-Adicionar\n2-Remover\n3-Ordenar\n4-Listar\n5-Sair\nDigite a opcao desejada: ");
        scanf("%d", &head->seletor);
            if(head->seletor == 1){
               insere_pessoa(head);
            }
            if(head->seletor == 2){
            //  remove_pessoa(head);
            }
            if(head->seletor == 3){
             //  ordena(head);
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


