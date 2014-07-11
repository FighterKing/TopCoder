#include <unordered_set>
using namespace std;

class TheBrickTowerEasyDivTwo {
public:
	int find(int redCount, int redHeight, int blueCount, int blueHeight) {
		unordered_set<int> ret;
		int h, redLeft, blueLeft;

		h = 0; redLeft = redCount; blueLeft = blueCount;
		while (redLeft > 0 && blueLeft > 0) {
			h += redHeight; ret.insert(h); redLeft--;
			h += blueHeight; ret.insert(h); blueLeft--;
		}
		if (redLeft > 0) ret.insert(h + redHeight);

		h = 0; redLeft = redCount; blueLeft = blueCount;
		while (blueLeft > 0 && redLeft > 0) {
			h += blueHeight; ret.insert(h); blueLeft--;
			h += redHeight; ret.insert(h); redLeft--;
		}
		if (blueLeft > 0) ret.insert(h + blueHeight);

		return ret.size();
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
		cout << "Testing TheBrickTowerEasyDivTwo (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1405064213;
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
		TheBrickTowerEasyDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int redCount = 1;
				int redHeight = 2;
				int blueCount = 3;
				int blueHeight = 4;
				_expected = 4;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}
			case 1:
			{
				int redCount = 4;
				int redHeight = 4;
				int blueCount = 4;
				int blueHeight = 7;
				_expected = 12;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}
			case 2:
			{
				int redCount = 7;
				int redHeight = 7;
				int blueCount = 4;
				int blueHeight = 4;
				_expected = 13;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}
			case 3:
			{
				int redCount = 47;
				int redHeight = 47;
				int blueCount = 47;
				int blueHeight = 47;
				_expected = 94;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}
			/*case 4:
			{
				int redCount = ;
				int redHeight = ;
				int blueCount = ;
				int blueHeight = ;
				_expected = ;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}*/
			/*case 5:
			{
				int redCount = ;
				int redHeight = ;
				int blueCount = ;
				int blueHeight = ;
				_expected = ;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}*/
			/*case 6:
			{
				int redCount = ;
				int redHeight = ;
				int blueCount = ;
				int blueHeight = ;
				_expected = ;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
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
