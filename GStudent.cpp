//
// Created by sakuno on 22-12-11.
//

#include <iostream>
#include <utility>
#include "GStudent.h"

float GStudent::get_point() {
    return scores["science"] * 0.25 +
           scores["data_struct"] * 0.2 +
           scores["algorithm"] * 0.2 +
           scores["english"] * 0.15 +
           scores["math"] * 0.2;
}

ostream& operator<<(ostream& os, GStudent& gs){
    os << "Name:\t" << gs.name << endl
       << "StudentID:\t" << gs.stuID << endl
       << "Age:\t" << gs.age << endl
       << "Sex:\t" << gs.sex << endl
       << "Point:\t" << gs.get_point();
}

GStudent::GStudent() {
    type = GRADUATE;
}

GStudent::GStudent(ScoreMap sc) :
    Student(std::move(sc)){
    type = GRADUATE;
}