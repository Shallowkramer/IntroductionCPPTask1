// IntroductionCPPAssessmentTask1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyString.h"

int main()
{
    MyString myStringDefault;
    MyString myStringCustom1 ("Custom1 String");
    MyString myStringCustom2 ("Custom1 String");
    MyString myStringCopy (myStringDefault);

    std::cout << myStringCustom1.CharacterAt(15) << std::endl;

    myStringDefault.WriteToConsole();
    myStringCustom1.WriteToConsole();
    myStringCopy.WriteToConsole();


    if (myStringCustom1.EqualTo(myStringCustom2))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    
    myStringDefault.Prepend(myStringCustom1);

    myStringDefault.WriteToConsole();
}
