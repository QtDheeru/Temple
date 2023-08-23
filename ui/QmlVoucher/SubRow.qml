import QtQuick 2.0

Component
{
    id: _customDelegate1

    Item {
        width: parent.width
        height: 37

        Rectangle
        {
            id: _rec7
            anchors.fill: parent
            color: styleData.selected ? "lightblue" : "white"
            border.color: "white"
            border.width: 1
            Rectangle {
                width: parent.width
                height: 2
                anchors.bottom: parent.bottom
                color: styleData.selected ? "lightblue" : "white"
                border.color: "black"
                border.width: 1
            }
        }
    }
}
