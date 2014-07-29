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


class MnemonicMemory {
public:
	string getPhrase(string number, vector <string> dictionary) {
		sort(dictionary.begin(), dictionary.end(), [](const string &a, const string &b) -> bool {
				if (a.size() == b.size())
					return a < b;
				else
					return a.size() < b.size();
			});
		map<int, deque<string> > dict;
		for (auto s : dictionary)
			dict[s.size()].push_back(s);
		string ret = "";
		for (auto c : number) {
			ret += dict[c-'0'].front() + " ";
			dict[c-'0'].pop_front();
		}
		return ret.substr(0, ret.size()-1);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, vector <string> p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	MnemonicMemory *obj;
	string answer;
	obj = new MnemonicMemory();
	clock_t startTime = clock();
	answer = obj->getPhrase(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	
	string p0;
	vector <string> p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = "25735";
	string t1[] = {"is","there","anybody","out","there"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "is there anybody out there";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "31415926";
	string t1[] = {"may","i","have","a","large","container","of","coffee"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "may a have i large container of coffee";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "1212";
	string t1[] = {"a","aa","a","aa"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "a aa a aa";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "11111111122";
	string t1[] = {"a","b","d","c","a","e","f","z","zz","za","az","e"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "a a b c d e e f z az za";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "2222";
	string t1[] = {"ab","cd","ef","a","b","ab"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "ab ab cd ef";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
// It is often helpful to have a mnemonic phrase handy for a math test.  For example, the number 25735 can be remembered as "is there anybody out there".  If we count the number of characters in every word, we would get the sequence 2, 5, 7, 3, 5, which represents the original number!
// 
// 
// Unfortunately for you, your professor likes to make the students memorize random numbers and then test them.  To beat the system, your plan is to come up with mnemonic phrases that will represent the numbers you must memorize.
// 
// 
// You are given a string number and a vector <string> dictionary.  Return a single space delimited list of words, where each word is an element of dictionary, and no element of dictionary is used more than once. The phrase must contain exactly n words, where n is the number of digits in the number, and the length of the i-th word must be equal to the i-th digit of the number for all i.  If more than one phrase is possible, return the one that comes first alphabetically (in other words, if you have several words of the same length, you should use them in alphabetical order).
// 
// 
// DEFINITION
// Class:MnemonicMemory
// Method:getPhrase
// Parameters:string, vector <string>
// Returns:string
// Method signature:string getPhrase(string number, vector <string> dictionary)
// 
// 
// CONSTRAINTS
// -dictionary will contain between 1 and 50 elements, inclusive.
// -Each element of dictionary will contain between 1 and 9 characters, inclusive.
// -Each element of dictionary will contain only lowercase letters ('a'-'z').
// -number will contain between 1 and 50 characters, inclusive.
// -number will contain only digits between '1' and '9', inclusive.
// -There will always be a possible solution with the given dictionary.
// 
// 
// EXAMPLES
// 
// 0)
// "25735"
// {"is", "there", "anybody", "out", "there"}
// 
// Returns: "is there anybody out there"
// 
// The example from the problem statement.
// 
// 1)
// "31415926"
// {"may", "i", "have", "a", "large", "container", "of", "coffee"}
// 
// Returns: "may a have i large container of coffee"
// 
// Make sure you use words of the same length in alphabetical order.
// 
// 2)
// "1212"
// {"a", "aa", "a", "aa"}
// 
// Returns: "a aa a aa"
// 
// 
// 
// 3)
// "11111111122"
// {"a", "b", "d", "c", "a", "e", "f", "z", "zz", "za", "az", "e"}
// 
// Returns: "a a b c d e e f z az za"
// 
// 
// 
// 4)
// "2222"
// {"ab", "cd", "ef", "a", "b", "ab"}
// 
// Returns: "ab ab cd ef"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
