#include <string>
#include "StudentHeader.h"
#include <vector>
#include <algorithm>
using namespace std;

/*
	John Westbrooks
	OLA 2: STL
	Program description:
			The registrationBid.txt file is read into the program. Each line of the file is 
saved as a Student class object which is then stored in a vector of Student objects. A copy of
the data is then saved as another vector of Student objects. This copy will serve as raw data.
Next, the program calls the "dropCourse" function and removes students who dropped their course.
Then the "acceptanceNumber" function is called, and the amount of students accepted into each 
course is recorded. Next the program begins a for loop that will iterate once for each distinct
course being offered. Within this for loop is a nested for loop that will iterate once for each
student who did not drop their course. A test is done to see if the current student being accessed
is a member of the current course being accessed by stringVector, a vector containing each unique
course. If they are equal, the current student object is also saved in a new vector of Student
objects named courseVector. Each time after the nested for loop ends, courseVector is passed to
"sortAndShow" function which sorts and shows the students in the course. sortAndShow calls the
"nameCheck" function which ensures  the proper last name is displayed with each student as the STL
sort method and "dropCourse" functions may scramble some data pertaining to last names. The proper
last name is pulled from the vector containing the raw data from the file.
*/





bool sortPattern(Student lhs, Student rhs)			//stl Sort method
{
	return lhs.getBid() > rhs.getBid();

}

vector<Student> checkNames(vector<Student>& srtVec, vector<Student>& rwDtVec)
{
	vector<Student> courseList = srtVec;		//holds the course being operated on
	vector<Student> raw = rwDtVec;				//holds all raw data from file
	vector<Student> lstNameHolder;			//student vector to hold sorted raw data
	int crsSize = courseList.size();			//loop counter - # students in course
	int dataSize = raw.size();					//loop counter - # students in raw data

	for (int x4 = 0; x4 < dataSize; x4++) {	//loop through once for each student in
												//raw data.
		for (int y4 = 0; y4 < crsSize; y4++) {	//loop through once for each student in
			if (courseList[y4].getCourse() == raw[x4].getCourse()) {	//the course.
				if (courseList[y4].getName() == raw[x4].getName()) {
					lstNameHolder.push_back(raw[x4]); //if the course and first names are =
				}	//end of if name == name			//then store this raw data.
			}										//end of if course == course
		}											//end of y4 for loop
	}												//end of x4 for loop

	return lstNameHolder;						//return vector filled with raw data
}






											//function below collects # students per course.
vector<int> acceptanceNumber(int lengthCatalog, vector<string> &stringVector)
{
	vector<int> accptVc;										
	int numAccepted;											//hold the # accepted into course.	
	int catalog = lengthCatalog;
	vector<string> catalogVec = stringVector;
	for (int counter = 0; counter < catalog; counter++){//loop through once for each course offered.
		cout << "Enter the number of students accepted into " << catalogVec[counter] << ": ";
		cin >> numAccepted;
		accptVc.push_back(numAccepted);							//store amount in vector<int>.
		cout << "\n";
	}																
	return accptVc;														//return vector<int>.
}														

										
vector<Student> dropCourse(vector<Student> &droppedCourse, vector <Student> &studentVector, int lengthRoster)
{											//this function removes students who dropped.
	vector<Student> drpdCrsVec = droppedCourse;
	vector<Student> stdntVctr = studentVector;
	int lngthRstr = lengthRoster;				//number of total students
	int numWhoDrpd = drpdCrsVec.size();			//number of students who dropped a course
	for (int x2 = 0; x2 < numWhoDrpd; x2++)		//loop through once for each student who
	{											//dropped a course

		for (int y2 = 0; y2 < lngthRstr; y2++)	//loop through once for each student
		{
											
			if (drpdCrsVec[x2].getCourse() == stdntVctr[y2].getCourse())//if current student 
			{													//who dropped's course & name
																//match current student's...
				if (drpdCrsVec[x2].getName() == stdntVctr[y2].getName())	
				{				
					
					stdntVctr.erase(stdntVctr.begin() + y2);			//remove them from data.
					lngthRstr = stdntVctr.size();						//decrement counters
					y2 = y2 - 1;

					
				}
			}														//end of if line 60.
		}														//end of nested for line 57.
	}															//end of outer for line 54.
	return stdntVctr;
}																//end of dropCourse function.

