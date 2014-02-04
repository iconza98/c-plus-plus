// Ikani Samani
// 
//
// HastTable driver

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "HashTable.h"

using namespace std;

// function prototypes:

int main()
{

	HashTable table = HashTable();
	cout << "Default HashTable created" << endl;
	ifstream input;
	cout << "opening elements text file" << endl;
	input.open("elements.txt");	
	if (input.fail())
	{
		cout << "\n-------------------" << endl;
		cout << "File failed to open" << endl;
		cout << "-------------------" << endl;
		system("PAUSE");
		exit(0);
	}

	if(!(input.bad()))
	{
		char c;
		string word;
		double num;

		cout << "Opening File Sucessful" << endl;
		while(!input.bad() && !input.eof())
		{
			if(isalpha(input.peek()))
			{
				input >> c;
					word.push_back(c);		
			}
			if(islower(input.peek()))
			{
				input >> c;
				word.push_back(c);
				if(islower(input.peek()))
				{
					input >> c;
					word.push_back(c);
				}
			}

			if(isdigit(input.peek()))
			{
				string temp;
				// read in the element weight
				getline(input, temp);
				num = atof(temp.c_str());

				// create hashtable element
				table.insert(word, num);
				// cout << word << ' ' << num << endl;
				// clear word,
				word.clear();
	
			}
			else input.ignore();
		}
		input.close();

		cout << "\nAll items inserted into HashTable" << endl;
		cout << "=====================================" << endl;
	}
	
	cout << "\nUsed spaced: " << table.getSize() << endl;
	
	table.print();
	

	// ===============================================================================
	// read from the file and calculate the weight
	cout << "Read Formula files and Calculate" << endl;
	ifstream formula;
	cout << "opening Formula text file" << endl;
	formula.open("formulas.txt");
	if (formula.fail())
	{
		cout << "\n-------------------" << endl;
		cout << "File failed to open" << endl;
		cout << "-------------------" << endl;
		system("PAUSE");
		exit(0);
	}
	if(!(formula.fail()))
	{
		cout << "Opening File Sucessful" << endl;


		double sum = 0;
		double variable1 = 0;
		double number = 0;
		string word;
		char c;
		cout << "Reading from File.." << endl;

		while(!formula.bad() && !formula.eof())
		{
			if(isalpha(formula.peek()))
			{
			
				if(isupper(formula.peek())) // checks to see if is encountering another atom
				{
					
					if (!(word.empty()))
					{
						// process the word
						double hashspitback = table.retrieve(word);
						sum += hashspitback;
						cout << word;
						word.clear();

						// enter capital letter to char array
						formula >> c;
						word.push_back(c); 
					}
					else
					{
						formula >> c;
						word.push_back(c);
					}
				}
				if (islower(formula.peek()))
				{
					formula >> c;
					word.push_back(c);
					if (islower(formula.peek()))
					{
						formula >> c;
						word.push_back(c);
					}
				}
			}
			if(isdigit(formula.peek()))
			{
				char n;
				string temp;
				// read in number and multiple it by the element;
				formula >> n;
				temp.push_back(n);

				if(isdigit(formula.peek()))
				{	
					
					formula >> n;
					temp.push_back(n);
					number = stoi(temp);

				}
				else
				{
					number = stoi(temp);
				}
		

				// multiply the number and add it to sum.
				double hashspitback = table.retrieve(word);
				hashspitback *= number;
				sum += hashspitback;
				cout << word << number;
				word.clear();
			}
			if(formula.peek() == '(') // parentesis
			{
				if( !(word.empty()))
					{
						sum += table.retrieve(word);
						cout << word;
						word.clear();
					}
				if (formula.peek() == '(')
					{
						formula >> c;
						cout << c;
						word.clear();
					}
				while (formula.peek() != ')')
					{
						if(isalpha(formula.peek()))
						{
			
							if(isupper(formula.peek())) // checks to see if is encountering another atom
							{
					
								if (!(word.empty()))
								{
									// process the word
									double hashspitback = table.retrieve(word);
									variable1 += hashspitback;
									cout << word;
									word.clear();

									// enter capital letter to char array
									formula >> c;
									word.push_back(c); 
								}
								else
								{
									formula >> c;
									word.push_back(c);
								}
							}
							if (islower(formula.peek()))
							{
								formula >> c;
								word.push_back(c);
								if (islower(formula.peek()))
								{
									formula >> c;
									word.push_back(c);
								}
							}
						}
						if(isdigit(formula.peek()))
						{
							char n;
							string temp;
							// read in number and multiple it by the element;
							formula >> n;
							temp.push_back(n);

							if(isdigit(formula.peek()))
							{	
					
								formula >> n;
								temp.push_back(n);
								number = stoi(temp);

							}
							else
							{
								number = stoi(temp);
							}
		

							// multiply the number and add it to sum.
							double hashspitback = table.retrieve(word);
							hashspitback *= number;
							variable1 += hashspitback;
							cout << word << number;
							word.clear();
						}
				}

			}
			if(formula.peek() == ')')
			{
				if(!(word.empty()))
				{
					// process the word
					double hashspitback = table.retrieve(word);
					variable1 += hashspitback;
					cout << word;
					word.clear();
				}
				formula >> c;
				cout << c; // display ')' char

				if(isdigit(formula.peek()))
				{
					formula >> number;
					variable1 *= number;
					cout << number;
				}
				sum += variable1;
				variable1 = 0;
				word.clear();


			}
			if(formula.peek() == '\n' ) // check if \n
			{
				
				if (!(word.empty()))
				{
					// process the word
					double hashspitback = table.retrieve(word);
					sum += hashspitback;
					cout << word;
					word.clear();
				}
				cout << " The weight of molecue is: " << sum << endl;
				// clear out data memebers that need to be reset
				word.clear();
				number = 0;
				variable1 = 0;
				sum = 0;
				formula.ignore();

			}

		}

	}


	system("pause");
	return 0;
}
// use this function to parse in fomulas and do calculations



