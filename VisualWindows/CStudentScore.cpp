//
// Created by sakuno on 22-12-13.
//

#include "CStudentScore.h"

#include <sstream>

template<typename T>
float toFloat(T num){
    float res;
    stringstream ss;
    ss << num;
    ss >> res;
    return res;
}

void CStudentScore::initItem() {
    EnglishTitle = new QLabel("英语");
    MathTitle = new QLabel("数学");
    ComputerTitle = new QLabel("计算机");
    scoreTitleLayout = new QVBoxLayout;
    EnglishLine = new QLineEdit();
    MathLine = new QLineEdit();
    ComputerLine = new QLineEdit();
    scoreLineLayout = new QVBoxLayout;
    scoreInputLayout = new QHBoxLayout;
    btnLayout = new QHBoxLayout;
    yesBtn = new QPushButton("确定");
    cancelBtn = new QPushButton("取消");

    scoreTitleLayout->addWidget(EnglishTitle);
    scoreTitleLayout->addWidget(MathTitle);
    scoreTitleLayout->addWidget(ComputerTitle);
    scoreLineLayout->addWidget(EnglishLine);
    scoreLineLayout->addWidget(MathLine);
    scoreLineLayout->addWidget(ComputerLine);
    scoreInputLayout->addLayout(scoreTitleLayout);
    scoreInputLayout->addLayout(scoreLineLayout);
    btnLayout->addWidget(yesBtn);
    btnLayout->addWidget(cancelBtn);
}

CStudentScore::CStudentScore(QWidget *parent) {
    initItem();
    initUi();
    initConnect();
}

void CStudentScore::initUi() {
    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(scoreInputLayout);
    mainLayout->addLayout(btnLayout);
    setLayout(mainLayout);
}

void CStudentScore::toInsertCStuScore() {
    show();
}

void CStudentScore::initConnect() {
    connect(yesBtn, SIGNAL(clicked()), this, SLOT(buildScoreMap()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
}

void CStudentScore::buildScoreMap() {
    ScoreMap map;
    map["english"] = toFloat(EnglishLine->text().toStdString());
    map["math"] = toFloat(MathLine->text().toStdString());
    map["computer"] = toFloat(ComputerLine->text().toStdString());
    emit scoreMap(map);
    close();
}
