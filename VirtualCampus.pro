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
    list.cpp \
    listofstudents.cpp \
    degree.cpp \
    listofmarks.cpp \
    listofcourses.cpp \
    listofseminars.cpp \
    date.cpp \
    lecture.cpp \
    listofresources.cpp \
    listofusers.cpp \
    listoffdps.cpp \
    listoflectures.cpp \
    nodores.cpp \
    listares.cpp

HEADERS += \
    virtualcampus.h \
    resource.h \
    user.h \
    course.h \
    fdp.h \
    seminar.h \
    student.h \
    professor.h \
    administrator.h \
    list.h \
    listofstudents.h \
    degree.h \
    listofmarks.h \
    listofcourses.h \
    listofseminars.h \
    date.h \
    lecture.h \
    listofresources.h \
    listofusers.h \
    listoffdps.h \
    listoflectures.h \
    nodores.h \
    listares.h
