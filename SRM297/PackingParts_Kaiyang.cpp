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


class PackingParts {
public:
  int pack(vector <int> partSizes, vector <int> boxSizes) {
    int count = 0;
    int j = 0;
    for (auto i : partSizes) {
      while (j < boxSizes.size() && boxSizes[j] < i)
        ++j;
      if (j >= boxSizes.size()) break;
      ++j;
      ++count;
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
  PackingParts *obj;
  int answer;
  obj = new PackingParts();
  clock_t startTime = clock();
  answer = obj->pack(p0, p1);
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
    int t0[] = {2,2,2};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {1,2,2,3};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 3;
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 1 -----
    int t0[] = {1,5};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {2,5};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 2;
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 2 -----
    int t0[] = {10,10,10,10};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {9,9,9,10,10,10};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 3;
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 3 -----
    int t0[] = {1,1,1,1};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {1,2,2,3,6,7};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 4;
    all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 4 -----
    int t0[] = {1,1,1,1};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {2,3,6};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 3;
    all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 5 -----
    int t0[] = {10,32,46,55,55,84,100};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {15,31,34,46,59,68,83,99};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 6;
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
// PROBLEM STATEMENT
// 
// Given a set of parts and a set of boxes, you are asked to determine how many of the parts can be packed into  boxes. You can put at most one part into each box. In order for a part to fit into a box, the box must be the same size as or larger than the part. You follow the following process when packing the parts:
// 
// 
// Choose the smallest part that has not been packed yet.
// Find the smallest empty box the part fits into. If there is no such box, you cannot pack any more parts, and you stop.
// Pack the part into the box.
// If all parts have been packed, stop. Otherwise, continue with step 1.
// 
// 
// 
// You are given a vector <int> partSizes containing the sizes of the parts, and a vector <int> boxSizes containing the sizes of the boxes. Both vector <int>s will be sorted in non-descending order.
// 
// 
// Return an int representing the maximum number of parts you can pack by following the process above.
// 
// 
// DEFINITION
// Class:PackingParts
// Method:pack
// Parameters:vector <int>, vector <int>
// Returns:int
// Method signature:int pack(vector <int> partSizes, vector <int> boxSizes)
// 
// 
// CONSTRAINTS
// -partSizes will contain between 1 and 50 elements, inclusive.
// -boxSizes will contain between 1 and 50 elements, inclusive.
// -Both partSizes and boxSizes will be sorted in non-decreasing order.
// -Each element in partSizes and boxSizes will be between 1 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {2,2,2}
// {1,2,2,3}
// 
// Returns: 3
// 
// We have three parts of size 2. Two of them can be packed into boxes of size 2, and one into a box of size 3.
// 
// 1)
// {1,5}
// {2,5}
// 
// Returns: 2
// 
// The part of size 1 goes into the box of size 2 and the part of size 5 goes into the box of size 5.
// 
// 2)
// {10,10,10,10}
// {9,9,9,10,10,10}
// 
// Returns: 3
// 
// We have four parts of size 10, but only three boxes that can fit parts that big.
// 
// 3)
// {1,1,1,1}
// {1,2,2,3,6,7}
// 
// Returns: 4
// 
// Here, we have plenty of boxes to choose from.
// 
// 4)
// {1,1,1,1}
// {2,3,6}
// 
// Returns: 3
// 
// The boxes are big, but we only have three, so we cannot pack four parts.
// 
// 5)
// {10,32,46,55,55,84,100}
// {15,31,34,46,59,68,83,99}
// 
// Returns: 6
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!

