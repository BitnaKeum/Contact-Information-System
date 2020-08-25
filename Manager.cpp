#include <iostream>
#include <fstream>

#include "Manager.h"

using namespace std;


//A function to save commands, data1, and data2 from Command.txt.
bool Manager::getData()
{

	ifstream CommandText;

	// Load Command.txt using the IFstream
	CommandText.open("Command.txt");


	while (1)
	{
		if (!CommandText) {
			cout << "Cannot open Command.txt!" << endl;
			exit(100);
		}

		CommandText.unsetf(ios::skipws);



		for (int i = 0; i < 20; i++)
		{
			CommandText >> command[i];

			if (command[i] == 32)
			// if reading space from file
			{
				command[i] = '\0';	// delete the space character


				// Data other than command exists on the corresponding line
				for (int j = 0; j < 30; j++)
				{
					// store information in commandData1
					CommandText >> commandData1[j];

					if (commandData1[j] == 32)
						//if reading space from file
					{
						commandData1[j] = '\0';	// delete the space character



						for (int k = 0; k < 20; k++)
						{
							// store information in commandData2
							CommandText >> commandData2[k];

							// reaching the end of the line
							if (commandData2[k] == '\n')
							{
								commandData2[k] = '\0';
								break;	// End saving to commandData2
							}
						}
						

						break;	// end saving to commandData1

					}	// if(data1[j] == 32)


					else if (commandData1[j] == '\n')
					{
						commandData1[j] = '\0';	// delete the '\n' character
						break;	// end saving to commandData1
					}



				}	// for(int j = 0; j < 20; j++)

				break;	// end saving to command


			}	// if(command[i] == 32)


			else if (command[i] == '\n')
			{
				command[i] = '\0';	// delete the '\n' character
				break;	// end saving to command
			}

		}






		// if command is LOAD 
		if (!strcmp(command, "LOAD"))
		{
			cout << endl << "[LOAD]" << endl;
			log << endl << "[LOAD]" << endl;

			if (LOAD_ADD(command)) {
				cout << "Success" << endl << endl;
				log << "Success" << endl << endl;
			}
		}
			
			
		// if command is ADD
		else if(!strcmp(command, "ADD")) 
		{
			cout << endl << "[ADD]" << endl;
			log << endl << "[ADD]" << endl;

			if (LOAD_ADD(command)) {
				cout << "Success" << endl << endl;
				log << "Success" << endl << endl;
			}
		}



		// if command is PRINT
		else if (!strcmp(command, "PRINT")) {


			// there is no parameter in command PRINT
			if (commandData1[0] == 0)
			{
				cout << endl << "[PRINT]" << endl;
				log << endl << "[PRINT]" << endl;

				PRINT();
				cout << endl;
				log << endl;
			}


			// there is parameter in command PRINT
			else
			{
				cout << endl << "[PRINT " << commandData1 << "]" << endl; 
				log << endl << "[PRINT " << commandData1 << "]" << endl;

				PRINT(commandData1);

				cout << endl;
				log << endl;
			}


		}



		// if command is UPDATE
		else if (!strcmp(command, "UPDATE")) {
			cout << endl << "[UPDATE]" << endl;
			log << endl << "[UPDATE]" << endl;
			
			if (UPDATE()) {
				cout << "Success" << endl << endl;
				log << "Success" << endl << endl;
			}

			
		}



		// if command is MODIFY_DEPARTMENT
		else if (!strcmp(command, "MODIFY_DEPARTMENT"))
		{
			cout << endl << "[MODIFY_DEPARTMENT]" << endl;
			log << endl << "[MODIFY_DEPARTMENT]" << endl;

			if (MODIFY_DEPT(commandData1, commandData2)) {
				cout << "Success" << endl << endl;
				log << "Success" << endl << endl;
			}

			
		}



		// if command is DELETE_DEPARTMENT
		else if (!strcmp(command, "DELETE_DEPARTMENT"))
		{
			cout << endl<< "[DELETE_DEPARTMENT]" << endl;
			log << endl << "[DELETE_DEPARTMENT]" << endl;

			if (DELETE_DEPT(commandData1)) {
				cout << "Success" << endl << endl;
				log << "Success" << endl << endl;
			}
		}



		else if (!strcmp(command, "PRINT_STUDENT_ID"))
		{
			cout << endl << "[PRINT_STUDENT_ID]" << endl;
			log << endl << "[PRINT_STUDENT_ID]" << endl;

			PRINT_STUDENT_ID();
			cout << endl;
			log << endl;

		}



		else if (!strcmp(command, "PRINT_CONTACT"))
		{
			cout << endl << "[PRINT_CONTACT]" << endl;
			log << endl << "[PRINT_CONTACT]" << endl;

			PRINT_CONTACT();
			cout << endl;
			log << endl;
		}

		
		
		else if (!strcmp(command, "FIND_NAME"))
		{
			cout << endl << "[FIND_NAME " << commandData1 << "]" << endl;
			log << endl << "[FIND_NAME " << commandData1 << "]" << endl;

			FIND_NAME(commandData1);
			cout << endl;
			log << endl;
		}



		else if (!strcmp(command, "SAVE"))
		{
			cout << endl << "[SAVE]" << endl;
			log << endl << "[SAVE]" << endl;

			if (SAVE(commandData1)) {
				cout << commandData1 << " " << "Success" << endl << endl;
				log << commandData1 << " " << "Success" << endl << endl;
			}
		}



		else if (!strcmp(command, "EXIT"))
		{
			cout << endl << "[EXIT]" << endl;
			log << endl << "[EXIT]" << endl;

			EXIT();
		}
			

		// if the command is not existing, print the error code
		else
		{
			cout << endl << "error code : 000" << endl;
			log << endl << "error code : 000" << endl;
		}
	


		// To load next commands, free memory
		memset(command, 0, sizeof(command));
		memset(commandData1, 0, sizeof(commandData1));
		memset(commandData2, 0, sizeof(commandData2));
	}

	return true;
}






