//
// Created by sakuno on 22-12-11.
//

#ifndef STUGPAMANAGER_GSTUDENT_H
#define STUGPAMANAGER_GSTUDENT_H


#include "Student.h"
#define GRADUATE 3

class GStudent : public Student {
public:
    GStudent();
    GStudent(string id, string n, int a, char s, ScoreMap sc);
    float get_point() override;
    friend ostream& operator<<(ostream& os, GStudent& gs);
};


#endif //STUGPAMANAGER_GSTUDENT_H
