#pragma once
#include <iostream>

class Node
{

public:
	Node *Pnext; // indicate next node in ascending order
	Node *Pprev; // point to the previous node in ascending order
	Node *Pup; // indicate a department or higher node in ascending order
	Node *Pdown; // point to child node in ascending order


	Node()
		:
		Pnext(NULL),
		Pprev(NULL),
		Pup(NULL),
		Pdown(NULL)
	{
	}

	~Node()
	{

	}
};

