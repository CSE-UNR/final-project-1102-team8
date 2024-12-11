//Luka Wozniak and Luis Sarellano
//12-5-24
//Make a Madlib
#define MAX_NUM_LINE 100
#define MAX_LINE_LENGTH 300
#define MAX_LETTERS 3
#include<stdio.h>
void choose(char**); //Choose a madlib from the repository
void getInput(char*); //Count verbs, adjectives, and nouns
void countLines(FILE*);
void userint(char, int); //Does the prompting and storing of user inputs
void match(); //matches the inputs to the correct spot in the madlib
void display(); //displays the updated madlib

int main(int argc, char* argv[]){
	
	choose(argv);
		
	return 0;
}

void choose(char *argv1[]){
	
	char* str1 = argv1[1];
	if(str1 != "madlib1.txt" || "madlib2.txt"){
		str1 = "madlib1.txt";
	}
	getInput(str1);
}
void getInput(char *madLibNum){
	
	FILE* fptr;
	fptr = fopen(madLibNum, "r");
	
	if(fptr == NULL){
		printf("File wasnt succesfully connected");
	}
	else{
		countLines(fptr);
	}
	
}
void countLines(FILE* fptr){
	char charNum;
	int i = 0;
	int j = 0;
	char textArray[MAX_NUM_LINE][MAX_LINE_LENGTH];
	while((charNum = fgetc(fptr)) != EOF){
		
		if(charNum == '\n'){
			i++;
			j = 0;
		}
		else{
			textArray[i][j++] = charNum;
		}
	}
	
	match(textArray, i);
}
void match(char textArray[][MAX_LINE_LENGTH], int i){
	
	int count = 0;
	for(int a=0; a<i; a++){
		if(textArray[a][0] == 'A'){
			printf("Please enter an adjective: ");
			scanf("%s", &textArray[a][0]); 
		}else if(textArray[a][0] == 'N'){
			printf("Please enter a noun: ");
			scanf("%s", &textArray[a][0]);
		}else if(textArray[a][0] == 'V'){
			printf("Please enter a verb: ");
			scanf("%s", &textArray[a][0]);
		}
	}
	display(textArray, i);

}
void display(char textArray[][MAX_LINE_LENGTH], int i){
	
	for(int a=0; a<i; a++){
		for(int b=0; b<MAX_LINE_LENGTH; b++){
			printf("%c", textArray[a][b]);
		}
	}
	
}
