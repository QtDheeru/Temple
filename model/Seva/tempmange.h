#ifndef TEMPMANGE_H
#define TEMPMANGE_H
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include<QObject>
#include "seva_type.h"
#include "TableViewType.h"
#include"TableViewSeva.h"
#include "dbfile.h"
#include"mainscreen.h"
#include"addnewseva.h"
#include "hedderforprintreceipt.h"
#include<QScreen>
class Tempmange : public QWidget
{
    Q_OBJECT
public:
    explicit Tempmange(QWidget *parent = nullptr);
    QHBoxLayout *h1,*h2,*h3;
    QVBoxLayout *v1;

    addnewseva *add;
    mainScreen *m;
    seva_type *w;
    TableViewType *table_type ;
    TableViewSeva *table_seva;
    dbfile *db;
    hedderForPrintReceipt *hedder;
    void t_mange(QString);
    void paintEvent(QPaintEvent *event);
    ~Tempmange();
signals:

public slots:
};


#endif // TEMPMANGE_H
