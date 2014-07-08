#include <vector>
using namespace std;

class BlockTower {
public:
	int getTallest(vector <int> blockHeights) {
		int ret = 0;
		for (auto h : blockHeights) {
			if (h % 2 == 0) ret += h;
		}
		for (int i = 0; i < blockHeights.size(); i++) {
			if (blockHeights[i] % 2 == 1) {
				int sum = 0;
				for (int j = 0; j < i; j++) {
					if (blockHeights[j] % 2 == 0) sum += blockHeights[j];
				}
				for (int j = i; j < blockHeights.size(); j++) {
					if (blockHeights[j] % 2 == 1) sum += blockHeights[j];
				}
				if (ret < sum) ret = sum;
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
		cout << "Testing BlockTower (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404826186;
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
		BlockTower _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int blockHeights[] = {4,7};
				_expected = 11;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}
			case 1:
			{
				int blockHeights[] = {7,4};
				_expected = 7;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}
			case 2:
			{
				int blockHeights[] = {7};
				_expected = 7;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}
			case 3:
			{
				int blockHeights[] = {4};
				_expected = 4;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}
			case 4:
			{
				int blockHeights[] = {48,1,50,1,50,1,48};
				_expected = 196;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}
			case 5:
			{
				int blockHeights[] = {49,2,49,2,49};
				_expected = 147;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}
			case 6:
			{
				int blockHeights[] = {44,3,44,3,44,47,2,47,2,47,2};
				_expected = 273;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}
			/*case 7:
			{
				int blockHeights[] = ;
				_expected = ;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int blockHeights[] = ;
				_expected = ;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int blockHeights[] = ;
				_expected = ;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
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
