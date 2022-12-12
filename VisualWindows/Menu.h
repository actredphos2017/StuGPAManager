//
// Created by sakuno on 22-12-12.
//

#ifndef STUGPAMANAGER_MENU_H
#define STUGPAMANAGER_MENU_H

#include <QDialog>
#include <QLabel>

#include "../Report.h"

namespace Ui{
    class Menu;
};

class Menu : public QDialog{
    Q_OBJECT

private:
    Ui::Menu* ui;

    QMap<StudentType, QString> stuTypeChangeMap;

    QString fileName;

    void flashData();

    void initItem();
    void initConnect();

public:
    Menu(QWidget* parent = nullptr);
    virtual ~Menu();

public slots:
    void inputFile();
    void save();
    void outputFile();
    void searchName();
};


#endif //STUGPAMANAGER_MENU_H
