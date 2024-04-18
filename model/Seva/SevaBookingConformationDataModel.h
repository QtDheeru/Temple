#ifndef SEVABOOKINGCONFORMATIONDATAMODEL_H
#define SEVABOOKINGCONFORMATIONDATAMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QDebug>
#include "../SevaName.h"
#include "../Seva/MySevaReceipt.h"
#include "IDataWriter.h"

class SevaBookingConformationDataModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int receiptNumber READ receiptNumber WRITE setReceiptNumber);
    Q_PROPERTY(QString date READ date WRITE setDate);
    Q_PROPERTY(QString sevatime READ sevatime WRITE setSevatime NOTIFY sevatimeChanged)

    Q_PROPERTY(QString mobilenumber READ mobilenumber WRITE setMobilenumber);
    Q_PROPERTY(QString name READ name WRITE setName);
    Q_PROPERTY(QString nakshtra READ nakshtra WRITE setNakshtra);
    Q_PROPERTY(QString gothra READ gothra WRITE setGothra);

    Q_PROPERTY(int bank READ bank WRITE setBank);
    Q_PROPERTY(QString banklist READ banklist WRITE setBanklist);

    Q_PROPERTY(QString note READ note WRITE setNote);
public:
    explicit SevaBookingConformationDataModel(QObject *parent = nullptr);
    enum role{
        Sevaname,
        SevaCharge,
        Count,
        Extracharge,
        Cash,
        Sevadate,
        Sevatime
    };

    int rowCount(const QModelIndex &index)const override;
    QVariant data(const QModelIndex &index,int role)const override;
    virtual QHash<int,QByteArray> roleNames() const override;
   Q_INVOKABLE void init();

    Q_INVOKABLE void addData(
                             int receiptNumber,QString date,QString sevatime,QString mobile,QString name,QString Nakshatra,
                             QString gothra,int bank,QString banklist,QString note
            );

    Q_INVOKABLE void addNewData(QString sevaname,int sevacharges,int count,int extra,int cash,QString sevadate,QString sevatime);

    Q_INVOKABLE void saveReceiptDetails(QString receiptNumber,
                                        QString mobile, QString name, QString nak,
                                        QString gotra);

    Q_INVOKABLE bool saveReceipt(MySevaReceipt *receipt);
    Q_INVOKABLE bool addSeva(SevaName *s);
    Q_INVOKABLE bool deleteSeva(SevaName *s);
    bool removeSeva(int index,QString sevaname);
    Q_INVOKABLE bool reset();
    bool clearSevaList();

    void print();
    void printReceipt();

    const QString &date() const;
    void setDate(const QString &newDate);

    QString mobilenumber() const;
    void setMobilenumber(QString newMobilenumber);

    const QString &name() const;
    void setName(const QString &newName);

    const QString &nakshtra() const;
    void setNakshtra(const QString &newNakshtra);

    const QString &gothra() const;
    void setGothra(const QString &newGothra);

    int bank() const;
    void setBank(int newBank);

    const QString &banklist() const;
    void setBanklist(const QString &newBanklist);

    const QString &note() const;
    void setNote(const QString &newNote);

    int receiptNumber() const;
    void setReceiptNumber(int newReceiptNumber);

    QString receiptNo() const;
    void setReceiptNo(const QString &receiptNo);

    QString reference() const;
    void setReference(const QString &reference);

    QString address() const;
    void setAddress(const QString &address);

    QString momento() const;
    void setMomento(const QString &momento);

    MySevaReceipt *sevaReceipt() const;

    QList<SevaName *> sevabookinglist() const;

    const QString &sevatime() const;
    void setSevatime(const QString &newSevatime);

    void display();
signals:
    void sevatimeChanged();
    void modelChanged(int cost);
private:
    int m_receiptNumber;
    QString m_receiptNo;
    QString m_name;
    QString m_date;
    QString m_sevatime;
    QString m_mobilenumber;
    QString m_nakshtra;
    QString m_gothra;
    QString m_reference;
    QString m_address;
    QString m_receiptDate;
    QString m_momento;
    QString m_bookedBy;

    MySevaReceipt *m_sevaReceipt;
    QList<SevaName*> m_sevabookinglist;   
    int m_bank;
    QString m_banklist;
    QString m_note;
    SevaName *sb;

    QSharedPointer<IDataWriter> m_dataWriter;
};

#endif // SEVABOOKINGCONFORMATIONDATAMODEL_H
