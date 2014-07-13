#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

class MarbleDecoration {
public:
	int maxLength(int R, int G, int B) {
		vector<int> colors {R, G, B};
		sort(colors.begin(), colors.end(), greater<int>());
		if (colors[0] == colors[1])
			return colors[0] * 2;
		else
			return colors[1] * 2 + 1;
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
		cout << "Testing MarbleDecoration (256.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1405218244;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 256.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MarbleDecoration _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int R = 0;
				int G = 0;
				int B = 0;
				_expected = 0;
				_received = _obj.maxLength(R, G, B); break;
			}
			case 1:
			{
				int R = 3;
				int G = 0;
				int B = 0;
				_expected = 1;
				_received = _obj.maxLength(R, G, B); break;
			}
			case 2:
			{
				int R = 5;
				int G = 1;
				int B = 2;
				_expected = 5;
				_received = _obj.maxLength(R, G, B); break;
			}
			case 3:
			{
				int R = 7;
				int G = 7;
				int B = 4;
				_expected = 14;
				_received = _obj.maxLength(R, G, B); break;
			}
			case 4:
			{
				int R = 2;
				int G = 3;
				int B = 5;
				_expected = 7;
				_received = _obj.maxLength(R, G, B); break;
			}
			case 5:
			{
				int R = 13;
				int G = 13;
				int B = 13;
				_expected = 26;
				_received = _obj.maxLength(R, G, B); break;
			}
			/*case 6:
			{
				int R = ;
				int G = ;
				int B = ;
				_expected = ;
				_received = _obj.maxLength(R, G, B); break;
			}*/
			/*case 7:
			{
				int R = ;
				int G = ;
				int B = ;
				_expected = ;
				_received = _obj.maxLength(R, G, B); break;
			}*/
			/*case 8:
			{
				int R = ;
				int G = ;
				int B = ;
				_expected = ;
				_received = _obj.maxLength(R, G, B); break;
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
