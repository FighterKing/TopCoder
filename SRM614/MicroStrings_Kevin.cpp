// Brute Force, Simulation
// 200
#include<string>
using std::string;
class MicroStrings {
public:
  string makeMicroString(int A, int D) {
    string str;
    do{
      str += std::to_string(A);
    }while ((A -= D) >= 0);                                                                            
    return str;
  }
};
