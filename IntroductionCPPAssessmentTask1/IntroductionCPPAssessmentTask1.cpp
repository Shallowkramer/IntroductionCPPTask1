// IntroductionCPPAssessmentTask1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyString.h"

int main()
{
    MyString myStringDefault;
    MyString myStringCustom ("Custom String");

    myStringDefault.WriteToConsole();
    myStringCustom.WriteToConsole();
}
