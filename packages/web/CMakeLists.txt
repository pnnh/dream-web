cmake_minimum_required(VERSION 3.15)

project(dream-wasm VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Core Gui Quick QuickLayouts QuickControls2
        QuickTemplates2 Network REQUIRED)

set(PROJECT_SOURCES
        src/main.cpp
        src/md5.h
        src/md5.cc
        src/wasm/wasm.h
        src/models/videoListModel.h
        src/models/videoListModel.cc
        src/services/store/store.cc
        src/http/http.h
        src/http/http.cpp)

qt_add_executable(dream-wasm
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES})

target_link_libraries(dream-wasm
        PRIVATE Qt6::Core Qt6::Gui Qt6::Quick Qt6::QuickControls2 Qt6::Network)

# 当编译WebAssembly时修改链接参数，否则会报初始内存太小错误
if (EMSCRIPTEN)
    set(QT_WASM_INITIAL_MEMORY 96MB)
    set(QT_WASM_TOTAL_MEMORY 128MB)
    #target_link_options(dream-wasm PRIVATE "-s TOTAL_MEMORY=96MB")
endif ()

#add_subdirectory(ExtraModule)
#target_link_libraries(dream-wasm PRIVATE extra_moduleplugin)

qt_import_qml_plugins(dream-wasm)
qt_finalize_executable(dream-wasm)

set(qml_files
        assets/qml/Main.qml
        assets/qml/App.qml
        assets/qml/ArticleList.qml
        assets/qml/Font.qml
        assets/qml/pages/IndexPage.qml
        assets/qml/pages/LoginPage.qml
        assets/qml/pages/ReadPage.qml)


qt_add_qml_module(dream-wasm
        URI qtwasm
        VERSION 1.0
        QML_FILES ${qml_files})

