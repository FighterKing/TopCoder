// Same solution as tc
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


class PiecewiseLinearFunctionDiv2 {
public:
  vector <int> countSolutions(vector <int> Y, vector <int> query) {
    vector<pair<int, int>> v;
    vector<int> re;
    int i = 0;
    for (i = 1; i < Y.size(); ++i)
      v.push_back(make_pair(Y[i - 1], Y[i]));
    
    for (auto i : query) {
      int count = 0;
      int j = 0;
      for (; j < v.size() - 1; ++j) {
        if (i == v[j].first && i == v[j].second) {
          re.push_back(-1);
          break;
        } else if ((i >= v[j].first && i < v[j].second) || 
                   (i > v[j].second && i <= v[j].first)) {
          ++count;
        }
      }
      if (j < v.size() - 1)
        continue;
      
      if (i == v[j].first && i == v[j].second) {
        re.push_back(-1);
        continue;
      } else if ((i >= v[j].first && i <= v[j].second) || 
                  (i >= v[j].second && i <= v[j].first)) {
        ++count;
      }
      
      re.push_back(count);
    }
    return re;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, vector <int> p2) {
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
  PiecewiseLinearFunctionDiv2 *obj;
  vector <int> answer;
  obj = new PiecewiseLinearFunctionDiv2();
  clock_t startTime = clock();
  answer = obj->countSolutions(p0, p1);
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
  vector <int> p1;
  vector <int> p2;
	
  {
    // ----- test 0 -----
    int t0[] = {1,4,-1,2};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {-2,-1,0,1};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {0,1,2,3};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 1 -----
    int t0[] = {0,0};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {-1,0,1};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {0,-1,0};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 2 -----
    int t0[] = {2,4,8,0,3,-6,10};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {0,1,2,3,4,0,65536};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {3,4,5,4,3,3,0};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 3 -----
    int t0[] = {-178080289,-771314989,-237251715,-949949900,-437883156,-835236871,-316363230,-929746634,-671700962};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {-673197622,-437883156,-251072978,221380900,-771314989,-949949900,-910604034,-671700962,-929746634,-316363230};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {8,6,3,0,7,1,4,8,3,4};
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
// PROBLEM STATEMENT
// F is a function that is defined on all real numbers from the closed interval [1,N].
// You are given a vector <int> Y with N elements.
// For each i (1 <= i <= N) we have F(i) = Y[i-1].
// Additionally, you know that F is piecewise linear: for each i, on the interval [i,i+1] F is a linear function.
// The function F is uniquely determined by this information.
// For example, if F(4)=1 and F(5)=6 then we must have F(4.7)=4.5.
// 
// As another example, this is the plot of the function F for Y = {1, 4, -1, 2}.
// 
// 
// 
// You are also given a vector <int> query.
// For each i, compute the number of solutions to the equation F(x) = query[i].
// Note that sometimes this number of solutions can be infinite.
// 
// Return a vector <int> of the same length as query.
// For each i, element i of the return value should be -1 if the equation F(x) = query[i] has an infinite number of solutions.
// Otherwise, element i of the return value should be the actual number of solutions this equation has.
// 
// DEFINITION
// Class:PiecewiseLinearFunctionDiv2
// Method:countSolutions
// Parameters:vector <int>, vector <int>
// Returns:vector <int>
// Method signature:vector <int> countSolutions(vector <int> Y, vector <int> query)
// 
// 
// CONSTRAINTS
// -Y will contain between 2 and 50 elements, inclusive.
// -Each element of Y will be between -1,000,000,000 and 1,000,000,000, inclusive.
// -query will contain between 1 and 50 elements, inclusive.
// -Each element of query will be between -1,000,000,000 and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1, 4, -1, 2}
// {-2, -1, 0, 1}
// 
// Returns: {0, 1, 2, 3 }
// 
// This is the example from the problem statement. The detailed information about the queries is:
// 
// There is no such x that F(x) = -2 is satisfied.
// F(x) = -1 is only true for x = 3.
// F(x) = 0 has two roots: 2.8 and 10/3.
// F(x) = 1 has three roots: 1, 2.6 and 11/3.
// 
// 
// 1)
// {0, 0}
// {-1, 0, 1}
// 
// Returns: {0, -1, 0 }
// 
// This function's plot is a horizontal segment between points (1, 0) and (2, 0). F(x) = 0 is satisfied for any x between 1 and 2 and thus the number of solutions is infinite. For any other value on the right-hand side, it has no solutions.
// 
// 2)
// {2, 4, 8, 0, 3, -6, 10}
// {0, 1, 2, 3, 4, 0, 65536}
// 
// Returns: {3, 4, 5, 4, 3, 3, 0 }
// 
// 
// 
// 3)
// {-178080289, -771314989, -237251715, -949949900, -437883156, -835236871, -316363230, -929746634, -671700962}
// 
// {-673197622, -437883156, -251072978, 221380900, -771314989, -949949900, -910604034, -671700962, -929746634, -316363230}
// 
// Returns: {8, 6, 3, 0, 7, 1, 4, 8, 3, 4 }
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!

