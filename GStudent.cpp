//
// Created by sakuno on 22-12-11.
//

#include <iostream>
#include "GStudent.h"

float GStudent::get_point() {
    return science * 0.25 +
           dataStruct * 0.2 +
           algorithm * 0.2 +
           english * 0.15 +
           math * 0.2;
}

ostream& operator<<(ostream& os, GStudent& gs){
    os << "Name:\t" << gs.name << endl
       << "StudentID:\t" << gs.stuID << endl
       << "Age:\t" << gs.age << endl
       << "Sex:\t" << gs.sex << endl
       << "Point:\t" << gs.get_point();
}