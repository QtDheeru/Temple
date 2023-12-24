import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
Item
{
    property var myWidth;
    property var myHeight;
    property bool enlarge;
    property string myColor:"#9370db"
    property string myText;
    property string myTextColor:"black";
    property bool myFillWidth;
    property bool myFillHeight;
    property string myBorderColor:"black";
    property real fontSize;
    property real myRadius  /*((50/parent.width) * 100)*/
    property bool myTextBold: true

    signal myClick();
    signal myEntered();
    signal myExited();

    Layout.fillHeight: myFillHeight
    Layout.fillWidth: myFillWidth
    width:myWidth
    height:myHeight

    Rectangle
    {
        id: _root
        anchors.fill: parent
        color: myColor
        border.color: myBorderColor
        radius: myRadius
        Text
        {
            text: myText
            color: myTextColor
            font.bold: myTextBold
            anchors.centerIn: parent
            font.pixelSize: fontSize
        }

        MouseArea
        {
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                myClick()
            }
            onEntered: {
                myEntered()
                scalarEntered.running = enlarge
            }
            onExited: {
                myExited()
                scalarExited.running = enlarge
            }
        }
    }
    ScaleAnimator{
        id: scalarEntered
        target: _root
        from: 1
        to: 1.06
        running: false
    }

    ScaleAnimator{
        id: scalarExited
        target: _root
        from: 1.06
        to: 1
        running: false
    }
}
