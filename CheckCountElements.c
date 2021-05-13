#include"Trains.h"
#include <stddef.h>
  //Считает количество элементов
  long countOfElements(Train* list){
    long i = 0;
    while(list!=NULL){
        i++;
        list=list->next;
    } 
    return i;
  }
