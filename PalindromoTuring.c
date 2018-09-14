#include<stdio.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct _infoM{
	char vlr;//inicial(I), 0, 1 ou espaço em branco(U))
	int estado;//-1 e -2 sao qsim e qnao, respectivamente
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
	v->valor = cadeia[t]; //pega o caractere atual da cadeia para jogar na lista
	v->prev = u->first->prev;
	v->prox=u->first;
	u->first->prev->prox = v;
	u->first->prev = v;
	__fpurge(stdin);
	
	
	u->first = u->first->prev;

	if(u->nItens == 2){
		u->first->prox = u->last;
		u->first->prox->prev = u->first;
	}

	u->nItens++;
	return u;
}

TpLista *display(TpLista *u){
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
				   /*I*/ M[0][0].vlr = 'I'; M[0][0].estado = 0; M[0][0].mov = 1;
				   /*0*/ M[1][0].vlr = 'I'; M[1][0].estado = 1; M[1][0].mov = 1;
				   /*1*/ M[2][0].vlr = 'I'; M[2][0].estado = 2; M[2][0].mov = 1;
			       /*U*/ M[3][0].vlr = 'X'; M[3][0].estado = -1; M[3][0].mov = 0; 

			         //                       q1
				   /*0*/ M[1][1].vlr = '0'; M[1][1].estado = 1; M[1][1].mov = 1;
				   /*1*/ M[2][1].vlr = '1'; M[2][1].estado = 1; M[2][1].mov = 1;
			       /*U*/ M[3][1].vlr = 'X'; M[3][1].estado = 3; M[3][1].mov = -1;

					//                        q2
				   /*0*/ M[1][2].vlr = '0'; M[1][2].estado = 2; M[1][2].mov = 1;
				   /*1*/ M[2][2].vlr = '1'; M[2][2].estado = 2; M[2][2].mov = 1;
			       /*U*/ M[3][2].vlr = 'X'; M[3][2].estado = 4; M[3][2].mov = -1;

					//                        q3
				   /*0*/ M[1][3].vlr = '0'; M[1][3].estado = 5; M[1][3].mov = 0;
				   /*1*/ M[2][3].vlr = '1'; M[2][3].estado = -2; M[2][3].mov = 0;

//											  q4
				   /*0*/ M[1][0].vlr = '0'; M[1][0].estado = -2; M[1][0].mov = 0;
				   /*1*/ M[2][0].vlr = '1'; M[2][0].estado = 5; M[2][0].mov = 0;

//											  q5
				   /*I*/ M[0][0].vlr = 'I'; M[0][0].estado = 0; M[0][0].mov = 1;
				   /*0*/ M[1][0].vlr = '0'; M[1][0].estado = 5; M[1][0].mov = -1;
				   /*1*/ M[2][0].vlr = '1'; M[2][0].estado = 5; M[2][0].mov = -1;
			       /*U*/ M[3][0].vlr = 'X'; M[3][0].estado = 5; M[3][0].mov = -1; 

	TpLista *u = (TpLista *)malloc(sizeof(TpLista));
	u->first = NULL;
	u->last = NULL;
	u->nItens = 0;
	char cadeia[10];
	puts("Insira uma cadeia binaria:");
	scanf("%s", cadeia);

	TpNodo *l = (TpNodo *)malloc(sizeof(TpNodo));
	TpNodo *v = (TpNodo *)malloc(sizeof(TpNodo));
		l->valor = 'U';
		l->m = 0;
		l->prox = NULL;
		v->valor = 'I'; //insere o primeiro nodo da lista como o caractere inicial da fita
		v->m = 0;
		u->first = v;
		u->last = l;
		u->first->prox = u->last;
		u->first->prev = NULL;
		u->last->prox = NULL;
		u->last->prev = u->first;
		u->first = u->first->prox;
		u->nItens = 2;
		for(int t=0; t<strlen(cadeia); t++){
			u=push(u, cadeia, t);
			u->nItens++;
		}
		printf("\n");

		u->first = u->first->prev;
	int estadoA = 0;
	while(estadoA >= 0){
		/*if(u->first->valor == 'I'){
			u->first->valor = M[0][estadoA].vlr;
			u->first->m = M[0][estadoA].mov;
			estadoA = M[0][estadoA].estado;
			printf("F\n");
		}
		else if(u->first->valor == '0'){
			u->first->valor = M[1][estadoA].vlr;
			u->first->m = M[1][estadoA].mov;
			estadoA = M[1][estadoA].estado;
			printf("B\n");
		}
		else if(u->first->valor == '1'){
			u->first->valor = M[2][estadoA].vlr;
			u->first->m = M[2][estadoA].mov;
			estadoA = M[2][estadoA].estado;
			printf("C\n");
		}
		else{//(u->first->valor == 'X'){
			u->first->valor = M[3][estadoA].vlr;
			u->first->m = M[3][estadoA].mov;
			estadoA = M[3][estadoA].estado;
			printf("D\n");
		}*/
		int mv;
		if(estadoA == 0){
			if(u->first->valor == 'I'){
				u->first->m = 1;
			}else if(u->first->valor == '0'){
				u->first->valor = 'I';
				estadoA = 1;
				u->first->m = 1;
			}else if(u->first->valor == '1'){
				u->first->valor = 'I';
				estadoA = 2;
				u->first->m = 1;
			}else{//(u->first->valor == 'U')
				estadoA = -1;
				u->first->m = 0;
			}
		}else if(estadoA == 1){
			if(u->first->valor == '0'){
				u->first->m = 1;
			}else if(u->first->valor == '1'){
				u->first->m = 1;
			}else{//(u->first->valor == 'U')
				estadoA = 3;
				u->first->m = -1;
			}
		}else if(estadoA == 2){
			if(u->first->valor == '0'){
				u->first->m = 1;
			}else if(u->first->valor == '1'){
				u->first->m = 1;
			}else if(u->first->valor == 'U'){
				estadoA = 4;
				u->first->m = -1;
			}else{}
		}else if(estadoA == 3){
			if(u->first->valor == '0'){
				u->first->valor = 'U';
				estadoA = 5;
				u->first->m = 0;
			}else if(u->first->valor == '1'){
				estadoA = -2;
				u->first->m = 0;
			}else{
				estadoA = -1;
				u->first->m = 0;
			}
		}else if(estadoA == 4){
			if(u->first->valor == '0'){
				estadoA = -2;
				u->first->m = 0;
			}else if(u->first->valor == '1'){
				u->first->valor = 'U';
				estadoA = 5;
				u->first->m = 0;
			}else{
				estadoA = -1;
				u->first->m = 0;
			}
		}else if(estadoA == 5){
			if(u->first->valor == 'I'){
				estadoA = 0;
				u->first->m = 1;
			}else if(u->first->valor == '0'){
				estadoA = 5;
				u->first->m = -1;
			}else if(u->first->valor == '1'){
				estadoA = 5;
				u->first->m = -1;
			}else{//(u->first->valor == 'U')
				estadoA = 5;
				u->first->m = -1;
			}
		}
		if(u->first->m == -1){
			mv = -1;
			u->first = u->first->prev;
		}else if(u->first->m == 1){
			mv = 1;
			u->first = u->first->prox;
		}
		printf("(q%d, ", estadoA);
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
		
		while(u->first->prox != NULL ){
			u->first = u->first->prox;
			printf("%c", (u->first->valor));
			
		}
		while(u->first != a){
			u->first = u->first->prev;
		}
		printf(",  %d)\n\n", mv);

	}
	free(u);
	free(l);
	free(v);
	return 0;
}