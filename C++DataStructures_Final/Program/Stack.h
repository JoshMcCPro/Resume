#pragma once
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// Stack Class
class DynamicStack {
private:
	// get binary nbr
	struct Node {
		// variables
		char c;
		Node* next;

		// constructor
		Node(char c) {
			this->c = c;
			next = NULL;
		}

	};
	// variables
	Node* top;

public:
	// constructor
	DynamicStack();
	// deconstructor
	~DynamicStack();
	// finds out if the stack is empty
	bool empty();
	// gets top of stack
	char getTop();
	// puts nbr on top of stack
	void push(char c);
	// deletes nbr on top of stack
	void pop();
	// displays the stack nbrs
	void printStack(int tag);
	// delets all stack nbrs
	void purgeStack();
	// Checks if stack is correct
	void CheckStack(int tag, int nbrofletters);

};
// constructor
DynamicStack::DynamicStack()
{
	top = NULL;
}
// deconstructor
DynamicStack::~DynamicStack()
{

}
// finds out if the stack is empty
bool DynamicStack::empty() {
	return (top == NULL);
}
// gets top of stack
char DynamicStack::getTop()
{
	if (top == NULL)
	{
		throw invalid_argument("Empty Stack!");
	}
	return top->c;
}
// puts nbr on top of stack
void DynamicStack::push(char newC)
{
	//cout << "Adding " << newC << " to top of stack." << endl;
	Node* temp = new Node(newC);
	temp->next = top;
	top = temp;
}
// deletes nbr on top of stack
void DynamicStack::pop()
{
	if (top == NULL)
	{
		throw underflow_error("Stack is Empty!");
	}

	cout << "Deleting " << top->c << " from stack." << endl;
	Node* temp = top;
	top = top->next;
	delete temp;
}
// displays the stack nbrs
void DynamicStack::printStack(int tag)
{
	Node* current = top;
	Node* temp;

	cout << "-----------------------------------" << endl;
	cout << tag + 1<< "| ";
	while (current != NULL)
	{
		temp = current;
		current = current->next;

		cout << temp->c << " ";
	
	}
	cout << endl;

}
// delets all stack nbrs
void DynamicStack::purgeStack()
{
	Node* current = top;
	Node* temp;

	//iterate until we reach end of list
	while (current != NULL) {
		temp = current;
		current = current->next;

		cout << "Deleting " << temp->c << endl;
		delete temp;
	}
}

// Check if the player has won the game
void DynamicStack::CheckStack(int tag, int NbrOfLetters)
{
	Node* current = top;
	Node* temp;
	string yourStack;

	cout << "-----------------------------------" << endl;
	cout << tag + 1 << "| ";
	while (current != NULL)
	{
		temp = current;
		current = current->next;

		cout << temp->c << " ";
		yourStack += temp->c;

	}
	cout << endl;

	cout << "Your Stack: " << yourStack << endl;

	if (NbrOfLetters == 3)
	{
		if (yourStack == "ABC")
		{
			cout << "You Won!" << endl;
			exit(0);
		}
		else
		{
			cout << "Incorrect" << endl;
		}
	}
	else if (NbrOfLetters == 4)
	{
		if (yourStack == "ABCD")
		{
			cout << "You Won!" << endl;
			exit(0);
		}
		else
		{
			cout << "Incorrect" << endl;
		}
	}
	else if (NbrOfLetters == 5)
	{
		if (yourStack == "ABCDE")
		{
			cout << "You Won!" << endl;
			exit(0);
		}
		else
		{
			cout << "Incorrect" << endl;
		}
	}
	else if (NbrOfLetters == 6)
	{
		if (yourStack == "ABCDEF")
		{
			cout << "You Won!" << endl;
			exit(0);
		}
		else
		{
			cout << "Incorrect" << endl;
		}
	}



}