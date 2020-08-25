#pragma once
#include <string>


class ContactNode
{

public:
	char contact[32];	// arrange for contacts
	ContactNode *Pright;

	// constructor
	ContactNode()
	{
		contact[32] = { 0 };
		Pright = NULL;
	}

	// overloading constructor
	ContactNode(char* informContact)
	{
		strcpy(contact, informContact);
		Pright = NULL;
	}

	// destructor
	~ContactNode()
	{

	}
};

