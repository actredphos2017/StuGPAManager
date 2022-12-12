#include <iostream>
#include <sstream>

#include "Report.h"

int main() {
    Report re;
    ScoreMap sc1;
    sc1["english"] = 87.5;
    sc1["math"] = 79;
    sc1["computer"] = 81;
    re.insert(new CStudent("001","小红", 19, 'f', sc1));

    ScoreMap sc2;
    sc2["chinese"] = 93;
    sc2["math"] = 86;
    sc2["computer"] = 90;
    re.insert(new FStudent("002","Tony", 20, 'm', sc2));


    stringstream ss;
    re.write(ss);
    string str = ss.str();

    Report re2;
    re2.read(ss);
    stringstream ss2;
    re2.write(ss2);
    cout << (str == ss2.str()) << endl;

    return 0;
}
