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


class RGBStreet {
public:
  int estimateCost(vector <string> houses) {
    int size = houses.size();
    vector<vector<unsigned int>> v(size, vector<unsigned int>(3, -1));
    stringstream strStream(houses[0]);
    vector<int> costs(3, 0);
    int i = 0;
    while (strStream >> costs[i++]);
    v[0][0] = costs[0];
    v[0][1] = costs[1];
    v[0][2] = costs[2];
    for (i = 1; i < size; ++i) {
      stringstream strStream(houses[i]);
      int j = 0;
      while (strStream >> costs[j++]);
      v[i][0] = min(v[i - 1][1], v[i - 1][2]) + costs[0];
      v[i][1] = min(v[i - 1][0], v[i - 1][2]) + costs[1];
      v[i][2] = min(v[i - 1][0], v[i - 1][1]) + costs[2];
    }
    return min({v[size - 1][0], v[size - 1][1], v[size - 1][2]});
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
  cout << "Test " << testNum << ": [" << "{";
  for (int i = 0; int(p0.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << "\"" << p0[i] << "\"";
  }
  cout << "}";
  cout << "]" << endl;
  RGBStreet *obj;
  int answer;
  obj = new RGBStreet();
  clock_t startTime = clock();
  answer = obj->estimateCost(p0);
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
	
  vector <string> p0;
  int p1;
	
  {
    // ----- test 0 -----
    string t0[] = {"1 100 100","100 1 100","100 100 1"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 3;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 1 -----
    string t0[] = {"1 100 100","100 100 100","1 100 100"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 102;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 2 -----
    string t0[] = {"26 40 83","49 60 57","13 89 99"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 96;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 3 -----
    string t0[] = {"30 19 5","64 77 64","15 19 97","4 71 57","90 86 84","93 32 91"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 208;
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------
  }
	
  {
    // ----- test 4 -----
    string t0[] = {"71 39 44","32 83 55","51 37 63","89 29 100","83 58 11","65 13 15","47 25 29","60 66 19"};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 253;
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
// PROBLEM STATEMENT
// The people of RGB Street have decided to paint each of their houses red, green, or blue.  They've also decided that no two neighboring houses will be painted the same color.  The neighbors of house i are houses i-1 and i+1.  The first and last houses are not neighbors.
// 
// You will be given a vector <string> houses, where the ith element corresponds to house i.  Each element of houses will be formatted as "R G B" (quotes for clarity only), where R, G and B are the costs of painting the corresponding house red, green, and blue, respectively.  Return the minimal total cost required to perform the work.
// 
// 
// 
// DEFINITION
// Class:RGBStreet
// Method:estimateCost
// Parameters:vector <string>
// Returns:int
// Method signature:int estimateCost(vector <string> houses)
// 
// 
// CONSTRAINTS
// -houses will contain between 1 and 20 elements, inclusive.
// -Each element of houses will be in the format "R G B" (quotes for clarity only), where R, G and B are integers with no leading zeroes.
// -In each element of houses, the values R, G and B will be between 1 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"1 100 100", "100 1 100", "100 100 1"}
// 
// Returns: 3
// 
// "RGB" is the best choice, and the total cost of the work is equal to 3.
// 
// 1)
// {"1 100 100", "100 100 100", "1 100 100"}
// 
// Returns: 102
// 
// The minimum possible cost is 102, and there are two solutions that result in that cost: "RGR" and "RBR". 
// 
// 
// 2)
// {"26 40 83", "49 60 57", "13 89 99"}
// 
// Returns: 96
// 
// 3)
// {"30 19 5", "64 77 64", "15 19 97", "4 71 57", "90 86 84", "93 32 91"}
// 
// Returns: 208
// 
// 
// 
// 4)
// {"71 39 44", "32 83 55", "51 37 63", "89 29 100", 
//  "83 58 11", "65 13 15", "47 25 29", "60 66 19"}
// 
// Returns: 253
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!


