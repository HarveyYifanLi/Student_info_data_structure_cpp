/*
 * Student_info.h
 *
 *  Created on: Jan 10, 2017
 *      Author: yifan
 */

#ifndef STUDENT_INFO_H_
#define STUDENT_INFO_H_

#include <iostream>
#include <string>
#include <vector>

class Student_info {
	// data members are protected as private implicitly
	// before the first protection label appears
	double midterm, final;
	std::vector<double> homework;

public:
	std::string student_name;

    // declare two basic constructors
	Student_info(); // empty Student_info object
	Student_info(std::istream&);


	// definition and declaration for accessor member function name()
	std::string name() const {
		return student_name;
	}
	// definition and declaration for member function valid()
    bool valid() const {
    	return !homework.empty();
    }
    //declaration for the member function read()
    std::istream& read(std::istream&);
    //declaration for the member function grade()
    double grade() const;

};
// declaration for the compare function (nonmember)
bool compare(const Student_info&, const Student_info&);


#endif /* STUDENT_INFO_H_ */
