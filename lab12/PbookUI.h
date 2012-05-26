#ifndef PBOOKUI_H
#define PBOOKUI_H

#include <QtGui/QWidget>
#include "ui_PbookUI.h"
#include "controller/ctrl.h"

class PbookUI : public QWidget
{
    Q_OBJECT

public:
    PbookUI(Ctrl* c,QWidget *parent = 0);

    ~PbookUI();

private:
    Ui::PbookUIClass ui;
    Ctrl* c;
    void reloadList(vector<PhNo*> all);
    void makeLinks();
private slots:
	void selectNo();
	void filter();
};

#endif // PBOOKUI_H
