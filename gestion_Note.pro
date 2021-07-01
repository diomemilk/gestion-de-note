QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    classe.cpp \
    classemodel.cpp \
    dbaccess.cpp \
    flowcontroller.cpp \
    gestionfarmateur.cpp \
    gestionformatuermodel.cpp \
    main.cpp \
    mainformateur.cpp \
    module.cpp \
    modulemodel.cpp \
    profile.cpp \
    service.cpp \
    uiauthentification.cpp\
    uiadministrateur.cpp \
    uifarmateur.cpp \
    uiresponsable.cpp \
    user.cpp \
    usermodel.cpp



HEADERS += \
    classe.h \
    classemodel.h \
    dbaccess.h \
    flowcontroller.h \
    gestionfarmateur.h \
    gestionformatuermodel.h \
    mainformateur.h \
    module.h \
    modulemodel.h \
    profile.h \
    service.h \
    uiauthentification.h\
    uiadministrateur.h \
    uifarmateur.h \
    uiresponsable.h \
    user.h \
    usermodel.h


FORMS += \
    mainformateur.ui \
    profile.ui \
    uiauthentification.ui\
    uiadministrateur.ui \
    uifarmateur.ui \
    uiresponsable.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc

DISTFILES +=
