//
// Created by sakuno on 22-12-11.
//

#ifndef STUGPAMANAGER_REPORT_H
#define STUGPAMANAGER_REPORT_H

#include <list>
#include <vector>
#include <iostream>

#include "nlohmann/json.hpp"

#include "Student.h"
#include "GStudent.h"
#include "CStudent.h"
#include "FStudent.h"

using namespace std;

class Report {
public:
    list<Student*> students;

public:
    Report() = default;

    void insert(Student* stu);
    void insert(const Report& re);

    void remove(Student* stu);
    void remove(const Report& re);

    Report& operator[](StudentType _t);
    friend ostream& operator<<(ostream& os, Report& re);

    void read(istream& is);
    void write(ostream& os);
    int size();

    friend istream& operator>>(istream& os, Report& re);
};


#endif //STUGPAMANAGER_REPORT_H
