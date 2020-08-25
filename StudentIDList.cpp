#include "StudentIDList.h"



bool StudentIDList::makeStudentIDList(NameList namelist)
{
	// namelist.Pcur points the first node of NameList
	namelist.Pcur = namelist.Phead;


	while (1)
	{
		// if StudentIDList is empty
		if (Phead == NULL)
		{
			// Phead points the StudentIDNode that the first NameNode points
			Phead = namelist.Phead->Pfront;

			Pcur = Phead;
		}


		else
		{

			// if the node that namelist.Pcur points is the last node, quit
			if (namelist.Pcur->Pnext == NULL)
				break;


			// namelist.Pcur moves to the following node
			namelist.Pcur = (NameNode*)namelist.Pcur->Pnext;

			// StudentIDList connecting
			Pcur->Pfront = namelist.Pcur->Pfront;

			// Pcur points the following node
			Pcur = Pcur->Pfront;



		}

	}

	return true;
}