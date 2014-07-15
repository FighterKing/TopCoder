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


class ComparerInator {
public:
  int makeProgram(vector <int> A, vector <int> B, vector <int> wanted) {
    int b[4] = {0};
    auto size = A.size();
    for (int i = 0; i < size; ++i) {
      if (wanted[i] == A[i])
        ++b[0];
      if (wanted[i] == B[i])
        ++b[1];
      
      if (wanted[i] == max(A[i], B[i]))
        ++b[3];
      if (wanted[i] == min(A[i], B[i]))
        ++b[2];
    }
    
    if (size == b[0] || size == b[1])
      return 1;
    else if (size == b[2] || size == b[3])
      return 7;
    else 
      return -1;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, bool hasAnswer, int p3) {
  cout << "Test " << testNum << ": [" << "{";
  for (int i = 0; int(p0.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << p0[i];
  }
  cout << "}" << "," << "{";
  for (int i = 0; int(p1.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << p1[i];
  }
  cout << "}" << "," << "{";
  for (int i = 0; int(p2.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << p2[i];
  }
  cout << "}";
  cout << "]" << endl;
  ComparerInator *obj;
  int answer;
  obj = new ComparerInator();
  clock_t startTime = clock();
  answer = obj->makeProgram(p0, p1, p2);
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

  vector <int> p0;
  vector <int> p1;
  vector <int> p2;
  int p3;

  {
    // ----- test 0 -----
    int t0[] = {1, 1, 1, 1, 1};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {1, 1, 1, 1, 2};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {1, 1, 1, 1, 2};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    p3 = 1;
    all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    int t0[] = {1,3};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {2,1};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {2,3};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    p3 = 7;
    all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    int t0[] = {1,3,5};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {2,1,7};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {2,3,5};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    p3 = -1;
    all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    int t0[] = {1,3,5};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {2,1,7};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {1,3,5};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    p3 = 1;
    all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }

  {
    // ----- test 4 -----
    int t0[] = {1,2,3,4,5,6,7,8,9,10,11};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {5,4,7,8,3,1,1,2,3,4,6};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {1,2,3,4,3,1,1,2,3,4,6};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    p3 = 7;
    all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }

  {
    // ----- test 5 -----
    int t0[] = {1,5,6,7,8};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {1,5,6,7,8};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {1,5,6,7,8};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    p3 = 1;
    all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
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
