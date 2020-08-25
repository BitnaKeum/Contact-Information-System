#pragma once
#include "StudentIDNode.h"
#include "NameList.h" 

class StudentIDList
{
public:
	StudentIDNode* Phead;
	StudentIDNode* Pcur;


	StudentIDList()
		:
		Phead(NULL),
		Pcur(NULL)
	{	
	}
	

	~StudentIDList()
	{

	}


	bool makeStudentIDList(NameList namelist);
};

