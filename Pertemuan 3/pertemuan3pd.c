#include <stdio.h>

void alfabet(int i){
	
	
	if(i<'z'){
		alfabet(i+1);
	}
	
	printf("%c", i);
}

int main(){
	alfabet('a');
	
	return 0;
	
}