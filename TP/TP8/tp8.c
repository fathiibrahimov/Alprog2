#include "tp8.h"

void bacabaca(){
	int n=0;
	
	FILE *fbukabuku;
	//baca yang list buku mentah
	fbukabuku = fopen("ListBukuMentah.dat", "r");
	fscanf(fbukabuku, "%s %s %s %s", jualbuku[n].judul, jualbuku[n].penulis, jualbuku[n].genre, jualbuku[n].toko);
	while(strcmp(jualbuku[n].judul, "####") !=0){
		n++;
		fscanf(fbukabuku, "%s %s %s %s", jualbuku[n].judul, jualbuku[n].penulis, jualbuku[n].genre, jualbuku[n].toko);
	}
	fclose(fbukabuku);
	
	n=0;
	//baca yang toko buku
	fbukabuku = fopen("TokoBuku.dat", "r");
	fscanf(fbukabuku, "%s %s", kobuku[n].judul, kobuku[n].toko);
	while(strcmp(kobuku[n].judul, "####") !=0){
		n++;
		fscanf(fbukabuku, "%s %s", kobuku[n].judul, kobuku[n].toko);
	}
	fclose(fbukabuku);
	
	n=0;
	//baca yang genre
	fbukabuku = fopen("Genre.dat", "r");
	fscanf(fbukabuku, "%s %s", gebuku[n].judul, gebuku[n].genre);
	while(strcmp(gebuku[n].judul, "####") !=0){
		n++;
		fscanf(fbukabuku, "%s %s", gebuku[n].judul, gebuku[n].genre);
	}
	fclose(fbukabuku);
	
	n=0;
	//baca yang penulis
	fbukabuku = fopen("Author.dat", "r");
	fscanf(fbukabuku, "%s %s", pebuku[n].judul, pebuku[n].penulis);
	while(strcmp(pebuku[n].judul, "####") !=0){
		n++;
		fscanf(fbukabuku, "%s %s", pebuku[n].judul, pebuku[n].penulis);
	}
	fclose(fbukabuku);
}

void henshin(){
	int n=0;
	int m=0;
	
	//disini mulai ngubah ngubah aka menggabungkan data
	while(strcmp(jualbuku[n].judul, "####") !=0){
		//cek yang penulis
		while(strcmp(pebuku[m].judul, "####") !=0){
			if(strcmp(jualbuku[n].penulis, pebuku[m].judul)==0){
				strcpy(jualbuku[n].penulis, pebuku[m].penulis);
			}
			m++;
		}
		m=0;
		
		//cek yang genre
		while(strcmp(gebuku[m].judul, "####") !=0){
			if(strcmp(jualbuku[n].genre, gebuku[m].judul)==0){
				strcpy(jualbuku[n].genre, gebuku[m].genre);
			}
			m++;
		}
		m=0;
		
		//cek yang toko
		while(strcmp(kobuku[m].judul, "####") !=0){
			if(strcmp(jualbuku[n].toko, kobuku[m].judul)==0){
				strcpy(jualbuku[n].toko, kobuku[m].toko);
			}
			m++;
		}
		m=0;
		
		n++;
	}
}

void finis(){
	int n=0;
	
	//ini cuma write aka bikin file list buku final doang
	FILE *fbukabuku;
	fbukabuku = fopen("ListBukuFinal.dat", "w");
		
	while(strcmp(jualbuku[n].judul, "####") !=0){
		fprintf(fbukabuku, "%s %s %s %s\n", jualbuku[n].judul, jualbuku[n].penulis, jualbuku[n].genre, jualbuku[n].toko);
		++n;
			
	}
	
	fprintf(fbukabuku, "#### #### #### ####");
	
	fclose(fbukabuku);
}

