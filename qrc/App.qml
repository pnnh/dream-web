import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
    Layout.fillHeight: true
    Layout.fillWidth: true

    RowLayout {
        Layout.preferredWidth: parent.width
        RowLayout {
            Layout.maximumWidth: 960
            Layout.preferredWidth: 960
            Layout.minimumWidth: 960
            Layout.alignment: Qt.AlignCenter
            height: 40

            RowLayout {
                Layout.alignment: Qt.AlignLeft
                Text {
                    text: "Hello中文"
                    font.pointSize: 20
                }
                Text {
                    text: "Hello中文2"
                    font.pointSize: 20
                }
            }

            Text {
                text: "Hello中文3"
                font.pointSize: 20
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

