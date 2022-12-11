//
// Created by sakuno on 22-12-11.
//

#ifndef STUGPAMANAGER_REPORT_H
#define STUGPAMANAGER_REPORT_H

#include <list>
#include <vector>
#include <iostream>

#include "Student.h"

using namespace std;

class Report {
private:
    list<Student*> stus;
public:
    void insert(Student* stu);
    void insert(Report& re);
    void remove(Report& re);
    void remove(const string& condition);
    Report& operator[](const string& condition);
    friend ostream& operator<<(ostream& os, Report& re);

    bool read(istream& is, ostream& errorOs = cout);
    bool write(ostream& os, ostream& errorOs = cout);
    friend istream& operator>>(istream& os, Report& re);
};


#endif //STUGPAMANAGER_REPORT_H
