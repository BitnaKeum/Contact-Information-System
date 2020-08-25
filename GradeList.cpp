#include "GradeList.h"




bool GradeList::makeGradeList(NameList namelist)
{
	// namelist.Pcur points the first node of NameList
	namelist.Pcur = namelist.Phead;


	while (1)
	{
		// if GradeList is empty
		if (Phead == NULL)
		{
			// Phead points the GradeNode that the first NameNode points
			Phead = namelist.Phead->Pleft;

			Pcur = Phead;
		}


		else
		{

				// if the node that namelist.Pcur points is the last node, quit
				if (namelist.Pcur->Pnext == NULL)
					break;


				// namelist.Pcur moves to the following node
				namelist.Pcur = (NameNode*)namelist.Pcur->Pnext;

				// GradeList connecting
				Pcur->Pleft = (GradeNode*)namelist.Pcur->Pleft;

				// Pcur points the following node
				Pcur = Pcur->Pleft;

			

		}

	}

	return true;
}