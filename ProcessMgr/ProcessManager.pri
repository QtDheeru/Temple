INCLUDEPATH += $$PWD
HEADERS += \
    $$PWD/ProcessExplorer.h \
    $$PWD/ProcessExplorer_p.h \

SOURCES += \
    $$PWD/ProcessExplorer.cpp \

windows {
    SOURCES += \
    $$PWD/ProcessExplorer_Windows.cpp \
}
macx{
    SOURCES += \
    $$PWD/ProcessExplorer_Mac.cpp
}
