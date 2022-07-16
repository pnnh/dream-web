#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFontDatabase>

#include <src/models/videoListModel.h>
#include "src/http/http.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    qmlRegisterType<VideoListModel>("an.qt.CModel", 1, 0, "VideoListModel");

    // 设置全局字体，用于解决Qt for WebAssembly中文显示异常问题
    // fileName 参数不用带qrc:前缀
    int fontId = QFontDatabase::addApplicationFont(":/qtwasm/assets/fonts/WenQuanYi/wqy-microhei-lite.ttc");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    qDebug() << "fontfamilies:" << fontFamilies;
    if (!fontFamilies.empty()) {
        QFont font;
        auto fontFamilie = fontFamilies[0];
        font.setFamily(fontFamilie);//设置全局字体
        QGuiApplication::setFont(font);
    }

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qtwasm/qrc/Main.qml"));

    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

#ifndef NDEBUG
  // nondebug
  // todo 测试目的
  TestConnectionGet();
#endif
    return QGuiApplication::exec();
}

