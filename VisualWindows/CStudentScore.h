//
// Created by sakuno on 22-12-13.
//

#ifndef STUGPAMANAGER_CSTUDENTSCORE_H
#define STUGPAMANAGER_CSTUDENTSCORE_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QPushButton>

#include "../Report.h"

class CStudentScore : public QDialog {
    Q_OBJECT

    QHBoxLayout* scoreInputLayout;

    QVBoxLayout* scoreTitleLayout;
    QVBoxLayout* scoreLineLayout;


    QLabel* EnglishTitle;
    QLineEdit* EnglishLine;

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
    explicit CStudentScore(QWidget* parent = nullptr);

public slots:
    void toInsertCStuScore();
    void buildScoreMap();

signals:
    void scoreMap(ScoreMap);
    void fleshData();
};


#endif //STUGPAMANAGER_CSTUDENTSCORE_H
