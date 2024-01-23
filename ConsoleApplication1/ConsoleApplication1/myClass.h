#pragma once
class myClass
{
private:
	char* m_value;

public:

	myClass();
	myClass(const char* std);
	myClass( myClass& std);
	myClass operator=( myClass& other);
	myClass operator+=( myClass& other);
	~myClass();

	int val_length();
	char* getval();
};

