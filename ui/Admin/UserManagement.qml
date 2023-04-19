import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQml.Models 2.15
import "../components"

Rectangle{
    id:rect
    color: "skyblue"
    anchors.fill: parent
    signal loadAdminrights();
    signal loadMenuPage()
    Label{
        id:_header
        text:"Admin Actions"
        font.pixelSize: parent.width/50
        anchors.horizontalCenter: parent.horizontalCenter
    }
    ListModel{
        id: rolemodel
        ListElement { text: "Admin" }
        ListElement { text: "Others" }
    }

    Rectangle{
        id:entryrect
        height: parent.height/1.15
        width: parent.width/1.15
        border.width: 0.5
        color: "transparent"
        anchors.centerIn: parent
        Column{
            id:column
            height: parent.height/1.5
            width: parent.width/1.25
            spacing: parent.height/25
            anchors.centerIn: parent
            MyRowEntry {
                id:_name;
                _labelText :qsTr("Name:")
                myHeight:parent.height/7
                myWidth: parent.width/1.2
                fontPixelSize: parent.width/25
                anchors.left: parent.left
                anchors.leftMargin: parent.width/5
            }
            MyRowEntry {
                id:_lastname;
                _labelText :qsTr("Last Name:")
                myHeight:parent.height/7
                myWidth: parent.width/1.2
                fontPixelSize: parent.width/25
                anchors.left: parent.left
                anchors.leftMargin: parent.width/5
            }
            MyRowEntry {
                id:userid;
                _labelText :qsTr("UserID:")
                myHeight:parent.height/7
                myWidth: parent.width/1.2
                fontPixelSize: parent.width/25
                anchors.left: parent.left
                anchors.leftMargin: parent.width/5
            }
            MyRowEntry {
                id:_password;
                _labelText :qsTr("Password:")
                myHeight:parent.height/7
                myWidth: parent.width/1.2
                fontPixelSize: parent.width/25
                anchors.left: parent.left
                anchors.leftMargin: parent.width/5
            }
            MyComboEntry{
                id:myrole
                myHeight:parent.height/10
                myWidth: parent.width/1.6
                fontPixelSize: parent.width/25
                comboBoxFontSize: parent.width /35
                rowspacing: 120
                _labelText :qsTr("Role:")
                isEditable: true
                _dataModel:rolemodel
                anchors.left: parent.left
                anchors.leftMargin: parent.width/5
            }
        }
        Row{
            width: parent.width
            height: parent.height/10
            spacing: parent.width/25
            anchors.left: parent.left
            anchors.leftMargin: parent.width/21
            anchors.top: column.bottom
            anchors.topMargin: parent.height/25
            Button{
                text:"Add User"
                height: parent.height
                width: parent.width/5
                anchors.verticalCenter: parent.verticalCenter
                onClicked: {
                    console.log("user Addclicked")
                    sevaProxy.userManagement.addUser(_name._data,_lastname._data,userid._data,_password._data,myrole._data,"")
                }
            }
            Button{
                text:"ModifyUser"
                height: parent.height
                width: parent.width/5
                anchors.verticalCenter: parent.verticalCenter
                onClicked: {
                    console.log("user Modify Clicked")
                }
            }
            Button{
                text:"DeleteUser"
                height: parent.height
                width: parent.width/5
                anchors.verticalCenter: parent.verticalCenter
                onClicked: {
                    console.log(" user Delete Clicked")
                }
            }
            Button{
                text:"Clear"
                height: parent.height
                width: parent.width/5
                anchors.verticalCenter: parent.verticalCenter
                onClicked: {
                    console.log("Delete Clicked")
                    _name._data = ""
                    _lastname._data = ""
                    userid._data = ""
                    _password._data=""
                }
            }
        }
    }

    DisplayDialog {
        id :_errorDialog
        visible: false
        width: 600
        function showMsg(message){
            _errorDialog.visible = true;
            _errorDialog.text2Display = message
            _errorDialog.open();
            //_errorDialog.visible = false;
        }
    }
    Connections{
        id:connection
        target: sevaProxy.userManagement
        onUserAdded:{
            _errorDialog.showMsg(msg)
        }
    }
    Keys.onEscapePressed: {
        loadMenuPage()
    }
}
