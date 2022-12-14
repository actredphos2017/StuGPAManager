//
// Created by sakuno on 22-12-13.
//

#include "GStudentScore.h"

#include <sstream>

template<typename T>
float toFloat(T num){
    float res;
    stringstream ss;
    ss << num;
    ss >> res;
    return res;
}

void GStudentScore::initItem() {
    ScienceTitle = new QLabel("科学");
    DataStructTitle = new QLabel("数据结构");
    AlgorithmTitle = new QLabel("算法");
    MathTitle = new QLabel("数学");
    EnglishTitle = new QLabel("英语");

    scoreTitleLayout = new QVBoxLayout;

    ScienceLine = new QLineEdit();
    DataStructLine = new QLineEdit();
    AlgorithmLine = new QLineEdit();
    MathLine = new QLineEdit();
    EnglishLine = new QLineEdit();

    scoreLineLayout = new QVBoxLayout;
    scoreInputLayout = new QHBoxLayout;
    btnLayout = new QHBoxLayout;
    yesBtn = new QPushButton("确定");
    cancelBtn = new QPushButton("取消");

    scoreTitleLayout->addWidget(ScienceTitle);
    scoreTitleLayout->addWidget(DataStructTitle);
    scoreTitleLayout->addWidget(AlgorithmTitle);
    scoreTitleLayout->addWidget(MathTitle);
    scoreTitleLayout->addWidget(EnglishTitle);

    scoreLineLayout->addWidget(ScienceLine);
    scoreLineLayout->addWidget(DataStructLine);
    scoreLineLayout->addWidget(AlgorithmLine);
    scoreLineLayout->addWidget(MathLine);
    scoreLineLayout->addWidget(EnglishLine);

    scoreInputLayout->addLayout(scoreTitleLayout);
    scoreInputLayout->addLayout(scoreLineLayout);
    btnLayout->addWidget(yesBtn);
    btnLayout->addWidget(cancelBtn);

}

GStudentScore::GStudentScore(QWidget *parent) {
    initItem();
    initUi();
    initConnect();
    setWindowTitle("研究生成绩");
    setWindowModality(Qt::ApplicationModal);
}

void GStudentScore::initUi() {
    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(scoreInputLayout);
    mainLayout->addLayout(btnLayout);
    setLayout(mainLayout);
}

void GStudentScore::toInsertGStuScore() {
    show();
}

void GStudentScore::initConnect() {
    connect(yesBtn, SIGNAL(clicked()), this, SLOT(buildScoreMap()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
}

void GStudentScore::buildScoreMap() {
    ScoreMap map;
    map["science"] = toFloat(ScienceLine->text().toStdString());
    map["english"] = toFloat(EnglishLine->text().toStdString());
    map["math"] = toFloat(MathLine->text().toStdString());
    map["data_struct"] = toFloat(DataStructLine->text().toStdString());
    map["algorithm"] = toFloat(AlgorithmLine->text().toStdString());
    emit scoreMap(map);
    close();
}
