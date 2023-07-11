import QtQuick 2.0
import "../components"
import "./SevaNames"
import QtQuick.Layouts 1.3

Rectangle {
    //color: "red"
    anchors.fill: parent
    anchors.centerIn: parent
    anchors.margins: 5
    signal loadMenuPage()
    focus: true
    ColumnLayout{
        anchors.fill: parent
        anchors.centerIn: parent
        anchors.margins: 5
        spacing: 1
        MyHeader{
            height: 50
            Layout.minimumHeight: 50
            Layout.fillWidth: true
        }
        SevaActionSelector{
            id:_actionSelector
            Layout.minimumHeight: 40
            Layout.fillWidth: true
        }
        RowLayout{
            width: parent.width
            Layout.preferredHeight: 500
            Layout.fillHeight: true
            spacing: 1
            SevaTypeDetailView{
                id:sevatypecomp
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.minimumWidth: 100
                Layout.preferredWidth: 200
            }
            SevaTypeEntryPage{
                id : sevaTypeEntry
                Layout.fillWidth: true
                height:  parent.height
                Layout.fillHeight: true
                Layout.minimumWidth: 100
                Layout.preferredWidth: 200
                visible: _actionSelector.sevaTypeSelected
                Layout.alignment: Qt.AlignVCenter
            }
            SevaNameEntry{
                id : sevaNameEntry
                Layout.fillWidth: true
                height:  parent.height
                Layout.fillHeight: true
                Layout.minimumWidth: 100
                Layout.preferredWidth: parent.width/6
                visible: _actionSelector.sevaNameSelected
            }
        }

        Connections{
             target : sevatypecomp
             onSevaTypeSelected :{
                 sevaTypeEntry.setSevaType(sevaType);
                 sevaNameEntry.setSevaType(sevaType);
             }
        }
    }
    Keys.onEscapePressed: {
        console.log("Esc pressed in Admin Page...")
        //this.close()
        loadMenuPage()
    }
    Component.onCompleted: {
        console.log("Admin Page is created........")

    }
}
