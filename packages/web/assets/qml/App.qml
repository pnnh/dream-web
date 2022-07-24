import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt.example.qobjectSingleton 1.0
import "pages"
import ExtraModule

Item {

    StackView {
        id: routeStack
        initialItem: mainPage
        anchors.fill: parent
    }

    Component {
        id: mainNav

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

                        Item {
                            height: 32
                            width: 80
                            Layout.alignment: Qt.AlignLeft
                            Text {
                                anchors.centerIn: parent
                                text: "首页"
                                font.pixelSize: 18
                                font.weight: 400
                                font.family: RegisteredSingleton.primaryFont.name
                            }
                            MouseArea {
                                anchors.fill: parent
                                cursorShape: Qt.PointingHandCursor
                                onClicked: {
                                    console.debug("点击首页", debug)
                                    routeStack.push(mainPage)
                                }
                            }
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
                        Extra {}
                        CardModel {}
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
                                routeStack.push(loginPage)
                            }
                        }
                    }
                }
            }
        }
    }

    Component {
        id: mainPage

        ColumnLayout {
            anchors.fill: parent
            spacing: 8

            Loader {
                sourceComponent: mainNav
                Layout.alignment: Qt.AlignTop
                Layout.preferredWidth: parent.width
            }
            IndexPage {
                Layout.preferredWidth: 960
                Layout.maximumWidth: 960
                Layout.alignment: Qt.AlignCenter
                Layout.fillHeight: true
            }
        }
    }
    Component {
        id: loginPage

        ColumnLayout {
            anchors.fill: parent
            spacing: 8

            Loader {
                sourceComponent: mainNav
                Layout.alignment: Qt.AlignTop
                Layout.preferredWidth: parent.width
            }
            LoginPage {
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

