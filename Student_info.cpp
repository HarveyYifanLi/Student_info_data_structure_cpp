/*
 * Student_info.cpp
 *
 *  Created on: Jan 10, 2017
 *      Author: yifan
 */

#include "Student_info.h"
#include <stdexcept>
#include <iostream>

using std::istream;
using std::vector;
using std::domain_error;

istream& read_hw(istream& in, vector<double>& homework)
{
    if (in)
    {
        // get rid of previous contents
        homework.clear();

        // read homework grades
        double x;

        while (in >> x){
            homework.push_back(x);
        }

        // clear the stream so that input will work for the next student record
        in.clear();
    }
    return in;
}

// definition of the Student_info::read() member function
istream& Student_info::read(istream& in)
{

    in >> student_name >> midterm >> final;

    // read and store all the student's homework scores (to the temporary vector<double> container)
    read_hw(in, homework);
 /*
    // compute the student's overall score, and store to the Student_info object
    try
    {
        s.final_grade = grade(midterm, final, homework);
    }
    catch (domain_error e)
    {
        s.final_grade = -1;  // indicating student has done no homework
    }
    */
    return in;
}

// definition of the two constructors of the Student_info class
Student_info::Student_info(): midterm(0), final(0) {};
Student_info::Student_info(istream& in){read(in);}

// we are interested in sorting the Student_info object by the student's name
bool compare(const Student_info& x, const Student_info& y)
{
    return x.student_name < y.student_name;
}



double median(vector<double> homework)
{
    typedef vector<double>::size_type vec_sz;

    vec_sz size = homework.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(homework.begin(),homework.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];

}


double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}


double grade(double midterm, double final, const vector<double>& homework)
{
    if (homework.size() == 0)
        throw domain_error("student has done no homework");

    return grade(midterm, final, median(homework));

}

// definition of the Student_info::grade() member function

double Student_info::grade() const {

	return ::grade(midterm, final, homework);

}




















