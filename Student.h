// Student Object definition
// Programmer:  Jonathan Godley - c3188072
// Course: SENG1120
// Last modified:  11/10/2017
#ifndef JONATHAN_STUDENT
#define JONATHAN_STUDENT

#include <string> // provides string functionality
#include <cstdlib> // provides NULL

using namespace std;
namespace jonathan_A3
{
	class Student
	{
		public:
			// CONSTRUCTOR
			// Precondition : init_name and init_grade provided
			// Postcondition:  A new instance of Student is created and its
			//  instance data initialsed to the parameter provided value
			Student(string init_name, int init_grade);

			// DESTRUCTOR
			// Precondition:		A Student instance has been initialsed
			// Postcondition:   	This Student instance is deleted
			~Student();

			// MEMBER FUNCTIONS
			// Precondition:		A Student instance has been initialsed
			// Postcondition:   	name is returned
			string getName() const;

			// Precondition:		A Student instance has been initialsed
			// Postcondition:   	grade is returned
			int getGrade() const;

		private:
        // Member variables
        string *name;
        int *grade;

				// OVERLOADED OPERATORS
				// Precondition: A student is initialised with data
				// Postcondition: outputs the content of the student object in a form suitable for printing.
				friend ostream& operator<<(ostream& out, const Student& student);

				// Precondition: A student is initialised with data
				// Postcondition: true returned if both students equal
				friend bool operator == (const Student& sLeft, const Student& sRight);

				// Precondition: A student is initialised with data
				// Postcondition: true returned if sleft less than sRight
				friend bool operator < (const Student& sLeft, const Student& sRight);

				// Precondition: A student is initialised with data
				// Postcondition: true returned if sleft more than sRight
				friend bool operator > (const Student& sLeft, const Student& sRight);

    };
}
#endif
