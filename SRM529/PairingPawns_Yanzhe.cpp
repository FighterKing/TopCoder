#include <vector>
using namespace std;

class PairingPawns {
public:
	int savedPawnCount(vector <int> start) {
		for (int i = start.size() - 1; i >= 1; i--)
			start[i - 1] += start[i] / 2;
		return start[0];
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
		cout << "Testing PairingPawns (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1405217269;
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
		PairingPawns _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int start[] = {0,2};
				_expected = 1;
				_received = _obj.savedPawnCount(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}
			case 1:
			{
				int start[] = {10,3};
				_expected = 11;
				_received = _obj.savedPawnCount(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}
			case 2:
			{
				int start[] = {0,0,0,8};
				_expected = 1;
				_received = _obj.savedPawnCount(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}
			case 3:
			{
				int start[] = {0,1,1,2};
				_expected = 1;
				_received = _obj.savedPawnCount(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}
			case 4:
			{
				int start[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,123456};
				_expected = 0;
				_received = _obj.savedPawnCount(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}
			case 5:
			{
				int start[] = {1000,2000,3000,4000,5000,6000,7000,8000};
				_expected = 3921;
				_received = _obj.savedPawnCount(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}
			/*case 6:
			{
				int start[] = ;
				_expected = ;
				_received = _obj.savedPawnCount(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int start[] = ;
				_expected = ;
				_received = _obj.savedPawnCount(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int start[] = ;
				_expected = ;
				_received = _obj.savedPawnCount(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
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
