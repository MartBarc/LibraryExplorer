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
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string>
#include <vector>

#include "book.h"
#include "user.h"

book updatedBooks[100];

using namespace std;

int book::getISBN()
{
    return ISBN;
}
string book::getTitle()
{
    return title;
}
string book::getAuthor()
{
    return author;
}
int book::getCategory()
{
    return category;
}
string *book::getReserveQ()
{
    return reserveQ;
}
int *book::getCopiesQ()
{
    return copiesQ;
}

book::book()
{
    ISBN=-1;
    title = "NULL";
    author = "NULL";
    category = -1;
    for (int i=0 ; i < 10; i++)
    {
        copiesQ[i]=-1;
        reserveQ[i]="NULL";
    }
}

void book::load_book(int inISBN, string inTitle, string inAuthor,int inCategory,int arr1[], string arr2[])
{
    ISBN= inISBN;
    title = inTitle;
    author = inAuthor;
    category = inCategory;
    for (int i=0; i < 10; i++)
    {
        copiesQ[i]=arr1[i];
        reserveQ[i]=arr2[i];
    }
}

void book::init_fileB()
{
    book temp;
    for (int i; i < 100; i++)
    {
        updatedBooks[i]=temp;
    }
    update_fileB();
}

void book::load_fileB()
{
    book bookTemp;
    string titleRead,authRead;
    int tISBN,tcat;
    int c[10];
    string r[10];
    vector<book> allBooks;
    ifstream in("book.txt");

    if(in.fail())
    {
        cout <<"ERROR: File failed to open"<<endl;
        exit(1);
    }
    while(!in.eof())
    {
        in >> tISBN >> titleRead >> authRead >> tcat;
        in >>c[0]>>c[1]>>c[2]>>c[3]>>c[4]>>c[5]>>c[6]>>c[7]>>c[8]>>c[9];
        in >>r[0]>>r[1]>>r[2]>>r[3]>>r[4]>>r[5]>>r[6]>>r[7]>>r[8]>>r[9];

        bookTemp.load_book(tISBN,titleRead,authRead,tcat,c,r);
        //bookTemp.show_book();
        allBooks.push_back(bookTemp);
    }
    for (int i=0; i<100; i++)
    {
        updatedBooks[i] = allBooks[i];
        //updatedBooks[i].show_book();
    }
    in.close();
}

void book::update_fileB()
{
    book t;
    vector<book> allBooks;
    ofstream in("book.txt");

    if(in.fail())
    {
        cout <<"ERROR: File failed to open"<<endl;
        exit(1);
    }
    for (int i = 0; i < 100; i++)
    {
        t = updatedBooks[i];
        in << t.ISBN<<"\t"<< t.title<<"\t" << t.author<<"\t" <<t.category<<"\n";
        for (int j=0 ; j < 10 ; j++)
        {
            in <<t.copiesQ[j]<<"\t";
        }
        in<<"\n";
        for (int j=0 ; j < 10 ; j++)
        {
            in <<t.reserveQ[j]<<"\t";
        }
        in <<"\n";
        //updatedBooks[i].show_book();
    }
    in.close();
}

void book::show_book()
{
    cout<<"\n\tISBN: "<<ISBN<<endl;
    cout<<"\tTitle: "<<title<<endl;
    cout<<"\tAuthor: "<<author<<endl;
    cout<<"\tCategory: ";
    switch (category)
    {
    case 0:
        cout<<"Unknown"<<endl;
        break;
    case 1:
        cout<<"Comedy"<<endl;
        break;
    case 2:
        cout<<"Romance"<<endl;
        break;
    case 3:
        cout<<"Action"<<endl;
        break;
    case 4:
        cout<<"Horror"<<endl;
        break;
    case 5:
        cout<<"Kids/Todlers"<<endl;
        break;
    case 6:
        cout<<"Educational"<<endl;
        break;
    case 7:
        cout<<"Religious"<<endl;
        break;
    case 8:
        cout<<"News"<<endl;
        break;
    case 9:
        cout<<"Documentary"<<endl;
        break;
    default:
        cout<<"New/Unregistered"<<endl;
        break;
    }
    cout << "ID Numbers: ";
    for (int i=0; i < 10 ; i++)
    {
        if (copiesQ[i]!=0)
        {
            cout << copiesQ[i] << "~";
        }
    }
    cout <<endl;
    cout<< "Who's reserving: ";
    for (int i=0; i < 10 ; i++)
    {
        if (reserveQ[i]!="NULL")
        {
            cout << reserveQ[i] << "<--";
        }
    }
    cout <<endl;
}

