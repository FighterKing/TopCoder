#include <string>
#include <algorithm>
using namespace std;

class EllysSubstringSorter {
public:
    string getMin(string S, int L) {
        string ans = S;
        for (int i = 0; i < S.length() - L + 1; i++) {
            string copy = S;
            sort(copy.begin() + i, copy.begin() + i + L);
            if (copy < ans) ans = copy;
        }
        return ans;
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
        cout << "Testing EllysSubstringSorter (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++)
        {
            ostringstream s; s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1399557836;
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
        EllysSubstringSorter _obj;
        string _expected, _received;
        time_t _start = clock();
        switch (_tc)
        {
            case 0:
            {
                string S = "TOPCODER";
                int L = 4;
                _expected = "COPTODER";
                _received = _obj.getMin(S, L); break;
            }
            case 1:
            {
                string S = "ESPRIT";
                int L = 3;
                _expected = "EPRSIT";
                _received = _obj.getMin(S, L); break;
            }
            case 2:
            {
                string S = "AAAAAAAAA";
                int L = 2;
                _expected = "AAAAAAAAA";
                _received = _obj.getMin(S, L); break;
            }
            case 3:
            {
                string S = "ABRACADABRA";
                int L = 5;
                _expected = "AAABCRDABRA";
                _received = _obj.getMin(S, L); break;
            }
            case 4:
            {
                string S = "BAZINGA";
                int L = 6;
                _expected = "ABGINZA";
                _received = _obj.getMin(S, L); break;
            }
            case 5:
            {
                string S = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
                int L = 21;
                _expected = "AAAAAABDDDEEIIIJOOSUWWWWDBPOAWDUISAWDOOPAWD";
                _received = _obj.getMin(S, L); break;
            }
            /*case 6:
            {
                string S = ;
                int L = ;
                _expected = ;
                _received = _obj.getMin(S, L); break;
            }*/
            /*case 7:
            {
                string S = ;
                int L = ;
                _expected = ;
                _received = _obj.getMin(S, L); break;
            }*/
            /*case 8:
            {
                string S = ;
                int L = ;
                _expected = ;
                _received = _obj.getMin(S, L); break;
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
