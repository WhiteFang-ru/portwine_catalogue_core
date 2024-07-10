#include "port_CB.h"

class VintagePort : public Port // style necessarily = "vintage"
{
private:
    char *nickname; // i.e., "The Noble" or "Old Velvet", etc.
    int year;       // vintage year
public:
    VintagePort();
    VintagePort(const char *brnd, int btl, const char *nickn, int yr);
    VintagePort(const VintagePort &vp);
    ~VintagePort() { delete[] nickname; }
    VintagePort &operator=(const VintagePort &vp);
    void Show() const;
    friend ostream &operator<<(ostream &os, const VintagePort &vp);
};
