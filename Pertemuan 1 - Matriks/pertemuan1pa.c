#include <stdio.h>
int main(){
	int bar [5][5];
	int i, j;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			bar[i][j]=((i+1)*10)+1+j;
		}
	}
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d ", bar[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}