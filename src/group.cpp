#include <iostream>
#include <fstream>
#include <iomanip>

#include "group.h"

using namespace std;

void copyDataGroup(group* from, group* to) { // Метод перемещения информации между элементами
    to->id = from->id;
    to->count = from->count;
	to->name = from->name;
}

// Методы добавление и удаления элементов списка
void addPageGroup(group* start, int position) { // Добавление нового элемента в список
	int i = 0;

	group* current = start;
	group* New = new group;

	while ((i < position - 1) && (current->next != NULL)) {
		current = current->next;
	}

	New->next = current->next;
	New->back = current->back;
	current->next = New;
}

void deletePageGroup(group* start, int position) { // Удаление определённого элемента в списке
	int i = 0;

	group* current = start;
	group* del;

	while ((current->next->next != NULL) && (i < position - 1)) {
		current = current->next;
	}
	del = current->next;
	current->next = del->next;
	delete del;
}
void deleteListGroup(group* start) { // Удаление списка
	group* current = start->next;

	while (current != start) {
		current = current->next;
		delete start;
		start = current;
	}
	delete start;
}

// Методы отображение и сохранения списка
const int idLenght = 6;
const int countLenght = 6;
const int nameLenght = 15;

const char horizontalLine = '-';
const char verticalLine = '|';
const char corner = '+';
const char space = ' ';

void printConsoleGroup(group* start) { // Отображение списка в консоли
	group* current = start;

	cout << setfill(horizontalLine) << corner
		 << setw(idLenght + 1)      << corner
         << setw(countLenght + 1)   << corner
         << setw(nameLenght + 1)    << corner << endl;

	cout << setfill(space)
		<< verticalLine << setw(idLenght)      << "id"    << right
        << verticalLine << setw(countLenght)   << "count" << right
		<< verticalLine << setw(nameLenght)    << "name"  << right
		<< verticalLine << endl;

	do {
		cout << setfill(horizontalLine) << corner
			 << setw(idLenght + 1)      << corner
             << setw(countLenght + 1)   << corner
			 << setw(nameLenght + 1)    << corner << endl;

		cout <<setfill(space) 
			 << verticalLine << setw(idLenght)    << current->id    << right
             << verticalLine << setw(countLenght) << current->count << right
			 << verticalLine << setw(nameLenght)  << current->name  << right
			 << verticalLine << endl;

		current = current->next;

	} while (current != start);

	cout << setfill(horizontalLine) << corner
		 << setw(idLenght + 1)      << corner
         << setw(countLenght + 1)   << corner
		 << setw(nameLenght + 1)    << corner << endl;
	cout << endl;
}
void fileReadGroup(group* start, const char* fileName) { // Считывания списка из файла
	int i = 1;
	ifstream ifs(fileName);

	group* current = start;

	while (!ifs.eof()) {
		current->id = i;
		ifs >> current->name;
        ifs >> current->count;

		if (!ifs.eof()) {
			addPageGroup(start, i++);
			current = current->next;
		}
	}
	current->next = start;
	ifs.close();
}
void fileComplementGroup(group* start, const char* fileName) { // Запись списка в файл
	group* current = start;
	int i = 1;

	while (current->next != start) {
		current = current->next;
		i++;
	}

	ifstream ifs(fileName);

	while (!ifs.eof()) {
		current->id = i;
		ifs >> current->name;
        ifs >> current->count;
		if (!ifs.eof()) {
			addPageGroup(start, i++);
			current = current->next;
		}
	}
	current->next = start;
}

group* givePageGroup(group* start, int position) {
	group* current = start;

	for (int i = 0; i < position; i++) {
		if (current->next == start) {
			break;
		}
		current = current->next;
	}
	return current;
}

void setIdGroup(group* start, int position, int _id) {
	group* current = start;
	int i = 0;

	while ((current->next != start) && (i < position)) {
		current = current->next;
	}
	current->id = _id;
}

void setCountGroup(group* start, int position, int _count) {
	group* current = start;
	int i = 0;

	while ((current->next != start) && (i < position)) {
		current = current->next;
	}
	current->count = _count;
}

void setNameGroup(group* start, int position, string _name) {
	group* current = start;
	int i = 0;

	while ((current->next != start) && (i < position)) {
		current = current->next;
	}
	current->name = _name;
}

group* findIdGroup(group* start, int key) {

	group* current = start;
	group* answer = new group;
	group* current_answer = answer;
	bool find = false;

	while (1) {
		if (current->id == key) {
			if (!find) {
				copyDataGroup(current, current_answer);
				find = true;
			}
			else {
				addPageGroup(current_answer, 1);
				current_answer = current_answer->next;
				copyDataGroup(current, current_answer);
			}
		}
		if (current->next != start) {
			current = current->next;
		}
		else {
			break;
		}
	}
	if (find) {
		return answer;
	}
	else {
		delete answer;
		return NULL;
	}
}

group* findCountGroup(group* start, int key) {

	group* current = start;
	group* answer = new group;
	group* current_answer = answer;
	bool find = false;

	while (1) {
		if (current->id == key) {
			if (!find) {
				copyDataGroup(current, current_answer);
				find = true;
			}
			else {
				addPageGroup(current_answer, 1);
				current_answer = current_answer->next;
				copyDataGroup(current, current_answer);
			}
		}
		if (current->next != start) {
			current = current->next;
		}
		else {
			break;
		}
	}
	if (find) {
		return answer;
	}
	else {
		delete answer;
		return NULL;
	}
}

group* findNameGroup(group* start, string key) {

	group* current = start;
	group* answer = new group;
	group* current_answer = answer;
	bool find = false;

	while (1) {
		if (current->name == key) {
			if (!find) {				
				copyDataGroup(current, current_answer);
				find = true;
			}
			else {
				addPageGroup(current_answer, 1);
				current_answer = current_answer->next;
				copyDataGroup(current, current_answer);
			}
		}
		if (current->next != start) {
			current = current->next;
		}
		else {
			break;
		}
	}
	if (find) {
		current_answer->next = answer;
		return answer;
	}
	else {
		delete answer;
		return NULL;
	}
}