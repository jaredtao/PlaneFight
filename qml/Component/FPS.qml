import QtQuick 2.9
Item{
    property int fps: 60
    property int frameCount: 0
    implicitWidth: 100
    implicitHeight: 50
    Item {
        id: fpsItem
        implicitWidth: 100
        implicitHeight: 50
        NumberAnimation on rotation {
            from: 0
            to: 360
            duration: 800
            loops: Animation.Infinite
        }
        onRotationChanged: ++frameCount;
    }
    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            fps = frameCount;
            frameCount = 0;
        }
    }

    CText {
        text: "FPS:" + fps
        anchors.centerIn: parent
    }
}
