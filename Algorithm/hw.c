#define _CRT_SECURE_NO_WARNINGS

#if 1

#include <stdio.h>
#include <stdlib.h>

#define BOTHCOMPARE (itr1 < m1[0].value && m1[itr1].col == i && m1[itr1].row == j) && (itr2 < m2[0].value && m2[itr2].col == i && m2[itr2].row == j)
#define M1COMPARE itr1 < m1[0].value && m1[itr1].col == i && m1[itr2].row == j
#define M2COMPARE itr2 < m2[0].value && m2[itr2].col == i && m2[itr2].row == j

typedef struct matrix{
	int col;
	int row;
	int value;
}Matrix;

void setMat(Matrix **m, int col, int row, int value){
	Matrix *temp = *m;
	temp->value += 1;
	(*m) = (Matrix*)malloc(sizeof(Matrix)*temp->value);
	for (int i = 0; i<temp->value - 1; i++){
		(*m)[i].col = temp[i].col;
		(*m)[i].row = temp[i].row;
		(*m)[i].value = temp[i].value;
	}
	(*m)[temp->value - 1].col = col;
	(*m)[temp->value - 1].row = row;
	(*m)[temp->value - 1].value = value;
	free(temp);
}

Matrix* matMulti(Matrix *m1, Matrix *m2){
	int itr1 = 1, itr2 = 1;
	Matrix *result = (Matrix*)malloc(sizeof(Matrix));
	result[0].col = m1[0].col;
	result[0].row = m2[0].row;
	result[0].value = 1;
	
	int **temp = (int**)malloc(sizeof(int*)*m1[0].col);
	for (int i = 0; i < m1[0].col; i++){
		temp[i] = (int*)malloc(sizeof(int)*m2[0].row);
	}
	for (int i = 0; i < m1[0].col; i++){
		for (int j = 0; j < m2[0].row; j++){
			temp[i][j] = 0;
		}
	}
	int x, y;
	for (int i = 1; i < m1[0].value; i++){
		for (int j = 1; j < m2[0].value; j++){
			if (m1[i].row == m2[j].col){
				x = m1[i].col;
				y = m2[j].row;
				temp[x][y] += m1[i].value * m2[j].value;
			}
		}
	}

	for (int i = 0; i < m1[0].col; i++){
		for (int j = 0; j < m2[0].row; j++){
			setMat(&result, i, j, temp[i][j]);
		}
	}
	free(temp);
	return result;
}

Matrix* operation(char oper, Matrix *m1, Matrix *m2){
	int itr1 = 1, itr2 = 1;
	Matrix *result = (Matrix*)malloc(sizeof(Matrix));
	result[0].col = m1[0].col;
	result[0].row = m1[0].row;
	result[0].value = 1;
	if (oper == '+'){
		for (int i = 0; i < m1[0].col; i++){
			for (int j = 0; j < m1[0].row; j++){
				if (BOTHCOMPARE){
					setMat(&result, i, j, m1[itr1++].value + m2[itr2++].value);
				}
				else if (M1COMPARE){
					setMat(&result, i, j, m1[itr1++].value);
				}
				else if (M2COMPARE){
					setMat(&result, i, j, m2[itr2++].value);
				}
			}
		}
	}
	else if (oper == '-'){
		for (int i = 0; i < m1[0].col; i++){
			for (int j = 0; j < m1[0].row; j++){
				if (BOTHCOMPARE){
					setMat(&result, i, j, m1[itr1++].value - m2[itr2++].value);
				}
				else if (M1COMPARE){
					setMat(&result, i, j, m1[itr1++].value);
				}
				else if (M2COMPARE){
					setMat(&result, i, j, -m2[itr2++].value);
				}
			}
		}
	}
	return result;
}