void sortAndShow(vector<Student>& courseVector, vector<int>& acceptVec, int numInCrs, string thisCrs, vector<Student>& rawData)
{
	
	int y3 = 0;					
	vector<Student> srtVec = courseVector;			//students in current course
	vector<Student> rwDtVec = rawData;				//raw data, here to be passed
	int nmInCrs = numInCrs;							//# of students in this course
	string whtCrs = thisCrs;						//name of current course (i.e. cs1001)	
	vector<Student> lastNameVec;					//will hold raw data that pertain to
													//the current course.

	if (srtVec.empty() || nmInCrs == 0)				//if the course is empty or no acceptance.
	{		
		cout << "\nStudents listed registered for " << whtCrs << "\n";
		cout << "This course is empty.\n";
	}

	else if (srtVec.size() == 1)				//else if the course has one student enrolled.
	{
		cout << "\nStudents listed registered for " << srtVec[0].getCourse() << ":\n";
		srtVec[0].display();
		cout << " " << srtVec[0].getLastName() << "\n";
		int numInCrs2 = (nmInCrs - 1);					//loop counter for empty seats.
		for (int x4 = 0; x4 < numInCrs2; x4++)
		{
			cout << "This is an open seat.\n";
		}
	}												//end of else if line 93.

	else {		//else there are > 1 students in the course enrolled, or accepted.

								//sort course by bid.
		sort(srtVec.begin(), srtVec.end(), sortPattern);
		lastNameVec = checkNames(srtVec, rwDtVec);		//this function loads a student vector
													//with the raw data of the students in this
													//course from the raw data file.
		cout << "\nStudents listed registered for " << srtVec[0].getCourse() << "\n";
		int numNames = lastNameVec.size();

		for (int x3 = 0; x3 < nmInCrs; x3++)			//loop through once for each student in
		{											//the course.
				if (srtVec.size() <= x3){			
					cout << "This is an open seat.\n";	
				}
				else{
		
					for (int y3 = 0; y3 < numNames; y3++) {		//loop through for each student
						if (srtVec[x3].getName() == lastNameVec[y3].getName()){
							srtVec[x3].display();	//display sorted data
							cout << lastNameVec[y3].getLastName() << "\n";	//display last name
														//form data file. If statement tests
														//to be sure appropriate last name is
														//is displayed.
						}						//end of if (name == name)

					}									//end of for y3
				}		//end of else
		}										//end of for loop line 153
	}											//end of outer else - line 143
}												// end of sortAndShow function

int main()
{
	ifstream regFile;
	char status;											//B or D
	int bid;												//bid amount
	int lengthRoster;										//# of students
	int lengthCatalog;										//# of courses offered
	int numAccepted;										//# accepted into a course
	int numInCrs;											//# actively enrolled in a course
	string course;											//course name
	string name;											//student's first name
	string lastName;										//student's last name
	vector<Student> studentVector;								//holds student objects
	vector<Student> rawData;								//holds unfiltered student objects
	vector<string> stringVector;								//holds distinct courses
	vector<Student> courseVector;						//holds students in a certain course
	vector<Student> droppedCourse;						//holds request to drop a course
	vector<int>		acceptVec;							//holds # accepted into each course

	regFile.open("registrationBid.txt"); //open text

	while (!regFile.eof())											//loop while file is open.
	{

		regFile >> status >> bid >> course >> name >> lastName;	     //read line from file.
		Student student(status, bid, course, name, lastName);		//create student object.
		if (status == 'D')										//if student drops, store in
		{														// a special vector.
			droppedCourse.push_back(student);
		}
		studentVector.push_back(student);							//store current student.
		stringVector.push_back(course);								//store current courses.
		stable_sort(stringVector.begin(), stringVector.end());				//sort courses.
		auto holder = unique(stringVector.begin(), stringVector.end());
		stringVector.erase(holder, stringVector.end());
		//store non-unique courses, and then erase them.
	}													
	
	regFile.close();			
	lengthRoster = studentVector.size(); //number of students who added/dropped a class
	rawData = studentVector;						//create copy of unfiltered data
	studentVector = dropCourse(droppedCourse, studentVector, lengthRoster);
											//function call above removes students who
											//dropped a course - function begins line 84
	lengthRoster = studentVector.size();		//set loop counter with # of students after drop
	lengthCatalog = stringVector.size();		//set loop counter with # of courses
																
	acceptVec = acceptanceNumber(lengthCatalog, stringVector);	
	//above function call gets # accepted into each course. functions begins on line
	for (int x = 0; x < lengthCatalog; x++)				//loop through once for each distinct,
	{																//course being offered.
		
		numInCrs = acceptVec[x];							//number of people in this course
		
		string thisCrs;									//holds the name of the current course
		thisCrs = stringVector[x];											//assigning value
		cout << "\n";
		for (int y = 0; y < lengthRoster; y++){			//loop through once for each student.
			if (stringVector[x] == studentVector[y].getCourse()){ //if course = student's course
				courseVector.push_back(studentVector[y]); //add student to new vector.
											//it will hold the all the values being tested
			}							                        //for by the outer for loop (x).
		}													
				//call function to sort and show the enrollment in the course x is accessing.
		sortAndShow(courseVector, acceptVec, numInCrs, thisCrs, rawData);
		
		courseVector.clear();			//remove all current student objects from courseVector.
	}															
	system("PAUSE");
	return 0;
}