import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import ".."

//import ExtraModule

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
            //Extra {}
            //            CardModel {}
            Text {
                text: "文章查看页面"
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

