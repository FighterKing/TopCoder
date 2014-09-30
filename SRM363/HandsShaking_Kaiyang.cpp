// Just Find the pattern
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


class HandsShaking {
public:
  long long countPerfect(int n) {
    vector<long long> v(n + 1, 0);
    v[0] = 1;
    for (int i = 2; i <= n ; i += 2) {
      for (int j = 0; j <= (i - 2); j += 2) {
        v[i] += v[j] * v[i - 2 - j];
      }
    }
    return v[n];
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, long long p1) {
  cout << "Test " << testNum << ": [" << p0;
  cout << "]" << endl;
  HandsShaking *obj;
  long long answer;
  obj = new HandsShaking();
  clock_t startTime = clock();
  answer = obj->countPerfect(p0);
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
  long long p1;
	
  {
    // ----- test 0 -----
    p0 = 2;
    p1 = 1ll;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 1 -----
    p0 = 4;
    p1 = 2ll;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 2 -----
    p0 = 8;
    p1 = 14ll;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
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
// Consider a meeting of n businessmen sitting around a circular table. To start the meeting, they must shake hands. Each businessman shakes the hand of exactly one other businessman. All handshakes happen simultaneously. We say that the shake is perfect if no arms cross each other. Given an int n, return the number of perfect shakes that exist for n businessmen. See examples for further clarification.
// 
// DEFINITION
// Class:HandsShaking
// Method:countPerfect
// Parameters:int
// Returns:long long
// Method signature:long long countPerfect(int n)
// 
// 
// NOTES
// -Businessmen are distinguishable. Rotating a perfect shake can yield a different perfect shake (see example 1).
// 
// 
// CONSTRAINTS
// -n will be between 2 and 50, inclusive.
// -n will be even.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 
// Returns: 1
// 
// Two businessmen have only one possibility - just to shake each other's hand.
// 
// 1)
// 4
// 
// Returns: 2
// 
// Two out of three possible shakes are perfect.
// ? ? 
// 
// 2)
// 8
// 
// Returns: 14
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
