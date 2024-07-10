#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Port
{
private:
    char *brand;
    char *style; // i.e., tawny, ruby, vintage
    int bottles;

public:
    Port(const char *brnd = "none", const char *stl = "none", int btl = 0);
    Port(const Port &p); // copy constructor
    virtual ~Port() {
        delete[] brand;
        delete[] style;
    }
    Port &operator=(const Port &p);
    Port &operator+=(int btlplus); // adds btlplus to bottles
    Port &operator-=(int btlminus); // subtracts btlminus from bottles, if available
    int BottleCount() const { return bottles; }
    virtual void Show() const;
    friend ostream &operator<<(ostream &os, const Port &p);
    // Because operator<<() accesses private Port object members directly,
    // it has to be a friend to the Port class
};
