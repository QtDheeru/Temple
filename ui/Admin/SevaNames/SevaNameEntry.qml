import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import "../../components"
import Utils 1.0

Item {
    id  : _root
    Layout.fillWidth: true
    property var sevaNameObject
    function setSevaType(sevaType){
        console.log("Seva Type ="+sevaType.sevaTypeName);
        sevatypeName._data = sevaType.sevaTypeName;
        sevaCode._data = sevaType.sevaTypeId
    }
    function getSevaNameDetail(idx){
        console.log("inside suman getSevaNameDetail ",idx)
        sevaNameObject = sevaProxy.getSevaByIndex(idx)
        sevaName._data = sevaNameObject.sevaName
        sevaId._data = sevaNameObject.sevaId
        sevaCost._data = sevaNameObject.sevaCost
        sevaDateStart._data = sevaNameObject.sevaStartDate
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
                _data:sevaProxy.getNextSevaId()
                _editable : true
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
                        _errorDialog.showError("Do you want Modify Seva?",1)
                    }
                }
                Button{
                    text:"Close"
                    Layout.fillWidth: true
                    onClicked: {
                        console.log("Close Clicked")
                        _errorDialog.showError("Do you want close Seva?",2)
                    }
                }
                Button{
                    text:"Clear"
                    Layout.fillWidth: true
                    onClicked: {
                        console.log("clear Clicked")
                        clear()
                    }
                }
            }
        }
        DisplayDialog {
            id :_errorDialog
            visible: false
            width: 600
            z:3
            property int buttonNum
            function showError(message,buttonType){
                console.log("Inside Show Error...");
                _errorDialog.buttonNum = buttonType
                _errorDialog.visible = true;
                _errorDialog.text2Display = message
                _errorDialog.open();

            }
            onNoAction: {
                _errorDialog.close()
            }
            onYesAction: {
                if(buttonNum == 1){
                    sevaProxy.modifySeva(parseInt(sevaId._data),sevaName._data,sevaCost._data,getCurrentDate())
                }
                else if(buttonNum == 2){
                    sevaProxy.closeSeva(parseInt(sevaId._data))
                }
                else{
                    console.log("default")
                }
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
    Connections{
        id:connection
        target: sevaProxy
        property int defaultvar: 0
        onErrorMessage:{
            _errorDialog.showError(errMsg,defaultvar)
        }
        onSendStatustoQml:{
            console.log("onSendStatustoQml",status)
            _errorDialog.showError(status,defaultvar)
        }
        onSendUpdateStatustoQml:{
            console.log("onSendUpdateStatustoQml",updateStatus)
            _ernamespacenamespacenamespacenamespacenamespacenamespacenamespacenamespacenamespacenamespacenamespacerorDialog.showError(updateStatus,defaultvar)
        namespacenamespacenamespacenamespace}
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
        _errorDialog.showError(message,0)
    }

    function clear(){
        sevaName.clearData()
        sevaCost.clearData()
        sevaId.clearData()
        sevaDateStart.clearData()
        sevaDateStart._data = getCurrentDate()
        sevaId._data = sevaProxy.getNextSevaId()
    }
    function getCurrentDate() {
        var now = new Date();
        var year = now.getFullYear();
        var month = now.getMonth() + 1; // Month is zero-based
        var day = now.getDate();

        // Ensure that month and day have two digits
        if (month < 10) month = "0" + month;
        if (day < 10) day = "0" + day;

        return year + "-" + month + "-" + day;
    }
}