void matPrint(Matrix *m){
	printf("\n%d %d\n", m[0].col, m[0].row);
	int i = 1;
	for (int j = 0; j < m[0].col; j++){
		for (int k = 0; k < m[0].row; k++){
			if (i<m[0].value && m[i].col == j && m[i].row == k){
				printf("%d ", m[i].value);
				i++;
			}
			else{
				printf("0 ");
			}
		}
		printf("\n");
	}

}
void sparsePrint(Matrix *m){
	for(int i = 0; i < m[0].value; i++){
		printf("%d %d %d\n", m[i].col, m[i].row, m[i].value);
	}
}
Matrix* init(){
	Matrix *m;
	int col, row;
	scanf("%d %d", &col, &row);
	m = (Matrix*)malloc(sizeof(Matrix));
	m[0].col = col;
	m[0].row = row;
	m[0].value = 1;
	for (int i = 0; i<col; i++){
		for (int j = 0; j<row; j++){
			int temp;
			scanf("%d", &temp);
			if (temp != 0){
				setMat(&m, i, j, temp);
			}
		}
	}
	return m;
}

int main(){
	char oper;
	scanf("%c", &oper);
	int col1, row1, col2, row2;
	Matrix *mat1, *mat2, *result=0;
	mat1=init();
	mat2=init();

	if ((mat1[0].col ==mat2[0].col && mat1[0].row == mat2[0].row) && (oper == '+' || oper == '-')){
		result = operation(oper, mat1, mat2);
	}
	else if (oper == '*' && mat1[0].row == mat2[0].col){
		result = matMulti(mat1, mat2);
	}
	else{
		printf("Error\n");
		return -1;
	}
	printf("\n ���1�� ������\n");
	sparsePrint(mat1);
	printf("\n ���2�� ������\n");
	sparsePrint(mat2);
	printf("\n ������� ������\n");
	sparsePrint(result);
	matPrint(result);
	return 0;
}

#endif

#if 0

#include <stdio.h>

#include <malloc.h>// malloc�Լ��� �������� �����Դϴ�.

#include <string.h>



#define SIZE 50// SIZE�� ũ��� 50���� �����մϴ�.



typedef struct triple{// ����ü�� �����մϴ�.

	int row;

	int col;

	int value;

} triple;



triple a[SIZE], f_a[SIZE];// a����ü�� f_a�ΰ��� ����ü�� �����մϴ� ���� ��ҵ� ��İ��� �� �ڸ��Դϴ�.



int **num;// �Է¹��� �迭�� ������� ������ �迭�� �����մϴ�.

int **result;



void first_matrix(int row, int col);// �Է¹��� �迭�� ���ȭ ��Ű�� �Լ��Դϴ�.

void change_matrix(int row, int col);// �ι�° �Է��� �ޱ����� ������ ���� ����ü�� �����ϴ� �Լ�

void multi(int e, int f);// �������� ���� �ϴ� �Լ��Դϴ�.

void main()

{



	int row, col, i, j;



	printf("ù��° �迭�� ������ �Է� : ");

	scanf("%d %d", &row, &col);// ù��° �Է��� �޽��ϴ�.



	first_matrix(row, col);// ������ȭ �ϱ� ���� �Լ��Դϴ�.

	change_matrix(row, col);// ���� �����ϱ� ���� ���

	printf("ù��° �������Դϴ�\n");

	for (i = 0; i <= a[0].value; i++) printf("%4d%4d%4d\n", f_a[i].row, f_a[i].col, f_a[i].value); // �������� ����մϴ�.



	printf("�ι�° �迭�� ������ �Է� : ");

	scanf("%d %d", &row, &col);

	first_matrix(row, col);// ������ȭ �ϱ� ���� �Լ�



	printf("�ι�° �������Դϴ�\n");

	for (i = 0; i <= a[0].value; i++) printf("%4d%4d%4d\n", a[i].row, a[i].col, a[i].value);



	result = (int**)malloc((sizeof(int) * f_a[0].row));// ������� ������ �迭�Դϴ�.

	for (i = 0; i<f_a[0].col; i++)// ���� �Է¹��� f_a[0].row ��� a[0].col ����ŭ ũ������

		result[i] = (int*)malloc((sizeof(int) * a[0].col));



	for (i = 0; i<f_a[0].row; i++)

		for (j = 0; j<a[0].col; j++)

			result[i][j] = 0;// ��� ���� ������ �迭�� ��� 0���� �ʱ�ȭ�մϴ�.





	multi(f_a[0].value, a[0].value); // �����ĳ����� ���� ���� �Լ� �Ű������� �� �迭�� ���� ������ �Ѱ��ݴϴ�.

	printf("�̰���¥��!!\n");

	for (i = 0; i<f_a[0].row; i++){

		for (j = 0; j<a[0].col; j++){

			printf("%4d", result[i][j]);// ����� ���

		}

		printf("\n");

	}

}



