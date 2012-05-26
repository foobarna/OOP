#include "PbookUI.h"

#include <QtGui>
#include <QApplication>

#include "domain/testPhNo.h"
#include "repository/repo.h"
#include "controller/ctrl.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
     * run the tests
     */
    testPhNo* t=new testPhNo();
    t->runTest();

    Repo* r = new Repo("info.txt");
    cout<<r->getSize()<<endl;
    assert(r->getSize()==3);
    Ctrl* c = new Ctrl(r);
    vector<PhNo*> v;
    v = c->getAll();
    cout<<v.size()<<endl;

    PbookUI w(c);

    w.show();
    return a.exec();
}
