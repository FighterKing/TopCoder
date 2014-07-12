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


class RandomColoringDiv2 {
  int getMost(int maxColor, int startColor, int d2) {
    int most = min(d2, maxColor - startColor - 1);
    most += startColor - max(0, startColor - d2) + 1;
    return most;
  }
  
  int getLeastMost(int maxColor, int startColor, int d1, int d2) {
    int least = 0;
    int leastColor = 0;
    if (startColor + d2 <= maxColor - 1)
      maxColor = startColor + d2 + 1;


    if (startColor - d2 >= 0) 
      leastColor = startColor - d2;

    if (startColor + d1 <= maxColor - 1){
      least += maxColor - (startColor + d1);
    }
    if (startColor - d1 >= leastColor) {
      least += startColor - d1 - leastColor + 1;
    }

    if (0 == d1)
      --least;
    return least;
  }
public:
  int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
    int mostR = getMost(maxR, startR, d2);
    int mostG = getMost(maxG, startG, d2);
    int mostB = getMost(maxB, startB, d2);
    
    int lmR = getLeastMost(maxR, startR, d1, d2);
    int lmG = getLeastMost(maxG, startG, d1, d2);
    int lmB = getLeastMost(maxB, startB, d1, d2);
    
    int sum = mostR * mostG * mostB;
    sum -= (mostR - lmR) * (mostG - lmG) * (mostB - lmB);
    return sum;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, bool hasAnswer, int p8) {
  cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4 << "," << p5 << "," << p6 << "," << p7;
  cout << "]" << endl;
  RandomColoringDiv2 *obj;
  int answer;
  obj = new RandomColoringDiv2();
  clock_t startTime = clock();
  answer = obj->getCount(p0, p1, p2, p3, p4, p5, p6, p7);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << p8 << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << answer << endl;
  if (hasAnswer) {
    res = answer == p8;
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
  int p1;
  int p2;
  int p3;
  int p4;
  int p5;
  int p6;
  int p7;
  int p8;

  {
    // ----- test 0 -----
    p0 = 5;
    p1 = 1;
    p2 = 1;
    p3 = 2;
    p4 = 0;
    p5 = 0;
    p6 = 0;
    p7 = 1;
    p8 = 3;
    all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    p0 = 4;
    p1 = 2;
    p2 = 2;
    p3 = 0;
    p4 = 0;
    p5 = 0;
    p6 = 3;
    p7 = 3;
    p8 = 4;
    all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    p0 = 4;
    p1 = 2;
    p2 = 2;
    p3 = 0;
    p4 = 0;
    p5 = 0;
    p6 = 5;
    p7 = 5;
    p8 = 0;
    all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    p0 = 6;
    p1 = 9;
    p2 = 10;
    p3 = 1;
    p4 = 2;
    p5 = 3;
    p6 = 0;
    p7 = 10;
    p8 = 540;
    all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
    // ------------------
  }

  {
    // ----- test 4 -----
    p0 = 6;
    p1 = 9;
    p2 = 10;
    p3 = 1;
    p4 = 2;
    p5 = 3;
    p6 = 4;
    p7 = 10;
    p8 = 330;
    all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
    // ------------------
  }

  {
    // ----- test 5 -----
    p0 = 49;
    p1 = 59;
    p2 = 53;
    p3 = 12;
    p4 = 23;
    p5 = 13;
    p6 = 11;
    p7 = 22;
    p8 = 47439;
    all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
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
