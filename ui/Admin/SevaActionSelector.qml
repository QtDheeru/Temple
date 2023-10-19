import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Rectangle{
    color: "skyblue"
    border.width: 0.5
    property alias sevaTypeSelected : _sevaType.checked
    property alias sevaNameSelected : _sevaName.checked
    RowLayout {
        anchors.fill: parent
        Layout.alignment: Qt.AlignLeft
        Layout.leftMargin: 10
        RadioButton {
            id: _sevaType
            Layout.preferredHeight: parent.height/2
            Layout.preferredWidth: parent.width/2
            font.pixelSize:  parent.width/60
            text: "Seva Type"
            checked: true
        }
        RadioButton {
            id: _sevaName
            Layout.preferredHeight:parent.height/2
            Layout.preferredWidth: parent.width/2
            font.pixelSize: parent.width/60
            text: "Seva Name"
            visible: true
            checked: false
        }
    }
}

