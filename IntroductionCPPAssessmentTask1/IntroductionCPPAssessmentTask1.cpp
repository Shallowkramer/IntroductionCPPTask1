// IntroductionCPPAssessmentTask1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyString.h"

int main()
{
    MyString myStringDefault;
    MyString myStringDefault2;
    MyString equalityTest;
    MyString equalityTest2;
    MyString myStringCustom1 ("Custom1 String");
    MyString myStringCustom2 ("Custom1 String");
    MyString myStringCustom3 ("Defaultt Consttructtor");
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


    //testing read from console
    std::cout << std::endl;

    myStringDefault.ReadFromConsole();

    std::cout << std::endl;

    myStringDefault.WriteToConsole();


    //Equality Operator
    std::cout << std::endl;

    if (equalityTest == equalityTest2)
    {
        std::cout << "equal" << std::endl;
    }
    else
    {
        std::cout << "not equal" << std::endl;
    }


    //Inequality Operator
    std::cout << std::endl;

    if (equalityTest != equalityTest2)
    {
        std::cout << "not equal" << std::endl;
    }
    else
    {
        std::cout << "equal" << std::endl;
    }


    //Subscript operator
    std::cout << std::endl;

    std::cout << myStringDefault2[0] << std::endl;

    
    //Assignment Operator
    std::cout << std::endl;

    myStringCustom1 = myStringDefault2;

    myStringCustom1.WriteToConsole();


    //Less Than Operator
    std::cout << std::endl;

    if (equalityTest < myStringCustom3)
    {
        std::cout << "equalityTest comes before myStringCustom3" << std::endl;
    }
    else
    {
        std::cout << "equalityTest does NOT comes before myStringCustom3" << std::endl;
    }
}
