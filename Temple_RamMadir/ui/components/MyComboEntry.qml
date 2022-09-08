import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

Rectangle {
    id : _root
    property int myHeight : 30
    property int fontPixelSize : 20
    property int myWidth
    implicitWidth:150;implicitHeight:myHeight
    property alias _labelText : _label.text
    property alias _dataModel : _tInput.model
    property alias _dataModelRole : _tInput.textRole
    property alias _data :_tInput.currentText
    property alias _enteredText : _tInput.editText
    property alias currentIndex :_tInput.currentIndex
    property alias   isEditable : _tInput.editable
    signal indexChanged(var i)
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
            //anchors.verticalCenter: parent.verticalCenter
           // Layout.alignment: Qt.AlignVCenter
            text : "Mobile Number"
            color: "black"
            font.pixelSize: _root.fontPixelSize
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 100//_root.myWidth*0.33
            Layout.preferredHeight: _root.myHeight
            Layout.minimumWidth: 100//_root.myWidth*0.33
            Layout.minimumHeight: 30
            Layout.alignment: Qt.AlignVCenter
            verticalAlignment: TextInput.AlignVCenter
            Layout.leftMargin: 10
        }
        ComboBox{
            id :_tInput
            //Layout.fillHeight: true
            //Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 100//_root.myWidth - _label.width
            Layout.preferredHeight: myHeight
            Layout.minimumWidth: 100//_root.myWidth - _label.width
            Layout.minimumHeight: myHeight
            Layout.alignment:  Qt.AlignVCenter
            Layout.rightMargin: 10
            font.pixelSize: _root.fontPixelSize
//            indicator: Image {
//                id: indi
//                scale : 0.5
//                source: "qrc:/ui/assets/Images/up-and-down-arrows.png"
//            }
            onActivated:{
                console.log(" Activated Index ="+index)
                console.log("Selected Text ="+_tInput.textAt(index))
            }
            onCurrentIndexChanged: {

                var currentItem = delegateModel.items.get(currentIndex)
               indexChanged(currentItem)
            }
        }
    }

    function findTextInComboBox(combotext){
        console.log(" FInding the tetxt ="+combotext)
        return _tInput.find(combotext);
    }
}