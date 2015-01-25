/*****************************************************************
 *
 *  NAME: 		Marc Khristian Partoriza
 *
 *  HOMEWORK:           Project 2
 *
 *  CLASS:           	ICS 212
 *
 *  INSTRUCTOR:         Ravi Narayan
 *
 *  DATE:            	Nov 23, 2014
 *
 *  FILE:  	        llist.cpp
 *
 *  DESCRIPTION:       This file runs a user-interface menu, in which
 *                     you can manipulate a record database.
 *
 ****************************************************************/

/************************/
#ifndef RECORD_H
#define RECORD_H
#include "record.h"
#endif

#ifndef LLIST_H
#define LLIST_H
#include "llist.h"
#endif

#ifdef debug
int debugMode = 1;
#else
int debugMode = 0;
#endif

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "debugMode.h"
using namespace std;

/*** PROTOTYPES ***/
void clearInput();
char* getName();
char* getfield();
int getYear();
char* getTelNo();
/************************/

/*****************************************************************
 *
 *  Function name:  	main
 *
 *  DESCRIPTION:        Runs a user-interface menu that allows the user
 *                      to load records on start, add, delete, modify,
 *                      print and/or reverse the record database and
 *   			save at termination. Running with definition
 * 			debug, will run the function in debugmode,
 *			printing additional output.
 *
 *  Parameters:      	void
 *
 *
 *  Return values:      0 : success
 *		        other: Program crash and/or invalid input.
 *
 ****************************************************************/

int main()
{
    /*** Create new list. Adds elements(if any) via readfile() ***/

    llist list("records.txt");
    int choice = 0;

    /*** Record database -- Interactive Menu ***/

    do
    {
        cout << "---------\n";
        cout << "Main Menu (Enter number with desired action)\n";
        cout << "1. Add Record\n";
        cout << "2. Print Record\n";
        cout << "3. Print All Records\n";
        cout << "4. Modify Record\n";
        cout << "5. Delete Record\n";
        cout << "6. Reverse List\n";
        cout << "7. Save and Quit\n";

        cin >> choice;
        clearInput();

        if ( choice == 1 )
        {
        cout << "Adding a record...\n";
	    char * name    = getName();
	    char * address = getfield();
	    int year       = getYear();
	    char * telno   = getTelNo();
            list.addRecord(name , address , year , telno);
	    delete name;
	    delete address;
	    delete telno;
        }

        else if ( choice == 2 )
        {
            char * name = getName();
            list.printRecord(name);
	    delete name;
        }

        else if ( choice == 3 )
        {
   	   /*** Overloaded operator << prints all records in a list ***/

           cout << list;
        }

        else if ( choice == 4 )
        {
	    char * name    = getName();
	    char * address = getfield();
	    char * telno   = getTelNo();
            list.modifyRecord(name , address , telno);
	    delete name;
	    delete address;
	    delete telno;
        }

        else if ( choice == 5 )
        {
	    char * name = getName();
            list.deleteRecord(name);
	    delete name;
        }

        else if ( choice == 6 )
	{
            list.reverse();
	}

    }while( choice != 7 );


    return 0;
}

/*** CLASS LLIST FUNCTIONS ***/

/*****************************************************************
 *
 *  Function name:  	addRecord
 *
 *  DESCRIPTION:        A user-interface funcition: adds a record with the
 *                      following parameter values to the end of the
 *                      records "list."
 *
 *  Parameters:         name - name value for new record
 *                      adress - address value for new record
 *                      birthYear - year value for new record
 *                      telNo - telephone number value for new record
 *
 *  Return values:  	 0 : success
 *		         other : error when creating/adding new record.
 *
 ****************************************************************/

int llist::addRecord (char name[], char address[], int birthYear, char telNo[])
{
    /*** Prints function name and parameters if debugMode is ON ***/

    if(debugMode != 0)
    {
        cout << "Function: addRecord\n";
        cout << "Parameters: \n" << name;
	cout << address << "\n";
	cout << birthYear << "\n";
	cout << telNo << "\n";
    }

    /*** If start is null/list is empty, create record at START ***/

    if(!start)
    {
        struct record * temp1 = new struct record;

	strcpy( temp1->name , name);
	strcpy( temp1->address , address);
	temp1->yearofbirth = birthYear;
	strcpy( temp1->telno , telNo);
        temp1->next = NULL;

        start = temp1;

    }

    else
    {
        struct record * temp1 = start;

        /*** Loop to the end of list and add the new record there ***/

        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }

        temp1->next = new struct record;

	strcpy( (*(temp1->next)).name , name );
        strcpy( (*(temp1->next)).address , address );
        strcpy( (*(temp1->next)).telno , telNo );
	(*(temp1->next)).yearofbirth = birthYear;
        (*(temp1->next)).next = NULL;

    }

    return 0;
}

