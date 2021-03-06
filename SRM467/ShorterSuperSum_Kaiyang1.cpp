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


class ShorterSuperSum {
public:
  int calculate(int k, int n) {
    vector<vector<int>> v(k + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; ++i)
      v[0][i] = i;

    for (int i = 1; i <= k; ++i) 
      for (int z = 1; z <= n; ++z) 
        for (int j = 1; j <= z; ++j) 
          v[i][z] += v[i - 1][j];
    
    return v[k][n];
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
  cout << "Test " << testNum << ": [" << p0 << "," << p1;
  cout << "]" << endl;
  ShorterSuperSum *obj;
  int answer;
  obj = new ShorterSuperSum();
  clock_t startTime = clock();
  answer = obj->calculate(p0, p1);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << p2 << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << answer << endl;
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
  int p1;
  int p2;

  {
    // ----- test 0 -----
    p0 = 1;
    p1 = 3;
    p2 = 6;
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    p0 = 2;
    p1 = 3;
    p2 = 10;
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    p0 = 4;
    p1 = 10;
    p2 = 2002;
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    p0 = 10;
    p1 = 10;
    p2 = 167960;
    all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
