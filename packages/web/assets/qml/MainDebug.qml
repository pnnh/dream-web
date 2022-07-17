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

    // 这样方便调试，修改后刷新页面即可
    Loader {
        id: pageLoader
        source: "http://127.0.0.1:3500/assets/qml/App.qml"
        width: parent.width
        height: parent.height
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5;height:960;width:1400}
}
##^##*/

