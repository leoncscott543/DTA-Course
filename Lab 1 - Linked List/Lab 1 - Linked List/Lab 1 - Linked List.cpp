// Linked List Lab.cpp : Defines the entry point for the console application.
// Implementing a Linked List
// Leon Scott: September 9, 2016
// When i say "we" in the comments, I am referring to the compiler and I :) 

// Requirements:
// CreateList (checkmate)
// PrintList (checkmate)
// InsertNode (checkmate)
// DeleteNode (checkmate)
// SearchList (checkmate)
// ReverseList (checkmate)
// ListSize (checkmate)

#include "stdafx.h"
#include <iostream>
using namespace std;




// this is our structure for a node 
struct node {
	node *link; // this is pointer that will link to the next pointer in the list
	int value; // this is the value that will be stored in each pointer
};


// this function is responsible for returning the size of the user's list.... this could come in handy throughout this program
int ListSize(node *first) 
{
	int size = 0; // we start the size of the list with 0 as our base case
	node *current; // defining the node to hop through the list

	current = first; // set this node equal to our firt node in the the linked list


	 // the while loop will progress until we get to the end of the list (or when the last node's link is a NULL address)
	while (current->link != NULL) 
	{
		size++; // increase (size) by 1 each loop.... aka we're counting each node in the list

		current = current->link; // progress through the loop by pointing our current [node] to the next node in the user's link
	}

	return size; // the function concludes by returning the (size) of the list. Now I can simply call this function whenever I need to utilize it
}

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
		std::cin >> num; 

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
		std::cin >> num; // user enters the next number in the list

	} // loop comes to a close

	return first;
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

// this function allows the user to enter a new value anywhere inside of their list
void InsertNode(node *first)
{
	int index; // I made this integer so that the while loop knows how many times to loop as we traverse through our list

	node *current; // this node pointer keeps track of where we are in the list
	node *insert = new node; // its important that i make a new node called (insert)... this node is the node that the user essentially wants to add

	int place = 0; // this integer used to keep track of where in the list a switch needs to be made (see the while loop)

	current = first; // just setting the current node to the first node in the loop

	insert->value = NULL; // setting our (insert) node to NULL just as a base case;

// this place holder is used if the user enters an invalid input
option1:
	cout << endl << endl << "What value would you like to INSERT? "; 
	std::cin >> insert->value;

// this place holder is used if the user enters an invalid input
option2:
	cout << endl << "Here's your list again!" << endl << endl;

	PrintList(current); // the list is printed again for the user's sake... all hail the user


	cout << endl << "At which ELEMENT index would you like to INSERT your value? "; 
	std::cin >> index;
	
	// base case scenarios
	if (index == 0)
	{
		insert->link = first; 
		first = insert;
		
		cout << endl << "Here's your new list" << endl << endl;

		PrintList(first);
		return;
	}
			// alright, so here are our correction statements.... in the case that the user integers a number larger than a list or something thats not an integer
			else if (index > ListSize(first))
			{
				cout << endl << endl << "********** TRY AGAIN! INTEGER CANNOT BE GREATER THAN SIZE OF LIST*************";
				goto option1;
			}
			else if (index == NULL)
			{
				cout << endl << endl << "******* TRY AGAIN! INTEGERS ONLY PLEASE !! ***********";
				goto option2;
			}


	// this loop is responsible for traversing the loop up until (current) node reaches the spot where the user wants to add a value after
	while (place < index)
	{
		current = current->link;
		place++;
	}

	// another base case scenario... just in case the user wants to change the last element in the list
	if (index == (ListSize(first)-1))
		{
		insert = current->link; 
		return; 
		}
	// this is the fun part
	insert->link = current->link; // I took the new node the user made, pointed it's link to the next node in the linked list....
	current->link = insert; // and then I took current's link and pointed it to insert!!! So essentially we placed (insert)'s contents in the list as if it was always there. 

	cout << endl << endl << "Great! Here's your new list!" << endl << endl;

	PrintList(first); // printing list again so the user can see their new value

	return;
}