void bikintabel(){
	int i;
	int n=0;
	int p1=0;
	int p2=0;
	int p3=0;
	int p4=0;
	int p5;
	int beda;
	
	//cari panjang yang terpanjang di tiap baris
	while(strcmp(jualbuku[n].judul, "####") !=0){
		if(strlen(jualbuku[n].judul)>p1){
			p1=strlen(jualbuku[n].judul);
		}
		if(strlen(jualbuku[n].penulis)>p2){
			p2=strlen(jualbuku[n].penulis);
		}
		if(strlen(jualbuku[n].genre)>p3){
			p3=strlen(jualbuku[n].genre);
		}
		if(strlen(jualbuku[n].toko)>p4){
			p4=strlen(jualbuku[n].toko);
		}
		++n;
	}
	
	p5=p1+p2+p3+p4;//cek panjang terpanjang ditambah terpanjang yang lain buat batas tabel
	
	for(i=0;i<p5+13;i++){//print atas tabel
		printf("=");
	}
	
	n=0;
	
	while(strcmp(jualbuku[n].judul, "####") !=0){//print yang bagian bawahnya atas tabel
		printf("\n");
		printf("|");//print yang bagian judul
		if(strlen(jualbuku[n].judul)<p1){
			beda=p1-strlen(jualbuku[n].judul);
			printf(" %s ", jualbuku[n].judul);
			for(i=0;i<beda;i++){
				printf(" ");
			}
		}else{
			printf(" %s ", jualbuku[n].judul);
		}
		
		printf("|");//print yang bagian penulis
		if(strlen(jualbuku[n].penulis)<p2){
			beda=p2-strlen(jualbuku[n].penulis);
			printf(" %s ", jualbuku[n].penulis);
			for(i=0;i<beda;i++){
				printf(" ");
			}
		}else{
			printf(" %s ", jualbuku[n].penulis);
		}
		
		printf("|");//print yang bagian genre
		if(strlen(jualbuku[n].genre)<p3){
			beda=p3-strlen(jualbuku[n].genre);
			printf(" %s ", jualbuku[n].genre);
			for(i=0;i<beda;i++){
				printf(" ");
			}
		}else{
			printf(" %s ", jualbuku[n].genre);
		}
		
		printf("|");//print yang bagian toko buku
		if(strlen(jualbuku[n].toko)<p4){
			beda=p4-strlen(jualbuku[n].toko);
			printf(" %s ", jualbuku[n].toko);
			for(i=0;i<beda;i++){
				printf(" ");
			}
		}else{
			printf(" %s ", jualbuku[n].toko);
		}
		
		printf("|");
		n++;
	}
	
	printf("\n");
	for(i=0;i<p5+13;i++){//print bagian bawah tabel
		printf("=");
	}
	printf("\n");
	
}

void menunyatuan(){
	int pilihan;
	
	printf("==================================\n");
	printf("Yo Whatsapp line messenger gan sis\n");
	printf("Selamat datang di tp8 buatan saya\n");
	printf("==================================\n");
	printf("Pilih mau ngapain gan sis : \n");
	printf("1. Mau nambahin record di Toko Buku mas bro mbak sis??\n");
	printf("2. Mau nambahin record di Genre ?\n");
	printf("3. Mau tambah tambah di bagian Author ??\n");
	printf("4. Mau minus kali minus di bagian List Buku yang belum mateng ??\n");
	printf("5. Mau liat List Buku yang udah mateng nih pasti ?\n");
	printf("6. Mau keluar dari tp buatan saya ?\n");
	printf("*tulis nomornya sesuai menu ya gan\n");
	printf("Silahkan masukkan pilihan karena hidup adalah pilihan : ");
	scanf("%d", &pilihan);
	
	//cuma menu saja disini
	if(pilihan==1){
		tambahrekor(1);
	}else if(pilihan==2){
		tambahrekor(2);
	}else if(pilihan==3){
		tambahrekor(3);
	}else if(pilihan==4){
		tambahrekor(4);
	}else if(pilihan==5){
		semuabutuhproses();
		bikintabel();
		printf("Sekarang silahkan pilih menu yang lain : \n");
		menudua();
	}else if(pilihan==6){
		printf("====================================\n");
		printf("Selamat jalan mas bro gan mbak sis\n");
		printf("====================================\n");
	}else{
		printf("\n\nGak ada pilihannya loh, coba tak muat ulang menunya\n");
		menudua();
	}
}

