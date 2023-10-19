import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

Rectangle {
    implicitWidth:300;implicitHeight:40
    property alias _labelText : _label.text
    //border.color: "yellow";border.width: 1
    property alias _datamodel : _tInput.model
    property alias _radButton : _label
    property alias _data :_tInput.currentText
    property alias _currentIndex :_tInput.currentIndex
    focus: true
    Layout.fillWidth: true
    color: "transparent"
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
        ComboBox{
            id :_tInput
            Layout.fillWidth: true
            Layout.preferredWidth: 200
            Layout.preferredHeight: 40
            Layout.minimumWidth: 200
            Layout.minimumHeight: 40
            Layout.alignment:  Qt.AlignBottom
            Layout.rightMargin: 10
            onActivated:{
                console.log(" Activated Index ="+index)
                console.log("Selected Text ="+_tInput.textAt(index))
            }
        }
    }
    function findTextInComboBox(combotext){
        console.log(" Finding the tetxt ="+combotext)
        return _tInput.find(combotext);
    }
}