void first_matrix(int row, int col){// ������ȭ �ϱ� ���� �Լ��Դϴ�.



	int i, j, count = 0;

	int p = 1;

	num = (int**)malloc((sizeof(int) * row));// ����ڰ� �Է��� ��ŭ �迭 ũ�⸦ �����մϴ�.

	for (i = 0; i<row; i++)

		num[i] = (int*)malloc((sizeof(int) * row));



	for (i = 0; i<row; i++){

		printf("%d ���� �Է��ϼ��� : ", i);

		for (j = 0; j<col; j++){

			scanf("%d", &num[i][j]);

		}

	}



	for (i = 0; i<row; i++){

		for (j = 0; j<col; j++){

			if (num[i][j] != 0){// �Է¹��� ����� ���� 0�� �ƴϸ� �װ��� ��� �� �׸��� ����

				a[p].row = i;// a[p].row, col, value�� �־��ݴϴ�.

				a[p].col = j;

				a[p].value = num[i][j];

				p++; // ���⿡�� p�� 1�� �δ� ������ a[0].row�� ���� ����, col�� ���� ����,

				count++; // vaule�� ���� ������ ���� �����Դϴ�.

			}

		}

	}

	a[0].row = row;

	a[0].col = col;// a[0].row�� a[0].col�� ��� ���� ������

	a[0].value = count;// count�� ����ŭ ���� ���� �̹Ƿ� a[0].value�� count�� �־��ݴϴ�.

}



void change_matrix(int row, int col){// ���� �����ϴ� �Լ��Դϴ�.

	int i, j;



	for (i = 0; i <= a[0].value; i++)

		for (j = 0; j<3; j++){

		f_a[i].row = a[i].row;

		f_a[i].col = a[i].col;

		f_a[i].value = a[i].value;// a[]����ü�� ��� ���� f_a����ü�� �����ŵ�ϴ�.

		}

}



void multi(int e, int f){// �������� ���� ���ϴ� �Լ�

	int i, j;

	int x, y, jin, hyun;



	for (i = 1; i <= e; i++){// �Ű������� �� ����� ���� ������ �޽��ϴ�.

		for (j = 1; j <= f; j++){

			if (f_a[i].col == a[j].row){// ���� ù��° ����� ���� �ι�° ����� ���� ���ٸ�

				x = f_a[i].row;// x�� ù��° �Է¹��� ����� �ప��

				y = a[j].col;// y�� �ι�° �Է¹��� ����� ������ ������ �ֽ��ϴ�.

				jin = f_a[i].value;// jin�� ó���Է¹��� �迭�� �ִ� ���� �������ְ�

				hyun = a[j].value; // hyun�� �ι�°�� �Է¹��� �迭�� �ִ� ���� ������ �ֽ��ϴ�.

				result[x][y] += jin * hyun;

				// result�迭�� [x][y]��ġ�� jin�� hyun���� ���Ͽ� ������ �ִ� ����

			}// ��ø���� ��� +�� �����ݴϴ�.^^

		}

	}

}
#endif