void book::show_allb()
{
    char c1;
    bool again=true;
    int numIn;
    string stringIn;

    do
    {
        cout<<"\n=------------------------------------=";
        cout<<"\n\n\t1 -- Search ISBN";
        cout<<"\n\t2 -- Search Title";
        cout<<"\n\t3 -- Search Author";
        cout<<"\n\t4 -- Search Category";
        cout<<"\n\t0 -- Exit\n";

        cin>>c1;

        switch(c1)
        {
        case '1':
            cout<<"Please enter input: ";
            cin >> numIn;
            for (int i =0 ; i < 100; i++)
            {
                if (updatedBooks[i].getISBN()==numIn)
                {
                    updatedBooks[i].show_book();
                }
            }
            break;
        case '2':
            cout<<"Please enter input: ";
            cin >> stringIn;
            for (int i =0 ; i < 100; i++)
            {
                if (updatedBooks[i].getTitle()==stringIn)
                {
                    updatedBooks[i].show_book();
                }
            }
            break;
        case '3':
            cout<<"Please enter input: ";
            cin >> stringIn;
            for (int i =0 ; i < 100; i++)
            {
                if (updatedBooks[i].getAuthor()==stringIn)
                {
                    updatedBooks[i].show_book();
                }
            }
            break;
        case '4':
            cout<<"\tCategory List:\t"<<endl;
            cout<<"\t0 -- Unknown"<<endl;
            cout<<"\t1 -- Comedy"<<endl;
            cout<<"\t2 -- Romance"<<endl;
            cout<<"\t3 -- Action"<<endl;
            cout<<"\t4 -- Horror"<<endl;
            cout<<"\t5 -- Kids/Todlers"<<endl;
            cout<<"\t6 -- Educational"<<endl;
            cout<<"\t7 -- Religious"<<endl;
            cout<<"\t8 -- News"<<endl;
            cout<<"\t9 -- Documentary"<<endl;
            cout<<"\tOther -- New/Unregistered"<<endl;
            cout<<"Please enter input: ";
            cin >> numIn;
            for (int i =0 ; i < 100; i++)
            {
                if (updatedBooks[i].getCategory()==numIn)
                {
                    updatedBooks[i].show_book();
                }
            }
            break;
        case '0':
            again=false;
            break;
        default:
            break;
        }

    }
    while (again);
}

void book::load_bookISBN(int inNum)
{
    for (int i = 0 ; i < 100 ; i++)
    {
        if (inNum == updatedBooks[i].ISBN)
        {
            ISBN = updatedBooks[i].getISBN();
            title =  updatedBooks[i].getTitle();
            author = updatedBooks[i].getAuthor();
            category = updatedBooks[i].getCategory();
            // string *resPoint = updatedBooks[i].getReserveQ();
            //int *copPoint = updatedBooks[i].getCopiesQ();
            //*reserveQ = resPoint;
            //*copiesQ =  copPoint;
        }
    }
}

//***********************************************
//*******************COPY B*******************
copyB updatedCopyB[10000];

copyB::copyB()
{
    ID=-1;
    borrower = "NULL";
    date = -1;
    resDate = -1;
    exDate = -1;
}

void copyB::load_copyB(int inID,string inBorrower,double inDate,double inResDate,double inExDate)
{
    ID=inID;
    borrower = inBorrower;
    date = inDate;
    resDate = inResDate;
    exDate = inExDate;
}

void copyB::init_fileC()
{
    copyB temp;
    for (int i; i < 10000; i++)
    {
        updatedCopyB[i]=temp;
    }
    update_fileC();
}

