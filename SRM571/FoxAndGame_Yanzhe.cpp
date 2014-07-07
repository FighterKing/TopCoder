#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class FoxAndGame {
public:
	int countStars(vector <string> result) {
		int ret = 0;
		for (auto r : result)
			ret += count(r.begin(), r.end(), 'o');
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
		cout << "Testing FoxAndGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404743018;
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
		FoxAndGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string result[] = {"ooo",
				                   "ooo"};
				_expected = 6;
				_received = _obj.countStars(vector <string>(result, result+sizeof(result)/sizeof(string))); break;
			}
			case 1:
			{
				string result[] = {"ooo",
				                   "oo-",
				                   "o--"};
				_expected = 6;
				_received = _obj.countStars(vector <string>(result, result+sizeof(result)/sizeof(string))); break;
			}
			case 2:
			{
				string result[] = {"ooo",
				                   "---",
				                   "oo-",
				                   "---",
				                   "o--"};
				_expected = 6;
				_received = _obj.countStars(vector <string>(result, result+sizeof(result)/sizeof(string))); break;
			}
			case 3:
			{
				string result[] = {"o--",
				                   "o--",
				                   "o--",
				                   "ooo",
				                   "---"};
				_expected = 6;
				_received = _obj.countStars(vector <string>(result, result+sizeof(result)/sizeof(string))); break;
			}
			case 4:
			{
				string result[] = {"---",
				                   "o--",
				                   "oo-",
				                   "ooo",
				                   "ooo",
				                   "oo-",
				                   "o--",
				                   "---"};
				_expected = 12;
				_received = _obj.countStars(vector <string>(result, result+sizeof(result)/sizeof(string))); break;
			}
			case 5:
			{
				string result[] = {"---",
				                   "---",
				                   "---",
				                   "---",
				                   "---",
				                   "---"};
				_expected = 0;
				_received = _obj.countStars(vector <string>(result, result+sizeof(result)/sizeof(string))); break;
			}
			case 6:
			{
				string result[] = {"oo-"};
				_expected = 2;
				_received = _obj.countStars(vector <string>(result, result+sizeof(result)/sizeof(string))); break;
			}
			/*case 7:
			{
				string result[] = ;
				_expected = ;
				_received = _obj.countStars(vector <string>(result, result+sizeof(result)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string result[] = ;
				_expected = ;
				_received = _obj.countStars(vector <string>(result, result+sizeof(result)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string result[] = ;
				_expected = ;
				_received = _obj.countStars(vector <string>(result, result+sizeof(result)/sizeof(string))); break;
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
