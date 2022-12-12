//
// Created by sakuno on 22-12-11.
//

#include "Report.h"

void Report::insert(Student *stu) {
    for(auto it : students)
        if(*it == *stu){
            (*it) = (*stu);
            return;
        }
    students.push_back(stu);
}

void Report::insert(const Report& re) {
    for(auto it : re.students)
        insert(it);
}

void Report::remove(Student *stu) {
    for(auto pos = students.begin(); pos != students.end(); pos ++)
        if(**pos == *stu){
            students.erase(pos);
            return;
        }
}

void Report::remove(const Report& re) {
    for(auto it : re.students)
        remove(it);
}

Report &Report::operator[](StudentType _t) {
    Report res;
    for(auto it : students)
        if(it->type == _t)
            res.insert(it);
    return res;
}

void Report::write(ostream& os) {
    nlohmann::json j;
    int i = 0;
    for(auto it : students){
        j[i]["stuID"] = it->stuID;
        j[i]["name"] = it->name;
        j[i]["age"] = it->age;
        j[i]["sex"] = it->sex;
        j[i]["type"] = it->type;
        j[i]["score"] = it->scores;
        i ++;
    }
    os << j;
    j.clear();
}

void Report::read(istream &is) {
    nlohmann::json j;
    is >> j;

    for(auto it : j){
        Student* stu;
        StudentType t = it["type"];
        switch (t){
            case 1:
                stu = new CStudent((string)it["stuID"],
                                   (string)it["name"],
                                   (int)it["age"],
                                   (char)(int)it["sex"],
                                   (ScoreMap)it["score"]);
                break;
            case 2:
                stu = new FStudent((string)it["stuID"],
                                   (string)it["name"],
                                   (int)it["age"],
                                   (char)(int)it["sex"],
                                   (ScoreMap)it["score"]);
                break;
            case 3:
                stu = new GStudent((string)it["stuID"],
                                   (string)it["name"],
                                   (int)it["age"],
                                   (char)(int)it["sex"],
                                   (ScoreMap)it["score"]);
                break;
        }
        students.push_back(stu);
    }
}
