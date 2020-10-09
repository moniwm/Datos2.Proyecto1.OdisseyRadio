cmake_minimum_required(VERSION 3.17)
project(OdisseyRadio)

set(CMAKE_CXX_STANDARD 17)

# Tell cmake where Qt is located
set(Qt5_DIR "../Qt/5.15.1/clang_64/lib/cmake/Qt5")

# Tell cmake to find the modules Qt5Core and Qt5widgets
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_executable(OdisseyRadio main.cpp)

# Link the library to the executable
target_link_libraries(OdisseyRadio Qt5::Core Qt5::Widgets)