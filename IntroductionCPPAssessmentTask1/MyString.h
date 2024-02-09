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
	char& CharacterAt(size_t _index);
	const char& CharacterAt(size_t _index) const;

	bool EqualTo(const MyString& _str);

	MyString& Append(const MyString& _str);
	MyString& Prepend(const MyString& _str);

	const char* ConstStr() const;

	MyString& ToLower();
	MyString& ToUpper();

	size_t Find(const MyString& _str);
	size_t Find(size_t _startIndex, const MyString& _str);

	MyString& Replace(const MyString& _find, const MyString& _replace);

	MyString& ReadFromConsole();
	MyString& WriteToConsole();


	//Operator Overides
	bool operator==(const MyString& _other);
	bool operator!=(const MyString& _other);

	MyString& operator=(const MyString& _str);

	char& operator[](size_t _index);
	const char& operator[](size_t _index) const;


private:
	char* string;

};