// A function to implement the command LOAD or ADD
bool Manager::LOAD_ADD(char * command)
{
	ifstream InformText;


	// if command is LOAD
	if (!strcmp(command, "LOAD"))
	{
		// Read information in Information.txt using ifstream
		InformText.open("Information.txt");


		// if Information.txt does not exist
		if (!InformText) {
			cout << "error code : 100" << endl;
			log << "error code : 100" << endl;

			exit(100);
		}

	}

	// if command is ADD
	else if (!strcmp(command, "ADD"))
	{
		// Read information in Add_information.txt using ifstream
		InformText.open("Add_information.txt");


		// if Add_information.txt does not exist
		if (!InformText) {
			cout << "error code : 200" << endl;
			log << "error code : 200" << endl;

			exit(100);
		}
	}

	


	// repeat until end of file is reached
	while (!InformText.eof())
	{
		
		InformText >> informDept >> informName >> informGrade >> informID >> informContact;


		// if command is ADD
		if (!strcmp(command, "ADD"))
		{
			namelist.Pcur = namelist.Phead;


			while (1)
			{
				// if there is same ID or contact in existing list
				if ( !strcmp(namelist.Pcur->Pfront->studentid, informID) || !strcmp(namelist.Pcur->Pright->contact, informContact) )
				{
					// print the error code
					cout << "error code : 200-1" << endl;
					log << "error code : 200-1" << endl;

					break;
				}


				// if there is no same ID or contact in existing list
				if (namelist.Pcur->Pnext == NULL)
					break;


				namelist.Pcur = (NameNode*)namelist.Pcur->Pnext;
			}

			// if print the error code
			if (namelist.Pcur->Pnext != NULL)
				continue;
		
		}



		// generate DepartmentList
		deptlist.LinkedList(informDept);	

		// generate NameList
		namelist.LinkedList(informName, informGrade, informID, informContact, informDept, &deptlist);	
		





		memset(informDept, 0, sizeof(informDept));
		memset(informName, 0, sizeof(informName));
		memset(informID, 0, sizeof(informID));
		memset(informContact, 0, sizeof(informContact));


	}

	// create GradeList, StudentIDList, and ContactList using sorted NameList
	gradelist.makeGradeList(namelist);
	idlist.makeStudentIDList(namelist);
	contactlist.makeContactList(namelist);






	
	return true;
}



// A function to print informations of all students of all departments
bool Manager::PRINT()
{
	deptlist.Pcur = deptlist.Phead;

	if (deptlist.Pcur == NULL)
	{

		// print the error code
		cout << "error code : 600-1" << endl;
		log << "error code : 600-1" << endl << endl;
		return false;
	}


	while (1)
	{
		namelist.Pcur = (NameNode*)deptlist.Pcur->Pdown;

		while (1)
		{
			if (namelist.Pcur->Pdown == NULL)
				break;

			namelist.Pcur = (NameNode*)namelist.Pcur->Pdown;
		}	// namelist.Pcur points the last node of NameList which is connected to DepartmentNode




		while (1)
		{

			cout << deptlist.Pcur->de_name << "/";
			cout << namelist.Pcur->name << "/";
			cout << namelist.Pcur->Pleft->grade << "/";
			cout << namelist.Pcur->Pfront->studentid << "/";
			cout << namelist.Pcur->Pright->contact << endl;


			log << deptlist.Pcur->de_name << "/";
			log << namelist.Pcur->name << "/";
			log << namelist.Pcur->Pleft->grade << "/";
			log << namelist.Pcur->Pfront->studentid << "/";
			log << namelist.Pcur->Pright->contact << endl;


			// if the NameNode is the first node which is connected to DepartmentNode, then break
			if (namelist.Pcur->Pup == deptlist.Pcur)
				break;


			namelist.Pcur = (NameNode*)namelist.Pcur->Pup;

		}


		
		// if deptlist.Pcur points the last node in DepartmentList, then break
		if (deptlist.Pcur->Pnext == deptlist.Phead)
			break;

		deptlist.Pcur = (DepartmentNode*)deptlist.Pcur->Pnext;
	}

	return true;
}



