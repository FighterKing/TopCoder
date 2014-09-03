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


class PalindromicSubstringsDiv2 {
private:
	bool isPalindorme(string str) {
		for (int i = 0, j = str.size() - 1; i <= j; i++, j--)
			if (str[i] != str[j])
				return false;
		return true;
	}
public:
	int count(vector <string> S1, vector <string> S2) {
		string target = "";
		for (auto c : S1)
			target += c;
		for (auto c : S2)
			target += c;

		int N = target.size();
		int ret = 0;

		bool **memo;
		memo = new bool* [N];
		for (int i = 0; i < N; i++)
			memo[i] = new bool [N];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				memo[i][j] = false;

		// length = 1
		for (int i = 0; i < N; i++)
			memo[i][i] = true;
		ret += N;

		// length = 2
		for (int i = 0; i < N - 1; i++)
			if (target[i] == target[i+1]) {
				memo[i][i+1] = true;
				ret++;
			}

		// length >= 3
		for (int len = 3; len <= N; len++) {
			for (int i = 0; i + len - 1 < N; i++) {
				int j = i + len - 1;
				if (memo[i+1][j-1] && target[i] == target[j]) {
					memo[i][j] = true;
					ret++;
				}
			}
		}

		for (int i = 0; i < N; i++)
			delete [] memo[i];
		delete [] memo;

		return ret;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	PalindromicSubstringsDiv2 *obj;
	int answer;
	obj = new PalindromicSubstringsDiv2();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
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
	
	vector <string> p0;
	vector <string> p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"a","a",""};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"a"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 6;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"zaz"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1.clear() /*{}*/;
	p2 = 4;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"top"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"coder"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 8;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0.clear() /*{}*/;
	string t1[] = {"daata"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 7;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
// Marco recently learned about palindromic strings.
// A palindromic string is a string that reads the same forwards and backwards.
// For example, "radar" and "racecar" are palindromic strings.
// 
// Now Marco is excited about palindromic strings.
// In particular, he likes strings that have a lot of palindromic substrings.
// For example, he really likes the string "aaa" because it has 6 palindromic substrings: "a" occurs three times, "aa" occurs twice, and "aaa" occurs once.
// 
// Right now, Marco has a string S composed of lowercase letters.
// You are to reconstruct S from the given vector <string>s S1 and S2 as follows:
// 
// Concatenate in order all elements of S1 to make a string A.
// Concatenate in order all elements of S2 to make a string B.
// Finally, concatenate A and B to get S.
// 
// 
// 
// Return the number of palindromic substrings in S.
// 
// DEFINITION
// Class:PalindromicSubstringsDiv2
// Method:count
// Parameters:vector <string>, vector <string>
// Returns:int
// Method signature:int count(vector <string> S1, vector <string> S2)
// 
// 
// CONSTRAINTS
// -S1 and S2 will each contain no more than 50 elements.
// -Each element of S1 and S2 will contain no more than 50 characters.
// -S will contain at least 1 character.
// -S will contain only lowercase letters ('a' - 'z').
// 
// 
// EXAMPLES
// 
// 0)
// {"a","a",""}
// {"a"}
// 
// Returns: 6
// 
// This is the example given in the statement, "aaa".
// 
// 1)
// {"zaz"}
// {}
// 
// Returns: 4
// 
// 
// 
// 2)
// {"top"}
// {"coder"}
// 
// Returns: 8
// 
// 
// 
// 3)
// {}
// {"daata"}
// 
// Returns: 7
// 
// There are five palindromic substrings of length 1, one of length 2 ("aa" starting at index 1), and one of length 3 ("ata" starting at index 2).
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
