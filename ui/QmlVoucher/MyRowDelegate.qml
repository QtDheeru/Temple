import QtQuick 2.0

Component
{
    id: rowDelegate
    Rectangle
    {
        id: _rect
        width:parent.width
        height:40
        color: styleData.selected ? "lightblue" : "white"
        Rectangle {
            width: parent.width
            height: 1
            anchors.bottom: parent.bottom
            color: "black"
        }
    }
}
