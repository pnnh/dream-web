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
        color: "#ffffff"
        ArticleList {
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

