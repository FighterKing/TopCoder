#include <vector>
#include <algorithm>
using namespace std;

class LittleElephantAndBooks {
public:
    int getNumber(vector <int> pages, int number) {
        sort(pages.begin(), pages.end());
        int ret = 0;
        for (int i = 0; i < number - 1; i++)
            ret += pages[i];
        ret += pages[number];
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
        cout << "Testing LittleElephantAndBooks (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++)
        {
            ostringstream s; s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1401257790;
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
        LittleElephantAndBooks _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc)
        {
            case 0:
            {
                int pages[] = {1, 2};
                int number = 1;
                _expected = 2;
                _received = _obj.getNumber(vector <int>(pages, pages+sizeof(pages)/sizeof(int)), number); break;
            }
            case 1:
            {
                int pages[] = {74, 7, 4, 47, 44};
                int number = 3;
                _expected = 58;
                _received = _obj.getNumber(vector <int>(pages, pages+sizeof(pages)/sizeof(int)), number); break;
            }
            case 2:
            {
                int pages[] = {3, 1, 9, 7, 2, 8, 6, 4, 5};
                int number = 7;
                _expected = 29;
                _received = _obj.getNumber(vector <int>(pages, pages+sizeof(pages)/sizeof(int)), number); break;
            }
            case 3:
            {
                int pages[] = {74, 86, 32, 13, 100, 67, 77};
                int number = 2;
                _expected = 80;
                _received = _obj.getNumber(vector <int>(pages, pages+sizeof(pages)/sizeof(int)), number); break;
            }
            /*case 4:
            {
                int pages[] = ;
                int number = ;
                _expected = ;
                _received = _obj.getNumber(vector <int>(pages, pages+sizeof(pages)/sizeof(int)), number); break;
            }*/
            /*case 5:
            {
                int pages[] = ;
                int number = ;
                _expected = ;
                _received = _obj.getNumber(vector <int>(pages, pages+sizeof(pages)/sizeof(int)), number); break;
            }*/
            /*case 6:
            {
                int pages[] = ;
                int number = ;
                _expected = ;
                _received = _obj.getNumber(vector <int>(pages, pages+sizeof(pages)/sizeof(int)), number); break;
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
