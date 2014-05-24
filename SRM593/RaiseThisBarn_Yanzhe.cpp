#include <string>
using namespace std;

class RaiseThisBarn {
private:
    int count(string s) {
        int ret = 0;
        for (auto c : s)
            ret += (c == 'c');
        return ret;
    }
public:
    int calc(string str) {
        size_t N = str.length();
        int ret = 0;
        int all_cows = count(str);
        for (size_t i = 1; i < N; i++)
            ret += (count(str.substr(0, i)) * 2 == all_cows);
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
        cout << "Testing RaiseThisBarn (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++)
        {
            ostringstream s; s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1400914904;
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
        RaiseThisBarn _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc)
        {
            case 0:
            {
                string str = "cc..c.c";
                _expected = 3;
                _received = _obj.calc(str); break;
            }
            case 1:
            {
                string str = "c....c....c";
                _expected = 0;
                _received = _obj.calc(str); break;
            }
            case 2:
            {
                string str = "............";
                _expected = 11;
                _received = _obj.calc(str); break;
            }
            case 3:
            {
                string str = ".c.c...c..ccc.c..c.c.cc..ccc";
                _expected = 3;
                _received = _obj.calc(str); break;
            }
            /*case 4:
            {
                string str = ;
                _expected = ;
                _received = _obj.calc(str); break;
            }*/
            /*case 5:
            {
                string str = ;
                _expected = ;
                _received = _obj.calc(str); break;
            }*/
            /*case 6:
            {
                string str = ;
                _expected = ;
                _received = _obj.calc(str); break;
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
