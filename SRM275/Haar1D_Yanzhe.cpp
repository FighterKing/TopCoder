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


class Haar1D {
public:
  vector <int> transform(vector <int> data, int L) {
  	int N = data.size();
  	for (int l = 0; l < L; l++) {
  		int n = N / pow(2, l);
  		vector<int> shadow(n);
  		for (int i = 0; i < n; i += 2) {
  			shadow[i/2] = data[i] + data[i+1];
  			shadow[i/2 + n/2] = data[i] - data[i+1];
  		}
  		for (int i = 0; i < n; i++)
  			data[i] = shadow[i];
  	}
  	return data;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, vector <int> p2) {
  cout << "Test " << testNum << ": [" << "{";
  for (int i = 0; int(p0.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << p0[i];
  }
  cout << "}" << "," << p1;
  cout << "]" << endl;
  Haar1D *obj;
  vector <int> answer;
  obj = new Haar1D();
  clock_t startTime = clock();
  answer = obj->transform(p0, p1);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << "{";
    for (int i = 0; int(p2.size()) > i; ++i) {
      if (i > 0) {
        cout << ",";
      }
      cout << p2[i];
    }
    cout << "}" << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << "{";
  for (int i = 0; int(answer.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << answer[i];
  }
  cout << "}" << endl;
  if (hasAnswer) {
    if (answer.size() != p2.size()) {
      res = false;
    } else {
      for (int i = 0; int(answer.size()) > i; ++i) {
        if (answer[i] != p2[i]) {
          res = false;
        }
      }
    }
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
  int p1;
  vector <int> p2;

  {
    // ----- test 0 -----
    int t0[] = {1,2,3,5};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 1;
    int t2[] = {3,8,-1,-2};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    int t0[] = {1,2,3,5};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 2;
    int t2[] = {11,-5,-1,-2};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    int t0[] = {1,2,3,4,4,3,2,1};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 3;
    int t2[] = {20,0,-4,4,-1,-1,1,1};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    int t0[] = {94,47,46,28,39,89,75,4,28,62,69,89,34,55,81,24};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 2;
    int t2[] = {215,207,248,194,67,49,-68,-16,47,18,-50,71,-34,-20,-21,57};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
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