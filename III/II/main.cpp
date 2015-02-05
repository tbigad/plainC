/*2. �������� ������� �������� ����� �������� ����� ��������� ��������� ������.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node					//���������, ����������� ������
{
	int m_data;

	struct node *leftPTR;		//������ �� ����� �����
	struct node *rightPTR;		//�� ������

}Node;

void addNode(Node **, int );	//�������� �������� ������
int orderTravers(Node *);	//������ ����� ������
int countNodes(Node *);		//�������� ������������� ��������
int iNumb = 0;						//����������, ������������ � �������� �������� �����

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
	Node *rootPTR = NULL;	//������������� ����� ������
	int iKey = 0;

	printf("Enter nodes (integers)\n");
	printf("Enter any letter to leave:\n");

	while (scanf("%d", &iKey))		//����� �� ����� ���������� ��� ����� ����� �����
	{
		addNode(&rootPTR, iKey);
	}
	printf("Number of uncomplited nodes: %d\n", orderTravers(rootPTR));
}
