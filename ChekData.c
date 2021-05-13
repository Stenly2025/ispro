#include<stdbool.h>
#include<stddef.h>
#include<stdio.h>
    //Проверяет размер строки 
    //перед присвоением строке 
    //с ограниченным размером
    // bool chekStringSize(char *str[]){
    //     int i = 0;
    //     while(*str[i]!='\0'&&i<4096)i++;
        
    //     if(i>4096) {
    //         perror("Слишком длинная строка");    
    //         return false;
    //     }
    //     return true;
    // }
    // //Проверяет размер строки числом типа long
    // bool chekLongNumberSize(char *str[]){
    //     int i = 0;
    //     while(*str[i]!='\0'&&i<10){
    //         if(*str[i]<48||*str[i]>58)
    //         {
    //             perror("В строке с номером поезда посторонние символы");
    //             return false;
    //         } 
    //         i++;
    //     }

    //     if(i>10) {
    //         perror("Слишком длиннное число (номер поезда)");
    //         return false;
    //     }

    //     return true;
    // }
    // //Проверяет размер строки числом типа int
    // bool chekIntNumberSize(char *str[]){
    //     int i = 0;
    //     while(*str[i]!='\0'&&i<5){
    //         if(*str[i]<48||*str[i]>58)
    //         {
    //             perror("В строке с количеством вагонов посторонние символы");
    //             return false;
    //         }
    //         i++;
    //     }
        
    //     if(i>5){
    //         perror("Слишком длинное число (количество вагонов)");
    //         return false;
    //     }

    //     return true;
    // }    

