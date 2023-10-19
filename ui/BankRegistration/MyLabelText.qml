import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

RowLayout{
    property string labeltext
    property alias textField  :datetext.text
    property bool calender:false
    property var navigate
    property  int space
    property alias cale:cale
    property var inputType;
    property var validate
    property alias text:datetext
    spacing: space
    Label{
        text:labeltext
        font.pixelSize:20
        font.bold: true
        color:"black"
    }
    TextField{
        id:datetext
        font.pixelSize:20
        Layout.maximumWidth:220
        Layout.fillWidth: true
        placeholderTextColor:"gray"
        KeyNavigation.down:navigate
        color:"black"
//        text: textField
        inputMethodHints:inputType// Ensure numeric keyboard on mobile
        validator: validate
        background: Rectangle {
            color: "lightgrey"
        }

        Rectangle{
            id:rect
            visible: calender
            anchors.left: parent.left
            anchors.leftMargin:190
            width:30
            height:30
            color:"lightgray"

            Image {
                anchors.fill: parent
                source: "qrc:/ui/assets/Images/calender.jpeg"
            }
            MouseArea{
                id:cal
                anchors.fill: parent
                onClicked:  {
                    cale.visible=!cale.visible
                }
            }
            CalenderFile{
                id:cale
                visible: false
                onClicked: {
                    cale.visible=false
                }
            }
        }
        UnderLine{
        }
    }
}
