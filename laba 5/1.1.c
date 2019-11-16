#include <stdio.h>
#include <stdlib.h>
void print_mass(int *A,int n);
void scan_mass(int *A,int n);

int main() {
	int n,zero1,zero2,i,res = 1;
	printf("Enter N :");
	scanf("%d",&n);
	int mass[n];
	printf("Enter zero1 :");
	scanf("%d",&zero1);
	printf("Enter zero2 :");
	scanf("%d",&zero2);
	if (zero1 > n || zero2 > n && zero1 < 0 || zero2 < 0) {
		printf("Enter correct data !!");
		return 0;
	}
	scan_mass(mass,n);
	for(i = zero1;i <zero2 - 1;i++){
		res *= mass[i];
	}
	print_mass(mass,n);
	printf("%d",res);

	return 0;
}

void scan_mass(int *A,int n){
	int i;
	for(i =0;i <n;i++){
		printf("a[%d]",i);
		scanf("%d",&A[i]);
	}
}
void print_mass(int *A,int n){
	int i;
	for(i =0;i <n;i++){
		printf("%d ",A[i]);
		
	}
	printf("\n");
}
