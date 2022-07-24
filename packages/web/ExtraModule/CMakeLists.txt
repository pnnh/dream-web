
find_package(Qt6 COMPONENTS Core Gui Quick QuickLayouts QuickControls2 REQUIRED)

include_directories(${Qt6QuickLayouts_INCLUDE_DIRS})
qt6_add_library(extra_module STATIC)

qt6_add_qml_module(extra_module
        URI "ExtraModule"
        VERSION 1.0
        QML_FILES
        Extra.qml
        SOURCES
        CardModel.h
        CardModel.cc)

target_link_libraries(extra_module PRIVATE Qt::QmlPrivate Qt::QuickPrivate)

qt6_target_compile_qml_to_cpp(extra_module
        QML_FILES
        Extra.qml)

