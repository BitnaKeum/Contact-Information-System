#pragma once
#include <iostream>
#include <string>

class StudentIDNode
{

public:
	char studentid[32];
	StudentIDNode *Pfront;


	StudentIDNode()
	{
		studentid[32] = { 0 };
		Pfront = NULL;
	}

	StudentIDNode(char* informID)
	{
		strcpy(studentid, informID);
		Pfront = NULL;
	}

	~StudentIDNode()
	{

	}
};

