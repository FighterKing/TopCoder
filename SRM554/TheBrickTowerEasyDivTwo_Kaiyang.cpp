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


class TheBrickTowerEasyDivTwo {
  void get(set<int> &s, int rC, int rH, int bC, int bH) {
    for (int i = 1, j = 0; i <= rC && j <= bC; ++i){
      s.insert(i * rH + j * bH);
      ++j;
      if (j <= bC)
        s.insert(i * rH + j * bH);
    }
  }
public:
  int find(int redCount, int redHeight, int blueCount, int blueHeight) {
    set<int> s;
    get(s, redCount, redHeight, blueCount, blueHeight);
    get(s, blueCount, blueHeight, redCount, redHeight);
    return s.size();
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, int p4) {
  cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
  cout << "]" << endl;
  TheBrickTowerEasyDivTwo *obj;
  int answer;
  obj = new TheBrickTowerEasyDivTwo();
  clock_t startTime = clock();
  answer = obj->find(p0, p1, p2, p3);
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
  int p2;
  int p3;
  int p4;

  {
    // ----- test 0 -----
    p0 = 1;
    p1 = 2;
    p2 = 3;
    p3 = 4;
    p4 = 4;
    all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    p0 = 4;
    p1 = 4;
    p2 = 4;
    p3 = 7;
    p4 = 12;
    all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    p0 = 7;
    p1 = 7;
    p2 = 4;
    p3 = 4;
    p4 = 13;
    all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    p0 = 47;
    p1 = 47;
    p2 = 47;
    p3 = 47;
    p4 = 94;
    all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
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