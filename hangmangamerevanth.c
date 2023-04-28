#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>


#define CHANCE 6

char words[15][40]={"netflix","amazon","instagram","hyderabad","america","chicken","ganga","bgmi","football","viratkohli","bugatti"};
char wordclue[15][40]={"Ott flatform","shopping site","social media","City","Country","Food Recipe","River","Popular Game","Sport","Cricketer","SuperCar",};
int stinglen(char str[30]){
    int i;
    for( i=0;str[i]!='\0';i++);
    return i;
}




void printBody(int mistakes, char *body) {
	printf("\tMistakes :%d\n", mistakes);
	switch(mistakes) {

		case 6: body[6] = '\\'; break;
		case 5: body[5] = '/'; break;
		case 4: body[4] = '\\'; break;
		case 3: body[3] = '|'; break;
		case 2: body[2] = '/'; break;
		case 1: body[1] = ')', body[0] = '('; break;
		default: break;

	}

	printf("\t _________\n"
	       "\t|         |\n"
	       "\t|        %c %c\n"
	       "\t|        %c%c%c\n"
	       "\t|        %c %c\n"
	       "\t|             \n"
	       "\t|             ", body[0], body[1], body[2],
	       body[3], body[4], body[5], body[6]);
}



int main() {

	printf("\n\t Be aware you can be hanged!!.");

	printf("\n\n\t Rules : ");
	printf("\n\t - Maximum 6 mistakes are allowed.");
	printf("\n\t - All alphabet are in lower case.");
	printf("\n\t - All words are name of very popular Websites. eg. Google");
	printf("\n\t - If you enjoy continue, otherwise close it.");

	printf("\n\t Syntax : Alphabet");
	printf("\n\t Example : a \n");
	int num, i,wordselectindex,wordselectlength;
	char wordselected[40];
	char body[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	bool found;
    time_t t1;
	int win;
	int randomindex;
	char guess;
    srand ( (unsigned) time (&t1));
    randomindex=rand() % 10;
    strcpy(wordselected,words[randomindex]);
    wordselectlength=stinglen(wordselected);
	char *guessed = malloc(wordselectlength );
	char falseWord[CHANCE];
    printf("%s",wordclue[randomindex]);



	int mistakes = 0;
	

	do {

		found = false;
		printf("\n\n");
		printBody(mistakes, body);
		printf("\n\n");
		printf("\t%s\n",wordclue[randomindex]);
		printf("\tFalse Letters : ");
		if(mistakes == 0) printf("None\n");
		for (int i = 0; i < mistakes; ++i)
		{
			printf("%c", falseWord[i]);
		}
		printf("\n\n");
		
		printf("\tGive me a alphabet in lower case : ");
		do {
		    scanf("%c",&guess);
		    
		} while ( getchar() != '\n' );
		for (int i = 0; i <= wordselectlength; i++)
		{
			if(wordselected[i] == guess) {
				found = true;
				guessed[i] = guess;
			}	
		}
		if(!found) {
			falseWord[mistakes] = guess;
			mistakes ++;
		}
		win = strcmp(guessed,wordselected);
		system("cls");
	}while(mistakes < CHANCE && win != 0);

	if(win == 0) {
		printf("\n");
		printf("\t%s\n",guessed);
		printf("\n\tCongrats! You have won : %s\n\n", wordselected);
	} else {
		printf("\n");
		printBody(mistakes, body);
		printf("\n\n\tBetter try next time. Word was %s\n\n", wordselected);
	}
	getch();

	
	return 0;
}
