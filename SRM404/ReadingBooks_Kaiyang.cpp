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


class ReadingBooks {
public:
  int countBooks(vector <string> readParts) {
    const int COM = 1 | 2 | 4;
    int count = 0;
    int c = 0;
    string last = "";
    for (auto str : readParts) {
      if (str == last)
        c = 0;

      if ("introduction" == str) 
        c |= 1;
      else if ("story" == str) 
        c |=2;
      else if ("edification" == str)
        c |= 4;
      if (c == COM) {
        c = 0;
        ++count;
      } 
      last = str;
    }
    return count;
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
  ReadingBooks *obj;
  int answer;
  obj = new ReadingBooks();
  clock_t startTime = clock();
  answer = obj->countBooks(p0);
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
    string t0[] = {"introduction","story","introduction","edification"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 1;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    string t0[] = {"introduction","story","edification","introduction","story","edification"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 2;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    string t0[] = {"introduction","story","introduction","edification","story","introduction"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 1;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    string t0[] = {"introduction","story","introduction","edification","story","story","edification","edification","edification","introduction","introduction","edification","story","introduction","story","edification","edification","story","introduction","edification","story","story","edification","introduction","story"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 5;
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
// There are some books, each consisting of exactly three parts:
// introduction, story and edification. 
// There is a reader who goes through the books and reads various
// parts. 
// Each time he finishes reading a part, he adds the name of the part
// to the end of a list. 
// He may read zero or more parts from each book, and he can read them
// in any order, but he cannot 
// read each part more than once. 
// Whenever he starts reading a new book, he can no longer go back and
// read any parts of books he has 
// looked at previously.
// 
// 
// You are given a vector <string> readParts containing the list
// created by the reader. 
// Each element of readParts is "introduction", "story" or
// "edification" (quotes for clarity). 
// Return the maximum possible number of books for which the reader
// has read all three parts.
// 
// 
// 
// DEFINITION
// Class:ReadingBooks
// Method:countBooks
// Parameters:vector <string>
// Returns:int
// Method signature:int countBooks(vector <string> readParts)
// 
// 
// CONSTRAINTS
// -readParts will contain between 1 and 50 elements, inclusive.
// -Each element of readParts will be "introduction", "story" or
// "edification" (quotes for clarity).
// 
// 
// EXAMPLES
// 
// 0)
// {"introduction", "story", "introduction", "edification"}
// 
// Returns: 1
// 
// It is possible that the reader has read the introduction from the
// first book and all 3 parts from the second one. Of course, it is
// also possible that he has read one part from four different books,
// but we are interested in the maximal number of books for which all
// 3 parts have been read.
// 
// 1)
// {"introduction", "story", "edification", "introduction", "story",
// "edification"}
// 
// Returns: 2
// 
// Two books have been read in their entirety.
// 
// 2)
// {"introduction", "story", "introduction", "edification", "story",
// "introduction"}
// 
// Returns: 1
// 
// 3)
// {"introduction", "story", "introduction", "edification", "story",
//  "story", "edification", "edification", "edification",
// "introduction",
//  "introduction", "edification", "story", "introduction", "story",
//  "edification", "edification", "story", "introduction",
// "edification",
//  "story", "story", "edification", "introduction", "story"}
// 
// Returns: 5
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!