/*****************************************************************
 *
 *  Function name:  	printRecord
 *
 *  DESCRIPTION:    A user-interface function: prints record(s) with the
 * 		    following name.
 *
 *  Parameters:          name - name value for print
 *
 *  Return values:  	 0 : success
 *		         other : error when finding/printing record.
 *
 ****************************************************************/

int llist::printRecord(char name[])
{
    /*** Prints function name and parameters if debugMode is ON ***/

    if(debugMode != 0)
    {
        cout << "Function: printRecord\n";
        cout << "Parameters: \n" << name << "\n";
    }

    struct record * temp1 = start;
    int found = 0;

    /*** Loop through list, printing matched records ***/

    while(temp1 != NULL)
    {
        if( strcmp(temp1->name, name) == 0 )
        {
            cout << "---------\n";
            cout << temp1->name << "\n";
	    cout << temp1->address << "\n";
            cout << temp1->yearofbirth << "\n";
            cout << temp1->telno << "\n";

            found = 1;
        }
        temp1 = temp1->next;
    }

    if(found == 0)
    {
	cout << name << "was not found\n";
    }

    return 0;
}

/*****************************************************************
 *
 *  Function name:  	modifyRecord
 *
 *  DESCRIPTION:    A user-interface funcition: modifies a record with the following
 *                 		parameter values.
 *
 *  Parameters:      	name - name value for modifying record
 *                      adress - address value for modifying record
 *                      telNo - telephone number value for modifiying record
 *
 *  Return values:  	 0 : success
 *		         other : error when finding/modifying record.
 *
 ****************************************************************/

int llist::modifyRecord (char name[], char address[], char telNo[])
{
    /*** Prints function name and parameters if debugMode is ON ***/

    if(debugMode != 0)
    {
        cout << "Function: modifyRecord\n";
        cout << "Parameters: \n" << name;
	cout << address << "\n";
	cout << telNo << "\n";
    }

    struct record * temp1 = start;
    int found = 0;

    /*** Loop through list, modifying matched records ***/

    while(temp1 != NULL)
    {
        if( strcmp(temp1->name, name) == 0 )
        {
            strcpy(temp1->address, address);
            strcpy(temp1->telno, telNo);
            found = 1;
        }
	temp1 = temp1->next;
    }

    if(found == 0)
    {
        cout << name << "was not found\n";
    }

    return 0;
}

/*****************************************************************
 *
 *  Function name:  	printAll
 *
 *  DESCRIPTION:    A user-interface function: prints all records
 *
 *  Parameters:      	void
 *
 *  Return values:  	 0 : success
 *		     other : error when finding/printing record.
 *
 ****************************************************************/

void llist::printAll()
{
    /*** Prints function name and parameters if debugMode is ON ***/

    if(debugMode != 0)
    {
        cout << "Function: printAllRecords\n";
    }

    struct record * temp1 = start;

    if(!temp1)
    {
        cout << "There is no content in the list\n";
    }

    /*** Loop through list, printing ALL records ***/

    while(temp1 != NULL)
    {
        cout << "---------\n";
        cout << temp1->name << "\n";
        cout << temp1->address << "\n";
        cout << temp1->yearofbirth << "\n";
        cout << temp1->telno << "\n";
	temp1 = temp1->next;
    }
}

/*****************************************************************
 *
 *  Function name:  	deleteRecord
 *
 *  DESCRIPTION:    A user-interface funcition: deletes record(s)
 *                  with the following parameter name value.
 *
 *  Parameters:      	name - name value for deleting record
 *
 *  Return values:  	 0 : success
 *			-1 : error when finding/removing record.
 *
 ****************************************************************/

