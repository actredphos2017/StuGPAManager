//
// Created by sakuno on 22-12-11.
//

#ifndef STUGPAMANAGER_CSTUDENT_H
#define STUGPAMANAGER_CSTUDENT_H

#include "Student.h"

class CStudent : public Student{
public:
    float english;
    float math;
    float IT;

public:
    float get_point();
    friend ostream& operator<<(ostream& os, CStudent& cs);
};


#endif //STUGPAMANAGER_CSTUDENT_H
