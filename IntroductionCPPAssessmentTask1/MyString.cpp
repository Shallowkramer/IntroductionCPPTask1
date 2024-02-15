#include "MyString.h"
#include <iostream>
#include <ctype.h>

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
	//combines the length of 1 string with the length of the other string with null terminator
	int newLength = Length() + _str.LengthNullIncluded();

	//Copied constructor
	MyString tempString(string);

	//deletes string after being copied
	delete[] string;


	//makes new string of the correct length
	string = new char[newLength];

	//includes null terminator as string concatanate needs that to work
	string[0] = '\0';

	//appends strings
	strcat_s(string, newLength, tempString.string);
	strcat_s(string, newLength, _str.string);

	return string;
}

MyString MyString::Prepend(const MyString& _str)
{
	//combines the length of 1 string with the length of the other string with null terminator
	int newLength = Length() + _str.LengthNullIncluded();

	//Copied constructor
	MyString tempString(string);

	//deletes string after being copied
	delete[] string;


	//makes new string of the correct length
	string = new char[newLength];

	//includes null terminator as string concatanate needs that to work
	string[0] = '\0';

	//prepends strings
	strcat_s(string, newLength, _str.string);
	strcat_s(string, newLength, tempString.string);

	return string;
}

const char* MyString::CStr() const
{
	return string;
}

MyString MyString::ToLower()
{
	for (int i = 0; i < Length(); i++)
	{
		if (isupper((int)(string[i])))
		{
			string[i] = tolower((int)string[i]);
		}
	}
	
	return string;
}

MyString MyString::ToUpper()
{
	for (int i = 0; i < Length(); i++)
	{
		if (islower((int)(string[i])))
		{
			string[i] = toupper((int)string[i]);
		}
	}

	return string;
}

bool MyString::CompareAt(int index, const char* c)
{

	for (int i = 0; i < strlen(c); i++)
	{
		if (string[index] != c[i])
		{
			return false;
		}

		index++;
	}
	return true;
}

int MyString::Find(int _startIndex, MyString& c)
{

	if (strlen(c.string) < Length())
	{
		for (int i = _startIndex; i < Length() - c.Length(); i++)
		{
			if (CompareAt(i, c.string))
			{
				return i;
			}
		}
	}

	return -1;
}

int MyString::Find(const char* c)
{
	return Find(0, c);;
}

int MyString::Find(int _startIndex, const char* c)
{
	if (strlen(c) < Length())
	{
		for (int i = _startIndex; i < Length() - strlen(c); i++)
		{
			if (CompareAt(i, c))
			{
				return i;
			}
		}
	}

	return -1;
}

int MyString::Find(MyString& c)
{
	return Find(0, c);
}



//MyString MyString::Replace(MyString& _find, MyString& _replace)
//{
//	Find(_find);
//
//	return string;
//}

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
