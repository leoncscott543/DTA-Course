// Linked List Lab.cpp : Defines the entry point for the console application.
// Implementing a Linked List
// Leon Scott: September 9, 2016

// Requirements:
// AddNode
// InsertNode
// DeleteNode
// PrintList
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


// this function is responsible for creating a linked list using our (node) structure as a user defined data type we just built above
node *AddNode() {

	node *first, *newNode, *last;
	/* I created three different pointer varaibles of the (node) type


	first: this node stays put
	newNode: this node makes the new node
	last: this node points to the last node

	*/
	int num; // this integer is will pass the user's input into the (new) created nodes

	int i = 0; // this integer is just for interfacing stuff... moving on
	cout << "Create a list of integers ending with 0: " << endl << endl << "Index " << i << ": "; // Im asking the user the enter a list of numbers that end with 0 so i know when to terminate the node creation process

	cin >> num; // user enters integer

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
int main()
{
	AddNode();

	char f;
	cin >> f;
	return 0;
}

