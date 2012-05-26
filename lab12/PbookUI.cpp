#include "PbookUI.h"
#include <iostream>

using namespace std;

PbookUI::PbookUI(Ctrl* c,QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	this->c = c;
	makeLinks();
	reloadList(c->getAll());
}

PbookUI::~PbookUI()
{

}

void PbookUI::makeLinks(){
	QObject::connect(ui.list, SIGNAL(itemSelectionChanged()), this,SLOT(selectNo()));
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(filter()));
}

void PbookUI::reloadList(vector<PhNo*> all){
	ui.list->clear();
	for(unsigned int i=0; i < all.size();i++){
		string name = all[i]->getName();
		QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(name), ui.list);
		item->setData(Qt::UserRole, QVariant::fromValue(i));
	}
}

void PbookUI::selectNo(){
	QList<QListWidgetItem*> sel = ui.list->selectedItems();
	if (sel.size() == 0) {
			return;
	}
	QListWidgetItem *item = sel.at(0);
	QString qName = item->text();
	string name = qName.toStdString();
	PhNo* p = c->findByName(name);
	ui.lineEdit->setText(QString::fromStdString(p->getName()));
	ui.lineEdit_2->setText(QString::fromStdString(p->getNo()));
	ui.lineEdit_3->setText(QString::fromStdString(p->getCity()));
}

void PbookUI::filter(){
	vector<PhNo*> all,f;
	string s = ui.lineEdit_4->text().toStdString();
	cout<<s<<endl;
	f = c->getFilter(s);
	cout<<f.size()<<endl;
	all = c->getAll();
	reloadList(f);
}
