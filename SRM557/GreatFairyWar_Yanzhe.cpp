#include <vector>
using namespace std;

class GreatFairyWar {
public:
	int minHP(vector <int> dps, vector <int> hp) {
		int cdps = 0;
		int ret = 0;
		for (auto d : dps)
			cdps += d;
		for (int i = 0; i < dps.size(); i++) {
			ret += hp[i] * cdps;
			cdps -= dps[i];
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
		cout << "Testing GreatFairyWar (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404893847;
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
		GreatFairyWar _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dps[] = {1,2};
				int hp[] = {3,4};
				_expected = 17;
				_received = _obj.minHP(vector <int>(dps, dps+sizeof(dps)/sizeof(int)), vector <int>(hp, hp+sizeof(hp)/sizeof(int))); break;
			}
			case 1:
			{
				int dps[] = {1,1,1,1,1,1,1,1,1,1};
				int hp[] = {1,1,1,1,1,1,1,1,1,1};
				_expected = 55;
				_received = _obj.minHP(vector <int>(dps, dps+sizeof(dps)/sizeof(int)), vector <int>(hp, hp+sizeof(hp)/sizeof(int))); break;
			}
			case 2:
			{
				int dps[] = {20,12,10,10,23,10};
				int hp[] = {5,7,7,5,7,7};
				_expected = 1767;
				_received = _obj.minHP(vector <int>(dps, dps+sizeof(dps)/sizeof(int)), vector <int>(hp, hp+sizeof(hp)/sizeof(int))); break;
			}
			case 3:
			{
				int dps[] = {5,7,7,5,7,7};
				int hp[] = {20,12,10,10,23,10};
				_expected = 1998;
				_received = _obj.minHP(vector <int>(dps, dps+sizeof(dps)/sizeof(int)), vector <int>(hp, hp+sizeof(hp)/sizeof(int))); break;
			}
			case 4:
			{
				int dps[] = {30,2,7,4,7,8,21,14,19,12};
				int hp[] = {2,27,18,19,14,8,25,13,21,30};
				_expected = 11029;
				_received = _obj.minHP(vector <int>(dps, dps+sizeof(dps)/sizeof(int)), vector <int>(hp, hp+sizeof(hp)/sizeof(int))); break;
			}
			case 5:
			{
				int dps[] = {1};
				int hp[] = {1};
				_expected = 1;
				_received = _obj.minHP(vector <int>(dps, dps+sizeof(dps)/sizeof(int)), vector <int>(hp, hp+sizeof(hp)/sizeof(int))); break;
			}
			/*case 6:
			{
				int dps[] = ;
				int hp[] = ;
				_expected = ;
				_received = _obj.minHP(vector <int>(dps, dps+sizeof(dps)/sizeof(int)), vector <int>(hp, hp+sizeof(hp)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int dps[] = ;
				int hp[] = ;
				_expected = ;
				_received = _obj.minHP(vector <int>(dps, dps+sizeof(dps)/sizeof(int)), vector <int>(hp, hp+sizeof(hp)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int dps[] = ;
				int hp[] = ;
				_expected = ;
				_received = _obj.minHP(vector <int>(dps, dps+sizeof(dps)/sizeof(int)), vector <int>(hp, hp+sizeof(hp)/sizeof(int))); break;
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
