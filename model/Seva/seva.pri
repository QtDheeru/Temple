INCLUDEPATH += $$PWD
HEADERS += \
    $$PWD/GotraModel.h \
    $$PWD/ISevaReceiptNumberInterface.h \
    $$PWD/MySevaReceipt.h \
    $$PWD/NakshatraModel.h \
    $$PWD/SevaBookingConformationDataModel.h \
    $$PWD/SevaReceiptNumber.h \
    $$PWD/SevaTypeNamesDataModel.h


SOURCES += \
    $$PWD/GotraModel.cpp \
    $$PWD/MySevaReceipt.cpp \
    $$PWD/NakshatraModel.cpp \
    $$PWD/SevaBookingConformationDataModel.cpp \
    $$PWD/SevaReceiptNumber.cpp \
    $$PWD/SevaTypeNamesDataModel.cpp

include(./SevaJson/SevaJson.pri)
include(../Reports/Reports.pri)
include(../ProfitAndLoss/ProfitAndLoss.pri)

DISTFILES +=
