#include "DepartmentList.h"
#include <string>
#include <iostream>


bool DepartmentList::LinkedList(char *informDept)
{

	Pcur = Phead;


	DepartmentNode* newDept = new DepartmentNode(informDept);


	// if DepartmentList is empty
	if (Phead == NULL)
	{
		Phead = newDept;	// Phead points the new node
	}

	else
	{

		// sort by name in ascending order in DepartmentList
		while (1)
		{

			// if Pcur->de_name is SMALLER than newDept->de_name
			if (strcmp(Pcur->de_name, newDept->de_name) == -1)
			{


				// if the node Pcur pointing is not the last node
				if (Pcur->Pnext != Phead)
				{
					// Pcur points the next node
					Pcur = (DepartmentNode*)Pcur->Pnext;
					continue;
				}

				else
				{
					Pcur->Pnext = newDept;	
					Pcur = newDept;		// Pcur points the new node
					Pcur->Pnext = Phead;
					// new node points the frontmost node (circular linked list)

					break;
				}
				
			}


			// if Pcur->de_name is BIGGER than newDept->de_name
			else if (strcmp(Pcur->de_name, newDept->de_name) == 1)
			{

				// if de_name of the new node is the smallest
				if (Pcur == Phead)
				{
					Phead = newDept;

					Phead->Pnext = Pcur;


					DepartmentNode* Ptemp = Pcur;

					while (1)
					{
						// if the node pointed by Pcur is the last node of DepartmentList
						if (Pcur->Pnext == NULL || Pcur->Pnext == Ptemp)
							break;

						else
							// Pcur points the next node
							Pcur = (DepartmentNode*)Pcur->Pnext;
					}

					// the last node of DepartmentList points the new node
					Pcur->Pnext = Phead;


					break;
				}


				else
				{
					Ppre = Phead;
					
					
					while (Ppre->Pnext != Pcur)
						Ppre = (DepartmentNode*)Ppre->Pnext;
					// Ppre points the previous node of the node Pcur pointing


					Ppre->Pnext = newDept;
					Ppre = newDept;
					Ppre->Pnext = Pcur;
					// New node connected between node pointing to Ppre and node pointing to Pcur


					break;
				}


			}

			// if Pcur->de_name is SAME	with newDept->de_name
			else
			{
				break;
			}



		}



	}



	return true;
}


//A function that free dynamic memory, used in destructor
void DepartmentList::clear()
{
	Ppre = Phead;

	Pcur = (DepartmentNode*)Ppre->Pnext;


	while (1)
	{
		delete Ppre;

		Ppre = Pcur;


		if (Ppre->Pnext == Phead)
		{
			// free memory
			delete Ppre;
			break;
		}

		Pcur = (DepartmentNode*)Pcur->Pnext;
	}

}