void semuabutuhproses(){//ini iseng aja karena saya males manggil 3 prosedur secara beruntun
	bacabaca();
	henshin();
	finis();
}

void tambahrekor(int pilahpilih){
	FILE *fdatabuku;
	int n=0;
	int pilihan=0;
	
	if(pilahpilih==1){//nambah record bagian toko buku
		n=0;
		printf("=============================================\n");
		printf("*Input seperti ini : KodeToko NamaToko\n");
		printf("Jika sudah selesai input masukkan #### ####\n");
		printf("Masukkan record untuk toko buku :\n");
		fdatabuku = fopen("TokoBuku.dat", "r");
		fscanf(fdatabuku, "%s %s", kobuku[n].judul, kobuku[n].toko);
	
		while(strcmp(kobuku[n].judul, "####") !=0){
			++n;
			fscanf(fdatabuku, "%s %s", kobuku[n].judul, kobuku[n].toko);
		}

		scanf("%s %s", kobuku[n].judul, kobuku[n].toko);
				
		while(strcmp(kobuku[n].judul, "####") !=0){
			++n;
			scanf("%s %s", kobuku[n].judul, kobuku[n].toko);
		}	
	
		fclose(fdatabuku);
		fdatabuku = fopen("TokoBuku.dat", "w");
		n=0;
		while(strcmp(kobuku[n].judul, "####") !=0){
			fprintf(fdatabuku, "%s %s\n", kobuku[n].judul, kobuku[n].toko);
			++n;
		}
	
		fprintf(fdatabuku, "#### ####");
		fclose(fdatabuku);
		
		
	}else if(pilahpilih==2){//nambah record bagian genre
		n=0;
		printf("=============================================\n");
		printf("*Input seperti ini : KodeGenre NamaGenre\n");
		printf("Jika sudah selesai input masukkan #### ####\n");
		printf("Masukkan record untuk Genre :\n");
		fdatabuku = fopen("Genre.dat", "r");
		fscanf(fdatabuku, "%s %s", gebuku[n].judul, gebuku[n].genre);
	
		while(strcmp(gebuku[n].judul, "####") !=0){
			++n;
			fscanf(fdatabuku, "%s %s", gebuku[n].judul, gebuku[n].genre);
		}
	
		scanf("%s %s", gebuku[n].judul, gebuku[n].genre);
		
		while(strcmp(gebuku[n].judul, "####") !=0){
			++n;
			scanf("%s %s", gebuku[n].judul, gebuku[n].genre);
		}	
	
		fclose(fdatabuku);
		fdatabuku = fopen("Genre.dat", "w");
		n=0;
		while(strcmp(gebuku[n].judul, "####") !=0){
			fprintf(fdatabuku, "%s %s\n", gebuku[n].judul, gebuku[n].genre);
			++n;
		}
	
		fprintf(fdatabuku, "#### ####");
		fclose(fdatabuku);
		
	}else if(pilahpilih==3){//nambah record bagian penulis
		n=0;
		printf("=============================================\n");
		printf("*Input seperti ini : KodePenulis NamaPenulis\n");
		printf("Jika sudah selesai input masukkan #### ####\n");
		printf("Masukkan record untuk Penulis :\n");
		fdatabuku = fopen("Author.dat", "r");
		fscanf(fdatabuku, "%s %s", pebuku[n].judul, pebuku[n].penulis);
	
		while(strcmp(pebuku[n].judul, "####") !=0){
			++n;
			fscanf(fdatabuku, "%s %s", pebuku[n].judul, pebuku[n].penulis);
		}
	
		scanf("%s %s", pebuku[n].judul, pebuku[n].penulis);
		
		while(strcmp(pebuku[n].judul, "####") !=0){
			++n;
			scanf("%s %s", pebuku[n].judul, pebuku[n].penulis);
		}	
	
		fclose(fdatabuku);
		fdatabuku = fopen("Author.dat", "w");
		n=0;
		while(strcmp(pebuku[n].judul, "####") !=0){
			fprintf(fdatabuku, "%s %s\n", pebuku[n].judul, pebuku[n].penulis);
			++n;
		}
	
		fprintf(fdatabuku, "#### ####");
		fclose(fdatabuku);
	}else if(pilahpilih==4){//nambah record bagian list buku mentah
		n=0;
		printf("=============================================\n");
		printf("*Input seperti ini : JudulBuku KodePenulis Genre TokoBuku\n");
		printf("Jika sudah selesai input masukkan #### #### #### ####\n");
		printf("Masukkan record untuk List Buku Mentah :\n");
		fdatabuku = fopen("ListBukuMentah.dat", "r");
		fscanf(fdatabuku, "%s %s %s %s", jualbuku[n].judul, jualbuku[n].penulis, jualbuku[n].genre, jualbuku[n].toko);
	
		while(strcmp(jualbuku[n].judul, "####") !=0){
			++n;
			fscanf(fdatabuku, "%s %s %s %s", jualbuku[n].judul, jualbuku[n].penulis, jualbuku[n].genre, jualbuku[n].toko);
		}
	
		scanf("%s %s %s %s", jualbuku[n].judul, jualbuku[n].penulis, jualbuku[n].genre, jualbuku[n].toko);
		
		while(strcmp(jualbuku[n].judul, "####") !=0){
			++n;
			scanf("%s %s %s %s", jualbuku[n].judul, jualbuku[n].penulis, jualbuku[n].genre, jualbuku[n].toko);
		}	
	
		fclose(fdatabuku);
		fdatabuku = fopen("ListBukuMentah.dat", "w");
		n=0;
		while(strcmp(jualbuku[n].judul, "####") !=0){
			fprintf(fdatabuku, "%s %s %s %s\n", jualbuku[n].judul, jualbuku[n].penulis, jualbuku[n].genre, jualbuku[n].toko);
			++n;
		}
	
		fprintf(fdatabuku, "#### #### #### ####");
		fclose(fdatabuku);
	}
	
	printf("Ada urusan lain lagi ?\n");//ini buat manggil menu atau keluar
		printf("Jawab 1 untuk ya, 2 untuk tidak : ");
		scanf("%d", &pilihan);
		if(pilihan ==1){
			menudua();
		}else if(pilihan==2){
			printf("Selamat jalan mas bro gan mbak sis\n");
		}else{
			printf("Anda salah masukin no, tak panggilkan menu saja\n");
			menudua();
		}
	
}

