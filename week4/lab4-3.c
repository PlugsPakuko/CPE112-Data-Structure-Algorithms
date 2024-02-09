//Pakkawat Kaolim 66070503446
//Lab 4.3 : Tower of Hanoi

#include <stdio.h>

int count = 0;

void TowerOfHanoi(int n, char src, char aux, char dest){
	if (n == 1){
		printf("Move disk 1 from %c to %c\n", src, dest);
		count++;
		return ;
	}
	TowerOfHanoi(n-1,src, dest, aux);
	printf("Move disk %d from %c to %c\n",n , src, dest);
	count++;
	TowerOfHanoi(n-1, aux,src,dest);
}

int main(void){
	int size;
	scanf("%d", &size);
	TowerOfHanoi(size,'A','B','C');
	printf("Total moves: %d\n", count);

	return 0;
}