int llist::deleteRecord(char name[])
{
    /*** Prints function name and parameters if debugMode is ON ***/

    if(debugMode != 0)
    {
        cout << "Function: deleteRecord\n";
        cout << "Parameters: \n" << name << "\n";
    }

    struct record * temp1 = NULL;
    struct record * temp2 = start;
    int found = 0;

    /*** Loop through list, deleting matched records ***/

    while(temp2 != NULL)
    {
        if ( strcmp(temp2->name, name) == 0)
        {
	    /*** If first element in list ***/

	    if(temp1 == NULL)
	    {
	        struct record * temp3 = temp2;
		temp2 = temp2->next;
		start = temp2;
		delete temp3;
		found = 1;
	    }

	    /*** Not first element ***/

	    else
	    {
		struct record * temp3 = temp2;
		temp1->next = temp2->next;
		temp2 = temp1->next;
		found = 1;
		delete temp3;
	    }
	}

	else
        {
	    temp1 = temp2;
	    temp2 = temp2->next;
	}
    }

    if(found == 0)
    {
        cout << name << "was not found\n";
    }

    return 0;
}

/*****************************************************************
 *
 *  Function name:  	reverse
 *
 *  DESCRIPTION:    A user-interface function: reverses the order of the
 *                  record database.
 *
 *  Parameters:      	void
 *
 *  Return values:  	void
 *
 ****************************************************************/

void llist::reverse()
{
    /*** Prints function name if debugMode is ON ***/

    if(debugMode != 0)
    {
        cout << "Function: reverse\n";
    }

    start = reverse(start);
    cout << " List reversed \n";
}

record * llist::reverse(record * head)
{
    if(head->next == NULL)
    {
        return head;
    }
    else
    {
        record * temp = reverse(head->next);
        head->next->next = head;
	head->next = NULL;
        return temp;
    }
}

/*****************************************************************
 *
 *  Function name:      OVERLOADING OPERATOR <<
 *
 *  DESCRIPTION:    Changes the operator << with llist to print all records
 *
 *  Parameters:      os - ostream& to add the outputted information
 *                   list - the list you are printing on
 *
 *  Return values:    ostream&: the totalling output stream.
 *                   other : error when finding/printing record.
 *
 ****************************************************************/

ostream& operator<<(ostream& os, const llist& list)
{
    /*** Prints function name if debugMode is ON ***/

    if(debugMode != 0)
    {
        cout << "Function: printAllRecords\n";
    }

    struct record * temp1 = list.start;

    if(!temp1)
    {
        os << "There is no content in the list\n";
    }

    /*** Loop through list, printing ALL records ***/

    while(temp1 != NULL)
    {
        os << "---------\n";
        os << temp1->name << "\n";
        os << temp1->address << "\n";
        os << temp1->yearofbirth << "\n";
        os << temp1->telno << "\n";
        temp1 = temp1->next;
    }

    return os;
}

/*****************************************************************
 *
 *  Function name:  	writefile
 *
 *  DESCRIPTION:        writes (saves) the current list of records into a
 *                      text file, to be used again by the user at a later
 *                      time. the list deconstructor is called. this function
 *                      is called upon exiting.
 *
 *
 *  Parameters:      	void
 *
 *  Return values:  	 0 : success
 *                   other : error finding/reading file.
 *
 ****************************************************************/

int llist::writefile()
{
    /*** Prints function name and parameters if debugMode is ON ***/

    if(debugMode != 0)
    {
        cout << "Function: writefile\n";
    }

    FILE * file = fopen(filename, "w");
    if(!file)
    {
        cout << "Error opening file";
        return 1;
    }
    struct record * temp1 = start;

    while(temp1 != NULL)
    {
	fprintf(file, ".%s.%s.%d.%s.", temp1->name, temp1->address,
                temp1->yearofbirth, temp1->telno);
	temp1 = temp1->next;
    }

    fclose(file);
    return 0;
}

/*****************************************************************
 *
 *  Function name:  	readfile
 *
 *  DESCRIPTION:        A function that reads a filename and the record
 *                      contents and then adds (loads) the records back
 *                      on the record database. the list constructor is
 *                      called. this function is called  upon starting the program.
 *
 *
 *  Parameters:      	void
 *
 *  Return values:  	 0 : success
 *		     other : error finding/reading file.
 *
 ****************************************************************/