// A function to print informations of all students of a certain department
bool Manager::PRINT(char * commandData1)
{
	deptlist.Pcur = deptlist.Phead;

	if (deptlist.Pcur == NULL)
	{
		cout << "error code : 600-1" << endl;
		log << "error code : 600-1" << endl << endl;
		return false;
	}




	// repeat until deptlist.Pcur points the node including the commandData1
	while (strcmp(deptlist.Pcur->de_name, commandData1))
	{
		// if deptlist.Pcur points the last node in DepartmentList
		if (deptlist.Pcur->Pnext == NULL)
		{
			cout << "error code : 600-2" << endl;
			log << "error code : 600-2" << endl << endl;

			return false;
		}

		deptlist.Pcur = (DepartmentNode*)deptlist.Pcur->Pnext;
	}



		namelist.Pcur = (NameNode*)deptlist.Pcur->Pdown;

		while (1)
		{
			if (namelist.Pcur->Pdown == NULL)
				break;

			namelist.Pcur = (NameNode*)namelist.Pcur->Pdown;
		}	// namelist.Pcur points the last node of NameList which is connected to DepartmentNode




		while (1)
		{

			cout << deptlist.Pcur->de_name << "/";
			cout << namelist.Pcur->name << "/";
			cout << namelist.Pcur->Pleft->grade << "/";
			cout << namelist.Pcur->Pfront->studentid << "/";
			cout << namelist.Pcur->Pright->contact << endl;

			log << deptlist.Pcur->de_name << "/";
			log << namelist.Pcur->name << "/";
			log << namelist.Pcur->Pleft->grade << "/";
			log << namelist.Pcur->Pfront->studentid << "/";
			log << namelist.Pcur->Pright->contact << endl;


			// if the NameNode is the first node which is connected to DepartmentNode, then break
			if (namelist.Pcur->Pup == deptlist.Pcur)
				break;


			namelist.Pcur = (NameNode*)namelist.Pcur->Pup;

		}



	return true;


}



// A function to update information from Update_information.txt
bool Manager::UPDATE()
{
	ifstream InformText;

	InformText.open("Update_information.txt");


	if (!InformText) {
		cout << "error code : 300" << endl;
		log << "error code : 300" << endl;

		exit(100);
	}




	// repeat until reaching the end of file
	while (!InformText.eof())
	{

		InformText >> informDept >> informName >> informGrade >> informID >> informContact;


		namelist.Pcur = namelist.Phead;


		// disciriminate if there is the name in NameList
		while (1)
		{
			// if there is the name in NameList
			if (!strcmp(namelist.Pcur->name, informName))
				break;

			// when reaching the last node of NameList, there is no that name in NameList
			if (namelist.Pcur->Pnext == NULL)
			{
				// print the error code
				cout << "error code : 300-2" << endl;
				log << "error code : 300-2" << endl;

				break;
			}
			namelist.Pcur = (NameNode*)namelist.Pcur->Pnext;
		}

		// if there is no that name in NameList
		if (strcmp(namelist.Pcur->name, informName))
			continue;




		namelist.Pcur = namelist.Phead;


		while (1)
		{
			// if there is same ID or contact in existing list
			if (!strcmp(namelist.Pcur->Pfront->studentid, informID) || !strcmp(namelist.Pcur->Pright->contact, informContact))
			{
				// print the error code
				cout << "error code : 300-1" << endl;
				log << "error code : 300-1" << endl;

				break;
			}


			// if there is no same ID or contact in existing list
			if (namelist.Pcur->Pnext == NULL)
				break;


			namelist.Pcur = (NameNode*)namelist.Pcur->Pnext;


			// if namelist.Pcur points the same name, points the next node
			if(!strcmp(namelist.Pcur->name, informName))
				namelist.Pcur = (NameNode*)namelist.Pcur->Pnext;
		}

		// if print the error code
		if (namelist.Pcur->Pnext != NULL)
			continue;






		namelist.Ptemp = namelist.Pcur;

		while (namelist.Ptemp->Pup != NULL)
			namelist.Ptemp = (NameNode*)namelist.Ptemp->Pup;
		// namelist.Ptemp points the DepartmentNode that the NameNode is included


		deptlist.Pcur = (DepartmentNode*)namelist.Ptemp;
		// Pcur points the DepartmentNode that the NameNode is included




		// if department is different (=> ID is also different)
		if (strcmp(deptlist.Pcur->de_name, informDept)) 
		{
			// update new ID in existing studentid
			strcpy(namelist.Pcur->Pfront->studentid, informID);


			// if namelist.Pcur is directly linked to DepartmentNode
			if (namelist.Pcur->Pup == deptlist.Pcur)
			{
				if (namelist.Pcur->Pdown == NULL) {
					deptlist.Pcur->Pdown = NULL;


					deptlist.Ppre = deptlist.Phead;


					if (deptlist.Pcur == deptlist.Phead) {
						while (deptlist.Ppre->Pnext != deptlist.Phead)
							deptlist.Ppre = (DepartmentNode*)deptlist.Ppre->Pnext;
						// deptlist.Ppre points the last node in DepartmentList

						break;
					}

					else
					{
						while (deptlist.Ppre->Pnext != deptlist.Pcur)
							deptlist.Ppre = (DepartmentNode*)deptlist.Ppre->Pnext;
						

						deptlist.Ppre->Pnext = deptlist.Pcur->Pnext;
						delete deptlist.Pcur;
						// delete the DepartmentNode that has no NameNode
					}
				}
			}



			else
			{
				if (namelist.Pcur->Pdown == NULL)
					namelist.Pcur->Pup->Pdown = NULL;

				else {
					namelist.Pcur->Pup->Pdown = namelist.Pcur->Pdown;
					namelist.Pcur->Pdown->Pup = namelist.Pcur->Pup;
				}


				deptlist.Pcur = deptlist.Phead;

				// repeat until deptlist->Pcur->de_name equals to informDept
				while (strcmp(deptlist.Pcur->de_name, informDept))
				{
					// deplist->Pcur points the next node
					deptlist.Pcur = (DepartmentNode*)deptlist.Pcur->Pnext;
				}




				// If there is no node connected to DepartmentNode
				if (deptlist.Pcur->Pdown == NULL)
				{
					deptlist.Pcur->Pdown = namelist.Pcur;

					namelist.Pcur->Pup = deptlist.Pcur;
					namelist.Pcur->Pdown = NULL;
					//DepartmentNode and NameNode connected in both directions
				}


				// If there is any node connected to DepartmentNode
				else
				{

					namelist.Ptemp = (NameNode*)deptlist.Pcur->Pdown;


					while (1)
					{

						// if namelist.Ptemp->name is SMALLER than namelist.Pcur->name or same  
						if (strcmp(namelist.Ptemp->name, namelist.Pcur->name) == -1 || strcmp(namelist.Ptemp->name, namelist.Pcur->name) == 0)
						{
							// if the node Ptemp pointing is not the last node
							if (namelist.Ptemp->Pdown != NULL)
							{
								// Ptemp points the next node
								namelist.Ptemp = (NameNode*)namelist.Ptemp->Pdown;
								continue;
							}

							else
							{
								namelist.Ptemp->Pdown = namelist.Pcur;

								namelist.Pcur->Pup = namelist.Ptemp;


								break;
							}
						}


						// if namelist.Ptemp->name is BIGGER than newName->name
						else if (strcmp(namelist.Ptemp->name, namelist.Pcur->name) == 1)
						{

							if (namelist.Ptemp == deptlist.Pcur->Pdown)
							{
								deptlist.Pcur->Pdown = namelist.Pcur;
								namelist.Pcur->Pup = deptlist.Pcur;
								// link DepartmentNode and new NameNode (bidirectional)

								namelist.Ptemp->Pup = namelist.Pcur;
								namelist.Pcur->Pdown = namelist.Ptemp;
								// link existing NameNode¿Í new NameNode (bidirectional)

								break;


							}


							else
							{
								namelist.Ppre = (NameNode*)deptlist.Pcur->Pdown;


								while (namelist.Ppre->Pdown != namelist.Ptemp)
									namelist.Ppre = (NameNode*)namelist.Ppre->Pdown;
								// namelist.Ppre points the previous node of the node Ptemp pointing


								namelist.Pcur->Pdown = namelist.Ptemp;
								namelist.Pcur->Pup = namelist.Ppre;
								// namelist.Pcur points to the upper and lower nodes in the location where it should be inserted

								namelist.Ppre->Pdown = namelist.Pcur;
								namelist.Ptemp->Pup = namelist.Pcur;
								// namelist.Pcur node is inserted completely


								break;
							}


						}	// else if


					}	// while
				}	// else
			}
		}	//if






		// if contact information is different
		if (strcmp(namelist.Pcur->Pright->contact, informContact)) {

			// update new contact in existing contact
			strcpy(namelist.Pcur->Pright->contact, informContact);
		}



	}	// while




	return true;

}



