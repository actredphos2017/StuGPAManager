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
    int age;
    char sex{};
    StudentType type{};
    ScoreMap scores;

public:
    virtual float get_point() = 0;
    Student();
    Student(string id, string n, int a, char s, StudentType t, ScoreMap sc);
    Student(const Student& stu);
    bool operator==(const Student& stu) const;
    void operator=(const Student& stu);
};


#endif //STUGPAMANAGER_STUDENT_H
