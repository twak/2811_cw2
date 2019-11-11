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

find_package(Qt5 COMPONENTS Widgets Multimedia MultimediaWidgets Network Xml Gui REQUIRED)
#find_package(Qt5Multimedia REQUIRED)

set(SOURCE_FILES main.cpp the_player.cpp the_player.h the_button.cpp the_button.h)
add_executable(cw2 ${SOURCE_FILES})

target_link_libraries(cw2 Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets Qt5::Network Qt5::Xml Qt5::Gui)