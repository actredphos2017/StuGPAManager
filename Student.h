//
// Created by sakuno on 22-12-11.
//

#ifndef STUGPAMANAGER_STUDENT_H
#define STUGPAMANAGER_STUDENT_H

#include <string>
#include <map>

using namespace std;

typedef unsigned int StudentType;
typedef map<string, float> ScoreMap;

class Student {
public:
    string stuID;
    string name;
    string age;
    char sex{};
    StudentType type{};
    ScoreMap scores;

public:
    virtual float get_point() = 0;
    Student();
    explicit Student(ScoreMap sc);
    bool operator==(const Student& stu);
};


#endif //STUGPAMANAGER_STUDENT_H
