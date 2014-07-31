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


class Party {
public:
  double averageNames(int n, vector <int> personA, vector <int> personB) {
    vector<set<int>> v(n);
    int size = personA.size();
    for (int i = 0; i < size; ++i) {
      int a = personA[i];
      int b = personB[i];
      v[a].insert(b);
      v[a].insert(v[b].begin(), v[b].end());
      v[b].insert(a);
      v[b].insert(v[a].begin(), v[a].end());
    }
    double sum = 0;

    for (int i = 0; i < n; ++i){
      v[i].erase(i);
      sum += v[i].size();
    }
    return sum / n;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, bool hasAnswer, double p3) {
  cout << "Test " << testNum << ": [" << p0 << "," << "{";
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
  Party *obj;
  double answer;
  obj = new Party();
  clock_t startTime = clock();
  answer = obj->averageNames(p0, p1, p2);
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
    res = fabs(p3 - answer) <= 1e-9 * max(1.0, fabs(p3));
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
  vector <int> p2;
  double p3;

  {
    // ----- test 0 -----
    p0 = 4;
    int t1[] = {0,1,2};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {1,2,3};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    p3 = 2.25;
    all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    p0 = 5;
    int t1[] = {0,0,0,0,0,0,0};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {1,2,3,4,3,2,1};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    p3 = 4.0;
    all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    p0 = 100;
    int t1[] = {52,19,52,19};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {19,52,19,52};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    p3 = 0.02;
    all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    p0 = 25;
    int t1[] = {14,14,16,4,14,16,2,16,8,15,17,17,3,3,19,17,20,4,24,8};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {16,2,23,16,11,8,5,19,15,20,19,18,14,12,22,9,0,7,23,10};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    p3 = 4.44;
    all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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
