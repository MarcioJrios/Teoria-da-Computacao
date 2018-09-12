#include<stdio.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct _infoM{
	char valor;//inicial, 0, 1 ou null(espaço em branco)
	char estado;
	int mov;//-1 esq, 0 não move, 1 dir
} TpInfoM;

typedef struct _nodo{
	char valor;
	int m;
	struct _nodo *prox;
	struct _nodo *prev;
} TpNodo;

typedef struct _lista{
	int nItens;
	TpNodo *first;
	TpNodo *last;
} TpLista;

TpLista *push(TpLista *u, char cadeia[10], int t){
	TpNodo *v = (TpNodo *)malloc(sizeof(TpNodo));
	
		if(u->nItens == 0){
			u->first = v;
		}else{
			v->prox=u->first;
			u->first->prev = v;
	}
	system("clear");
	__fpurge(stdin);
	
	if(u->nItens == 0){
		TpNodo *l = (TpNodo *)malloc(sizeof(TpNodo));
		l->valor = 'X';
		l->prox = NULL;
		v->valor = 'I'; //insere o primeiro nodo da lista como o caractere inicial da fita
		u->first = v;
		u->last = l;
		u->first->prox = l;
		u->first->prev = NULL;
		u->last->prox = NULL;
		u->last->prev = u->first;
		printf("e");
		u->nItens++;
	}else{
		v->valor = cadeia[t]; //pega o caractere atual da cadeia pra jogar na lista
		u->first = v;
		u->first->prev = NULL;

	}
	u->nItens++;
	return u;
}
/*void *pop(TpLista *u){
	int n;
	if(u->nItens == 0){
		printf("Lista Vazia!\n");
		return u;
	}
	printf("Digite o codigo do produto que deseja remover: \n");
	scanf("%d", &n);
	TpNodo *aux2;
	TpLista aux1;
	aux1 = *u;
	if(u->first->prox == NULL && u->first->prev == NULL && u->first->info.cod == n){	
		u->first = NULL;
		u->nItens=0;
		printf("Elemento de codigo [%d] removido com sucesso!\n", n);
		return u;
	}else{
		while(u->first != NULL){
			
			if(u->first->info.cod == n){
				if(u->first->prev == NULL){
					u->first = u->first->prox;
					u->first->prev = NULL;
					printf("Elemento de codigo [%d] removido com sucesso!\n", n);
					u->nItens--;
					return u;
				}else if(u->first->prox == NULL){
						u->first = u->first->prev;
						u->first->prox = NULL;
						while(u->first->prev != NULL){
							u->first = u->first->prev;
						}
						printf("Elemento de codigo [%d] removido com sucesso!\n", n);
						u->nItens--;
						return u;
					}else{
						aux2 = u->first;
						u->first = u->first->prox;
						u->first->prev = aux2->prev;
						u->first = u->first->prev;
						u->first->prox = aux2->prox;
						while(u->first->prev != NULL){
							u->first = u->first->prev;
						}
						printf("Elemento de codigo [%d] removido com sucesso!\n", n);
						u->nItens--;
						free(aux2);
						return u;
					}
				}
			aux1 = *u;
			u->first = u->first->prox;
		}
				
	}
	if(u->first == NULL && u->nItens > 0)
		*u = aux1;
	while(u->first->prev != NULL){
		u->first = u->first->prev;
		}
	printf("Elemento de código %d não encontrado", n);
	system("sleep 1");
	return u;
}*/

TpLista *display(TpLista *u){
	system("clear");
	TpLista aux = *u;
	if(u->nItens == 0){
			puts("Lista Vazia");
			return u;
	}
	printf("Valor: ");
	for(; u->first !=NULL;u->first = u->first->prox){
		printf("%c", (u->first->valor));
	}
		*u = aux;
		return u;
}

