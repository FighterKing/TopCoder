#include <string>
#include <unordered_set>
using namespace std;

class TopFox {
public:
	int possibleHandles(string familyName, string givenName) {
		int ret = 0;
		unordered_set<string> record;
		for (int i = 1; i <= familyName.size(); i++) {
			for (int j = 1; j <= givenName.size(); j++) {
				string handle = familyName.substr(0, i) + givenName.substr(0, j);
				if (record.find(handle) == record.end()) {
					record.insert(handle);
					ret++;
				}
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
		cout << "Testing TopFox (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404537751;
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
		TopFox _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string familyName = "ab";
				string givenName = "cd";
				_expected = 4;
				_received = _obj.possibleHandles(familyName, givenName); break;
			}
			case 1:
			{
				string familyName = "abb";
				string givenName = "bbc";
				_expected = 7;
				_received = _obj.possibleHandles(familyName, givenName); break;
			}
			case 2:
			{
				string familyName = "fox";
				string givenName = "ciel";
				_expected = 12;
				_received = _obj.possibleHandles(familyName, givenName); break;
			}
			case 3:
			{
				string familyName = "abbbb";
				string givenName = "bbbbbbbc";
				_expected = 16;
				_received = _obj.possibleHandles(familyName, givenName); break;
			}
			case 4:
			{
				string familyName = "abxy";
				string givenName = "xyxyxc";
				_expected = 21;
				_received = _obj.possibleHandles(familyName, givenName); break;
			}
			case 5:
			{
				string familyName = "ababababab";
				string givenName = "bababababa";
				_expected = 68;
				_received = _obj.possibleHandles(familyName, givenName); break;
			}
			/*case 6:
			{
				string familyName = ;
				string givenName = ;
				_expected = ;
				_received = _obj.possibleHandles(familyName, givenName); break;
			}*/
			/*case 7:
			{
				string familyName = ;
				string givenName = ;
				_expected = ;
				_received = _obj.possibleHandles(familyName, givenName); break;
			}*/
			/*case 8:
			{
				string familyName = ;
				string givenName = ;
				_expected = ;
				_received = _obj.possibleHandles(familyName, givenName); break;
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
