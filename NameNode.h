#pragma once

#include "Node.h"
#include "GradeNode.h"
#include "StudentIDNode.h"
#include "ContactNode.h"

#include <string>


class NameNode : public Node
{

public:

	char name[32];

	GradeNode *Pleft;
	StudentIDNode *Pfront;
	ContactNode *Pright;


	NameNode()
	{
		name[32] = { 0 };

		Pleft = NULL;
		Pfront = NULL;
		Pright = NULL;
		
	}

	NameNode(char* informName)
	{
		strcpy(name, informName);
	}


	~NameNode()
	{

	}
};

