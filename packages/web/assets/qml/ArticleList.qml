import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import an.qt.CModel 1.0
import Qt.example.qobjectSingleton 1.0
import "pages"

ListView {
    id: listView
    signal itemPressed(var pk)
    topMargin: 16
    spacing: 4
    clip: true
    orientation: ListView.Vertical

    property StackView routeStack2

    delegate: Rectangle {
        id: wrapper
        height: 120
        width: parent.width
        ColumnLayout {
            anchors.fill: parent
            spacing: 4
            anchors.margins: 8

            Text {
                text: model.pk
                font.pixelSize: 18
                font.weight: 600
                font.family: RegisteredSingleton.primaryFont.name
                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        console.debug("进入查看页", debug)
                        routeStack2.push(readPage)
                    }
                }
            }

            Text {
                text: model.title
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
                    font.family: RegisteredSingleton.primaryFont.name
                }
                Text {
                    text: "105"
                    color: "#86909c"
                }
            }
            Rectangle {
                height: 1
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

    Component {
        id: readPage

        ColumnLayout {
            anchors.fill: parent
            spacing: 8

            Loader {
                sourceComponent: mainNav
                Layout.alignment: Qt.AlignTop
                Layout.preferredWidth: parent.width
            }
            ReadPage {
                Layout.preferredWidth: 960
                Layout.maximumWidth: 960
                Layout.alignment: Qt.AlignCenter
                Layout.fillHeight: true
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

