#include <iostream>
#include <fstream>
#include <iomanip>

#include "examination.h"

using namespace std;

void copyDataExamination(examination* from, examination* to) { // Метод перемещения информации между элементами
    to->id = from->id;
	to->name = from->name;
    to->professorId = from->professorId;
}

// Методы добавление и удаления элементов списка
void addPageExamination(examination* start, int position) { // Добавление нового элемента в список

	int i = 0;

	examination* current = start;
	examination* New = new examination;

	while ((i < position - 1) && (current->next != NULL)) {
		current = current->next;
	}

	New->next = current->next;
	New->back = current->back;
	current->next = New;
}

void deletePageExamination(examination* start, int position) { // Удаление определённого элемента в списке
	int i = 0;

	examination* current = start;
	examination* del;

	while ((current->next->next != NULL) && (i < position - 1)) {
		current = current->next;
	}
	del = current->next;
	current->next = del->next;
	delete del;
}
void deleteListExamination(examination* start) { // Удаление списка
	examination* current = start->next;

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
const int professorIdLenght = 12;

const char horizontalLine = '-';
const char verticalLine = '|';
const char corner = '+';
const char space = ' ';

void printConsoleExamination(examination* start) { // Отображение списка в консоли
	examination* current = start;

	cout << setfill(horizontalLine)     << corner
		 << setw(idLenght + 1)          << corner
         << setw(nameLenght + 1)        << corner
		 << setw(professorIdLenght + 1) << corner << endl;

	cout << setfill(space)
		<< verticalLine << setw(idLenght)          << "id"   << right
		<< verticalLine << setw(nameLenght)        << "name" << right
        << verticalLine << setw(professorIdLenght) << "professorId" << right
		<< verticalLine << endl;

	do {
		cout << setfill(horizontalLine)     << corner
			 << setw(idLenght + 1)          << corner
			 << setw(nameLenght + 1)        << corner
		     << setw(professorIdLenght + 1) << corner << endl;

		cout <<setfill(space) 
			 << verticalLine << setw(idLenght)          << current->id          << right
			 << verticalLine << setw(nameLenght)        << current->name        << right
             << verticalLine << setw(professorIdLenght) << current->professorId << right
			 << verticalLine << endl;

		current = current->next;

	} while (current != start);

	cout << setfill(horizontalLine)     << corner
		 << setw(idLenght + 1)          << corner
		 << setw(nameLenght + 1)        << corner
         << setw(professorIdLenght + 1) << corner << endl;
	cout << endl;
}
void fileReadExamination(examination* start, const char* fileName) { // Считывания списка из файла
	int i = 1;
	ifstream ifs(fileName);

	examination* current = start;

	while (!ifs.eof()) {
		current->id = i;
		ifs >> current->name;
        ifs >> current->professorId;

		if (!ifs.eof()) {
			addPageExamination(start, i++);
			current = current->next;
		}
	}
	current->next = start;
	ifs.close();
}
void fileComplementExamination(examination* start, const char* fileName) { // Запись списка в файл
	examination* current = start;
	int i = 1;

	while (current->next != start) {
		current = current->next;
		i++;
	}

	ifstream ifs(fileName);

	while (!ifs.eof()) {
		current->id = i;
		ifs >> current->name;
        ifs >> current->professorId;
		if (!ifs.eof()) {
			addPageExamination(start, i++);
			current = current->next;
		}
	}
	current->next = start;
}

examination* givePageExamination(examination* start, int position) {
	examination* current = start;

	for (int i = 0; i < position; i++) {
		if (current->next == start) {
			break;
		}
		current = current->next;
	}
	return current;
}

void setIdExamination(examination* start, int position, int _id) {
	examination* current = start;
	int i = 0;

	while ((current->next != start) && (i < position)) {
		current = current->next;
	}
	current->id = _id;
}

void setNameExamination(examination* start, int position, string _name) {
	examination* current = start;
	int i = 0;

	while ((current->next != start) && (i < position)) {
		current = current->next;
	}
	current->name = _name;
}

void setProfessorIdExamination(examination* start, int position, string _professorId) {
	examination* current = start;
	int i = 0;

	while ((current->next != start) && (i < position)) {
		current = current->next;
	}
	current->name = _professorId;
}

examination* findIdExamination(examination* start, int key) {

	examination* current = start;
	examination* answer = new examination;
	examination* current_answer = answer;
	bool find = false;

	while (1) {
		if (current->id == key) {
			if (!find) {
				copyDataExamination(current, current_answer);
				find = true;
			}
			else {
				addPageExamination(current_answer, 1);
				current_answer = current_answer->next;
				copyDataExamination(current, current_answer);
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

examination* findNameExamination(examination* start, string key) {

	examination* current = start;
	examination* answer = new examination;
	examination* current_answer = answer;
	bool find = false;

	while (1) {
		if (current->name == key) {
			if (!find) {				
				copyDataExamination(current, current_answer);
				find = true;
			}
			else {
				addPageExamination(current_answer, 1);
				current_answer = current_answer->next;
				copyDataExamination(current, current_answer);
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