//
// Created by Larry on 2021/11/25.
//

#ifndef QTEMPTY_VIDEOLISTMODEL_H
#define QTEMPTY_VIDEOLISTMODEL_H

#include <QAbstractListModel>
#include <QtQml/qqmlregistration.h>

class CardModel : public QObject {
  Q_OBJECT
  QML_ELEMENT
  Q_PROPERTY(QString source READ source WRITE setSource);
public:
  explicit CardModel(QObject *parent = nullptr);
  ~CardModel() override;
  [[nodiscard]] QString source() const;
  void setSource(const QString &filePath);
};

#endif // QTEMPTY_VIDEOLISTMODEL_H
