//
// Created by sakuno on 22-12-11.
//

#include <iostream>
#include <utility>
#include "Student.h"

bool Student::operator==(const Student &stu) const {
    return stuID == stu.stuID &&
           name == stu.name &&
           age == stu.age &&
           sex == stu.sex;
}

Student::Student() = default;

Student::Student(const Student &stu) {
    name = stu.name;
    stuID = stu.stuID;
    age = stu.age;
    sex = stu.sex;
    scores = stu.scores;
    type = stu.type;
}

void Student::operator=(const Student &stu) {
    name = stu.name;
    stuID = stu.stuID;
    age = stu.age;
    sex = stu.sex;
    scores = stu.scores;
    type = stu.type;
}

Student::Student(string id, string n, int a, char s, StudentType t, ScoreMap sc):
    stuID(std::move(id)),
    name(std::move(n)),
    age(a),
    sex(s),
    type(t),
    scores(std::move(sc)){}