// Brute Force
// 1. Sort the pair according to the first value
// 2. There're two patterns when they become friends, check it!
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


class ShoutterDiv2 {
public:
  int count(vector <int> s, vector <int> t) {
    vector<pair<int, int>> v;
    for (int i = 0; i < s.size(); ++i) 
      v.push_back(make_pair(s[i], t[i]));

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){return a.first < b.first;});

    int count = 0;
    auto it = v.begin();
    for (; it != v.end(); ++it) {
      auto it2 = it;
      for (++it2; it2 != v.end(); ++it2) {
        if (it->second >= it2->first && it->second <= it2->second)
          ++count;
        else if (it->second >= it2->second)
          ++count;
          
      }
    }
    return count;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
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
  cout << "}";
  cout << "]" << endl;
  ShoutterDiv2 *obj;
  int answer;
  obj = new ShoutterDiv2();
  clock_t startTime = clock();
  answer = obj->count(p0, p1);
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

  vector <int> p0;
  vector <int> p1;
  int p2;

  {
    // ----- test 0 -----
    int t0[] = {1,2,4};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {3,4,6};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 2;
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    int t0[] = {0};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {100};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 0;
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    int t0[] = {0,0,0};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {1,1,1};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 3;
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    int t0[] = {9,26,8,35,3,58,91,24,10,26,22,18,15,12,15,27,15,60,76,19,12,16,37,35,25,4,22,47,65,3,2,23,26,33,7,11,34,74,67,32,15,45,20,53,60,25,74,13,44,51};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {26,62,80,80,52,83,100,71,20,73,23,32,80,37,34,55,51,86,97,89,17,81,74,94,79,85,77,97,87,8,70,46,58,70,97,35,80,76,82,80,19,56,65,62,80,49,79,28,75,78};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 830;
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