// A function to modify department name 
bool Manager::MODIFY_DEPT(char* commandData1, char* commandData2)
{
	//Pcur will point to DepartmentNode before modified
	deptlist.Pcur = deptlist.Phead;		


	while (strcmp(deptlist.Pcur->de_name, commandData1))
	{
		deptlist.Ppre = deptlist.Pcur;

		
		// if reaching the last node in DepartmentList
		if (deptlist.Pcur->Pnext == deptlist.Phead)
		{
			cout << "error code : 400" << endl<< endl;
			log << "error code : 400" << endl;
			return false;
		}

		deptlist.Pcur = (DepartmentNode*)deptlist.Pcur->Pnext;
	}	// Pcur points the DepartmentNode before modified
		// Ppre points the previous node of what Pcur is pointing


	// when commandData 1 is embedded in the first node of DepartmentList
	if (deptlist.Pcur == deptlist.Phead)
	{
		while (deptlist.Ppre->Pnext != NULL)
			deptlist.Ppre = (DepartmentNode*)deptlist.Ppre->Pnext;
		// deptlist.Ppre points the last node in DepartmentList

		deptlist.Phead = (DepartmentNode*)deptlist.Pcur->Pnext;
	}






	// namelist.Pcur points the first NameNode corresponding the DepartmentNode
	namelist.Pcur = (NameNode*)deptlist.Pcur->Pdown;



	// delete the DepartmentNode before modified
	deptlist.Ppre->Pnext = deptlist.Pcur->Pnext;
	delete deptlist.Pcur;


	namelist.Ptemp = namelist.Phead;
	
	// namelist.Ptemp points the previous node of what namelist.Pcur is pointing
	while (namelist.Ptemp->Pnext != namelist.Pcur)
		namelist.Ptemp = (NameNode*)namelist.Ptemp->Pnext;





	while (1)
	{

		char t_name[10] = { 0 };
		int t_grade = 0;
		char t_id[11] = { 0 };
		char t_contact[15] = { 0 };
		char t_dept[30] = { 0 };

		
		
		strcpy(t_name, namelist.Pcur->name);
		t_grade = namelist.Pcur->Pleft->grade;
		strcpy(t_id, namelist.Pcur->Pfront->studentid);
		strcpy(t_contact, namelist.Pcur->Pright->contact);
		strcpy(t_dept, commandData2);


		
		gradelist.Pcur = namelist.Pcur->Pleft;
		namelist.Ptemp->Pleft->Pleft = gradelist.Pcur->Pleft;
		// disconnect current GradeNode from GradeList


		contactlist.Pcur = namelist.Pcur->Pright;
		namelist.Ptemp->Pright->Pright = contactlist.Pcur->Pright;
		// disconnect the current ContactNode from ContactList


		idlist.Pcur = namelist.Pcur->Pfront;
		namelist.Ptemp->Pfront->Pfront = idlist.Pcur->Pfront;
		// disconnect the current studentI DNode from studentIDList


		
		delete gradelist.Pcur;
		delete contactlist.Pcur;
		delete idlist.Pcur;
		// delete the GradeNode, ContactNode and studentIDNode connected to current NameNode

		

		// namelist.Ptemp points the previous node of what namelist.Pcur is pointing
		while (namelist.Ptemp->Pnext != namelist.Pcur)
			namelist.Ptemp = (NameNode*)namelist.Ptemp->Pnext;


		
		namelist.Ptemp->Pnext = namelist.Pcur->Pnext;

		NameNode* temp = (NameNode*)namelist.Pcur->Pnext;


		//namelist.Ptemp->Pnext->Pprev = namelist.Ptemp;
		temp->Pprev = namelist.Ptemp;
		// disconnect the current node from Namelist



		


		temp = namelist.Pcur;





		// new nodes connected to the DepartmentNode before modification to the DepartmentNode after modification
		namelist.LinkedList(t_name, t_grade, t_id, t_contact, t_dept, &deptlist);





		namelist.Pcur = temp;


		namelist.Ppre = namelist.Pcur;


		// terminate while statement if the last node of the department
		if (namelist.Pcur->Pdown == NULL)
		{
			// delete the NameNode
			delete namelist.Ppre;
			break;
		}
		

		namelist.Pcur = (NameNode*)namelist.Pcur->Pdown;


		// delete the NameNode
		delete namelist.Ppre;


	}







	// Cause NameList is modified, regenerate GradeList, StudentIDList, ContactList
	gradelist.makeGradeList(namelist);
	idlist.makeStudentIDList(namelist);
	contactlist.makeContactList(namelist);
	


	return true;
}



