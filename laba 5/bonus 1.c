#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void ClearScreen();
void rand_num(int *A,int size);
int Num(int j,int num);
void print_mass(int *A,int n);
int    check (int *A,int *B,int size);

int main() {
	
	setlocale(LC_ALL,"rus");
	char ch;
	int num,num2,size,j,menu,tr = 0,flag2 = 1,sus;
	for(;;){
	printf("Виберите режим игри\n");
	printf("1)Два игрока\n");
	printf("2)Человек против компютера\n");
	printf("Ваш вибор :");
	scanf("%d",&menu);
	
	printf("Размер числа (0 < X < 11):");
	scanf("%d",&size);
	if (size > 11 || size < 0) {
			printf("Ну я ж попросив\n");
			continue;
		}
			
		for(;;){
			
		
			int B[size];
			int A[size];
			switch(menu){
			
			
			case 1 : 
				
				printf("Ввдите загадуимоє число :");
				scanf("%d",&num);				
				for(j = 0;j < size;j++){
				A[size - j - 1]= Num(j,num);	
				}
				ClearScreen();
				break;
			
			case 2:
					
				rand_num(A,size);
				break;	
			}
			for(;;){
			
			flag2 = 1;
			printf("Ваш ответ :");
			scanf("%d",&num2);
			for(j = 0;j < size;j++){
				B[size - j - 1]= Num(j,num2);	
			}
			sus = check (A,B,size);
			tr ++;
			if(tr == 10|| tr == 20||tr == 30||tr == 40||tr == 50||tr == 60){
			printf("НЕ получаєтьця да , хочеш окнчить игру y/n :");
			scanf("%s",&ch);
			if(ch == 'y'||tr == 70){
			printf("Спасибо што играл в мою игру");	
			return 0;	
			}
		}
			if ( sus == 1 ){
				tr = 0;	
				printf("Окончить игру y/n :");
				scanf("%s",&ch);
				if(ch == 'y'){
				printf("Спасибо што играл в мою игру");	
				return 0;		
					}
					flag2 = 0;
				break;
				}			
		
				if(flag2 == 0) break;	
		}
		printf("Хотите изменить режим y/n :");
		scanf("%s",&ch);
		if(ch == 'y'){
			break;
		} 
	}
}

}


int Num(int j,int num){
	int first,pr;
	pr  = pow(10,j);
	first = num/pr%10;
	return first;
}

void print_mass(int *A,int n){
	int i;
	for(i =0;i <n;i++){
		printf("%d ",A[i]);
		
	}
	printf("\n");
}


int   check (int *A,int *B,int size){
	int i,j,cow = 0,bull = 0;
	for(i = 0;i < size;i++){
		if(A[i] == B[i]) bull++;
		for(j = 0;j < size;j++){
			if(A[i] == B[j] && A[i] != B[i]) cow ++;
		}
	}
	if(bull == size ) {		
	printf("Ти виграв\n");
	return 1;
	}
	
	else printf("Коров : %d Бикив : %d\n",cow,bull);
	
}

void rand_num(int *A,int size){
	int i,j,flag ;
	srand(time(0));
		for(i = 0;i < size;i ++){	
			A[i] = rand()%10;
			}
	for(;;){
		flag = 0;
		srand(time(0));
		for(i = 0;i < size;i ++){	
			for(j = 0;j < i;j ++){	
				if (A[i] == A[j]) {
				A[i] = rand()%10;	
				flag =1;	
				}
			}	
		}
		if (flag == 0)return;
	}
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

