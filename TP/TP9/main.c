#include "tp9.h"

int main(){
	char pita[50];//string untuk menampung pita
	scanf("%49[^\n]s", &pita);
	
	START(pita);//memulai mesin
	cek();
	
	while(EOP()==0){//apabila pita belum habis
		INC(pita);
		cek();
	}
	
	printf("%d\n", GETBANYAK());//sesuai pesanan ya
	return 0;
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 9 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/