int main(){
	int n;
	TpInfoM M[4][6];

					//                        q0
				   /*I*/ M[0][0].valor = 'I'; M[0][0].estado = '0'; M[0][0].mov = 1;
				   /*0*/ M[1][0].valor = 'I'; M[1][0].estado = '1'; M[1][0].mov = 1;
				   /*1*/ M[2][0].valor = 'I'; M[2][0].estado = '2'; M[2][0].mov = 1;
			       /*U*/ M[3][0].valor = 'X'; M[3][0].estado = 's'; M[3][0].mov = 0; 

			         //                       q1
				   /*0*/ M[1][1].valor = '0'; M[1][1].estado = '1'; M[1][1].mov = 1;
				   /*1*/ M[2][1].valor = '1'; M[2][1].estado = '1'; M[2][1].mov = 1;
			       /*U*/ M[3][1].valor = 'X'; M[3][1].estado = '3'; M[3][1].mov = -1;

					//                        q2
				   /*0*/ M[1][2].valor = '0'; M[1][2].estado = '2'; M[1][2].mov = 1;
				   /*1*/ M[2][2].valor = '1'; M[2][2].estado = '2'; M[2][2].mov = 1;
			       /*U*/ M[3][2].valor = 'X'; M[3][2].estado = '4'; M[3][2].mov = -1;

					//                        q3
				   /*0*/ M[1][3].valor = '0'; M[1][3].estado = '5'; M[1][3].mov = 0;
				   /*1*/ M[2][3].valor = '1'; M[2][3].estado = 'n'; M[2][3].mov = 0;

//											  q4
				   /*0*/ M[1][0].valor = '0'; M[1][0].estado = 'n'; M[1][0].mov = 0;
				   /*1*/ M[2][0].valor = '1'; M[2][0].estado = '5'; M[2][0].mov = 0;

//											  q5
				   /*I*/ M[0][0].valor = 'I'; M[0][0].estado = '1'; M[0][0].mov = 1;
				   /*0*/ M[1][0].valor = '0'; M[1][0].estado = '5'; M[1][0].mov = -1;
				   /*1*/ M[2][0].valor = '1'; M[2][0].estado = '5'; M[2][0].mov = -1;
			       /*U*/ M[3][0].valor = 'X'; M[3][0].estado = '5'; M[3][0].mov = -1; 

	TpLista *u = (TpLista *)malloc(sizeof(TpLista));
	u->first = NULL;
	u->last = NULL;
	u->nItens = 0;
	char cadeia[10];
	puts("Insira uma cadeia binaria:");
	scanf("%s", cadeia);
		for(int t=0; t<=strlen(cadeia); t++){
			u=push(u, cadeia, t);
			printf("A");
			u->nItens++;
		}
	char estadoA = '0';
	while(u->first->prox != NULL || estadoA != 's' || estadoA != 'n'){
		if(estadoA == '0'){
			if(u->first->valor == 'I'){
				u->first->m = M[0][0].mov;
				puts("a");
			}else if(u->first->valor == '0'){
				u->first->valor = M[1][0].valor;
				estadoA = M[1][0].estado;
				u->first->m = M[1][0].mov;
				puts("b");
			}else if(u->first->valor == '1'){
				u->first->valor = M[2][0].valor;
				estadoA = M[2][0].estado;;
				u->first->m = M[2][0].mov;
				puts("c");
			}else{//(u->first.valor == 'X')
				estadoA = M[3][0].estado;
				u->first->m = M[3][0].mov;
				puts("d");
			}
		}else if(estadoA == '1'){
			if(u->first->valor == '0'){
				u->first->m = M[1][1].mov;
			}else if(u->first->valor == '1'){
				u->first->m = M[2][1].mov;
			}else{//(u->first.valor == 'X')
				estadoA = '3';
				u->first->m = M[3][1].mov;
			}
		}else if(estadoA == '2'){
			if(u->first->valor == '0'){
				u->first->m = M[1][2].mov;
			}else if(u->first->valor == '1'){
				u->first->m = M[2][2].mov;
			}else{//(u->first.valor == 'X')
				estadoA = '4';
				u->first->m = M[3][2].mov;
			}
		}else if(estadoA == '3'){
			if(u->first->valor == '0'){
				estadoA = '5';
				u->first->m = M[1][3].mov;
			}else{//(u->first.valor == '1')
				estadoA = 'n';
				u->first->m = M[2][3].mov;
			}
		}else if(estadoA == '4'){
			if(u->first->valor == '0'){
				estadoA = 'n';
				u->first->m = M[1][4].mov;
			}else{//(u->first.valor == '1')
				estadoA = '5';
				u->first->m = M[2][4].mov;
			}
		}else if(estadoA == '5'){
			if(u->first->valor == 'I'){
				estadoA = M[0][5].estado;
				u->first->m = M[0][5].mov;
			}else if(u->first->valor == '0'){
				estadoA = M[1][5].estado;
				u->first->m = M[1][5].mov;
			}else if(u->first->valor == '1'){
				estadoA = M[2][5].estado;;
				u->first->m = M[2][5].mov;
			}else{//(u->first.valor == 'X')
				estadoA = M[3][5].estado;
				u->first->m = M[3][5].mov;
			}
		}

		if(u->first->m == -1)
			u->first = u->first->prev;
		else if(u->first->m == 1)
			u->first = u->first->prox;

		printf("(q%c, ", estadoA);
		TpNodo *a = (TpNodo *)malloc(sizeof(TpNodo));
		a = u->first;
		while(u->first->prev!=NULL){
			u->first = u->first->prev;
		}
		printf("%c", (u->first->valor));
		while(u->first != a){
			printf("%c", (u->first->prox->valor));
			u->first = u->first->prox;
		}
		printf(",");
		u->first = u->first->prox;
		while(u->first->prox != NULL ){
			printf("%c", (u->first->valor));
			u->first = u->first->prox;
		}
		while(u->first != a){
			u->first = u->first->prev;
		}

		printf(",  %d)", u->first->m);
	}
	do{
		puts("\t\tMENU\n");
		puts("2: Para extrair um elemento da pilha;");
		puts("3: Para listar todos os campos dos elementos da pilha;");
		puts("0: Sair.\n");
		puts("Digite a opção desejada:");
		scanf("%d", &n);
		switch(n){
			case 1:
				//
				break;
				system("clear");
			case 2:
				system("clear");
				//u=pop(u);
				break;
			case 3:
				u=display(u);
				puts("");
				break;
			case 0:
				system("clear");
				puts("Voce escolheu por sair!");
				break;
			default:
				puts("Opcao invalida!");
		}
	}while(n!=0);
	free(u);
	return 0;
}