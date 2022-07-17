cmake_minimum_required(VERSION 3.15)

project(dream-web VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Gui Quick QuickControls2 Network REQUIRED)

set(PROJECT_SOURCES
        src/main.cpp
        src/md5.cc src/md5.h
        src/wasm/wasm.h
        src/models/videoListModel.cc
        src/services/store/store.cc
        src/http/http.cpp)

qt_add_executable(dream-web
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES})

target_link_libraries(dream-web
        PRIVATE Qt6::Core Qt6::Gui Qt6::Quick Qt6::QuickControls2 Qt6::Network)

# 当编译WebAssembly时修改链接参数，否则会报初始内存太小错误
if (EMSCRIPTEN)
    set(QT_WASM_INITIAL_MEMORY 96MB)
    set(QT_WASM_TOTAL_MEMORY 128MB)
    #target_link_options(dream-web PRIVATE "-s TOTAL_MEMORY=96MB")
endif ()

qt_import_qml_plugins(dream-web)
qt_finalize_executable(dream-web)

set_source_files_properties(assets/qml/Font.qml PROPERTIES QT_QML_SINGLETON_TYPE TRUE)

#set_source_files_properties(assets/qml/Font.qml PROPERTIES
#        QT_QML_SOURCE_VERSIONS "1.0"
#        QT_QML_SOURCE_TYPENAME Font2)

qt_add_qml_module(dream-web
        URI qtwasm
        VERSION 1.0
        QML_FILES
        assets/qml/Main.qml
        assets/qml/App.qml
        assets/qml/ArticleList.qml
        assets/qml/Font.qml)

#set_source_files_properties(assets/qml/Font.qml PROPERTIES QT_QML_SINGLETON_TYPE TRUE)
#
#set_source_files_properties(assets/qml/Font.qml PROPERTIES
#        QT_QML_SOURCE_VERSIONS "1.0"
#        QT_QML_SOURCE_TYPENAME CustomStyles
#        )
#
#qt_target_qml_sources(dream-web
#        QML_FILES assets/qml/Font.qml)