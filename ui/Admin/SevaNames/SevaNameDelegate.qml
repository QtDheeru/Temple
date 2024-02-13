import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

RowLayout{
    width: parent.width
    height: 30
    spacing: 1
    signal itemClicked(int idx)
    Button {
        text : index
        height: parent.height
        background: Rectangle{color : "skyblue"}
        Layout.minimumWidth: 50
        Layout.maximumWidth: 50
        Layout.preferredWidth:  50
        Layout.fillHeight: true
        onClicked:
        {
           itemClicked(index)
        }
    }

    Button {
        id : b1
        Layout.fillWidth: true
        background: Rectangle{color : "skyblue"}
        Layout.maximumWidth: 400
        Layout.minimumWidth: 300
        contentItem: Text {
            id : _t1
            text : SevaName
            font.pixelSize: 20
            color: "black"
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignVCenter
        }
        onClicked:
        {
           itemClicked(index)
        }
    }
    Button {
        id : b2
        background: Rectangle{color : "skyblue"}
        Layout.fillWidth: true

        contentItem: Text {
            id : _t2
            text : SevaId
            font.pixelSize: 20
            color: "black"
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignVCenter
        }
        onClicked:
        {
           itemClicked(index)
        }

    }
    Component.onCompleted: {
        console.log("SevaNameDelegate is created........")
    }
}


