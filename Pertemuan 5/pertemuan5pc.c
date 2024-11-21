#include <stdio.h>

int data[8]={3,5,4,2,1,6,7,8};

void qcTengah(int kiri, int kanan){
	int i, j, temp;
	i=kiri;
	j=kanan;
	int pivot = data[(kanan+kiri)/2];
	do{
		while((data[i]<pivot)&&(i<=j)){
			i++;
		}
		while((data[j]>pivot)&&(i<=j)){
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
	
	if((kiri<j)&&(j<kanan)&&(i!=j)){
		qcTengah(kiri,j);
	}
	if((i<kanan)&&(i>kiri)){
		qcTengah(i, kanan);
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
	
	qcTengah(0,7);
	
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