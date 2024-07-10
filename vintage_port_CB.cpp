#include "vintage_port_CB.h"


VintagePort::VintagePort()
        : Port("no brand", "vintage", 0) {
    string temp = "no nick";
    nickname = (char*)temp.c_str();
    year = 0;
}

VintagePort::VintagePort(const char *brnd, int btl, const char *nickn, int yr)
    : Port(brnd, "vintage", btl) {
    nickname = new char[strlen(nickn) + 1];
    strcpy(nickname, nickn);
    year = yr;
}

VintagePort::VintagePort(const VintagePort &vp)
    : Port(vp) {
    year = vp.year;
    nickname = new char[strlen(vp.nickname) + 1];
}

VintagePort &VintagePort::operator=(const VintagePort &vp) {
    if(this == &vp) { return *this; }
    Port::operator=(vp); // copy Port (aka base) portion
    delete[] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const {
    Port::Show(); // display base portion
    // Nickname: Old velvet
    // Year: 1950
    cout << "Nickname: "s << nickname << endl;
    cout << "Year: "s << year << endl;
}

ostream &operator<<(ostream &os, const VintagePort &vp)
{
    os << (const Port &)vp; // ostream for Port ('base') portion
    os << vp.nickname << ", "s << vp.year << endl; // output: Old velvet, 1950
    return os;
}