void menudua(){//ini buat menu yang tidak awal
	int pilihan;
	
	printf("Pilih mau ngapain gan sis : \n");
	printf("1. Mau nambahin record di Toko Buku mas bro mbak sis??\n");
	printf("2. Mau nambahin record di Genre ??\n");
	printf("3. Mau tambah tambah di bagian Author ?\n");
	printf("4. Mau minus kali minus di bagian List Buku yang belum mateng ??\n");
	printf("5. Mau liat List Buku yang udah mateng nih pasti ?\n");
	printf("6. Mau keluar dari tp buatan saya ?\n");
	printf("*tulis nomornya sesuai menu ya gan\n");
	printf("Silahkan masukkan pilihan karena hidup adalah pilihan : ");
	scanf("%d", &pilihan);
	
	if(pilihan==1){
		tambahrekor(1);
	}else if(pilihan==2){
		tambahrekor(2);
	}else if(pilihan==3){
		tambahrekor(3);
	}else if(pilihan==4){
		tambahrekor(4);
	}else if(pilihan==5){
		semuabutuhproses();
		bikintabel();
		printf("Sekarang silahkan pilih menu yang lain : \n");
		menudua();
	}else if(pilihan==6){
		printf("Selamat jalan mas bro gan mbak sis\n");
	}else{
		printf("\n\nGak ada pilihannya loh, coba tak muat ulang menunya\n");
		menudua();
	}
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 8 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/