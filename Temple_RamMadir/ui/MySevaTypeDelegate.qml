import QtQuick 2.0

Rectangle{
    width: 230;height: 150;
    color: "#F4C430"
    border.width: 2;
//    border.color: "red"
    signal sevaTypeSelected(int index,int sevaTypeId)
    clip: true
    Text {
        text : sevaTypeName;
        anchors.centerIn: parent
        color: "black"
        font.pixelSize: 25
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
        clip: true
    }
    MouseArea{
        anchors.fill: parent
        onClicked: sevaTypeSelected(index,sevaTypeId)
    }
}
