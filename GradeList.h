#pragma once
#include "GradeNode.h"
#include "NameList.h"


class GradeList
{
public:
	GradeNode* Phead;
	GradeNode* Pcur;


	GradeList()
		:
		Phead(NULL),
		Pcur(NULL)
	{
	}

	~GradeList()
	{
	}


	bool makeGradeList(NameList namelist);

};

