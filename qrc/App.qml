import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
    Layout.fillHeight: true
    Layout.fillWidth: true

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

    RowLayout {
        Layout.preferredHeight: 80
        TextEdit {
            text: "Please Input 请输入内容"
            selectByMouse: true
            font.pointSize: 20
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.75;height:480;width:640}D{i:2}D{i:1}D{i:4}D{i:3}
}
##^##*/

