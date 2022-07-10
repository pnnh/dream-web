import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

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
                        text: "首页"
                        font.pointSize: 20
                    }
                    Text {
                        text: "文章"
                        font.pointSize: 20
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
                        font.pointSize: 14
                        font.weight: 400
                        color: "#FFFFFF"
                    }
                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            console.debug("点击按钮")
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
    D{i:0;autoSize:true;formeditorZoom:0.5;height:960;width:1400}
}
##^##*/

