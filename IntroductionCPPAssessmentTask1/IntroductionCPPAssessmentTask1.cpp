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


    //Testing CharacterAt
    std::cout << myStringCustom1.CharacterAt(15) << std::endl;


    //Testing Write To Console
    myStringDefault.WriteToConsole();
    myStringCustom1.WriteToConsole();
    myStringCopy.WriteToConsole();


    //Testing EqualTo
    if (myStringCustom1.EqualTo(myStringCustom2))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    

    //Testing Prepend
    myStringDefault.Prepend(myStringCustom1);

    myStringDefault.WriteToConsole();


    //Testing CStr
    std::cout << myStringDefault.CStr() << std::endl;


    //Testing ToLower
    myStringCopy.ToLower();
    myStringCopy.WriteToConsole();


    //testing ToUpper
    myStringCopy.ToUpper();
    myStringCopy.WriteToConsole();
}
