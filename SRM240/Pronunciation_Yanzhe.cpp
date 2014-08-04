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


class Pronunciation {
public:
	string canPronounce(vector <string> words) {
		vector<bool> flags(26, false);
		flags['a'-'a'] = true;
		flags['e'-'a'] = true;
		flags['i'-'a'] = true;
		flags['o'-'a'] = true;
		flags['u'-'a'] = true;

		for (auto s : words) {
			for (int i = 0; i < (int)s.size() - 1; i++)
				if (flags[tolower(s[i])-'a'] &&
						flags[tolower(s[i+1])-'a'] &&
						tolower(s[i]) != tolower(s[i+1]))
					return s;
			for (int i = 0; i < (int)s.size() - 2; i++)
				if (!flags[tolower(s[i])-'a'] &&
						!flags[tolower(s[i+1])-'a'] &&
						!flags[tolower(s[i+2])-'a'])
					return s;
		}
		return "";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	Pronunciation *obj;
	string answer;
	obj = new Pronunciation();
	clock_t startTime = clock();
	answer = obj->canPronounce(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	string p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"All","of","these","are","not","difficult"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"The","word","REALLY","is","really","hard"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "REALLY";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"TRiCKy"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "TRiCKy";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"irresistable","prerogative","uttermost","importance"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"Aa"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "";
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
// Peter has problems with pronouncing difficult words. In particular he can't pronounce words that contain three or more consecutive consonants (such as "street" or "first"). Furthermore he can't pronounce words that contain two or more consecutive vowels that are different (such as "goal" or "beauty"). He can pronounce words with two consecutive equal vowels though  (such as "need").
// 
// 
// 
// Is this problem we consider the 'y' to be always a consonant, even in words like "any". So the vowels are 'a', 'e', 'i', 'o' and 'u'. You are given a vector <string> words. If Peter can pronounce all the words, return an empty string; otherwise return the first word he can't pronounce.
// 
// DEFINITION
// Class:Pronunciation
// Method:canPronounce
// Parameters:vector <string>
// Returns:string
// Method signature:string canPronounce(vector <string> words)
// 
// 
// CONSTRAINTS
// -words contains between 1 and 50 elements, inclusive.
// -Each element of words has length between 1 and 50, inclusive.
// -Each element of words consists of upper- and lowercase letters.
// 
// 
// EXAMPLES
// 
// 0)
// {"All","of","these","are","not","difficult"}
// 
// Returns: ""
// 
// 1)
// {"The","word","REALLY","is","really","hard"}
// 
// Returns: "REALLY"
// 
// 2)
// {"TRiCKy"}
// 
// Returns: "TRiCKy"
// 
// Since the 'y' is a consonant, this word contain three consecutive consonants.
// 
// 3)
// {"irresistable","prerogative","uttermost","importance"}
// 
// Returns: ""
// 
// Peter can pronounce these words.
// 
// 4)
// {"Aa"}
// 
// Returns: ""
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
