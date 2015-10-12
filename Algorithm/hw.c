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
	printf("\n 행렬1의 희소행렬\n");
	sparsePrint(mat1);
	printf("\n 행렬2의 희소행렬\n");
	sparsePrint(mat2);
	printf("\n 계산결과의 희소행렬\n");
	sparsePrint(result);
	matPrint(result);
	return 0;
}

#endif

#if 0

#include <stdio.h>

#include <malloc.h>// malloc함수를 쓰기위한 선언문입니다.

#include <string.h>



#define SIZE 50// SIZE의 크기는 50으로 정의합니다.



typedef struct triple{// 구조체를 선언합니다.

	int row;

	int col;

	int value;

} triple;



triple a[SIZE], f_a[SIZE];// a구조체와 f_a두개의 구조체를 선언합니다 각각 희소된 행렬값이 들어갈 자리입니다.



int **num;// 입력받을 배열과 결과값을 저장할 배열을 선언합니다.

int **result;



void first_matrix(int row, int col);// 입력받은 배열을 희소화 시키는 함수입니다.

void change_matrix(int row, int col);// 두번째 입력을 받기위해 그전에 받은 구조체를 복사하는 함수

void multi(int e, int f);// 희소행렬의 곱을 하는 함수입니다.

void main()

{



	int row, col, i, j;



	printf("첫번째 배열의 갯수를 입력 : ");

	scanf("%d %d", &row, &col);// 첫번째 입력을 받습니다.



	first_matrix(row, col);// 희소행렬화 하기 위한 함수입니다.

	change_matrix(row, col);// 값을 복사하기 위한 행렬

	printf("첫번째 희소행렬입니다\n");

	for (i = 0; i <= a[0].value; i++) printf("%4d%4d%4d\n", f_a[i].row, f_a[i].col, f_a[i].value); // 희소행렬을 출력합니다.



	printf("두번째 배열의 갯수를 입력 : ");

	scanf("%d %d", &row, &col);

	first_matrix(row, col);// 희소행렬화 하기 위한 함수



	printf("두번째 희소행렬입니다\n");

	for (i = 0; i <= a[0].value; i++) printf("%4d%4d%4d\n", a[i].row, a[i].col, a[i].value);



	result = (int**)malloc((sizeof(int) * f_a[0].row));// 결과값을 저장할 배열입니다.

	for (i = 0; i<f_a[0].col; i++)// 전에 입력받은 f_a[0].row 행과 a[0].col 열만큼 크기조절

		result[i] = (int*)malloc((sizeof(int) * a[0].col));



	for (i = 0; i<f_a[0].row; i++)

		for (j = 0; j<a[0].col; j++)

			result[i][j] = 0;// 결과 값을 저장할 배열을 모두 0으로 초기화합니다.





	multi(f_a[0].value, a[0].value); // 희소행렬끼리의 곱을 위한 함수 매개변수로 각 배열의 값의 갯수를 넘겨줍니다.

	printf("이게진짜여!!\n");

	for (i = 0; i<f_a[0].row; i++){

		for (j = 0; j<a[0].col; j++){

			printf("%4d", result[i][j]);// 결과값 출력

		}

		printf("\n");

	}

}



void first_matrix(int row, int col){// 희소행렬화 하기 위한 함수입니다.



	int i, j, count = 0;

	int p = 1;

	num = (int**)malloc((sizeof(int) * row));// 사용자가 입력한 만큼 배열 크기를 지정합니다.

	for (i = 0; i<row; i++)

		num[i] = (int*)malloc((sizeof(int) * row));



	for (i = 0; i<row; i++){

		printf("%d 행을 입력하세요 : ", i);

		for (j = 0; j<col; j++){

			scanf("%d", &num[i][j]);

		}

	}



	for (i = 0; i<row; i++){

		for (j = 0; j<col; j++){

			if (num[i][j] != 0){// 입력받은 행렬의 값이 0이 아니면 그값의 행과 열 그리고 값을

				a[p].row = i;// a[p].row, col, value에 넣어줍니다.

				a[p].col = j;

				a[p].value = num[i][j];

				p++; // 여기에서 p를 1로 두는 이유는 a[0].row은 행의 갯수, col은 열의 갯수,

				count++; // vaule는 값의 갯수가 들어가기 때문입니다.

			}

		}

	}

	a[0].row = row;

	a[0].col = col;// a[0].row와 a[0].col의 행과 열의 갯수를

	a[0].value = count;// count한 수만큼 값의 갯수 이므로 a[0].value에 count를 넣어줍니다.

}



void change_matrix(int row, int col){// 값을 복사하는 함수입니다.

	int i, j;



	for (i = 0; i <= a[0].value; i++)

		for (j = 0; j<3; j++){

		f_a[i].row = a[i].row;

		f_a[i].col = a[i].col;

		f_a[i].value = a[i].value;// a[]구조체의 모든 값을 f_a구조체로 복사시킵니다.

		}

}



void multi(int e, int f){// 희소행렬의 곱을 구하는 함수

	int i, j;

	int x, y, jin, hyun;



	for (i = 1; i <= e; i++){// 매개변수로 두 행렬의 값의 갯수를 받습니다.

		for (j = 1; j <= f; j++){

			if (f_a[i].col == a[j].row){// 만약 첫번째 행렬의 열과 두번째 행렬의 행이 같다면

				x = f_a[i].row;// x는 첫번째 입력받은 행렬의 행값을

				y = a[j].col;// y는 두번째 입력받은 행렬의 열값을 가지고 있습니다.

				jin = f_a[i].value;// jin은 처음입력받은 배열에 있는 값을 가지고있고

				hyun = a[j].value; // hyun은 두번째로 입력받은 배열에 있는 값을 가지고 있습니다.

				result[x][y] += jin * hyun;

				// result배열의 [x][y]위치에 jin과 hyun값을 곱하여 그전에 있던 값과

			}// 중첩으로 계속 +를 시켜줍니다.^^

		}

	}

}
#endif