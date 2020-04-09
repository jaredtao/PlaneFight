import QtQuick 2.9
import SceneItem 1.0
import "../Component"
SceneItem {
    id: sceneRoot
    FPS {}
    Column {
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.margins: 10
        spacing: 2
        CText {
            text: qsTr("当前关卡:") + level
        }
        CText {
            text: qsTr("得分:") + score
        }
    }
    Connections {
        target: sceneRoot
        ignoreUnknownSignals: true
        onLose: {
            running = false
        }
        onGetScore: {
            score += level
            if (score > level * 10) {
                level++;
            }
        }
        onTrophyCountChanged: {
            if (running && trophyCount <= 0) {
                sceneRoot.createTrophy(Math.random() * sceneRoot.width, 0)
            }
        }
    }


    function start()
    {
        score = 0
        level = 1
        moveItem.x = (sceneRoot.width  - moveItem.width) / 2
        running = true;
        sceneRoot.createTrophy(Math.random() * sceneRoot.width, 0)
    }
    function stop()
    {
        running = false;
    }

    MoveableItem {
        id: moveItem
        x: (sceneRoot.width  - width) / 2
        y: sceneRoot.height - height - 20
        width: 100
        height: 100
        onTrigger: {
            triggerAnimation.restart()
        }
        sourceComponent: Image {
            anchors.centerIn: parent
            source: "qrc:/img/wang.png"
        }
        SequentialAnimation {
            id: triggerAnimation
            alwaysRunToEnd: true
            RotationAnimation { target: moveItem.item; to: -90}
            ScriptAction {
                script: {
                    sceneRoot.createBread(moveItem.x + 20, moveItem.y)
                }
            }
            RotationAnimation {target: moveItem.item; to: 0}
        }
    }
}
