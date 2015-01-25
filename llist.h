
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
 *  FILE:               llist.h
 *
 *  DESCRIPTION:       This file contains the class llist that
 *                     holds the values member functions thats
 *                     necessary to the database.
 *
 ****************************************************************/

#include <ostream>

class llist
{
    private:
    record         *start;
    char           filename[16];
    int            readfile();
    int            writefile();
    record *       reverse(record *);
    void           cleanup();

    public:
    llist( );
    llist(char []);
    llist(const llist&);
   ~llist( );
    int addRecord(char[], char[], int, char[]);
    int printRecord(char [ ]);
    int modifyRecord(char[], char[], char[]);
    void printAll();
    int deleteRecord(char []);
    void reverse();
    friend std::ostream& operator<<(std::ostream& os , const llist& list);

};
