import QtQuick 2.0
import QtQuick.Controls 2.5
Rectangle {
    id:_button
    border.color: "black"
    border.width: 2
    signal buttonClikcked()
    property string buttonText;
    property var myopacity
    opacity:myopacity
    Text {
        id: txt
        text:buttonText
        font.pixelSize: parent.width/12
        anchors.centerIn: parent
    }
    MouseArea{
        id:_SevaBooking
        anchors.fill: parent
        onClicked: buttonClikcked()
    }
}
