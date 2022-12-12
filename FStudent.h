//
// Created by sakuno on 22-12-11.
//

#ifndef STUGPAMANAGER_FSTUDENT_H
#define STUGPAMANAGER_FSTUDENT_H


#include "Student.h"
#define FOREIGN 2

class FStudent : public Student{
public:
    FStudent();
    explicit FStudent(ScoreMap sc);
    float get_point() override;
    friend ostream& operator<<(ostream& os, FStudent& cs);
};


#endif //STUGPAMANAGER_FSTUDENT_H
