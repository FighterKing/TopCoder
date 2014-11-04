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


class ImportantTasks {
public:
  int maximalCost(vector <int> complexity, vector <int> computers) {
    sort(computers.rbegin(), computers.rend());
    sort(complexity.rbegin(), complexity.rend());
    int count = 0;
    int j = 0;
    for (auto i : computers) {
      while (j < complexity.size() && complexity[j] > i)
        ++j;
      if (j >= complexity.size())
        return count;
      else
        ++count;
      ++j;
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
  ImportantTasks *obj;
  int answer;
  obj = new ImportantTasks();
  clock_t startTime = clock();
  answer = obj->maximalCost(p0, p1);
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
    int t0[] = {1,2,3};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {2,2,2};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 2;
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 1 -----
    int t0[] = {1,2,3};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {3};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 1;
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 2 -----
    int t0[] = {3,5,1,7};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {9,4,1,1,1};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 3;
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 3 -----
    int t0[] = {5,2,7,8,6,4,2,10,2,3};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {4,1,3,6,2,10,11,1,1,3,4,2};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 8;
    all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 4 -----
    int t0[] = {100};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {100,100};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 1;
    all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
// At Facebook, different tasks have to be executed simultaneously on a limited number of computers. You are given a set of incoming tasks. Each computer can execute at most one task, and each task must be fully executed on a single computer.  You are given vector <int>s complexity and computers.  Element i of complexity is the complexity of the i-th task.  Element i of computers is the maximal complexity of a task that can be handled by the i-th computer.  Return the maximal number of tasks that can be executed on the given computers.
// 
// DEFINITION
// Class:ImportantTasks
// Method:maximalCost
// Parameters:vector <int>, vector <int>
// Returns:int
// Method signature:int maximalCost(vector <int> complexity, vector <int> computers)
// 
// 
// CONSTRAINTS
// -complexity will contain between 1 and 50 elements, inclusive.
// -Each element of complexity will be between 1 and 1,000,000, inclusive.
// -computers will contain between 1 and 50 elements, inclusive.
// -Each element of computers will be between 1 and 1,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1,2,3}
// {2,2,2}
// 
// Returns: 2
// 
// The last task can't be executed on any of the computers.
// 
// 1)
// {1,2,3}
// {3}
// 
// Returns: 1
// 
// The computer can run any of the tasks, but there's only one computer, so only one task will be executed.
// 
// 2)
// {3,5,1,7}
// {9,4,1,1,1}
// 
// Returns: 3
// 
// It's impossible to execute all 4 tasks. In order to handle 3 tasks, you can execute task 0 on computer 1, task 2 on computer 2 and task 3 on computer 0 (all indices are 0-based).
// 
// 3)
// {5,2,7,8,6,4,2,10,2,3}
// {4,1,3,6,2,10,11,1,1,3,4,2}
// 
// Returns: 8
// 
// 
// 
// 4)
// {100}
// {100,100}
// 
// Returns: 1
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
