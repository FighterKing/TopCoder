#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class SwappingDigits {
public:
	string minNumber(string num) {
		vector<int> digits;
		for (auto d : num)
			digits.push_back(d - '0');
		sort(digits.begin(), digits.end());
		if (digits[0] == 0) {
			int i = 0;
			while (i < digits.size() && digits[i] == 0)
				i++;
			digits[0] = digits[i];
			digits[i] = 0;
		}
		int p;
		for (p = 0; p < digits.size(); p++) {
			if (digits[p] + '0' != num[p])
				break;
		}
		if (p == digits.size()) return num;

		int k;
		for (k = num.size() - 1; k >= 0; k--) {
			if (digits[p] + '0' == num[k])
				break;
		}
		char t = num[p]; num[p] = num[k]; num[k] = t;
		return num;
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
		cout << "Testing SwappingDigits (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404545615;
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
		SwappingDigits _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string num = "596";
				_expected = "569";
				_received = _obj.minNumber(num); break;
			}
			case 1:
			{
				string num = "93561";
				_expected = "13569";
				_received = _obj.minNumber(num); break;
			}
			case 2:
			{
				string num = "5491727514";
				_expected = "1491727554";
				_received = _obj.minNumber(num); break;
			}
			case 3:
			{
				string num = "10234";
				_expected = "10234";
				_received = _obj.minNumber(num); break;
			}
			case 4:
			{
				string num = "93218910471211292416";
				_expected = "13218910471211292496";
				_received = _obj.minNumber(num); break;
			}
			/*case 5:
			{
				string num = ;
				_expected = ;
				_received = _obj.minNumber(num); break;
			}*/
			/*case 6:
			{
				string num = ;
				_expected = ;
				_received = _obj.minNumber(num); break;
			}*/
			/*case 7:
			{
				string num = ;
				_expected = ;
				_received = _obj.minNumber(num); break;
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
