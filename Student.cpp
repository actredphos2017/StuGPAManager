//
// Created by sakuno on 22-12-11.
//

#include <iostream>
#include "Student.h"

bool Student::operator==(const Student &stu) {
    return stuID == stu.stuID &&
           name == stu.name &&
           age == stu.age &&
           sex == stu.sex;
}
