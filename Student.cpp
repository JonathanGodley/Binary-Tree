// Student Object implementation
// Programmer:  Jonathan Godley - c3188072
// Course: SENG1120
// Last modified:  11/10/2017
#include "Student.h"

namespace jonathan_A3
{
        // CONSTRUCTOR
        Student::Student(string init_name, int init_grade)
        {
            // create on heap
            name = new string(init_name);
            grade = new int(init_grade);
        }

        // DESTRUCTOR
        Student::~Student()
        {
            // call destructors of name and grade, remove pointers
            delete name;
            delete grade;

            name = NULL;
            grade = NULL;
        }

        // Member Functions
        // Return Name
        string Student::getName() const
        {
            return *name;
        }

		      // Return Grade
        int Student::getGrade() const
        {
            return *grade;
        }

        // OVERLOADED OPERATORS
				friend ostream& operator<<(ostream& out, const Student& student);
        {
          out << "(" << student.getName() << ", " << student.getGrade() << ")";
        }

        // overload == operator to use name variable in student object
				bool operator == (const Student& sLeft, const Student& sRight);
        {
          return (sLeft.getName() == sRight.getName();)
        }

        // overload < operator to use name variable in student object
				bool operator < (const Student& sLeft, const Student& sRight);
        {
          return (sLeft.getName() < sRight.getName();)
        }

        // overload > operator to use name variable in student object
				bool operator > (const Student& sLeft, const Student& sRight);
        {
          return (sLeft.getName() > sRight.getName();)
        }
}
