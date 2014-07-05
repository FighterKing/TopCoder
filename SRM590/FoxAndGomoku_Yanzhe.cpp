#include <string>
#include <vector>
using namespace std;

class FoxAndGomoku {
public:
	string win(vector <string> board) {
		int n = board.size();
		// check horizontally
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'o' && j + 5 <= n) {
					int k;
					for (k = j + 1; k < j + 5; k++) {
						if (board[i][k] != board[i][j])
							break;
					}
					if (k == j + 5) return "found";
				}
			}
		}
		// check vertically
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				if (board[i][j] == 'o' && i + 5 <= n) {
					int k;
					for (k = i + 1; k < i + 5; k++) {
						if (board[k][j] != board[i][j])
							break;
					}
					if (k == i + 5) return "found";
				}
			}
		}
		// check diagonally
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'o' && i + 5 <= n && j + 5 <= n) {
					int k, g;
					for (k = i + 1, g = j + 1; k < i + 5 && g < j + 5; k++, g++) {
						if (board[k][g] != board[i][j])
							break;
					}
					if (k == i + 5 && g == j + 5) return "found";
				}
				if (board[i][j] == 'o' && i - 4 >= 0 && j + 4 <= n) {
					int k, g;
					for (k = i - 1, g = j + 1; k >= i - 4 && g < j + 5; k--, g++) {
						if (board[k][g] != board[i][j])
							break;
					}
					if (k == i - 5 && g == j + 5) return "found";
				}
			}
		}
		return "not found";
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
		cout << "Testing FoxAndGomoku (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404532349;
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
		FoxAndGomoku _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"....o.",
				                  "...o..",
				                  "..o...",
				                  ".o....",
				                  "o.....",
				                  "......"};
				_expected = "found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"oooo.",
				                  ".oooo",
				                  "oooo.",
				                  ".oooo",
				                  "....."}
				                  ;
				_expected = "not found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"oooo.",
				                  ".oooo",
				                  "oooo.",
				                  ".oooo",
				                  "....o"}
				                  ;
				_expected = "found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"o.....",
				                  ".o....",
				                  "..o...",
				                  "...o..",
				                  "....o.",
				                  "......"};
				_expected = "found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"o....",
				                  "o.o..",
				                  "o.o.o",
				                  "o.o..",
				                  "o...."};
				_expected = "found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"..........",
				                  "..........",
				                  "..oooooo..",
				                  "..o.......",
				                  "..o.......",
				                  "..oooooo..",
				                  ".......o..",
				                  ".......o..",
				                  "..oooooo..",
				                  ".........."}
				                  ;
				_expected = "found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = {"..........",
				                  "..........",
				                  "..oooo.o..",
				                  "..o.......",
				                  "..o.......",
				                  "..o.oooo..",
				                  ".......o..",
				                  ".......o..",
				                  "..oooo.o..",
				                  ".........."};
				_expected = "not found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 7:
			{
				string board[] = {"ooooo",
				                  "ooooo",
				                  "ooooo",
				                  "ooooo",
				                  "ooooo"};
				_expected = "found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 8:
			{
				string board[] = {".....",
				                  ".....",
				                  ".....",
				                  ".....",
				                  "....."};
				_expected = "not found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 9:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 11:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
