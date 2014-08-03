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


class InequalityChecker {
public:
  vector <int> getDifferences(int n) {
    int s = 0;
    for (int i = 1; i < n; ++i)
      s += pow(i, 3);
    int S = s + pow(n, 3);
    int up = 2 * (s + S) - pow(n, 4);
    
    if (up % 4 == 0)
      return {up / 4, 1};
    else if (up % 2 == 0)
      return {up / 2, 2};
    else
      return {up, 4};

  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, vector <int> p1) {
  cout << "Test " << testNum << ": [" << p0;
  cout << "]" << endl;
  InequalityChecker *obj;
  vector <int> answer;
  obj = new InequalityChecker();
  clock_t startTime = clock();
  answer = obj->getDifferences(p0);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
      if (i > 0) {
        cout << ",";
      }
      cout << p1[i];
    }
    cout << "}" << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << "{";
  for (int i = 0; int(answer.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << answer[i];
  }
  cout << "}" << endl;
  if (hasAnswer) {
    if (answer.size() != p1.size()) {
      res = false;
    } else {
      for (int i = 0; int(answer.size()) > i; ++i) {
        if (answer[i] != p1[i]) {
          res = false;
        }
      }
    }
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

  {
    // ----- test 0 -----
    p0 = 2;
    int t1[] = {1,1};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    p0 = 3;
    int t1[] = {9,4};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    p0 = 100;
    int t1[] = {2500,1};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
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
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
 