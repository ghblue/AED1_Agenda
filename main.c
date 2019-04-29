#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//variasveis globais
void* pBuffer;
void* auxpBuffer;

//elementos da agenda
struct pessoa{
    char nome[20];
    int idade;
    double telefone;
};


struct variaveis_usadas{
	int i, j, k;
	int aux, aux1, aux_idade;
	double telefone_remove;
	int contador_pessoas;
	int contador_pessoas2;
	struct pessoa* aux_pessoa;
	int seletor, seletor2;
};



//funcao que realloca o tamanho do pBuffer
void change_size(struct variaveis_usadas* head){

    pBuffer = (void*)realloc(pBuffer, sizeof(struct variaveis_usadas)+(sizeof(struct pessoa)* head->contador_pessoas));
    printf("changed size");
    
}

void swap(int* a, int* b){

	int* aux;
	aux = a;
	a = b;
	b = aux;
}


void insetion_sort(struct variaveis_usadas* head){

	struct pessoa* aux;
	struct pessoa* aux_do_aux;
	head->i = 0;
	head->j = 0;
	head->aux_idade = 0;
	aux = pBuffer + sizeof(struct variaveis_usadas);
	aux_do_aux = aux + (1*sizeof(struct pessoa));
		for (head->i = head->i+1; head->i < head->contador_pessoas; head->i = head->i + 1)
		{
			//head->aux_idade = aux->idade;
			head->j = head->i - 1;


			/*for (head->j = head->i - 1; head->j >= 0; head->j = head->j - 1)
			{
				
			}*/
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



}

void insere_pessoa(struct variaveis_usadas* head){

	struct pessoa* aux;
	head->contador_pessoas = head->contador_pessoas + 1;
	change_size(head);
	// a linha abaixo é descrita por: o ponteiro aux_pessoa para preencher os dados a serem inseridos, esse ponteiro aponta para o inicio e a partir dessa linha ele vai apontar parao ultimo elemento do pBuffer;
	aux =  pBuffer + (sizeof(struct variaveis_usadas) + (sizeof(struct pessoa) * (head->contador_pessoas - 1 )));
	printf("\ninsira o nome da pessoa: ");
	//getchar();
	scanf("%s", aux->nome);
	printf("insira a idade da pessoa: ");
	scanf("%d", &aux->idade);
	printf("insira o número de telefone: ");
	scanf("%lf", &aux->telefone);
	printf("Pessoa adicionada com sucesso");
}

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
		printf("Pessoa removida com sucesso\n");
		change_size(head);
		}
	}




void lista_agenda(struct variaveis_usadas* head){

	struct pessoa* aux;
	aux = pBuffer + sizeof(struct variaveis_usadas);
	for (head->i = 0; head->i < head->contador_pessoas; head->i = head->i + 1)
	{
		printf("\nPessoa  [%d]: %s", head->i, aux->nome);
		printf("\nIdade   [%d]: %d", head->i, aux->idade);
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
        printf("1-Adicionar\n2-Remover\n3-Ordenar\n4-Listar\n5-Sair\nDigite a opcao desejada: ");
        scanf("%d", &head->seletor);
            if(head->seletor == 1){
               insere_pessoa(head);
            }
            if(head->seletor == 2){
              remove_pessoa(head);
            	//change_size(head);
            }
            if(head->seletor == 3){
               	 ordena(head);
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
