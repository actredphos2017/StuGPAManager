//
// Created by sakuno on 22-12-13.
//

#ifndef STUGPAMANAGER_GSTUDENTSCORE_H
#define STUGPAMANAGER_GSTUDENTSCORE_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QPushButton>

#include "../Report.h"

class GStudentScore : public QDialog {
    Q_OBJECT

    QHBoxLayout* scoreInputLayout;

    QVBoxLayout* scoreTitleLayout;
    QVBoxLayout* scoreLineLayout;

    QLabel* ScienceTitle;
    QLineEdit* ScienceLine;

    QLabel* DataStructTitle;
    QLineEdit* DataStructLine;

    QLabel* AlgorithmTitle;
    QLineEdit* AlgorithmLine;

    QLabel* MathTitle;
    QLineEdit* MathLine;

    QLabel* EnglishTitle;
    QLineEdit* EnglishLine;

    QHBoxLayout* btnLayout;
    QPushButton* yesBtn;
    QPushButton* cancelBtn;

    void initItem();
    void initUi();
    void initConnect();

public:
    explicit GStudentScore(QWidget* parent = nullptr);

public slots:
    void toInsertGStuScore();
    void buildScoreMap();

signals:
    void scoreMap(ScoreMap);
};


#endif //STUGPAMANAGER_CSTUDENTSCORE_H
