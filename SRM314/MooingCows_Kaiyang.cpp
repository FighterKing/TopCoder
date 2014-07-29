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


class MooingCows {
public:
  int dissatisfaction(vector <string> farmland) {
    vector<pair<int, int>> v;
    int y = farmland.size();
    int x = farmland[0].size();
    for (int i = 0; i < y; ++i)
      for (int j = 0; j < x; ++j) 
        if (farmland[i][j] == 'C')
          v.push_back({i, j});
    
    int size = v.size();
    unsigned min = -1;
    for (int i = 0; i < size; ++i) {
      int va = 0;
      for (int j = 0; j < size; ++j) {
        va += (v[i].first - v[j].first) * (v[i].first - v[j].first) + 
            (v[i].second - v[j].second) * (v[i].second - v[j].second);
      }
      if (va < min)
        min = va;
    }

    return min;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
  cout << "Test " << testNum << ": [" << "{";
  for (int i = 0; int(p0.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << "\"" << p0[i] << "\"";
  }
  cout << "}";
  cout << "]" << endl;
  MooingCows *obj;
  int answer;
  obj = new MooingCows();
  clock_t startTime = clock();
  answer = obj->dissatisfaction(p0);
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

  vector <string> p0;
  int p1;

  {
    // ----- test 0 -----
    string t0[] = {"C..",".C.",".C."};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 3;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    string t0[] = {"CCCC","CCCC","CCCC"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 26;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    string t0[] = {"C"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 0;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    string t0[] = {"CCC....","C......","....C.C",".C.CC..","C......"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 81;
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