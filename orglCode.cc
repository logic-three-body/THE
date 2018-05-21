//orgCode.cpp
#include "menu.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#define ESYS "Employee System"
#define MSYS "Master System"
#define ETITLE "====================================菜单===================================="
#define FOOT "============================================================================"
#define MTITLE "==================================店铺及员工管理=================================="

using namespace std;

//=======================================================logIn

void LogIn::isGoOn()
{
    if(tValue == 0)
        exit(0);
}

void LogIn::login()
{
    int t = 3;
    string userN,passW;
    HANDLE tOut;
    tOut = GetStdHandle(STD_OUTPUT_HANDLE);

    while(t>0)
    {
        SetConsoleTextAttribute(tOut,07);
        cout<<"\n\nYou have "<<t<<" chances to login.";
        cout<<"\n\tUsername  :  ";
        cin>>userN;
        cout<<"\n\tPassword  :  ";
        cin>>passW;
        if("master" == userN && "666666" == passW)
        {
            SetConsoleTextAttribute(tOut,FOREGROUND_GREEN|0X8);
            cout<<"\n\n\t\tLog in...";
            symbol = "master";
            Sleep(5*1000);
            system("cls");
            break;
        }
        else if("20189999" == userN && "private" == passW)
        {
            SetConsoleTextAttribute(tOut,FOREGROUND_GREEN|0X8);
            cout<<"\n\n\t\tLog in...";
            symbol = "employee";
            Sleep(3*1000);
            system("cls");
            break;
        }
        SetConsoleTextAttribute(tOut,FOREGROUND_RED|0X8);
        cout<<"The Username or the Passeord  is WRONG !!!\n\n";
        t--;
        tValue = t;
    }
}

void LogIn::select()
{
    if(symbol == "master")
    {
        //the master's system
        cout<<"master";
    }
    else if(symbol == "employee")
    {
        //the employees' system

        Employee A;//TIPS : If you want to use the classB's function in the classA , you could make a object to use it.
        A.theEmployeeSystem();
    }
}

//=======================================================The employees' system

COORD pos = {0,0};//define the begin pos


void Employee::showTheMenu(HANDLE hOut,string *types,int Size,int thisIndex){

    int i;
    system("cls");

    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|0x8);//get the 'TITLE'
    pos.X = 5;
    pos.Y = 2;
    SetConsoleCursorPosition(hOut,pos);//set the position of the 'TITLE'
    cout<<ETITLE;

    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|0x8);
    pos.X = 5;
    pos.Y = 17;
    SetConsoleCursorPosition(hOut,pos);
    cout<<FOOT;
//=======================================================================
    for(i=0 ; i<=Size ; i+=2){
        if(i == thisIndex){
            SetConsoleTextAttribute(hOut,FOREGROUND_RED|0x8);
            if(i>=0&&i<10){
                pos.X = 5;
                pos.Y = 5+i;
            }
            if(i >= 10&&i<20){
                pos.X = 35;
                pos.Y = i-5;
            }
            if(i>=20&&i<30){
                pos.X = 65;
                pos.Y = i-15;
            }
            SetConsoleCursorPosition(hOut,pos);
            cout<<"=>"<<types[i];
        }
        else{
            SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|0x8);
            if(i>=0&&i<10){
                pos.X = 5;
                pos.Y = 5+i;
            }
            if(i >= 10&&i<20){
                pos.X = 35;
                pos.Y = i-5;
            }
            if(i>=20&&i<30){
                pos.X = 65;
                pos.Y = i-15;
            }
            SetConsoleCursorPosition(hOut,pos);
            cout<<types[i];
        }
    }
//========================================================================
    fflush(stdout);//Why not use the system("cls")?
                   //because it's



}

int Employee::selectMenu(int Size ,int *thisIndex){
    int ch;
    ch = getch();
    switch(ch){
        case UP: if(*thisIndex>0) *thisIndex -= 2;break;
        case DOWN: if(*thisIndex<Size -2) *thisIndex += 2; break;
        case LEFT:if(*thisIndex>=10) *thisIndex -= 10;break;
        case RIGHT:if(*thisIndex<20) *thisIndex += 10;break;
        case SPACE:break;
        case ENTER:break;
        case ESC:break;
//Idea : to make a effect of rebacking
    }
}
//void Employee::inputValue(int sele){
//
//
//
//}
//void Employee::showAndPrintTheReceipt(){
//
//
//
//}

CONSOLE_CURSOR_INFO fff;//flashCursor

void Employee::theEmployeeSystem(){
    int sele;
    int thisIndex = 0;
    int Size = 30;
    HANDLE hOut;
    SetConsoleTitle(ESYS);//change this title

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);//get the std Handle

    GetConsoleCursorInfo(hOut,&fff);//get cursor

    fff.bVisible = 0;//set this cursor disappear

    SetConsoleCursorInfo(hOut,&fff);//set cursor

    while(true){
        showTheMenu(hOut,types,Size,thisIndex);
        sele = selectMenu(Size, &thisIndex);
//        if(sele == ESC){
//            break;
//        }
//I want to left this position to the setting of 'rebacking' , it's could be intresting :-)
        if(sele == ENTER){
            switch(thisIndex){
                case 0:break;
                case 2:break;
                case 4:break;
                case 6:break;
                case 8:break;
                case 10:break;
                case 12:break;
                case 14:break;
                case 16:break;
                case 18:break;
            }
        }
        //inputValue(sele);
    }
}












