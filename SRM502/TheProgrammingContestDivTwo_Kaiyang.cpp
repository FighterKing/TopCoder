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


class TheProgrammingContestDivTwo {
public:
  vector <int> find(int T, vector <int> requiredTime) {
    sort(requiredTime.begin(), requiredTime.end());
    int score = 0, task = 0, currentTime = 0;
    for (auto i : requiredTime) {
      if (T >= i) {
        ++score;
        currentTime += i;
        T -= i;
        task += currentTime;
      }
    }
    return {score, task};
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, bool hasAnswer, vector <int> p2) {
  cout << "Test " << testNum << ": [" << p0 << "," << "{";
  for (int i = 0; int(p1.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << p1[i];
  }
  cout << "}";
  cout << "]" << endl;
  TheProgrammingContestDivTwo *obj;
  vector <int> answer;
  obj = new TheProgrammingContestDivTwo();
  clock_t startTime = clock();
  answer = obj->find(p0, p1);
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
	
  int p0;
  vector <int> p1;
  vector <int> p2;
	
  {
    // ----- test 0 -----
    p0 = 74;
    int t1[] = {47};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {1,47};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 1 -----
    p0 = 74;
    int t1[] = {4747};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {0,0};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 2 -----
    p0 = 47;
    int t1[] = {8,5};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {2,18};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 3 -----
    p0 = 47;
    int t1[] = {12,3,21,6,4,13};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {5,86};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 4 -----
    p0 = 58;
    int t1[] = {4,5,82,3,4,65,7,6,8,7,6,4,8,7,6,37,8};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {10,249};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
    // ------------------
  }
	
  {
    // ----- test 5 -----
    p0 = 100000;
    int t1[] = {100000};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {1,100000};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
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
// Farmer John and Fox Brus are participating in a programming contest as a team.
// 
// 
// The duration of the contest is T minutes and they are given N tasks. Solutions can be submitted at any time during the contest, including exactly T minutes after the start of the contest. It takes them requiredTime[i] minutes to solve the i-th task.
// 
// 
// The score in this contest is represented by two numbers, solved and penalty. Initially both numbers are 0. If they solve a task t minutes after the start of the contest, solved increases by 1 and penalty increases by t. Two scores are compared by solved first. If two scores have different solved, the score with bigger solved is better. If two scores have the same solved, the score with smaller penalty is better.
// 
// 
// Return a vector <int> containing exactly two integers that describes the best score they can get. The first integer of the return value must represent solved and the second integer must represent penalty.
// 
// DEFINITION
// Class:TheProgrammingContestDivTwo
// Method:find
// Parameters:int, vector <int>
// Returns:vector <int>
// Method signature:vector <int> find(int T, vector <int> requiredTime)
// 
// 
// CONSTRAINTS
// -T will be between 1 and 100,000, inclusive.
// -requiredTime will contain between 1 and 50 elements, inclusive.
// -Each element of requiredTime will be between 1 and 100,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 74
// {47}
// 
// Returns: {1, 47 }
// 
// They can solve the task. solved will be 1 and penalty will be 47.
// 
// 1)
// 74
// {4747}
// 
// Returns: {0, 0 }
// 
// They don't have time enough to solve the task.
// 
// 2)
// 47
// {8, 5}
// 
// Returns: {2, 18 }
// 
// The order is important. If they solve task 0 first and task 1 second, solved will be 2 and penalty will be 21. If they solve task 1 first and task 0 second, solved will be 2 and penalty will be 18.
// 
// 3)
// 47
// {12, 3, 21, 6, 4, 13}
// 
// Returns: {5, 86 }
// 
// 
// 
// 4)
// 58
// {4, 5, 82, 3, 4, 65, 7, 6, 8, 7, 6, 4, 8, 7, 6, 37, 8}
// 
// Returns: {10, 249 }
// 
// 
// 
// 5)
// 100000
// {100000}
// 
// Returns: {1, 100000 }
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
