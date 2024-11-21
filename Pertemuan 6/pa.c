//penggabungan 2 buah array/tabel
void gabung_tidakUrut(int n, int array1[], int m, int array2[], int *array3){
	int i;
	int hitung = 0;
	
	//memasukkan isi array pertama ke dalam array ketiga
	for(i=0;i<n;i++){
		array3[hitung] = array1[i];
		hitung++;
	}
	
	//memasukkan isi array kedua ke dalam array ketiga
	for(i=0;i<m;i++){
		array3[hitung] = array2[i];
		hitung++;
	}
}