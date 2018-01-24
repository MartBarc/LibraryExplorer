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
#include <vector>

#include "book.h"
#include "user.h"

using namespace std;


//USER STUFF
reader updatedReaders[50];
int dataLoc;

string user::getName()
{
    return name;
}

bool user::getTeacher()
{
    return teacher;
}

//READER STUFF
int reader::getMaxCopies()
{
    return maxCopies;
}
int reader::getPenalties()
{
    return penalties;
}
int *reader::getBag()
{
    return bag;
}
int *reader::getReserved()
{
    return reserved;
}

reader::reader()
{
    name = "NULL";
    password = "NULL";
    maxCopies = 10;
    penalties = 0;
    teacher = false;
    for (int i=0; i < 10 ; i++)
    {
        bag[i] = -1;
        reserved[i] = -1;
    }
}

void reader::load_reader(string n,string p, bool tea, int m, int pen, int arr1[],int arr2[])
{
    name = n;
    password = p;
    teacher = tea;
    maxCopies = m;
    penalties = pen;
    for (int i=0; i <= 9 ; i++)
    {
        bag[i] = arr1[i];
        reserved[i] = arr2[i];
    }
}

void reader::init_fileR()
{
    reader temp;
    for (int i; i < 50; i++)
    {
        updatedReaders[i]=temp;
    }
    update_fileR();
}

void reader::load_fileR()
{
    reader readerTemp;
    string nRead,pRead;
    int mRead,penRead;
    bool teaRead;
    int c[10];
    int r[10];
    vector<reader> allReaders;
    ifstream in("reader.txt");

    if(in.fail())
    {
        cout <<"ERROR: File failed to open"<<endl;
        exit(1);
    }
    while(!in.eof())
    {
        in >> nRead >> pRead >> teaRead >> mRead >> penRead;
        in >>c[0]>>c[1]>>c[2]>>c[3]>>c[4]>>c[5]>>c[6]>>c[7]>>c[8]>>c[9];
        in >>r[0]>>r[1]>>r[2]>>r[3]>>r[4]>>r[5]>>r[6]>>r[7]>>r[8]>>r[9];

        readerTemp.load_reader(nRead,pRead,teaRead,mRead,penRead,c,r);
        //readerTemp.show_account();
        allReaders.push_back(readerTemp);
    }
    for (int i=0; i<50; i++)
    {
        updatedReaders[i] = allReaders[i];
    }
    in.close();
}

void reader::update_fileR()
{
    reader t;
    vector<reader> allReaders;
    ofstream in("reader.txt");

    if(in.fail())
    {
        cout <<"ERROR: File failed to open"<<endl;
        exit(1);
    }
    for (int i = 0; i < 50; i++)
    {
        t = updatedReaders[i];
        in << t.name<<"\t"<< t.password<<"\t" << t.teacher<<"\t" <<t.maxCopies<<"\t" << t.penalties<<"\n";
        in <<t.bag[0]<<"\t"<<bag[1]<<"\t"<<bag[2]<<"\t"<<bag[3]<<"\t"<<bag[4]<<"\t"<<bag[5]<<
           "\t"<<bag[6]<<"\t"<<bag[7]<<"\t"<<bag[8]<<"\t"<<bag[9]<<"\n";
        in <<t.reserved[0]<<"\t"<<t.reserved[1]<<"\t"<<t.reserved[2]<<"\t"<<t.reserved[3]<<"\t"
           <<t.reserved[4]<<"\t"<<t.reserved[5]<<"\t"<<t.reserved[6]<<"\t"<<t.reserved[7]<<"\t"
           <<t.reserved[8]<<"\t"<<t.reserved[9]<<"\n";
        //updatedReaders[i].show_account();
    }
    in.close();
}

void reader::change_password()
{
    string newP;
    cout<<"Please enter your new password: ";
    cin >> newP;

    password = newP;
}

void reader::show_account()
{
    if (teacher)
    {
        cout<<"\nTeacher: "<<endl;
    }
    else
    {
        cout<<"\nStudent: "<<endl;
    }
    cout<<"\n\tName: "<<name<<endl;
    cout<<"\tPassword: "<<password<<endl;
    cout<<"\nPenalties: "<<penalties<<endl;
    for (int i = 0; i < 10 ; i++)
    {
        if (reserved[i]>0)
        {
            cout<<reserved[i]<<"\t";
        }
    }

}


