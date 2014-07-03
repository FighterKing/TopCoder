#include <vector>
using namespace std;

class SumOfPower {
public:
	int findSum(vector <int> array) {
		int size = array.size();
		int ret = 0;
		for (int i = 0; i < size; i++)
			ret += array[i] * (size - i) * (i + 1);
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
		cout << "Testing SumOfPower (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404392094;
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
		SumOfPower _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int array[] = {1,2};
				_expected = 6;
				_received = _obj.findSum(vector <int>(array, array+sizeof(array)/sizeof(int))); break;
			}
			case 1:
			{
				int array[] = {1,1,1};
				_expected = 10;
				_received = _obj.findSum(vector <int>(array, array+sizeof(array)/sizeof(int))); break;
			}
			case 2:
			{
				int array[] = {3,14,15,92,65};
				_expected = 1323;
				_received = _obj.findSum(vector <int>(array, array+sizeof(array)/sizeof(int))); break;
			}
			case 3:
			{
				int array[] = {1,2,3,4,5,6,7,8,9,10};
				_expected = 1210;
				_received = _obj.findSum(vector <int>(array, array+sizeof(array)/sizeof(int))); break;
			}
			/*case 4:
			{
				int array[] = ;
				_expected = ;
				_received = _obj.findSum(vector <int>(array, array+sizeof(array)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int array[] = ;
				_expected = ;
				_received = _obj.findSum(vector <int>(array, array+sizeof(array)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int array[] = ;
				_expected = ;
				_received = _obj.findSum(vector <int>(array, array+sizeof(array)/sizeof(int))); break;
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
