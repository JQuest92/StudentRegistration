#pragma once
#include <iostream>
#include <string>
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
class Student

{
private:
	char status;												//hold active/drop
	int bid;													//hold bid amount
	string course;												//hold course
	string name;												//hold first name
	string lastName;											//hold last name
public:
	Student();
	Student(char s, int b, string c, string n, string ln);		//constructor

	void setStatus(char s)										//mutator
	{ s = status;}

	void setBid(int b)											//mutator
	{b = bid;}

	void setCourse(string c)									//mutator
	{ c = course;}

	void setName(string n)										//mutator
	{ n = name;}
 
	void setLastName(string ln)									//mutator
	{ln = lastName;}

	char getStatus()											//accessor
	{return status;}

	int getBid()												//accessor
	{return bid;}

	 string getCourse()											//accessor	
	{return course;}

	string getName()											//accessor
	{return name;}

	 string getLastName()										//accesor
	 {return lastName;}

	void display();												//display student -
																//registration info.
	void operator=(const Student &rhs);							//overload = operator -
																//so students can be set
																//equal to each other.
	bool operator>(const Student &rhs);
};

#endif