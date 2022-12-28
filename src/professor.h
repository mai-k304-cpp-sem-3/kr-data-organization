#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string> // Подключение библиотеки для работы со string

using namespace std;

struct professor { // Структура проеподователя
    int id; // Индекс
    professor* back; // Преведущий элемент списка
    professor* next; // Следующий элемент списка
    string name; // ФИО преподователя
};

void copyDataProfessor(professor* from, professor* to); // Метод перемещения информации между элементами

// Методы добавление и удаления элементов списка
void addPageProfessor(professor* start, int position); // Добавление нового элемента в список
void deletePageProfessor(professor* start, int position); // Удаление определённого элемента в списке
void deleteListProfessor(professor* start); // Удаление списка

// Методы отображение и сохранения списка
void printConsoleProfessor(professor* start); // Отображение списка в консоли
void fileReadProfessor(professor* start, const char* fileName); // Считывания списка из файла
void fileComplementProfessor(professor* start, const char* fileName); // Запись списка в файл

professor* givePageProfessor(professor* start, int position); // Взятие элемента списка

void setIdProfessor(professor* start, int position, int _id);
void setNameProfessor(professor* start, int position, string _name);

professor* findIdProfessor(professor* start, int key);
professor* findNameProfessor(professor* start, string key);

#endif