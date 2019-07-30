#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
class Hostel
{
    char room[4];
    char name[50];
    char roomie_name[50];
    char branch[50];
    char roomie_branch[50];
    char phone[10];
    char roomie_phone[10];
    public:
    void menu();
    void add();
    void display();
    void rooms();
    void edit();
    int check(char*);
    void modify(char*);
    void delete_rec(char*);
};
void Hostel::menu()
{
    int choice;
    while(choice!=5)
    {
        system("cls");
        cout<<"\n\t\t\t\t*************************";
        cout<<"\n\t\t\tAMBER HOSTEL MANAGEMENT SYSTEM";
        cout<<"\n\t\t\t\t      * MAIN MENU *";
        cout<<"\n\t\t\t\t*************************";
        cout<<"\n\n\n\t\t\t1.Book A Room";
        cout<<"\n\t\t\t2.Room Details";
        cout<<"\n\t\t\t3.List of Rooms Allotted";
        cout<<"\n\t\t\t4.Edit Record";
        cout<<"\n\t\t\t5.Exit";
        cout<<"\n\n\t\t\tEnter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            rooms();
            break;
        case 4:
            edit();
            break;
        case 5:
            break;
        default:
            {
                cout<<"\n\n\t\t\tWRONG CHOICE";
                cout<<"\n\t\t\tPress any key to CONTINUE";
                getch();
            }
        }
    }
}
int Hostel::check(char *rno)
{
    int flag=0;
    ifstream fin("amber.dat",ios::in);
    while(!fin.eof())
        {
            fin.read((char*)this,sizeof(Hostel));
            if(strcmp(rno,room))
                {
                    flag=1;
                    break;
                }
        }
    fin.close();
    return(flag);
}
void Hostel::add()
{
    system("cls");
    int flag;
    char rno[4];
    ofstream fout("amber.dat",ios::app);
    cout<<"\n Enter Student Details";
    cout<<"\n ----------------------";
    cout<<"\n\n Room Structure in Amber Hostel: ";
    cout<<"\n Total no. of Rooms - 800";
    cout<<"\n Total no. of Blocks - 4 (A,B,C,D)";
    cout<<"\n ********** BLOCK A **********";
    cout<<"\n Rooms for CSE 2nd Year from A-1 to A-50";
    cout<<"\n Rooms for Mechanical 2nd Year from A-101 to A-150";
    cout<<"\n Rooms for Civil & Chemical 2nd Year from A-201 to A-250";
    cout<<"\n Rooms for CSE DD,MNC,AGP & AGL 2nd Year from A-301 to A-350";
    cout<<"\n ********** BLOCK B **********";
    cout<<"\n Rooms for Electrical 2nd Year from B-1 to B-50";
    cout<<"\n Rooms for Electronics 2nd Year from B-101 to B-150";
    cout<<"\n Rooms for Petroleum 2nd Year from B-201 to B-250";
    cout<<"\n Rooms for Mining,Mineral & MME 2nd Year from B-301 to B-350";
    cout<<"\n ********** BLOCK C **********";
    cout<<"\n Rooms for CSE 3rd Year from C-1 to C-50";
    cout<<"\n Rooms for Mechanical 3rd Year from C-101 to C-150";
    cout<<"\n Rooms for Civil & Chemical 3rd Year from C-201 to C-250";
    cout<<"\n Rooms for CSE DD,MNC,AGP and AGL 3rd Year from C-301 to C-350";
    cout<<"\n ********** BLOCK D **********";
    cout<<"\n Rooms for Electrical 3rd Year from D-1 to D-50";
    cout<<"\n Rooms for Electronics 3rd Year from D-101 to D-150";
    cout<<"\n Rooms for Petroleum 3rd Year from D-201 to D-250";
    cout<<"\n Rooms for Mining,Mineral & MME 3rd Year from D-301 to D-350";
    cout <<"\n\n Enter The room number you want to stay in :- \n";
    cin>>rno;
    flag=check(rno);
    if(flag==0)
    cout<<"\n Sorry!! This room is not available";
    else
    {
        system("cls");
        strcpy(room,rno);
        cout<<"\n Name of Applicant:\t ";
        cin>>name;
        cout<<"\n Name of Room Partner:\t";
        cin>>roomie_name;
        cout<<"\n Your Branch:\t ";
        cin>>branch;
        cout<<"\n Your Roommate's Branch:\t ";
        cin>>roomie_branch;
        cout<<"\n Your Phone No:\t ";
        cin>>phone;
        cout<<"\n Your Roommate's phone No:\t ";
        cin>>roomie_phone;
        cout<<endl;
        fout.write((char*)this,sizeof(Hostel));
        cout<<"\n Your Room is Booked....Welcome to Amber Hostel";
    }
    cout<<"\nPress any key to continue";
    getch();
    fout.close();
}
void Hostel::display()
{
    system("cls");
    ifstream fin("amber.dat",ios::in);
    char rno[4];
    int flag=0;
    cout<<"\nEnter the room number:\n";
    cin>>rno;
    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(Hostel));
        if(strcmp(room,rno))
        {
            system("cls");
            cout<<"\n Room Details";
            cout<<"\n ----------------";
            cout<<"\n\n Room no: "<<room;
            cout<<"\n Name: "<<name;
            cout<<"\n Branch: "<<branch;
            cout<<"\n Phone no: "<<phone;
            cout<<"\n Name: "<<roomie_name;
            cout<<"\n Branch: "<<roomie_branch;
            cout<<"\n Phone no: "<<roomie_phone;
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"\nRoom Number not found or maybe Vacant";
    cout<<"\nPress any key to continue";
    getch();
    fin.close();
}
void Hostel::rooms()
{
    system("cls");
    ifstream fin("amber.dat",ios::in);
    cout<<"\n\t\t\t    List Of Rooms Allotted";
    cout<<"\n\t\t\t    ----------------------";
    cout<<"\n\n Room No.\tName\t\tBranch\t\t\t\tPhone No.\n";
    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(Hostel));
        cout<<"\n\n "<<room<<"\t\t"<<name<<"\t\t"<<branch<<"\t\t"<<phone;
        cout<<"\n\n "<<room<<"\t\t"<<roomie_name<<"\t\t"<<roomie_branch<<"\t\t"<<roomie_phone;
    }
    cout<<"\n\n\n\t\t\tPress any key to continue";
    getch();
    fin.close();
}
void Hostel::edit()
{
    int ch;
    char rno[4];
    system("cls");
    cout<<"\n EDIT MENU";
    cout<<"\n ---------";
    cout<<"\n\n 1.Modify Room Record";
    cout<<"\n 2.Delete Room Record";
    cout<<"\n Enter your choice: ";
    cin>>ch;
    system("cls");
    cout<<"\n Enter Room Number:";
    cin>>rno;
    switch(ch)
    {
    case 1:
        modify(rno);
        break;
    case 2:
        delete_rec(rno);
        break;
    default:
            cout<<"\nWRONG CHOICE";
    }
    cout<<"\n\n\n\t\t\tPress any key to continue";
    getch();
}
void Hostel::modify(char *rno)
{
    long pos,flag=0;
    fstream f("amber.dat",ios::in|ios::out|ios::binary);
    while(!f.eof())
    {
        pos=f.tellg();
        f.read((char*)this,sizeof(Hostel));
        if(strcmp(room,rno))
        {
            system("cls");
            cout<<"\n Name of Applicant:\t ";
            cin>>name;
            cout<<"\n Name of Room Partner:\t";
            cin>>roomie_name;
            cout<<"\n Your Branch:\t ";
            cin>>branch;
            cout<<"\n Your Roommate's Branch:\t ";
            cin>>roomie_branch;
            cout<<"\n Your Phone No:\t ";
            cin>>phone;
            cout<<"\n Your Roommate's phone No:\t ";
            cin>>roomie_phone;
            cout<<endl;
            f.seekg(pos);
            f.write((char*)this,sizeof(Hostel));
            cout<<"\n Record is modified";
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"\nRoom Number not found or maybe Vacant";
    cout<<"\nPress any key to continue";
    getch();
    f.close();
}
void Hostel::delete_rec(char *rno)
{
    int flag=0;
    char ch;
    ifstream fin("amber.dat",ios::in);
    ofstream fout("temp.dat",ios::out);
    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(Hostel));
        if(strcmp(room,rno))
        {
            system("cls");
            cout<<"\n Name: "<<name;
            cout<<"\n Branch: "<<branch;
            cout<<"\n Phone no: "<<phone;
            cout<<"\n Name: "<<roomie_name;
            cout<<"\n Branch: "<<roomie_branch;
            cout<<"\n Phone no: "<<roomie_phone;
            cout<<"\n\n Do you want to delete this record(y/n): ";
            cin>>ch;
            if(ch=='n')
                fout.write((char*)this,sizeof(Hostel));
            flag=1;
        }
        else
            fout.write((char*)this,sizeof(this));
    }
    fin.close();
    fout.close();
    if(flag==0)
        cout<<"\nRoom Number not found or maybe Vacant";
    else
    {
        remove("amber.dat");
        rename("temp.dat","amber.dat");
    }
    cout<<"\nPress any key to continue";
    getch();
}
int main()
{
    Hostel h;
    cout<<"\n\t\t\t****************************";
    cout<<"\n\t\t\t* HOSTEL MANAGEMENT PROJECT *";
    cout<<"\n\t\t\t****************************";
    cout<<"\n\n\t\tDeveloped By:";
    cout<<"\t Swapnil Narayan";
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue";
    getch();
    h.menu();
    return 0;
}
