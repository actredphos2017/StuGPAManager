//
// Created by sakuno on 22-12-11.
//

#include <iostream>
#include <utility>
#include "CStudent.h"

float CStudent::get_point() {
    return  scores["english"] * 0.3 +
            scores["math"] * 0.4 +
            scores["computer"] * 0.3;
}

ostream& operator<<(ostream& os, CStudent& fs){
    os << "Name:\t" << fs.name << endl
       << "StudentID:\t" << fs.stuID << endl
       << "Age:\t" << fs.age << endl
       << "Sex:\t" << fs.sex << endl
       << "Point:\t" << fs.get_point();
}

CStudent::CStudent() {
    type = COLLEGE;
}

CStudent::CStudent(ScoreMap sc):
    Student(std::move(sc)){
    type = COLLEGE;
}
