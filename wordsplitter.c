#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int buffsize = 10;
    int lenRead = 0;
    int loops = 0;
    char* inputString = malloc(buffsize);
    if(inputString == NULL){
        printf("malloc not happy, not enough memory for you :(\n)");
        return 1;
     }

    printf("Enter a sentence:");
    fgets(inputString, buffsize, stdin);
    lenRead += strlen(inputString);


    int Abuff = buffsize;
    if(lenRead == 0){
        printf("what kind of sentance is that buddy\n");
        return 0;
    }
    while(inputString[lenRead - 1] != '\n'){
        loops++;
        Abuff *= 2;
        char* temp = realloc(inputString, Abuff);
        if(inputString == NULL){
            printf("Realloc not happy, not enuf memory en la heap\n");
            return 1;
        }
        inputString = temp;

        fgets(inputString + lenRead, Abuff - lenRead, stdin);
        lenRead +=strlen(inputString + lenRead);

    }
    printf("%d, %s", loops, inputString);
    
    
}   