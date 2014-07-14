#include <string>
using namespace std;

class PalindromizationDiv2 {
private:
	bool isPalindrome(string seq) {
		int i, j;
		for (i = 0, j = seq.size() - 1; i <= j; i++, j--)
			if (seq[i] != seq[j])
				return false;
		return true;
	}
public:
	int getMinimumCost(int X) {
		int i, j;

		for (i = 0; X + i <= 100000; i++)
			if (isPalindrome(to_string(X + i)))
				break;
		for (j = 0; X - j >= 0; j++)
			if (isPalindrome(to_string(X - j)))
				break;

		return i < j ? i : j;
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
		cout << "Testing PalindromizationDiv2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1405318116;
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
		PalindromizationDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X = 25;
				_expected = 3;
				_received = _obj.getMinimumCost(X); break;
			}
			case 1:
			{
				int X = 12321;
				_expected = 0;
				_received = _obj.getMinimumCost(X); break;
			}
			case 2:
			{
				int X = 40;
				_expected = 4;
				_received = _obj.getMinimumCost(X); break;
			}
			case 3:
			{
				int X = 2011;
				_expected = 9;
				_received = _obj.getMinimumCost(X); break;
			}
			case 4:
			{
				int X = 0;
				_expected = 0;
				_received = _obj.getMinimumCost(X); break;
			}
			/*case 5:
			{
				int X = ;
				_expected = ;
				_received = _obj.getMinimumCost(X); break;
			}*/
			/*case 6:
			{
				int X = ;
				_expected = ;
				_received = _obj.getMinimumCost(X); break;
			}*/
			/*case 7:
			{
				int X = ;
				_expected = ;
				_received = _obj.getMinimumCost(X); break;
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
