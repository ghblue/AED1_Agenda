#include <stdio.h>
#include <stdlib.h>


//variasveis globais
int* c;
float* a;
int* contador_pessoas;
contador_pessoas = 0;
void* pBuffer;
struct* pessoa;

//elementos da agenda
struct pessoa{
    char nome[20];
    int idade;
    int telefone;
};
//funcao que realloca o tamanho do pBuffer
void change_size(){

    pBuffer = (void*)realloc(pBuffer, sizeof(int)+sizeof(float)+(sizeof(struct pessoa)**contador_pessoas));
    c = pBuffer;
    a = c+1;
    pessoa = a+1;

}

void insere_pessoa(){

    struct* pessoaAux = (struct* pessoa)malloc(sizeof(struct pessoa));


}

void remove_pessoa(){




}

void lista_agenda(){


}



int main(){

    int* seletor;
    pBuffer = (void*)malloc(sizeof(int)+sizeof(float)+(sizeof(struct pessoa)**contador_pessoas));

    while(1){
        printf("\n-----------AGENDA----------\n");
        printf("1-Adicionar\n2-Remover\n3-Salvar\n4-Listar\n5-Sair\nDigite a opcao desejada: ");
        scanf("%d", &seletor);
            if(*seletor == 1){
                insere_pessoa();
                ++contador_pessoas;
            }
            if(*seletor == 2){
                remove_pessoa();
                --contador_pessoas;
            }
            if(*seletor == 3){
                change_size();
            }
            if(*seletor == 4){
                lista_agenda();
            }
            if(*seletor == 5){
                exit(1);
            }

    }


    return 0;
}
