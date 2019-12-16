#include "note.h"

void note::Set_title(QString title)
{
    _title = title;
}

QString note::title() const
{
    return _title;
}

void note::Set_creation_number(int creation_number)
{
    _creation_number = creation_number;
}

int note::creation_number() const
{
    return _creation_number;
}

void note::Set_text(QString text)
{
    _text = text ;
}

QString note::text() const
{
    return _text;
}

note::note(QString title,QString text,int number)
{
    _title = title;
    _text = text;
    _creation_number = number;
}

note::note(const note &obj)
{
    _title = obj._title;
    _text = obj._text;
    _creation_number = obj._creation_number;
}
