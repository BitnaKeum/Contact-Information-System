#pragma once
#include <iostream>

class GradeNode
{

public:
	int grade;
	GradeNode *Pleft;


	GradeNode()
		:
		grade(0),
		Pleft(NULL)
	{
	}

	GradeNode(int informGrade)
		:
		grade(informGrade),
		Pleft(NULL)
	{
	}

	~GradeNode()
	{

	}
};

