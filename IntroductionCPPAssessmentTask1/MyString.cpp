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
	return Append(_str.CStr());
}

MyString MyString::Append(const char* _str)
{
	//combines the length of 1 string with the length of the other string with null terminator
	int newLength = LengthNullIncluded() + strlen(_str);

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
	strcat_s(string, newLength, _str);

	return string;
}

MyString MyString::Prepend(const MyString& _str)
{
	return Prepend(_str.CStr());
}

MyString MyString::Prepend(const char* _str)
{
	//combines the length of 1 string with the length of the other string with null terminator
	int newLength = LengthNullIncluded() + strlen((const char*)_str);

	//Copied constructor
	MyString tempString(string);

	//deletes string after being copied
	delete[] string;


	//makes new string of the correct length
	string = new char[newLength];

	//includes null terminator as string concatanate needs that to work
	string[0] = '\0';

	//prepends strings
	strcat_s(string, newLength, (const char*)_str);
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

int MyString::Find(int _startIndex, const MyString& c)
{
	return 	Find(_startIndex, c.string);
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



int MyString::Find(const MyString& c)
{
	return Find(0, c);
}

MyString MyString::SplitString(int splitStringAt)
{
	char* newString = new char[splitStringAt+1];

	for (int i = 0; i <= splitStringAt; i++)
	{
		if (i == splitStringAt)
		{
			newString[i] = '\0';
		}
		else
		{
			newString[i] = string[i];
		}		
	}
	
	/*std::cout << newString << std::endl;*/

	return newString;
}

MyString MyString::Replace(const char* _find, const char* _replace)
{
	/*int* locations;*/

	int diff = strlen(_replace) - strlen(_find);

	int length = LengthNullIncluded() + diff;

	char* tempString = new char[length];
	tempString[0] = '\0';

	if (strlen(_find) < Length())
	{
		for (int i = 0; i < Length(); i++)
		{
			if (Find(_find) != -1)
			{
				strcat_s(tempString, length, (SplitString(i).Append(_replace).string));

				std::cout << "find should happen when i=6" << std::endl;
				std::cout << i << std::endl;
			}
			else
			{
				//appends strings
				

				std::cout << "find did find should happen when i=6" << std::endl;
				
			}
		}
	}

	std::cout << tempString << std::endl;

	delete[] string;

	string = tempString;
	
	return string;
}

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
