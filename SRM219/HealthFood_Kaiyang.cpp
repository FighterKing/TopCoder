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


class HealthFood {
  bool helperMin(const vector<int>& v, vector<int> &re, vector<bool> &exist) {
    unsigned int min = -1;
    for (int i = 0; i < exist.size(); ++i) {
      if (exist[i] && v[i] < min) {
        min = v[i];
      }
    }
          
    for (int i = 0; i < exist.size(); ++i) {
      if (exist[i] && v[i] > min)
        exist[i] = false;
    }
          
    int count = 0;
    int index = 0;
    for (int i = 0; i < exist.size(); ++i) {
      if (exist[i]) {
        ++count;
        index = i;
      }
    }
    if (count == 1) {
      re.push_back(index);
      return true;
    }
    return false;    
  }
  bool helperMax(const vector<int>& v, vector<int> &re, vector<bool> &exist) {
    int max = 0;
    for (int i = 0; i < exist.size(); ++i) {
      if (exist[i] && v[i] > max) {
        max = v[i];
      }
    }
          
    for (int i = 0; i < exist.size(); ++i) {
      if (exist[i] && v[i] < max)
        exist[i] = false;
    }
          
    int count = 0;
    int index = 0;
    for (int i = 0; i < exist.size(); ++i) {
      if (exist[i]) {
        ++count;
        index = i;
      }
    }
    if (count == 1) {
      re.push_back(index);
      return true;
    }
    return false;
  }
public:
  vector <int> selectMeals(vector <int> protein, vector <int> carbs, vector <int> fat, vector <string> dietPlans) {
    vector<int> re;
    vector<int> calorie;
    for (int i = 0; i < protein.size(); ++i) {
      calorie.push_back(fat[i] * 9 + (carbs[i] + protein[i]) * 5);
    }
    for (auto str : dietPlans) {
      vector<bool> exist(protein.size(), true);
      bool done = false;
      for (auto c : str) {
        if (done)
          break;

        switch(c) {
        case 'C':
          done = helperMax(carbs, re, exist);
          break;
        case 'c':
          done = helperMin(carbs, re, exist);
          break;
        case 'P':
          done = helperMax(protein, re, exist);
          break;
        case 'p':
          done = helperMin(protein, re, exist);
          break;
        case 'F':
          done = helperMax(fat, re, exist);
          break;
        case 'f':
          done = helperMin(fat, re, exist);
          break;
        case 'T':
          done = helperMax(calorie, re, exist);
          break;
        case 't':
          done = helperMin(calorie, re, exist);
          break;
        }
      }
      for (int i = 0; !done && i < exist.size(); ++i) {
        if (exist[i]) {
          re.push_back(i);
          break;
        }
      }
    }
    return re;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, vector <string> p3, bool hasAnswer, vector <int> p4) {
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
  cout << "}" << "," << "{";
  for (int i = 0; int(p2.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << p2[i];
  }
  cout << "}" << "," << "{";
  for (int i = 0; int(p3.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << "\"" << p3[i] << "\"";
  }
  cout << "}";
  cout << "]" << endl;
  HealthFood *obj;
  vector <int> answer;
  obj = new HealthFood();
  clock_t startTime = clock();
  answer = obj->selectMeals(p0, p1, p2, p3);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << "{";
    for (int i = 0; int(p4.size()) > i; ++i) {
      if (i > 0) {
        cout << ",";
      }
      cout << p4[i];
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
    if (answer.size() != p4.size()) {
      res = false;
    } else {
      for (int i = 0; int(answer.size()) > i; ++i) {
        if (answer[i] != p4[i]) {
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
  vector <string> p3;
  vector <int> p4;

  {
    // ----- test 0 -----
    int t0[] = {3,4};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {2,8};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {5,2};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    string t3[] = {"P","p","C","c","F","f","T","t"};
    p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
    int t4[] = {1,0,1,0,0,1,1,0};
    p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
    all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    int t0[] = {3,4,1,5};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {2,8,5,1};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {5,2,4,4};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    string t3[] = {"tFc","tF","Ftc"};
    p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
    int t4[] = {3,2,0};
    p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
    all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    int t0[] = {18,86,76,0,34,30,95,12,21};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {26,56,3,45,88,0,10,27,53};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    int t2[] = {93,96,13,95,98,18,59,49,86};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    string t3[] = {"f","Pt","PT","fT","Cp","C","t","","cCp","ttp","PCFt","P","pCt","cP","Pc"};
    p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
    int t4[] = {2,6,6,2,4,4,5,0,5,5,6,6,3,5,6};
    p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
    all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
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
