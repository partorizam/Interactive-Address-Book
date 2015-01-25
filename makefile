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
 *  FILE:               record.h
 *
 *  DESCRIPTION:       This file contains the struct record that
 *                     holds the values for necessary to the data
 *                     base.
 ****************************************************************/


struct record
{
    char              name[25];
    char              address[80];
    int               yearofbirth;
    char              telno[15];
    struct record*     next;
};
