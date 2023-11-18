#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QComboBox>

#include "model/SevaTypeViewModel.h"
#include "model/SevaListViewModel.h"
#include "model/Seva/MySevaReceipt.h"
#include "SevaViewProxy.h"
#include "DBChecker.h"
#include "TrustListModel.h"
#include <QMutex>
#include "SevaCountOnDateModel.h"
#include "SevaDetailsOnDateModel.h"
#include "ReportFilterElements.h"
#include "ConfigureApp.h"
#include "model/voucher/saveVoucher.h"
#include "model/voucher/VoucherElement.h"
#include "model/voucher/VoucherFilterElements.h"
#include "model/voucher/VoucherReportModel.h"
#include "AccountReportMonthRangeElement.h"
#include"BookingReportDateRangeElement.h"
#include"SevaTypeNamesDataModel.h"
#include"SevaBookingConformationDataModel.h"
#include "devoteeproxy.h"
#include "model/BankRegistration_m/cheque_entryModel.h"
#include "model/BankRegistration_m/cashtransaction.h"
#include "VoucherProxy.h"



QScopedPointer<QFile>   m_logFile;
QMutex   mlock;

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);


    QApplication app(argc, argv);
    m_logFile.reset(new QFile("Data/MyLogger.txt"));

    QQmlApplicationEngine engine;

    Cheque_EntryModel checkEntry ;
    CashTransaction myModel;

    engine.rootContext()->setContextProperty("checkEntry",&checkEntry);
    engine.rootContext()->setContextProperty("myModel",&myModel);


    // Open the file logging
    m_logFile.data()->open(QFile::WriteOnly | QFile::Truncate | QFile::Text);
    // Set handler
//    qInstallMessageHandler(messageHandler);


    SevaCountOnDateModel *sevaCountOnDateModel ;
    SevaDetailsOnDateModel *sevaDetailsOnDateModel ;

    qmlRegisterType<SevaName>("Utils",1,0,"SevaName");
    qmlRegisterAnonymousType<SevaType>("SevaType",1);
    qmlRegisterType<MySevaReceipt>("Utils",1,0,"SevaReceipt");
    qmlRegisterType<DevotePersnalDetails>("Utils",1,0,"DevoteDetails");

    qmlRegisterUncreatableType<QAbstractItemModel>("Utils",1,0,"Abc","DontCreate");
    qmlRegisterType<ReportFilterElements>("ReportElements",1,0,"ReportFilterItems");
    qmlRegisterType<VoucherElement>("VoucherElement",1,0,"VouEle");
    qmlRegisterType<SevaBookingElement>("SevaBookingElement",1,0,"SevaBookingEle");
    qmlRegisterType<VoucherFilterElements>("VoucherFilterElement",1,0,"VouFilElem");
    qmlRegisterType<AccountReportDateRangeElement>(" AccountReportDateRangeElement",1,0," AccReportDateRangeElement");
    qmlRegisterType<AccountReportMonthRangeElement>(" AccountReportMonthRangeElement",1,0," AccReportMonthRangeElement");
    qmlRegisterType<BookingReportDateRangeElement>("BookingReportDateRangeElement",1,0," BookingReportDateRangeElement");
    qmlRegisterType<BookingReportMonthRangeElement>(" BookingReportMonthRangeElement",1,0," BookingReportMonthRangeElement");
    qmlRegisterType<SevaTypeNamesDataModel>("SevaTypeNamesDataModel",1,0,"SevaTypeNamesDataModel");
    qmlRegisterType<SevaBookingConformationDataModel>("SevaBookingConformationDataModel",1,0,"SevaBookingConformationDataModel");
    SevaViewProxy *proxy ;
    DevoteeProxy *devoteeProxy;
    SevaListViewModel *sevaModel ;
    DBChecker *dbchecker ;
    ConfigureApp *confApp;
    saveVoucher *vou;
    VoucherProxy voucherProxy;
    VoucherReportModel *vouRepModel;

    TrustListModel* trustListModel = TrustListModel::getTrustListModelInstance();
    engine.rootContext()->setContextProperty("trustListModel",trustListModel);

    confApp = ConfigureApp::getInstance();
    engine.rootContext()->setContextProperty("confApp",confApp);

    QObject::connect(trustListModel,&TrustListModel::currentConfigLocationChanged,
                     [&](){qDebug()<<"Inside lamda"<<Qt::endl;
    });

    QObject::connect(trustListModel,&TrustListModel::currentDataLocationChanged,
                     [&](){qDebug()<<"Inside lamda"<<Qt::endl;
        //Raj //configure app
        confApp->setAppPath(trustListModel->getConfigLocation());
        confApp->loadXMLFile();

        //
        sevaModel= new SevaListViewModel;
        dbchecker = new DBChecker;
        proxy = new SevaViewProxy;
        sevaCountOnDateModel = new SevaCountOnDateModel;
        sevaDetailsOnDateModel = new SevaDetailsOnDateModel;
        vou = new saveVoucher;
        vouRepModel = new VoucherReportModel;
        devoteeProxy = new DevoteeProxy;
        engine.rootContext()->setContextProperty("voucherProxy",&voucherProxy);
        engine.rootContext()->setContextProperty("sevaProxy",proxy);
        engine.rootContext()->setContextProperty("devoteeProxy",devoteeProxy);
        //    engine.rootContext()->setContextProperty("sevaTypeModel",mod);
        engine.rootContext()->setContextProperty("sevaDateCount",sevaCountOnDateModel);
        engine.rootContext()->setContextProperty("sevaDetailsonDateCount",sevaDetailsOnDateModel);
        engine.rootContext()->setContextProperty("sevaListModel",sevaModel);
        engine.rootContext()->setContextProperty("saveVoucher",vou);
        engine.rootContext()->setContextProperty("voucherReportModel",vouRepModel);


        engine.rootContext()->setContextProperty("dbchecker",dbchecker);});
    const QUrl url(QStringLiteral("qrc:/ui/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    mlock.lock();
    // Open stream file writes
    QTextStream out(m_logFile.data());
    // Write the date of recording
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");

    // By type determine to what level belongs message
    switch (type)
    {
    case QtInfoMsg:     out << "INF "; break;
    case QtDebugMsg:    out << "DBG "; break;
    case QtWarningMsg:  out << "WRN "; break;
    case QtCriticalMsg: out << "CRT "; break;
    case QtFatalMsg:    out << "FTL "; break;
    }

    // Write to the output category of the message and the message itself
    out << context.category << ": "<< msg << Qt::endl;
    out.flush();    // Clear the buffered data
    mlock.unlock();
}

