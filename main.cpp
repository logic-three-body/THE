//Programing:the system of resterant counting

#include <iostream>
#include <string>
#include "menu.h"
#include <sstream>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
    LogIn user;
    user.login();

    user.isGoOn();

    cout<<"\nhello!";

    user.select();



    return 0;
}
