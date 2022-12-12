//
// Created by sakuno on 22-12-11.
//

#ifndef STUGPAMANAGER_CSTUDENT_H
#define STUGPAMANAGER_CSTUDENT_H

#include <map>
#include "Student.h"
#define COLLEGE 1

class CStudent : public Student{
public:
    CStudent();
    CStudent(string id, string n, int a, char s, ScoreMap sc);
    float get_point() override;
    friend ostream& operator<<(ostream& os, CStudent& cs);
};


#endif //STUGPAMANAGER_CSTUDENT_H