void reader::reader_login()
{
    string n,p;
    int flag=0;

    cout<<"\tEnter The User Name: \n";
    cin>>n;
    cout<<"\tEnter The Password: \n";
    cin>>p;;

    if (n == "NULL")
    {
        cout << "Nice try."<<endl;
    }
    else
    {
        load_fileR();
        for (int i=0; i < 50; i++)
        {
            string tname=updatedReaders[i].getName();
            string tpassword=updatedReaders[i].password;

            //cout<<tname<<endl;
            //cout<<tpassword<<endl;

            if(tname==n&&tpassword==p)
            {
                //cout<<tname<<endl;
                flag=1;
                name = updatedReaders[i].getName();
                password = updatedReaders[i].password;
                teacher = updatedReaders[i].teacher;
                maxCopies = updatedReaders[i].maxCopies;
                penalties = updatedReaders[i].penalties;
                dataLoc = i;
                for (int j=0; j < maxCopies; j++)
                {
                    bag[j] = updatedReaders[i].bag[j];
                    reserved[j] =  updatedReaders[i].reserved[j];
                }
                break;
            }
        }
    }
    if(flag == 1)
    {
        reader_menu();
    }
    else
    {
        cout<<"\tWrong User Name or Password\n";
    }
}


void reader::reader_menu()
{
    char c1;
    bool again=true;

    do
    {
        book b;
        copyB c;
        cout<<"\n=------------------------------------=";
        cout<<"\n\t    ";
        if (teacher == true)
        {
            cout<<"Teacher"<<endl;
        }
        else
        {
            cout<<"Student"<<endl;
        }
        cout<<"=------------------------------------=\n";
        cout<<"\n\n\t1 -- Search Books";
        cout<<"\n\t2 -- Borrow Books";
        cout<<"\n\t3 -- Return Books";
        cout<<"\n\t4 -- Reserve Books";
        cout<<"\n\t5 -- Cancel Reservations";
        cout<<"\n\t6 -- My Information";
        cout<<"\n\t7 -- Change Password";
        cout<<"\n\t0 -- LogOut\n";

        cin >> c1;

        switch(c1)
        {
        case '1':
            load_fileR();
            b.show_allb();
            update_fileR();
            break;
        case '2':
            load_fileR();
            b.load_fileB();
            c.load_fileC();
            c.borrow_copy(updatedReaders[dataLoc]);
            b.update_fileB();
            c.update_fileC();
            update_fileR();
            break;
        case '3':
            load_fileR();
            c.return_copy(updatedReaders[dataLoc]);
            update_fileR();
            break;
        case '4':
            load_fileR();
            b.load_fileB();
            c.load_fileC();
            updatedReaders[dataLoc]=c.reserve_copy(updatedReaders[dataLoc]);
            b.update_fileB();
            c.update_fileC();
            update_fileR();
            break;
        case '5':
            load_fileR();
            b.load_fileB();
            c.load_fileC();
            c.cancel_reservation(updatedReaders[dataLoc]);
            b.update_fileB();
            c.update_fileC();
            update_fileR();
            break;
        case '6':
            load_fileR();
            show_account();
            update_fileR();
            break;
        case '7':
            load_fileR();
            change_password();
            update_fileR();
            break;
        case '0':
            update_fileR();
            again=false;
            break;
        default:
            break;
        }
    }
    while (again);
}

//***************************************************
//*****************ADMIN STUFF***********************
void admin::change_password()
{
    string tPassword;
    cout<<"\n\tEnter New Password:";
    cin>>tPassword;

    ofstream out("librarian.txt");
    if(out.fail())
    {
        cout <<"ERROR: File failed to open"<<endl;
        exit(1);
    }
    out << name << tPassword;

    cout<<"Your Account Has Been Changed!";
    out.close();
}

void admin::show_account()
{
    cout<<"\n\tName: "<<name<<endl;
    cout<<"\tPassword: "<<password<<endl;
}

void admin::create_reader()
{
    cout<<"\n\tEnter User Name:";
    cin>>name;
    cout<<"\n\tEnter Password:";
    cin>>password;
}

void admin::add_reader()
{
    int tcopies[10],treserved[10];
    string tName,tPassword;
    char inTeach;
    bool tTeacher=false;
    cout<<"\n\tEnter User Name:";
    cin>>tName;
    cout<<"\n\tEnter Password:";
    cin>>tPassword;
    cout<<"\n\tTeacher? Y/N: ";
    cin>>inTeach;
    if (inTeach=='Y'||inTeach=='y')
    {
        tTeacher=true;
    }

    reader temp;
    for(int i=0; i<50; i++)
    {
        temp = updatedReaders[i];
        if ((temp.name=="NULL")&&(temp.password=="NULL"))
        {
            if (tTeacher==true)
            {
                for (int j=0; j<10; j++)
                {
                    tcopies[j]=-1;
                    treserved[j]=-1;
                }
                cout <<tName<< " and " <<tPassword<<" has been added!"<<endl;
                updatedReaders[i].load_reader(tName,tPassword,tTeacher,0,0,tcopies,treserved);
                break;
            }
            else
            {
                for (int j=0; j<10; j++)
                {
                    tcopies[j]=-1;
                    treserved[j]=-1;
                }
                cout <<tName<< " and " <<tPassword<<" has been added!"<<endl;
                updatedReaders[i].load_reader(tName,tPassword,tTeacher,0,0,tcopies,treserved);
                break;
            }
            cout<<"\tYour Account Has Been Created"<<endl;;
        }
    }
}

