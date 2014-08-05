#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class LCMRange {
public:
	int lcm(int first, int last) {
		int ret = last;
		while (true) {
			int i;
			for (i = first; i < last; i++) {
				if (ret % i != 0) {
					ret += last;
					break;
				}
			}
			if (i == last) return ret;
		}
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	LCMRange *obj;
	int answer;
	obj = new LCMRange();
	clock_t startTime = clock();
	answer = obj->lcm(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 5;
	p2 = 60;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 4;
	p1 = 5;
	p2 = 20;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 12;
	p2 = 27720;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// The least common multiple of a group of integers is the smallest number that can be evenly divided by all the integers in the group.  Given two ints, first and last, find the least common multiple of all the numbers between first and last, inclusive.
// 
// DEFINITION
// Class:LCMRange
// Method:lcm
// Parameters:int, int
// Returns:int
// Method signature:int lcm(int first, int last)
// 
// 
// CONSTRAINTS
// -first will be between 1 and 12, inclusive.
// -last will be between first and 12, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 5
// 
// Returns: 60
// 
// The following statements show how 60 can be divided by all numbers from 1 to 5:
// 1*60 = 60
// 2*30 = 60
// 3*20 = 60
// 4*15 = 60
// 5*12 = 60
// 
// 1)
// 4
// 5
// 
// Returns: 20
// 
// Although 60 would be a common multiple for 4 and 5, 20 is the least common multiple.
// 
// 2)
// 1
// 12
// 
// Returns: 27720
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
