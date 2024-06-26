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
    signal loadLogin(int pagecount);
    signal sevabooking();
    signal accountDetails();
    signal bookingreport();
    signal admin();
    signal loadAdminrights()
    signal loadLogOut()
    signal loadMenuPage();
    signal loadDevoteeSelection()
    signal voucher();
    signal errorOccur(string errorMsg);
    property int countIfSevaNamesPresentInSevaTypes:0;
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
                loadDevoteeSelection()
                //               console.log("Seva Booking Button Clicked");
            }
        }
        TempleButton{
            id:button2
            width:_menupage.width/4
            height: _menupage.height/5
            color: "aqua"
            buttonText: "ACCOUNT DETAILS"
            border.width: _menupage.width/300
            enabled: sevaProxy.userManagement.rolenum === 1
            opacity: sevaProxy.userManagement.rolenum === 1 ? 1 :0.4
            onButtonClikcked: {
                console.log("account details button clicked");
                accountDetails();
                if(sevaProxy.userManagement.rolenum !== 1){
                    _adminmsg.showMsg("Admin Access Only!")
                } else {
                    console.log("this is admin")
                }
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
                // _errorPopup.open()
            }
        }
        TempleButton{
            id:button4
            width: _menupage.width/4
            height: _menupage.height/5
            color: "aqua"
            buttonText: "ADMIN"
            enabled: sevaProxy.userManagement.rolenum === 1
            opacity: sevaProxy.userManagement.rolenum === 1 ? 1 : 0.4
            border.width: _menupage.width/300
            onButtonClikcked: {
                loadAdminrights()
                console.log("admin button clicked")
                if(sevaProxy.userManagement.rolenum !== 1){
                    _adminmsg.showMsg("Admin Access Only!")
                }
                else{
                    console.log("this is admin")
                }
            }
        }
        TempleButton{
            id:button5
            width:_menupage.width/4
            height: _menupage.height/5
            color: "aqua"
            buttonText: "LOGOUT"
            border.width: _menupage.width/300
            onButtonClikcked: {
                loadLogOut()
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
                console.log("Voucher button clicked");
                voucher();
                _errorPopup.open()
            }
        }
        DisplayDialog{
            id:_errorPopup
            visible: false
            text2Display :"Not Implemented"
            onNoAction: {
                _errorPopup.close()
            }
        }
    }

    Loader{
        id:_loginloader
        height: parent.height/1.9
        width: parent.width/2.75
        anchors.centerIn: parent
    }
    Connections{
        id:_connection
        target:_menupage
        function onLoadLogin(pagecount){
            console.log("Inside LoadLogin")
            if(pagecount===2){
                console.log("Inside LoadLogin count2")
                _loginloader.setSource("qrc:/ui/Login.qml",{imgVisible:false,pageNumber:pagecount});
            }
            else if(pagecount === 4){
                console.log("Inside LoadLogin count4")
                _loginloader.setSource("qrc:/ui/Login.qml",{imgVisible:false,pageNumber:pagecount});
            }
        }
    }
    Connections{
        id:_loaderConnection
        target: _loginloader.item
        function onLoginSuccess(pcount){
            if(pcount===0){
                _loginloader.anchors.fill = parent
                loader.source = "MenuPage.qml"}
            if(pcount===2){
                _loginloader.anchors.fill = parent
                console.log("Inside pcount 2")
                loader.source = "qrc:/ui/Reports/Account/SevaReportPage.qml"
            }
            if (pcount === 4){
                _loginloader.anchors.fill = parent
                console.log("Inside pcount 4")
                loader.source = "qrc:/ui/Admin/AdminRights.qml"
            }
        }
        function onCloseWindow(){
            _loginloader.active= false
        }
        function onLoadUserManagement(){
            console.log("User Management loading")
            loader.source = "qrc:/ui/Admin/UserManagement.qml"
        }
    }
    Component.onCompleted: {
        console.log("the accounts enable",button2.enabled)
    }
//    Connections{
//        target:button1
//        function onLoadMenuPage(){
//            loadMenuPage()
//        }
//    }
}
