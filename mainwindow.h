#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "note.h"
#include "archive.h"
#include <cstdlib>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using std::vector;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    vector<note> myArchive;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /*
     * return element with such name from given vector
     * if didn't find returns element note("wrong input","error",-1);
     */
    note find_note_by_name(QString name,vector<note> notes);

    void on_actionAdd_triggered();

    void on_actionArchive_triggered();

    void on_Confirm_button_clicked();

    void on_Push_in_archive_button_clicked();

    void on_Show_button_clicked();

private:
    int _count_of_notes;
    vector <note> myNotes;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
