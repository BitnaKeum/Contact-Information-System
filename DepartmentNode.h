#pragma once
#include <iostream>
#include <string>
#include "Node.h"

class DepartmentNode : public Node
{

public:
	char de_name[32];	// array to store the name of department


	DepartmentNode()
	{
		de_name[32] = { 0 };
	}

	DepartmentNode(char* informDept)
	{
		strcpy(de_name, informDept);
	}

	~DepartmentNode()
	{
	}

};

