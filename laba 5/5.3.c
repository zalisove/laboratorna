#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <locale.h>
#include <windows.h>

void ClearScreen();
int count(float *A,int n,float k);
void sort(float *A,int N);
void print_mass(float *A,int n);
void scan_mass(float *A,int n);

int main() {
	setlocale(LC_ALL,"rus");
	int i,n ,num,menu,hz,flag = 0,flag2 =0;
	float k;
	for(;;){
	
		printf("1)Создать масив\n");
		printf("2)удалить елемент со значенєм К\n");
		printf("3)Удалить масив\n");
		printf("4)Вивесть масив\n");
		printf("5)Очистить консоль\n");
		printf("6)Вийти з програми\n");
		
		printf("Ваш вибор:");
		scanf("%d",&menu);
		printf("\n");
		
		switch(menu){
			case 1:
				
				printf("Введите размер масива:");
				scanf("%d",&n);
				hz = n;
				float *A = (float*) malloc(n*sizeof(float));
				scan_mass(A,n);	
				flag2 = 1;
				break;
	
			case 2:
			if (flag2 == 0){
				printf("Может ти сначала масив создаси, не протаке не задумувався?\n ");
				break;
			}
				printf("Введите число ктороє хотите удалить :");
				scanf("%f",&k);				
				num = count(A,hz,k);
				sort(A,n);
				hz -=num;
				float *B = (float*) malloc((hz)*sizeof(float));
				for(i = 0;i <hz;i++){
					B[i]=A[i];
				}
				flag = 1;
			break;
			case 3:
				flag2= 0;
				free(A);
				break;
			case 4:
				
			if (flag2 == 0){
				printf("Уважаємий пользователь шо ти собрався виводить, в тебеж ничого ще нема.\n");
				break;
				}
			 if(flag == 1){
				print_mass(B,hz);
				for(i = 0;i <hz;i++){
					A[i]=B[i];
				}
				free(B);
				flag = 0;
				}
			else print_mass(A,hz);
				break;
		
			case 5:
				
				ClearScreen();
				break;
			case 6:
				printf("Пока пользовотель ; ) \n\n");
				system("pause");
				return 0;
				break;
			
		
			
		}
	}
}
void sort(float *A,int N){
	int i,j;
	float k = 0.1;
	for(i = 0;i<N-1;i++){
		for(j = 0;j < N-1-i;j++){
			if(A[j] == k ){
				float tmp =A[j];
				A[j] = A[j+1];
				A[j+1] = tmp;
			}
		}
	}
}

void scan_mass(float *A,int n){
	int i;
	for(i =0;i <n;i++){
		printf("a[%d]",i);
		scanf("%f",&A[i]);
	}
}
void print_mass(float *A,int n){
	int i;
	for(i =0;i <n;i++){
		printf("%.0f ",A[i]);
		
	}
	printf("\n");
}

int count(float *A,int n,float k){
	int i,count  = 0;
	float l = 0.1;
	for(i =0;i < n;i++){
		if (A[i]== k){
		A[i] = l;
		count ++;
		} 
	}
	return count;
}
void ClearScreen()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }

