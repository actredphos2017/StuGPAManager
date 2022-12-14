//
// Created by sakuno on 22-12-12.
//


#include <QFileDialog>
#include <QMessageBox>
#include <QMenu>
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

QString getSexName(char c){
    return (c == 'w' ? "女" : (c == 'm' ? "男" : "未知"));
}




Menu::Menu(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Menu){
    ui->setupUi(this);

    initItem();
    initConnect();

    setWindowTitle("学生成绩管理系统");
}


Menu::~Menu() {
    delete ui;
}

void Menu::fleshData() {

    delete tempRep;
    tempRep = nullptr;
    if(!ui->search->text().isEmpty())
        tempRep = new Report(rep.findName(ui->search->text().toStdString()));

    showSingleType = (ui->typeChooose->currentText() != tr("全部"));

    if(showSingleType){
        if(tempRep == nullptr)
            tempRep = new Report(rep[rStuTypeChangeMap[ui->typeChooose->currentText()]]);
        else
            tempRep = new Report((*tempRep)[rStuTypeChangeMap[ui->typeChooose->currentText()]]);
    }

    Report* targetReport = (tempRep == nullptr ? &rep : tempRep);

    stringstream ss;
    ss << "平均绩点 ";
    if(!targetReport->size())
        ss << "无";
    else
        ss << targetReport->advPoint();
    vector<Student*> highestStu = targetReport->highestPointer();
    ss << "  最高绩点 ";
    if(highestStu.empty())
        ss << "无";
    else
        for(auto it : highestStu){
            stringstream tempSs;
            tempSs << it->name << ' ' << it->get_point() << "  ";
            if(tempSs.str().size() + ss.str().size() <= 70)
                ss << tempSs.str();
            else{
                ss << "...";
                break;
            }
        }

    ui->sumInfo->setText(ss.str().c_str());

    ui->status->setText("当前库中共有 " + toQString(targetReport->size()) + " 条数据");

    if(!ui->showDetails->isChecked()){

        ui->table->clear();

        ui->table->setRowCount(targetReport->size());

        QStringList hList;
        hList << "学号" << "姓名" << "类型" << "性别" << "年龄" << "绩点";
        ui->table->setColumnCount(hList.size());
        ui->table->setHorizontalHeaderLabels(hList);
        for(int i = 0; i < hList.size(); i ++)
            ui->table->setColumnWidth(i,targetReport->size());

        int rowI = 0;
        for(auto it : targetReport->students){
            ui->table->setItem(rowI, 0, new QTableWidgetItem(it->stuID.c_str()));
            ui->table->setItem(rowI, 1, new QTableWidgetItem(it->name.c_str()));
            ui->table->setItem(rowI, 2, new QTableWidgetItem(stuTypeChangeMap[it->type]));
            ui->table->setItem(rowI, 3, new QTableWidgetItem(getSexName(it->sex)));
            ui->table->setItem(rowI, 4, new QTableWidgetItem(toQString(it->age)));
            ui->table->setItem(rowI, 5, new QTableWidgetItem(toQString(it->get_point())));
            rowI ++;
        }
    }else{
        if(showSingleType){
            if(tempRep == nullptr)
                return;
            if(ui->typeChooose->currentText() == tr("本科生")){
                ui->table->clear();
                ui->table->setRowCount(targetReport->size());
                QStringList hList;
                hList << "学号" << "姓名" << "性别" << "年龄" << "英语" << "数学" << "计算机";
                ui->table->setColumnCount(hList.size());
                ui->table->setHorizontalHeaderLabels(hList);
                for(int i = 0; i < hList.size(); i ++)
                    ui->table->setColumnWidth(i,targetReport->size());

                int rowI = 0;
                for(auto it : targetReport->students){
                    ui->table->setItem(rowI, 0, new QTableWidgetItem(it->stuID.c_str()));
                    ui->table->setItem(rowI, 1, new QTableWidgetItem(it->name.c_str()));
                    ui->table->setItem(rowI, 2, new QTableWidgetItem(getSexName(it->sex)));
                    ui->table->setItem(rowI, 3, new QTableWidgetItem(toQString(it->age)));
                    ui->table->setItem(rowI, 4, new QTableWidgetItem(toQString(it->scores["english"])));
                    ui->table->setItem(rowI, 5, new QTableWidgetItem(toQString(it->scores["math"])));
                    ui->table->setItem(rowI, 6, new QTableWidgetItem(toQString(it->scores["computer"])));
                    rowI ++;
                }
            }else if(ui->typeChooose->currentText() == tr("留学生")){
                ui->table->clear();
                ui->table->setRowCount(targetReport->size());
                QStringList hList;
                hList << "学号" << "姓名" << "性别" << "年龄" << "语文" << "数学" << "计算机";
                ui->table->setColumnCount(hList.size());
                ui->table->setHorizontalHeaderLabels(hList);
                for(int i = 0; i < hList.size(); i ++)
                    ui->table->setColumnWidth(i,targetReport->size());

                int rowI = 0;
                for(auto it : targetReport->students){
                    ui->table->setItem(rowI, 0, new QTableWidgetItem(it->stuID.c_str()));
                    ui->table->setItem(rowI, 1, new QTableWidgetItem(it->name.c_str()));
                    ui->table->setItem(rowI, 2, new QTableWidgetItem(getSexName(it->sex)));
                    ui->table->setItem(rowI, 3, new QTableWidgetItem(toQString(it->age)));
                    ui->table->setItem(rowI, 4, new QTableWidgetItem(toQString(it->scores["chinese"])));
                    ui->table->setItem(rowI, 5, new QTableWidgetItem(toQString(it->scores["math"])));
                    ui->table->setItem(rowI, 6, new QTableWidgetItem(toQString(it->scores["computer"])));
                    rowI ++;
                }
            }else if(ui->typeChooose->currentText() == tr("研究生")){
                ui->table->clear();
                ui->table->setRowCount(targetReport->size());
                QStringList hList;
                hList << "学号" << "姓名" << "性别" << "年龄" << "科学" << "数据" << "算法" << "英语" << "数学";
                ui->table->setColumnCount(hList.size());
                ui->table->setHorizontalHeaderLabels(hList);
                for(int i = 0; i < hList.size(); i ++)
                    ui->table->setColumnWidth(i,targetReport->size());

                int rowI = 0;
                for(auto it : targetReport->students){
                    ui->table->setItem(rowI, 0, new QTableWidgetItem(it->stuID.c_str()));
                    ui->table->setItem(rowI, 1, new QTableWidgetItem(it->name.c_str()));
                    ui->table->setItem(rowI, 2, new QTableWidgetItem(getSexName(it->sex)));
                    ui->table->setItem(rowI, 3, new QTableWidgetItem(toQString(it->age)));
                    ui->table->setItem(rowI, 4, new QTableWidgetItem(toQString(it->scores["science"])));
                    ui->table->setItem(rowI, 5, new QTableWidgetItem(toQString(it->scores["data_struct"])));
                    ui->table->setItem(rowI, 6, new QTableWidgetItem(toQString(it->scores["algorithm"])));
                    ui->table->setItem(rowI, 7, new QTableWidgetItem(toQString(it->scores["english"])));
                    ui->table->setItem(rowI, 8, new QTableWidgetItem(toQString(it->scores["math"])));
                    rowI ++;
                }
            }
        }else{
            QMessageBox::information(this, "提示", "需筛选学生类型才能显示具体信息！");
            return;
        }
    }

}