void copyB::load_fileC()
{
    copyB tp;
    string borrowerRead,titleRead,authRead;;
    int inID,tISBN,tcat;
    double inDate,inResDate,inExDate;

    vector<copyB> allCopyB;
    ifstream in("copy.txt");
    if(in.fail())
    {
        cout <<"ERROR: File failed to open"<<endl;
        exit(1);
    }
    int junkQ1[10];
    string junkQ2[10];
    for (int i=0 ; i < 10; i++)
    {
        junkQ1[i]=-1;
        junkQ2[i]="NULL";
    }
    while(!in.eof())
    {
        in >> tISBN >> titleRead >> authRead >> tcat;
        in >> inID >> borrowerRead >> inDate >> inResDate >> inExDate;
        tp.load_copyB(inID,borrowerRead,inDate,inResDate,inExDate);
        tp.load_book(tISBN,titleRead,authRead,tcat,junkQ1,junkQ2);
        //tp.show_copy();
        allCopyB.push_back(tp);
    }
    for (int i=0; i<100; i++)
    {
        updatedCopyB[i] = allCopyB[i];
    }
    in.close();
}

void copyB::update_fileC()
{
    copyB t;
    vector<copyB> allCopyB;
    ofstream in("copy.txt");

    if(in.fail())
    {
        cout <<"ERROR: File failed to open"<<endl;
        exit(1);
    }
    for (int i = 0; i < 10000; i++)
    {
        t = updatedCopyB[i];
        in << t.ISBN<<"\t"<< t.title<<"\t" << t.author<<"\t" <<t.category<<"\n";
        in << t.ID<<"\t"<< t.borrower<<"\t" << t.date<<"\t" <<t.resDate<<"\t" << t.exDate<<"\n";
        //updatedCopyB[i].show_copy();
    }
    in.close();
}

void copyB::add_copy()
{
    int tNumCop,tISBN,tcat;
    string tTitle,tAuth;

    double TEMP_TIME=0.0;

    cout<<"\n\tEnter ISBN:";
    cin>>tISBN;
    cout<<"\n\tEnter Title:";
    cin>>tTitle;
    cout<<"\n\tEnter Author:";
    cin>>tAuth;
    cout<<"\tCategory List:\t"<<endl;
    cout<<"\t0 -- Unknown"<<endl;
    cout<<"\t1 -- Comedy"<<endl;
    cout<<"\t2 -- Romance"<<endl;
    cout<<"\t3 -- Action"<<endl;
    cout<<"\t4 -- Horror"<<endl;
    cout<<"\t5 -- Kids/Todlers"<<endl;
    cout<<"\t6 -- Educational"<<endl;
    cout<<"\t7 -- Religious"<<endl;
    cout<<"\t8 -- News"<<endl;
    cout<<"\t9 -- Documentary"<<endl;
    cout<<"\tOther -- New/Unregistered"<<endl;
    cout<<"\n\tEnter Category:";
    cin>>tcat;
    cout<<"\n\tEnter Number Of Copies (MAX 10 COPIES):";
    cin>>tNumCop;

    if (tNumCop>=10)
    {
        tNumCop = 10;
    }
    else if (tNumCop <= 0)
    {
        tNumCop = 0;
    }

    copyB temp;
    book temp2;
    int Q1[10],counter=0;
    string Q2[10];
    for (int j=0 ; j < 10; j++)
    {
        Q1[j]=0;
        Q2[j]="NULL";
    }
    for(int i=0; i<10000; i++)
    {
        temp = updatedCopyB[i];
        //cout<<temp.ISBN<<endl;
        //cout<<temp.title<<endl;

        if ((temp.ISBN<0)&&(temp.title=="NULL"))
        {
            string tBorrower = "NULL";
            Q1[counter] = 10000+i;
            updatedCopyB[i].load_book(tISBN,tTitle,tAuth,tcat,Q1,Q2);
            updatedCopyB[i].load_copyB(Q1[counter],tBorrower,TEMP_TIME,TEMP_TIME,TEMP_TIME);
            counter++;
        }
        if (counter>=tNumCop)
        {
            break;
        }
    }

    for(int i=0; i<100; i++)
    {
        temp2 = updatedBooks[i];
        //cout<<temp2.ISBN<<endl;
        //cout<<temp2.title<<endl;
        if ((temp2.ISBN<0)&&(temp2.title=="NULL"))
        {
            updatedBooks[i].load_book(tISBN,tTitle,tAuth,tcat,Q1,Q2);
            break;
        }
    }
    cout<<"\tYour Book Has Been Created!"<<endl;
}

