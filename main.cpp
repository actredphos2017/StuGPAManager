#include <QApplication>

#include "Report.h"
#include "VisualWindows/Menu.h"

Report rep;

int main(int argc, char* argv[]) {
    QApplication application(argc, argv);
    Menu m;
    m.show();
    return QApplication::exec();
}