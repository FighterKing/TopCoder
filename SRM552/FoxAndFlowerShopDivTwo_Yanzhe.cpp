#include <vector>
#include <string>
#include <iostream>
using namespace std;

class FoxAndFlowerShopDivTwo {
public:
	int theMaxFlowers(vector <string> flowers, int r, int c) {
		int ret = 0;
		int cur = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < flowers[0].size(); j++)
				cur += (int) (flowers[i][j] == 'F');
		if (cur > ret) ret = cur;

		cur = 0;
		for (int i = r + 1; i < flowers.size(); i++)
			for (int j = 0; j < flowers[0].size(); j++)
				cur += (int) (flowers[i][j] == 'F');
		if (cur > ret) ret = cur;

		cur = 0;
		for (int i = 0; i < flowers.size(); i++)
			for (int j = 0; j < c; j++)
				cur += (int) (flowers[i][j] == 'F');
		if (cur > ret) ret = cur;

		cur = 0;
		for (int i = 0; i < flowers.size(); i++)
			for (int j = c + 1; j < flowers[0].size(); j++)
				cur += (int) (flowers[i][j] == 'F');
		if (cur > ret) ret = cur;

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
		cout << "Testing FoxAndFlowerShopDivTwo (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1405065639;
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
		FoxAndFlowerShopDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string flowers[] = {"F.F",
				                    ".F.",
				                    ".F."};
				int r = 1;
				int c = 1;
				_expected = 2;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), r, c); break;
			}
			case 1:
			{
				string flowers[] = {"F..",
				                    "...",
				                    "..."};
				int r = 0;
				int c = 0;
				_expected = 0;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), r, c); break;
			}
			case 2:
			{
				string flowers[] = {".FF.F.F",
				                    "FF...F.",
				                    "..FF.FF"};
				int r = 1;
				int c = 2;
				_expected = 6;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), r, c); break;
			}
			case 3:
			{
				string flowers[] = {"F",
				                    ".",
				                    "F",
				                    "F",
				                    "F",
				                    ".",
				                    "F",
				                    "F"};
				int r = 4;
				int c = 0;
				_expected = 3;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), r, c); break;
			}
			case 4:
			{
				string flowers[] = {".FFF..F...",
				                    "FFF...FF.F",
				                    "..F.F.F.FF",
				                    "FF..F.FFF.",
				                    "..FFFFF...",
				                    "F....FF...",
				                    ".FF.FF..FF",
				                    "..F.F.FFF.",
				                    ".FF..F.F.F",
				                    "F.FFF.FF.F"};
				int r = 4;
				int c = 3;
				_expected = 32;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), r, c); break;
			}
			/*case 5:
			{
				string flowers[] = ;
				int r = ;
				int c = ;
				_expected = ;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), r, c); break;
			}*/
			/*case 6:
			{
				string flowers[] = ;
				int r = ;
				int c = ;
				_expected = ;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), r, c); break;
			}*/
			/*case 7:
			{
				string flowers[] = ;
				int r = ;
				int c = ;
				_expected = ;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), r, c); break;
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
