//
// Created by sakuno on 22-12-11.
//

#ifndef STUGPAMANAGER_GSTUDENT_H
#define STUGPAMANAGER_GSTUDENT_H


#include "Student.h"

class GStudent : public Student {
public:
    float science;
    float dataStruct;
    float algorithm;
    float english;
    float math;

public:
    float get_point() override;
    friend ostream& operator<<(ostream& os, GStudent& gs);
};


#endif //STUGPAMANAGER_GSTUDENT_H
