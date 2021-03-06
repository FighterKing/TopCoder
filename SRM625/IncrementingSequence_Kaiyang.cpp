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


class IncrementingSequence {
public:
  string canItBeDone(int k, vector <int> A) {
    int size = A.size();
    bool *exsits = new bool[size + 1];
    fill(exsits, exsits + size + 1, false);
    auto it = A.begin();
    for (; it != A.end();) {
      if (!exsits[*it]) {
        exsits[*it] = true;
        it = A.erase(it);
      } else {
        ++it;
      }
    }
    sort(A.begin(), A.end());
    
    for (int i = 1; i <= size; ++i) {
      if (!exsits[i]) {
        bool found = false;
        for (it = A.begin(); it != A.end(); ++it)
          if ((i - *it >=0  && (i - *it) % k == 0)) {
            it = A.erase(it);
            found = true;
            break;
          }
        if (!found) 
          return "IMPOSSIBLE";
      }
    }
    return "POSSIBLE";
  }
};



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, bool hasAnswer, string p2) {
  cout << "Test " << testNum << ": [" << p0 << "," << "{";
  for (int i = 0; int(p1.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << p1[i];
  }
  cout << "}";
  cout << "]" << endl;
  IncrementingSequence *obj;
  string answer;
  obj = new IncrementingSequence();
  clock_t startTime = clock();
  answer = obj->canItBeDone(p0, p1);
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
	
  int p0;
  vector <int> p1;
  string p2;
	
  {
    // ----- test 0 -----
    p0 = 3;
    int t1[] = {1,2,4,3};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = "POSSIBLE";
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 1 -----
    p0 = 5;
    int t1[] = {2,2};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = "IMPOSSIBLE";
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 2 -----
    p0 = 1;
    int t1[] = {1,1,1,1,1,1,1,1};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = "POSSIBLE";
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 3 -----
    p0 = 2;
    int t1[] = {5,3,3,2,1};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = "IMPOSSIBLE";
    all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 4 -----
    p0 = 9;
    int t1[] = {1,2,3,1,4,5,6,7,9,8};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = "POSSIBLE";
    all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 5 -----
    p0 = 2;
    int t1[] = {1,1,1,1,1,1,2,2,2,2,2,2};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = "POSSIBLE";
    all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 6 -----
    p0 = 1;
    int t1[] = {1};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = "POSSIBLE";
    all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
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
// You have a vector <int> A with N elements.
// 
// Your goal is to change it into a vector <int> that contains each number from 1 to N exactly once. The change will consist of zero or more steps. In each step, you may pick an arbitrary element of A and increment its value by k. You may pick the same element multiple times. Note that you are not allowed to decrement the value of any element.
// 
// You are given the int k and the vector <int> A.
// Return "POSSIBLE" if it is possible to achieve your goal. Return "IMPOSSIBLE" otherwise.
// 
// DEFINITION
// Class:IncrementingSequence
// Method:canItBeDone
// Parameters:int, vector <int>
// Returns:string
// Method signature:string canItBeDone(int k, vector <int> A)
// 
// 
// NOTES
// -Return value is case-sensitive. For example, you can't return "Possible" or "possible" instead of "POSSIBLE".
// 
// 
// CONSTRAINTS
// -k will be between 1 and 10, inclusive.
// -A will contain between 1 and 50 elements, inclusive.
// -Each element of A will be between 1 and 50, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// {1,2,4,3}
// 
// Returns: "POSSIBLE"
// 
// This sequence of length 4 already contains all numbers from 1 to 4 exactly once. Note that their order does not matter.
// 
// 1)
// 5
// {2,2}
// 
// Returns: "IMPOSSIBLE"
// 
// 
// 
// 2)
// 1
// {1,1,1,1,1,1,1,1}
// 
// Returns: "POSSIBLE"
// 
// There are many ways to achieve the goal. For example, it is possible to obtain the sequence {1,2,3,4,5,6,7,8}. To do this, just increment the element at each position one by one until it reaches the required value.
// 
// 3)
// 2
// {5,3,3,2,1}
// 
// Returns: "IMPOSSIBLE"
// 
// We want to have the values {1,2,3,4,5}, in any order. Currently, we are missing the 4. As k=2, the only way to produce a 4 is by incrementing a 2. But if we increment our only 2, we will have no way of producing another 2.
// 
// 4)
// 9
// {1,2,3,1,4,5,6,7,9,8}
// 
// Returns: "POSSIBLE"
// 
// 
// 
// 5)
// 2
// {1,1,1,1,1,1,2,2,2,2,2,2}
// 
// Returns: "POSSIBLE"
// 
// 
// 
// 6)
// 1
// {1}
// 
// Returns: "POSSIBLE"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!

