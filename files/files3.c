//Кулыгина 313ИС

//Подсчитать количество слов в файле

#include <stdio.h>
#include <string.h>
int word_count(char *); //функция подсчёта слов в строке
int main(){
	FILE * fin = fopen("in.txt", "r");
	char str[100];
	int words = 0;
	while(fgets(str, 100, fin) != NULL){
		words+= word_count(str);
	}
	printf("%d", words);
	fclose(fin);
}
int word_count(char *str){
	int count = 0;
	int in_word = 0; // флаг "не в слове"
	for (int i = 0;str[i] != '\0' && str[i] != '\n'; ++i){
		if (str[i] == ' '){
			in_word = 0;
		}
		else if (!in_word){
			++count;
			in_word = 1; //переключаемся на флаг "в слове"
		}
	}
	return count;
}
