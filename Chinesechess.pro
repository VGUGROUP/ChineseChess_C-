TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        alpha_beta.cpp \
        board_view.cpp \
        evaluation.cpp \
        main.cpp \
        piece.cpp \
        player.cpp \
        rule.cpp \
        state.cpp

HEADERS += \
    alpha_beta.h \
    board_view.h \
    evaluation.h \
    piece.h \
    player.h \
    rule.h \
    state.h
