#include "eval.h"

void masuk(){//minta masukan disini
	char tanda;
	int i=0;
	scanf(" %c", &tanda);//buat tau hurufnya apa
	if(tanda=='K'){//kalo k jalanin ini
		scanf("%d", &n);//minta batas kolom
		for(i=0;i<n;i++){//minta kolom
			scanf("%d", &k[i]);
		}
		scanf(" %c", &tanda);//cek huruf
		if(tanda=='B'){
			scanf("%d", &m);//minta batas baris
			for(i=0;i<m;i++){
				scanf("%d", &b[i]);//scanf baris
			}
		}
	}else if(tanda=='B'){//ini sama kaya diatas, cuma dibalik aja, yang baris duluan
		scanf("%d", &m);
		for(i=0;i<m;i++){
			scanf("%d", &b[i]);
		}
		scanf(" %c", &tanda);
		if(tanda=='K'){
			scanf("%d", &n);
			for(i=0;i<n;i++){
				scanf("%d", &k[i]);
			}
		}
	}
	
}

long long faktorial(long long a){//fungsi rekursif faktorialnya
	if(a==0){
		return 1;
	}else{
		return(a*faktorial(a-1));
	}
}

void proses(){//dapetin faktorialnya disini
	int i;
	int j;
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			isimatriks[i][j]=faktorial(k[j])*faktorial(b[i]);
		}
	}
}

void cetak(){//cetak hasil disini
	int i;
	int j;
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%lld\n", isimatriks[i][j]);
		}
	}
}