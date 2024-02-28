#pragma once

#include "MyString.h"
class TestsMyString
{
public:

	void WriteToFileTests();

private:
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
};

