QT += network widgets

TARGET = tdm
TEMPLATE = app

requires(qtConfig(filedialog))

HEADERS += src/addurldialog.h \
           src/mainwindow.h \
           src/downloadtask.h


SOURCES += src/main.cpp \
           src/addurldialog.cpp \
           src/mainwindow.cpp \
           src/downloadtask.cpp

# Forms and resources
FORMS += forms/addurlform.ui
RESOURCES += icons.qrc


# Windows resources only
win32 {
    RC_FILE += tdm.rc
}
