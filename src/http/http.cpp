//
// Created by Larry on 2022/7/12.
//

#include "http.h"
#include <iostream>

void TestConnection() {
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QUrl url = QUrl("http://127.0.0.1:8080/test");
    QNetworkRequest req = QNetworkRequest(url);
    QByteArray chunk = QString("hello").toLocal8Bit();
    //req.setHeader(QNetworkRequest::ContentTypeHeader, "multipart/form-data");
    qDebug() << "Url:" << url.url();
    QObject::connect(manager, &QNetworkAccessManager::finished, [](QNetworkReply *reply) {
        qDebug() << "Uploading Finish " << reply->error();
    });
    QNetworkReply *reply = manager->post(req, chunk);
    QObject::connect(reply, &QNetworkReply::uploadProgress, [](quint64 uploaded, quint64 total) {
        qDebug() << "Uploading" << QString::number(uploaded) << "/" << QString::number(total);
    });
}
