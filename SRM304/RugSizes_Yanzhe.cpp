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


class RugSizes {
public:
	int rugCount(int area) {
		int ret = 0;
		int upb = (int)sqrt(area);
		for (int i = 1; i <= upb; i++) {
			if (area % i == 0) {
				if (i % 2 == 0 && (area / i) % 2 == 0 && i * i != area)
					continue;
				ret++;
			}
		}
		return ret;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	RugSizes *obj;
	int answer;
	obj = new RugSizes();
	clock_t startTime = clock();
	answer = obj->rugCount(p0);
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
	
	int p0;
	int p1;
	
	{
	// ----- test 0 -----
	p0 = 4;
	p1 = 2;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 8;
	p1 = 1;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
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
// 
// Rugs come in various sizes. In fact, we can find a rug with any integer width
// and length, except that no rugs have a distinct width and length that are both even integers. For example, we can find a 4x4 rug, but not a 2x4 rug.  We want to know how many different choices we have for a
// given area.
// 
// Create a class RugSizes the contains a method rugCount that is given the desired
// area and returns the number of different ways in which we can choose a rug size that
// will cover that exact area.
// Do not count the same size twice -- a 6 x 9 rug and a 9 x 6 rug should be 
// counted as one choice.
// 
// 
// 
// DEFINITION
// Class:RugSizes
// Method:rugCount
// Parameters:int
// Returns:int
// Method signature:int rugCount(int area)
// 
// 
// CONSTRAINTS
// -area will be between 1 and 100,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 4
// 
// Returns: 2
// 
// 
// 
//    The choices are 1 x 4 (or equivalently 4 x 1) and 2 x 2.
// 
// 
// 
// 1)
// 8
// 
// Returns: 1
// 
//  
// 
//    Only 1 x 8 is available. Note that 2 x 4 has the desired area, but is not
//    available since its width and length differ and are both even numbers.
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!