//penggabungan array terurut ascending
void penggabungan_asc(int n, int m, int array1[], int array2[], int *array3){
	int i = 0, j = 0, k = 0, l = 0;
	
	//pengulangan mengisi tabel
	while((i<n) && (j<m)){
		//jika isi array 1 lebih kecil dibandingkan isi array2
		if(array1[i] < array2[j]){
			//masukkan isi array1 ke array3
			array3[k]=array1[i];
			i +=1;
			k +=1;
		//jika isi array2 lebih kecil dibandingkan isi array1
		}else if(array2[j]<array1[i]){
			//masukkan isi array2 ke array3
			array3[k]=array2[i];
			j +=1;
			k +=1;
		//jika besar isi kedua array sama
		}else{
			//masukkan isi array1 ke array3
			array3[k]=array1[i];
			i++;
			k++;
			
			//masukkan isi array 2 ke array3
			array3[k]=array2[i];
			j++;
			k++;
		}
	}
	//jika panjang array tabel1 lebih panjang
	if(i<n){
		//memindahkan sisa
		for(l=i;l<n;l++){
			array3[k]=array1[l];
			k++;
		}
	}
}
