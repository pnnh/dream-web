//
// Created by Larry on 2021/11/25.
//

#include "CardModel.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringView>
#include <QVector>
#include <QXmlStreamReader>

CardModel::CardModel(QObject *parent) : QObject(parent) {

  qDebug() << "CardModel init\n";
}

CardModel::~CardModel() {}

QString CardModel::source() const {
  qDebug() << "CardModel source\n";
  return "source";
}

void CardModel::setSource(const QString &filePath) {
  qDebug() << "CardModel setSource " << filePath << "\n";
}
