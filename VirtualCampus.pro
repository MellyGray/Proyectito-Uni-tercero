TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    virtualcampus.cpp \
    resource.cpp \
    user.cpp \
    course.cpp \
    fdp.cpp \
    seminar.cpp \
    student.cpp \
    professor.cpp \
    administrator.cpp \
    listares.cpp \
    nodores.cpp \
    listusers.cpp \
    nodousers.cpp

HEADERS += \
    resource.h \
    user.h \
    course.h \
    fdp.h \
    seminar.h \
    student.h \
    professor.h \
    administrator.h \
    listares.h \
    nodores.h \
    listusers.h \
    nodousers.h \
    virtualcampus.h
