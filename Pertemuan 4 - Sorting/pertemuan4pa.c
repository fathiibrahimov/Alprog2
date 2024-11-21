#include <stdio.h>

//prosedur menampilkan array
void printArray(int n, int arr[]){
	int i; //deklarasi
	//perulangan sebanyak n
	for(i=0; i<n;i++){
		//menampilkan array sesuai indeks
		printf("%d", arr[i]);
	}
	printf("\n");
}

int main(){
	////deklarasi
	int i,j,key;
	//array
	int array[5]={5,4,6,1,2};
	//perulangan sebanyak isi array dimulai dari indeks ke 1
	for(i=1;i<5;i++){
		//menjadikan array ke i sebagai kunci (data sisip)
		key = array[i];
		j=i-1;
		/*
		perulangan selama j nya >= 0
		(karena minimal indeks array adalah 0)
		&selama array indeks j lebih besar dari Key
		*/
		while(j>=0 &&key < array [j]){
			//tukar posisi
			array[j+1]=array[j];
			//j mundur 1
			j=j-1;
		}
		//menempatkan kunci pada array
		array[j+1]=key;
	}
	printArray(5, array);
	return 0;
}

//insertion sort