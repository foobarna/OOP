#ifndef HEKIL_H
#define HEKIL_H

#include <QtGui/QWidget>
#include "ui_hekil.h"

#include "controller/MovieRental.h"

using namespace controller;

class hekil : public QWidget
{
    Q_OBJECT

public:
    hekil(MovieRental* r,QWidget *parent = 0);
    ~hekil();

private:
    Ui::hekilClass ui;
    MovieRental* r;
    void updateListMovie();
    void linkSlots();

private slots:
	void saveMovie();
	void selectMovie();
	void deleteMovie();
	void updateMovie();

};

#endif // HEKIL_H
