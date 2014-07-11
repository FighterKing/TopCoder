#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class XorBoardDivTwo {
public:
	int theMax(vector <string> board) {
		int ret = 0;
	    int base = 0;
	    for (auto s : board)
	      base += count(s.begin(), s.end(), '1');

	    int sum;
	    for (int i = 0; i < board.size(); i++) {
	      for (int j = 0; j < board[i].size(); j++) {
	        sum = base;

	        sum -= count(board[i].begin(), board[i].end(), '1');
	        for (int k = 0; k < board.size(); k++)
	          if (board[k][j] == '1') sum--;
	        sum += count(board[i].begin(), board[i].end(), '0');
	        for (int k = 0; k < board.size(); k++)
	          if (board[k][j] == '0') sum++;

	        sum += (board[i][j] == '0') ? -2 : 2;

	        if (sum > ret) ret = sum;
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
		cout << "Testing XorBoardDivTwo (255.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1405042323;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 255.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		XorBoardDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"101",
				                  "010",
				                  "101"};
				_expected = 9;
				_received = _obj.theMax(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"111",
				                  "111",
				                  "111"};
				_expected = 5;
				_received = _obj.theMax(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"0101001",
				                  "1101011"};
				_expected = 9;
				_received = _obj.theMax(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"000",
				                  "001",
				                  "010",
				                  "011",
				                  "100",
				                  "101",
				                  "110",
				                  "111"};
				_expected = 15;
				_received = _obj.theMax(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"000000000000000000000000",
				                  "011111100111111001111110",
				                  "010000000100000001000000",
				                  "010000000100000001000000",
				                  "010000000100000001000000",
				                  "011111100111111001111110",
				                  "000000100000001000000010",
				                  "000000100000001000000010",
				                  "000000100000001000000010",
				                  "011111100111111001111110",
				                  "000000000000000000000000"};
				_expected = 105;
				_received = _obj.theMax(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.theMax(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.theMax(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.theMax(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
