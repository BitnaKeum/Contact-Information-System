#pragma once
#include "DepartmentNode.h"


class DepartmentList
{

public:

	DepartmentNode* Phead;
	DepartmentNode* Pcur;
	DepartmentNode* Ppre;

	bool dept_destructor;

	// constructor
	DepartmentList()
		:
		Phead(NULL),
		Pcur(NULL),
		Ppre(NULL)
	{
		dept_destructor = false;
	}

	// Destructor
	~DepartmentList()
	{
		if (dept_destructor)
			clear();
	}



	virtual bool LinkedList(char *informDept);

	void clear();
};




