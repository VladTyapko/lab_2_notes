#ifndef NOTE_H
#define NOTE_H
#include <QString>

class note
{
private:
    QString _title;
    QString _text;
    /*
     * number, based on which we will sort our array
     * it says when this node was created in comparing with other notes
     */
    int _creation_number;

public:
    void Set_title(QString title); // setter
    QString title() const; // getter
    void Set_creation_number(int creation_number); // setter
    int creation_number() const; // getter
    void Set_text(QString text); // setter
    QString text() const; // getter
    note(QString title,QString text,int number);
    note(const note &obj);
};

#endif // NOTE_H
