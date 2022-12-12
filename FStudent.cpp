//
// Created by sakuno on 22-12-11.
//

#include <iostream>
#include "FStudent.h"

float FStudent::get_point() {
    return chinese * 0.3 +
           math * 0.4 +
           IT * 0.3;
}

ostream& operator<<(ostream& os, FStudent& fs){
    os << "Name:\t" << fs.name << endl
       << "StudentID:\t" << fs.stuID << endl
       << "Age:\t" << fs.age << endl
       << "Sex:\t" << fs.sex << endl
       << "Point:\t" << fs.get_point();
}