//
// Created by sakuno on 22-12-13.
//

#ifndef STUGPAMANAGER_INSERTDIALOG_H
#define STUGPAMANAGER_INSERTDIALOG_H


#include <QDialog>
#include <QComboBox>
#include <QGroupBox>
#include <QSpinBox>
#include <QLayout>

class InsertDialog : public QDialog {
private:

    QComboBox* typeChoose;

    QLineEdit* nameLine;
    QLineEdit* stuIDLine;
    QComboBox* sexBox;
    QSpinBox* ageBox;

    QGroupBox* scoreInputGroup;

    QVBoxLayout* CStudentLayout;
    QLineEdit* csEnglishLine;
    QLineEdit* csMathLine;
    QLineEdit* csComputerLine;

    QVBoxLayout* FStudentLayout;
    QLineEdit* fsChineseLine;
    QLineEdit* fsMathLine;
    QLineEdit* fsComputerLine;

    QVBoxLayout* GStudentLayout;
    QLineEdit* gsMathLine;
    QLineEdit* gsScienceLine;
    QLineEdit* gsDataStructLine;
    QLineEdit* gsAlgorithmLine;


    void initItem();
    void initConnect();

public:

    InsertDialog(QWidget* parent = nullptr);

};


#endif //STUGPAMANAGER_INSERTDIALOG_H
