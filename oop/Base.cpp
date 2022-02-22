//
// Created by sun yin dong on 2021/6/6.
//

#include "Base.h"
#include <iostream>
namespace oop{
    using namespace std;
    Base::Base() {}

    Base::Base(int basePriviteInt) : base_privite_int(basePriviteInt) {}

    void Base::printBaseClassPrivateValue() {
        cout << base_privite_int << endl;
    }

    void Base::printInfo() {
        cout << "Call Base printInfo! ";
    }

    Base::~Base() {
        cout<<"     Base destructor is called! "<<endl;
    }
}



