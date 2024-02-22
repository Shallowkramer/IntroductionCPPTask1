// IntroductionCPPAssessmentTask1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyString.h"

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

void TestEverythingMyString();

int main()
{
    TestEverythingMyString();
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
