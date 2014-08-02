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


class Pronunciation {
public:
  string canPronounce(vector <string> words) {
    int case1 = 0, case2 = 0;
    char last = 0;
    for (auto i : words) {
      case1 = 0;
      case2 = 0;
      for (auto j : i) {
        switch (tolower(j)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          if (last != tolower(j)) {
            ++case2;
          } else {
            case2 = 1;
          }
          last = tolower(j);
          case1 = 0;
          break;
        default:
          ++case1;
          case2 = 0;
          break;
        }
        if (case1 >= 3 || case2 >= 2)
          return i;
      }
    }
    return "";
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
  cout << "Test " << testNum << ": [" << "{";
  for (int i = 0; int(p0.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << "\"" << p0[i] << "\"";
  }
  cout << "}";
  cout << "]" << endl;
  Pronunciation *obj;
  string answer;
  obj = new Pronunciation();
  clock_t startTime = clock();
  answer = obj->canPronounce(p0);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << "\"" << p1 << "\"" << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << "\"" << answer << "\"" << endl;
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
  string p1;

  {
    // ----- test 0 -----
    string t0[] = {"All","of","these","are","not","difficult"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = "";
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    string t0[] = {"The","word","REALLY","is","really","hard"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = "REALLY";
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    string t0[] = {"TRiCKy"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = "TRiCKy";
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    string t0[] = {"irresistable","prerogative","uttermost","importance"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = "";
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 4 -----
    string t0[] = {"Aa"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = "";
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
