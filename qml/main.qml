import QtQuick 2.9
import QtQuick.Window 2.2

import "./SubPage"
import "./Component"
Window {
    visible: true
    width: 600
    height: 800
    title: qsTr("飞机大战-王校长吃面包版")
    color: gConfig.backgroundColor

    Config {
        id: gConfig
        objectName: "gConfig"
    }

    Scene {
        id: scene
        width: parent.width
        height: parent.height
    }
    StartButton {
        anchors.centerIn: parent
        visible: !scene.running
        onClicked: {
            scene.start()
        }
    }
    WinTip {
        visible: !scene.running && scene.score > 0
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -100
    }
    CText {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("键盘左右键（← →）移动，空格键(space)发射")
    }
}
