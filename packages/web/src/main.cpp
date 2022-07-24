#include <QFontDatabase>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "src/http/http.h"
#include <QFile>
#include <src/models/videoListModel.h>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);
  qmlRegisterType<VideoListModel>("an.qt.CModel", 1, 0, "VideoListModel");
  qmlRegisterSingletonType(QUrl("qrc:/qtwasm/assets/qml/Font.qml"),
                           "Qt.example.qobjectSingleton", 1, 0,
                           "RegisteredSingleton");
  // 设置全局字体，用于解决Qt for WebAssembly中文显示异常问题
  // fileName 参数不用带qrc:前缀
  //  int fontId = QFontDatabase::addApplicationFont(
  //      ":/qtwasm/assets/fonts/NotoSansSC/NotoSansSC-Regular.otf");
  //  QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
  //  qDebug() << "fontfamilies:" << fontFamilies;
  //  if (!fontFamilies.empty()) {
  //    QFont font;
  //    auto fontFamilie = fontFamilies[0];
  //    font.setFamily(fontFamilie); // 设置全局字体
  //    QGuiApplication::setFont(font);
  //  }
  QQmlApplicationEngine engine;
  QString strUrl{"qrc:/qtwasm/assets/qml/Main.qml"};

#ifndef NDEBUG
  // todo 测试目的
  TestConnectionGet();
  engine.rootContext()->setContextProperty("debug", true);
  // strUrl = "qrc:/qtwasm/assets/qml/MainDebug.qml";
#else
  engine.rootContext()->setContextProperty("debug", false);
#endif

  const QUrl url(strUrl);

  engine.load(url);

  if (engine.rootObjects().isEmpty())
    return -1;

  return QGuiApplication::exec();
}
