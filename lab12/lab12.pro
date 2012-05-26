TEMPLATE = app
TARGET = lab12
QT += core \
    gui
HEADERS += controller/ctrl.h \
    repository/repo.h \
    domain/testPhNo.h \
    domain/PhNo.h \
    PbookUI.h
SOURCES += repository/repo.cpp \
    domain/PhNo.cpp \
    main.cpp \
    PbookUI.cpp
FORMS += PbookUI.ui
RESOURCES += 
