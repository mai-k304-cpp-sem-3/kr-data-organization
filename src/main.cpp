#include <iostream>
#include <string>

#include "examination.h"
#include "professor.h"
#include "group.h"

using namespace std;

const char EXAMINATIONS_FILE_NAME[] = "examinations.txt";
const char PROFESSOR_FILE_NAME[] = "professors.txt";
const char GROUP_FILE_NAME[] = "groups.txt";

int main()
{
	examination* examinations = new examination;
	fileReadExamination(examinations, EXAMINATIONS_FILE_NAME);
	printConsoleExamination(examinations);

	professor* professors = new professor;
	fileReadProfessor(professors, PROFESSOR_FILE_NAME);
	printConsoleProfessor(professors);
}
