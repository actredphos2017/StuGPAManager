//
// Created by sakuno on 22-12-12.
//


#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include "Menu.h"
#include "ui_Menu.h"

extern Report rep;

template<typename T>
QString toQString(T item){
    stringstream ss;
    ss << item;
    QString res = ss.str().c_str();
    return res;
}

string getFileName(const string& fullDirName){
    stringstream ss;
    for(const char& it : fullDirName){
        ss << it;
        if(it == '/' || it == '\\')
            ss.clear();
    }
    return ss.str();
}

string getFileType(const string& fullDirName){
    string fileName = getFileName(fullDirName);
    bool isContent = false;
    stringstream ss;
    for(const char& it : fileName){
        if(isContent)
            ss << it;
        if(it == '.'){
            isContent = true;
            ss.clear();
        }
    }
    return ss.str();
}




Menu::Menu(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Menu){
    ui->setupUi(this);

    initItem();
    initConnect();
}


Menu::~Menu() {
    delete ui;
}

void Menu::flashData() {
    ui->table->setRowCount(rep.size());

    QStringList hList;
    hList << "学号" << "姓名" << "类型" << "性别" << "年龄" << "绩点";
    ui->table->setColumnCount(hList.size());
    ui->table->setHorizontalHeaderLabels(hList);
    for(int i = 0; i < hList.size(); i ++)
        ui->table->setColumnWidth(i,rep.size());
    ui->table->horizontalHeader()->setStretchLastSection(true);
    ui->table->setContextMenuPolicy(Qt::CustomContextMenu);

    int rowI = 0;
    for(auto it : rep.students){
        qDebug() << stuTypeChangeMap[it->type];
        ui->table->setItem(rowI, 0, new QTableWidgetItem(it->stuID.c_str()));
        ui->table->setItem(rowI, 1, new QTableWidgetItem(it->name.c_str()));
        ui->table->setItem(rowI, 2, new QTableWidgetItem(stuTypeChangeMap[it->type]));
        ui->table->setItem(rowI, 3, new QTableWidgetItem(toQString(it->sex == 'w' ? "女" : "男")));
        ui->table->setItem(rowI, 4, new QTableWidgetItem(toQString(it->age)));
        ui->table->setItem(rowI, 5, new QTableWidgetItem(toQString(it->get_point())));
    }
}

void Menu::initItem() {
    stuTypeChangeMap[COLLEGE] = "本科生";
    stuTypeChangeMap[FOREIGN] = "留学生";
    stuTypeChangeMap[GRADUATE] = "研究生";

    ui->typeChooose->addItem(tr("全部"));
    ui->typeChooose->addItem(tr("本科生"));
    ui->typeChooose->addItem(tr("留学生"));
    ui->typeChooose->addItem(tr("研究生"));

    ui->typeChooose->setCurrentText(tr("全部"));
    ui->search->setPlaceholderText(tr("搜索学生名字……"));

    flashData();
}

void Menu::initConnect() {
    connect(ui->inputBtn, SIGNAL(clicked()), this, SLOT(inputFile()));
    connect(ui->outputBtn, SIGNAL(clicked()), this, SLOT(outputFile()));
    connect(ui->yesBtn, SIGNAL(clicked()), this, SLOT(searchName()));
    connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(save()));

}

void Menu::inputFile() {
    QString prepareFile = QFileDialog::getOpenFileName(this,"文件目录",QDir::homePath(),(QString)"交换文件 (*.json);;所有文件 (*)");
    if(prepareFile.isEmpty())
        return;
    ifstream iF;
    iF.open(prepareFile.toStdString());
    if(!iF.good()){
        iF.close();
        QMessageBox::information(this, "提示", "读取失败");
        return;
    }
    rep.read(iF);
    iF.close();
    fileName = prepareFile;
    flashData();
}

void Menu::outputFile() {
    QString prepareFile = QFileDialog::getSaveFileName(this,"文件保存目录",QDir::homePath(),(QString)"交换文件 (*.json);;所有文件 (*)");
    if(prepareFile.isEmpty())
        return;
    if(getFileType(prepareFile.toStdString()).empty())
        prepareFile += ".json";
    ofstream oF;
    oF.open(prepareFile.toStdString());
    if(!oF.good()){
        oF.close();
        QMessageBox::information(this, "提示", "保存失败");
        return;
    }
    rep.write(oF);
    oF.close();
    fileName = prepareFile;
    flashData();
}

void Menu::save() {
    if(fileName.isEmpty())
        return;
    ofstream oF;
    oF.open(fileName.toStdString());
    if(!oF.good()){
        oF.close();
        QMessageBox::information(this, "提示", "保存失败");
        return;
    }
    rep.write(oF);
    oF.close();
    flashData();
}

void Menu::searchName() {}