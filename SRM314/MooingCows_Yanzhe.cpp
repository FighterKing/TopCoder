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
#include <climits>
#include <ctime>

using namespace std;


class MooingCows {
public:
	int dissatisfaction(vector <string> farmland) {
		int ret = INT_MAX;
		for (int i = 0; i < farmland.size(); i++) {
			for (int j = 0; j < farmland[0].size(); j++) {
				if (farmland[i][j] == 'C') {
					int dissat = 0;
					for (int x = 0; x < farmland.size(); x++) {
						for (int y = 0; y < farmland[0].size(); y++) {
							if (farmland[x][y] == 'C')
								dissat += (x-i)*(x-i) + (y-j)*(y-j);
						}
					}
					if (dissat < ret)
						ret = dissat;
				}
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	MooingCows *obj;
	int answer;
	obj = new MooingCows();
	clock_t startTime = clock();
	answer = obj->dissatisfaction(p0);
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"C..",".C.",".C."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"CCCC","CCCC","CCCC"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 26;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"C"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"CCC....","C......","....C.C",".C.CC..","C......"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 81;
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
// The cows in Byterland are mooing loudly, annoying the residents very much.  Mrs. Darcy of the villa Pemberley is planning to resolve this problem by allowing only one cow to moo.  She will pick the cow whose mooing is the least offensive to all the other cows.
// 
// The farmland in Pemberley is divided into n*m squares of grassland.  Each square is either empty or occupied by a single cow.  When a cow at (x,y) moos, the dissatisfaction of a cow at (i,j) is equal to the square of the distance between them: ((x-i)2 + (y-j)2).  The total dissatisfaction is the sum of the dissatisfaction of all the cows.
// 
// Return the minimal total dissatisfaction that can be achieved by allowing only a single cow to moo.  The farmland will be given as a vector <string>, where '.' characters denote empty squares, and 'C' characters denote squares occupied by cows.
// 
// DEFINITION
// Class:MooingCows
// Method:dissatisfaction
// Parameters:vector <string>
// Returns:int
// Method signature:int dissatisfaction(vector <string> farmland)
// 
// 
// CONSTRAINTS
// -farmland will contain between 1 and 50 elements, inclusive.
// -Each element of farmland will contain between 1 and 50 characters, inclusive.
// -Each element of farmland will contain the same number of characters.
// -Each character in farmland will be either uppercase 'C' or '.'.
// -farmland will contain at least one uppercase 'C'.
// 
// 
// EXAMPLES
// 
// 0)
// {"C..",
//  ".C.",
//  ".C."}
// 
// Returns: 3
// 
// 
// If we set the uppermost cow to moo, the total dissatisfaction will be 2+5;
// If we set the middle cow to moo, the total dissatisfaction will be 2+1;
// If we set the bottommost cow to moo, the total dissatisfaction will be 1+5.
// 
// Certainly we will choose the second plan.
// 
// 1)
// {"CCCC",
//  "CCCC",
//  "CCCC"}
// 
// Returns: 26
// 
// 
// 
// 2)
// {"C"}
// 
// Returns: 0
// 
// 3)
// {"CCC....",
//  "C......",
//  "....C.C",
//  ".C.CC..",
//  "C......"}
// 
// Returns: 81
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!