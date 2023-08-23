import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Button{
    property string btxt;
    signal mouseClicked();
    text: btxt
    font.pixelSize: 13
    font.bold: true
    Layout.fillWidth: true
    Layout.preferredHeight: 35

    background:Rectangle{
        radius:20
        color:"lightgrey"
        MouseArea{
            anchors.fill: parent
            onClicked:{
                mouseClicked()
            }
        }
    }
}

