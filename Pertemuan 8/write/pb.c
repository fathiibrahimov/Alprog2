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
	fdatabuku = fopen("data.dat", "w");
	
	scanf("%s %s %s", perpustakaan[n].isbn, perpustakaan[n].judulBuku, perpustakaan[n].authorBuku);
	
	while(strcmp(perpustakaan[n].isbn, "####") !=0){
		fprintf(fdatabuku, "%s %s %s\n", perpustakaan[n].isbn, perpustakaan[n].judulBuku, perpustakaan[n].authorBuku);
		++n;
		scanf("%s %s %s", perpustakaan[n].isbn, perpustakaan[n].judulBuku, perpustakaan[n].authorBuku);
	
	}
	
	fprintf(fdatabuku, "#### #### ####");
	
	fclose(fdatabuku);
	
	return 0;
}