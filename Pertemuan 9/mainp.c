#include "mesinkarakterp.h"

int main(){
	char pita[50];//string untuk menampung pita
	printf("masukkan kalimat pada pita\n");
	scanf("%49[^\n]s", &pita);
	
	START(pita);//memulai mesin
	printf("%c\n", GETCC());//mengambil nilai cc
	
	while(EOP()==0){//apabila pita belum habis
		INC(pita);
		printf("%c\n", GETCC());
	}
}