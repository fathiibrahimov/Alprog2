#include <stdio.h>

void tower(int n, char awal, char akhir, char antara){
	if(n==1){
		printf("Pindahkan piringan ke %d dari tonggak %c ke tonggak %c\n", n, awal, akhir);
	}else{
		tower((n-1), awal, antara, akhir);
		//memindahkan piringan berikutnya dari awal ke antara
		printf("pindahkan piringan ke %d dari tonggak %c ke tonggak %c\n", n, awal, akhir);
		tower((n-1), awal, antara, akhir);
		//memindahkan piringan berikutnya dari antara ke akhir
	}
}

int main(){
	tower(3, 'A', 'C', 'B');
	
	return 0;
}