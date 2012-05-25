TEMPLATE = app
TARGET = hekil
QT += core \
    gui
HEADERS += ui/ConsoleUI.h \
    controller/MovieRental.h \
    controller/TestMovieRental.h \
    repository/ClientFileRepository.h \
    repository/ClientInMemoryRepository.h \
    repository/MovieFileRepository.h \
    repository/MovieInMemoryRepository.h \
    domain/Client.h \
    domain/ClientRepository.h \
    domain/ClientValidator.h \
    domain/Exceptions.h \
    domain/Movie.h \
    domain/MovieRepository.h \
    domain/MovieValidator.h \
    hekil.h
SOURCES += ui/ConsoleUI.cpp \
    controller/MovieRental.cpp \
    repository/ClientFileRepository.cpp \
    repository/ClientInMemoryRepository.cpp \
    repository/MovieFileRepository.cpp \
    repository/MovieInMemoryRepository.cpp \
    domain/ClientValidator.cpp \
    domain/MovieValidator.cpp \
    main.cpp \
    hekil.cpp
FORMS += hekil.ui
RESOURCES += 