void Menu::initItem() {
    stuTypeChangeMap[COLLEGE] = "本科生";
    stuTypeChangeMap[FOREIGN] = "留学生";
    stuTypeChangeMap[GRADUATE] = "研究生";
    rStuTypeChangeMap["本科生"] = COLLEGE;
    rStuTypeChangeMap["留学生"] = FOREIGN;
    rStuTypeChangeMap["研究生"] = GRADUATE;

    ui->typeChooose->addItem(tr("全部"));
    ui->typeChooose->addItem(tr("本科生"));
    ui->typeChooose->addItem(tr("留学生"));
    ui->typeChooose->addItem(tr("研究生"));

    ui->table->horizontalHeader()->setStretchLastSection(true);
    ui->table->setContextMenuPolicy(Qt::CustomContextMenu);

    ui->typeChooose->setCurrentText(tr("全部"));
    ui->search->setPlaceholderText(tr("搜索学生名字……"));

    insertDialog = new InsertDialog(this);

    fleshData();
}

void Menu::initConnect() {
    connect(ui->inputBtn, SIGNAL(clicked()), this, SLOT(inputFile()));
    connect(ui->outputBtn, SIGNAL(clicked()), this, SLOT(outputFile()));
    connect(ui->yesBtn, SIGNAL(clicked()), this, SLOT(fleshData()));
    connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui->showDetails, SIGNAL(clicked()), this, SLOT(fleshData()));
    connect(ui->delBtn, SIGNAL(clicked()), this, SLOT(delData()));
    connect(ui->addBtn, SIGNAL(clicked()), insertDialog, SLOT(toInsert()));
    connect(insertDialog, SIGNAL(fleshData()), this, SLOT(fleshData()));
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
    Report _rep;
    _rep.read(iF);
    iF.close();
    rep.insert(_rep);
    fileName = prepareFile;
    fleshData();
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
    fleshData();
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
    fleshData();
}

void Menu::delData() {
    if(ui->table->currentRow() == -1)
        return;
    int delLoc = ui->table->currentRow();
    Report* targetReport = (tempRep == nullptr ? &rep : tempRep);
    auto it = targetReport->students.begin();
    while(delLoc --)
        it ++;
    rep.remove(*it);
    fleshData();
}
