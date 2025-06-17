//Кулыгина 313ИС

//Каждую строку во входном файле сохранить в выходной файл в
//обратном порядке

#include <stdio.h>
#include <string.h>
void reverse(char *); //функция разворота строки
int main(){
	FILE * fin = fopen("in.txt", "r");
	FILE * fout = fopen("out.txt", "w");
	char str[100];
	while(fgets(str, 100, fin) != NULL){
		reverse(str);
		fprintf(fout, "%s\n", str);
	}
	fclose(fin);
	fclose(fout);
}
void reverse(char * str){
	// Удаляем символ '\n'
	int len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
		len--;
	}
	// Разворачиваем строку
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
