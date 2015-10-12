#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 100
typedef struct _tree
{
	char name[MAX];
	char tel[MAX];
	char mail[MAX];
	struct _tree *left;
	struct _tree *right;
}tree;

tree *head;
int menu(void);
void init_tree(void);
void insert_tree(char *name, char *tel, char *mail);
void delete_tree(char *name);
void search_tree(char *name);
void print_tree(tree *temp);
void main(void)
{
	int choice;
	char name[MAX];
	char tel[MAX];
	char mail[MAX];
	init_tree();
	while (1)
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			printf("\n이름을 입력하세요 : ");
			scanf("%s", name);
			fflush(stdin);
			printf("전화번호를 입력해주세요 : ");
			scanf("%s", tel);
			fflush(stdin);
			printf("E-mail을 입력해주세요 : ");
			scanf("%s", mail);
			fflush(stdin);
			insert_tree(name, tel, mail);
			system("cls");
			break;
		case 2:
			printf("\n삭제할 이름을 입력하세요 : ");
			scanf("%s", name);
			fflush(stdin);
			delete_tree(name);
			system("cls");
			break;
		case 3:
			printf("\n검색할 이름을 입력하세요 : ");
			scanf("%s", name);
			fflush(stdin);
			search_tree(name);
			system("cls");
			break;
		case 4:
			printf("\n\t\t☆☆☆☆ 전체 출력 ☆☆☆☆\n");
			print_tree(head->left);
			getch();
			system("cls");
			break;
		case 5:
			system("cls");
			exit(1);
			break;
		default:
			system("cls");
			continue;
		}
	}
}

int menu(void)
{
	int choice;
	printf("------------------------------------------------------------------------------\n");
	printf("\n| (1)친구 등록 || (2)친구 삭제 || (3)이름 검색 || (4)모두 보기 || (5)종 료 |\n\n");
	printf("\n : 메뉴를 선택하세요 ->  ");
	scanf("%d", &choice);
	fflush(stdin);
	return choice;
}

void init_tree(void)
{
	head = (tree*)malloc(sizeof(tree));
	head->left = NULL;
	head->right = NULL;
}

void delete_tree(char *name)
{
	tree *parent, *son, *nexth, *del;
	parent = head;
	del = head->left;
	while (del != NULL)
	{
		parent = del;
		if (strcmp(del->name, name) == 0)
			break;
		else if (strcmp(del->name, name) == 1)
			del = del->left;
		else
			del = del->right;
	}
	if (del == NULL)
	{
		printf("\t삭제할 이름이 없습니다\n");
		getch();
		return;
	}
	if (del->left == NULL && del->right == NULL)
		son = NULL;
	else if (del->right == NULL)
		son = del->left;
	else if (del->right->left == NULL)
	{
		son = del->right;
		son->left = del->left;
	}
	else
	{
		nexth = del->right;
		while (nexth->left->left != NULL)
			nexth = nexth->left;
		son = nexth->left;
		nexth->left = son->right;
		son->left = del->left;
		son->right = del->right;
	}
	if (parent == head || strcmp(parent->name, name) == 1)
		parent->left = son;
	else
		parent->right = son;
	printf("\t\t\t[%s] 삭제완료!!\n", del->name);
	free(del);
	memset(del, 0, sizeof(tree));
	getch();
}
void search_tree(char *name)
{
	tree *son;
	son = head->left;
	while (son != NULL)
	{
		if (strcmp(son->name, name) == 0)
		{
			printf("\n\t\t\t이름 : %s\n", son->name);
			printf("\t\t\t전화번호 : %s\n", son->tel);
			printf("\t\t\tE-mail : %s\n", son->mail);
			getch();
			return;
		}
		else if (strcmp(son->name, name) == 1)
			son = son->left;
		else
			son = son->right;
	}
	printf("\t\t\t검색 실패\n");
	getch();
}
void insert_tree(char *name, char *tel, char *mail)
{
	tree *parent, *son, *newnode;
	parent = head;
	son = head->left;
	while (son != NULL)
	{
		parent = son;
		if (strcmp(son->name, name) == 0)
			break;
		else if (strcmp(son->name, name) == 1)
			son = son->left;
		else
			son = son->right;
	}
	newnode = (tree*)malloc(sizeof(tree));
	newnode->left = NULL;
	newnode->right = NULL;
	strcpy(newnode->name, name);
	strcpy(newnode->tel, tel);
	strcpy(newnode->mail, mail);
	if (parent == head || strcmp(parent->name, name) == 1)
		parent->left = newnode;
	else if (strcmp(parent->name, name) == 0)
		return;
	else
		parent->right = newnode;
}
void print_tree(tree *temp)
{
	if (temp == NULL) return;
	print_tree(temp->left);
	printf("\n\t\t\t이름 : %s\n", temp->name);
	printf("\t\t\t전화번호 : %s\n", temp->tel);
	printf("\t\t\tE-Mail : %s\n", temp->mail);
	print_tree(temp->right);
}