/*2. Напишите функцию подсчета числа концевых узлов заданного бинарного дерева.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node					//структура, описывающая дерево
{
	int m_data;

	struct node *leftPTR;		//ссылка на левую ветвь
	struct node *rightPTR;		//на правую

}Node;

void addNode(Node **, int );	//прототип создания дерева
int orderTravers(Node *);	//прямой обход дерева
int countNodes(Node *);		//проверка существования потомков
int iNumb = 0;						//переменная, используемая в подсчете неполных узлов

void addNode(Node **treePTR, int key)
{
	Node *newNode = NULL;

	if (*treePTR == NULL)
	{
		newNode = (Node *)malloc(sizeof(Node));
		newNode->m_data = key;
		newNode->leftPTR = NULL;
		newNode->rightPTR = NULL;
		*treePTR = newNode;
	}	
	else
	{
		if ((*treePTR)->m_data > key)
			addNode(&((*treePTR)->rightPTR), key);
		else
			addNode(&((*treePTR)->leftPTR), key);
	}
}

int countNodes(Node *treePTR)
{

	if (treePTR ->leftPTR == NULL)
		return 1;

	if (treePTR->rightPTR == NULL)
		return 1;
	return 0;
}

int orderTravers(Node *treePTR)
{

	if (treePTR != NULL)
	{

		if (countNodes(treePTR) == 1)
			iNumb++;
		orderTravers(treePTR->leftPTR);
		orderTravers(treePTR->rightPTR);
	}

	return(iNumb);
}

void main()
{
	Node *rootPTR = NULL;	//инициализация корня дерева
	int iKey = 0;

	printf("Enter nodes (integers)\n");
	printf("Enter any letter to leave:\n");

	while (scanf("%d", &iKey))		//выход из цикла произойдет при вводе любой буквы
	{
		addNode(&rootPTR, iKey);
	}
	printf("Number of uncomplited nodes: %d\n", orderTravers(rootPTR));
}
