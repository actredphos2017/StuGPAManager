//
// Created by sakuno on 22-12-11.
//

#ifndef STUGPAMANAGER_STUDENT_H
#define STUGPAMANAGER_STUDENT_H


#include <string>

using namespace std;

class Student {
public:
    string stuID;
    string name;
    string age;
    char sex{};

public:
    virtual float get_point() = 0;
};


#endif //STUGPAMANAGER_STUDENT_H
