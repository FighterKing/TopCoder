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


class TheEquation {
public:
	int leastSum(int X, int Y, int P) {
		for (int sum = 2; ; sum++) {
			for (int a = 1; a < sum; a++) {
				int b = sum - a;
				if ((a*X + b*Y) % P == 0)
					return sum;
			}
		}
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	TheEquation *obj;
	int answer;
	obj = new TheEquation();
	clock_t startTime = clock();
	answer = obj->leastSum(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	int p3;
	
	{
	// ----- test 0 -----
	p0 = 2;
	p1 = 6;
	p2 = 5;
	p3 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 5;
	p1 = 5;
	p2 = 5;
	p3 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 998;
	p1 = 999;
	p2 = 1000;
	p3 = 501;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 1;
	p1 = 1;
	p2 = 1000;
	p3 = 1000;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 347;
	p1 = 873;
	p2 = 1000;
	p3 = 34;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
// You are given three positive integers, X, Y and P. Return the least sum of two positive integers a and b such that P is a divisor of a*X+b*Y.
// 
// DEFINITION
// Class:TheEquation
// Method:leastSum
// Parameters:int, int, int
// Returns:int
// Method signature:int leastSum(int X, int Y, int P)
// 
// 
// NOTES
// -The answer is never greater than 2*P: if a = P and b = P, then P is definitely a divisor of a*X+b*Y.
// 
// 
// CONSTRAINTS
// -X, Y and P will each be between 1 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 6
// 5
// 
// Returns: 3
// 
// When a=2 and b=1, a*X+b*Y is 10, which is a multiple of P=5. No other valid pair of values for a and b has a smaller sum.
// 
// 1)
// 5
// 5
// 5
// 
// Returns: 2
// 
// Don't forget that a and b must be positive.
// 
// 2)
// 998
// 999
// 1000
// 
// Returns: 501
// 
// 
// 
// 3)
// 1
// 1
// 1000
// 
// Returns: 1000
// 
// 
// 
// 4)
// 347
// 873
// 1000
// 
// Returns: 34
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!