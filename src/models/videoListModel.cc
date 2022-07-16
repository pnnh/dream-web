//
// Created by Larry on 2021/11/25.
//

#include "videoListModel.h"
#include <QXmlStreamReader>
#include <QVector>
#include <QDebug>
#include <QStringView>
#include "src/services/store/store.h"

VideoListModel::VideoListModel(QObject *parent) : QAbstractListModel(parent) {

  int role = Qt::UserRole;
  m_roleNames.insert(role++, "pk");
  m_roleNames.insert(role++, "name");
}

VideoListModel::~VideoListModel() {
  //delete m_dptr;
}

int VideoListModel::rowCount(const QModelIndex &parent = QModelIndex()) const {
  return m_videos.size();
}

void VideoListModel::add(QVariantMap value) {
  auto name = value["name"].value<QString>();
  qDebug() << "insertRows2" << name;
  TaskInfo info = {
      .title = name
  };
  //addInfo(info);

  beginInsertRows(QModelIndex(), 0, 0);

  auto video = new VideoData();
  video->append(info.pk);
  video->append(info.title);
  m_videos.insert(0, video);

  endInsertRows();
}

void VideoListModel::load() {
  VideoData *video;
  auto dataVector = queryTasks();
  QVectorIterator<TaskInfo> dataIterator(dataVector);
  while (dataIterator.hasNext()) {
    auto info = dataIterator.next();
    qDebug() << "info ==" << info.title;

    video = new VideoData();
    video->append(info.pk);
    video->append(info.title);
    m_videos.append(video);
  }

}

void VideoListModel::reset() {
  m_strError.clear();
  clear();
}

void VideoListModel::clear() {
  int count = m_videos.size();
  if (count > 0) {
    for (int i = 0; i < count; i++) {
      delete m_videos.at(i);
    }
    m_videos.clear();
  }
}

void VideoListModel::update(int index, QVariantMap value) {
  auto title = value["name"].value<QString>();
  qDebug() << "updateRows" << title;
  auto item = m_videos[index];
  auto pk = (*item)[0];
  qDebug() << "updateRows2" << pk << "|" << title;

  //updateInfoTitle(pk, title);
}

QVariant VideoListModel::data(const QModelIndex &index, int role) const {
  VideoData *d = m_videos[index.row()];
  return d->at(role - Qt::UserRole);
}

QHash<int, QByteArray> VideoListModel::roleNames() const {
  return m_roleNames;
}

QString VideoListModel::source() const {
  return m_strXmlFile;
}

void VideoListModel::setSource(const QString &filePath) {
  m_strXmlFile = filePath;
  reload();
}

//QString VideoListModel::errorString() const {
//  return m_strError;
//}
//
//bool VideoListModel::hasError() const {
//  return m_bError;
//}

void VideoListModel::reload() {
  beginResetModel();
  reset();
  load();
  endResetModel();
}

void VideoListModel::remove(int index) {
  beginRemoveRows(QModelIndex(), index, index);
  delete m_videos.takeAt(index);
  endRemoveRows();
}

QVariantMap VideoListModel::get(int index) {
  QVariantMap itemMap;
  if (index < m_videos.size()) {
    auto item = m_videos[index];
    if (item != nullptr && item->length() > 1) {
      itemMap["pk"] = (*item)[0];
      itemMap["title"] = (*item)[1];
    }
  }
  return itemMap;
}
