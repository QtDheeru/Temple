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
    Row{
        height: parent.height/5
        width: parent.width/1.5
        spacing: parent.width/10
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: parent.width/9
        TempleButton{
            id:_usermanagement
            width:parent.width/2
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
    Keys.onEscapePressed: {
        console.log("Esc pressed")
        loadMenuPage()
    }
}