void copyB::borrow_copy(reader InR)
{
    int tMax = InR.getMaxCopies();
    int tPen = InR.getPenalties();
    bool tTeacher = InR.getTeacher();
    int actMax,input;
    bool borrowed = false;

    if (tTeacher == true)
        actMax = 10;
    else
        actMax = 5;

    double inDate=0.0;

    string chReserve[10];
    int chCopies[10];

    if (tPen > 0 )//|| tMax == actMax
    {
        cout << "You have overdue books or loaded, please return them";
    }
    else
    {
        cout<<"Please enter the ISBN: ";
        cin >> input;

        for (int i = 0; i < 100; i++)
        {
            if (input == updatedBooks[i].getISBN()&& borrowed==false)
            {
                cout << "ISBN Found!" <<endl;

                for (int j = 0 ; j < 10 ; j++)
                {
                    chReserve[j] = updatedBooks[i].reserveQ[j];
                    chCopies[j] = updatedBooks[i].copiesQ[j];
                    cout << chCopies[j] <<endl;
                    for (int k=0; k < 10000; k++)
                    {
                        if (chCopies[j]==updatedCopyB[k].ID && chCopies[j] != 0 && borrowed==false)
                        {
                            if (updatedCopyB[k].borrower=="NULL")
                            {
                                cout << "Copy found!" <<endl;
                                updatedCopyB[k].show_copy();
                                updatedCopyB[k].load_copyB(chCopies[j],InR.getName(),
                                                           inDate,inDate,inDate);
                                borrowed = true;
                                cout << "Copy borrowed!" <<endl;
                            }
                            if (borrowed==false)
                            {

                            }

                        }
                        if (borrowed == true)
                        {
                            break;
                        }
                    }
                    if (borrowed == true)
                    {
                        break;
                    }
                }
                if (borrowed == true)
                {
                    break;
                }
                else
                {
                    cout <<"Copy is currently out! You must reserve it!"<<endl;
                }
            }
        }
    }
}

void copyB::return_copy(reader InR)
{
    int tMax = InR.getMaxCopies();
    int tPen = InR.getPenalties();
    bool tTeacher = InR.getTeacher();
    int input;
    bool returned = false;

    double inDate=0.0;

    string chReserve[10];

    cout<<"Please enter the book ID: ";
    cin >> input;

    for (int k=0; k < 10000; k++)
    {
        if (input==updatedCopyB[k].ID)
        {
            if (updatedCopyB[k].borrower!="NULL")
            {
                cout << "Copy found!" <<endl;
                updatedCopyB[k].show_copy();
                string null = "NULL";
                updatedCopyB[k].load_copyB(input,null,inDate,inDate,inDate);
                returned = true;
                cout << "Copy returned!" <<endl;
            }
            else
            {
                cout << "Copy already has been returned!"<<endl;
            }
        }
        if (returned == true)
        {
            break;
        }
    }
}

