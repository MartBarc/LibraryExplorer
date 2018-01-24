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
#include<string.h>

#include "book.h"
#include "user.h"

using namespace std;

book b;
reader r;
admin a;
copyB c;

int main()
{
    char ch;
    bool again=true;

    do
    {
    cout<<"--------------------------------------"<<endl;
    cout<<"-       Welcome to My Library!       -"<<endl;;
    cout<<"--------------------------------------"<<endl;
    cout<<"\t1 -- User Login"<<endl;
    cout<<"\t2 -- Librarian Login"<<endl;
    cout<<"\t3 -- Exit"<<endl;

    cin >> ch;

        switch(ch)
        {
        case '1':
            r.reader_login();
            break;
        case '2':
            a.admin_login();
            break;
        case '3':
            again = false;
            break;
        default:
            break;
        }
    }
    while (again);

    cin.get(); //Prevents shutdown.
    cin.get();
    return 0;
}
