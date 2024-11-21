#include "mesinkatap.h"

int main(){
	char pita[300];
	int jkata = 0;
	int jvo3 = 0;
	int jpalindrom = 0;
	printf("TULIS KALIMAT !\n");
	scanf("%299[^\n]s", &pita);
	
	startKata(pita);
	printf("%s\n", getKata());
	while(eopKata(pita) == 0){
		jkata++;
		if(vokal3()==1){
			jvo3++;
		}
		if(palindrom()==0){
			jpalindrom++;
		}
		incKata(pita);
		printf("%s\n", getKata());
	}
	
	if(getPanjang()>0){
		jkata++;
	}
	if(vokal3()==1){
		jvo3++;
	}
	if(palindrom()==0){
		jpalindrom++;
	}
	printf("jum kata : %d\njum vokal min3 : %d\njum palindrom : %d\n", jkata, jvo3, jpalindrom);
	
	return 0;
}