reader copyB::reserve_copy(reader InR)
{
    reader r = InR;
    int tMax = InR.getMaxCopies();
    int tPen = InR.getPenalties();
    bool tTeacher = InR.getTeacher();
    int readerRList[10];

    int input,BOOKP,COPYP;
    bool emptyCopy = false;

    string chReserve[10];
    int chCopies[10];

    if (tPen > 0 )//|| tMax == actMax
    {
        cout << "You have overdue books or loaded, please return them";
    }
    else
    {
        cout<<"Please enter the ISBN: ";
        cin >> input;

        for (int i = 0; i < 100; i++)
        {
            if (input == updatedBooks[i].getISBN())
            {
                BOOKP = i;
                cout << "ISBN Found!" <<endl;
                for (int j = 0 ; j < 10 ; j++)
                {
                    chReserve[j] = updatedBooks[i].reserveQ[j];
                    chCopies[j] = updatedBooks[i].copiesQ[j];
                    //cout << chCopies[j] <<endl;
                    for (int k=0; k < 10000; k++)
                    {
                        if (chCopies[j]==updatedCopyB[k].ID && chCopies[j] != 0)
                        {
                            if (updatedCopyB[k].borrower=="NULL")
                            {
                                cout << "Copy found!" <<endl;
                                COPYP = k;
                                emptyCopy = true;
                                break;
                            }
                        }
                        if (emptyCopy == true)
                        {
                            break;
                        }
                    }
                }
                bool checkBorrow=false;
                string input2;
                if (emptyCopy == true)
                {
                    cout << "An unborrowed book is already available, do "
                         <<"you want to borrow it instead? Y/N : ";
                    cin >> input2;
                    if (input2 == "Y" || input2 == "y")
                    {
                        borrow_copy(InR);
                        checkBorrow == true;
                    }
                }
                if (checkBorrow == false)
                {
                    string curString;
                    for (int z=0; z < 10; z++)
                    {
                        if (r.reserved[z]<0)
                        {
                            //cout<<z<<endl;
                            //cout<<input<<endl;
                            r.reserved[z] = input;
                            cout<<"Book added to person reservations!"<<endl;
                            break;
                        }

                    }
                    for (int i=0; i < 10; i++)
                    {

                        curString=updatedBooks[BOOKP].reserveQ[i];
                        if (curString == "NULL")
                        {
                            updatedBooks[BOOKP].reserveQ[i]=InR.getName();
                            cout<<"You've been added to book's reservation list!"<<endl;
                            break;
                        }
                    }
                }
            }
        }
    }
    return r;
}

void copyB::cancel_reservation(reader InR)
{
    int input;
    int allRes[10];
    cout<<"\nHere is your reserve list:"<<endl;
    for (int i=0; i < 10; i++)
    {
        allRes[i] = InR.reserved[i];
        if (allRes[i]>0)
        {
            cout << allRes[i] <<endl;
        }
    }
    cout << "Please enter the ISBN of the book reservation to cancel:"<<endl;
    cin >> input;

    for (int i = 0; i < 100; i++)
    {
        if (input == updatedBooks[i].getISBN())
        {
            for (int k=0; k<10; k++)
            {
                if (updatedBooks[i].reserveQ[k]==InR.name)
                {
                    for (int j=0; j<(10-k); j++)
                    {
                        updatedBooks[i].reserveQ[k] = updatedBooks[i].reserveQ[k+1];
                        updatedBooks[i].reserveQ[10] = "NULL";
                        cout<<"Reservation Deleted!"<<endl;
                    }
                }
            }
        }
    }
}

void copyB::delete_copy()
{
    int tISBN;
    bool found=false;

    cout<<"\n\tEnter ISBN:";
    cin>>tISBN;

    copyB temp;
    book temp2;

    for(int i=0; i<10000; i++)
    {
        temp = updatedCopyB[i];
        if ((temp.ISBN==tISBN))
        {
            copyB tempC;
            updatedCopyB[i] = tempC;
            found=true;
        }
    }

    for(int i=0; i<100; i++)
    {
        temp2 = updatedBooks[i];
        if ((temp2.ISBN==tISBN))
        {
            book tempB;
            updatedBooks[i] = tempB;
            found=true;
        }
    }
    if (found==true)
    {
        cout<<"\tBook Has Been Deleted!"<<endl;
    }
    else
    {
        cout<<"\tBook Has NOT Been Found!"<<endl;
    }
}


void copyB::show_copy()
{
    cout << ID <<"\t"<<borrower<<"\t"<<date<<"\t"<<resDate<<"\t"<<exDate<<endl;
    cout <<ISBN<<"\t"<<title<<"\t"<<author<<"\t"<<category<<endl;
    cout <<endl;
}
