using namespace std;

class FibonacciDiv2 {
public:
	int find(int N) {
		if (N == 1) return 0;
		int a = 0;
		int b = 1;
		int c = a + b;
		while (N < b || N > c) {
			int t = b + c;
			a = b; b = c; c = t;
		}
		return (N - b) <= (c - N) ? (N - b) : (c - N);
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
		cout << "Testing FibonacciDiv2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404140636;
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
		FibonacciDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1;
				_expected = 0;
				_received = _obj.find(N); break;
			}
			case 1:
			{
				int N = 13;
				_expected = 0;
				_received = _obj.find(N); break;
			}
			case 2:
			{
				int N = 15;
				_expected = 2;
				_received = _obj.find(N); break;
			}
			case 3:
			{
				int N = 19;
				_expected = 2;
				_received = _obj.find(N); break;
			}
			case 4:
			{
				int N = 1000000;
				_expected = 167960;
				_received = _obj.find(N); break;
			}
			/*case 5:
			{
				int N = ;
				_expected = ;
				_received = _obj.find(N); break;
			}*/
			/*case 6:
			{
				int N = ;
				_expected = ;
				_received = _obj.find(N); break;
			}*/
			/*case 7:
			{
				int N = ;
				_expected = ;
				_received = _obj.find(N); break;
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
