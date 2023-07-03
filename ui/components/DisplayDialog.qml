import QtQuick 2.0
import QtQuick.Controls 2.5

Dialog {
    visible: true
    title: "Information.."
    property alias text2Display : _t1.text
    width: 400;height: 250

    standardButtons: Dialog.Ok | Dialog.Close

    closePolicy: Popup.NoAutoClose
    signal yesAction();
    signal noAction();

    modal: true
    background: Rectangle{
        anchors.fill: parent
        color:"lightblue"
        border.width: 1;
        border.color: "black"
    }
    contentItem: Rectangle {
        color: "lightblue"
        implicitWidth: 300
        implicitHeight: 100
        Text {
            id :_t1
            color: "navy"
            anchors.centerIn: parent
            font.pixelSize: 25
        }
    }
    header: Rectangle{
        width: parent.width;
        height: 40;color:"#00A4EF"
        border.width: 1;
        border.color: "black"
        Text {
            text :"Information ";
            anchors.centerIn: parent;
            font.pixelSize: 25
        }
    }
    footer: DialogButtonBox{
        alignment: Qt.AlignCenter
        standardButtons: DialogButtonBox.Ok
        onAccepted: {
            console.log("Ok clicked")
            yesAction();
        }
    }

    x: (parent.width - width) / 2
    y: (parent.height - height) / 2
}
