#ifndef GROUP_H
#define GROUP_H

#include <string> // Подключение библиотеки для работы со string

using namespace std;

struct group { // Структура группы
    int id; // Индекс
    group* back; // Преведущий элемент списка
    group* next; // Следующий элемент списка
    int count; // Кол-во учеников в группе
    string name; // Название группы
};

void copyDataGroup(group* from, group* to); // Метод перемещения информации между элементами

// Методы добавление и удаления элементов списка
void addPageGroup(group* start, int position); // Добавление нового элемента в список
void deletePageGroup(group* start, int position); // Удаление определённого элемента в списке
void deleteListGroup(group* start); // Удаление списка

// Методы отображение и сохранения списка
void printConsoleGroup(group* start); // Отображение списка в консоли
void fileReadGroup(group* start, const char* fileName); // Считывания списка из файла
void fileComplementGroup(group* start, const char* fileName); // Запись списка в файл

group* givePageGroup(group* start, int position); // Взятие элемента списка

void setIdGroup(group* start, int position, int _id);
void setCountGroup(group* start, int position, int _count);
void setNameGroup(group* start, int position, string _name);

group* findIdGroup(group* start, int key);
group* findCountGroup(group* start, int key);
group* findNameGroup(group* start, string key);

#endif