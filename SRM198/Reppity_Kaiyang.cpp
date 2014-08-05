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


class Reppity {
public:
  int longestRep(string input) {
    int size = input.size();
    int re = size / 2;
    while (re > 0) {
      int startPos = 0;
      
      while (startPos + re <= size) {
        int pos = startPos;
        string str = input.substr(pos, re), str2;
        pos += re;
        while (pos + re <= size && str != str2) {
          str2 = input.substr(pos, re);
          ++pos;
        }

        if (str == str2)
          return re;
        ++startPos;
      }
      --re;
    }
    return 0;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
  cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
  cout << "]" << endl;
  Reppity *obj;
  int answer;
  obj = new Reppity();
  clock_t startTime = clock();
  answer = obj->longestRep(p0);
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

  string p0;
  int p1;

  {
    // ----- test 0 -----
    p0 = "ABCDEXXXYYYZZZABCDEZZZYYYXXX";
    p1 = 5;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    p0 = "abcdabcdabcdabCD";
    p1 = 6;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    p0 = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";
    p1 = 25;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    p0 = "againANDagainANDagainANDagainANDagainANDagain";
    p1 = 21;
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 4 -----
    p0 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWX";
    p1 = 0;
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
