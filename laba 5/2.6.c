#include <stdio.h>
#include <stdlib.h>

void scan_mass(int *A,int n);

int main() {
	int N,tmp,i,j;
	printf("Enter N; ");
	scanf("%d",&N);
	int mass[N];
	scan_mass(mass,N);
	for(i =0;i <N;i++){
		if(abs(mass[i]) <= 1){
			printf("%d ",mass[i]);
		}
	}
	for(i =0;i <N;i++){
		if(abs(mass[i]) > 1){
			printf("%d ",mass[i]);
		}
	}
	return 0;
}


void scan_mass(int *A,int n){
	int i;
	for(i =0;i <n;i++){
		printf("a[%d]",i);
		scanf("%d",&A[i]);
	}
}
