import QtQuick 2.0
import QtQuick.Controls 2.5

Dialog {
    id: d1
    property string dTxt;
    property string dImage;
    width: 270
    height: 150
    closePolicy: Popup.NoAutoClose
    modal:true

    Rectangle{
        id:rect
        width:parent.width
        height: 40
        radius: 15
        anchors.bottom: parent.bottom
        color: "lightblue"
        gradient: Gradient {
            GradientStop { position: 0.5; color: "lightskyblue" }
            GradientStop { position: 1.0; color: "white" }
        }
        Button{
            id:bt
            text: "OK"
            background:rect
            anchors.centerIn: parent
            anchors.fill: parent
            font.bold: true
            onClicked: {
                d1.visible=false
            }
        }
    }
    Text{
        id: txt
        text: dTxt
        font.bold: true
        font.pixelSize: 15
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top;
        anchors.topMargin: 5
    }
    Image{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top;
        anchors.topMargin: 35
        source: dImage
    }
}

