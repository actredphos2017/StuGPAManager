//
// Created by sakuno on 22-12-12.
//

#ifndef STUGPAMANAGER_MENU_H
#define STUGPAMANAGER_MENU_H


#include <QDialog>
#include <QLabel>

namespace Ui{
    class Menu;
};

class Menu : public QDialog{
    Q_OBJECT

private:
    Ui::Menu* ui;

public:
    Menu(QWidget* parent);

};


#endif //STUGPAMANAGER_MENU_H
