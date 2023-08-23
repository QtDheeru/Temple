#ifndef CHEQUE_ENTRYMODEL_H
#define CHEQUE_ENTRYMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QDebug>
#include "model/BankRegistration_m/cheque_entry_data.h"
#include "model/DBInterface.h"

//#include <chequeentrydb.h>

enum selection{
    RECEIPT_DATE=0 , CHECK_DATE , BANK , RECEIPT_NUMBER , AMOUNT
};

class Cheque_EntryModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit Cheque_EntryModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    // QAbstractItemModel interface
    QHash<int, QByteArray> roleNames() const;
    QList <Cheque_Entry_Data *> m_checklist;
    QList<int > m_listOfNumToAddDB;


    QList<Cheque_Entry_Data *> checklist() const;
    void setChecklist(const QList<Cheque_Entry_Data *> &newChecklist);

    QList<int> listOfNumToAddDB() const;
    void setListOfNumToAddDB(const QList<int> &newListOfNumToAddDB);

public slots:
    void addtoListMain(QString bankname,QString receiptNumber, QString receiptDate, QString amount, QString chequeDate);
    void addToList(int );
    void removeFromList(int );
    void submitToBank();
    void emptyList();
    void removeDbAddedElementsFromList();
    void onClearChequeList();

    void fetchFromDataBase();

signals:
    void checklistChanged();
    void addedToDataBase();
    void listOfNumToAddDBChanged();

private:
//    ChequeEntryDB *chequeEntry_DB;
//    DBInterface *dbInterface;
};

#endif // CHEQUE_ENTRYMODEL_H
