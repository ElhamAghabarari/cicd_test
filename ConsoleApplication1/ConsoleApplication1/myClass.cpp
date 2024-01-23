#include "myClass.h"
#include <cstring>

myClass::myClass() {
	m_value = nullptr;
}

myClass::myClass(const char* std) {
	m_value = new char[strlen(std) + 1];
	strcpy_s(m_value, strlen(std)+1, std);
}

myClass::myClass( myClass& other) {
	m_value = new char[other.val_length() + 1];
	strcpy_s(m_value, other.val_length() + 1, other.m_value);
}

myClass myClass::operator=( myClass& other) {
	if (m_value!= nullptr) {
		delete[] m_value;
		m_value = nullptr;
	}
	m_value = new char[other.val_length() + 1];
	strcpy_s(m_value, other.val_length() + 1, other.m_value);

	return *this;
}

myClass myClass::operator+=( myClass& other) {
	if (m_value != nullptr) {
		char* temp = new char[other.val_length() + val_length() + 1];
		strcpy_s(temp, other.val_length() + val_length() + 1, m_value);
		strcat_s(temp, other.val_length() + val_length() + 1, other.m_value);

		delete[] m_value;
		m_value = nullptr;
		m_value = temp;
	}
	else {
		m_value = new char[other.val_length() + 1];
		strcpy_s(m_value, other.val_length() + 1,other.m_value);
	}
	
	

	return *this;
}

myClass::~myClass() {
	if (m_value != nullptr) {
		delete[] m_value;
		m_value = nullptr;
	}
}

int myClass::val_length() {
	if (m_value != nullptr) {
		return (int)strlen(m_value);
	}
	return 0;
}

char* myClass::getval() {
	return m_value;
}
