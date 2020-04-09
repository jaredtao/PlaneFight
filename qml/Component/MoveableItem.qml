import QtQuick 2.9
import QtQuick.Controls 1.4
Item {
    id: root
    signal trigger()
    property alias source: loader.source
    property alias sourceComponent: loader.sourceComponent
    property alias item: loader.item
    focus: true
    Keys.enabled: true
    Keys.onPressed: {
        if (event.key === Qt.Key_Left)
        {
            root.x = Math.max(root.x -gConfig.velocity, 0)
        }
        else if( event.key === Qt.Key_Right)
        {
            root.x = Math.min( root.x + gConfig.velocity, root.parent.width - root.width)
        }
        else if(event.key === Qt.Key_Space)
        {
            root.trigger()
        }
    }

    Loader {
        id: loader
        anchors.fill: parent
        onLoaded: {
            root.width = item.width
            root.height = item.height
        }
    }
}
