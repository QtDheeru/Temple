import QtQuick 2.0
import QtQuick.Controls 2.5
import "../components"

Rectangle {
    id:_mainrect
    height: parent.height
    width: parent.width
    color: "cornflowerblue"
    border.color: "black"
    border.width: 4
    focus: true
    signal loadUserManagement();
    signal loadMenuPage()
    signal admin()
    signal loadBankRegistration()
    signal loadVoucherAdministration();
    signal showAllDataView()
    property int buttonsCount : 5

    Grid{
        anchors.fill: parent
        rows: 2
        columns: 3
        spacing : parent.height/15
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: parent.height/10
        anchors.leftMargin: parent.width/8


        TempleButton{
            id:_usermanagement
            width: parent.width/4
            height: parent.height/3
            color: "aqua"
            buttonText: "USER MANAGEMENT"
            border.width: _mainrect.width/300
            onButtonClikcked: {
                console.log("User Management button clicked");
                loadUserManagement()
            }
        }
        TempleButton{
            id:_addSeva
            width:parent.width/4
            height: parent.height/3
            color: "aqua"
            buttonText: "ADD SEVA"
            border.width: _mainrect.width/300
            onButtonClikcked: {
                console.log("AddSeva button clicked");
                admin()
            }
        }
        TempleButton{
            id:_allData
            width:parent.width/4
            height: parent.height/3
            color: "aqua"
            buttonText: "ALL DATA"
            border.width: _mainrect.width/300
            onButtonClikcked: {
                console.log("AddSeva button clicked");
                showAllDataView()
            }
        }
        TempleButton{
            id:_usermanagement1
            width:parent.width/4
            height: parent.height/3
            color: "aqua"
            buttonText: "BANK REGISTER"
            border.width: _mainrect.width/300
            onButtonClikcked: {
                console.log("User Management button clicked");
                checkEntry.fetchFromDataBase()
                loadBankRegistration()
                myModel.initial();
            }
        }
        TempleButton{
            id:_addSeva2
            width:parent.width/4
            height: parent.height/3
            color: "aqua"
            buttonText: "VOUCHER ADMINISTRATION"
            border.width: _mainrect.width/300
            onButtonClikcked:
            {
                console.log("voucher admin..button clicked");
                loadVoucherAdministration();
            }
        }
        Keys.onEscapePressed: {
            console.log("AdminRights :: Esc pressed")
            loadMenuPage()
        }
    }
    Keys.onEscapePressed: {
        console.log("AdminRights :: Esc pressed")
        loadMenuPage()
    }
}
