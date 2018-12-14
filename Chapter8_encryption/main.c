//
//  main.c
//  Chapter8_encryption
//
//  Created by Nicholas Morris on 14/12/18.
//  Copyright © 2018 Nicholas Morris. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>

#define N 100
int main(int argc, const char * argv[]) {
    
    int i = 0;
    int length = 0;
    int ch;
    int shift;
    int array[N] = {' '};
    
    //Prompt user to enter message to be encrypted
    printf("Enter message to be encrypted: ");
    while ((ch = getchar()) != '\n' && ch != EOF) {
        array[i] = ch;
        i++;
        length++;
      
    }
    //Prompt user for shift amount
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);
    //Shift the elements and give them values corresponding to 1-26 to A-Z
    for(i = 0; i < N; i++){
        if(array[i] >= 'A' && array[i] <= 'Z'){
            array[i] = (unsigned int)((array[i] - 'A') + shift)%26;
        }
        else if (array[i] >= 'a' && array[i] <= 'z'){
            array[i] = (unsigned int)(abs(((array[i] - 'a') + shift)%26))-26;
        }
        
    }
    //Conversions
    for(i = 0; i < N; i++){
        if(array[i] >= 0 && array[i] < 26){
            array[i] = array[i] + 'A';
        }
        else if (array[i] >= -26 && array[i] < 0){
            array[i] = array[i] + 'a'+26;
        }
        
    }
    
    
    //Print the array
    for(i = 0; i < length; i++){
        printf("%c", array[i]);
    }
    puts("\n");
    
    
}
