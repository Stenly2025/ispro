#ifndef _RMANAGER_H
#define _RMANAGER_H
#include<stddef.h>
#include<stdio.h>
#include"Trains.h"
// typedef struct Train Train;
// struct Train
// {
//     long index;
//     char station[4096];
//     long trainNumber;
//     int countOfCar;
//     char trainType[4096];
//     char destination[4096];
//     struct Train * next;    
// };
    //Считывает ввод с клавиатуры и
    //создаёт новую ячейку списка 
    Train* makeRecord();
    //Добавление нового эелемента
    //в список
    Train* addElement(Train* list, Train* el);
    //Вывод всех элементов
    void showAll(Train* list);
    //Удаляет элемент списка
    Train* deleteElement(Train* list);
    //Изменяет элементы
    Train* changeElement(Train* list);
    //
    int listSize(Train* list);
#endif

