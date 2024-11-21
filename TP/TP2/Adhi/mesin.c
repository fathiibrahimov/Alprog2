#include "header.h"

void masukkan(){

    int i = 0;
    int j = 0;

    scanf ("%d", &a);
    scanf ("%d", &b);

    for (i = 0; i < a; i++){
		for (j = 0; j < b; j++){
			scanf("%s", job[i][j].kerja);
		}
	}

	for (i = 0; i < a; i++){
		for (j = 0; j < b; j++){
			scanf("%s", job[i][j].nama);
		}
	}

	for (i = 0; i < a; i++){
		for (j = 0; j < b; j++){
			scanf("%d", &job[i][j].gaji);
		}
	}

    do{
        scanf("%s", masuktukar[y]);
        y++;
    }while (strcmp(masuktukar[y-1],"oke.") !=0);

}

void pisah(){
    int i = 0;
    int j = 0;
    int k = 0;
    int z = 0;

    char kerjadepan[50][50];
    char kerjabelakang[50][50];
    for (i = 0;i<a;i++){
        for (j=0;j<b;j++)
		kerjadepan[i][j] = '\0';//??
		kerjabelakang[i][j] = '\0';//??
	}

    for (i=0;i<y;i++){
        for (j=0;j<strlen(masuktukar[i]);j++){
            if (masuktukar[i][j] == '-'){//salah 1
                for (k=0;k<j;k++){
                    kerjadepan[i][k] = masuktukar[i][k];
                }
                for (k=j+1;k<strlen(masuktukar[i]);k++){
                    kerjabelakang[i][z] = masuktukar[i][k];
                    z++;
                }
                z = 0;
            }
        }
    }

    for (i=0;i<y;i++){
        printf ("%s\n", kerjadepan[i]);
        printf ("%s\n", kerjabelakang[i]);
    }
    
    int a1,b1;
    int a2,b2;

    for (k=0;k<y;k++){
        for (i=0;i<a;i++){
            for (j=0;j<b;j++){//salah 4
                if (strcmp(kerjadepan[k],job[i][j].kerja)==0){//salah2
                    a1 = i;
                    b1 = j;
					printf("nih :%d %d\n", a1, b1);
                }
                if (strcmp(kerjabelakang[k],job[i][j].kerja)==0){//salah3
                    a2 = i;
                    b2 = j;
					printf("nih :%d %d\n", a2, b2);
                }
            }
        }
    int tampunggaji = job[a1][b1].gaji;
    job[a1][b1].gaji = job[a2][b2].gaji;
    job[a2][b2].gaji = tampunggaji + (0.2*tampunggaji);
	
    char tampungnama[50];
    strcpy(tampungnama,job[a1][b1].nama);
    strcpy(job[a1][b1].nama,job[a2][b2].nama);
    strcpy(job[a2][b2].nama,tampungnama);
	
    }
}

void output(){
    
    int i = 0;
    int j = 0;

    for (i=0;i<a;i++){
        for (j=0;j<b;j++){
            printf ("%s->%s,%d",job[i][j].kerja,job[i][j].nama,job[i][j].gaji);
        if (j<b-1){
            printf (" "); 
        }
    printf ("\n");
        }
    }
}