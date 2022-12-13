#include <QApplication>

#include "Report.h"
#include "VisualWindows/Menu.h"

Report rep;

int main(int argc, char* argv[]) {

    ScoreMap sc;
    sc["english"] = 90;
    sc["math"] = 76;
    sc["computer"] = 82.5;
    rep.insert(new CStudent("001","小红",19,'w',sc));

    ScoreMap sc2;
    sc2["chinese"] = 90;
    sc2["math"] = 76;
    sc2["computer"] = 82.5;
    rep.insert(new FStudent("002","Tony",19,'w',sc2));

    ScoreMap sc3;
    sc3["chinese"] = 90;
    sc3["math"] = 76;
    sc3["computer"] = 82.5;
    rep.insert(new FStudent("003","Jenny",19,'w',sc3));

    QApplication application(argc, argv);
    Menu m;
    m.show();
    return QApplication::exec();
}
