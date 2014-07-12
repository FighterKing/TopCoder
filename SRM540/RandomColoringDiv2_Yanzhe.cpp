#include <vector>
using namespace std;

class RandomColoringDiv2 {
public:
	int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {

		vector<int> maxs {maxR, maxG, maxB};
		vector<int> starts {startR, startG, startB};

		int base = 1, off = 1;
		for (int i = 0; i < 3; i++) {
			int lo = starts[i] - d2 > 0 ? starts[i] - d2 : 0;
			int hi = starts[i] + d2 < maxs[i] ? starts[i] + d2 : maxs[i] - 1;
			base *= (hi - lo + 1);
			if (d1 > 0) {
				lo = starts[i] - d1 + 1 > 0 ? starts[i] - d1 + 1 : 0;
				hi = starts[i] + d1 - 1 < maxs[i] ? starts[i] + d1 - 1 : maxs[i] - 1;
				off *= (hi - lo + 1);
			} else
				off = 0;
		}

		return base - off;
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
		cout << "Testing RandomColoringDiv2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1405143703;
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
		RandomColoringDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int maxR = 5;
				int maxG = 1;
				int maxB = 1;
				int startR = 2;
				int startG = 0;
				int startB = 0;
				int d1 = 0;
				int d2 = 1;
				_expected = 3;
				_received = _obj.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 1:
			{
				int maxR = 4;
				int maxG = 2;
				int maxB = 2;
				int startR = 0;
				int startG = 0;
				int startB = 0;
				int d1 = 3;
				int d2 = 3;
				_expected = 4;
				_received = _obj.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 2:
			{
				int maxR = 4;
				int maxG = 2;
				int maxB = 2;
				int startR = 0;
				int startG = 0;
				int startB = 0;
				int d1 = 5;
				int d2 = 5;
				_expected = 0;
				_received = _obj.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 3:
			{
				int maxR = 6;
				int maxG = 9;
				int maxB = 10;
				int startR = 1;
				int startG = 2;
				int startB = 3;
				int d1 = 0;
				int d2 = 10;
				_expected = 540;
				_received = _obj.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 4:
			{
				int maxR = 6;
				int maxG = 9;
				int maxB = 10;
				int startR = 1;
				int startG = 2;
				int startB = 3;
				int d1 = 4;
				int d2 = 10;
				_expected = 330;
				_received = _obj.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 5:
			{
				int maxR = 49;
				int maxG = 59;
				int maxB = 53;
				int startR = 12;
				int startG = 23;
				int startB = 13;
				int d1 = 11;
				int d2 = 22;
				_expected = 47439;
				_received = _obj.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			/*case 6:
			{
				int maxR = ;
				int maxG = ;
				int maxB = ;
				int startR = ;
				int startG = ;
				int startB = ;
				int d1 = ;
				int d2 = ;
				_expected = ;
				_received = _obj.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}*/
			/*case 7:
			{
				int maxR = ;
				int maxG = ;
				int maxB = ;
				int startR = ;
				int startG = ;
				int startB = ;
				int d1 = ;
				int d2 = ;
				_expected = ;
				_received = _obj.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}*/
			/*case 8:
			{
				int maxR = ;
				int maxG = ;
				int maxB = ;
				int startR = ;
				int startG = ;
				int startB = ;
				int d1 = ;
				int d2 = ;
				_expected = ;
				_received = _obj.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
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
