/*
GitHub Repository: 
[Group work]
Main Programmer: 
August Bryan N.Florese
Researchers: 
Bryan Teddy Alvarico
Ian Pacelo
Rowell Ferrer
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <tuple>
#include <stdlib.h>

using namespace std;


void Display();
void Reverse_Display();
struct Node {
	char data;
	Node *next;
	Node *previous;
};

//GLOBAL
Node *head = NULL;
Node *tail = NULL;
Node *node = NULL;
int List_Size = 0;





void Add_Node(char letter) {
	node = new Node;
	node->next = NULL;
	node->previous = NULL;
	node->data = letter;
	if (head == NULL) {
		head = tail = node;
		List_Size++;
	}
	else if (node->previous == NULL && List_Size == 1){
		node->previous = head;
		tail->next = node;
		tail = node;
		List_Size++; //Not sure if there's a better way to initialize the first previous node.
	}
	else {
		tail->next = node;
		node->previous = tail;
		tail = node;
	}
}

tuple<int, string> Initialize() {
	cout << "We will now create your linked list. \n";
	cout << "First, enter the number of elements. \n";
	int Size;
	string Line;
	while (!(cin >> Size)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << ": ";
	} cin.ignore(1000, '\n');
	cout << "Now, enter characters up to your limit [" << Size << "] delimited by spaces: ";
	getline(cin, Line); cin.ignore(1000, '\n');
	return make_tuple(Size, Line);
} //For c++11 use make_pair with pair<1,2>

//In Php, the term explode is used when a string is separated by a delimiter
void Explode(int Size , string Line) {
	int temp = Size;
	for (int i = 0; i <= Line.length() - 1; i++) {
		if (isspace(Line[i]) && temp <= 0 || temp <= 0){
			//Do nothing!
		}
		else if (!isspace(Line[i])) {
			Add_Node(Line[i]);
			temp--;
		}
	}
}

void Display() {
	node = head;
	cout << "{ ";
	while (node != NULL) {
		if (node == tail) {
			cout << node->data;
			node = node->next;
		}
		else {
			cout << node->data << ", ";
			node = node->next;
		}
	} cout << " } ";
	system("pause");
}

void Reverse_Display() {
	node = tail;
	cout << "{ ";
	while (node != NULL) {
		if (node == head) {
			cout << node->data;
			node = node->previous;
		}
		else {
			cout << node->data << ", ";
			node = node->previous;
		}
	} cout << " } ";
	system("pause");
}

void Menu() {
	int choice;
	system("cls");
	cout << "[1] Display in-order" << endl;
	cout << "[2] Display in reverse order" << endl;
	cout << "[3] Exit program" << endl;
	cout << "Choice: ";
	cin >> choice;
	switch (choice) {
	case 1:Display();break;
	case 2:Reverse_Display();break;
	case 3:exit(1);break;
	}
}

int main()
{
	int Size; string Line;
	//Tie function for pre-initialized tuple variables | Tuple returns two types
	tie(Size, Line) = Initialize();
	//Creates the nodes
	Explode(Size, Line);
	while (true) {
		//Looping menu items
		Menu();
	}
	return 0;
}