// this function allows the user the delete any node in the list they've made
void DeleteNode(node *first)
{
	node *left, *byebye, *right;

	// these three pointers are really vital... they allow me to point one node to another while deleting the node inbetween them. 
	left = first;
	byebye = first;
	right = first; 

	// for the while loop
	int index;
	int i = 0;

option: // starting place in case user enters invalid integer

	cout << endl << endl;
	// prints the list again for reference
	PrintList(first);

	
	cout << endl << endl << "Here's your list for reference... Which INDEX would you like to DELETE? ";

	std::cin >> index; // user enters the element they would like to delete. 



	// base case scenario... just trying to prevent a crash thats all :)
	if (index == 0)
	{
		first = first->link; // we move our (first) node pointer forward so that it doesn't get deleted. 

		delete byebye; // delete (node) 0 from the heap

		cout << "No problem! Here's your new list! " << endl << endl;

		PrintList(first); // print new list for all to see

		return;
	}

	else if (index == NULL || index > ListSize(first))
	{
		cout << endl << endl << "********** INVALID ENTRY!!! PLEASE ENTER AN INTEGER FROM 0 TO " << ListSize(first) << " **********";

		goto option;
	}


	// the following loops traverse our three pointers through the linked list to their assigned spots...
	// the three pointers should be lined up right next to each other
	// pointer 2 (byebye) is the one in the middle, and this is the one that will be deleted lol quite obviously
	while (i < index-1)
	{
		left = left->link;

		i++;
	}

	i = 0;

	while (i < index)
	{
		byebye = byebye->link;

		i++;
	}

	i = 0;

	while (i <= index)
	{
		right = right->link;

		i++;
	}


	// we point the left's link to the right node
	left->link = right;

	// and then we delete the middle node (which is the node the user wants to delete of course) bye bye :)
	delete byebye;

	cout << "No problem! Here's your new list! " << endl << endl;

	PrintList(first); // print new list for all to see

	return;
}

// this function is responsible for searching for specific values in the list, outputing where they are found, and outputing the number of occurances 
void SearchList(node *first)
{
	node *check;

	check = first; 

	int i = 0;
	int occur = 0; // keep track of while loops
	int size = ListSize(first);

	int search;

	cout << endl << endl << "What number are you looking for? ";

	std::cin >> search;

	cout << endl;

	while (i < size)
	{
		if (check->value == search)
		{
			occur++;

			cout << endl << "Index: " << i << " = " << search;
		}

		check = check->link;
		i++;
	}

	cout << endl << endl << "OCCURANCES: " << occur; 

	return;
}

/*void ReverseList(node *first)
{
	int i = 0;
	int c = ListSize(first);
	int size = ListSize(first);

	node *last = NULL;

	node *rev = new node; 

	node *cur;

	rev = first; 

	while (c >= 0)
	{
		cur = first;
		while (i < size)
		{
			cur = cur->link;
			size--;
		}
		rev->value = cur -> value; 
		rev->link = NULL; 

		if (cur->link = NULL)
		{
			first = rev;
			last = rev; 
		}
		else
		{
			last->link = rev;
		}

		c--;
	}



	cout << endl << endl;

	PrintList(first);

	return;
}*/


// main function is tasked with managing manaing interactions between the user and the functions the user may want to use
int main()
{
	node *Initial_Node; // this node will be used to begin new processes

	cout << "Hello Earthling! Lets make a list !!"; // this is how the program will start

	Initial_Node = CreateList(); // we point the node to our CreateList function that creates a list and returns our (first) node.... 
								 // so in essense Initial_Node is pointing to (first) node
								 // this will also trigger the CreateList() program to start running.... 
										// i had a problem with this running when i didnt want it to, so i just moved it to the top of the main function... quick fix

	int user_options; // this is used to keep track of what the user wants to do


options: // hear no evil speak no evil lol this is a place to jump back to if the user doesnt enter an integer

	cout << endl << endl << "What would you like to do next? " << endl << endl; 


re_enter: // so if the user enters a non integer or a number larger than 8, we just jump back to this point

		// these are the user's options
		cout << "[1] Create a new list" << endl;
		cout << "[2] Print your list" << endl;
		cout << "[3] Insert value" << endl;
		cout << "[4] Delete value" << endl;
		cout << "[5] Search for value" << endl;
		cout << "[6] Reverse List" << endl;
		cout << "[7] Size of List" << endl;

		cout << endl << "[OPTION]: ";

			std::cin >> user_options;
	
			if (user_options == NULL || user_options > 8 || user_options == 0) // base case scenario.... we send them back up to the options with clearer instructions on how to choose an option. 
			{
				cout << endl << endl << "*********** sorry, thats not a valid entry. Just use integers from 1 to 7 *************" << endl << endl; 
				goto re_enter;
			} 
			else // so if there are no user errors, then we can run the switch conditonal statement.... each case runs one of the 7 functions that the user chose
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

					case 3:
					{
						// run the insertnode function and pass our initial_node pointer
						InsertNode(Initial_Node);

						goto options;

						break;
					}

					case 4:
					{
						// run our deletenode function and pass our initial_node pointer
						DeleteNode(Initial_Node);

						goto options;

						break;
					}

					case 5:
					{
						// calling the searchlist funtion and passing our initial_node which would be *first
						SearchList(Initial_Node);

						goto options;

						break;
					}

					/*case 6:
					{
						ReverseList(Initial_Node);
						break;
					}*/

					case 7:
					{
						cout << endl << endl << "List size: [ " << ListSize(Initial_Node) << " ]";
					}
				}
			}

	
	
	 

	char f;
	std::cin >> f;
	return 0;
}

