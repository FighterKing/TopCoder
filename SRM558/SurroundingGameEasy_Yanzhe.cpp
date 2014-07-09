#include <vector>
#include <string>
#include <iostream>
using namespace std;

class SurroundingGameEasy {
public:
	int score(vector <string> cost, vector <string> benefit, vector <string> stone) {
		int sumCost = 0;
		int sumBenefit = 0;
		for (int i = 0; i < stone.size(); i++) {
			for (int j = 0; j < stone[i].size(); j++) {
				if (stone[i][j] == 'o') {
					sumCost += cost[i][j] - '0';
					sumBenefit += benefit[i][j] - '0';
				} else {
					bool dominate = true;
					if (dominate && i - 1 >= 0 && stone[i-1][j] != 'o')
						dominate = false;
					if (dominate && i + 1 < stone.size() && stone[i+1][j] != 'o')
						dominate = false;
					if (dominate && j - 1 >= 0 && stone[i][j-1] != 'o')
						dominate = false;
					if (dominate && j + 1 < stone[i].size() && stone[i][j+1] != 'o')
						dominate = false;
					if (dominate)
						sumBenefit += benefit[i][j] - '0';
				}
			}
		}
		return sumBenefit - sumCost;
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
		cout << "Testing SurroundingGameEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404892295;
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
		SurroundingGameEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cost[] = {"21","12"};
				string benefit[] = {"21","12"};
				string stone[] = {".o","o."};
				_expected = 4;
				_received = _obj.score(vector <string>(cost, cost+sizeof(cost)/sizeof(string)), vector <string>(benefit, benefit+sizeof(benefit)/sizeof(string)), vector <string>(stone, stone+sizeof(stone)/sizeof(string))); break;
			}
			case 1:
			{
				string cost[] = {"99","99"};
				string benefit[] = {"11","11"};
				string stone[] = {".o","o."};
				_expected = -14;
				_received = _obj.score(vector <string>(cost, cost+sizeof(cost)/sizeof(string)), vector <string>(benefit, benefit+sizeof(benefit)/sizeof(string)), vector <string>(stone, stone+sizeof(stone)/sizeof(string))); break;
			}
			case 2:
			{
				string cost[] = {"888","888","888"};
				string benefit[] = {"000","090","000"};
				string stone[] = {"...",".o.","..."};
				_expected = 1;
				_received = _obj.score(vector <string>(cost, cost+sizeof(cost)/sizeof(string)), vector <string>(benefit, benefit+sizeof(benefit)/sizeof(string)), vector <string>(stone, stone+sizeof(stone)/sizeof(string))); break;
			}
			case 3:
			{
				string cost[] = {"4362","4321"};
				string benefit[] = {"5329","5489"};
				string stone[] = {"...o","..o."};
				_expected = 22;
				_received = _obj.score(vector <string>(cost, cost+sizeof(cost)/sizeof(string)), vector <string>(benefit, benefit+sizeof(benefit)/sizeof(string)), vector <string>(stone, stone+sizeof(stone)/sizeof(string))); break;
			}
			case 4:
			{
				string cost[] = {"5413","4323","8321","5490"};
				string benefit[] = {"0432","7291","3901","2310"};
				string stone[] = {"ooo.","o..o","...o","oooo"};
				_expected = -12;
				_received = _obj.score(vector <string>(cost, cost+sizeof(cost)/sizeof(string)), vector <string>(benefit, benefit+sizeof(benefit)/sizeof(string)), vector <string>(stone, stone+sizeof(stone)/sizeof(string))); break;
			}
			/*case 5:
			{
				string cost[] = ;
				string benefit[] = ;
				string stone[] = ;
				_expected = ;
				_received = _obj.score(vector <string>(cost, cost+sizeof(cost)/sizeof(string)), vector <string>(benefit, benefit+sizeof(benefit)/sizeof(string)), vector <string>(stone, stone+sizeof(stone)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string cost[] = ;
				string benefit[] = ;
				string stone[] = ;
				_expected = ;
				_received = _obj.score(vector <string>(cost, cost+sizeof(cost)/sizeof(string)), vector <string>(benefit, benefit+sizeof(benefit)/sizeof(string)), vector <string>(stone, stone+sizeof(stone)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string cost[] = ;
				string benefit[] = ;
				string stone[] = ;
				_expected = ;
				_received = _obj.score(vector <string>(cost, cost+sizeof(cost)/sizeof(string)), vector <string>(benefit, benefit+sizeof(benefit)/sizeof(string)), vector <string>(stone, stone+sizeof(stone)/sizeof(string))); break;
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
