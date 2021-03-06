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


class ListeningIn {
public:
  string probableMatch(string typed, string phrase) {
    int i = 0, j = 0;
    string ret = "";
  	while (i < typed.size()) {
      if (j == phrase.size())
        return "UNMATCHED";

      while (phrase[j] != typed[i]) {
        ret.push_back(phrase[j]);
        j++;
        if (j == phrase.size())
          return "UNMATCHED";
      }

      i++; j++;
    }
    
    for (; j < phrase.size(); j++)
      ret.push_back(phrase[j]);

    return ret;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, string p1, bool hasAnswer, string p2) {
  cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"";
  cout << "]" << endl;
  ListeningIn *obj;
  string answer;
  obj = new ListeningIn();
  clock_t startTime = clock();
  answer = obj->probableMatch(p0, p1);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << "\"" << p2 << "\"" << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << "\"" << answer << "\"" << endl;
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

  string p0;
  string p1;
  string p2;

  {
    // ----- test 0 -----
    p0 = "cptr";
    p1 = "capture";
    p2 = "aue";
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    p0 = "port to me";
    p1 = "teleport to me";
    p2 = "tele";
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    p0 = "back  to base";
    p1 = "back to base";
    p2 = "UNMATCHED";
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    p0 = "bbbbb";
    p1 = "abababab";
    p2 = "UNMATCHED";
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
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