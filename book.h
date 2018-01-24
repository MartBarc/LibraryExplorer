/*-------------------------------------Info------------------------------------
 *	Name:				Date:			Current Version:
 *	Martin Barcelon		12-09-2017		1.1
 *
 *	Email:
 *	martin.barcelon@stonybrook.edu
 *
 *	Student ID:
 *	110250249
 * ------------------------------------Info----------------------------------*/
#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include "user.h"

using namespace std;
class book
{
public:
    string title,author;
    string reserveQ[10];
    int copiesQ[10];
    int numCopies,ISBN,category;

     int getISBN();
     string getTitle();
     string getAuthor();
     int getCategory();
     string *getReserveQ();
     int *getCopiesQ();

    book();
    void load_book(int inISBN, string inTitle, string inAuthor,int inCategory,int arr1[], string arr2[]);

    void init_fileB();
    void load_fileB();
    void update_fileB();

    void show_book();
    void show_allb();
    void load_bookISBN(int inNum);
};

class copyB: public book
{
public:
    int ID;
    double date,resDate,exDate;
    string borrower;

    copyB();
    void load_copyB(int inID,string inBorrower,double inDate,double inResDate,double inExDate);

    void init_fileC();
    void load_fileC();
    void update_fileC();

    void add_copy();
    void borrow_copy(reader InR);
    void return_copy(reader InR);
    reader reserve_copy(reader InR);
    void cancel_reservation(reader InR);
    void delete_copy();
    void show_copy();

};

#endif // BOOK_H_INCLUDED
