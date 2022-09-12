#ifndef SEVATYPENAMESVIEWMODEL_H
#define SEVATYPENAMESVIEWMODEL_H

#include <QObject>
#include <QMap>
#include <QDebug>
#include "../common.h"
#include "../DBInterface.h"
#include "../SevaType.h"
#include "ISevaReceiptNumberInterface.h"
#include "SevaReceiptNumber.h"
#include "../MySevaBookingProgressViewModel.h"
#include "SevaBookingConformationDataModel.h"
#include "./model/Seva/MySevaReceipt.h"
#include "./model/DevotePersnalDetails.h"

class SevaTypeNamesDataModel : public QObject
{
    Q_OBJECT
public:
    explicit SevaTypeNamesDataModel(QObject *parent = nullptr);
    ~SevaTypeNamesDataModel();
    static SevaTypeNamesDataModel* self();

    bool querySevaTypes();
    bool querySevaNames();
    QList<SevaName*> getSevaList(int sevaType);


    bool processSevaNames(SevaName *);
    QList<SevaType*> getSevaTypes();
    SevaName* getSevaDetails(int sevaType, int sevaId);
    bool printSevaDetails(int sevaType, int sevaId);

    bool saveReceiptDetails(QString recNumber, QString devName, QString mobNumber, QString nakshatra, QString gothra);
    bool saveReceipt(MySevaReceipt *receipt);
    bool addSevaOnly(SevaName *s);

    QStringList getNakshatras();
    QStringList getGothras();
    QStringList getBankList();
    QString     getNextReceiptNumber();

    DevotePersnalDetails* searchMobile(QString mobile);

    MySevaBookingProgressViewModel *getSevaBookingProgress() const;
    bool resetBookingProgressModel();

    bool printReceipt();
    bool deleteSeva(SevaName *s);

public slots:
    bool processSevaTypes(SevaType *);
signals:

private :
    void connectSignals();

private :
    static SevaTypeNamesDataModel* _instance;
    QMap<int, SevaType*> m_sevaTypeDetails;
    QMap<int, QMap<int, SevaName*> > m_sevaNameDetails;

    ISevaReceiptNumberInterface *m_receiptGenerator;
    MySevaBookingProgressViewModel *m_sevaBookingProgress;
    SevaBookingConformationDataModel *m_sevaBookingModel;
};

#endif // SEVATYPENAMESVIEWMODEL_H
