import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import ".."

Rectangle {
    Layout.preferredWidth: parent.width
    Layout.fillHeight: true
    radius: 4

    Rectangle {
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        width: 960
        color: "#FFFFFF"
        Rectangle {
            anchors.fill: parent
            anchors.margins: 16

            ColumnLayout {
                RowLayout {
                    spacing: 8
                    Text {
                        text: "账号"
                        Layout.preferredWidth: 80
                        horizontalAlignment: Qt.AlignRight
                        verticalAlignment: Qt.AlignVCenter
                        Layout.preferredHeight: 32
                        font.pixelSize: 14
                        font.weight: 400
                        font.family: RegisteredSingleton.primaryFont.name
                    }
                    TextField {
                        Layout.preferredWidth: 160
                        placeholderText: "请输入账号"
                        Layout.preferredHeight: 32
                        verticalAlignment: Qt.AlignVCenter
                        font.pixelSize: 14
                        font.weight: 400
                        font.family: RegisteredSingleton.primaryFont.name
                    }
                }
                Row {
                    Text {
                        text: "验证码"
                        width: 80
                        height: 32
                        horizontalAlignment: Qt.AlignRight
                        verticalAlignment: Qt.AlignVCenter
                        font.pixelSize: 14
                        font.weight: 400
                        font.family: RegisteredSingleton.primaryFont.name
                    }
                    Rectangle {
                        width: 8
                        height: 32
                    }

                    TextField {
                        width: 160
                        height: 32
                        placeholderText: "请输入验证码"
                        verticalAlignment: Qt.AlignVCenter
                        font.pixelSize: 14
                        font.weight: 400
                        font.family: RegisteredSingleton.primaryFont.name
                    }
                }
                RowLayout {

                    Rectangle {
                        Layout.preferredWidth: 80
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
                                console.debug("点击登录", debug)
                            }
                        }
                    }
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

