#include <vector>
using namespace std;

class ShoutterDiv2 {
public:
	int count(vector <int> s, vector <int> t) {
		int ret = 0;
		int n = s.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				// (s[i], t[i]) v.s. (s[j], t[j])
				if ((s[j] <= s[i] && s[i] <= t[j]) ||
					(s[j] <= t[i] && t[i] <= t[j]) ||
					(s[i] < s[j] && t[j] < t[i]))
					ret++;
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
		cout << "Testing ShoutterDiv2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404632102;
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
		ShoutterDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int s[] = {1, 2, 4};
				int t[] = {3, 4, 6};
				_expected = 2;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 1:
			{
				int s[] = {0};
				int t[] = {100};
				_expected = 0;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 2:
			{
				int s[] = {0,0,0};
				int t[] = {1,1,1};
				_expected = 3;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 3:
			{
				int s[] = {9,26,8,35,3,58,91,24,10,26,22,18,15,12,15,27,15,60,76,19,12,16,37,35,25,4,22,47,65,3,2,23,26,33,7,11,34,74,67,32,15,45,20,53,60,25,74,13,44,51};
				int t[] = {26,62,80,80,52,83,100,71,20,73,23,32,80,37,34,55,51,86,97,89,17,81,74,94,79,85,77,97,87,8,70,46,58,70,97,35,80,76,82,80,19,56,65,62,80,49,79,28,75,78};
				_expected = 830;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			/*case 4:
			{
				int s[] = ;
				int t[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int s[] = ;
				int t[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int s[] = ;
				int t[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
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
