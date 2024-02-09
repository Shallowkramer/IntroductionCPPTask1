#include "MyString.h"
#include <iostream>

MyString::MyString()
{
	
}

MyString::MyString(const char* _str)
{

}

MyString::MyString(const MyString& _other)
{
}

MyString::~MyString()
{
}

size_t MyString::Length() const
{
	return size_t();
}

char& MyString::CharacterAt(size_t _index)
{
	// TODO: insert return statement here
}

const char& MyString::CharacterAt(size_t _index) const
{
	// TODO: insert return statement here
}

bool MyString::EqualTo(const MyString& _str)
{
	return false;
}

MyString& MyString::Append(const MyString& _str)
{
	// TODO: insert return statement here
}

MyString& MyString::Prepend(const MyString& _str)
{
	// TODO: insert return statement here
}

const char* MyString::ConstStr() const
{
	return nullptr;
}

MyString& MyString::ToLower()
{
	// TODO: insert return statement here
}

MyString& MyString::ToUpper()
{
	// TODO: insert return statement here
}

size_t MyString::Find(const MyString& _str)
{
	return size_t();
}

size_t MyString::Find(size_t _startIndex, const MyString& _str)
{
	return size_t();
}

MyString& MyString::Replace(const MyString& _find, const MyString& _replace)
{
	// TODO: insert return statement here
}

MyString& MyString::ReadFromConsole()
{
	// TODO: insert return statement here
}

MyString& MyString::WriteToConsole()
{
	// TODO: insert return statement here
}

bool MyString::operator==(const MyString& _other)
{
	return false;
}

bool MyString::operator!=(const MyString& _other)
{
	return false;
}

MyString& MyString::operator=(const MyString& _str)
{
	// TODO: insert return statement here
}

char& MyString::operator[](size_t _index)
{
	// TODO: insert return statement here
}

const char& MyString::operator[](size_t _index) const
{
	// TODO: insert return statement here
}
