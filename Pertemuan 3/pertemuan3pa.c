#include <stdio.h>

void alfabet(int i){
	printf("%c", i);
	
	if(i<'z'){
		alfabet(i+1);
	}
	
}

int main(){
	alfabet('a');
	
	return 0;
	
}