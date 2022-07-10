cmake_minimum_required(VERSION 3.15)

project(dream-web VERSION 0.1 LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Gui Quick REQUIRED)

set(PROJECT_SOURCES
        src/main.cpp
        src/md5.cc src/md5.h
        src/wasm/wasm.h)

qt_add_executable(dream-web
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES})

target_link_libraries(dream-web
        PRIVATE Qt6::Core Qt6::Gui Qt6::Quick)

# 当编译WebAssembly时修改链接参数，否则会报初始内存太小错误
if(EMSCRIPTEN)
    target_link_options(dream-web PRIVATE -s TOTAL_MEMORY=32MB)
endif()

qt_import_qml_plugins(dream-web)
qt_finalize_executable(dream-web)

qt_add_qml_module(dream-web
        URI qtwasm
        VERSION 1.0
        QML_FILES
        qrc/Main.qml qrc/App.qml
        RESOURCES
        assets/fonts/WenQuanYi/wqy-microhei-lite.ttc)