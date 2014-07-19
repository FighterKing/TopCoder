#include <vector>
#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;

class AverageAverage {
public:
	double average(vector <int> numList) {
		int n = numList.size();
		vector<int> facts {1};
		int acc = 1;
		for (int i = 1; i <= n; i++) {
			acc *= i;
			facts.push_back(acc);
		}

		double f = 0;
		for (int i = 0; i < n; i++)
			f += facts[n-1] * 1.0 / (facts[i] * facts[n-i-1] * (i+1));

		int sum = accumulate(numList.begin(), numList.end(), 0);

		return f * sum / (pow(2, n) - 1);
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
		cout << "Testing AverageAverage (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1405741376;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AverageAverage _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numList[] = {1,2,3};
				_expected = 2.0;
				_received = _obj.average(vector <int>(numList, numList+sizeof(numList)/sizeof(int))); break;
			}
			case 1:
			{
				int numList[] = {42};
				_expected = 42.0;
				_received = _obj.average(vector <int>(numList, numList+sizeof(numList)/sizeof(int))); break;
			}
			case 2:
			{
				int numList[] = {3,1,4,15,9};
				_expected = 6.4;
				_received = _obj.average(vector <int>(numList, numList+sizeof(numList)/sizeof(int))); break;
			}
			/*case 3:
			{
				int numList[] = ;
				_expected = ;
				_received = _obj.average(vector <int>(numList, numList+sizeof(numList)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int numList[] = ;
				_expected = ;
				_received = _obj.average(vector <int>(numList, numList+sizeof(numList)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int numList[] = ;
				_expected = ;
				_received = _obj.average(vector <int>(numList, numList+sizeof(numList)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
