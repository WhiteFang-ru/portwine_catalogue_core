#include "vintage_port_CB.h"

int main() {
    Port port("Sandemans", "Ruby", 20);
    VintagePort vintage_p = VintagePort("Cockburn", 5, "The Noble", 1940);
    cout << "Using object directly,\n"s;
    cout << "port.show():"s << endl;
    port.Show();      // use Port method
    cout << "vintage_p.Show()"s << endl;
    vintage_p.Show(); // use VintagePort method
    cout << "port, operator<<() :\n"s << port << endl;
    cout << "vintage_p, operator<<() :\n"s << vintage_p << endl;

    Port *ptr_port = &port;
    cout << "\nUsing type 'Port *' pointer to objects,\n";
    cout << "1) for 'port':\n";
    ptr_port->Show(); // use Port method for port object
    cout << "2) for 'vintage_p':\n";
    ptr_port = &vintage_p;
    ptr_port->Show(); // use VintagePort method for vintage_p object

    cout << "Assignment operator works: \n";
    VintagePort vintage_p_new = vintage_p;
    vintage_p_new.Show();

    cout << "operator+=() works for 'port' object.\n";
    port.operator+=(2);
    port += 2; // same
    cout << "added bottles count of 'port' object:\t" << port.BottleCount() << endl;

    cout << "operator-=() works for 'vintage_p_new' object.\n";
    vintage_p_new -= 7;
    cout << "decreased bottles count of 'vintage_p_new' object:\t" << vintage_p_new.BottleCount() << endl;

    return 0;
}