void admin::create_admin()
{
    cout<<"\n\tEnter User Name:";
    cin>>name;
    cout<<"\n\tEnter Password:";
    cin>>password;
}

void admin::add_admin()
{
    string tName,tPassword;

    cout<<"\n\tEnter User Name:";
    cin>>tName;
    cout<<"\n\tEnter Password:";
    cin>>tPassword;

    ofstream out("librarian.txt");
    if(out.fail())
    {
        cout <<"ERROR: File failed to open"<<endl;
        exit(1);
    }
    out << tName << tPassword;

    cout<<"Your Account Has Been Created";
}

void admin::admin_login()
{
    string n,p,nRead,pRead;
    int flag=0;
    ifstream in("librarian.txt");

    cout<<"\n\n\tEnter The User Name: ";
    cin>>n;
    cout<<"\n\n\tEnter The Password: ";
    cin>>p;

    if(in.fail())
    {
        cout <<"ERROR: File failed to open"<<endl;
        exit(1);
    }

    while(!in.eof())
    {
        in >> nRead >> pRead;
        if((n==nRead)&&(p==pRead))
        {
            flag = 1;
            cout<<"\n\tWELCOME  "<<nRead;
            name = nRead;
            password = pRead;
        }
    }
    in.close();
    if(flag==1)
    {
        admin_menu();
    }
    else
    {
        cout<<"\tWrong User Name or Password\n";
    }
}

void admin::show_allu()
{
    string input;
    cout<<"Please enter username: ";
    cin >> input;
    for (int i = 0; i < 50 ; i++)
    {
        if (updatedReaders[i].getName()==input)
        {
            updatedReaders[i].show_account();
            break;
        }
    }
}

void admin::delete_user()
{
    string tName;

    cout<<"\n\tEnter Account Name:";
    cin>>tName;

    reader temp;
    for(int i=0; i<50; i++)
    {
        temp = updatedReaders[i];
        //cout<<temp.getName()<<endl;

        if (temp.getName()==tName)
        {
            reader temp2;
            updatedReaders[i] = temp2;
        }
    }
    cout<<"\tAccount Has Been Deleted!"<<endl;
}

void admin::admin_menu()
{
    book b;
    reader r;
    copyB c;
    char c1;
    bool again=true;
    char RESET='N';

    do
    {
        cout<<"\n\n\t*****************";
        cout<<"\n\t  Librarian Menu";
        cout<<"\n\t*****************"<<endl;
        cout<<"\n\t1.Search Books";
        cout<<"\n\t2.Add Book";
        cout<<"\n\t3.Delete Book";
        cout<<"\n\t4.Search Users";
        cout<<"\n\t5.Add User";
        cout<<"\n\t6.Delete User";
        cout<<"\n\t7.My Information";
        cout<<"\n\t8.Change Password";
        cout<<"\n\t9.Reset All Data\n";
        cout<<"\n\t0.LogOut";
        cout<<"\n\n\tEnter Your Choice: \n";
        cin >> c1;
        switch(c1)
        {
        case '1':
            b.load_fileB();
            b.show_allb();
            b.update_fileB();
            break;
        case '2':
            b.load_fileB();
            c.load_fileC();
            c.add_copy();
            b.update_fileB();
            c.update_fileC();
            break;
        case '3':
            b.load_fileB();
            c.load_fileC();
            c.delete_copy();
            b.update_fileB();
            c.update_fileC();
            break;
        case '4':
            r.load_fileR();
            show_allu();
            r.update_fileR();
            break;
        case '5':
            r.load_fileR();
            add_reader();
            r.update_fileR();
            break;
        case '6':
            r.load_fileR();
            delete_user();
            r.update_fileR();
            break;
        case '7':
            r.load_fileR();
            show_account();
            r.update_fileR();
            break;
        case '8':
            change_password();
            break;
        case '9':
            cout <<"\tARE YOU SURE? Y/N\t";
            cin>> RESET;
            if (RESET == 'Y'||RESET== 'y')
            {
                c.init_fileC();
                r.init_fileR();
                b.init_fileB();
            }
            break;
        case '0':
            r.update_fileR();
            again = false;
            break;
        default:
            break;
        }
    }
    while (again);
}
