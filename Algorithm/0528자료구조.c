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
	// 새로운 노드를 생성한다
	node *temp = (node*)malloc(sizeof(node));
	// 새 노드에 value, next값을 넣어준다.
	temp->value = value;
	temp->next = NULL;

	// 만약 List에 아무것도 없다면
	if (list->head == NULL){

	}
	// List에 값이 있다면
	else{

	}
}

node* searchNode(List *list, int value){
	// list에서 해당값을 가진 노드를 찾아 그 노드의 주소값을 돌려준다.
	return NULL;
}

void delete(List *list, node* n){
	// list에서 해당 node 주소값을 찾아 삭제한다.
}

void print(List *list){
	// temp를 head로 초기화.
	node *temp = list->head;

	// temp 가 끝이 아닐때까지
	while (temp != ....){
		printf("%d --> ", temp->value);
		temp = // 다음 노드값을 넣어준다.
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