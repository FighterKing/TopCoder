// Brute force
// 1. Find the rule
// 2. 1th appears array.size() times, 2th appears array.size() +
// array.size() - 2 times,..., array.size() / 2 th appears array.size() +
// array.size() - 2 + ... + array.size() - (array.size() / 2 - 1) * 2
// times, ..., the last appears array.size() times.
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


class SumOfPower {
public:
  int findSum(vector <int> array) {
    int size = array.size();
    int sum = 0;
    int mul = 0;
    int i = 0;
    for (; i < size / 2; ++i) {
      mul +=  (size - i * 2);
      sum += (array[i] + array[size - 1 - i]) * mul ;
    }
    if (size % 2 == 1) {
      mul +=  (size - i * 2);
      sum += mul * array[size / 2];
    }
    return sum;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
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
  SumOfPower *obj;
  int answer;
  obj = new SumOfPower();
  clock_t startTime = clock();
  answer = obj->findSum(p0);
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
    int t0[] = {1,2};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 6;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    int t0[] = {1,1,1};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 10;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    int t0[] = {3,14,15,92,65};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 1323;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    int t0[] = {1,2,3,4,5,6,7,8,9,10};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 1210;
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
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!