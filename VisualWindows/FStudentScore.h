//
// Created by sakuno on 22-12-13.
//

#ifndef STUGPAMANAGER_FSTUDENTSCORE_H
#define STUGPAMANAGER_FSTUDENTSCORE_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QPushButton>

#include "../Report.h"

class FStudentScore : public QDialog {
    Q_OBJECT

    QHBoxLayout* scoreInputLayout;

    QVBoxLayout* scoreTitleLayout;
    QVBoxLayout* scoreLineLayout;


    QLabel* ChineseTitle;
    QLineEdit* ChineseLine;

    QLabel* MathTitle;
    QLineEdit* MathLine;

    QLabel* ComputerTitle;
    QLineEdit* ComputerLine;


    QHBoxLayout* btnLayout;
    QPushButton* yesBtn;
    QPushButton* cancelBtn;

    void initItem();
    void initUi();
    void initConnect();

public:
    explicit FStudentScore(QWidget* parent = nullptr);

public slots:
    void toInsertFStuScore();
    void buildScoreMap();

signals:
    void scoreMap(ScoreMap);
};


#endif //STUGPAMANAGER_FSTUDENTSCORE_H
