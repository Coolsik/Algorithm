#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int value;
	struct Node *next;
}node;
typedef struct ListNode{
	node *head;
}List;
void addFront(List *list, int value){
	// ���ο� ��带 �����Ѵ�
	node *temp = (node*)malloc(sizeof(node));
	// �� ��忡 value, next���� �־��ش�.
	temp->value = value;
	temp->next = NULL;

	// ���� List�� �ƹ��͵� ���ٸ�
	if (list->head == NULL){

	}
	// List�� ���� �ִٸ�
	else{

	}
}

node* searchNode(List *list, int value){
	// list���� �ش簪�� ���� ��带 ã�� �� ����� �ּҰ��� �����ش�.
	return NULL;
}

void delete(List *list, node* n){
	// list���� �ش� node �ּҰ��� ã�� �����Ѵ�.
}

void print(List *list){
	// temp�� head�� �ʱ�ȭ.
	node *temp = list->head;

	// temp �� ���� �ƴҶ�����
	while (temp != ....){
		printf("%d --> ", temp->value);
		temp = // ���� ��尪�� �־��ش�.
	}
}

int main(){
	List *list = (List*)malloc(sizeof(List));
	list->head = NULL;

	addFront(list, 5);
	addFront(list, 4);
	addFront(list, 3);
	addFront(list, 2);
	addFront(list, 1);

	//node *temp = searchNode(list, 3);

	//delete(temp);

	print(list);

	return 0;
}