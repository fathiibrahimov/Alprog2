#include <stdio.h>

int main(){
	int data[8]={3,5,4,2,1,6,7,8};
	
	int i, temp, pindah;//variabel yang akan digunakan dalam sorting
	printf("Data: ");
	for(i=0;i<8;i++){//mencetak data sebelum di sorting
		if(i!=7){
			printf("%d ", data[i]);
		}else{
			printf("%d\n", data[i]);
		}
	}
	
	do{//perulangan untuk mengecek setiap anggota data
		pindah = 0;
		
		for(i=0;i<(8-1);i++){
			/*perulangan untuk mengecek data yang dipilih terhadap data yang
			*/
			if(data[i]>data[i+1]){//proses membandingkan data
				//proses pemindahan data
				temp = data[i];
				data[i]=data[i+1];
				data[i+1]=temp;
				pindah =1;
			}
			
		}
	}while(pindah==1);
	
	printf("Hasil Sorting: ");
	for(i=0;i<8;i++){
		if(i!=7){
			printf("%d ", data[i]);
		}else{
			printf("%d\n", data[i]);
		}
	}
	
	return 0;
}