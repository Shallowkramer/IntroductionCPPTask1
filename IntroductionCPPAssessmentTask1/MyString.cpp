#include "MyString.h"
#include <iostream>

MyString::MyString()
{
	string = new char[20] {"Default Constructor"};
}

MyString::MyString(const char* _str)
{
	//length of the string including null terminator
	int length = strlen(_str) +1;
	
	//new string
	string = new char[length]; 

	//input string being copied to new string
	strcpy_s(string, length, _str);
}

MyString::MyString(const MyString& _other)
{
	int length = _other.LengthNullIncluded();

	string = new char[length];

	strcpy_s(string, length, _other.string);
}

MyString::~MyString()
{
	delete[] string;
}

size_t MyString::Length() const
{
	int length = strlen(string);

	return length;
}

size_t MyString::LengthNullIncluded() const
{
	int length = strlen(string) + 1;

	return length;
}


char MyString::CharacterAt(size_t _index)
{
	if (_index < 0 || Length() < _index)
	{
		return '\0'; 
	}
	else
	{
		return string[_index];
	}
}

bool MyString::EqualTo(const MyString& _str)
{
	if (strcmp(string, _str.string) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

MyString MyString::Append(const MyString& _str)
{
	int newLength = Length() + _str.LengthNullIncluded();

	MyString tempString(string);

	delete[] string;

	string = new char[newLength];

	string[0] = '\0';

	strcat_s(string, newLength, tempString.string);
	strcat_s(string, newLength, _str.string);

	return string;
}

//MyString& MyString::Prepend(const MyString& _str)
//{
//	// TODO: insert return statement here
//}

const char* MyString::CStr() const
{
	return nullptr;
}

//MyString& MyString::ToLower()
//{
//	// TODO: insert return statement here
//}

//MyString& MyString::ToUpper()
//{
//	// TODO: insert return statement here
//}

size_t MyString::Find(const MyString& _str)
{
	return size_t();
}

size_t MyString::Find(size_t _startIndex, const MyString& _str)
{
	return size_t();
}

//MyString& MyString::Replace(const MyString& _find, const MyString& _replace)
//{
//	// TODO: insert return statement here
//}
//
void MyString::ReadFromConsole()
{
	
}

void MyString::WriteToConsole()
{
	std::cout << string << std::endl;
}

//bool MyString::operator==(const MyString& _other)
//{
//	return false;
//}
//
//bool MyString::operator!=(const MyString& _other)
//{
//	return false;
//}
//
//MyString& MyString::operator=(const MyString& _str)
//{
//	// TODO: insert return statement here
//}
//
//char& MyString::operator[](size_t _index)
//{
//	// TODO: insert return statement here
//}
//
//const char& MyString::operator[](size_t _index) const
//{
//	// TODO: insert return statement here
//}
