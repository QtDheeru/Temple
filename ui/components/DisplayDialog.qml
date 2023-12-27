import QtQuick 2.0
import QtQuick.Controls 2.5

Dialog {
    visible: true
    title: "Information.."
    property var page
    property alias text2Display : _t1.text
    width: 400;height: 250
    property string rectColor:"lightblue"
    property string contentColor:"lightblue"
    property bool footerVisible:true
    property bool setButtons:false

    standardButtons: setButtons?Dialog.Ok :Dialog.Ok | Dialog.Close
    property int context : 0
    closePolicy: Popup.NoAutoClose
    signal yesAction();
    signal noAction();

    modal: true
    background: Rectangle{
        anchors.fill: parent
        color:rectColor
        border.width: 1;
        border.color: "black"
    }
    contentItem: Rectangle {
        color: contentColor
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
        Image {
            id: cancel
            source: "qrc:/ui/assets/Images/remove.png"
            height: 30
            width: 30
            visible: true
            anchors.right: parent.right
            MouseArea{
                anchors.fill: cancel
                onClicked: {
                    noAction();
                }
            }
        }
    }
    footer: DialogButtonBox{
        visible: footerVisible
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
