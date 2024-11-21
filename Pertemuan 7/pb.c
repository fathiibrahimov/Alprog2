#include <stdio.h>

int arr1[10]={12,13,25,34,45,54,55.61,70,83};

int binSearch(int cari){
	int found = 0;
	int i,n,k;
	i=0;
	n=9;
	
	while((i<=n) && (found==0)){
		k=(int)(i+n)/2;
		if(arr1[k]==cari){
			found=1;
		}else{
			if(arr1[k]>cari){
				n=k-1;
			}else{
				i=k+1;
			}
		}
	}
	
	return found;
}

int main(){
	int cari;
	scanf("%d", &cari);
	
	if(binSearch(cari)==1){
		printf("Data ditemukan.\n");
	}else{
		printf("Data tidak ditemukan.\n");
	}
	
	return 0;
}