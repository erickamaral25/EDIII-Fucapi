/*
 ============================================================================
 Name        : MyBinTree.c
 Author      : Erick Amaral
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


//estrutura do no
struct treeNode{
	int value;
	struct treeNode* leftNode;
	struct treeNode* rightNode;
};

//renomear strutura
typedef struct treeNode node;


//funcoes da arvore binaria
//funcao para imprimir a arvore em pre-order
void printPreOrder(node* n){

	if(n != NULL){

		printf("%i ", n->value);
		printPreOrder(n->leftNode);
		printPreOrder(n->rightNode);
	}
}
//funcao para imprimir a arvore em in-order
void printInOrder(node* n){

	if(n != NULL){

		printInOrder(n->leftNode);
		printf("%i ", n->value);
		printInOrder(n->rightNode);
	}
}
//funcao para imprimir a arvore em post-order
void printPostOrder(node* n){

	if(n != NULL){

		printPostOrder(n->leftNode);
		printPostOrder(n->rightNode);
		printf("%i ", n->value);
	}
}

//funcao para inserir um novo no
node* insertNode(int valor, node* left, node* right){

	node* n = (node*) malloc(sizeof(node));

		if(n==NULL){
			exit(1);
		}else{
			n->value = valor;
			n->leftNode = left;
			n->rightNode = right;
		}

	return n;
}


// Arvore Binaria:
//            47
//     25            77
//  11    43      65    93
//


int main(void){
	//cria um no tipo folha na arvore binaria
	node* n = insertNode(47, insertNode(25, insertNode(11, NULL, NULL), insertNode(43, NULL, NULL)), insertNode(77, insertNode(65, NULL, NULL), insertNode(93, NULL, NULL)));

	//imprime a arvore em pre-order
	printf("Printing Pre-Order: ");
	printPreOrder(n);

	//imprime a arvore em in-order
	printf("\nPrinting In-Order: ");
	printInOrder(n);

	//imprime a arvore em post-order
	printf("\nPrinting Post-Order: ");
	printPostOrder(n);

	return EXIT_SUCCESS;
}
