// Same solution as tc.
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


class NextOrPrev {
public:
  int getMinimum(int nextCost, int prevCost, string start, string goal) {
    int i = 0; 
    int cost = 0;
    vector<char> v(start.size(), 0);
    for (; i < start.size(); ++i) {
      if (start[i] <= goal[i])
        cost += nextCost * (goal[i] - start[i]);
      else 
        cost += prevCost * (start[i] - goal[i]);
      v[i] = goal[i];
    }
    bool possible = true;
    int j = 0;
    for (i = 0; i < start.size() && possible; ++i) {
      for (j = i + 1; j < start.size(); ++j) {
        if(start[i] < start[j] && start[i] <= v[i] && start[j] >= v[j] && v[i] > v[j]) {
          possible = false;
          break;
        } else if (start[i] > start[j] && start[j] <= v[j] && start[i] >= v[i] && v[j] > v[i]) {
          possible = false;
          break;
        } else if (min(start[i], v[i]) > min(start[j], v[j]) && max(start[i], v[i]) < max(start[j], v[j])) {
          possible = false;
          break;
        } else if (min(start[j], v[j]) > min(start[i], v[i]) && max(start[j], v[j]) < max(start[i], v[i])) {
          possible = false;
          break;
        }
      }
    }
    if (possible)
      return cost;
    return -1;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, string p2, string p3, bool hasAnswer, int p4) {
  cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "\"" << p2 << "\"" << "," << "\"" << p3 << "\"";
  cout << "]" << endl;
  NextOrPrev *obj;
  int answer;
  obj = new NextOrPrev();
  clock_t startTime = clock();
  answer = obj->getMinimum(p0, p1, p2, p3);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << p4 << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << answer << endl;
  if (hasAnswer) {
    res = answer == p4;
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
  string p2;
  string p3;
  int p4;
	
  {
    // ----- test 0 -----
    p0 = 5;
    p1 = 8;
    p2 = "ae";
    p3 = "bc";
    p4 = 21;
    all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }
	
  {
    // ----- test 1 -----
    p0 = 5;
    p1 = 8;
    p2 = "ae";
    p3 = "cb";
    p4 = -1;
    all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }
	
  {
    // ----- test 2 -----
    p0 = 1;
    p1 = 1;
    p2 = "srm";
    p3 = "srm";
    p4 = 0;
    all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }
	
  {
    // ----- test 3 -----
    p0 = 10;
    p1 = 1;
    p2 = "acb";
    p3 = "bdc";
    p4 = 30;
    all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }
	
  {
    // ----- test 4 -----
    p0 = 10;
    p1 = 1;
    p2 = "zyxw";
    p3 = "vuts";
    p4 = 16;
    all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }
	
  {
    // ----- test 5 -----
    p0 = 563;
    p1 = 440;
    p2 = "ptrbgcnlaizo";
    p3 = "rtscedkiahul";
    p4 = 10295;
    all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }
	
  {
    // ----- test 6 -----
    p0 = 126;
    p1 = 311;
    p2 = "yovlkwpjgsna";
    p3 = "zpwnkytjisob";
    p4 = -1;
    all_right = KawigiEdit_RunTest(6, p0, p1, p2, p3, true, p4) && all_right;
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
// Consider a string consisting of lowercase characters and following two operations that can change it: 
// 
// 	Next: Choose a lowercase character other than 'z' and replace its every occurrence with the next character 
// 	('a' -> 'b', 'b' -> 'c', ..., 'x' -> 'y', 'y' -> 'z'). 
// 	Prev: Choose a lowercase character other than 'a' and replace its every occurrence with the previous character 
// 	('b' -> 'a', 'c' -> 'b', ..., 'y' -> 'x', 'z' -> 'y'). 
// 
// You can use each operation as many times as you want, and in any order you like. 
// You are given ints nextCost and prevCost. 
// These represent the cost of using each Next and Prev operation, respectively. 
// You are also given two strings start and goal. 
// These strings are special: no two characters in start are the same, and no two characters in goal are the same. 
// Return the minimum cost required in order to transform start into goal using the above operations. 
// If transforming start into goal is impossible, return -1 instead. 
// 
// 
// DEFINITION
// Class:NextOrPrev
// Method:getMinimum
// Parameters:int, int, string, string
// Returns:int
// Method signature:int getMinimum(int nextCost, int prevCost, string start, string goal)
// 
// 
// CONSTRAINTS
// -nextCost and prevCost will each be between 1 and 1000, inclusive. 
// -start and goal will each contain between 1 and 26 characters, inclusive. 
// -start and goal will contain the same number of characters. 
// -Each character in start and goal will be a lowercase character. 
// -The characters in start will be distinct. 
// -The characters in goal will be distinct. 
// 
// 
// EXAMPLES
// 
// 0)
// 5
// 8
// "ae"
// "bc"
// 
// Returns: 21
// 
// There are several optimal sequences of operations. 
// Here is one of them: "ae" -(Next)-> "be" -(Prev)-> "bd" -(Prev)-> "bc". The total cost is 5 + 8 + 8 = 21. 
// 
// 
// 1)
// 5
// 8
// "ae"
// "cb"
// 
// Returns: -1
// 
// It is impossible to transform "ae" into "cb". 
// 
// 
// 2)
// 1
// 1
// "srm"
// "srm"
// 
// Returns: 0
// 
// start and goal may be the same. 
// The cost of an empty sequence of operations is 0. 
// 
// 
// 3)
// 10
// 1
// "acb"
// "bdc"
// 
// Returns: 30
// 
// 
// 
// 4)
// 10
// 1
// "zyxw"
// "vuts"
// 
// Returns: 16
// 
// 
// 
// 5)
// 563
// 440
// "ptrbgcnlaizo"
// "rtscedkiahul"
// 
// Returns: 10295
// 
// 
// 
// 6)
// 126
// 311
// "yovlkwpjgsna"
// "zpwnkytjisob"
// 
// Returns: -1
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!

