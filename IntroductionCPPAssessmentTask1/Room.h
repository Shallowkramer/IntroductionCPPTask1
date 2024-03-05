#pragma once
class MyString;
class InterfaceGameObject;

class Room
{
public:
	//Functions
	Room();
	~Room();

	void SetUp(int i);

	void Description() const;


	//Variables
	InterfaceGameObject* item;

private:
	MyString* descrption;
};

