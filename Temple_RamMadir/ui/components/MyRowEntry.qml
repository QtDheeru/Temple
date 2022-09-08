import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

//FocusScope{
//    width: rootRect.width;height: rootRect.height
//    x:rootRect.x;y:rootRect.y
Rectangle {
    id:rootRect
    property alias _labelText : _label.text
    property alias _data  : _tInput.text
    property alias _labelFontSize :_label.font.pixelSize
    property alias _editable : _tInput.editable
    property alias isDataExist : _tInput.isDataExist
    property alias regExpValidator: _tInput.regExpValidator
    signal editDone();
    property int myHeight : 40
    property int fontPixelSize : 20


    implicitWidth:300;implicitHeight:myHeight
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
            color: "black"
            font.pixelSize: fontPixelSize
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 100
            Layout.preferredHeight: myHeight
            Layout.minimumWidth: 150
            Layout.minimumHeight: myHeight
            Layout.alignment: Qt.AlignBottom
            verticalAlignment: TextInput.AlignBottom
            Layout.leftMargin: 10
        }
        LineTextInput{
            id :_tInput
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 200
            Layout.preferredHeight: myHeight
            Layout.minimumWidth: 150
            Layout.minimumHeight: myHeight
            Layout.alignment: Qt.AlignRight
            Layout.rightMargin: 10
            focus: true
            activeFocusOnTab :true
            onEditComplete:{
                console.log(" RowEntry - Edit is completet")
                editDone();
            }
        }
    }
    function clearData(){
        _tInput.clearData();
    }
    onActiveFocusChanged: {
        console.log("focus changed")
        if(activeFocus) _tInput.forceActiveFocus()
    }
}
//}
