#include <stdio.h>

int data[8]={3,5,4,2,1,6,7,8};

void qcPinggir(int kiri, int kanan){
	int i, j, temp;
	i=kiri;
	j=kanan;
	
	do{
		while((data[i]<data[kanan])&&(i<=j)){
			i++;
		}
		while((data[j]>data[kiri])&&(i<=j)){
			j--;
		}
		
		if(i<j){
			temp = data[i];
			data[i]=data[j];
			data[j]=temp;
			i++;
			j--;
		}
	}while(i<j);
	
	if(kiri<j){
		qcPinggir(kiri, j);
	}
	if(i<kanan){
		qcPinggir(i, kanan);
	}
}

int main(){
	int i;
	
	printf("Data: ");
	for(i=0;i<8;i++){
		if(i!=7){
			printf("%d ", data[i]);
		}else{
			printf("%d\n", data[i]);
		}
	}
	
	qcPinggir(0,7);
	
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