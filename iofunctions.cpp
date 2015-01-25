/*****************************************************************
 *
 *  NAME:               Marc Khristian Partoriza
 *
 *  HOMEWORK:           Project 2
 *
 *  CLASS:              ICS 212
 *
 *  INSTRUCTOR:         Ravi Narayan
 *
 *  DATE:               November 23, 2014
 *
 *  FILE:               iofunctions.cpp
 *
 *  DESCRIPTION:       This file contains the functions to get user
 *                     input for the record values: name, address,
 *                     birthyear, and telephone number. Along with
 *                     clearInput.
 *
 ****************************************************************/

/************************/
#include <iostream>
#include <cstdio>
using namespace std;
void clearInput();
/************************/

/*****************************************************************
 *
 *  Function name:  	getName()
 *
 *  DESCRIPTION:    prompts the user for a name with maximum 25 characters.
 *
 *  Parameters:      	void
 *
 *  Return values:  	 pointer to the users input ( char * )
 *
 ****************************************************************/

char * getName()
{
    cout << "Enter a name (MAX 25 characters): \n";
    cout << ">";

    char * nameInput = new char[25];
    fgets(nameInput, 25, stdin);
    return nameInput;
}

/*****************************************************************
 *
 *  Function name:  	getfield
 *
 *  DESCRIPTION:    prompts the user for an address (maximum 80
 *                  characters, in which he is able to enter multiple
 *                  lines until a '.' is received.
 *
 *  Parameters:      	void
 *
 *  Return values:  	 pointer to the users input ( char * )
 *
 ****************************************************************/

char * getfield()
{
    char * line = new char[81];
    int size = 0;

    cout << "Enter an address (MAX 80 characters)\n";
    cout << "Press 'Enter' for a new line";
    cout << ",and '.' to end :\n";
    cout << ">";

    while ( (size < 79) && (line[size] = getchar()) != '.')
    {
        size++;
    }
    clearInput();
    line[size] = '\0';
    return line;
}

/*****************************************************************
 *
 *  Function name:  	getYear
 *
 *  DESCRIPTION:    prompts the user for an birth year (1-2014)
 *
 *
 *  Parameters:      	void
 *
 *  Return values:  	 pointer to the users input ( int )
 *
 ****************************************************************/

int getYear()
{
    cout << "Enter a birth year \n";
    cout << ">";

    int yearOfBirth;
    cin >> yearOfBirth;
    if ((yearOfBirth < 1) | (yearOfBirth > 2015))
    {
        return 0;
    }
    clearInput();
    return yearOfBirth;
}

/*****************************************************************
 *
 *  Function name:  	getTelNo
 *
 *  DESCRIPTION:    prompts the user for a telephone number with maximum
 *                                15 characters
 *
 *  Parameters:      	void
 *
 *  Return values:  	 pointer to the users input ( char * )
 *
 ****************************************************************/

char * getTelNo()
{
    cout << "Enter a phone number (MAX 25 characters):\n";
    cout << ">";

    char * telNo = new char[15];
    fgets(telNo , 15 , stdin);
    return telNo;
}

/*****************************************************************
 *
 *  Function name:  	clearinput
 *
 *  DESCRIPTION:        Clears the input buffer, used after receiving
 *                      input from user.
 *
 *  Parameters:      	void
 *
 *  Return values:  	void
 *
 *
 ****************************************************************/

void clearInput()
{
    char currentBuffer;
    while((currentBuffer = getchar()) != '\n' && currentBuffer != EOF);
}
