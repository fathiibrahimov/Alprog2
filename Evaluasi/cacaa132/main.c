#include "eval.h"

int main(){
	char pita[300];//string untuk menampung pita
	scanf("%299[^\n]s", &pita);
	banyak=0;
	
	START(pita);//memulai mesin
	cek();
	
	while(EOP()==0){//apabila pita belum habis
		INC(pita);
		cek();
	}
	
	printf("%d\n", GETBANYAK());//sesuai pesanan ya
	return 0;
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Kompetisi Latihan Alpro 2 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/