// A function to delete department name and all information of the department
bool Manager::DELETE_DEPT(char* commandData1)
{
	//Pcur will point to DepartmentNode before modified
	deptlist.Pcur = deptlist.Phead;		


	while (strcmp(deptlist.Pcur->de_name, commandData1))
	{
		deptlist.Ppre = deptlist.Pcur;

		// if reaching the last node in DepartmentList
		if (deptlist.Pcur->Pnext == deptlist.Phead)
		{
			cout << "error code : 500" << endl << endl;
			log << "error code : 500" << endl;
			return false;
		}

		deptlist.Pcur = (DepartmentNode*)deptlist.Pcur->Pnext;
	}	// Pcur points the DepartmentNode before modified
		// Ppre points the previous node of what Pcur is pointing
	


		// when commandData 1 is embedded in the first node of DepartmentList
	if (deptlist.Pcur == deptlist.Phead)
	{
		while (deptlist.Ppre->Pnext != NULL)
			deptlist.Ppre = (DepartmentNode*)deptlist.Ppre->Pnext;
		// deptlist.Ppre points the last node in DepartmentList

		deptlist.Phead = (DepartmentNode*)deptlist.Pcur->Pnext;
	}






	// namelist.Pcur points the first NameNode corresponding the DepartmentNode
	namelist.Pcur = (NameNode*)deptlist.Pcur->Pdown;



	// delete the DepartmentNode before modified
	deptlist.Ppre->Pnext = deptlist.Pcur->Pnext;
	delete deptlist.Pcur;



	namelist.Ptemp = namelist.Phead;
	
	





	while (1)
	{
		// namelist.Ptemp points the previous node of what namelist.Pcur is pointing
		while (namelist.Ptemp->Pnext != namelist.Pcur)
			namelist.Ptemp = (NameNode*)namelist.Ptemp->Pnext;
		

		gradelist.Pcur = namelist.Pcur->Pleft;
		namelist.Ptemp->Pleft->Pleft = gradelist.Pcur->Pleft;
		


		contactlist.Pcur = namelist.Pcur->Pright;
		namelist.Ptemp->Pright->Pright = contactlist.Pcur->Pright;
		// disconnect current GradeNode from GradeList


		idlist.Pcur = namelist.Pcur->Pfront;

		namelist.Ptemp->Pfront->Pfront = idlist.Pcur->Pfront;
		// disconnect the current studentI DNode from studentIDList

		
		delete gradelist.Pcur;
		delete contactlist.Pcur;
		delete idlist.Pcur;
		// delete the GradeNode, ContactNode and studentI DNode connected to current NameNode

		

		// namelist.Ptemp points the previous node of what namelist.Pcur is pointing
		while (namelist.Ptemp->Pnext != namelist.Pcur)
			namelist.Ptemp = (NameNode*)namelist.Ptemp->Pnext;


		
		namelist.Ptemp->Pnext = namelist.Pcur->Pnext;

		NameNode* temp = (NameNode*)namelist.Pcur->Pnext;


		//namelist.Ptemp->Pnext->Pprev = namelist.Ptemp;
		temp->Pprev = namelist.Ptemp;
		
		// disconnect the current node from Namelist


		

		namelist.Ppre = namelist.Pcur;


		// terminate while statement if the last node of the department
		if (namelist.Pcur->Pdown == NULL)
		{
			// delete the NameNode
			delete namelist.Ppre;
			break;
		}
		

		namelist.Pcur = (NameNode*)namelist.Pcur->Pdown;


		// delete the NameNode
		delete namelist.Ppre;


	}




	return true;
}



