TEMPLATE = app

QT += quick
CONFIG += c++11

SOURCES += \
    src/main.cpp \
    src/SceneItem.cpp

RESOURCES += \
    Img.qrc \
    Qml.qrc
OTHER_FILES += \
    .clang-format \
    .travis.yml \
    appveyor.yml \
    LICENSE \
    README.md

HEADERS += \
    src/SceneItem.h
