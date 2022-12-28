#include <iostream>
#include <fstream>
#include <iomanip>

#include "professor.h"

using namespace std;

void copyDataProfessor(professor* from, professor* to) { // Метод перемещения информации между элементами
    to->id = from->id;
	to->name = from->name;
}

// Методы добавление и удаления элементов списка
void addPageProfessor(professor* start, int position) { // Добавление нового элемента в список

	int i = 0;

	professor* current = start;
	professor* New = new professor;

	while ((i < position - 1) && (current->next != NULL)) {
		current = current->next;
	}

	New->next = current->next;
	New->back = current->back;
	current->next = New;
}

void deletePageProfessor(professor* start, int position) { // Удаление определённого элемента в списке
	int i = 0;

	professor* current = start;
	professor* del;

	while ((current->next->next != NULL) && (i < position - 1)) {
		current = current->next;
	}
	del = current->next;
	current->next = del->next;
	delete del;
}
void deleteListProfessor(professor* start) { // Удаление списка
	professor* current = start->next;

	while (current != start) {
		current = current->next;
		delete start;
		start = current;
	}
	delete start;
}

// Методы отображение и сохранения списка
const int idLenght = 6;
const int nameLenght = 15;

const char horizontalLine = '-';
const char verticalLine = '|';
const char corner = '+';
const char space = ' ';

void printConsoleProfessor(professor* start) { // Отображение списка в консоли
	professor* current = start;

	cout << setfill(horizontalLine) << corner
		 << setw(idLenght + 1)      << corner
         << setw(nameLenght + 1)    << corner << endl;

	cout << setfill(space)
		<< verticalLine << setw(idLenght)   << "id"   << right
		<< verticalLine << setw(nameLenght) << "name" << right
		<< verticalLine << endl;

	do {
		cout << setfill(horizontalLine) << corner
			 << setw(idLenght + 1)      << corner
			 << setw(nameLenght + 1)    << corner << endl;

		cout <<setfill(space) 
			 << verticalLine << setw(idLenght)   << current->id   << right
			 << verticalLine << setw(nameLenght) << current->name << right
			 << verticalLine << endl;

		current = current->next;

	} while (current != start);

	cout << setfill(horizontalLine) << corner
		 << setw(idLenght + 1)      << corner
		 << setw(nameLenght + 1)    << corner << endl;
	cout << endl;
}
void fileReadProfessor(professor* start, const char* fileName) { // Считывания списка из файла
	int i = 1;
	ifstream ifs(fileName);

	professor* current = start;

	while (!ifs.eof()) {
		current->id = i;
		ifs >> current->name;

		if (!ifs.eof()) {
			addPageProfessor(start, i++);
			current = current->next;
		}
	}
	current->next = start;
	ifs.close();
}
void fileComplementProfessor(professor* start, const char* fileName) { // Запись списка в файл
	professor* current = start;
	int i = 1;

	while (current->next != start) {
		current = current->next;
		i++;
	}

	ifstream ifs(fileName);

	while (!ifs.eof()) {
		current->id = i;
		ifs >> current->name;
		if (!ifs.eof()) {
			addPageProfessor(start, i++);
			current = current->next;
		}
	}
	current->next = start;
}

professor* givePageProfessor(professor* start, int position) {
	professor* current = start;

	for (int i = 0; i < position; i++) {
		if (current->next == start) {
			break;
		}
		current = current->next;
	}
	return current;
}

void setIdProfessor(professor* start, int position, int _id) {
	professor* current = start;
	int i = 0;

	while ((current->next != start) && (i < position)) {
		current = current->next;
	}
	current->id = _id;
}

void setNameProfessor(professor* start, int position, string _name) {
	professor* current = start;
	int i = 0;

	while ((current->next != start) && (i < position)) {
		current = current->next;
	}
	current->name = _name;
}

professor* findIdProfessor(professor* start, int key) {

	professor* current = start;
	professor* answer = new professor;
	professor* current_answer = answer;
	bool find = false;

	while (1) {
		if (current->id == key) {
			if (!find) {
				copyDataProfessor(current, current_answer);
				find = true;
			}
			else {
				addPageProfessor(current_answer, 1);
				current_answer = current_answer->next;
				copyDataProfessor(current, current_answer);
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

professor* findNameProfessor(professor* start, string key) {

	professor* current = start;
	professor* answer = new professor;
	professor* current_answer = answer;
	bool find = false;

	while (1) {
		if (current->name == key) {
			if (!find) {				
				copyDataProfessor(current, current_answer);
				find = true;
			}
			else {
				addPageProfessor(current_answer, 1);
				current_answer = current_answer->next;
				copyDataProfessor(current, current_answer);
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