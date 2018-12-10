// This program demonstrates the generic Binary Tree Templates I have created.
// Programmer:  Jonathan Godley - c3188072
// Course: SENG1120
// Last modified:  11/10/17
#include "Queue.h"
#include <iostream>
using namespace std;
using namespace jonathan_A3;

int main(void)
{
        // create our queues
        Queue<int>* inputOne = new Queue<int>();
        Queue<int>* inputTwo = new Queue<int>();
        Queue<int>* inputThree = new Queue<int>();
        Queue<int>* outputOne = new Queue<int>();

        // String Stream to cast int etc to string
        ostringstream ss;

        // string variable to hold our incoming inputThree
        string input = "";

        // boolean variable to check if inputs are ordered
        bool ordered = true;

        // step 1 - Query user for 3 sequences of inputs.
        cout << "Please enter three sequences: \n";
        getline(cin, input);
        input >> *inputOne;

        getline(cin, input);
        input >> *inputTwo;

        getline(cin, input);
        input >> *inputThree;

        // step 2 - Check inputs are valid.
        // i'm going to add this as a function in the queue class itself, "isOrdered"
        // rather than have to try and dequeue and requeue objects.
        if (inputOne->isOrdered()==false)
        {
                cout << "Sequence 1 is not ordered \n";
                ordered = false;
        }
        if(inputTwo->isOrdered()==false)
        {
                cout << "Sequence 2 is not ordered \n";
                ordered = false;
        }
        if(inputThree->isOrdered()==false)
        {
                cout << "Sequence 3 is not ordered \n";
                ordered = false;
        }


        // step 3 - run algorithm if ordered
        // so first check if ordered
        if (ordered == false) // not ordered
        {
                cout << "ERROR: An input sequence was not ordered - Aborting";

                // finished, so we delete our queues
                delete inputOne;
                delete inputTwo;
                delete inputThree;
                delete outputOne;

                // return failure
                return EXIT_FAILURE;
        }
        else // ordered
        {
                // NOTE: I HAVE used enqueue rather than >> here in order to simplify things
                //  ss.str() >> *outputOne; was being rejecteted, and input = ss.str(); input >> *outputOne;
                // was what would've worked, which was a waste of space. Two commands instead of one.

                // so we're going to loop until all 3 input queues are empty.
                // with a truly horrible block of code.
                while (!inputOne->isEmpty()||!inputTwo->isEmpty()||!inputThree->isEmpty())
                {
                        // all 3 have items left, the most common occurences
                        if (!inputOne->isEmpty()&&!inputTwo->isEmpty()&&!inputThree->isEmpty())
                        {
                                // we'll try for: if 1 is less than 2 & 3, if 2 is less than 1 & 3, and an else
                                if (inputOne->front() <= inputTwo->front() && inputOne->front() <= inputThree->front())
                                {
                                        ss << inputOne->dequeue();
                                        outputOne->enqueue(ss.str());
                                        ss.str("");
                                }// if 2 is less than 1 & 3
                                else if (inputTwo->front() <= inputOne->front() && inputTwo->front() <= inputThree->front())
                                {
                                        ss << inputTwo->dequeue();
                                        outputOne->enqueue(ss.str());
                                        ss.str("");
                                }
                                else // must be 3 <= 2 & 1
                                {
                                        ss << inputThree->dequeue();
                                        outputOne->enqueue(ss.str());
                                        ss.str("");
                                }
                        }

                        // if only one of the 3 queues has content
                        else if (!inputOne->isEmpty()^!inputTwo->isEmpty()^!inputThree->isEmpty())
                        {
                                // find out which one
                                if (!inputOne->isEmpty())
                                {
                                        ss << inputOne->dequeue();
                                        outputOne->enqueue(ss.str());
                                        ss.str("");
                                }
                                if (!inputTwo->isEmpty())
                                {
                                        ss << inputTwo->dequeue();
                                        outputOne->enqueue(ss.str());
                                        ss.str("");
                                }
                                if (!inputThree->isEmpty())
                                {
                                        ss << inputThree->dequeue();
                                        outputOne->enqueue(ss.str());
                                        ss.str("");
                                }
                        }

                        // check if only 1 & 2, only 2 & 3, or only 1 & 3 have content
                        else if (!inputOne->isEmpty()&&!inputTwo->isEmpty()&&inputThree->isEmpty())
                        {
                                // 1 vs 2
                                if (inputOne->front() <= inputTwo->front())
                                {
                                        ss << inputOne->dequeue();
                                        outputOne->enqueue(ss.str());
                                        ss.str("");
                                }
                                else
                                {
                                        ss << inputTwo->dequeue();
                                        outputOne->enqueue(ss.str());
                                        ss.str("");
                                }
                        }

                        else if (inputOne->isEmpty()&&!inputTwo->isEmpty()&&!inputThree->isEmpty())
                        {
                                // 2 vs 3
                                if (inputTwo->front() <= inputThree->front())
                                {
                                        ss << inputTwo->dequeue();
                                        outputOne->enqueue(ss.str());
                                        ss.str("");
                                }
                                else
                                {
                                        ss << inputThree->dequeue();
                                        outputOne->enqueue(ss.str());
                                        ss.str("");
                                }
                        }
                        else if (!inputOne->isEmpty()&&inputTwo->isEmpty()&&!inputThree->isEmpty())
                        {
                                // 1 vs 3
                                if (inputOne->front() <= inputThree->front())
                                {
                                        ss << inputOne->dequeue();
                                        outputOne->enqueue(ss.str());
                                        ss.str("");
                                }
                                else
                                {
                                        ss << inputThree->dequeue();
                                        outputOne->enqueue(ss.str());
                                        ss.str("");
                                }
                        }
                }

                // output results
                cout << "Output: " << *outputOne;

                // finished, so we delete our queues
                delete inputOne;
                delete inputTwo;
                delete inputThree;
                delete outputOne;

                // return success
                return EXIT_SUCCESS;
        }
}