// A function to sort IDs in ascending order using insertion sort
// and print all information
bool Manager::PRINT_STUDENT_ID()
{

	idlist.Pcur = idlist.Phead;

	// if there is no StudetnIDList
	if (idlist.Pcur == NULL)
	{
		cout << "error code : 700" << endl;
		log << "error code : 700" << endl << endl;
		return false;
	}


	// copy the idlist to cpy_idlist
	while (1)
	{
		StudentIDNode* newNode = new StudentIDNode(idlist.Pcur->studentid);


		// if cpy_idlist is empty
		if (cpy_idlist.Phead == NULL)
		{
			// Phead points the new node
			cpy_idlist.Phead = newNode;

			// Pcur points the new node
			cpy_idlist.Pcur = cpy_idlist.Phead;
		}


		else
		{
			// link the new node in cpy_idlist
			cpy_idlist.Pcur->Pfront = newNode;

			// Pcur points the new node
			cpy_idlist.Pcur = cpy_idlist.Pcur->Pfront;
		}




		// if reaching the last node in idlist, break
		if (idlist.Pcur->Pfront == NULL)
			break;


		//Pcur points the next node in idlist
		idlist.Pcur = idlist.Pcur->Pfront;

	}





	// sort cpy_idlist in ascending order using insertion sort

	StudentIDNode index_minus;

	// Pcur points the second node
	cpy_idlist.Pcur = cpy_idlist.Phead->Pfront;


	while (1)
	{


		char tempID[11] = { 0 };

		// store currently pointing studentid in tempID 
		strcpy(tempID, cpy_idlist.Pcur->studentid);

		StudentIDNode* Pwalker = cpy_idlist.Phead;



		while (Pwalker->Pfront != cpy_idlist.Pcur)
		{
			Pwalker = Pwalker->Pfront;
			// Pwalker points the previous node of what cpy_idlist.Pcur is pointing
		}


		 
		while (1)
		{
			// if the studentid pointed by Pwalker is BIGGER than tempID
			if (strcmp(Pwalker->studentid, tempID) == 1)
			{
				strcpy(Pwalker->Pfront->studentid, Pwalker->studentid);


				StudentIDNode* Ptemp = cpy_idlist.Phead;



				while (Ptemp->Pfront != Pwalker)
				{
					// if Ptemp and Pwalker point the first node in StudentIDList
					if (Ptemp == Pwalker) {
						Ptemp = &index_minus;
						break;
					}


					Ptemp = Ptemp->Pfront;
					// Ptemp points the previous node or same node of what Pwalker points
				}


				Pwalker = Ptemp;

				// if Pwalker is out of linkedlist
				if (Pwalker == &index_minus)
					break;



			}

			// if the studentid pointed by Pwalker is SMALLER than tempID, break
			else
				break;




		}


		// insert tempID to correct direction
		if (Pwalker == &index_minus)
			strcpy(cpy_idlist.Phead->studentid, tempID);

		else
			strcpy(Pwalker->Pfront->studentid, tempID);






		// if reaching the last node in StudentIDList, then break
		if (cpy_idlist.Pcur->Pfront == NULL)
			break;

		// Pcur points the next StudentIDNode
		cpy_idlist.Pcur = cpy_idlist.Pcur->Pfront;

	}





	




	// Printing


	// Pcur points the first node in cpy_idlist
	cpy_idlist.Pcur = cpy_idlist.Phead;



	while (1)
	{
		namelist.Pcur = namelist.Phead;



		while (strcmp(cpy_idlist.Pcur->studentid, namelist.Pcur->Pfront->studentid))
		{
			namelist.Pcur = (NameNode*)namelist.Pcur->Pnext;
		}
		// namelist.Pcur points the NameNode which has the information, cpy_idlist.Pcur->studentid




		// store the direction of the node that namelist.Pcur points 
		namelist.Ptemp = namelist.Pcur;


		// namelist.Ptemp points the DepartmentNode including the name
		while (namelist.Ptemp->Pup != NULL)
			namelist.Ptemp = (NameNode*)namelist.Ptemp->Pup;


		// point the nodes linked to that NameNode
		deptlist.Pcur = (DepartmentNode*)namelist.Ptemp;
		gradelist.Pcur = namelist.Pcur->Pleft;
		contactlist.Pcur = namelist.Pcur->Pright;






		// print the results
		cout << deptlist.Pcur->de_name << "/";
		cout << namelist.Pcur->name << "/";
		cout << gradelist.Pcur->grade << "/";
		cout << cpy_idlist.Pcur->studentid << "/";
		cout << contactlist.Pcur->contact << endl;

		log << deptlist.Pcur->de_name << "/";
		log << namelist.Pcur->name << "/";
		log << gradelist.Pcur->grade << "/";
		log << cpy_idlist.Pcur->studentid << "/";
		log << contactlist.Pcur->contact << endl;





		// if Pcur points the last node in cpy_idlist, break
		if (cpy_idlist.Pcur->Pfront == NULL)
			break;


		// Pcur points the next node
		cpy_idlist.Pcur = cpy_idlist.Pcur->Pfront;

	}







	// delete the memory of cpy_idlist 


	cpy_idlist.Pcur = cpy_idlist.Phead->Pfront;

	StudentIDNode* Ppre = cpy_idlist.Phead;


	while (1)
	{
		delete Ppre;

		Ppre = cpy_idlist.Pcur;

		if (cpy_idlist.Pcur->Pfront == NULL)
		{
			delete Ppre;
			break;
		}

		cpy_idlist.Pcur = cpy_idlist.Pcur->Pfront;
	}




	return true;
}



