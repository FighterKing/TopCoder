#include <string>
using namespace std;

class LittleElephantAndBallsAgain {
private:
    bool same(string s) {
        if (s.length() < 2) return true;
        bool ret = true;
        for (auto i : s)
            ret = ret && (i == s[0]);
        return ret;
    }
public:
    int getNumber(string S) {
        if (same(S)) return 0;
        int head = getNumber(S.substr(1)) + 1;
        int tail = getNumber(S.substr(0, S.length()-1)) + 1;
        return (head < tail) ? head : tail;
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
        cout << "Testing LittleElephantAndBallsAgain (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++)
        {
            ostringstream s; s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1400836079;
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
        LittleElephantAndBallsAgain _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc)
        {
            case 0:
            {
                string S = "RRGGBB";
                _expected = 4;
                _received = _obj.getNumber(S); break;
            }
            case 1:
            {
                string S = "R";
                _expected = 0;
                _received = _obj.getNumber(S); break;
            }
            case 2:
            {
                string S = "RGBRGB";
                _expected = 5;
                _received = _obj.getNumber(S); break;
            }
            case 3:
            {
                string S = "RGGGBB";
                _expected = 3;
                _received = _obj.getNumber(S); break;
            }
            case 4:
            {
                string S = "RGBRBRGRGRBBBGRBRBRGBGBBBGRGBBBBRGBGRRGGRRRGRBBBBR";
                _expected = 46;
                _received = _obj.getNumber(S); break;
            }
            /*case 5:
            {
                string S = ;
                _expected = ;
                _received = _obj.getNumber(S); break;
            }*/
            /*case 6:
            {
                string S = ;
                _expected = ;
                _received = _obj.getNumber(S); break;
            }*/
            /*case 7:
            {
                string S = ;
                _expected = ;
                _received = _obj.getNumber(S); break;
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
