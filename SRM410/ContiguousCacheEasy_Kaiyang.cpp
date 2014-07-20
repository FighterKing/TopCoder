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


class ContiguousCacheEasy {
public:
  int bytesRead(int n, int k, vector <int> addresses) {
    int sum = 0;
    int offset = 0;
    for (auto i : addresses) {
      if (i >= offset && i <= offset + k - 1)
        continue;
      if (i > offset + k - 1) {
        int diff = i - (offset + k - 1);
        if (diff > k - 1) {
          sum += k;
          offset = i - (k - 1);
        } else {
          sum += diff;
          offset += diff;
        }
      } else if (i < offset) {
        int diff = offset - i;
        if (diff > (k - 1)) {
          sum += k;
          offset = i;
        } else {
          sum += diff;
          offset -= diff;
        }
      }
    }
    return sum;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, bool hasAnswer, int p3) {
  cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
  for (int i = 0; int(p2.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << p2[i];
  }
  cout << "}";
  cout << "]" << endl;
  ContiguousCacheEasy *obj;
  int answer;
  obj = new ContiguousCacheEasy();
  clock_t startTime = clock();
  answer = obj->bytesRead(p0, p1, p2);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << p3 << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << answer << endl;
  if (hasAnswer) {
    res = answer == p3;
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
  vector <int> p2;
  int p3;

  {
    // ----- test 0 -----
    p0 = 100;
    p1 = 5;
    int t2[] = {6,0,3,20,22,16};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    p3 = 13;
    all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    p0 = 100;
    p1 = 1;
    int t2[] = {0,4,6,6,4,10};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    p3 = 4;
    all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    p0 = 1000;
    p1 = 999;
    int t2[] = {0,4,123,987,999,500,0};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    p3 = 2;
    all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
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
