#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SquareOfDigits {
public:
	int getMax(vector <string> data) {
		int width = min(data.size(), data[0].size());
		for (int d = width; d > 1; d--) {
			for (int i = 0; i + d <= data[0].size(); i++) {
				for (int j = 0; j + d <= data.size(); j++) {
					if (data[j][i] == data[j][i+d-1] &&
						data[j][i] == data[j+d-1][i] &&
						data[j][i] == data[j+d-1][i+d-1])
						return d * d;
				}
			}
		}
		return 1;
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
		cout << "Testing SquareOfDigits (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1405866173;
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
		SquareOfDigits _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string data[] = {"12",
				                 "34"};
				_expected = 1;
				_received = _obj.getMax(vector <string>(data, data+sizeof(data)/sizeof(string))); break;
			}
			case 1:
			{
				string data[] = {"1255",
				                 "3455"};
				_expected = 4;
				_received = _obj.getMax(vector <string>(data, data+sizeof(data)/sizeof(string))); break;
			}
			case 2:
			{
				string data[] = {"42101",
				                 "22100",
				                 "22101"};
				_expected = 9;
				_received = _obj.getMax(vector <string>(data, data+sizeof(data)/sizeof(string))); break;
			}
			case 3:
			{
				string data[] = {"1234567890"};
				_expected = 1;
				_received = _obj.getMax(vector <string>(data, data+sizeof(data)/sizeof(string))); break;
			}
			case 4:
			{
				string data[] = {"9785409507",
				                 "2055103694",
				                 "0861396761",
				                 "3073207669",
				                 "1233049493",
				                 "2300248968",
				                 "9769239548",
				                 "7984130001",
				                 "1670020095",
				                 "8894239889",
				                 "4053971072"};
				_expected = 49;
				_received = _obj.getMax(vector <string>(data, data+sizeof(data)/sizeof(string))); break;
			}
			/*case 5:
			{
				string data[] = ;
				_expected = ;
				_received = _obj.getMax(vector <string>(data, data+sizeof(data)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string data[] = ;
				_expected = ;
				_received = _obj.getMax(vector <string>(data, data+sizeof(data)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string data[] = ;
				_expected = ;
				_received = _obj.getMax(vector <string>(data, data+sizeof(data)/sizeof(string))); break;
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
