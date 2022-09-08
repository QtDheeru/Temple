import QtQuick 2.0
import QtQuick.Controls 2.5
import "./components"

Rectangle {
    id:_menupage
    property var styles : MyStyles{}
    anchors.fill: parent
    color: "cornflowerblue"
    border.color: "black"
    border.width: 4
    signal sevabooking();
    signal accountDetails();
    signal bookingreport();
    signal admin();
    signal closeProject();
    signal voucher();
    Grid{
        id:grid
        columns: 3
        rows: 3
        spacing: parent.width/20
        anchors.top: parent.top
        anchors.topMargin: parent.height/4
        anchors.left: parent.left
        anchors.leftMargin: parent.width/14
        TempleButton{
            id:button1
            width:_menupage.width/4
            height: _menupage.height/5
            border.width: _menupage.width/300
            color: "aqua"
            buttonText: "SEVA BOOKING"
            onButtonClikcked: {
                console.log("Seva Booking Button Clicked");
                sevabooking();
            }
        }
        TempleButton{
            id:button2
            width:_menupage.width/4
            height: _menupage.height/5
            color: "aqua"
            buttonText: "ACCOUNT DETAILS"
            border.width: _menupage.width/300
            onButtonClikcked: {
                console.log("account details button clicked");
                accountDetails();
                //_errorDialog.open()
            }
        }
        TempleButton{
            id:button3
            width:_menupage.width/4
            height: _menupage.height/5
            color: "aqua"
            buttonText: "BOOKING REPORT"
            border.width: _menupage.width/300
            onButtonClikcked: {
                console.log("booking report button clicked");
                bookingreport();
                _errorDialog.open()
            }
        }
        TempleButton{
            id:button4
            width:_menupage.width/4
            height: _menupage.height/5
            color: "aqua"
            buttonText: "ADMIN"
            border.width: _menupage.width/300
            onButtonClikcked: {
                console.log("admin button clicked")
                admin();
                _errorDialog.open()
            }
        }
        TempleButton{
            id:button5
            width:_menupage.width/4
            height: _menupage.height/5
            color: "aqua"
            buttonText: "CLOSE PROJECT"
            border.width: _menupage.width/300
            onButtonClikcked: {
                console.log("close button clicked");
                closeProject();
                _errorDialog.open()
            }
        }
        TempleButton{
            id:button6
            width:_menupage.width/4
            height: _menupage.height/5
            color: "aqua"
            buttonText: "VOUCHER"
            border.width: _menupage.width/300
            onButtonClikcked: {
                console.log("voucher button clicked");
                voucher();
                _errorDialog.open()
            }
        }
        DisplayDialog{
            id:_errorDialog
            visible: false
            text2Display :"Not Implemented"
        }
    }
    Keys.onEscapePressed: {
        console.log("Esc pressed in select seva type view")
        this.close()
    }
}
