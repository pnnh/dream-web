//
// Created by Larry on 2021/12/19.
//

#include "store.h"
#include <QtWidgets/QApplication>
#include <QUuid>

QVector<TaskInfo> queryTasks() {
  QVector<TaskInfo> infoVect; //testInfo向量，用于存储数据库查询到的数据

    int index = 0;
    while (index++ < 10) {
      auto video = TaskInfo();
      video.title = "新任务";
      infoVect.push_back(video);
    }

  return infoVect;
}

TaskInfo sqlite::findTask(QString pk) {
  TaskInfo tmp;
  tmp.title = "新任务";
  return tmp;
}