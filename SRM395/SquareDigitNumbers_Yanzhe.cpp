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


class SquareDigitNumbers {
private:
    bool isSquareDigitNumber(int n) {
        while (n > 0) {
            int d = n % 10;
            if (d != 0 && d != 1 && d != 4 && d != 9)
                return false;
            n = n / 10;
        }
        return true;
    }
public:
	int getNumber(int n) {
        int c = -1;
        while (n >= 0) {
            c++;
            while (!isSquareDigitNumber(c))
                c++;
            n--;
        }
        return c;
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
	SquareDigitNumbers *obj;
	int answer;
	obj = new SquareDigitNumbers();
	clock_t startTime = clock();
	answer = obj->getNumber(p0);
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
	p0 = 0;
	p1 = 0;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 5;
	p1 = 11;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 16;
	p1 = 100;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 121;
	p1 = 1941;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 123;
	p1 = 1949;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
// You enjoy working with numbers that contain only square digits (namely, 0, 1, 4 and 9).  The sequence containing only these digits is 0, 1, 4, 9, 10, 11, 14...   Return the n-th term (indexed from 0) in this sequence.
// 
// DEFINITION
// Class:SquareDigitNumbers
// Method:getNumber
// Parameters:int
// Returns:int
// Method signature:int getNumber(int n)
// 
// 
// CONSTRAINTS
// -n will be between 0 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 0
// 
// Returns: 0
// 
// The first square digit number is 0.
// 
// 1)
// 5
// 
// Returns: 11
// 
// 
// 
// 2)
// 16
// 
// Returns: 100
// 
// 
// 
// 3)
// 121
// 
// Returns: 1941
// 
// 
// 
// 4)
// 123
// 
// Returns: 1949
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
