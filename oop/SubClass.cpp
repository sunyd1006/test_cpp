//
// Created by sun yin dong on 2021/6/6.
//

#include <iostream>
#include "SubClass.h"

namespace oop {
    using namespace std;

    void SubClass::subPrintBaseClassPrivateValue() {
        // oop::Base::printBaseClassPrivateValue();        // 这种方式也不行
    }

    void SubClass::printInfo() {
        cout << "SubClass printInfo begin: ";
        Base::printInfo();
        cout << "SubClass printInfo end: ";
    }

    SubClass::~SubClass() {
        cout << "   SubClass destructor is called! " << endl;
    }
}
