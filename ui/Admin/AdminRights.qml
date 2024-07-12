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

    property int buttonsCount : 5
    property string fileName: "AdminRights.qml "

    signal loadUserManagement();
    signal loadMenuPage()
    signal admin()
    signal loadBankRegistration()
    signal loadVoucherAdministration();
    signal showAllDataView()
    signal loadProfitAndLossBasePage()

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
            id: _addSeva
            width: parent.width/4
            height: parent.height/3
            color: "aqua"
            buttonText: "ADD SEVA"
            border.width: _mainrect.width/300
            onButtonClikcked: {
                console.log(fileName + "AddSeva button clicked");
                admin()
            }
        }
        TempleButton{
            id: _allData
            width: parent.width/4
            height: parent.height/3
            color: "aqua"
            buttonText: "ALL DATA"
            border.width: _mainrect.width/300
            onButtonClikcked: {
                console.log(fileName + "AddSeva button clicked");
                showAllDataView()
            }
        }
        TempleButton{
            id: _bankRegister
            width: parent.width/4
            height: parent.height/3
            color: "aqua"
            buttonText: "BANK REGISTER"
            border.width: _mainrect.width/300
            onButtonClikcked: {
                console.log(fileName + "User Management button clicked");
                checkEntry.fetchFromDataBase()
                loadBankRegistration()
                myModel.initial();
            }
        }
        TempleButton{
            id: _voucher
            width:parent.width/4
            height: parent.height/3
            color: "aqua"
            buttonText: "VOUCHER ADMINISTRATION"
            border.width: _mainrect.width/300
            onButtonClikcked:
            {
                console.log(fileName + "voucher button clicked");
                loadVoucherAdministration();
            }
        }
        TempleButton{
            id: _profitNLoss
            width:parent.width/4
            height: parent.height/3
            color: "aqua"
            buttonText: "Profit And Loss"
            border.width: _mainrect.width/300
            onButtonClikcked:
            {
                console.log(fileName + "Profit And Loss button clicked");
                loadProfitAndLossBasePage();
            }
        }
        Keys.onEscapePressed: {
            console.log(fileName + " Esc pressed")
            loadMenuPage()
        }
    }
    Keys.onEscapePressed: {
        console.log(fileName + " Esc pressed")
        loadMenuPage()
    }
}
