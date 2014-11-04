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


class LinearPolyominoCovering {
public:
  string findCovering(string region) {
    string str = ".";
    size_t index = 0, last = 0, t;
    string rstr = "";
    
    while ((index = region.find_first_of(str, last)) != string::npos) {
      t = index - last;
      if (!(t % 4 == 2 || t % 4 == 0))
        return "impossible";
      
      rstr += string(t / 4 * 4, 'A');
      rstr += string(t % 4, 'B');
      if ((t = region.find_first_not_of(".", index)) != string::npos)
        t = t - index;
      else 
        t = region.size() - index;
      rstr += string(t, '.');
      last = t + index;
    }
    t = region.size() - last;
    if (!(t % 4 == 2 || t % 4 == 0))
      return "impossible";

    rstr += string(t / 4 * 4, 'A');
    rstr += string(t % 4, 'B');
    return rstr;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
  cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
  cout << "]" << endl;
  LinearPolyominoCovering *obj;
  string answer;
  obj = new LinearPolyominoCovering();
  clock_t startTime = clock();
  answer = obj->findCovering(p0);
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
	
  string p0;
  string p1;
	
  {
    // ----- test 0 -----
    p0 = ".";
    p1 = ".";
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 1 -----
    p0 = "XX.XX";
    p1 = "BB.BB";
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 2 -----
    p0 = "XXXX....XXX.....XX";
    p1 = "impossible";
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 3 -----
    p0 = "X";
    p1 = "impossible";
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 4 -----
    p0 = "XX.XXXXXXXXXX..XXXXXXXX...XXXXXX";
    p1 = "BB.AAAAAAAABB..AAAAAAAA...AAAABB";
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
// You have an infinite number of the following two polyominoes: AAAA and BB.
// 
// You are given a string region, filled with characters '.' and 'X'. You need to cover (without overlapping) all the 'X' characters with the given polyominoes.
// 
// Return a string that contains the same region with cells marked '.' left untouched, and cells marked 'X' changed to 'A' or 'B', according to the polyomino that covers the cell.
// 
// If there is no solution, return the string "impossible" (quotes for clarity only).
// 
// If there are multiple solutions, return the lexicographically smallest one.
// 
// 
// DEFINITION
// Class:LinearPolyominoCovering
// Method:findCovering
// Parameters:string
// Returns:string
// Method signature:string findCovering(string region)
// 
// 
// NOTES
// -A string S is greater than a string T lexicographically if T is a proper prefix of S, or if S has a greater character at the first position where the strings differ.
// 
// 
// CONSTRAINTS
// -region will contain between 1 and 50 characters, inclusive.
// -Each character of region will be either '.' or uppercase 'X'.
// 
// 
// EXAMPLES
// 
// 0)
// "XXXXXX"
// 
// Returns: "AAAABB"
// 
// There is only room for one AAAA polyomino, so there are three possible coverings: "AAAABB", "BBAAAA", and "BBBBBB". The first one is the lexicographically smallest.
// 
// 1)
// "XX.XX"
// 
// Returns: "BB.BB"
// 
// The empty cell in the middle should be left uncovered, so we can't use the AAAA polyomino here.
// 
// 2)
// "XXXX....XXX.....XX"
// 
// Returns: "impossible"
// 
// The middle segment of Xs is too narrow for an AAAA polyomino, but is too wide for a BB polyomino.
// 
// 3)
// "X"
// 
// Returns: "impossible"
// 
// 
// 
// 4)
// "XX.XXXXXXXXXX..XXXXXXXX...XXXXXX"
// 
// Returns: "BB.AAAAAAAABB..AAAAAAAA...AAAABB"
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
