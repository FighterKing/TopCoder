#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class SlimeXSlimeRancher2 {
public:
	int train(vector <int> attributes) {
		vector<int>::iterator it;
		it = max_element(attributes.begin(), attributes.end());
		int ret = 0;
		for (auto d : attributes)
			ret += (*it - d);
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
		cout << "Testing SlimeXSlimeRancher2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1405319198;
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
		SlimeXSlimeRancher2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int attributes[] = {1,2,3};
				_expected = 3;
				_received = _obj.train(vector <int>(attributes, attributes+sizeof(attributes)/sizeof(int))); break;
			}
			case 1:
			{
				int attributes[] = {5,5};
				_expected = 0;
				_received = _obj.train(vector <int>(attributes, attributes+sizeof(attributes)/sizeof(int))); break;
			}
			case 2:
			{
				int attributes[] = {900,500,100};
				_expected = 1200;
				_received = _obj.train(vector <int>(attributes, attributes+sizeof(attributes)/sizeof(int))); break;
			}
			/*case 3:
			{
				int attributes[] = ;
				_expected = ;
				_received = _obj.train(vector <int>(attributes, attributes+sizeof(attributes)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int attributes[] = ;
				_expected = ;
				_received = _obj.train(vector <int>(attributes, attributes+sizeof(attributes)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int attributes[] = ;
				_expected = ;
				_received = _obj.train(vector <int>(attributes, attributes+sizeof(attributes)/sizeof(int))); break;
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
