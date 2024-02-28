#include "TestsMyString.h"
#include <iostream>
#include <fstream>
#include "MyString.h"

void TestsMyString::TestLength(const char testFile[10])
{
    MyString myString1;

    TestPrintSuccessFail(myString1.Length() == 19, "Test Length", testFile);
}

void TestsMyString::TestCharacterAt(const char testFile[10])
{
    MyString myString1;

    TestPrintSuccessFail(myString1.CharacterAt(0) == 'D', "Test CharacterAt", testFile);
}

void TestsMyString::TestEqualTo(const char testFile[10])
{
    MyString myString1;
    MyString myStringDefault2;

    TestPrintSuccessFail(myString1.EqualTo(myStringDefault2), "Test EqualTo", testFile);
}

void TestsMyString::TestAppend(const char testFile[10])
{
    MyString myString1;
    MyString myString2("D");

    myString1.Append(myString2);

    TestPrintSuccessFail(strcmp(myString1.CStr(), "Default ConstructorD") == 0, "Test Append", testFile);
}

void TestsMyString::TestPrepend(const char testFile[10])
{
    MyString myString1;
    MyString myString2("D");

    myString1.Prepend(myString2);

    TestPrintSuccessFail(strcmp(myString1.CStr(), "DDefault Constructor") == 0, "Test Prepend", testFile);
}

void TestsMyString::TestCStr(const char testFile[10])
{
    MyString myString1;

    TestPrintSuccessFail(strcmp(myString1.CStr(), "Default Constructor") == 0, "Test CStr", testFile);
}

void TestsMyString::TestToLower(const char testFile[10])
{
    MyString myString1;

    myString1.ToLower();

    TestPrintSuccessFail(strcmp(myString1.CStr(), "default constructor") == 0, "Test ToLower", testFile);
}

void TestsMyString::TestToUpper(const char testFile[10])
{
    MyString myString1;

    myString1.ToUpper();

    TestPrintSuccessFail(strcmp(myString1.CStr(), "DEFAULT CONSTRUCTOR") == 0, "Test ToUpper", testFile);
}

void TestsMyString::TestFindString(const char testFile[10])
{
    MyString myString1;

    TestPrintSuccessFail(myString1.Find("a") == 3, "Test FindString", testFile);
}

void TestsMyString::TestFindStringStartIndex(const char testFile[10])
{
    MyString myString1;

    TestPrintSuccessFail(myString1.Find(7, "t") == 12, "Test FindStringStartIndex", testFile);
}

void TestsMyString::TestReplace(const char testFile[10])
{
    MyString myString1;

    myString1.Replace("t", "hi");

    TestPrintSuccessFail(strcmp(myString1.CStr(), "Defaulhi Conshiruchior") == 0, "Test Replace", testFile);
}

void TestsMyString::TestReadFromConsole(const char testFile[10])
{
    TestPrintSuccessFail(true, "Test ReadFromConsole", testFile);
}

void TestsMyString::TestEqualityOperator(const char testFile[10])
{
    MyString myString1;
    MyString myString2;

    TestPrintSuccessFail(myString1 == myString2, "Test EqualityOperator", testFile);
}

void TestsMyString::TestInequalityOperator(const char testFile[10])
{
    MyString myString1;
    MyString myString2("D");

    TestPrintSuccessFail(myString1 != myString2, "Test InequalityOperator", testFile);
}

void TestsMyString::TestSubscriptOperator(const char testFile[10])
{
    MyString myString1;

    TestPrintSuccessFail(myString1[0] == 'D', "Test SubscriptOperator", testFile);
}

void TestsMyString::TestAssignementOperator(const char testFile[10])
{
    MyString myString1;
    MyString myString2("D");

    myString2 = myString1;

    TestPrintSuccessFail(strcmp(myString1.CStr(), myString2.CStr()) == 0, "Test AssignmentOperator", testFile);
}

void TestsMyString::TestLessThanOperator(const char testFile[10])
{
    MyString myString1;
    MyString myString2("Default Donstructor");

    TestPrintSuccessFail(myString1 < myString2, "Test LessThanOperator", testFile);
}

void TestsMyString::TestPrintSuccessFail(bool _bool, const char* _str, const char testFile[10])
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

MyString TestsMyString::PrintDateAndTime()
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

void TestsMyString::TestEverythingMyString(const char testFile[10])
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

void TestsMyString::WriteToFileTests()
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
