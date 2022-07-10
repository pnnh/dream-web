import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import an.qt.CModel 1.0

ListView {
    id: listView
    signal itemPressed(var pk)
    topMargin: 16
    spacing: 4
    clip: true
    orientation: ListView.Vertical

    delegate: Rectangle {
        id: wrapper
        height: 120
        width: parent.width
        ColumnLayout {
            anchors.fill: parent
            spacing: 4
            anchors.margins: 8

            Text {
                text: "Qt 6.2编译WebAssembly"
                font.pointSize: 18
                font.weight: 600
            }

            Text {
                text: "演示通过cmake将Qt6项目编译为WebAssembly，并加载自定义中文字体"
                font.pointSize: 14
                color: "#5e5e5e"
            }

            RowLayout {
                spacing: 4
                Text {
                    text: "Larry"
                    color: "#86909c"
                }
                Text {
                    text: "2022年2月6日 7:52"
                    color: "#86909c"
                }
                Text {
                    text: "105"
                    color: "#86909c"
                }
            }
            Rectangle {
                height: 2
                Layout.preferredWidth: parent.width
                color: "#e5e6eb"
            }
        }
    }
    boundsBehavior: Flickable.StopAtBounds
    model: VideoListModel {
        source: "videos"
    }
    ScrollBar.vertical: ScrollBar {
        visible: active
        background: Item {
            opacity: 0
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

