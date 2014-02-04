
#include "Search.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>

using namespace std;

const double MICRO_SEC = pow(10,6);
const int ARRAY_SIZE = 100000;

int main()
{
	bool evaluate;
	double beginTime, endTime, diffTime, time;
	srand(clock());
	int target = rand()%ARRAY_SIZE;
	
	Search searchObject = Search(ARRAY_SIZE, 0);
	searchObject.init_array();
	cout << "Search Object Initialized" << endl;
	
	

	searchObject.init_sorted_array();
	cout << "Array Sorted " << endl;
	

	cout << "------------------------------------------" << endl;
	cout << "            Recursive Bin search          " << endl;
	cout << "-------------------------------------------" << endl;
	searchObject.resetCounter();

	beginTime = clock();
	evaluate = searchObject.recursive_binary_find(target, 0,searchObject.getSize());
	cout << searchObject.getCounter() << " Loops" << endl;
	if(evaluate) cout << "True" << endl;
	else cout << "False" <<endl;
	endTime = clock();
	
	diffTime = endTime - beginTime;

	cout << "Time: " << endl;
	time = (diffTime / CLOCKS_PER_SEC) * MICRO_SEC / searchObject.getCounter();
	cout << time << endl;
	

	cout << "------------------------------------------" << endl;
	cout << "             iterator Bin search           " << endl;
	cout << "-------------------------------------------" << endl;

	beginTime = clock();
	evaluate = searchObject.iterative_binary_find(target, 0,searchObject.getSize());
	cout << searchObject.getCounter() << " Loops" << endl;
	if(evaluate) cout << "True" << endl;
	else cout << "False" <<endl;
	endTime = clock();

	diffTime = endTime - beginTime;

	cout << "Time: " << endl;
	time = (diffTime / MICRO_SEC)  / searchObject.getCounter();
	cout << time << endl;
	

	cout << "------------------------------------------" << endl;
	cout << "            Sequiental Bin search         " << endl;
	cout << "-------------------------------------------" << endl;

	beginTime = clock();
	evaluate = searchObject.sequential_find(target);
	cout << searchObject.getCounter() << " Loops" << endl;
	if(evaluate) cout << "True" << endl;
	else cout << "False" <<endl;
	endTime = clock();
	
	diffTime = endTime - beginTime;

	cout << "Time: " << endl;
	time = (diffTime / CLOCKS_PER_SEC) * MICRO_SEC  / searchObject.getCounter();
	cout << setprecision(2) << time << endl;
	
	cout << "Target element: " << target << endl;
	system("PAUSE");
	return 0;

}