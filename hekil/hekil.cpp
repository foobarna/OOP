#include "hekil.h"
#include <vector>
#include <qlabel.h>
#include <string>
#include <qmessagebox.h>
#include <qlistwidget.h>
#include "domain/Exceptions.h"

using namespace controller;
using namespace domain;

hekil::hekil(MovieRental* r,QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	this->r = r;
	linkSlots();
	updateListMovie();
}

hekil::~hekil()
{

}

void hekil::linkSlots(){
	QObject::connect(ui.saveBtn,SIGNAL(clicked()), this, SLOT(saveMovie()));
	QObject::connect(ui.listMovie, SIGNAL(itemSelectionChanged()), this,SLOT(selectMovie()));
	QObject::connect(ui.delBtn, SIGNAL(clicked()), this, SLOT(deleteMovie()));
	QObject::connect(ui.upBtn, SIGNAL(clicked()), this, SLOT(updateMovie()));
}

void hekil::updateListMovie(){
	ui.listMovie->clear();
	vector<Movie*> all = r->getAllMovies();
	for(int i=0; i < all.size();i++){
		string desc = all[i]->getTitle();
		QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(desc), ui.listMovie);
		item->setData(Qt::UserRole, QVariant::fromValue(i));
	}
}

void hekil::saveMovie(){
	string title = ui.mTitle->text().toStdString();
	string type = ui.mType->text().toStdString();
	string desc = ui.mDesc->text().toStdString();
	bool available = ui.mAv->text().toInt();
	try{
		r->addNewMovie(title,type,desc,available);
		updateListMovie();
		QMessageBox::information(this, "Info", "Movie stored!");
	} catch(MyException ex){
		QMessageBox::critical(this, "Error",QString::fromStdString(ex.getMessage()));
	}

};
void hekil::selectMovie(){
	QList<QListWidgetItem*> sel = ui.listMovie->selectedItems();
	if (sel.size() == 0) {
		return;
	}
	QListWidgetItem *item = sel.at(0);
	QString qtitle = item->text();
	string title = qtitle.toStdString();
	Movie *m = r->searchMovie(title);
	ui.mTitle->setText(QString::fromStdString(title));
	ui.mType->setText(QString::fromStdString(m->getType()));
	ui.mDesc->setText(QString::fromStdString(m->getDesc()));
	ui.mAv->setText(QString::number(m->getAvailable()));

};
void hekil::deleteMovie(){
	QList<QListWidgetItem*> sel = ui.listMovie->selectedItems();
		if (sel.size() == 0) {
			return;
		}
	QListWidgetItem *item = sel.at(0);
	QString qtitle = item->text();
	string title = qtitle.toStdString();
	r->removeMovie(title);
	updateListMovie();
};

void hekil::updateMovie(){
	QList<QListWidgetItem*> sel = ui.listMovie->selectedItems();
	if (sel.size() == 0) {
		return;
	}
	QListWidgetItem *item = sel.at(0);
	QString qtitle = item->text();
	string title = qtitle.toStdString();
	try{
		r->updateMovieType(title,ui.mType->text().toStdString());
		r->updateMovieDesc(title,ui.mDesc->text().toStdString());
		r->updateMovieAvailable(title,ui.mAv->text().toInt());
		QMessageBox::information(this, "Info", "Movie updated!");
		updateListMovie();
	} catch (MyException ex){
		QMessageBox::critical(this, "Error",QString::fromStdString(ex.getMessage()));
	}
}
