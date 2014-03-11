// Ikani Samani
// Project: Stack
//
// Disclaimer: 
// I Ikani Samani have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library.
// I understand that any violation of this disclaimer will result in a 0 for the project.
// ----------------------------------------------------------------------------------------------------
//

/*
	Put main and other function(s) to convert infix to postfix in here.
*/

#include "stack.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
using namespace samani_stack;

// prototype function
void postifix_output(istream& );
int precendence(char );

int main()
{
	cout << "INFIX to POSTFIX EXPRESSION" << endl;
	
	// create an ifstream object to read file
	ifstream input;
	input.open("tests.txt");
	if (!input)
	{
		cout << "\n-------------------" << endl;
		cout << "File failed to open" << endl;
		cout << "-------------------" << endl;
		system("PAUSE");
		exit(0);
	}
	if(input)
	{
		cout << "Opening File Sucessful" << endl;
		postifix_output(input);
	}
	
	input.close();
	system("PAUSE");
	return 0;
}
// Precondition: expression is fully parenthesized
void postifix_output(istream& ins)
{
	const char RIGHT_PARENTHESIS = ')';

	stack<char> operations;
	int number;
	char symbol;

	// Looop continues whil istream is not "bad"
	// (tested by ins) and next charater isn't newline
	while (ins)
	{
		// test for newline character
		if (ins.peek() == '\n')
		{
			while (!operations.empty())
			{
				symbol = operations.top();
				operations.pop();
				cout << symbol;
			}
			ins.ignore();
			cout << '\n';
		}
		// test for digit, and display
		else if (isdigit(ins.peek()))
		{
			ins >> number;
			cout << number;
		}
		else if (isalpha(ins.peek()))
		{
			char letter;
			ins >> letter;
			cout << letter;
		}
		// test for operator char and push on the stack if it is
		else if (strchr("+-*/", ins.peek()) != NULL)
		{
			ins >> symbol;

			// check for prcedence
			while(!operations.empty() && precendence(operations.top()) >= precendence(symbol))
			{
					char current_symbol = operations.top();
					cout << current_symbol;
					operations.pop();
			}
			operations.push(symbol);

		}
		else if (ins.peek() == RIGHT_PARENTHESIS && !operations.empty())
		{
			symbol =  operations.top();
			cout << symbol;
			operations.pop();
			ins.ignore();
			// might need to push onto the stack
		}
		else
		{
			ins.ignore();
		}
	}
}
int precendence(char x)
{
	switch(x)
	{
	case '*': return 3;
	case '/': return 3;
	case '+': return 2;
	case '-': return 2;

	default: return 0;
	}
}

