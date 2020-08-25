#pragma once
#include "ContactNode.h"
#include "NameList.h"


class ContactList
{
public:
	ContactNode* Phead;
	ContactNode* Pcur;


	ContactList()
		:
		Phead(NULL),
		Pcur(NULL)
	{

	}

	~ContactList()
	{

	}


	bool makeContactList(NameList namelist);

};

