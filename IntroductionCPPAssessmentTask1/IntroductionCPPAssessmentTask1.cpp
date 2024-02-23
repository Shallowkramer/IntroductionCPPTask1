// IntroductionCPPAssessmentTask1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "MyString.h"
using namespace std;

void TestLength();
void TestCharacterAt();
void TestEqualTo();
void TestAppend();
void TestPrepend();
void TestCStr();
void TestToLower();
void TestToUpper();
void TestFindString();
void TestFindStringStartIndex();
void TestReplace();
void TestReadFromConsole();
void TestEqualityOperator();
void TestInequalityOperator();
void TestSubscriptOperator();
void TestAssignementOperator();
void TestLessThanOperator();
void TestPrintSuccessFail(bool input);

MyString PrintDateAndTime();

void TestEverythingMyString();

void WriteToFileTests();

int main()
{
    WriteToFileTests();


}

void TestLength()
{
    MyString myString1;

    TestPrintSuccessFail(myString1.Length() == 19);
}

void TestCharacterAt()
{
    MyString myString1;

    TestPrintSuccessFail(myString1.CharacterAt(0) == 'D');
}

void TestEqualTo()
{
    MyString myString1;
    MyString myStringDefault2;

    TestPrintSuccessFail(myString1.EqualTo(myStringDefault2));
}

void TestAppend()
{
    MyString myString1;
    MyString myString2("D");

    myString1.Append(myString2);

    TestPrintSuccessFail(strcmp(myString1.CStr(), "Default ConstructorD") == 0);
}

void TestPrepend()
{
    MyString myString1;
    MyString myString2("D");

    myString1.Prepend(myString2);

    TestPrintSuccessFail(strcmp(myString1.CStr(), "DDefault Constructor") == 0);
}

void TestCStr()
{
    MyString myString1;

    TestPrintSuccessFail(strcmp(myString1.CStr(), "Default Constructor") == 0);
}

void TestToLower()
{
    MyString myString1;

    myString1.ToLower();

    TestPrintSuccessFail(strcmp(myString1.CStr(), "default constructor") == 0);
}

void TestToUpper()
{
    MyString myString1;

    myString1.ToUpper();

    TestPrintSuccessFail(strcmp(myString1.CStr(), "DEFAULT CONSTRUCTOR") == 0);
}

void TestFindString()
{
    MyString myString1;

    TestPrintSuccessFail(myString1.Find("a") == 3);
}

void TestFindStringStartIndex()
{
    MyString myString1;

    TestPrintSuccessFail(myString1.Find(7, "t") == 12);
}

void TestReplace()
{
    MyString myString1;

    myString1.Replace("t", "hi");

    TestPrintSuccessFail(strcmp(myString1.CStr(), "Defaulhi Conshiruchior") == 0);
}

void TestReadFromConsole()
{
    TestPrintSuccessFail(true);
}

void TestEqualityOperator()
{
    MyString myString1;
    MyString myString2;

    TestPrintSuccessFail(myString1 == myString2);
}

void TestInequalityOperator()
{
    MyString myString1;
    MyString myString2("D");

    TestPrintSuccessFail(myString1 != myString2);
}

void TestSubscriptOperator()
{
    MyString myString1;

    TestPrintSuccessFail(myString1[0] == 'D');
}

void TestAssignementOperator()
{
    MyString myString1;
    MyString myString2("D");

    myString2 = myString1;

    TestPrintSuccessFail(strcmp(myString1.CStr(), myString2.CStr()) == 0);
}

void TestLessThanOperator()
{
    MyString myString1;
    MyString myString2("Default Donstructor");

    TestPrintSuccessFail(myString1 < myString2);
}

void TestPrintSuccessFail(bool input)
{
    if (input)
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Fail" << std::endl;
    }
}

MyString PrintDateAndTime()
{
    struct tm newTime;
    time_t now = time(0);
    localtime_s(&newTime, &now);
    int sec = newTime.tm_sec;
    int minute = newTime.tm_min;
    int hour = newTime.tm_hour;

    int day = newTime.tm_mday;
    int month = 1 + newTime.tm_mon;
    int year = newTime.tm_year + 1900;
    
    //should print "The Date is: (day)/(month)/year The time is: (hour):(minute):(sec)"
    
    //Creates first half of the string which is the date
    MyString newString("The Date is: ");
    MyString stringDay(day);
    MyString stringMonth(month);
    MyString stringYear(year);

    newString.Append(stringDay);
    newString.Append("/");
    newString.Append(stringMonth);
    newString.Append("/");
    newString.Append(stringYear);


    //The Time is:
    MyString stringSec(sec);
    MyString stringMin(minute);
    MyString stringHour(hour);

    newString.Append(" The time is: ");
    newString.Append(stringHour);
    newString.Append(":");
    newString.Append(stringMin);
    newString.Append(":");
    newString.Append(stringSec);

   /* newString.WriteToConsole();

    std::cout << newString.CStr() <<std::endl;*/

    return newString;
}

void TestEverythingMyString()
{
    TestLength();
    TestCharacterAt();
    TestEqualTo();
    TestAppend();
    TestPrepend();
    TestCStr();
    TestToLower();
    TestToUpper();
    TestFindString();
    TestFindStringStartIndex();
    TestReplace();
    TestReadFromConsole();
    TestEqualityOperator();
    TestInequalityOperator();
    TestSubscriptOperator();
    TestAssignementOperator();
    TestLessThanOperator();
}

void WriteToFileTests()
{
    std::fstream tests;

    MyString printDateAndTime(PrintDateAndTime());
    std::cout << printDateAndTime.CStr() << std::endl;


    /*TestEverythingMyString();*/
}
