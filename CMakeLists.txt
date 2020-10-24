cmake_minimum_required(VERSION 3.17)
project(OdisseyRadio)

set(CMAKE_CXX_STANDARD 17)

# Tell cmake where Qt is located
#set(Qt5_DIR "../Qt/5.15.1/clang_64/lib/cmake/Qt5")
set(Qt5_DIR "/usr/lib/Qt5.14.2/5.14.2/gcc_64/lib/cmake/Qt5")

# Tell cmake to find the modules Qt5Core and Qt5widgets
find_package(Qt5 COMPONENTS Core Widgets Multimedia REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_executable(OdisseyRadio
        OdisseyGUI/main.cpp
        OdisseyGUI/mainwindow.cpp
        OdisseyGUI/mainwindow.h
        OdisseyGUI/mainwindow.ui
        OdisseyGUI/MP3Player.cpp
        OdisseyGUI/MP3Player.h
        OdisseyGUI/DurationSubject.cpp
        OdisseyGUI/DurationSubject.h
        OdisseyGUI/MemoryUsage.cpp
        OdisseyGUI/MemoryUsage.h
        OdisseyGUI/OS.cpp
        OdisseyGUI/OS.h
        #build-OdisseyGUI-Works-Debug/ui_mainwindow.h
        )

# Link the library to the executable
target_link_libraries(OdisseyRadio Qt5::Core Qt5::Widgets Qt5::Multimedia)