// A funtion to sort contacts in descending order using selection sort 
// and print all information 
bool Manager::PRINT_CONTACT()
{

	contactlist.Pcur = contactlist.Phead;

	// if ContactList is empty
	if (contactlist.Pcur == NULL)
	{
		cout << "error code : 800 " << endl;
		log << "error code : 800" << endl << endl;
		return false;
	}


	// copy the contactlist to cpy_contactlist
	while (1)
	{
		ContactNode* newNode = new ContactNode(contactlist.Pcur->contact);


		// if cpy_contactlist is empty
		if (cpy_contactlist.Phead == NULL)
		{
			// Phead points the new node
			cpy_contactlist.Phead = newNode;

			// Pcur points the new node
			cpy_contactlist.Pcur = cpy_contactlist.Phead;
		}



		else
		{
			// link the new node in cpy_idlist
			cpy_contactlist.Pcur->Pright = newNode;

			// Pcur points the new node
			cpy_contactlist.Pcur = cpy_contactlist.Pcur->Pright;
		}




		// if reaching the last node in contactlist, break
		if (contactlist.Pcur->Pright == NULL)
			break;


		//Pcur points the next node in contactlist
		contactlist.Pcur = contactlist.Pcur->Pright;

	}













	// sort cpy_contactlist in descending order using selection sorting

	// Pcur points the first node
	cpy_contactlist.Pcur = cpy_contactlist.Phead;






	while (cpy_contactlist.Pcur->Pright != NULL)
	{

		ContactNode* Smallest = cpy_contactlist.Pcur;

		// Pwalker points the next node of what cpy_contactlist.Pcur points
		ContactNode* Pwalker = cpy_contactlist.Pcur->Pright;



		while (1)
		{

			// compare strings because they must be sorted in descending order
			if (strcmp(Pwalker->contact, Smallest->contact) == 1)
			{
				Smallest = Pwalker;

			}






			// if Pwalker points the last node
			if (Pwalker->Pright == NULL)
				break;


			// Pwalker points the next node
			Pwalker = Pwalker->Pright;

		}






		// swap the contact stored in Pcur and Smallest
		char tempContact[15] = { 0 };

		strcpy(tempContact, cpy_contactlist.Pcur->contact);
		strcpy(cpy_contactlist.Pcur->contact, Smallest->contact);
		strcpy(Smallest->contact, tempContact);







		// Pcur points the next node
		cpy_contactlist.Pcur = cpy_contactlist.Pcur->Pright;



	}









	// Printing


	// Pcur points the first node in cpy_idlist
	cpy_contactlist.Pcur = cpy_contactlist.Phead;



	while (1)
	{
		namelist.Pcur = namelist.Phead;



		while (strcmp(cpy_contactlist.Pcur->contact, namelist.Pcur->Pright->contact))
		{
			namelist.Pcur = (NameNode*)namelist.Pcur->Pnext;
		}
		// namelist.Pcur points the NameNode which has the information, cpy_contactlist.Pcur->contact




		// store the direction of the node that namelist.Pcur points 
		namelist.Ptemp = namelist.Pcur;


		// namelist.Ptemp points the DepartmentNode including the name
		while (namelist.Ptemp->Pup != NULL)
			namelist.Ptemp = (NameNode*)namelist.Ptemp->Pup;


		// point the nodes linked to that NameNode
		deptlist.Pcur = (DepartmentNode*)namelist.Ptemp;
		gradelist.Pcur = namelist.Pcur->Pleft;
		idlist.Pcur = namelist.Pcur->Pfront;





		// print the results
		cout << deptlist.Pcur->de_name << "/";
		cout << namelist.Pcur->name << "/";
		cout << gradelist.Pcur->grade << "/";
		cout << idlist.Pcur->studentid << "/";
		cout << cpy_contactlist.Pcur->contact << endl;


		log << deptlist.Pcur->de_name << "/";
		log << namelist.Pcur->name << "/";
		log << gradelist.Pcur->grade << "/";
		log << idlist.Pcur->studentid << "/";
		log << cpy_contactlist.Pcur->contact << endl;




		// if Pcur points the last node in cpy_contactlist, break
		if (cpy_contactlist.Pcur->Pright == NULL)
			break;


		// Pcur points the next node
		cpy_contactlist.Pcur = cpy_contactlist.Pcur->Pright;

	}








	// delete the memory of cpy_contactlist 


	cpy_contactlist.Pcur = cpy_contactlist.Phead->Pright;

	ContactNode* Ppre = cpy_contactlist.Phead;


	while (1)
	{
		delete Ppre;

		Ppre = cpy_contactlist.Pcur;

		if (cpy_contactlist.Pcur->Pright == NULL)
		{
			delete Ppre;
			break;
		}
		
		cpy_contactlist.Pcur = cpy_contactlist.Pcur->Pright;
	}








	return true;
}



