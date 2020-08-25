#pragma once
#include "NameNode.h"
#include "DepartmentList.h"


class NameList
{

public:
	
	NameNode* Phead;
	NameNode* Pcur;
	NameNode* Ppre;
	NameNode* Ptemp;

	bool name_destructor;

	NameList()
		:
		Phead(NULL),
		Pcur(NULL),
		Ppre(NULL),
		Ptemp(NULL)
	{
		name_destructor = false;
	}

	~NameList()
	{
		if(name_destructor)
			clear();
	}



	virtual bool LinkedList(char* informName, int informGrade, char* informID, char* informContact, char* informDept, DepartmentList* deptlist);

	void clear();
};

