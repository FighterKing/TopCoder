#include <cstdlib>
using namespace std;

class MinimalDifference {
private:
	int digitSum(int x) {
		int ret = 0;
		do {
			ret += x % 10;
			x = x / 10;
		} while (x != 0);
		return ret;
	}
public:
	int findNumber(int A, int B, int C) {
		int dC = digitSum(C);
		int ret = A; int dRet = abs(digitSum(A) - dC);
		for (int i = A + 1; i <= B; i++) {
			int tmp = abs(digitSum(i) - dC);
			if (tmp < dRet) {
				dRet = tmp;
				ret = i;
			}
		}
		return ret;
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing MinimalDifference (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1405760953;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MinimalDifference _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 1;
				int B = 9;
				int C = 10;
				_expected = 1;
				_received = _obj.findNumber(A, B, C); break;
			}
			case 1:
			{
				int A = 11;
				int B = 20;
				int C = 20;
				_expected = 11;
				_received = _obj.findNumber(A, B, C); break;
			}
			case 2:
			{
				int A = 1;
				int B = 1;
				int C = 999;
				_expected = 1;
				_received = _obj.findNumber(A, B, C); break;
			}
			case 3:
			{
				int A = 100;
				int B = 1000;
				int C = 99;
				_expected = 189;
				_received = _obj.findNumber(A, B, C); break;
			}
			case 4:
			{
				int A = 1987;
				int B = 9123;
				int C = 1;
				_expected = 2000;
				_received = _obj.findNumber(A, B, C); break;
			}
			/*case 5:
			{
				int A = ;
				int B = ;
				int C = ;
				_expected = ;
				_received = _obj.findNumber(A, B, C); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				int C = ;
				_expected = ;
				_received = _obj.findNumber(A, B, C); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				int C = ;
				_expected = ;
				_received = _obj.findNumber(A, B, C); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
