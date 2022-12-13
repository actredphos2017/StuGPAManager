//
// Created by sakuno on 22-12-13.
//

#include "InsertDialog.h"

#include <utility>
#include <sstream>

template<typename T>
int toInt(T val){
    int res;
    stringstream ss;
    ss << val;
    ss >> res;
    return res;
}

InsertDialog::InsertDialog(QWidget *parent):
    QDialog(parent){
    initUi();
    initItem();
    initConnect();
}

void InsertDialog::toInsert() {
    this->show();
}

void InsertDialog::initUi() {
    mainLayout = new QVBoxLayout;
    {
        insertLayout = new QVBoxLayout;
        {
            auto basicInfo = new QHBoxLayout;
            {
                auto BasicTitleLayout = new QVBoxLayout;
                {
                    nameTitle = new QLabel("姓名");
                    BasicTitleLayout->addWidget(nameTitle);

                    stuIDTitle = new QLabel("学号");
                    BasicTitleLayout->addWidget(stuIDTitle);

                    sexTitle = new QLabel("性别");
                    BasicTitleLayout->addWidget(sexTitle);

                    ageTitle = new QLabel("年龄");
                    BasicTitleLayout->addWidget(ageTitle);

                    typeTitle = new QLabel("类型");
                    BasicTitleLayout->addWidget(typeTitle);
                }
                basicInfo->addLayout(BasicTitleLayout);

                auto BasicInsertLayout = new QVBoxLayout;
                {
                    nameLine = new QLineEdit;
                    BasicInsertLayout->addWidget(nameLine);

                    stuIDLine = new QLineEdit;
                    BasicInsertLayout->addWidget(stuIDLine);

                    sexBox = new QComboBox;
                    BasicInsertLayout->addWidget(sexBox);

                    ageBox = new QSpinBox;
                    BasicInsertLayout->addWidget(ageBox);

                    typeBox = new QComboBox;
                    BasicInsertLayout->addWidget(typeBox);
                }
                basicInfo->addLayout(BasicInsertLayout);
            }
            insertLayout->addLayout(basicInfo);
            insertScore = new QPushButton("输入成绩");
            insertLayout->addWidget(insertScore);
        }
        mainLayout->addLayout(insertLayout);

        btnLayout = new QHBoxLayout;
        {
            yesBtn = new QPushButton("添加");
            btnLayout->addWidget(yesBtn);

            cancelBtn = new QPushButton("取消");
            btnLayout->addWidget(cancelBtn);
        }
        mainLayout->addLayout(btnLayout);
    }
    setLayout(mainLayout);
}

void InsertDialog::initItem() {
    sexBox->addItem("男");
    sexBox->addItem("女");
    ageBox->setMaximum(60);
    ageBox->setMinimum(1);
    ageBox->setValue(18);
    typeBox->addItem("本科生");
    typeBox->addItem("留学生");
    typeBox->addItem("研究生");
    csDialog = new CStudentScore;
    fsDialog = new FStudentScore;
    gsDialog = new GStudentScore;
}

void InsertDialog::initConnect() {
    connect(insertScore, SIGNAL(clicked()), this, SLOT(toInsertScoreMap()));
    connect(this, SIGNAL(toCS()), csDialog, SLOT(toInsertCStuScore()));
    connect(this, SIGNAL(toFS()), fsDialog, SLOT(toInsertFStuScore()));
    connect(this, SIGNAL(toGS()), gsDialog, SLOT(toInsertGStuScore()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
    connect(csDialog, SIGNAL(scoreMap(ScoreMap)), this, SLOT(getScoreMap(ScoreMap)));
    connect(fsDialog, SIGNAL(scoreMap(ScoreMap)), this, SLOT(getScoreMap(ScoreMap)));
    connect(gsDialog, SIGNAL(scoreMap(ScoreMap)), this, SLOT(getScoreMap(ScoreMap)));
    connect(yesBtn, SIGNAL(clicked()), this, SLOT(addStudent()));
}

void InsertDialog::toInsertScoreMap() {
    if(typeBox->currentText() == "本科生")
        emit toCS();
    else if(typeBox->currentText() == "留学生")
        emit toFS();
    else if(typeBox->currentText() == "研究生")
        emit toGS();
}

void InsertDialog::getScoreMap(ScoreMap map) {
    scores = std::move(map);
}

void InsertDialog::addStudent() {
    if(typeBox->currentText() == "本科生")
        rep.insert(new CStudent(
                stuIDLine->text().toStdString(),
                nameLine->text().toStdString(),
                ageBox->value(),
                (sexBox->currentText() == "男" ? 'm' : (sexBox->currentText() == "女" ? 'w' : '\0')),
                scores
                ));
    else if(typeBox->currentText() == "留学生")
        rep.insert(new FStudent(
                stuIDLine->text().toStdString(),
                nameLine->text().toStdString(),
                ageBox->value(),
                (sexBox->currentText() == "男" ? 'm' : (sexBox->currentText() == "女" ? 'w' : '\0')),
                scores
        ));
    else if(typeBox->currentText() == "研究生")
        rep.insert(new GStudent(
                stuIDLine->text().toStdString(),
                nameLine->text().toStdString(),
                ageBox->value(),
                (sexBox->currentText() == "男" ? 'm' : (sexBox->currentText() == "女" ? 'w' : '\0')),
                scores
        ));
    emit fleshData();
}
