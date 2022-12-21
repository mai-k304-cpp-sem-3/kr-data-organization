#ifndef EXAMINATION_H
#define EXAMINATION_H

#include <string> // Подключение библиотеки для работы со string

using namespace std;

struct examination { // Структура экзамена
    int id; // Индекс
    examination* back; // Преведущий элемент списка
    examination* next; // Следующий элемент списка
    string name; // Название предмета
    int professorId; // Преподователь
};

void copyDataExamination(examination* from, examination* to); // Метод перемещения информации между элементами

// Методы добавление и удаления элементов списка
void addPageExamination(examination* start, int position); // Добавление нового элемента в список
void deletePageExamination(examination* start, int position); // Удаление определённого элемента в списке
void deleteListExamination(examination* start); // Удаление списка

// Методы отображение и сохранения списка
void printConsoleExamination(examination* start); // Отображение списка в консоли
void fileReadExamination(examination* start, const char* fileName); // Считывания списка из файла
void fileComplementExamination(examination* start, const char* fileName); // Запись списка в файл

examination* givePageExamination(examination* start, int position); // Взятие элемента списка

void setIdExamination(examination* start, int position, int _id);
void setNameExamination(examination* start, int position, string _name);
void setProfessorIdExamination(examination* start, int position, string _professorId);

examination* findIdExamination(examination* start, int key);
examination* findNameExamination(examination* start, string key);

#endif