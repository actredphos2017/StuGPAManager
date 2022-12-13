//
// Created by sakuno on 22-12-13.
//

#ifndef STUGPAMANAGER_INSERTDIALOG_H
#define STUGPAMANAGER_INSERTDIALOG_H


#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QGroupBox>
#include <QPushButton>
#include <QSpinBox>
#include <QLayout>
#include <QLabel>

#include "../Report.h"
#include "FStudentScore.h"
#include "CStudentScore.h"
#include "GStudentScore.h"

extern Report rep;

class InsertDialog : public QDialog {
    Q_OBJECT

private:

    QVBoxLayout* mainLayout;
    QVBoxLayout* insertLayout;

    QLabel* nameTitle;
    QLineEdit* nameLine;

    QLabel* stuIDTitle;
    QLineEdit* stuIDLine;

    QLabel* sexTitle;
    QComboBox* sexBox;

    QLabel* ageTitle;
    QSpinBox* ageBox;

    QLabel* typeTitle;
    QComboBox* typeBox;

    QWidget* scoreInputGroup;

    QPushButton* insertScore;

    QHBoxLayout* btnLayout;
    QPushButton* yesBtn;
    QPushButton* cancelBtn;

    CStudentScore* csDialog;
    FStudentScore* fsDialog;
    GStudentScore* gsDialog;

    ScoreMap scores;

    void initUi();
    void initItem();
    void initConnect();


public:

    explicit InsertDialog(QWidget* parent = nullptr);

signals:
    void toCS();
    void toFS();
    void toGS();
    void fleshData();


public slots:
    void toInsert();
    void toInsertScoreMap();
    void getScoreMap(ScoreMap map);
    void addStudent();

};


#endif //STUGPAMANAGER_INSERTDIALOG_H
