import QtQuick 2.0
import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: root
    anchors.fill: parent
    width: 800;height: 600
    color: "#F4C430"
    TableView{
        id:table
        //anchors.top: searchBar.bottom
        height: parent.height
        width: parent.width
        model: sevaProxy.allReportModel
        columnSpacing: 1
        rowSpacing: 1
        clip: true
        onMovementStarted: {
            if(table.movingHorizontally){
                flickableDirection = table.Flickable.HorizontalFlick
                return
            }
            if(table.movingVertically)
                flickableDirection = table.Flickable.VerticalFlick            
        }
        onMovementEnded: flickableDirection = table.Flickable.AutoFlickIfNeeded
        ScrollBar.vertical: ScrollBar {
            id: vbar
            anchors.top:  table.top
            width: 10
            height: 10
            active: !hbar.active
            contentItem: Rectangle {
                id:contentItem_rect
                width:10
                implicitHeight:20
                radius: implicitHeight/2
                color: "gray"
            }
        }
        ScrollBar.horizontal:  ScrollBar {
            id: hbar
            anchors.bottom: table.bottom
            width: 10
            height: 10
            active: !vbar.active
            contentItem: Rectangle {
                id:contentItem_rect2
                height:10
                implicitWidth: 4
                radius: implicitHeight/2
                color: "gray"
            }
        }
        delegate: Rectangle{
            implicitHeight: header ? 30 :20
            implicitWidth: name2.width + 50
            color: header ? "yellow" :"skyblue"
            border.width: header ? 3:1
            clip: true
            Text {
                id: name2
                text: DevoteeName
                clip: true
                font.bold: header
                font.pixelSize: header  ? 20:12
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: 5
                horizontalAlignment: TextInput.AlignLeft
                verticalAlignment: TextInput.AlignLeft
            }
        }
    }

}
