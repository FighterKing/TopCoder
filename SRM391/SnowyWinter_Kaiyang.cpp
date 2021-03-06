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


class SnowyWinter {
public:
  int snowyHighwayLength(vector <int> startPoints, vector <int> endPoints) {
    set<pair<int, int> > s;
    for (int i = 0; i < startPoints.size(); ++i) {
      s.insert({startPoints[i], endPoints[i]});
    }
    int sum = 0;
    pair<int, int> b = {-1, -1};
    for (auto i : s) {
      if (i.first > b.second) {
        sum += i.second - i.first;
        b = i;
      } else {
        int t = max(b.second, i.second);
        sum += t - b.second;
        b.second = t;
      }
      
    }
    return sum;
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
  SnowyWinter *obj;
  int answer;
  obj = new SnowyWinter();
  clock_t startTime = clock();
  answer = obj->snowyHighwayLength(p0, p1);
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
    int t0[] = {17,85,57};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {33,86,84};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 44;
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    int t0[] = {45,100,125,10,15,35,30,9};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {46,200,175,20,25,45,40,10};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 132;
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    int t0[] = {4387,711,2510,1001,4687,3400,5254,584,284,1423,3755,929,2154,5719,1326,2368,554};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {7890,5075,2600,6867,7860,9789,6422,5002,4180,7086,8615,9832,4169,7188,9975,8690,1423};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 9691;
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    int t0[] = {4906,5601,5087,1020,4362,2657,6257,5509,5107,5315,277,6801,2136,2921,5233,5082,497,8250,3956,5720};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {4930,9130,9366,2322,4687,4848,8856,6302,5496,5438,829,9053,4233,4119,9781,8034,3956,9939,4908,5928};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 9510;
    all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 4 -----
    int t0[] = {51,807,943,4313,8319,3644,481,220,2161,448,465,1657,6290,22,6152,647,3185,4474,2168};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {1182,912,1832,7754,9557,7980,4144,3194,7129,5535,1172,2043,6437,7252,9508,4745,8313,8020,4017};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 9535;
    all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 5 -----
    int t0[] = {8786,7391,201,4414,5822,5872,157,1832,7487,7518,2267,1763,3984,3102,7627,4099,524,1543,1022,3060};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {9905,7957,3625,6475,9314,9332,4370,8068,8295,8177,7772,2668,7191,8480,9211,4802,2625,1924,9970,4180};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 9813;
    all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
