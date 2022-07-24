import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt.example.qobjectSingleton 1.0

Item {

    StackView {
        id: routeStack
        initialItem: mainPage
        anchors.fill: parent
    }

    Component {
        id: mainPage

        ColumnLayout {
            anchors.fill: parent
            spacing: 8

            Rectangle {
                Layout.alignment: Qt.AlignTop
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
                            Text {
                                text: routeStack.depth
                            }

                            Button {
                                text: "Push"
                                onClicked: routeStack.push(mainPage)
                            }
                            Button {
                                text: "Pop"
                                enabled: routeStack.depth > 1
                                onClicked: routeStack.pop()
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

            Loader {
                id: pageLoader
                source: "./pages/Index.qml"
                Layout.preferredWidth: 960
                Layout.maximumWidth: 960
                Layout.alignment: Qt.AlignCenter
                Layout.fillHeight: true
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.25;height:960;width:1400}
}
##^##*/

