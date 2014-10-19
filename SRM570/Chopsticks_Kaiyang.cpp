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


class Chopsticks {
public:
  int getmax(vector <int> length) {
    sort(length.begin(), length.end());
    int sum = 0;
    int i = 0; 
    int last = length[0];
    int count = 1;
    for (int i = 1; i < length.size(); ++i) {
      if (length[i] == last) {
        ++count;
      } else {
        sum += count / 2;
        last = length[i];
        count = 1;
      }
    }
    sum += count / 2;
    return sum;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
  cout << "Test " << testNum << ": [" << "{";
  for (int i = 0; int(p0.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << p0[i];
  }
  cout << "}";
  cout << "]" << endl;
  Chopsticks *obj;
  int answer;
  obj = new Chopsticks();
  clock_t startTime = clock();
  answer = obj->getmax(p0);
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
	
  vector <int> p0;
  int p1;
	
  {
    // ----- test 0 -----
    int t0[] = {5,5};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 1;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 1 -----
    int t0[] = {1,2,3,2,1,2,3,2,1};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 4;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 2 -----
    int t0[] = {1};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 0;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 3 -----
    int t0[] = {1,2,3,4,5,6,7,8,9};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 0;
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 4 -----
    int t0[] = {35,35,35,50,16,30,10,10,35,50,16,16,16,30,50,30,16,35,50,30,10,50,50,16,16,10,35,50,50,50,16,35,35,30,35,10,50,10,50,50,16,30,35,10,10,30,10,10,16,35};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 24;
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
// Cat Carol wants to invite some of her friends to a lunch at her house.
// Carol has some chopsticks of possibly different lengths.
// Each of the invited guests must receive two chopsticks.
// Additionally, the two chopsticks given to each guest must have exactly the same length.
// 
// You are given a vector <int> length.
// Each element of length is the length of one of Carol's chopsticks.
// Compute and return the maximum number of friends Carol may invite.
// 
// DEFINITION
// Class:Chopsticks
// Method:getmax
// Parameters:vector <int>
// Returns:int
// Method signature:int getmax(vector <int> length)
// 
// 
// CONSTRAINTS
// -length will contain between 1 and 50 elements, inclusive.
// -Each element of length will be between 1 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {5,5}
// 
// Returns: 1
// 
// Two chopsticks have the same length. Carol can invite one friend.
// 
// 1)
// {1,2,3,2,1,2,3,2,1}
// 
// Returns: 4
// 
// Carol can make one pair of chopsticks of length 1, two pairs of chopsticks of length 2, and one pair of chopsticks of length 3. She can invite four guests in total.
// 
// 2)
// {1}
// 
// Returns: 0
// 
// Carol has only one chopstick. Carol can't invite anybody.
// 
// 3)
// {1,2,3,4,5,6,7,8,9}
// 
// Returns: 0
// 
// No two chopsticks have the same length. Carol can't invite anybody.
// 
// 4)
// {35,35,35,50,16,30,10,10,35,50,16,16,16,30,50,30,16,35,50,30,10,50,50,16,16,
// 10,35,50,50,50,16,35,35,30,35,10,50,10,50,50,16,30,35,10,10,30,10,10,16,35}
// 
// Returns: 24
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
