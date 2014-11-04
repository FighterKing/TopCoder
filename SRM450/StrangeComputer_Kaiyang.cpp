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


class StrangeComputer {
public:
  int setMemory(string mem) {
    int count = 0;
    char lastBit = '0';
    for (auto i : mem) {
      if (i != lastBit) {
        ++count;
        lastBit = i;
      }
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
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
  cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
  cout << "]" << endl;
  StrangeComputer *obj;
  int answer;
  obj = new StrangeComputer();
  clock_t startTime = clock();
  answer = obj->setMemory(p0);
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
    p0 = "0011";
    p1 = 1;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 1 -----
    p0 = "000";
    p1 = 0;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 2 -----
    p0 = "0100";
    p1 = 2;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 3 -----
    p0 = "111000111";
    p1 = 3;
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
// You have been given a very strange computer.  Its memory consists of several bits, each initially set to 0, and it can only perform the following type of operation:
// 
// Choose one of the bits in memory, and choose a value - 0 or 1.  All the bits between the selected bit and the last bit in memory, inclusive, will be set to the chosen value.  For example, if the memory is "0010", and you choose the second bit and a value of 1, the memory will change to "0111".
// 
// You are given a string mem.  The number of characters in mem is equal to the number of bits in the computer's memory.  Return the minimum number of operations required to set the computer's memory equal to mem.
// 
// DEFINITION
// Class:StrangeComputer
// Method:setMemory
// Parameters:string
// Returns:int
// Method signature:int setMemory(string mem)
// 
// 
// CONSTRAINTS
// -mem will contain between 1 and 50 characters, inclusive.
// -mem will contain only the characters '0' (zero) or '1' (one).
// 
// 
// EXAMPLES
// 
// 0)
// "0011"
// 
// Returns: 1
// 
// Choose the third bit and a value of 1.
// 
// 1)
// "000"
// 
// Returns: 0
// 
// No operations are needed.
// 
// 2)
// "0100"
// 
// Returns: 2
// 
// 0000 -> 0111 -> 0100
// 
// 3)
// "111000111"
// 
// Returns: 3
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
