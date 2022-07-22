//
// Created by Larry on 2022/7/12.
//

#include "http.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

std::string GetJsonString() {
  QJsonObject jsonObject;
  jsonObject.insert("hello", "world");
  auto strFromObj =
      QJsonDocument(jsonObject).toJson(QJsonDocument::Indented).toStdString();
  return strFromObj;
}

void TestConnectionPost() {
  QNetworkAccessManager *manager = new QNetworkAccessManager();
  QUrl url = QUrl("http://code.sfx.xyz:3500/graphql/mutation");
  QNetworkRequest req = QNetworkRequest(url);

  QByteArray chunk = QString::fromStdString(GetJsonString()).toLocal8Bit();
  req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  qDebug() << "Url:" << url.url();
  QObject::connect(manager, &QNetworkAccessManager::finished,
                   [](QNetworkReply *reply) {
                     qDebug() << "Uploading Finish " << reply->error() << "\n";
                     auto bytes = reply->readAll();
                     QString respContent = bytes;
                     qDebug() << respContent;
                   });
  QNetworkReply *reply = manager->post(req, chunk);
  QObject::connect(reply, &QNetworkReply::uploadProgress,
                   [](quint64 uploaded, quint64 total) {
                     qDebug() << "Uploading" << QString::number(uploaded) << "/"
                              << QString::number(total);
                   });
}

void TestConnectionGet() {
  auto *manager = new QNetworkAccessManager();
  QUrl url = QUrl("http://code.sfx.xyz:3500/restful/index/query");
  QNetworkRequest req = QNetworkRequest(url);

  qDebug() << "Url:" << url.url();

  QNetworkReply *reply = manager->get(req);
  QObject::connect(reply, &QNetworkReply::finished, [reply]() {
    auto bytes = reply->readAll();
    QString respContent = bytes;
    // qDebug() << "Result: " << respContent;
    QJsonParseError jsonError;
    auto jsonDoc = QJsonDocument::fromJson(bytes, &jsonError);
    qDebug() << "json转换结果：" << jsonError.errorString();
    QJsonObject jsonObject = jsonDoc.object();

    foreach (const QString &key, jsonObject.keys()) {
      QJsonValue value = jsonObject.value(key);
      qDebug() << "Key = " << key << ", Value = " << value.toString();
    }
  });
}
