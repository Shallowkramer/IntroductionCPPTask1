#pragma once
class MyString
{
public:
	//Contructors and deconstructors
	MyString();
	MyString(const char* _str);

	MyString(const MyString& _other);

	~MyString();
	

	//Functions
	size_t Length() const;
	size_t LengthNullIncluded() const;

	char CharacterAt(size_t _index);

	bool EqualTo(const MyString& _str);

	MyString Append(const MyString& _str);
	MyString Prepend(const MyString& _str);

	const char* CStr() const;

	MyString ToLower();
	MyString ToUpper();

	int Find(const MyString& _str);
	int Find(size_t _startIndex, const MyString& _str);

	MyString& Replace(const MyString& _find, const MyString& _replace);

	void ReadFromConsole();
	void WriteToConsole();


	//Operator Overides
	bool operator==(const MyString& _other);
	bool operator!=(const MyString& _other);

	MyString& operator=(const MyString& _str);

	char& operator[](size_t _index);
	const char& operator[](size_t _index) const;


	//Public Variables

private:
	//Variables
	char* string;

	char* findStringString;

};

