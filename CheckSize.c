#include<stdio.h>

    //Считает длину строки
    int sizeOfString(char number[4096]){
        int i = 0;
        while(number[i]!='\0')i++;                
        return i;
    }
