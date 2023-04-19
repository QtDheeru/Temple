import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import "../../components"
import Utils 1.0

Item {
    id  : _root
    Layout.fillWidth: true
    function setSevaType(sevaType){
        console.log("Seva Type ="+sevaType.sevaTypeName);
        sevatypeName._data = sevaType.sevaTypeName;
        sevaCode._data = sevaType.sevaTypeId
    }

    Rectangle{
        id:rect
        color: "skyblue"
        anchors.fill: parent
        border.width: 1
        border.color: "black"
        anchors.centerIn: parent
        anchors.margins: 1

        ColumnLayout{
            id : _c1
            height: parent.height
            width: parent.width
            anchors.centerIn: parent
            anchors.margins: 5
            property int hScaleFactor : 20
            property int fontSize : width/25
            spacing: 1
            Rectangle{
                id : header
                height: 25
                color: "#00A2ED"
                Layout.alignment: Qt.AlignVCenter | Qt.AlignTop
                Layout.preferredWidth: parent.width
                Layout.topMargin: 0
                Text {
                    text :qsTr("Enter Seva Details")
                    font.bold : true
                    font.italic: true
                    font.pixelSize: 20
                    anchors.centerIn: parent
                }
            }
            MyRowEntry {
                id:sevatypeName;_labelText :qsTr("Seva Type Name")
                myHeight:parent.height/_c1.hScaleFactor
                width: parent.width
                myWidth: parent.width
                _editable:false
            }
            MyRowEntry {
                id:sevaCode;_labelText :qsTr("Seva Type Code")
                myHeight:parent.height/_c1.hScaleFactor
                width: parent.width
                myWidth: parent.width
                _editable : false
            }
            MyRowEntry {
                id:sevaName;_labelText :qsTr("Seva Name")
                myHeight:parent.height/_c1.hScaleFactor
                myWidth: parent.width
            }
            MyRowEntry {
                id:sevaId;_labelText :qsTr("Seva ID")
                myHeight:parent.height/_c1.hScaleFactor
                myWidth: parent.width
            }
            MyRowEntry {
                id:sevaCost;_labelText :qsTr("Seva Cost")
                myHeight:parent.height/_c1.hScaleFactor
                myWidth: parent.width
            }
            MyRowEntry {
                id:sevaDateStart;_labelText :qsTr("Seva Date")
                myHeight:parent.height/_c1.hScaleFactor
                myWidth: parent.width
            }
            MyRowEntry {
                id:sevaTime;_labelText :qsTr("Seva Time")
                myHeight:parent.height/_c1.hScaleFactor
                myWidth: parent.width
            }
            MyRowEntry {
                id:teerthaPrasadaCount;_labelText :qsTr("Teertha Prasada Count")
                myHeight:parent.height/_c1.hScaleFactor
                width: parent.width
                myWidth: parent.width
                _editable: teerthaPrasada.checked
                CheckBox {
                    id:teerthaPrasada;
                    x : teerthaPrasadaCount.width - 50
                    checked : true
                    z:5
                }
            }
            MyRowEntry {
                id:sankalpa;_labelText :qsTr("Sankalpa Required ?")
                myHeight:parent.height/_c1.hScaleFactor
                width: parent.width
                myWidth: parent.width
                _editable : false
                CheckBox {
                    id:sankalpaBox;
                    x : sankalpa.width - 50
                    checked : true
                    z:5
                }
            }

            MyRowEntry {
                id:userName;_labelText :qsTr("UserName")
                myHeight:parent.height/_c1.hScaleFactor
                myWidth: parent.width
            }
            RowLayout{
                width: parent.width
                height: 50
                Layout.margins: 10
                Button{
                    text:"Add"
                    Layout.fillWidth: true
                    onClicked: {
                        addNewSeva()
                        sevaProxy.sevaBookingModelData.querySevaNames()
                    }
                }
                Button{
                    text:"Modify"
                    Layout.fillWidth: true
                    onClicked: {
                        console.log("Modify Clicked")
                    }
                }
                Button{
                    text:"Delete"
                    Layout.fillWidth: true
                    onClicked: {
                        console.log("Delete Clicked")
                    }
                }
                Button{
                    text:"Clear"
                    Layout.fillWidth: true
                    onClicked: {
                        console.log("Delete Clicked")
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

        Component{
            id : seva
            SevaName{}
        }
    }
    Component.onCompleted: {
        header.width = _root.width
    }

    function addNewSeva(){
        console.log("SevaNameEntry.qml - Addclicked")
        var sevaObj = seva.createObject(null);
        sevaObj.sevaName = sevaName._data
        sevaObj.sevaId = parseInt(sevaId._data);
        sevaObj.sevaType = parseInt(sevaCode._data);
        sevaObj.sevaCost = sevaCost._data;
        sevaObj.sevaStartDate = sevaDateStart._data;
        sevaObj.sevaStartTime = sevaTime._data
        sevaObj.teerthaPrasada = parseInt(teerthaPrasadaCount._data)
        sevaObj.sankalpa = sankalpa._data
        sevaObj.userName = userName._data
        var message = sevaProxy.createNewSeva(sevaObj)
        _errorDialog.showError(message)
    }
}
