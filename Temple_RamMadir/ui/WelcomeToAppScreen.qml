import QtQuick 2.0
import "./components"

Rectangle{
    id:root
    property var styles: MyStyles{}
    color: styles.backgroundcolorOfApp
    anchors.fill: parent
    signal welcomeToAppTimeTriggered()
    Text {
        id: name
        text: qsTr("Welcome")
        font.pixelSize: root.height/10
        anchors.centerIn: parent
        color: "Black"
    }
    Timer {
        interval: 5000; running: true;
        repeat: false
        onTriggered: welcomeToAppTimeTriggered()
    }
}
