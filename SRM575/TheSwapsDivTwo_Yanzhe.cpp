#include <vector>
using namespace std;

class TheSwapsDivTwo {
public:
	int find(vector <int> sequence) {
		int ret = 0;
		bool dup = false;
		for (int i = 0; i < sequence.size(); i++) {
			for (int j = i + 1; j < sequence.size(); j++) {
				if (sequence[i] != sequence[j]) ret++;
				else if (!dup) {
					ret++;
					dup = true;
				}
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
		cout << "Testing TheSwapsDivTwo (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404731783;
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
		TheSwapsDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sequence[] = {4, 7, 4};
				_expected = 3;
				_received = _obj.find(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
			}
			case 1:
			{
				int sequence[] = {1, 47};
				_expected = 1;
				_received = _obj.find(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
			}
			case 2:
			{
				int sequence[] = {9, 9, 9, 9};
				_expected = 1;
				_received = _obj.find(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
			}
			case 3:
			{
				int sequence[] = {22, 16, 36, 35, 14, 9, 33, 6, 28, 12, 18, 14, 47, 46, 29, 22, 14, 17, 4, 15, 28, 6, 39, 24, 47, 37};
				_expected = 319;
				_received = _obj.find(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
			}
			/*case 4:
			{
				int sequence[] = ;
				_expected = ;
				_received = _obj.find(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int sequence[] = ;
				_expected = ;
				_received = _obj.find(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int sequence[] = ;
				_expected = ;
				_received = _obj.find(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
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
