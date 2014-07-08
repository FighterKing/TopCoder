#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

class CucumberMarket {
public:
	string check(vector <int> price, int budget, int k) {
		sort(price.begin(), price.end(), greater<int>());
		int sum = 0;
		for (int i = 0; i < k; i++)
			sum += price[i];
		return (sum <= budget) ? "YES" : "NO";
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
		cout << "Testing CucumberMarket (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404826114;
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
		CucumberMarket _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int price[] = {1000,1,10,100};
				int budget = 1110;
				int k = 3;
				_expected = "YES";
				_received = _obj.check(vector <int>(price, price+sizeof(price)/sizeof(int)), budget, k); break;
			}
			case 1:
			{
				int price[] = {1000,1,10,100};
				int budget = 1109;
				int k = 3;
				_expected = "NO";
				_received = _obj.check(vector <int>(price, price+sizeof(price)/sizeof(int)), budget, k); break;
			}
			case 2:
			{
				int price[] = {33,4};
				int budget = 33;
				int k = 1;
				_expected = "YES";
				_received = _obj.check(vector <int>(price, price+sizeof(price)/sizeof(int)), budget, k); break;
			}
			case 3:
			{
				int price[] = {1,1,1,1,1,1};
				int budget = 2;
				int k = 4;
				_expected = "NO";
				_received = _obj.check(vector <int>(price, price+sizeof(price)/sizeof(int)), budget, k); break;
			}
			case 4:
			{
				int price[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
				int budget = 10000;
				int k = 9;
				_expected = "YES";
				_received = _obj.check(vector <int>(price, price+sizeof(price)/sizeof(int)), budget, k); break;
			}
			/*case 5:
			{
				int price[] = ;
				int budget = ;
				int k = ;
				_expected = ;
				_received = _obj.check(vector <int>(price, price+sizeof(price)/sizeof(int)), budget, k); break;
			}*/
			/*case 6:
			{
				int price[] = ;
				int budget = ;
				int k = ;
				_expected = ;
				_received = _obj.check(vector <int>(price, price+sizeof(price)/sizeof(int)), budget, k); break;
			}*/
			/*case 7:
			{
				int price[] = ;
				int budget = ;
				int k = ;
				_expected = ;
				_received = _obj.check(vector <int>(price, price+sizeof(price)/sizeof(int)), budget, k); break;
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
