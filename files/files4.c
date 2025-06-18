//Кулыгина 313ИС

//«Склеить» все строки файла через строку-разделитель

#include <stdio.h>
#include <string.h>
int main(){
	FILE * fin = fopen("in.txt", "r");
	char str[100];
	char new_str[10000] = "";
	char separator[] = ";";
	while(fgets(str, 10000, fin) != NULL){
		str[strcspn(str, "\n")] = '\0'; //убрать \n
		if (new_str[0] != '\0') //если строка не пустая
			strcat(new_str, separator);
		strcat(new_str, str);
	}
	printf("%s", new_str);
	fclose(fin);
}
