import QtQuick 2.0
Rectangle{
    id:rect
    property string headOrText1;
    property string headOrText2;
    property string headOrText3;
    property string headOrText4;

    property int horAddfontSize1;
    property int horAddfontSize2;
    property int horAddfontSize3;
    property int horAddfontSize4;

    property color hOrAddTextcolor1;
    property color hOrAddTextcolor2;
    property color hOrAddTextcolor3;
    property color hOrAddTextcolor4;

    property bool hOrAddtextBold1;
    property bool hOrAddtextBold2;
    property bool hOrAddtextBold3;
    property bool hOrAddtextBold4;

    property int colSpacing;

    Column{
        width:parent.width
        anchors.centerIn: parent
        spacing:colSpacing
        Text {
            id:txt1
            text:rect.headOrText1;
            color:rect.hOrAddTextcolor1
            font.pixelSize: rect.horAddfontSize1
            horizontalAlignment: Text.AlignHCenter
            font.bold: rect.hOrAddtextBold1
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text {
            id:txt2
            text:rect.headOrText2;
            color:rect.hOrAddTextcolor2
            font.pixelSize: rect.horAddfontSize2
            horizontalAlignment: Text.AlignHCenter
            font.bold: rect.hOrAddtextBold2
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text {
            id:txt3
            text:rect.headOrText3;
            color:rect.hOrAddTextcolor3
            font.pixelSize: rect.horAddfontSize3
            horizontalAlignment: Text.AlignHCenter
            font.bold: rect.hOrAddtextBold3
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text {
            id:txt4
            text:rect.headOrText4;
            color:rect.hOrAddTextcolor4
            font.pixelSize: rect.horAddfontSize4
            horizontalAlignment: Text.AlignHCenter
            font.bold: rect.hOrAddtextBold4
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

}

