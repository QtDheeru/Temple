import QtQuick 2.0

Component
{
    id: _comp1
    Item {
        width: parent.width
        height: 40

        Rectangle {
            anchors.fill: parent
            color: "lightgrey"
            border.color: "black"
            border.width: 1
            Text
            {
                text: styleData.value
                font.bold: true
                anchors.centerIn: parent
                font.pixelSize: 15
            }
        }
    }

}
