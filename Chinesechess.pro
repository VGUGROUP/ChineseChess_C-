TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        alpha_beta.cpp \
        evaluation.cpp \
        main.cpp \
        piece.cpp \
        rule.cpp \
        state.cpp

HEADERS += \
    alpha_beta.h \
    evaluation.h \
    piece.h \
    rule.h \
    state.h