int llist::readfile()
{

    FILE * file = fopen(filename, "r+");
    char currentChar;
    if(!file)
    {
        return 1;
    }

    /*** Prints function name and parameters if debugMode is ON ***/
    if(debugMode != 0)
    {
        cout << "Function: readfile\n";
        cout << "filename: " << filename << "\n";
        cout << "Loading Done\n";
    }

    while( (currentChar = fgetc(file)) != EOF)
    {
        char readName[25], readAddress[80], readBirthYear[25], readTelNo[25];
	int x = 0;

        /*** GET NAME ***/
        while( (currentChar = fgetc(file)) != '.')
        {
            readName[x] = currentChar;
	    x++;
        }
        readName[x] = '\0';

        /*** GET ADDRESS ***/
        x = 0;
        while( (currentChar = fgetc(file)) != '.')
        {
	    readAddress[x] = currentChar;
	    x++;
        }
        readAddress[x] = '\0';

        /*** GET BIRTH YEAR***/
        x = 0;
        while( (currentChar = fgetc(file)) != '.')
        {
            readBirthYear[x] = currentChar;
 	    x++;
        }
	readBirthYear[x] = '\0';
        int readBirthYearInt = (atoi(readBirthYear));

        /*** GET TELEPHONE NUMBER ***/
        x = 0;
        while( (currentChar = fgetc(file)) != '.')
        {
            readTelNo[x] = currentChar;
            x++;
        }
        readTelNo[x] = '\0';

        /*** Take read values and add it to the record database ***/
        addRecord(readName, readAddress, readBirthYearInt, readTelNo);


    }

    fclose(file);

    return 0;
}

/*****************************************************************
 *
 *  Function name:  	cleanup
 *
 *  DESCRIPTION:        frees (deletes) every record on the list. this
 *                      function is called at program termination to avoid
 *                      memory leaks.
 *
 *
 *  Parameters:      	void
 *
 *  Return values:  	void
 *
 ****************************************************************/

void llist::cleanup()
{
    /*** Prints function name if debugMode is ON ***/

    if(debugMode != 0)
    {
        cout << "Function: cleanup\n";
    }

    struct record * temp1 = start;

    while(temp1 != NULL)
    {
        struct record * temp2 = temp1;
        temp1 = temp1->next;
	delete temp2;
    }
    start = NULL;
}

/*****************************************************************
 *
 *  Function name:     llist()
 *
 *  DESCRIPTION:        constructor: creates a new empty list with
 *                      with filename, "default.txt" and loads
 *                      data from said filename.
 *
 *  Parameters:         void
 *
 *  Return values:      void
 *
 ****************************************************************/

llist::llist()
{
    /*** Prints function name if debugMode is ON ***/

    if(debugMode != 0)
    {
        cout << "Function: llist constructor (no parameters)\n";
    }

    start = NULL;
    strcpy(filename,"default.txt");
    readfile();
}

/*****************************************************************
 *
 *  Function name:     llist(char[])
 *
 *  DESCRIPTION:        constructor: creates a new empty list with
 *                      with filename with the given name and loads data from
 *                      said fiename.
 *
 *  Parameters:         name - the name of the filename to store records
 *
 *  Return values:      void
 *
 ****************************************************************/

llist::llist(char name[])
{
    /*** Prints function name if debugMode is ON ***/

    if(debugMode != 0)
    {
        cout << "Function: llist constructor: " << name << "\n";
    }

    start = NULL;
    strcpy(filename,name);
    readfile();
}

/*****************************************************************
 *
 *  Function name:     llist(const llist&)
 *
 *  DESCRIPTION:        copy constructor: creates a new llist with
 *                      same values as another llist (otherList)
 *
 *  Parameters:         otherList - the llst to copy
 *
 *  Return values:      void
 *
 ****************************************************************/

llist::llist(const llist& otherList)
{
    /*** Prints function name if debugMode is ON ***/

    if(debugMode != 0)
    {
        cout << "Function: llist copy constructor: " << "\n";
    }

    start = otherList.start;
    strcpy(filename,otherList.filename);
}

/*****************************************************************
 *
 *  Function name:     ~llist()
 *
 *  DESCRIPTION:        destructor: deallocates the whole llist when
 *                      the llist is gone. then writes it to filename
 *
 *  Parameters:
 *
 *  Return values:      void
 *
 ****************************************************************/

llist::~llist()
{
    /*** Prints function name if debugMode is ON ***/

    if(debugMode != 0)
    {
        cout << "Function: llist destructor \n";
    }

    writefile();
    cleanup();
}
