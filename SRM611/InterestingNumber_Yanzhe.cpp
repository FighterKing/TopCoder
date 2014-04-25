#include <string>
#include <algorithm>
using namespace std;

class InterestingNumber {
public:
	string isInteresting(string x) {
		string shadow = x;
        for (int i = 0; i < shadow.size(); i++) {
            if (shadow[i] != 'x') {
               if (count(shadow.begin(), shadow.end(), shadow[i]) != 2)
                   return "Not interesting";
                string::size_type pair = shadow.rfind(shadow[i]);
               if (pair - i - 1 != (shadow[i] - '0'))
                   return "Not interesting";
               else
                   shadow[pair] = 'x';
            }
        }
        return "Interesting";
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
		cout << "Testing InterestingNumber (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398399345;
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
		InterestingNumber _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string x = "2002";
				_expected = "Interesting";
				_received = _obj.isInteresting(x); break;
			}
			case 1:
			{
				string x = "1001";
				_expected = "Not interesting";
				_received = _obj.isInteresting(x); break;
			}
			case 2:
			{
				string x = "41312432";
				_expected = "Interesting";
				_received = _obj.isInteresting(x); break;
			}
			case 3:
			{
				string x = "611";
				_expected = "Not interesting";
				_received = _obj.isInteresting(x); break;
			}
			case 4:
			{
				string x = "64200246";
				_expected = "Interesting";
				_received = _obj.isInteresting(x); break;
			}
			case 5:
			{
				string x = "631413164";
				_expected = "Not interesting";
				_received = _obj.isInteresting(x); break;
			}
			/*case 6:
			{
				string x = ;
				_expected = ;
				_received = _obj.isInteresting(x); break;
			}*/
			/*case 7:
			{
				string x = ;
				_expected = ;
				_received = _obj.isInteresting(x); break;
			}*/
			/*case 8:
			{
				string x = ;
				_expected = ;
				_received = _obj.isInteresting(x); break;
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
