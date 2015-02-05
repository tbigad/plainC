#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int data; /* любые члены */
    struct item *next; /* указатель на другую структуру типа item*/
} Item;

typedef struct stack
{
    Item *first;
} Stack;

/* Изменяет стек, возращая возвращая значение топа, которой позже можно удалить*/
int pop(Stack *StackPop)
{
	int p;
	Item *t;
	t = (Item *)malloc(sizeof(Item));
	if (StackPop->first != NULL)
	{
		p = StackPop->first->data;
		t = StackPop->first;
		StackPop->first = StackPop->first->next;
		free(t);
		return p;
	} 
	else
		printf("\n stack is empty.");
}

/* Добовляет значение в вершину стека, возвращает значение новой вершины */
Stack *push(int PushData, Stack *StackPush)
{
    Item* p;
    p = (Item *)malloc(sizeof(Item));
    p->data = PushData;
    p->next = StackPush->first;
    StackPush->first = p;
    return StackPush;
}

void display(Stack *DisStack)
{
	Item *p;
	if (DisStack->first == NULL)
	{
		printf("stack is empty");
	}
	else
	{
		printf("Stack: \n");
		p=DisStack->first;
		while(p != NULL)
		{
			printf("\n %d", p->data);
			p=p->next;
		}
	}	
}

Stack* init(void)
{
    Stack *StackPtr = (Stack*)malloc(sizeof(Stack)); /* создание элемента */
    StackPtr->first = NULL;
	return StackPtr;
}

/* копирует перебором возвращая новый стек а промежуточный удаляет*/
Stack *CopyStack(Stack *CopyS)
{
	Stack *_CopyStack = init();
	Stack *_BettwenStack = init();
	Item *p = CopyS->first;
	while(p != NULL)
	{
		_BettwenStack = push(p->data,_BettwenStack);
		p=p->next;
	}
	p = _BettwenStack->first;
	while(p != NULL)
	{
		_CopyStack = push(p->data,_CopyStack);
		p=p->next;
	}
	free(_BettwenStack);
	return _CopyStack;
}

void destroy(Stack* Dstack)
{
    if(Dstack != NULL)
    {
    printf("No stack");
    }
}

int main(void)
{
	Stack *top1 = init();
	Stack *top2;
	push(1,top1);
	push(2,top1);
	push(3,top1);
	push(4,top1);
	push(5,top1);
	top2 = CopyStack(top1);
	printf("Hello World!\n");
    return 0;
}


