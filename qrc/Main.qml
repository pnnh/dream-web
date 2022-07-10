import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    visible: true
    width: 1440
    height: 960
    x: Screen.width / 2 - width / 2
    y: Screen.height / 2 - height / 2
    title: qsTr("Hello World")
    color: "#F6F6F6"

    App {
        width: parent.width
    }
}
