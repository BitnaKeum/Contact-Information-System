#include "NameList.h"
#include "GradeNode.h"
#include "StudentIDNode.h"
#include "ContactNode.h"
#include <string>



bool NameList::LinkedList(char* informName, int informGrade, char* informID, char* informContact, char* informDept, DepartmentList* deptlist)
{

	Pcur = Phead;


	NameNode* newName = new NameNode(informName);

	GradeNode* newGrade = new GradeNode(informGrade);
	StudentIDNode* newID = new StudentIDNode(informID);
	ContactNode* newContact = new ContactNode(informContact);




	// Pleft of NameNode points the GradeNode
	newName->Pleft = newGrade;
	// Pfront of NameNode points the StudentIDNode
	newName->Pfront = newID;
	// Pright of NameNode points the ContactNode
	newName->Pright = newContact;



	// if DepartmentList is empty
	if (Phead == NULL)
	{
		Phead = newName;	// Phead points the new node




		// DepartmentList to NameList
		// connect up and down NameList

		deptlist->Pcur = deptlist->Phead;

		deptlist->Pcur->Pdown = newName;
		newName->Pup = deptlist->Pcur;

	}
	
	
	else
	{
		// sort by name in ascending order in NameList
		while (1)
		{

			// if Pcur->name is SMALLER than newName->name
			if (strcmp(Pcur->name, newName->name) == -1)
			{
				// if the node Pcur pointing is not the last node
				if (Pcur->Pnext != NULL)
				{
					// Pcur points the next node
					Pcur = (NameNode*)Pcur->Pnext;
					continue;
				}

				else
				{
					Pcur->Pnext = newName;

					newName->Pprev = Pcur;


					//Pcur points the new node
					Pcur = newName;
	


					break;
				}

			}


			// if Pcur->name is BIGGER than newName->name
			else if (strcmp(Pcur->name, newName->name) == 1)
			{
				if (Pcur == Phead)
				{
					Pcur = newName;

					// link new node and existing node
					Pcur->Pnext = Phead;
					// new node is the frontmost node
					Phead = newName;


					Phead->Pprev = newName;
					Phead = newName;

					break;
				}

				
				else
				{
					Ppre = Phead;

					while (Ppre->Pnext != Pcur)
						Ppre = (NameNode*)Ppre->Pnext;
					// Ppre points the previous node of the node Pcur pointing


					newName->Pnext = Pcur;
					newName->Pprev = Ppre;
					// refer to the front and rear nodes where the ne amame must be inserted

					Ppre->Pnext = newName;
					Pcur->Pprev = newName;
					// newName node is inserted completely


					break;
				}


			}

			// if Pcur->de_name is SAME	with newName->name
			else
			{

				// if the node pointed by Pcur is the last node 
				if (Pcur->Pnext == NULL)
				{
					Pcur->Pnext = newName;
					newName->Pprev = Pcur;
					// connect the new NameNode to the node that was created first (bi-directional)
					
				}

				else
				{
					// Pcur points the next node
					Pcur = (NameNode*)Pcur->Pnext;

					Ppre = Phead;


					while (Ppre->Pnext != Pcur)
						Ppre = (NameNode*)Ppre->Pnext;
					// Ppre points the previous node of what Pcur points

					Ppre->Pnext = newName;
					newName->Pprev = Ppre;
					// link previous node and new NameNode (bi-directional)

					newName->Pnext = Pcur;
					Pcur->Pprev = newName;
					// link following node and new NameNode (bi-directional)




				}



				break;
			}


		}	// while







			// connect DepartmentList to NameList
			// connect up and down NameList
		
		deptlist->Pcur = deptlist->Phead;

		// repeat until deptlist->Pcur->de_name equals to informDept
		while (strcmp(deptlist->Pcur->de_name, informDept))
		{
			// deplist->Pcur points the next node
			deptlist->Pcur = (DepartmentNode*)deptlist->Pcur->Pnext;
		}



	

		// If there is no node connected to DepartmentNode
		if (deptlist->Pcur->Pdown == NULL)
		{
			deptlist->Pcur->Pdown = newName;

			Pcur = (NameNode*)deptlist->Pcur->Pdown;
			Pcur->Pup = deptlist->Pcur;
			// DepartmentNode and NameNode connected in both directions
		}


		// If there is any node connected to DepartmentNode
		else
		{

			Pcur = (NameNode*)deptlist->Pcur->Pdown;


			while (1)
			{

				// if Pcur->name is SMALLER than newName->name or same  
				if (strcmp(Pcur->name, newName->name) == -1 || strcmp(Pcur->name, newName->name) == 0)
				{
					// if the node Pcur pointing is not the last node
					if (Pcur->Pdown != NULL)
					{
						// Pcur points the next node
						Pcur = (NameNode*)Pcur->Pdown;
						continue;
					}

					else
					{
						Pcur->Pdown = newName;

						newName->Pup = Pcur;


						//Pcur points the new node
						Pcur = newName;





						break;
					}

				}


				// if Pcur->name is BIGGER than newName->name
				else if (strcmp(Pcur->name, newName->name) == 1)
				{

					if (Pcur == deptlist->Pcur->Pdown)
					{
						deptlist->Pcur->Pdown = newName;
						newName->Pup = deptlist->Pcur;
						// link DepartmentNode and new NameNode (bi-direcitonal)

						Pcur->Pup = newName;
						newName->Pdown = Pcur;
						// link existing NameNode¿Í new NameNode (bi-direcitonal)

						break;


					}


					else
					{
						Ppre = (NameNode*)deptlist->Pcur->Pdown;


						while (Ppre->Pdown != Pcur)
							Ppre = (NameNode*)Ppre->Pdown;
						// Ppre points the previous node of the node Pcur pointing


						newName->Pdown = Pcur;
						newName->Pup = Ppre;
						// refer to the upper and lower nodes where the ne amame must be inserted

						Ppre->Pdown = newName;
						Pcur->Pup = newName;
						// newName node is inserted completely


						break;
					}


				}


			}	// while
		}







	}

	


	return true;
}


void NameList::clear()
{
	Ppre = Phead;

	if (Ppre->Pnext != NULL)
		Pcur = (NameNode*)Ppre->Pnext;

	while (1)
	{
		// delete ContactNode, StudentIDNode, GradeNode that connected to the NameNode
		delete Ppre->Pright;
		delete Ppre->Pfront;
		delete Ppre->Pleft;
		// delete the NameNode
		delete Ppre;

		Ppre = Pcur;

		// Pcur points the next node of whawt Ppre points
		if (Ppre->Pnext == NULL)
		{
			delete Ppre->Pright;
			delete Ppre->Pfront;
			delete Ppre->Pleft;

			delete Ppre;

			break;
		}

		Pcur = (NameNode*)Pcur->Pnext;

	}
}