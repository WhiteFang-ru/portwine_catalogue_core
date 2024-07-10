#include "port_CB.h"

Port::Port(const char *brnd, const char *stl, int btl) {
    brand = new char[strlen(brnd) + 1];
    strcpy(brand, brnd);
    style = new char[strlen(stl) + 1];
    strcpy(style, stl);
    bottles = btl;
}

Port::Port(const Port &p) {
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    style = new char[strlen(p.brand) + 1];
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port &Port::operator=(const Port &p) {
    if (this == &p) {
        return *this;
    };
    delete[] brand;
    delete[] style;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    style = new char[strlen(p.brand) + 1];
    strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}



Port &Port::operator+=(int btlplus)  {// adds btlplus to bottles
    bottles += btlplus;
    return *this;
}

Port &Port::operator-=(int btlminus) {
    while(btlminus > bottles) {
        cout << "Too many bottles to substract. Enter less: \n";
        string temp;
        cin >> temp;
        btlminus = stoi(temp);
    }
    bottles -= btlminus;
    return *this;
}

void Port::Show() const {
// Brand: Gallo
// Kind: tawny
//Bottles: 20
    cout << "Brand: "s << brand << endl;
    cout << "Kind: "s << style << endl;
    cout << "Bottles: "s << bottles << endl;
}

ostream &operator<<(ostream &os, const Port &p) {
    os << p.brand << ", "s << p.style << ", "s << p.bottles << endl;
    // Gallo, tawny, 20
    return os;
}
