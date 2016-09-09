// Linked List Lab.cpp : Defines the entry point for the console application.
// Implementing a Linked List
// Leon Scott: September 9, 2016
// When i say "we" in the comments, I am referring to the compiler and I :) 

// Requirements:
// CreateList (checkmate)
// PrintList
// InsertNode
// DeleteNode
// SearchList
// ReverseList

#include "stdafx.h"
#include <iostream>

using namespace std;


// this is our structure for a node 
struct node {
	node *link; // this is pointer that will link to the next pointer in the list
	int value; // this is the value that will be stored in each pointer
};


// this function is responsible for creating a linked list using the (node) structure as a user defined data type that I built above
node *CreateList() {

	node *first, *newNode, *last;
	/* I created three different pointer varaibles of the (node) type


	first: this node stays put
	newNode: this node makes the new node
	last: this node points to the last node

	*/

	int num; // this integer is will pass the user's input into the (new) created nodes

	int i = 0; // this integer is just for interfacing stuff... moving on


		// Im asking the user the enter a list of numbers that end with 0 so i know when to terminate the node creation process
		cout << endl << endl << "Type integer and press [ENTER] (dont use 0) to add your values to the list.\n\nWhen you're done, just enter 0: " << endl << endl << "Index " << i << ": "; 

		// user enters integer
		cin >> num; 

	first = NULL; // its important that we initialize our (current) pointer to NULL so that we know when we are at the beginning of the list

	last = NULL; // we have to initialize this one as well.... i was getting an initialization error without so.... this should fix it

				 // everything in this while loop is the process of creating our Linked Listed nodes... when we hit 0, the list is over
	while (num != 0)
	{
		newNode = new node; // lets boogie! We take our newNode pointer that we made above and point it to a dynamically allocated (node) type varaible


							// now that we have our first node, lets define its contents!!


		newNode->value = num; // we set the value of integer value of that node to the (num) the user gave us
		newNode->link = NULL; // we set the link (the pointer) of the node to NULL 

							  // so if our (first) pointer we made is equal to NULL, we are in the beginning of the list
		if (first == NULL)
		{
			first = newNode; // so we point our first node pointer to our newNode;
			last = newNode; // and we point our last node pointer to our newNode as well

							// we do this because if (first is equal to NULL) we are at the beginning of the list.... 
							// (first) always will be the first node, and (last) will continue to shift to the last newNode as you'll see in our else statement

		}

		else
		{
			last->link = newNode; // point our link in (last) pointer of type (node) to newNode
			last = newNode; // point the type (node) to our newNode
		}

		i++; // add one to our (i) so that we can print out "Index i: " so the user knows how large their list is when they are building it 
		cout << "Index " << i << ": "; // hence....  ^^^^^
		cin >> num; // user enters the next number in the list

	} // loop comes to a close

	return first; // we return the first node in our list....
}

// this is my printing function.... I've changed the name of the Initial_Node that was passed to (first)... just trying to keep a level of consistency
void PrintList(node *first) 
{
	int i = 0; // this is used for interfacing, nothing super special 

	node *current; // lets make a node pointer called current.... we will print the value of this node as we progress through the list

	current = first; // we initially point current to first.... so this will be the first node that is printed 


	// OK LETS WORK SOME MAGIC 
	 ////////////////////////
	       ///////////
		      ///

	while (current != NULL) // So within this loop we will print the current value of our nodes until we hit 0 (which, if you remember, is our termination value we made in our CreateList() function above)
	{
		cout << "Index " << i << ": " << current->value << endl; // we print the current value of our node

		current = current->link; // and then I point the current node to the next link within the node (in plain english, we are jumping to the next space in the list) 

		i++; // increase index being printed.... hopefully this puts a smile on the user's face
	}

	return;
}

// main function is tasked with managing manaing interactions between the user and the functions the user may want to use
int main()
{
	node *Initial_Node; // this node will be used to begin new processes

	cout << "Hello Earthling! Lets make a list !!";

	Initial_Node = CreateList(); // we point the node to our CreateList function that creates a list and returns our (first) node.... 
								 // so in essense Initial_Node is pointing to (first) node

	int user_options;

options:
	cout << endl << endl << "What would you like to do next? " << endl << endl;


re_enter:

		cout << "[1] Create a new list" << endl;
		cout << "[2] Print your list" << endl;
		/*cout << "[3] Insert value" << endl;
		cout << "[4] Delete value" << endl;
		cout << "[5] Search for value" << endl;
		cout << "[6] Reverse List" << endl;
		cout << "[7] Sort List" << endl;*/

		cout << endl << "[OPTION]: ";

			cin >> user_options;
	
			if (user_options == NULL)
			{
				cout << "sorry, thats not a valid entry. Just use integers" << endl << endl; 
				goto re_enter;
			}
			else 
			{
				switch (user_options)
				{
					case 1: 
					{
						CreateList(); // this will just run the the CreateList function again

						goto options;

						break;
					}

					case 2:
					{
						cout << endl << endl << "Wala!" << endl; 

						PrintList(Initial_Node); // this prints the list that we made... we pass the first node in our list to this function as a starting point for printing

						goto options;

						break;
					}

					/*case 3:
					{
						break;
					}

					case 4:
					{
						break;
					}

					case 5:
					{
						break;
					}

					case 6:
					{
						break;
					}

					case 7:
					{
						break;
					}*/
				}
			}

	
	
	 

	char f;
	cin >> f;
	return 0;
}

