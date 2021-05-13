#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct Train Train;
  struct Train
  {
    long index;
    char station[4096];
    char trainNumber[4096];
    char countOfCar[4096];
    char trainType[4096];
    char destination[4096];
    struct Train * next;    
  };
//Переиндексация
Train* indexed(Train* list);
//Выделение памяти под нужный тип
  Train* allocate() {
    Train* newEl = (Train * )malloc(sizeof(Train));
    newEl->next = NULL; 
    return newEl;
  }
  //Перемещает каретку на последний элемент списка
  Train* goToEnd(Train* list){
    if(list==NULL) return list;
    if(list->next==NULL) return list;
    while (list->next!=NULL) list = list->next;    
    return list;
  }
  //Перемещает каретку на предпоследний элемент списка
  Train* lastButOne(Train* list){
    if(list==NULL) return list;
    else if(list->next==NULL) return list;
    while (list->next->next!=NULL) list = list->next;
        
    return list;
  }
  //Перемещает указатель в позицию n
  Train* goHere(Train* list,long n){
    while (list->index!=n && list!=NULL) list = list->next;   
    return list;
  }
  //Добавляет в конец элемент списка
  Train* add(Train* list, Train *el){
    if(list == NULL)
    {
      el->index = 0;
      list = el; 
    }else {
      Train* l = lastButOne(list);
      if(l->next==NULL)el->index = l->index+1;
      else el->index = l->next->index+1;           
      if(l->next!=NULL)l = l->next;
      l->next = el;
    }
    return list;
  }
  //Считает количество элементов
  long count(Train* list){
    long i = 0;
    while(list!=NULL){
        i++;
        list=list->next;
    } 
    return i;
  }
  //Удалет элемент в позиции n из списка list 
  Train*deleteAt(Train* list, long i){
    if(i == 0){
      Train*el = list;
      list = list->next;
      free(el);
    }
    else if(i == count(list)-1){        
        Train* el1 = lastButOne(list);
        Train* el2;
        el2 = el1->next;
        free(goToEnd(el2));
        el1->next=NULL;
        }
    else if(i>0 && i<count(list)-1){
      Train*el1 = goHere(list, i-1);
      Train*el2 = el1->next;
      el1->next = el2->next;       
      free(el2);  
    }
    else perror("\nЭлемент n вышел за пределы массива\n");
    list = indexed(list);
    return list;
  }

//   //Добавляет элемент в позицию n
//   Train*insertTo(Train* el, Train* list, long i){
//     Train* el2;
//     if(i<count(list)-1&&i>0){
//       el2 = goHere(list, i-1);
//       Train* el3 = el2->next;
//       el2->next = el;
//       el2->next->next = el3;
//     }
//     else if(i == 0){
//       el->next = list;
//       list = el;    
//     }
//     else if(i==count(list)-1)goToEnd(list)->next = el;
//     else{
//       perror("\nОшибка при добавлении элемента в указанную позицию!\n");
//     }
//     return list;
//   }
  //Создание нового элемента
  Train*createTrain(char station[4096], char trainNumber[4096],char countOfCar[4096],char trainType[4096],char destination[4096])
  {
    Train*tr = allocate();
    strcpy(tr->station,station); 
    strcpy(tr->trainType,trainType); 
    strcpy(tr->destination,destination); 
    strcpy(tr->trainNumber,trainNumber); 
    strcpy(tr->countOfCar, countOfCar); 
    return tr; 
  }
  //Переиндексация
  Train* indexed(Train* list){
    Train* l = list;
    int i = 0;
    while (l!=NULL)
    {
      l->index = i++;
      l=l->next;
    }
    return list;
  }
