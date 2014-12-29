// First, we remove rectangles less than 'limit'.
// then, we exchange width and height to make sure width less then
// height.
// and sort thest rectangles by their width.
// {3,6,5,8,2,9,14}   => {2, 3, 3, 5, 6, 6, 8}
// {14,6,13,8,15,6,3} => {15, 14, 14, 13, 6, 9, 8}
// We first pick (2, 15) then we find those rectangles whose height is
// no less than ceil(limit / double(2)), then we first pick (3, 14)
// ... quite straight forward.
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


class PilingRectsDiv2 {
public:
  int getmax(vector <int> X, vector <int> Y, int limit) {
    vector<pair<int, int>> p;
    vector<int> x, y;
    int i = 0;
    int size = X.size();
    for (; i < size; ++i) {
      if (X[i] * Y[i] >= limit) {
        p.push_back(make_pair(min(X[i], Y[i]), max(X[i], Y[i])));
      }
    }

    sort(p.begin(), p.end());
    for (auto i : p) {
      x.push_back(i.first);
      y.push_back(i.second);
    } 
                       
    int count = -1;
    size = x.size();
    if (size == 0)
      return -1;
    
    p.clear();
    for (int i = 0; i < size; ++i) {
      int down = ceil(limit / static_cast<double>(x[i]));
      int t = 1;
      p.clear();
      p.push_back(make_pair(x[i], y[i]));
      for (int j = i + 1; j < size; ++j) {
        if (y[j] >= down) {
          ++t;
          p.push_back(make_pair(x[j], y[j]));
        }
      }
      count = max(count, t);
    }
    return count;
  }

};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, int p3) {
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
  cout << "}" << "," << p2;
  cout << "]" << endl;
  PilingRectsDiv2 *obj;
  int answer;
  obj = new PilingRectsDiv2();
  clock_t startTime = clock();
  answer = obj->getmax(p0, p1, p2);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << p3 << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << answer << endl;
  if (hasAnswer) {
    res = answer == p3;
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
  int p3;
	
  {
    // ----- test 0 -----
    int t0[] = {193, 79, 92, 27, 144, 161, 173, 58, 143, 177, 167, 147, 3, 154, 26, 75, 148, 155, 60, 195, 48, 118, 5, 88, 161, 147, 37, 127, 170, 183, 95, 195, 28, 159, 64, 79, 179, 119};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] =  {123, 53, 151, 140, 145, 50, 177, 145, 199, 161, 161, 90, 125, 82, 97, 166, 161, 6, 45, 84, 102, 198, 131, 91, 21, 160, 132, 108, 104, 39, 30, 88, 20, 132, 114, 37, 53, 58};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 15171;
    p3 = 10;
    all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }
	
  {
    // ----- test 1 -----
    int t0[] = {4,7};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {7,4};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 25;
    p3 = 2;
    all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }
	
  {
    // ----- test 2 -----
    int t0[] = {10};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {10};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 9999;
    p3 = -1;
    all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }
	
  {
    // ----- test 3 -----
    int t0[] = {10};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {3};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 30;
    p3 = 1;
    all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }
	
  {
    // ----- test 4 -----
    int t0[] = {3,6,5,8,2,9,14};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {14,6,13,8,15,6,3};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 27;
    p3 = 4;
    all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
    // ------------------
  }
	
  {
    // ----- test 5 -----
    int t0[] = {121,168,86,106,36,10,125,97,53,26,148,129,41,18,173,55,13,73,91,174,177,190,28,164,122,92,5,26,58,188,14,67,48,196,41,94,24,89,54,117,12,6,155,103,200,128,184,29,92,149};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {199,182,43,191,2,145,15,53,38,37,61,45,157,129,119,123,177,178,183,188,132,108,112,137,92,59,75,196,102,152,114,121,181,93,32,3,24,116,4,163,96,159,196,43,59,150,79,113,20,146};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 5345;
    p3 = 24;
    all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
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
// Snake Snuke has N rectangles cut out of paper.
// The rectangles are labeled 0 through N-1.
// You are given vector <int>s X and Y with N elements each.
// For each i, the sides of rectangle i have lengths X[i] and Y[i].
// 
// Snake Snuke will choose some of his rectangles and place them onto a table, one rectangle at a time, in any order he likes.
// Each rectangle (except for the first one) must overlap the immediately previous one, so at the end Snuke will have a pile of rectangles.
// Snuke may rotate the rectangles, but once placed, the sides of each rectangle must be parallel to the sides of the table.
// (I.e., he may only swap the width and height of some rectangles he places.)
// After placing all the rectangles, Snuke computes the area that is covered by all N rectangles.
// (Formally, the area of their intersection.)
// 
// You are also given an int limit.
// The area computed by Snuke must be greater than or equal to limit.
// 
// Return the largest positive R such that Snuke can select some R of his rectangles and place them in such a way that the area of their intersection is at least limit. If there is no such R, return -1 instead.
// 
// 
// DEFINITION
// Class:PilingRectsDiv2
// Method:getmax
// Parameters:vector <int>, vector <int>, int
// Returns:int
// Method signature:int getmax(vector <int> X, vector <int> Y, int limit)
// 
// 
// CONSTRAINTS
// -X and Y will contain between 1 and 50 elements, inclusive.
// -X and Y will contain the same number of elements.
// -Each element of X and Y will be between 1 and 200, inclusive.
// -limit will be between 1 and 40000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1,2,3,1}
// {3,2,4,4}
// 3
// 
// Returns: 3
// 
// He can choose rectangles 0, 2, and 3. These three rectangles can then be placed in such a way that both rectangle 2 and rectangle 3 cover rectangle 0 completely. For this placement, the area of their intersection will be exactly 3.
// 
// 1)
// {4,7}
// {7,4}
// 25
// 
// Returns: 2
// 
// Note that he can rotate rectangles.
// 
// 2)
// {10}
// {10}
// 9999
// 
// Returns: -1
// 
// There is no possible choice.
// 
// 3)
// {10}
// {3}
// 30
// 
// Returns: 1
// 
// 
// 
// 4)
// {3,6,5,8,2,9,14}
// {14,6,13,8,15,6,3}
// 27
// 
// Returns: 4
// 
// 
// 
// 5)
// {121,168,86,106,36,10,125,97,53,26,148,129,41,18,173,55,13,73,91,174,177,190,28,164,122,92,5,26,58,188,14,67,48,196,41,94,24,89,54,117,12,6,155,103,200,128,184,29,92,149}
// {199,182,43,191,2,145,15,53,38,37,61,45,157,129,119,123,177,178,183,188,132,108,112,137,92,59,75,196,102,152,114,121,181,93,32,3,24,116,4,163,96,159,196,43,59,150,79,113,20,146}
// 5345
// 
// Returns: 24
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
