#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "cJSON/cJSON.h"

char *letters = 0;
long length;
cJSON * lettersJSON;
FILE *letterFile;

void bprintc(char *character){  //bprintc stands for big print charachter

	cJSON *letter = cJSON_GetObjectItemCaseSensitive(lettersJSON,character);
	//char *str = lettersJSON->string;

	if (cJSON_IsArray(letter))
    {
		cJSON *row = letter->child;
		for(int i = 0; i < 4; i++){
			printf("%s\n", row->valuestring);
			row = row->next;
		}
    }else{
		printf("not a string");
	}
}


void bprintsVertical(char *string){  //bprints stands for big print string vertical

    char *stringCopy = string;

	for(int letterIndex = 0; letterIndex < strlen(stringCopy); letterIndex++){
		char character = stringCopy[letterIndex];
        //printf("%c\n", character);

        cJSON *letter = cJSON_CreateObject();

        cJSON_ArrayForEach(letter,lettersJSON){
            if(*letter->string == character){

                //printf("found character %c in lettersJSON\n",*letter->string);
                cJSON *row = letter->child;
    			for(int i = 0; i < 4; i++){
	    			printf("%s\n", row->valuestring);
		    		row = row->next;
			    }
			    printf("\n");
            }
        }
	}
}


void bprints(char *string){  //bprints stands for big print string

    char *stringCopy = string;
    
    for(int j = 0; j < 4; j++){
	    for(int letterIndex = 0; letterIndex < strlen(stringCopy); letterIndex++){
		    char character = stringCopy[letterIndex];
            //printf("%c\n", character);

            cJSON *letter = cJSON_CreateObject();
            bool letterFound = false;

            cJSON_ArrayForEach(letter,lettersJSON){
                if(*letter->string == character){
                    letterFound = true;
                    //printf("found character %c in lettersJSON\n",*letter->string);
                    cJSON *row = letter->child;
    			    for(int i = 0; i < j; i++){
		    		    row = row->next;
			        }
                    printf("%s", row->valuestring);
                }
            }
            if(!letterFound && character != '\n'){
                printf("letter %c not found", character);
            }
	    }
        printf("\n");
    }
}

void printCompressedLetters(cJSON *lettersJSON){
	letters = cJSON_Print(lettersJSON);
    printf("%s",letters);
}

int main(){

	letterFile = fopen("big_letters.json", "rb");
	
	if(letterFile){

		fseek(letterFile, 0, SEEK_END);
		length = ftell(letterFile);
		fseek(letterFile, 0, SEEK_SET);
		letters = malloc(length * sizeof(char));
		if(letters){
			fread(letters, 1, length, letterFile);
		}
		fclose(letterFile);
	}

    lettersJSON = cJSON_CreateObject();
	lettersJSON = cJSON_Parse(letters);

	char *words = malloc(10*sizeof(char));
    fgets(words, 256, stdin);
	printf("you typed: %s", words); //words has a \n character at the end
	bprints(words);
	
    //printCompressedLetters(lettersJSON);

	return 0;
}

