#pragma once
class MyString
{
public:
	//Contructors and deconstructors
	MyString();
	MyString(const char* _str);
	MyString(int _int);

	MyString(const MyString& _other);

	~MyString();
	

	//Functions	
	size_t Length() const;
	size_t LengthNullIncluded() const;

	char CharacterAt(size_t _index);

	bool EqualTo(const MyString& _str);

	MyString Append(const MyString& _str);
	MyString Append(const char* _str);
	MyString Prepend(const MyString& _str);
	MyString Prepend(const char* _str);

	const char* CStr() const;

	MyString ToLower();
	MyString ToUpper();

	int Find(const MyString& c);
	int Find(int _startIndex, const MyString& c);

	int Find(const char* c);
	int Find(int _startIndex, const char* c);

	


	MyString Replace(const char* _find, const char* _replace);

	void ReadFromConsole();
	void WriteToConsole();


	//Operator Overides
	bool operator==(const MyString& _other);
	bool operator!=(const MyString& _other);

	MyString& operator=(const MyString& _str);

	char& operator[](size_t _index);
	const char& operator[](size_t _index) const;

	bool operator<(const MyString& _str);

	MyString operator+(const MyString& _other);
	MyString operator+=(const MyString& _other);

	//Public Variables

private:
	//Variables
	char* string;

	//Functions
	bool CompareAt(int index, const char* c);

	
	int* FindAllInstances(const char* c);
	int LengthAllInstances(const int* allInstances, int initialLength);
	char* SplitString(int splitStringStart, int splitStringEnd, const char* find);

};

