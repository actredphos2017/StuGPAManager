//
// Created by sakuno on 22-12-11.
//

#ifndef STUGPAMANAGER_REPORT_H
#define STUGPAMANAGER_REPORT_H

#include <list>
#include <vector>
#include <iostream>

#include "cppconn/driver.h"
#include "cppconn/connection.h"
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h"

#include "Student.h"

using namespace std;
using namespace sql;

class Report {
private:
    bool connectSQL = false;
    Driver*     dri = nullptr;
    Connection* con = nullptr;

    list<Student*> container;

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
