import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt.example.qobjectSingleton 1.0

ColumnLayout {
    Layout.fillHeight: true
    Layout.fillWidth: true
    spacing: 8

    Rectangle {

        height: 56
        Layout.preferredWidth: parent.width
        color: "#FFFFFF"
        RowLayout {

            anchors.centerIn: parent
            RowLayout {
                Layout.maximumWidth: 960
                Layout.preferredWidth: 960
                Layout.minimumWidth: 960
                Layout.alignment: Qt.AlignCenter
                height: 40

                RowLayout {
                    Layout.alignment: Qt.AlignLeft
                    Text {
                        text: "首页2"
                        font.pixelSize: 18
                        font.family: RegisteredSingleton.primaryFont.name
                    }
                    Text {
                        text: "文章4"
                        font.pixelSize: 18
                        font.family: RegisteredSingleton.primaryFont.name
                    }
                }
                Rectangle {
                    height: 32
                    width: 80
                    Layout.alignment: Qt.AlignRight
                    color: "#0078D4"
                    radius: 4
                    Text {
                        anchors.centerIn: parent
                        text: "登录"
                        font.pixelSize: 14
                        font.weight: 400
                        font.family: RegisteredSingleton.primaryFont.name
                        color: "#FFFFFF"
                    }
                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            console.debug("点击按钮", debug)
                            console.debug("点击按钮2",
                                          RegisteredSingleton.textColor)
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        Layout.preferredWidth: parent.width
        Layout.fillHeight: true
        radius: 4

        Rectangle {
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            width: 960
            color: "#ffffff"
            ArticleList {
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.25;height:960;width:1400}
}
##^##*/

