QT += quick widgets sql printsupport xml

CONFIG += c++11
#CONFIG += plugin c++11
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ConfigureApp.cpp \
        DBChecker.cpp \
        SevaViewProxy.cpp \
        Trust.cpp \
        TrustConfiguration.cpp \
        TrustListModel.cpp \
        main.cpp \
        model/BankDetails.cpp \
        model/DBInterface.cpp \
        model/DevotePersnalDetails.cpp \
        model/MomentoCategory.cpp \
        model/MySevaBookingProgressViewModel.cpp \
        model/SevaListViewModel.cpp \
        model/SevaName.cpp \
        model/SevaType.cpp \
        model/SevaTypeViewModel.cpp \
        model/UserManagement.cpp

RESOURCES += qml.qrc
DESTDIR = $$PWD/bins
CONFIG -= app_bundle

RC_ICONS = $$PWD/bins/Config/App.ico
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ConfigureApp.h \
    DBChecker.h \
    SevaViewProxy.h \
    Trust.h \
    TrustConfiguration.h \
    TrustListModel.h \
    model/BankDetails.h \
    model/DBInterface.h \
    model/DevotePersnalDetails.h \
    model/MomentoCategory.h \
    model/MySevaBookingProgressViewModel.h \
    model/SevaListViewModel.h \
    model/SevaName.h \
    model/SevaType.h \
    model/SevaTypeViewModel.h \
    model/UserManagement.h

include(model/Print/Print.pri)
include(model/Seva/seva.pri)
include(model/DataSave/DataSave.pri)
include(model/voucher/voucher.pri)
include(model/DevoteeManager/Devotee.pri)
#Reports integrated for all views
#
