#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

struct List {
	List* next = NULL;
	List* back = NULL;

	int number = NULL;
	float price = NULL;

	string name;
	string surname;
	string phoneNumber;

	string type;
	string productionTime;

	string priceOfAccessories;
	string supplier;
	string deliveryTime;

};

/***********************************
*  ������ ����������� �� ��������  *
***********************************/

void addPage(List* start, int num);


void deletePage(List* start);
void deleteList(List* start);

/**************************
*   ������ �����-������	  *
**************************/

void printConsole(List* start);
void fileReadList(List* start, const char* f_name);
void fileComplementList(List* start, const char* f_name);

/*********************************************************
*   ������� ����������� � ���������� ������� ��������    *
*********************************************************/

List* givePage(List* start, int position);

void setNumber(List* start, int position, int number);
void setPrice(List* start, int position, float newPrice);

void setName(List* start, int position, string newName);
void setSurname(List* start, int position, string newSurname);
void setPhoneNumber(List* start, int position, string phoneNumber);

void setType(List* start, int number, string newType);
void setProductionTime(List* start, int position, string newData);

void setPriceOfAccessories(List* start, int position, string newData);
void setSupplier(List* start, int position, string newData);
void setDeliveryTime(List* start, int position, string newData);

	/*******************
	*  ������� ������  *
	*******************/

List* findNumber(List* start, int key);
List* findPrice(List* start, float key);
List* findName(List* start, string key);
List* findSurname(List* start, string key);
List* findPhoneNumber(List* start, string key);
List* findType(List* start, string key);
List* findProductionTime(List* start, string key);
List* findPriceOfAccessories(List* start, string key);
List* findSupplier(List* start, string key);
List* findDeliveryTime(List* start, string key);

#endif