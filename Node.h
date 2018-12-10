// Node Object to hold a data items in a binary tree
// Programmer:  Jonathan Godley - c3188072
// Course: SENG1120
// Last modified:  4/11/2017

#ifndef JONATHAN_BTNODE
#define JONATHAN_BTNODE

#include <cstdlib> // provides NULL

//#include "Student.cpp"

using namespace std;
namespace jonathan_A3
{
	template <typename value_type>
	class Node
	{
		public:
		//CONSTRUCTOR
		// Precondition : N/A
		// Postcondition:  A new instance of Node is created and its
		//  instance data initialsed to the parameter provided values
		Node(value_type* init_data = value_type(), Node<value_type>* parent_link = NULL);

		//DESTRUCTOR
		// Precondition:	A Node instance has been initialsed
		// Postcondition:   The Nodes pointers are cleared and Node is deleted
		~Node();

		//MODIFICATION MEMEBER FUNCTIONS
		// Precondition : data has been initialsed
		// Postcondition: the provided paramater is set as the data value
		void set_data(const value_type* new_data);

		// Precondition : parent_link has been initialsed
		// Postcondition: the provided paramater is set as the parent value
		void set_parent(Node<value_type>* parent_link);

		// Precondition : bLeft_link has been initialsed
		// Postcondition: the provided paramater is set as the bLeft value
		void set_bLeft(Node<value_type>* bLeft_link);

		// Precondition : bRight_link has been initialsed
		// Postcondition: the provided paramater is set as the bRight value
		void set_bRight(Node<value_type>* bRight_link);

		//CONSTANT MEMBER FUNCTIONS
		// Precondition : data has been initialsed
		// Postcondition: the value of data is returned
		value_type* get_data() const;

		// Precondition : parent has been initialsed
		// Postcondition: the value of parent is returned
		Node<value_type>* get_parent() const;

		// Precondition : bLeft has been initialsed
		// Postcondition: the value of bLeft is returned
		Node<value_type>* get_bLeft() const;

		// Precondition : bRight has been initialsed
		// Postcondition: the value of bRight is returned
		Node<value_type>* get_bRight() const;

		private:
		// member variables
		value_type *data;
		Node<value_type> *parent;
		Node<value_type> *bLeft;
		Node<value_type> *bRight;
	};
		#include "Node.template"

}
#endif
