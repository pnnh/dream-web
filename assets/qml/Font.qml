pragma Singleton

import QtQml
import QtQuick

QtObject {

    readonly property var primaryFont: FontLoader {
        source: "http://127.0.0.1:8081/fonts/NotoSansSC/NotoSansSC-Regular.otf"
        onStatusChanged: {
            console.log(
                "onStatusChanged status:" + status) // Not getting called
        }
    }
    property int textSize: 20
    property color textColor: "green"
    readonly property string test: "hello_test"
}
