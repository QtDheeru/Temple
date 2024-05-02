import QtQuick 2.15
import QtQuick.Layouts 1.3

RowLayout{spacing: 1
    signal loadAdminrights();
    Rectangle
    {
        color: "lightgrey"
        Layout.maximumWidth:parent.width/2
        Layout.fillWidth: true
        Layout.fillHeight: true
        CashAdmin{
            anchors.fill: parent
        }
    }
    Rectangle{
        color: "lightgrey"
        Layout.maximumWidth:parent.width/2
        Layout.fillWidth: true
        Layout.fillHeight: true
        CheckList{
            Layout.maximumWidth: parent.width-100
            Layout.maximumHeight: parent.height-200
        }
    }

    Keys.onEscapePressed: {
        loadAdminrights()
        console.log("Esc pressed in Integrate file")
    }

}

