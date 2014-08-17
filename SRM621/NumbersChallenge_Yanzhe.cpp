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

// Dynamic Programming
class NumbersChallenge
{
public:
    int MinNumber(vector <int> S)
    {
        bool *memo = new bool[2000001] {false};
        memo[0] = true;

        for (auto d : S) {
            for (int j = 2000000; j - d >= 0; j--)
                if (memo[j - d])
                    memo[j] = true;
        }

        int r = 0;
        for (; r < 2000001; r++)
            if (!memo[r]) break;
        delete []memo;
        return r;
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1)
{
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}";
    cout << "]" << endl;
    NumbersChallenge *obj;
    int answer;
    obj = new NumbersChallenge();
    clock_t startTime = clock();
    answer = obj->MinNumber(p0);
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
int main()
{
    bool all_right;
    all_right = true;

    vector <int> p0;
    int p1;

    {
        // ----- test 0 -----
        int t0[] = {5, 1, 2};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 4;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {2, 1, 4};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 8;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {2, 1, 2, 7};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 6;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 1092;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        int t0[] = {883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 56523;
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
// Your friend Lucas gave you a sequence S of positive integers.
//
// For a while, you two played a simple game with S:
// Lucas would pick a number, and you had to select some elements of S such that the sum of all numbers you selected is the number chosen by Lucas.
// For example, if S={2,1,2,7} and Lucas chose the number 11, you would answer that 2+2+7 = 11.
//
// Lucas now wants to trick you by choosing a number X such that there will be no valid answer.
// For example, if S={2,1,2,7}, it is not possible to select elements of S that sum up to 6.
//
// You are given the vector <int> S.
// Find the smallest positive integer X that cannot be obtained as the sum of some (possibly all) elements of S.
//
// DEFINITION
// Class:NumbersChallenge
// Method:MinNumber
// Parameters:vector <int>
// Returns:int
// Method signature:int MinNumber(vector <int> S)
//
//
// CONSTRAINTS
// -S will contain between 1 and 20 elements, inclusive.
// -Each element of S will be between 1 and 100,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// {5, 1, 2}
//
// Returns: 4
//
// These are all the positive integers that can be obtained: 1, 2, 3, 5, 6, 7, and 8.
// (We can obtain 3 as 1+2, 6 as 1+5, 7 as 2+5, and 8 as 1+2+5.)
// The smallest positive integer not present in the above list is 4.
//
// 1)
// {2, 1, 4}
//
// Returns: 8
//
// We can obtain each of the sums from 1 to 7, inclusive. The smallest impossible sum is 8.
//
// 2)
// {2, 1, 2, 7}
//
// Returns: 6
//
// The example given in the problem statement.
//
// 3)
// {94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1}
//
// Returns: 1092
//
//
//
// 4)
// {883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13}
//
// Returns: 56523
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
