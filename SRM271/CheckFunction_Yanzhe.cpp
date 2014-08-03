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


class CheckFunction {
public:
	int newFunction(string code) {
		vector<int> dashes {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
		int ret = 0;
		for (auto c : code)
			ret += dashes[c-'0'];
		return ret;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	CheckFunction *obj;
	int answer;
	obj = new CheckFunction();
	clock_t startTime = clock();
	answer = obj->newFunction(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	string p0;
	int p1;
	
	{
	// ----- test 0 -----
	p0 = "13579";
	p1 = 21;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "02468";
	p1 = 28;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "73254370932875002027963295052175";
	p1 = 157;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
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
// You are given a string code containing a message composed entirely of decimal digits ('0'-'9'). Each digit consists of some number of dashes (see diagram below). A "check function" of a message is defined as the total number of dashes in the message. Return the value of the check function for the message represented in code.
// 
// 
// 
// 
// DEFINITION
// Class:CheckFunction
// Method:newFunction
// Parameters:string
// Returns:int
// Method signature:int newFunction(string code)
// 
// 
// NOTES
// -0 consists of 6 dashes, 1 consists of 2 dashes, 2 consists of 5 dashes, 3 consists of 5 dashes, 4 consists of 4 dashes, 5 consists of 5 dashes, 6 consists of 6 dashes, 7 consists of 3 dashes, 8 consists of 7 dashes, 9 consists of 6 dashes.
// 
// 
// CONSTRAINTS
// -code will contain between 1 and 50 characters, inclusive.
// -Each character in code will be a digit ('0'-'9').
// 
// 
// EXAMPLES
// 
// 0)
// "13579"
// 
// Returns: 21
// 
// 1 consists of 2 dashes;
// 3 consists of 5 dashes;
// 5 consists of 5 dashes;
// 7 consists of 3 dashes;
// 9 consists of 6 dashes;
// 2 + 5 + 5 + 3 + 6 = 21.
// 
// 1)
// "02468"
// 
// Returns: 28
// 
// 2)
// "73254370932875002027963295052175"
// 
// Returns: 157
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
