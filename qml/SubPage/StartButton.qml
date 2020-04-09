import QtQuick 2.9
import "../Component"
CButton {
    width: 120
    height: 50
    radius: 10
    color: gConfig.btnColor
    border.color: gConfig.borderColor
    border.width: 2
    contentSourceComponent: CText {
        text: qsTr("开始游戏")
        anchors.centerIn: parent
    }
}
