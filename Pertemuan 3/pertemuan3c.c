#include <stdio.h>

int sum(int n){
	printf("n = %d\n", n);
	//jika 0 ????
	
	if(n>0){
		if(n==1){
			return 1;
		}else{
			return (n+sum(n-1));
		}
	}else{
		if(n==0){
			return 0;
		}else{
			return (n+sum(n+1));
		}
	}
}

int main(){
	int tes;
	printf("masukan angka: ");
	scanf("%d", &tes);
	
	int hasil = sum(tes);
	printf("hasil sum: %d\n", hasil);
	return 0;
}