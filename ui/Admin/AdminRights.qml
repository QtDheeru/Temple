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
    signal loadUserManagement();
    signal loadMenuPage()
    signal admin()
    signal loadBankRegistration()
    signal loadVoucherAdministration();

    Column{
        anchors.fill: parent
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: parent.height/4
        anchors.leftMargin: parent.width/7
        spacing: 200
        Row{
            height: parent.height/5
            width: parent.width/1.5
            spacing: parent.width/10
            TempleButton{
                id:_usermanagement
                width:(parent.width)/2
                height: parent.height
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
                width:parent.width/2
                height: parent.height
                color: "aqua"
                buttonText: "ADD SEVA"
                border.width: _mainrect.width/300
                onButtonClikcked: {
                    console.log("AddSeva button clicked");
                    admin()
                }
            }
        }
        Row{
            height: parent.height/5
            width: parent.width/1.5
            spacing: parent.width/10
            TempleButton{
                id:_usermanagement1
                width:parent.width/2
                height: parent.height
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
                width:parent.width/2
                height: parent.height
                color: "aqua"
                buttonText: "VOUCHER ADMINISTRATION"
                border.width: _mainrect.width/300
                onButtonClikcked: {
                    console.log("voucher admin..button clicked");
                    loadVoucherAdministration();
                }
            }
        }
    }
    Keys.onEscapePressed: {
        console.log("Esc pressed")
        loadMenuPage()
    }
}
