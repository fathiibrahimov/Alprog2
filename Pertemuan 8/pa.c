#include <stdio.h>
#include <string.h>

typedef struct{
	char isbn[20];
	char judulBuku[100];
	char authorBuku[50];
}dataBuku;

int main(){
	int i;
	int n=0;
	
	dataBuku perpustakaan[100];
	
	FILE *fdatabuku;
	fdatabuku = fopen("data.dat", "r");
	
	fscanf(fdatabuku, "%s %s %s", perpustakaan[n].isbn, perpustakaan[n].judulBuku, perpustakaan[n].authorBuku);
	
	while(strcmp(perpustakaan[n].isbn, "####") !=0){
		++n;
		fscanf(fdatabuku, "%s %s %s", perpustakaan[n].isbn, perpustakaan[n].judulBuku, perpustakaan[n].authorBuku);
	}
	
	fclose(fdatabuku);
	
	if(n == 0){
		printf("FILE KOSONG!\n");
	}else{
		printf("ISI FILE:\n");
		for(i=0;i<n;i++){
			printf("%s %s %s\n", perpustakaan[i].isbn, perpustakaan[i].judulBuku, perpustakaan[i].authorBuku);
		}
	}
	
	return 0;
}