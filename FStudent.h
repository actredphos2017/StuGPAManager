//
// Created by sakuno on 22-12-11.
//

#ifndef STUGPAMANAGER_FSTUDENT_H
#define STUGPAMANAGER_FSTUDENT_H


#include "Student.h"

class FStudent : public Student{
public:
    float chinese;
    float math;
    float IT;

public:
    float get_point();
    friend ostream& operator<<(ostream& os, const FStudent& cs);
};


#endif //STUGPAMANAGER_FSTUDENT_H
