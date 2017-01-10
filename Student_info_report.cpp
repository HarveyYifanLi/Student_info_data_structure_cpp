//============================================================================
// Name        : Student_info_report.cpp
// Author      : Yifan Li
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <istream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <ios>
#include "Student_info.h"


using namespace std;
using std::sort;


int main() {

vector<Student_info> students;
Student_info record;
string::size_type maxlen = 0;
// read and store the data

	while (record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

// alphabetize the student records

	sort(students.begin(), students.end(), compare);

// write the names and grades
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {

		cout << students[i].name()

	         << string(maxlen + 1 - students[i].name().size(), ' ');

		try {
				double final_grade = students[i].grade();

				streamsize prec = cout.precision();
				cout << setprecision(3) << final_grade
					 << setprecision(prec)<< endl;

		}
		catch (domain_error e) {
				cout << e.what() << endl;
		}

	} // end of for-loop

return 0;

} // end of main

