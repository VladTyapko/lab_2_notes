#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <QDialog>
#include <QListWidget>
#include "note.h"
#include <vector>

using std::vector;

namespace Ui {
class archive;
}

class archive : public QDialog
{
    Q_OBJECT

public:
    vector<note> archiveNotes;
    QListWidget *archive_list;
    explicit archive(QWidget *parent = nullptr);
    ~archive();

private:
    Ui::archive *ui;
};

#endif // ARCHIVE_H
