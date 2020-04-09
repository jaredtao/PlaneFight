import QtQuick 2.9
import QtQuick.Controls 1.4
Rectangle {
    id: btnRoot
    signal clicked()
    property alias contentSource: btnLoader.source
    property alias contentSourceComponent: btnLoader.sourceComponent
    property alias contentItem: btnLoader.item
    property alias containsMouse: btnArea.containsMouse
    property alias containsPress: btnArea.containsPress
    Loader {
        id: btnLoader
        anchors.centerIn: parent
    }
    MouseArea {
        id: btnArea
        anchors.fill: parent
        onClicked: btnRoot.clicked()
    }
}
