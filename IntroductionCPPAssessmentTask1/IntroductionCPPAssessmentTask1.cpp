// IntroductionCPPAssessmentTask1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyString.h"

int main()
{
    MyString myStringDefault;
    MyString myStringDefault2;
    MyString myStringCustom1 ("Custom1 String");
    MyString myStringCustom2 ("Custom1 String");
    MyString myStringCustom3("Defaultt Consttructtor");
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
    std::cout << std::endl;

    myStringDefault.Prepend(myStringCustom1);

    myStringDefault.WriteToConsole();


    //Testing CStr
    std::cout << std::endl;

    std::cout << myStringDefault.CStr() << std::endl;


    //Testing ToLower
    std::cout << std::endl;

    myStringCopy.ToLower();
    myStringCopy.WriteToConsole();


    //testing ToUpper
    std::cout << std::endl;

    myStringCopy.ToUpper();
    myStringCopy.WriteToConsole();

    //testing find
    std::cout << std::endl;

    
    myStringDefault2.WriteToConsole();


    MyString findCon("Con");

    std::cout << myStringDefault2.Find(findCon) << std::endl;


    //testing replace
    std::cout << std::endl;

    myStringDefault2.Replace("t", "hi");

    myStringDefault2.WriteToConsole();

    
    std::cout << std::endl;

    myStringDefault2.Replace("hi", "t");

    myStringDefault2.WriteToConsole();


    std::cout << std::endl;

    myStringCustom3.Replace("hi", "t");

    myStringCustom3.WriteToConsole();

}
