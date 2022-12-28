cmake_minimum_required(VERSION 3.22) # Минимальная версия Cmake

project(kr-1-data-organization) # Название проекта

set(CMAKE_CXX_STANDARD 11) # Версия стандарта C++

set(SOURCE_EXE src/main.cpp) # Установка переменной со списком исходников для исполняемого файла

set(SOURCE_LIB src/examination.cpp
               src/professor.cpp
               src/group.cpp
) # Установка переменной со списком исходников для библиотеки

add_library(lib STATIC ${SOURCE_LIB}) # Создание статической библиотеки

add_executable(kr-1-data-organization ${SOURCE_EXE}) # Создаие исполняеого файла

target_link_libraries(kr-1-data-organization lib) # Линковка программы с библиотекой