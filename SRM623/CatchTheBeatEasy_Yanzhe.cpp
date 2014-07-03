#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

class CatchTheBeatEasy {
public:
	string ableToCatchAll(vector <int> x, vector <int> y) {
		multimap<int, int> m;
		for (int i = 0; i < x.size(); i++)
			m.insert(pair<int, int> (y[i], x[i]));
		map<int, int>::iterator it;
		int c_time, c_pos;
		bool works = true;
		for (it = m.begin(), c_time = 0, c_pos = 0; it != m.end(); it++) {
			if (c_time + abs(c_pos - it->second) > it->first) {
				works = false;
				break;
			}
			c_time = it->first;
			c_pos = it->second;
		}
		if (works)
			return "Able to catch";
		else
			return "Not able to catch";
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
		cout << "Testing CatchTheBeatEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404228791;
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
		CatchTheBeatEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {-1, 1, 0};
				int y[] = {1, 3, 4};
				_expected = "Able to catch";
				_received = _obj.ableToCatchAll(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {-3};
				int y[] = {2};
				_expected = "Not able to catch";
				_received = _obj.ableToCatchAll(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {-1, 1, 0};
				int y[] = {1, 2, 4};
				_expected = "Not able to catch";
				_received = _obj.ableToCatchAll(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {0, -1, 1};
				int y[] = {9, 1, 3};
				_expected = "Able to catch";
				_received = _obj.ableToCatchAll(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {70,-108,52,-70,84,-29,66,-33};
				int y[] = {141,299,402,280,28,363,427,232};
				_expected = "Not able to catch";
				_received = _obj.ableToCatchAll(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {-175,-28,-207,-29,-43,-183,-175,-112,-183,-31,-25,-66,-114,-116,-66};
				int y[] = {320,107,379,72,126,445,318,255,445,62,52,184,247,245,185};
				_expected = "Able to catch";
				_received = _obj.ableToCatchAll(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 6:
			{
				int x[] = {0,0,0,0};
				int y[] = {0,0,0,0};
				_expected = "Able to catch";
				_received = _obj.ableToCatchAll(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 7:
			{
				int x[] = {-7,16,-41,2,22,-28,45,27,5,-67,21,-85,-61,-20,-7,-90,-39,-60,-51,-33,-81,23,-41,18,11,4,-44,0,-19,-12,-40};
				int y[] = {344,265,187,217,271,356,275,306,54,450,101,481,489,362,80,456,156,412,390,388,541,27,174,241,317,121,193,340,213,138,421};
				_expected = "Not able to catch";
				_received = _obj.ableToCatchAll(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 8:
			{
				int x[] = {1,2};
				int y[] = {8,8};
				_expected = "Not able to catch";
				_received = _obj.ableToCatchAll(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 9:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.ableToCatchAll(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
