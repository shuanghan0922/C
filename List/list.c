#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Linkedlist
{
	int data;
	Linkedlist *next;
};

Linkedlist *creat_list(int nodeNum);
Linkedlist *insertElm(Linkedlist *head,int data,int pla);
void printList(Linkedlist *node);

int main(void)
{
	Linkedlist *list = creat_list(10);
	printf("创建初始链表:\n");
	printList(list);
	printf("在链表中插入一个元素:\n");
	insertElm(list,4,6);			//将数字4放置在位置6的地方
	printList(list);
	return 0;
}

Linkedlist *creat_list(int nodeNum)             //创建一个链表
{
	Linkedlist *head = (Linkedlist *)malloc(sizeof(Linkedlist));     
	Linkedlist *temp = head;            
	for (int a=1;a<=nodeNum;a++)
	{
		Linkedlist *node = (Linkedlist *)malloc(sizeof(Linkedlist));   
		node->data = a;
		node->next = NULL;
		temp->next = node;
		temp = temp->next;
	}
	return head;
}

Linkedlist *insertElm(Linkedlist *head,int data,int pla)
{
	Linkedlist *temp = head;
	for (int i=0;i<pla;i++)
	{
		if (temp == NULL)       
		{
			printf("Insert Error!\n");
			return head;             
		}
		temp = temp->next;          
	}
	Linkedlist *c = (Linkedlist *)malloc(sizeof(Linkedlist));    
	c->data = data;            
	c->next = temp->next;       
	temp->next = c;
	return head;
}

void printList(Linkedlist *node)                
{
	while (node->next)                 
	{
		node = node->next;              
		printf("node->data = %d\n",node->data);	
	}
}
