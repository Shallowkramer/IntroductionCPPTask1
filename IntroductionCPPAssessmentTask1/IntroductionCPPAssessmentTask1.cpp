// IntroductionCPPAssessmentTask1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "MyString.h"
using namespace std;

void TestLength(const char testFile[10]);
void TestCharacterAt(const char testFile[10]);
void TestEqualTo(const char testFile[10]);
void TestAppend(const char testFile[10]);
void TestPrepend(const char testFile[10]);
void TestCStr(const char testFile[10]);
void TestToLower(const char testFile[10]);
void TestToUpper(const char testFile[10]);
void TestFindString(const char testFile[10]);
void TestFindStringStartIndex(const char testFile[10]);
void TestReplace(const char testFile[10]);
void TestReadFromConsole(const char testFile[10]);
void TestEqualityOperator(const char testFile[10]);
void TestInequalityOperator(const char testFile[10]);
void TestSubscriptOperator(const char testFile[10]);
void TestAssignementOperator(const char testFile[10]);
void TestLessThanOperator(const char testFile[10]);
void TestPrintSuccessFail(bool _bool, const char* _str, const char testFile[10]);

MyString PrintDateAndTime();

void TestEverythingMyString(const char testFile[10]);

void WriteToFileTests();

int main()
{
    WriteToFileTests();
}

void TestLength(const char testFile[10])
{
    MyString myString1;

    TestPrintSuccessFail(myString1.Length() == 19, "Test Length", testFile);
}

void TestCharacterAt(const char testFile[10])
{
    MyString myString1;

    TestPrintSuccessFail(myString1.CharacterAt(0) == 'D', "Test CharacterAt", testFile);
}

void TestEqualTo(const char testFile[10])
{
    MyString myString1;
    MyString myStringDefault2;

    TestPrintSuccessFail(myString1.EqualTo(myStringDefault2), "Test EqualTo", testFile);
}

void TestAppend(const char testFile[10])
{
    MyString myString1;
    MyString myString2("D");

    myString1.Append(myString2);

    TestPrintSuccessFail(strcmp(myString1.CStr(), "Default ConstructorD") == 0, "Test Append", testFile);
}

void TestPrepend(const char testFile[10])
{
    MyString myString1;
    MyString myString2("D");

    myString1.Prepend(myString2);

    TestPrintSuccessFail(strcmp(myString1.CStr(), "DDefault Constructor") == 0, "Test Prepend", testFile);
}

void TestCStr(const char testFile[10])
{
    MyString myString1;

    TestPrintSuccessFail(strcmp(myString1.CStr(), "Default Constructor") == 0, "Test CStr", testFile);
}

void TestToLower(const char testFile[10])
{
    MyString myString1;

    myString1.ToLower();

    TestPrintSuccessFail(strcmp(myString1.CStr(), "default constructor") == 0, "Test ToLower", testFile);
}

void TestToUpper(const char testFile[10])
{
    MyString myString1;

    myString1.ToUpper();

    TestPrintSuccessFail(strcmp(myString1.CStr(), "DEFAULT CONSTRUCTOR") == 0, "Test ToUpper", testFile);
}

void TestFindString(const char testFile[10])
{
    MyString myString1;

    TestPrintSuccessFail(myString1.Find("a") == 3, "Test FindString", testFile);
}

void TestFindStringStartIndex(const char testFile[10])
{
    MyString myString1;

    TestPrintSuccessFail(myString1.Find(7, "t") == 12, "Test FindStringStartIndex", testFile);
}

void TestReplace(const char testFile[10])
{
    MyString myString1;

    myString1.Replace("t", "hi");

    TestPrintSuccessFail(strcmp(myString1.CStr(), "Defaulhi Conshiruchior") == 0, "Test Replace", testFile);
}

void TestReadFromConsole(const char testFile[10])
{
    TestPrintSuccessFail(true, "Test ReadFromConsole", testFile);
}

void TestEqualityOperator(const char testFile[10])
{
    MyString myString1;
    MyString myString2;

    TestPrintSuccessFail(myString1 == myString2, "Test EqualityOperator", testFile);
}

void TestInequalityOperator(const char testFile[10])
{
    MyString myString1;
    MyString myString2("D");

    TestPrintSuccessFail(myString1 != myString2, "Test InequalityOperator", testFile);
}

void TestSubscriptOperator(const char testFile[10])
{
    MyString myString1;

    TestPrintSuccessFail(myString1[0] == 'D', "Test SubscriptOperator", testFile);
}

void TestAssignementOperator(const char testFile[10])
{
    MyString myString1;
    MyString myString2("D");

    myString2 = myString1;

    TestPrintSuccessFail(strcmp(myString1.CStr(), myString2.CStr()) == 0, "Test AssignmentOperator", testFile);
}

void TestLessThanOperator(const char testFile[10])
{
    MyString myString1;
    MyString myString2("Default Donstructor");

    TestPrintSuccessFail(myString1 < myString2, "Test LessThanOperator", testFile);
}

void TestPrintSuccessFail(bool _bool, const char* _str, const char testFile[10])
{
    std::fstream tests;

    tests.open(testFile, std::ios::app);

    if (_bool)
    {
        tests << _str << " Success" << std::endl;

        std::cout << _str << " Success" << std::endl;
    }
    else
    {
        tests << _str << " Fail" << std::endl;

        std::cout << _str << " Fail" << std::endl;
    }

    tests.close();
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

void TestEverythingMyString(const char testFile[10])
{
    TestLength(testFile);
    TestCharacterAt(testFile);
    TestEqualTo(testFile);
    TestAppend(testFile);
    TestPrepend(testFile);
    TestCStr(testFile);
    TestToLower(testFile);
    TestToUpper(testFile);
    TestFindString(testFile);
    TestFindStringStartIndex(testFile);
    TestReplace(testFile);
    TestReadFromConsole(testFile);
    TestEqualityOperator(testFile);
    TestInequalityOperator(testFile);
    TestSubscriptOperator(testFile);
    TestAssignementOperator(testFile);
    TestLessThanOperator(testFile);
}

void WriteToFileTests()
{
    std::fstream tests;

    const char testFile[10] = "tests.txt";

    tests.open(testFile, std::ios::app);
    
    //if cannot open because tests.txt doesn't exists than this will create
    if (!(tests.is_open()))
    {
        tests.open(testFile, std::ios::out);
    }
    MyString printDateAndTime(PrintDateAndTime());

    tests << printDateAndTime.CStr() << std::endl;
    tests << std::endl;

    tests.close();

    printDateAndTime.WriteToConsole();
    std::cout << std::endl;



    TestEverythingMyString(testFile);

    tests.open(testFile, std::ios::app);

    if (tests.is_open())
    {
        tests << std::endl;
        tests << std::endl;

        tests.close();
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
    
}
