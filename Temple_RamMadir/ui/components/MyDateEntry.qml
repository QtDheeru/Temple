import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

Rectangle {
    id : _rootDateEntry
    implicitWidth:300;
    implicitHeight:myHeight
    property int myWidth :300
    property int myHeight : 40
    property int fontPixelSize : 20
    property alias _labelText : _label.text
    property alias selecteddate:_tInput.dateSelected
    signal dateChanged(var date)
    //border.color: "yellow";border.width: 1
    color: "transparent"
    focus: true
    Layout.fillWidth: true
    RowLayout{
        anchors.fill: parent
        Layout.leftMargin: 10
        spacing: myHeight/3
        Label{
            id : _label
            text : "Mobile Number"
            color: "Black"
            font.pixelSize: _rootDateEntry.fontPixelSize
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: _rootDateEntry.myWidth *0.33
            Layout.preferredHeight: _rootDateEntry.myHeight
            Layout.minimumWidth: _rootDateEntry.myWidth *0.33
            Layout.minimumHeight: _rootDateEntry.myHeight
            Layout.alignment: Qt.AlignVCenter
            verticalAlignment: TextInput.AlignVCenter
            Layout.leftMargin: 10
        }
        MyDatePicker{
            id :_tInput
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: _rootDateEntry.myWidth - _label.width
            Layout.preferredHeight: _rootDateEntry.myHeight
            Layout.minimumWidth: _rootDateEntry.myWidth - _label.width
            Layout.minimumHeight: _rootDateEntry.myHeight
            Layout.alignment:  Qt.AlignVCenter
            Layout.rightMargin: 10
            //font.pixelSize: _root.fontPixelSize
            fontPixelSize: _rootDateEntry.fontPixelSize
            myheight: _rootDateEntry.myHeight
            myWidth: _rootDateEntry.myWidth - _label.width
        }
    }
    Connections{
        target: _tInput
        function onDateChanged(date) {
            console.log("Rajjjjjjjjjjjjj"+date)
            dateChanged(date);
        }
    }
}
