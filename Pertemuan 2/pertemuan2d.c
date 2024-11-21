#include <stdio.h>
#include <time.h>

void wait(float x){
	//this is the procedure for making delay
	time_t start; //start time
	time_t current; //current time
	time(&start); //making the start time
	do
		time(&current); //making the current time
	//doing the checking while the differet time under and
	//meet the ending if the different time is x
	while (difftime(current, start) < x);
}

int main(){
	//make the matrix
	char arr[6][6];
	
	//making variables
	//i and j as the counters
	//x and y as the coordinates in the matrix
	//jalan as marking variable, whether the direction up or down
	int i, j, x=-1, y=-1, jalan=1;
	
	//inisialize the matrix
	//filled with -
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			arr[i][j]='-';
		}
	}
	
	//looping forever
	while(1){
		//clear the screen
		system("cls");
		
		//setting back the cell which is filled with B before
		if(x>=0&&(x<6)){
			arr[x][y]='-';
		}
		
		//the drawing constraints for the coordinate
		if((x==6)&&(y==6)){
			//bottom border as the mark of going up
			jalan=-1;
			x=x-1;
			y=y-1;
		}else if((x==-1)&&(y==-1)){
			//upper border as the mark of going up
			jalan=1;
			x=x+1;
			y=y+1;
		}else if(jalan==1){
			//if the direction is still going down
			x=x+1;
			y=y+1;
		}else{
			//if the direction is still going up
			x=x-1;
			y=y-1;
		}
		
		//fill the cell with B
		if((x>=0)&&(x<6)){
			arr[x][y]='B';
		}
		
		//draw to the screen
		for(i=0;i<6;i++){
			for(j=0;j<6;j++){
				if(arr[i][j]=='-'){
					printf("   ");
				}else{
					printf(" %c ", arr[i][j]);
				}
			}
			printf("\n");
		}
		//the delay procedure for 1 seconde
		wait(1);
		
	}
	return 0;
}