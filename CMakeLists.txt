cmake_minimum_required(VERSION 3.7)
project(cw2)

#set(CMAKE_PREFIX_PATH "/home/twak/Qt/5.12.5")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_CXX_STANDARD 11)

include_directories (${CMAKE_BINARY_DIR})

find_package(Qt5 COMPONENTS Widgets Multimedia MultimediaWidgets Network Xml REQUIRED)
#find_package(Qt5Multimedia REQUIRED)

set(SOURCE_FILES responsive_layout.cpp responsive_layout.h responsive_label.cpp responsive_label.h responsive_window.cpp responsive_window.h screenshot.cpp screenshot.h)
add_executable(cw2 ${SOURCE_FILES})

target_link_libraries(cw2 Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets Qt5::Network Qt5::Xml)