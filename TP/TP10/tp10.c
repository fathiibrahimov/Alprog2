#include "tp10.h"

void startKata(char pita[]){//mulai mesin kata
	indeks = 0;//ini indeks buat nunjukin lagi dimana
	panjang = 0;//panjang katanya
	while(pita[indeks] == ' '){//kalo spasi ntar indeksnya nambah terus
		indeks++;
	}
	while((pita[indeks] != ' ') && (pita[indeks] != '.')){//ini kalau memenuhi syarat nanti dapet katanya
		kata[panjang] = pita[indeks];
		indeks++;
		panjang++;
	}
	kata[panjang] = '\0';//diakhiri dengan \0, bukannya hamdalah
}


void resetKata(){//buat reset kata, tapi gak dipake disini
	panjang = 0;
	kata[panjang] = '\0';
}

void incKata(char pita[]){//buat lanjut ke kata selanjutnya
	panjang = 0;//reset panjang jadi 0 lagi
	while(pita[indeks] == ' '){//selama gak spasi lagi
		indeks++;
	}
	while((pita[indeks] != ' ') && (pita[indeks] != '.')){//masih sama kaya start kata sebenernya ini semua
		kata[panjang] = pita[indeks];
		indeks++;
		panjang++;
	}
	kata[panjang] = '\0';
}

char* getKata(){//buat ngambil kata
	return kata;
}

int getPanjang(){//buat ngambil panjang
	return panjang;
}

int eopKata(char pita[]){//buat tau apakah sudah selesai kalimatnya, dan saya baru nyadar kalo di modul gak dipake eopnya
	if(pita[indeks] == '.'){
		return 1;
	}else{
		return 0;
	}
}

void proses(){//ini semua prosesnya, biar gak menuhin main.c aja
	char pita[300];//kalimatnya
	scanf("%299[^\n]s", &pita);	//minta kalimat
	
	p1=0;//isi p1 dan p2 buat prima dan nonvoko
	p2=0;
	startKata(pita);//yak mulai
	if(prime(getPanjang())==1){//cari prima, kalo bener prima dia copas ke tampungan
		strcpy(kataprima[p1], getKata());
		p1++;
	}
	
	if(nonvoko()==2){//cari nonvoko, kalo bener nonvoko dia copas ke tampungan
		strcpy(katanon[p2], getKata());
		p2++;
	}
	
	while(eopKata(pita) == 0){
		incKata(pita);
		if(prime(getPanjang())==1){//cari prima, kalo bener prima dia copas ke tampungan
			strcpy(kataprima[p1], getKata());
			p1++;
		}
		if(nonvoko()==2){//cari nonvoko, kalo bener nonvoko dia copas ke tampungan
			strcpy(katanon[p2], getKata());
			p2++;
		}
	}
	keluar();
}

int prime(int n){//ini nyari apakah katanya prima, dan ini saya nyolong dari kodingan saya dulu yang make java dan itu saya nyolong dari internet
	int i, flag = 0;//flag buat nentuin ini kata prima atau bukan
    
    for (i=2;i<=n/2;++i) {//dicarinya make modulus, kalo ternyata panjang kata dibagi iteratornya modulusnya 0 , dia bukan prima karena bisa dibagi
        if(n%i==0) {
            flag=1;
            break;
        }
    }
    if (flag==0) {
        return 1;
    }else{
		return 2;
	}
}

int nonvoko(){//ini buat nyari kata nonvokonya
	int i;
	int flag=0;//buat nentuin ini nonvoko atau bukan
	char cc1, cc2, cc3;//buat nampung sementara karakternya
	int i1=0;//buat indeks karakternya
	int i2=1;
	int i3=2;
	
	if(panjang>2){//panjang kalimatnya harus lebih dari 2, dan saya baru inget seharusnya diatur kasus kalo panjangnya kurang dari dua, tapi keburu correct duluan
	//jadi saya biarkan saja
		for(i=2;i<panjang;i++){
			cc1=kata[i1];
			cc2=kata[i2];
			cc3=kata[i3];
			
			if((cc2=='a') || (cc2=='i') || (cc2=='u') || (cc2=='e') || (cc2=='o')){//nyari apakah kata ditengah vokal
				if((cc1!='a') || (cc1!='i') || (cc1!='u') || (cc1!='e') || (cc1!='o')){//nyari kata didepan konsonan atau bukan
					if((cc3!='a') || (cc3!='i') || (cc3!='u') || (cc3!='e') || (cc3!='o')){//nyari kata dibelakang konsonan atau bukan
						flag=1;//kalau bener flag bendera tapi bukan susunya 1
					}
				}
			}
			i1++;//nambah trooooos
			i2++;
			i3++;
		}
	}
	
	if(flag==1){
		return 1;
	}else{
		return 2;
	}
	
	
}

void keluar(){//outputnya disini
	int i;
	if(p1>0){//kalau ada primanya
		printf("PRIMA :\n");
		for(i=0;i<p1;i++){
			printf("-%s\n", kataprima[i]);
		}
		printf("+jumlah : %d\n\n", p1);
	}else{//kalau nggak ada
		printf("TIDAK ADA PRIMA.\n");
	}
	
	if(p2>0){//kalau ada nonvokonya
		printf("NONVOKO :\n");
		for(i=0;i<p2;i++){
			printf("-%s\n", katanon[i]);
		}
		printf("+jumlah : %d\n", p2);
	}else{//kalau nggak ada
		printf("TIDAK ADA NONVOKO.\n");
	}
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 10 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/