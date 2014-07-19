#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

class TimeTravellingCellar {
public:
	int determineProfit(vector <int> profit, vector <int> decay) {
		vector<int> sorted_profit(profit.begin(), profit.end());
		vector<int> sorted_decay(decay.begin(), decay.end());
		sort(sorted_profit.begin(), sorted_profit.end(), greater<int>());
		sort(sorted_decay.begin(), sorted_decay.end());

		int profit_1st = 0;
		for (; profit[profit_1st] != sorted_profit[0]; profit_1st++);

		int decay_1st = 0;
		for (; decay[decay_1st] != sorted_decay[0]; decay_1st++);

		if (profit_1st != decay_1st)
			return sorted_profit[0] - sorted_decay[0];
		else
			return max(sorted_profit[0] - sorted_decay[1], sorted_profit[1] - sorted_decay[0]);
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
		cout << "Testing TimeTravellingCellar (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1405735025;
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
		TimeTravellingCellar _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int profit[] = {1,2,3};
				int decay[] = {3,1,2};
				_expected = 2;
				_received = _obj.determineProfit(vector <int>(profit, profit+sizeof(profit)/sizeof(int)), vector <int>(decay, decay+sizeof(decay)/sizeof(int))); break;
			}
			case 1:
			{
				int profit[] = {3,2};
				int decay[] = {1,2};
				_expected = 1;
				_received = _obj.determineProfit(vector <int>(profit, profit+sizeof(profit)/sizeof(int)), vector <int>(decay, decay+sizeof(decay)/sizeof(int))); break;
			}
			case 2:
			{
				int profit[] = {3,3,3};
				int decay[] = {1,1,1};
				_expected = 2;
				_received = _obj.determineProfit(vector <int>(profit, profit+sizeof(profit)/sizeof(int)), vector <int>(decay, decay+sizeof(decay)/sizeof(int))); break;
			}
			case 3:
			{
				int profit[] = {1000,500,250,125};
				int decay[] = {64,32,16,8};
				_expected = 992;
				_received = _obj.determineProfit(vector <int>(profit, profit+sizeof(profit)/sizeof(int)), vector <int>(decay, decay+sizeof(decay)/sizeof(int))); break;
			}
			/*case 4:
			{
				int profit[] = ;
				int decay[] = ;
				_expected = ;
				_received = _obj.determineProfit(vector <int>(profit, profit+sizeof(profit)/sizeof(int)), vector <int>(decay, decay+sizeof(decay)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int profit[] = ;
				int decay[] = ;
				_expected = ;
				_received = _obj.determineProfit(vector <int>(profit, profit+sizeof(profit)/sizeof(int)), vector <int>(decay, decay+sizeof(decay)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int profit[] = ;
				int decay[] = ;
				_expected = ;
				_received = _obj.determineProfit(vector <int>(profit, profit+sizeof(profit)/sizeof(int)), vector <int>(decay, decay+sizeof(decay)/sizeof(int))); break;
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
