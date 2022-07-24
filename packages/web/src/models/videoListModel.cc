//
// Created by Larry on 2021/11/25.
//

#include "videoListModel.h"
#include "src/services/store/store.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringView>
#include <QVector>
#include <QXmlStreamReader>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <iostream>

VideoListModel::VideoListModel(QObject *parent) : QAbstractListModel(parent) {
  int role = Qt::UserRole;
  m_roleNames.insert(role++, "pk");
  m_roleNames.insert(role++, "title");
}

VideoListModel::~VideoListModel() {
  // delete m_dptr;
}

int VideoListModel::rowCount(const QModelIndex &parent = QModelIndex()) const {
  return m_videos.size();
}

void VideoListModel::add(QVariantMap value) {
  auto name = value["name"].value<QString>();
  qDebug() << "insertRows2" << name;
  TaskInfo info = {.title = name};

  beginInsertRows(QModelIndex(), 0, 0);

  auto video = VideoData();
  video.append(info.pk);
  video.append(info.title);
  m_videos.insert(0, video);

  endInsertRows();
}

void VideoListModel::reset() {
  m_strError.clear();
  clear();
}

void VideoListModel::clear() { m_videos.clear(); }

void VideoListModel::update(int index, QVariantMap value) {
  auto title = value["name"].value<QString>();
  qDebug() << "updateRows" << title;
  auto item = m_videos[index];
  auto pk = item[0];
  qDebug() << "updateRows2" << pk << "|" << title;

  // updateInfoTitle(pk, title);
}

QVariant VideoListModel::data(const QModelIndex &index, int role) const {
  VideoData d = m_videos[index.row()];
  return d.at(role - Qt::UserRole);
}

QHash<int, QByteArray> VideoListModel::roleNames() const { return m_roleNames; }

QString VideoListModel::source() const { return m_strXmlFile; }

void VideoListModel::setSource(const QString &filePath) {
  m_strXmlFile = filePath;
  reload();
}

void VideoListModel::reload() {
  beginResetModel();
  reset();

  auto *manager = new QNetworkAccessManager();
  QUrl url = QUrl("http://127.0.0.1:8080/restful/index/query");
  QNetworkRequest req = QNetworkRequest(url);

  qDebug() << "Url:" << url.url();

  QNetworkReply *reply = manager->get(req);

  QObject::connect(reply, &QNetworkReply::finished, [this, reply]() {
    auto bytes = reply->readAll();
    // QString respContent = bytes;
    // qDebug() << "Result: " << respContent;
    QJsonParseError jsonError;
    auto jsonDoc = QJsonDocument::fromJson(bytes, &jsonError);
    qDebug() << "json转换结果8：" << jsonError.errorString();
    QJsonObject jsonObject = jsonDoc.object();
    QJsonArray modelsArray = jsonObject["models"].toArray();

    foreach (const QJsonValue &value, modelsArray) {
      QJsonObject article = value.toObject();
      auto pk = article["pk"].toString();
      auto title = article["title"].toString();
      // qDebug() << "Key = " << pk << "|" << title << "\n";

      auto video = VideoData();
      video.append(pk);
      video.append(title);
      m_videos.append(video);
    }
    endResetModel();
  });
}

void VideoListModel::remove(int index) {
  beginRemoveRows(QModelIndex(), index, index);
  // delete m_videos.takeAt(index);
  endRemoveRows();
}

QVariantMap VideoListModel::get(int index) {
  QVariantMap itemMap;
  if (index < m_videos.size()) {
    auto item = m_videos[index];
    if (item.length() > 1) {
      itemMap["pk"] = item[0];
      itemMap["title"] = item[1];
    }
  }
  return itemMap;
}
