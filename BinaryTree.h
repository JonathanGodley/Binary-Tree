// This defines a class that implements a linked list object
// that consists of multiple nodes (updated to use templates)
// Programmer:  Jonathan Godley - c3188072
// Course: SENG1120
// Last modified:  19/09/17

#ifndef JONATHAN_BINARYTREE
#define JONATHAN_BINARYTREE

#include "Node.h"

using namespace std;
namespace jonathan_A3
{
	template <typename value_type>
	class BinaryTree
	{
		public:
			// Precondition:	N/A
			// Postcondition:  	An Binary Tree instance is created
			BinaryTree();

			// DESTRUCTOR
			// Precondition:	An Binary Tree Instance containts node instances
			// Postcondition:   Each node is deleted from the head of the list, leaving an empty linked list
			~BinaryTree();

			// MEMBER FUNCTIONS
			// Precondition:	An Linked List has been initialised, data provided
			// Postcondition:   data added as node to binary tree in appropriate position
			void add(value_type& data);

			// Precondition:	A Binary Tree is initialised with nodes containing data
			// Postcondition:   The selected node in the list is removed
			void removeNode(Node<value_type>* target);

			// Precondition:	A linked list is initialised with nodes containing data
			// Postcondition:   the number of nodes in the linked list is returned
			std::size_t size();

		private:
			node<value_type>* root_ptr_;
			size_t length;

			// OVERLOADED OPERATORS
			// Precondition: A student is initialised with data
			// Postcondition: outputs the content of the student object in a form suitable for printing.
			friend ostream& operator<<(ostream& out, const BinaryTree& bTree);

		};
	#include "BinaryTree.template"

}
#endif
