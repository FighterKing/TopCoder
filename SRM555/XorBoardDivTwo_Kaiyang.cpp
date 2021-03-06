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


class XorBoardDivTwo {
  int get(vector<string> &b) {
    int sum = 0;
    for (auto i : b) {
      for (auto j : i) {
        if (j == '1') 
          ++sum;
      }
    }
    return sum;
  }
public:
  int theMax(vector <string> board) {
    int Y = board.size();
    int X = board[0].size();
    int max = 0;
    for (int i = 0; i < Y; ++i) {
      vector<string> t = board;
      
      for (int k = 0; k < X; ++k) {
        if (t[i][k] == '0')
          t[i][k] = '1';
        else 
          t[i][k] = '0';
      }
      
      for (int k = 0; k < X; ++k) {
        vector<string> tt = t;
        for (int j = 0; j < Y; ++j) {
          if (tt[j][k] == '0')
            tt[j][k] = '1';
          else 
            tt[j][k] = '0';
        }
        
        int value = get(tt);
        if (value > max) 
          max = value;
      }
    }
      return max;
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
  XorBoardDivTwo *obj;
  int answer;
  obj = new XorBoardDivTwo();
  clock_t startTime = clock();
  answer = obj->theMax(p0);
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
    string t0[] = {"101","010","101"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 9;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    string t0[] = {"111","111","111"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 5;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    string t0[] = {"0101001","1101011"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 9;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    string t0[] = {"000","001","010","011","100","101","110","111"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 15;
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 4 -----
    string t0[] = {"000000000000000000000000","011111100111111001111110","010000000100000001000000","010000000100000001000000","010000000100000001000000","011111100111111001111110","000000100000001000000010","000000100000001000000010","000000100000001000000010","011111100111111001111110","000000000000000000000000"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 105;
    all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
