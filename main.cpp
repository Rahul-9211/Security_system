#include <iostream>
#include <fstream>

using namespace std;
void choice();
void change_password();
void access_file();

// Security system
void change_password()
{
    string password , pre_password , file_password;
    cout<<"\n \t\t Enter your Old password : ";
    cin>>pre_password;
    cout<<"\n \t\t Enter your new password : ";
    cin>>password;

    ifstream pass;
    pass.open("password2.txt", ios::in);

    getline(pass, file_password);
    pass.close();

    ofstream file;
    file.open("password2.txt", ios::out);

    if(file_password == "")
    {
        file << password;
        cout<<"\n \t\t Your password has been changes successfully ";
        file.flush();
        file.close();
        choice();
    }
    else if(file_password == pre_password)
    {
        file << password;
        cout<<"\n \t\t Your password has been changes successfully ";
        file.flush();
        file.close();
        choice();
    }
    else
        cout<<"\n \t\t You Entered wrong password ";
        choice();
}

void access_file()
{
    int marks;
    string password , name , id , file_password;
    cout<<"\n \t\t Enter password to access : ";
    cin>>password;

    ifstream file;
    file.open("password2.txt", ios::in);

    getline(file, file_password);
    file.close();

    if(file_password == "")
    {
        cout<<"\n \t\t First set password then access the file ";
        choice();
    }
    else if(password == file_password)
    {
        ifstream data;
        data.open("data.txt", ios::in);
        getline(data,name);
        getline(data,id);
        data >> marks;
        cout<<"\n \t\t Name : "<<name;
        cout<<"\n \t\t ID : "<<id;
        cout<<"\n \t\t Marks : "<<marks;
        data.close();
        choice();
    }
    else
        cout<<"\n \t\t You Entered wrong password ";
        choice();
}

void choice()
{
    int choice;
    cout<<"\n \t *****************************************";
    cout<<"\n \t\t This is security system program";
    cout<<"\n \t\t 1. Enter to change password";
    cout<<"\n \t\t 2. Enter to access file ";
    cout<<"\n \t\t 3. Enter to exit ";
    cout<<"\n \t *****************************************";
    cout<<"\n\n \t\t Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            change_password();
            break;
        case 2:
            access_file();
            break;
        case 3:
            break;
    }
}

int main()
{
    choice();
    return 0;
}
