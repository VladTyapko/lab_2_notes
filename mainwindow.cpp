#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->group_widget2->setEnabled(false);
    _count_of_notes = 0;
    ui->title_edit->setPlaceholderText("Your title");
    ui->new_note->setPlaceholderText("Write here:");
}

MainWindow::~MainWindow()
{
    delete ui;
}

note MainWindow::find_note_by_name(QString name,vector<note> notes)
{
    for(const auto &i:notes){
        if(i.title()==name){
            return i;
        }
    }
     return note("wrong input","error",-1);
}


void MainWindow::on_actionAdd_triggered()
{
    ui->group_widget2->setEnabled(true);
}

void MainWindow::on_actionArchive_triggered()
{
    archive *dialogArchive = new archive(this);
    dialogArchive->archiveNotes = myArchive;

    //each archivated note put in the list of created widget
    for(const auto &i:myArchive){
        dialogArchive->archive_list->addItem(i.title());
    }
    dialogArchive->show();

}

void MainWindow::on_Confirm_button_clicked()
{
    if(ui->Confirm_button->text()=="OK"){
        ui->group_widget2->setEnabled(false);
        ui->Confirm_button->setText("Confirm");
        ui->note_list->setEnabled(true);
        ui->title_edit->setReadOnly(true);
        ui->new_note->setReadOnly(true);
        ui->title_edit->clear();
        ui->new_note->clear();
    }
    else{
        myNotes.push_back(note(ui->title_edit->text(),ui->new_note->toPlainText(),_count_of_notes));
        ui->note_list->addItem(myNotes.back().title());
        ui->title_edit->clear();
        ui->new_note->clear();
        ui->group_widget2->setEnabled(false);
    }

}
    /*
     * push to archive and delete from curent list
     */
void MainWindow::on_Push_in_archive_button_clicked()
{
    if(!(ui->note_list->currentRow() == -1)){
        myArchive.push_back(find_note_by_name(ui->note_list->currentItem()->text(),myNotes)); // pushed to myarchive
        myNotes.erase(myNotes.begin()+ui->note_list->currentRow());// deleted from notes
        ui->note_list->takeItem(ui->note_list->currentRow()); // delete from listwidget
    }
}

void MainWindow::on_Show_button_clicked()
{
    if(!(ui->note_list->currentRow() == -1)){
        ui->group_widget2->setEnabled(true);
        ui->note_list->setEnabled(false);
        ui->title_edit->setReadOnly(true);
        ui->new_note->setReadOnly(true);
        ui->title_edit->setText(myNotes[ui->note_list->currentRow()].title());
        ui->new_note->setText(myNotes[ui->note_list->currentRow()].text());
        ui->Confirm_button->setText("OK");
    }
}
