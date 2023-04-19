import QtQuick 2.0
import QtQuick.Controls 2.5
import "../components"

Rectangle{
    id:rect

    color: "skyblue"

    function setSevaType(sevaType){
        console.log("Seva Type ="+sevaType.sevaTypeName);
        sevatypeName._data = sevaType.sevaTypeName;
        sevaCode._data = sevaType.sevaTypeId
    }

    Column{
        id:col
        height:parent.height
        width:parent.width
        spacing: 100
        anchors.centerIn: parent
        Rectangle{
            id:entryrect
            height: parent.height/1.5
            width: parent.width/1.5
            border.width: 0.5
            color: "transparent"
            anchors.horizontalCenter: parent.horizontalCenter
            Column{
                height: parent.height/1.1
                width: parent.width/1.75
                anchors.centerIn: parent
                spacing: parent.height/14
                MyRowEntry {
                    id:sevatypeName;_labelText :qsTr("Name")
                    myHeight:parent.height/5
                    myWidth: parent.width
                    fontPixelSize: parent.width/20
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                MyRowEntry {
                    id:sevaCode;_labelText :qsTr("SevaCode")
                    myHeight:parent.height/5
                    myWidth: parent.width
                    fontPixelSize: parent.width/20
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                MyRowEntry {
                    id:userName;_labelText :qsTr("UserName")
                    myHeight:parent.height/5
                    myWidth: parent.width
                    fontPixelSize: parent.width/20
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Row{
                    width: parent.width
                    height: 80
                    spacing: parent.width/12
                    anchors.left: parent.left
                    anchors.leftMargin: parent.width /(-7)
                    Button{
                        text:"Add"
                        anchors.verticalCenter: parent.verticalCenter
                        onClicked: {
                            console.log("Add userclicked")
                            var message = sevaProxy.addNewSevaType(sevatypeName._data,sevaCode._data,userName._data)
                             sevaProxy.sevaBookingModelData.querySevaType();
                            _errorDialog.showError(message)
                        }
                    }
                    Button{
                        text:"Modify"
                        anchors.verticalCenter: parent.verticalCenter
                        onClicked: {
                            console.log("Modify Clicked")
                        }
                    }
                    Button{
                        text:"Delete"
                        anchors.verticalCenter: parent.verticalCenter
                        onClicked: {
                            console.log("Delete Clicked")
                        }
                    }
                    Button{
                        text:"Clear"
                        anchors.verticalCenter: parent.verticalCenter
                        onClicked: {
                            console.log("Delete Clicked")
                            sevatypeName._data = ""
                            sevaCode._data = ""
                            userName._data = ""
                        }
                    }
                }
            }
        }

        DisplayDialog {
            id :_errorDialog
            visible: false
            width: 600
            function showError(message){
                _errorDialog.visible = true;
                _errorDialog.text2Display = message
                _errorDialog.open();
                //_errorDialog.visible = false;
            }
        }
        Connections{
            id:connection
            target: sevaProxy
            onErrorMessage:{
                _errorDialog.showError(errMsg)
            }
        }
    }
}
