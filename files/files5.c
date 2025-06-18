#include <stdio.h>
#include <string.h>
int main(){
	FILE * fin = fopen("in.txt", "r");
	FILE * word = fopen("word.txt", "r");
	
	char str[100];
	char current_word[100];
	
	while(fgets(str, 100, fin) != NULL){
		fscanf(word, "%s", current_word);
		if (strstr(str, current_word)){
			printf("%s", str);
		}
	}
	fclose(fin);
	fclose(word);
}

