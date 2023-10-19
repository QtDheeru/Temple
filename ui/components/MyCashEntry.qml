import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

Rectangle {
    implicitWidth:300;implicitHeight:40
    property alias _labelText : _label.text
    property alias _radButton : _label
    property alias amount2Pay : _tInput.text
    property alias isDataExist : _tInput.isDataExist
    property alias _editable : _tInput.editable
    //border.color: "yellow";border.width: 1
    color: "transparent"
    focus: true
    Layout.fillWidth: true
    RowLayout{
        anchors.fill: parent
        Layout.leftMargin: 10
        spacing: 30
        Label{
            id : _label
            text : "Mobile Number"
            font.pixelSize: 25
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40
            Layout.minimumWidth: 150
            Layout.minimumHeight: 30
            Layout.alignment: Qt.AlignBottom
            Layout.leftMargin: 10
        }
        LineTextInput{
            id :_tInput
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 200
            Layout.preferredHeight: 40
            Layout.minimumWidth: 200
            Layout.minimumHeight: 40
            Layout.alignment:  Qt.AlignBottom
            Layout.rightMargin: 10
        }
    }

    function displayErrorBorder(){

    }
}

