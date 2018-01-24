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
#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <vector>

using namespace std;

class user
{
public:
    string name;
    string password;
    bool teacher;

    string getName();
    bool getTeacher();

};

class reader : public user
{
public:
    int maxCopies;
    int penalties;
    int bag[10];
    int reserved[10];

    int getMaxCopies();
    int getPenalties();
    int *getBag();
    int *getReserved();

    reader();
    void load_reader(string n,string p, bool tea, int m, int pen, int arr1[],int arr2[]);

    void init_fileR();
    void load_fileR();
    void update_fileR();

    void change_password();
    void show_account();
    void reader_login();
    void reader_menu();
};

class admin : public user
{
public:
    void change_password();
    void show_account();
    void create_reader();
    void add_reader();
    void create_admin();
    void add_admin();
    void admin_login();
    void show_allu();
    void delete_user();
    void admin_menu();
};
#endif // USER_H_INCLUDED
