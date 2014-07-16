// Math + Brute Force
// the number of subset is (pow(2.0, size) - 1)
// the average is (binomial Coefficient) * sum(all elements) / i 
// where i is from 1 to numList.size();
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


class AverageAverage {
public:
  double average(vector <int> numList) {
    int size = numList.size();
    double sum = accumulate(numList.begin(), numList.end(), 0);
    double rev = 0;

    // Calculate binomial Coefficient
    vector<int> v;
    v.push_back(1);
    for (int i = 1; i < size; ++i) {
      vector<int> t;
      t.push_back(1);
      for (int j = 1; j < i; ++j)
        t.push_back(v[j - 1] + v[j]);
      t.push_back(1);
      v = std::move(t);
    }
    
    for (int i = 1; i <= v.size(); ++i)
      rev += sum * v[i - 1] / i;

    return rev / (pow(2.0, size) - 1);
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, double p1) {
  cout << "Test " << testNum << ": [" << "{";
  for (int i = 0; int(p0.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << p0[i];
  }
  cout << "}";
  cout << "]" << endl;
  AverageAverage *obj;
  double answer;
  obj = new AverageAverage();
  clock_t startTime = clock();
  answer = obj->average(p0);
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
    res = fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
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
  double p1;

  {
    // ----- test 0 -----
    int t0[] = {1,2,3};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 2.0;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    int t0[] = {42};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 42.0;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    int t0[] = {3,1,4,15,9};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 6.4;
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
