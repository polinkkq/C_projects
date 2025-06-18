//Кулыгина 313ИС

//Максимальная длина строки в файле

#include <stdio.h>
#include <string.h>
int main(){
	FILE * fin = fopen("in.txt", "r");
	int len, max = 0;
	char str[100];
	while(fgets(str, 100, fin) != NULL){
		printf("%s", str);
		len = strlen(str); 
		if (len > max) max = len;
	}
	printf("%d", max);
	fclose(fin);
}
