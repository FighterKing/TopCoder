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
#include <iterator>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class EratosthenSieve2 {
public:
	int nthElement(int n) {
		list<int> v(1000);
		int c(1);
		generate(v.begin(), v.end(), [&]{ return c++; });

		for (int s = 2; s <= 10; s++) {
			auto it = v.begin();
			int N = v.size();
			for (int i = 0; i < N / s; i++) {
				advance(it, s - 1);
				it = v.erase(it);
			}
		}

		vector<int> output;
		std::copy(v.begin(), v.end(), back_inserter(output));
		return output[n-1];
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
	EratosthenSieve2 *obj;
	int answer;
	obj = new EratosthenSieve2();
	clock_t startTime = clock();
	answer = obj->nthElement(p0);
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
	p0 = 3;
	p1 = 7;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 1;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 10;
	p1 = 79;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 25;
	p1 = 223;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
// Let N1 = {1, 2, 3, 4, 5, ..., 1000} (the set of all positive integers between 1 and 1000, inclusive).
// 
// 
// Delete every second number in N1. The result is N2 = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, ..., 999}.
// 
// 
// Delete every third number in N2. The result is N3 = {1, 3, 7, 9, 13, 15, 19, 21, 25, ..., 999}.
// 
// 
// Delete every fourth number in N3. The result is N4 = {1, 3, 7, 13, 15, 19, 25, 27, ...}.
// 
// 
// ...
// 
// 
// Delete every tenth number in N9. The result is N10. Find and return the n-th element of sequence N10, where n is a 1-based index.
// 
// 
// 
// DEFINITION
// Class:EratosthenSieve2
// Method:nthElement
// Parameters:int
// Returns:int
// Method signature:int nthElement(int n)
// 
// 
// NOTES
// -N10 will contain exactly 101 elements.
// 
// 
// CONSTRAINTS
// -n will be between 1 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// 
// Returns: 7
// 
// 1)
// 1
// 
// Returns: 1
// 
// 2)
// 10
// 
// Returns: 79
// 
// 3)
// 25
// 
// Returns: 223
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!