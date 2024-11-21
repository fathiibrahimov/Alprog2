#include "lif.h"

int main(){
	int i, j;
	scanf("%d", &n);//meminta masukan banyaknya ordo
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf(" %c", &ms1[i][j]);
		}
	}

	scanf("%d", &m);
	for(i = 0; i < m; i++){
		scanf(" %c", &rot[i]);
	}

	cetak();
	
	return 0;
}