// A function to find the name and print all information of the student
// OR find names that start with the last name and print them
bool Manager::FIND_NAME(char * commandData1)
{

	// If you enter only the last name, arrange the pointer that stores the names starting with that last name
	char* temp_Name[50] = { 0 };


	namelist.Pcur = namelist.Phead;




	while (1)
	{

		// if commandData1 includes last name
		if (commandData1[2] == 0) {
		
		// if namelist.Pcur->name is same with commandData1, break
			if (!strncmp(namelist.Pcur->name, commandData1, 2))
				break;

		}


		// commandData1 includes the full name
		else {

			// if namelist.Pcur->name is same with commandData1, break
			if (!strcmp(namelist.Pcur->name, commandData1))
				break;

		}


		// if there is no that last name in NameList
		if (namelist.Pcur->Pnext == NULL)
		{
			// print the error code
			cout << "error code : 900 " << endl;
			log << "error code : 900" << endl << endl;
			return false;
		}



		// if it is not same, namelist.pcur points the next node
		namelist.Pcur = (NameNode*)namelist.Pcur->Pnext;

	}







	// if corresponding name is existing
	if (namelist.Pcur->Pnext != NULL)
	{


		// when input the full name, print the all information

		if (commandData1[2] != 0)
		{

			while (1)
			{
				// store the direction of Pcur in Ptemp
				namelist.Ptemp = namelist.Pcur;



				while (namelist.Ptemp->Pup != NULL)
					namelist.Ptemp = (NameNode*)namelist.Ptemp->Pup;
				// namelist.Ptemp points the DepartmentNode that the NameNode is included


				deptlist.Pcur = (DepartmentNode*)namelist.Ptemp;
				// Pcur points the DepartmentNode that the NameNode is included





				// print all the information of the student
				cout << deptlist.Pcur->de_name << "/"
					<< namelist.Pcur->name << "/"
					<< namelist.Pcur->Pleft->grade << "/"
					<< namelist.Pcur->Pfront->studentid << "/"
					<< namelist.Pcur->Pright->contact << endl;

				log << deptlist.Pcur->de_name << "/"
					<< namelist.Pcur->name << "/"
					<< namelist.Pcur->Pleft->grade << "/"
					<< namelist.Pcur->Pfront->studentid << "/"
					<< namelist.Pcur->Pright->contact << endl;





				// to check if there is more same name
				namelist.Pcur = (NameNode*)namelist.Pcur->Pnext;


				// if namelist.Pcur->name is DIFFERENT with commandData1
				if (strcmp(namelist.Pcur->name, commandData1))
					break;


				// if namelist.Pcur->name is SAME with commandData1, repeat the loop

			}
		}


				
		


		// when input the last name

		else
		{
			int i = 0;


			while (1)
			{
				// save a name beginning with the first name to temp_Name
				temp_Name[i]= namelist.Pcur->name;



				// to check if there is more same name
				namelist.Pcur = (NameNode*)namelist.Pcur->Pnext;


				// if namelist.Pcur->name is DIFFERENT with commandData1
				if (strncmp(namelist.Pcur->name, commandData1,2))
					break;



				i++;

			}





			// sort the names in ascending order using bubble sort

			for (int current = 0; current < i; current++)
			{

				for (int walker = i; walker > current; walker--)
				{

					if (strncmp(temp_Name[walker], temp_Name[walker - 1], 2) == -1)
					{
						char temp[50] = { 0 };
						strcpy(temp, temp_Name[walker]);
						strcpy(temp_Name[walker], temp_Name[walker - 1]);
						strcpy(temp_Name[walker - 1], temp);
					}

				}

			}




			// print names beginning with the first name
			for (int j = 0; j < i; j++)
			{
				cout << temp_Name[j] << endl;

				log << temp_Name[j] << endl;
			}



		}

	}
	
	

	



	return true;
}



// A function to make a file named commandData1, and write text on it
bool Manager::SAVE(char * commandData1)
{






	// if there is no parameter
	if (*commandData1 == 0)
	{
		// print the error code
		cout << "error code : 1000" << endl;
		log << "error code : 1000" << endl << endl;
		return false;
	}


	ofstream writeText;

	// make a file named commandData1 and write on it
	writeText.open(commandData1);


	deptlist.Pcur = deptlist.Phead;

	
	while (1)
	{
		//namelist.Pcur points the first node connect to corresponding DepartmentNode
		namelist.Pcur = (NameNode*)deptlist.Pcur->Pdown;

		while (1)
		{
			// write in the file
			writeText << deptlist.Pcur->de_name << "/" 
				<< namelist.Pcur->name << "/" 
				<< namelist.Pcur->Pleft->grade << "/"
				<< namelist.Pcur->Pfront->studentid << "/"
				<< namelist.Pcur->Pright->contact << endl;


			// if it is the last NameNode connected to corresponding DepartmentNode
			if (namelist.Pcur->Pdown == NULL) 
				break;
			

			// Pcur points the next NameNode connected to corresponding DepartmentNode
			namelist.Pcur = (NameNode*)namelist.Pcur->Pdown;
		}

		// deptlist.Pcur points the next DepartmentNode
		deptlist.Pcur = (DepartmentNode*)deptlist.Pcur->Pnext;


		// if deptlist.Pcur points the last node in DepartmentList
		if (deptlist.Pcur == deptlist.Phead)
			break;

	}



	return true;
}



void Manager::EXIT()
{
	exit(100);
}




int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Manager manager;
	manager.getData();

	manager.namelist.name_destructor = true;
	manager.deptlist.dept_destructor = true;



	return 0;

}







