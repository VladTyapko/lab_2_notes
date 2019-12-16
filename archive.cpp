#include "archive.h"
#include "ui_archive.h"
#include <QApplication>
#include "mainwindow.h"

archive::archive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::archive)
{
    ui->setupUi(this);
    archive_list = ui->listWidget;
    connect(this,SIGNAL(aboutToQuit()),this,SLOT(activate_parent()));
}

archive::~archive()
{
    delete ui;
}


