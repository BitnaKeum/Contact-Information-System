#pragma once
#include <iostream>
#include <fstream>

#include "DepartmentList.h"
#include "NameList.h"
#include "GradeList.h"
#include "StudentIDList.h"
#include "ContactList.h"

#include <crtdbg.h>


using namespace std;


// read and act on commands from Command.txt.
class Manager
{
private:


	GradeList gradelist;
	StudentIDList idlist;
	StudentIDList cpy_idlist;	// used by PRINT_STUDENT_ID function
	ContactList contactlist;
	ContactList cpy_contactlist;	// used by PRINT_CONTACT function

	ofstream log;


public:

	DepartmentList deptlist;
	NameList namelist;

	char command[20];
	char commandData1[30];
	char commandData2[30];

	char informDept[30];
	char informName[10];
	int informGrade;
	char informID[11];
	char informContact[15];


	Manager()
	{
		command[20] = { 0, };
		commandData1[30] = { 0 };
		commandData2[30] = { 0 };

		informDept[30] = { 0 };
		informName[10] = { 0 };
		informGrade = 0;
		informID[11] = { 0 };
		informContact[15] = { 0 };

		log.open("LOG.txt");

	}

	~Manager()
	{

	}



	bool getData();

	bool LOAD_ADD(char * command);

	bool PRINT();
	bool PRINT(char * commandData1);
	
	bool UPDATE();

	bool MODIFY_DEPT(char* commandData1, char* commandData2);

	bool DELETE_DEPT(char* commandData1);

	bool PRINT_STUDENT_ID();

	bool PRINT_CONTACT();

	bool FIND_NAME(char* commandData1);

	bool SAVE(char* commandData1);

	void EXIT();


};

