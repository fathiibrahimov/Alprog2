#include <stdio.h>

void alfabet(int i, int j){
	printf("%c", i+j);
	
	if(i<'z'){
		alfabet(i+j);
	}
}

int main(){
	int i;
	for(i=25;i>=0;i--){
		alfabet('a', i);
	}
	
	
	
	return 0;
}