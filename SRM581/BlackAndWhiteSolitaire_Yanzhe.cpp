#include <string>
using namespace std;

class BlackAndWhiteSolitaire {
public:
	int minimumTurns(string cardFront) {
		bool black;
		int bf = 0;  // black first
		black = true;
		for (auto c : cardFront) {
			if (black) {
				if (c == 'W') bf++;
				black = false;
			} else {
				if (c == 'B') bf++;
				black = true;
			}
		}

		int wf = 0;  // white first
		black = false;
		for (auto c : cardFront) {
			if (black) {
				if (c == 'W') wf++;
				black = false;
			} else {
				if (c == 'B') wf++;
				black = true;
			}
		}

		return bf < wf ? bf : wf;
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
		cout << "Testing BlackAndWhiteSolitaire (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404551942;
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
		BlackAndWhiteSolitaire _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cardFront = "BBBW";
				_expected = 1;
				_received = _obj.minimumTurns(cardFront); break;
			}
			case 1:
			{
				string cardFront = "WBWBW";
				_expected = 0;
				_received = _obj.minimumTurns(cardFront); break;
			}
			case 2:
			{
				string cardFront = "WWWWWWWWW";
				_expected = 4;
				_received = _obj.minimumTurns(cardFront); break;
			}
			case 3:
			{
				string cardFront = "BBWBWWBWBWWBBBWBWBWBBWBBW";
				_expected = 10;
				_received = _obj.minimumTurns(cardFront); break;
			}
			/*case 4:
			{
				string cardFront = ;
				_expected = ;
				_received = _obj.minimumTurns(cardFront); break;
			}*/
			/*case 5:
			{
				string cardFront = ;
				_expected = ;
				_received = _obj.minimumTurns(cardFront); break;
			}*/
			/*case 6:
			{
				string cardFront = ;
				_expected = ;
				_received = _obj.minimumTurns(cardFront); break;
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
