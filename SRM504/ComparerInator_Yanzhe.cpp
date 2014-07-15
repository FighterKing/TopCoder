#include <vector>
using namespace std;

typedef int (*Program) (int, int);

int P1 (int a, int b) {return a;}
int P2 (int a, int b) {return b;}
int P3 (int a, int b) {return a < b ? a : b;}
int P4 (int a, int b) {return a < b ? b : a;}

class ComparerInator {
public:
	int makeProgram(vector <int> A, vector <int> B, vector <int> wanted) {
		vector<Program> progs {P1, P2, P3, P4};
		vector<int> lens {1, 1, 7, 7};

		for (int i = 0; i < 4; i++) {
			bool match = true;
			for (int j = 0; j < A.size(); j++)
				if ((progs[i])(A[j], B[j]) != wanted[j]) {
					match = false;
					break;
				}
			if (match) return lens[i];
		}
		return -1;
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
		cout << "Testing ComparerInator (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1405397887;
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
		ComparerInator _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1};
				int B[] = {2};
				int wanted[] = {2};
				_expected = 1;
				_received = _obj.makeProgram(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(wanted, wanted+sizeof(wanted)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {1,3};
				int B[] = {2,1};
				int wanted[] = {2,3};
				_expected = 7;
				_received = _obj.makeProgram(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(wanted, wanted+sizeof(wanted)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {1,3,5};
				int B[] = {2,1,7};
				int wanted[] = {2,3,5};
				_expected = -1;
				_received = _obj.makeProgram(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(wanted, wanted+sizeof(wanted)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {1,3,5};
				int B[] = {2,1,7};
				int wanted[] = {1,3,5};
				_expected = 1;
				_received = _obj.makeProgram(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(wanted, wanted+sizeof(wanted)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {1,2,3,4,5,6,7,8,9,10,11};
				int B[] = {5,4,7,8,3,1,1,2,3,4,6};
				int wanted[] = {1,2,3,4,3,1,1,2,3,4,6};
				_expected = 7;
				_received = _obj.makeProgram(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(wanted, wanted+sizeof(wanted)/sizeof(int))); break;
			}
			case 5:
			{
				int A[] = {1,5,6,7,8};
				int B[] = {1,5,6,7,8};
				int wanted[] = {1,5,6,7,8};
				_expected = 1;
				_received = _obj.makeProgram(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(wanted, wanted+sizeof(wanted)/sizeof(int))); break;
			}
			/*case 6:
			{
				int A[] = ;
				int B[] = ;
				int wanted[] = ;
				_expected = ;
				_received = _obj.makeProgram(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(wanted, wanted+sizeof(wanted)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				int B[] = ;
				int wanted[] = ;
				_expected = ;
				_received = _obj.makeProgram(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(wanted, wanted+sizeof(wanted)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int A[] = ;
				int B[] = ;
				int wanted[] = ;
				_expected = ;
				_received = _obj.makeProgram(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(wanted, wanted+sizeof(wanted)/sizeof(int))); break;
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
