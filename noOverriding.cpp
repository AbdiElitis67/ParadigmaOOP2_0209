#include <iostream>
using namespace std;

class baseClass {
public:
    virtual void perkenlaan() final{
        cout << "Hallo saya Function dari base class";
    }
};
