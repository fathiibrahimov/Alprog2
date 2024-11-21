#include <stdio.h>

void sequenSearch(int arr[], int n, int cari){
	int i, found;
	found =0;
	i=0;
	
	while((i<n) && (found ==0)){
		if(arr[i]==cari){
			found =1;
		}else{
			i++;
		}
	}
	
	if(found==1){
		printf("Angka %d ditemukan.\n", cari);
	}else{
		printf("Data tidak ditemukan.\n");
	}
}

int main(){
	int n, cari;
	printf("Masukkan jumlah data : ");
	scanf("%d", &n);
	int arr[n];
	
	int i;
	printf("Masukkan data : \n");
	for(i=0;i<n;i++){
		scanf("%d", &cari);
	}
	
	sequenSearch(arr, n, cari);
	
	return 0;
}