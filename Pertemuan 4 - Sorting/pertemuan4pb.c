#include <stdio.h>

//prosedur menampilkan array
void printArray(int n, int arr[]){
	int i; //deklarasi
	//perulangan sebanyak n
	for(i=0; i<n;i++){
		//menampilkan array sesuai indeks
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	////deklarasi
	int i, j, temp, minIdx;
	//array
	int array[5]={5,4,6,1,2};
	
	for(i=0;i<(5-1);i++){
		//mencari nilai minimum dari sebuah array
		minIdx=i;
		for(j=i+1;j<5;j++){
		if(array[minIdx]>array[j]){
				minIdx=j;
			}
		}
		//tukar posisi nilai minimum dengan indeks pertama
		temp=array[i];
		array[i]=array[minIdx];
		array[minIdx]=temp;
	}
	printArray(5, array);
	
	
	return 0;
}
//selection sort
