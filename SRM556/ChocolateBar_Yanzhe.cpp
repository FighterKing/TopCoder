#include <string>
#include <vector>
using namespace std;

class ChocolateBar {
public:
	int maxLength(string letters) {
		int ret = 0;
        vector<int> last(256, -1);
        int cur_len = 0;
        for (int i = 0; i < letters.size(); i++) {
            int cur = letters[i];
            cur_len = min(cur_len + 1,i - last[cur]);
            last[cur] = i;
            ret = max(cur_len, ret);
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
		cout << "Testing ChocolateBar (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1405043598;
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
		ChocolateBar _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string letters = "srm";
				_expected = 3;
				_received = _obj.maxLength(letters); break;
			}
			case 1:
			{
				string letters = "dengklek";
				_expected = 6;
				_received = _obj.maxLength(letters); break;
			}
			case 2:
			{
				string letters = "haha";
				_expected = 2;
				_received = _obj.maxLength(letters); break;
			}
			case 3:
			{
				string letters = "www";
				_expected = 1;
				_received = _obj.maxLength(letters); break;
			}
			case 4:
			{
				string letters = "thisisansrmbeforetopcoderopenfinals";
				_expected = 9;
				_received = _obj.maxLength(letters); break;
			}
			/*case 5:
			{
				string letters = ;
				_expected = ;
				_received = _obj.maxLength(letters); break;
			}*/
			/*case 6:
			{
				string letters = ;
				_expected = ;
				_received = _obj.maxLength(letters); break;
			}*/
			/*case 7:
			{
				string letters = ;
				_expected = ;
				_received = _obj.maxLength(letters); break;
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
