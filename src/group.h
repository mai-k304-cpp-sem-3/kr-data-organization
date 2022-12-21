#ifndef GROUP_H
#define GROUP_H

#include <string> // Подключение библиотеки для работы со string

struct group {
    int id;
    group* back;
    group* next;
    int count;
    string name;
    int examination;
};

#endif