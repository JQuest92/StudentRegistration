#include "StudentHeader.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student()													//default constructor
{
	status = ' ';
	bid = 0;
	course = " ";
	name = " ";
}

Student::Student(char s, int b, string c, string n, string ln)			//constructor to 
{															//create student object from
	status = s;												//.txt file.
	bid = b;
	course = c;
	name = n;
	lastName = ln;
}


void Student::display()											//display registration info
{
	cout << bid << " " << name << " ";
}


void Student::operator=(const Student &rhs) {					//set Student = Student
	status = rhs.status;		
	bid = rhs.bid;
	course = rhs.course;
	name = rhs.name;
}

bool Student::operator>(const Student &rhs) {
	return bid > rhs.bid;

}