#ifndef _TRAINS_H
#define _TRAINS_H
///Поля: вокзал, номер поезда, количество вагонов, тип (экспресс/обычный/спутник),
///станция назначения.
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
  //Выделение памяти под нужный тип
  Train* allocate();
  //Перемещает каретку на последний элемент списка
  Train* goToEnd(Train* list);
  //Перемещает каретку на предпоследний элемент списка
  Train* lastButOne(Train* list);
  //Перемещает указатель в позицию n
  Train* goHere(Train* list,long n);
  //Добавляет в конец элемент списка
  Train* add(Train* list, Train *el);
  //Считает количество элементов
  long count(Train* list);
  //Удалет элемент в позиции n из списка list 
  Train*deleteAt(Train* list, long i);
  // //Добавляет элемент в позицию n
  // Train*insertTo(Train* el, Train* list, long i);
  //Создание нового элемента
  Train*createTrain(
                    char station[4096], 
                    long trainNumber,
                    int countOfCar,
                    char trainType[4096],
                    char destination[4096]);
  //Переиндексация
  Train* indexed(Train* list);

#endif