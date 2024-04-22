import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import SevaBookingElement 1.0
import "./components"
Rectangle{
    id:_root
    width: parent.width
    height: parent.height
    signal loadSevaBookingView();
    signal loadvoucher(var bookedObj,int pageNo);
    signal loadCancelReceipt()
    //signal getCancelReceiptDetails(var clickedObj)
    property var storeObject;
    property var ve
    property int  pageNumber: 1
    signal receiptCancel(var receiptNo, var amount)
    RowLayout{
        id:searchRow
        width: _root.width
        spacing: 10
        Layout.alignment: Qt.AlignHCenter
        Layout.topMargin: _root.width/20
        SevaComboBox
        {
            id: _combo
        }
        SevaSearchBar
        {
            id: _searchBar
            Layout.maximumWidth: 700
            Layout.maximumHeight: 50
            onAccepted: _search.clicked()
            Keys.onDeletePressed: _clear.clicked()
            onTextEdited:
            {
                //                sevaProxy.sevaBSearchModel.updateTableModel(txt, _combo.currentText)
            }
            onTextChanged: sevaProxy.sevaBSearchModel.updateTableModel(txt, _combo.currentText)
        }
        Button{id:clear;text: "clear";onClicked: _searchBar.clear()}
    }
    TableView{
        id: lv1
        model: sevaProxy.sevaBSearchModel
        width: parent.width
        height: parent.height - searchRow.height
        anchors.top: searchRow.bottom
        anchors.topMargin: parent.height/100
        property var selectedRow;
        style: TableViewStyle {
            headerDelegate: Rectangle {
                height: 30
                color: "lightsteelblue"
                Text {
                    id: headerItem
                    anchors.centerIn: parent
                    text: styleData.value
                    font.bold: true
                    font.pixelSize: 15
                    font.family: "Helvetica"
                }
                Rectangle {
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    width: 1
                    color: "black"
                }
            }
            rowDelegate: Rectangle {
                id:r1
                height:40
                color: styleData.selected ? "skyblue" : "white"
                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton | Qt.RightButton
                    propagateComposedEvents: true
                    onClicked: {
                        console.log("mouse clicked right or left styleData.selected " + styleData.selected)

                        // clear any other selected row
                        lv1.selection.clear()

                        // select this row
                        lv1.currentRow = styleData.row
                        lv1.selection.select(styleData.row)

                        console.log("clicked cell in table view ",lv1.currentRow)

                        // convert mouse position from delegate to tableview coordinates
                        var coordinates = r1.mapToItem(lv1, mouse.x, mouse.y);
                        console.log("clicked cell in table view coordinates = ",coordinates)

                        // active and click the appropriate items (internal)
                        var clickIndex = lv1.__listView.indexAt(0, coordinates.y + lv1.__listView.contentY)
                        console.log("clicked cell in table view clickIndex = ",clickIndex)
                        if (clickIndex > -1) {
                            if (lv1.__activateItemOnSingleClick) lv1.activated(clickIndex)
                            lv1.clicked(clickIndex)
                        }
                        // consume the mouse event
                        mouse.accepted = true
                        if (mouse.button == Qt.LeftButton)
                        {
                            console.log("Left")

                            var v = sevaProxy.sevaBSearchModel.getRowOfDataFromTableViewModel(lv1.currentRow);
                            console.log("row of data of TB :" + v)
                            ve = sevaProxy.sevaBookingTV.getRowOfData(v);

                            // _allViewDataDialog._serialNo = ve.serial_no
                            _allViewDataDialog._personId = ve.person_id
                            _allViewDataDialog._devoteeName = ve.person.devoteeName
                            _allViewDataDialog._mobileNo= ve.person.mobileNumber
                            _allViewDataDialog._gothra= ve.person.gothra
                            _allViewDataDialog._nakshatra= ve.person.nakshatra
                            _allViewDataDialog._sevaType= ve.sevatype
                            _allViewDataDialog._sevaName= ve.sevaname
                            _allViewDataDialog._quantity= ve.quantity
                            _allViewDataDialog._receiptDate= ve.receiptDate
                            _allViewDataDialog._sevaDate= ve.sevaDate
                            _allViewDataDialog._totalCost= ve.totalCost
                            _allViewDataDialog._cash= ve.cash
                            _allViewDataDialog._bank= ve.bank

                            _sevaBookingElement.sno = ve.sno
                            _sevaBookingElement.person_id = ve.person_id
                            _sevaBookingElement.person.devoteeName = ve.person.devoteeName
                            _sevaBookingElement.person.mobileNumber= ve.person.mobileNumber
                            _sevaBookingElement.person.gothra= ve.person.gothra
                            _sevaBookingElement.person.nakshatra= ve.person.nakshatra
                            _sevaBookingElement.sevatype= ve.sevatype
                            _sevaBookingElement.sevaname= ve.sevaname
                            _sevaBookingElement.quantity= ve.quantity
                            _sevaBookingElement.receiptDate= ve.receiptDate
                            _sevaBookingElement.sevaDate= ve.sevaDate
                            _sevaBookingElement.totalCost= ve.totalCost
                            _sevaBookingElement.cash= ve.cash
                            _sevaBookingElement.bank= ve.bank
                            _sevaBookingElement.note = ve.note
                        }
                        else if (mouse.button == Qt.RightButton)
                        {
                            console.log("Right")
                            contextMenu.popup()
                            // var ve = sevaProxy.sevaBookingTV.getRowOfData(lv1.currentRow);
                            var v = sevaProxy.sevaBSearchModel.getRowOfDataFromTableViewModel(lv1.currentRow);
                            console.log("///////////////////"+v)
                            ve = sevaProxy.sevaBookingTV.getRowOfData(v);

                            //  _allViewDataDialog._serialNo = ve.serial_no
                            _allViewDataDialog._personId = ve.person_id
                            _allViewDataDialog._devoteeName = ve.person.devoteeName
                            _allViewDataDialog._mobileNo= ve.person.mobileNumber
                            _allViewDataDialog._gothra= ve.person.gothra
                            _allViewDataDialog._nakshatra= ve.person.nakshatra
                            _allViewDataDialog._sevaType= ve.sevatype
                            _allViewDataDialog._sevaName= ve.sevaname
                            _allViewDataDialog._quantity= ve.quantity
                            _allViewDataDialog._receiptDate= ve.receiptDate
                            _allViewDataDialog._sevaDate= ve.sevaDate
                            _allViewDataDialog._totalCost= ve.totalCost
                            _allViewDataDialog._cash= ve.cash
                            _allViewDataDialog._bank= ve.bank


                            _sevaBookingElement.sno = ve.sno
                            _sevaBookingElement.person_id = ve.person_id
                            _sevaBookingElement.person.devoteeName = ve.person.devoteeName
                            _sevaBookingElement.person.mobileNumber= ve.person.mobileNumber
                            _sevaBookingElement.person.gothra= ve.person.gothra
                            _sevaBookingElement.person.nakshatra= ve.person.nakshatra
                            _sevaBookingElement.sevatype= ve.sevatype
                            _sevaBookingElement.sevaname= ve.sevaname
                            _sevaBookingElement.quantity= ve.quantity
                            _sevaBookingElement.receiptDate= ve.receiptDate
                            _sevaBookingElement.sevaDate= ve.sevaDate
                            _sevaBookingElement.totalCost= ve.totalCost
                            _sevaBookingElement.cash= ve.cash
                            _sevaBookingElement.bank= ve.bank
                        }
                    }
                }
            }
            itemDelegate:Rectangle{
                id:itRect
                height:40
                color: styleData.selected ? "skyblue" : styleData.row%2 ? "light gray" : "white"

                Text {
                    text: styleData.value
                    leftPadding: 1
                    font.pixelSize: 14
                    anchors.verticalCenter:  parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 5
                }
                Rectangle{
                    anchors.right: parent.right
                    width:0.5
                    color:"gray"
                    height:parent.height
                }
            }
        }
        onClicked: {
            console.log("clicked cell in table view ",row)
            selectedRow = row
            {
                console.log("clicked cell in table view ",row)
            }
        }
        TableViewColumn {title: "Serial No"; role: "serialNo"; width: parent.width/12}
        TableViewColumn {title: "Rcpt No"; role: "RecieptNumber"; width: parent.width/12}
        //TableViewColumn {title: "Person ID"; role: "PersonID"; width: parent.width/12}
        TableViewColumn {title: "Devotee Name"; role: "DevoteeName"; width: parent.width/12}
        TableViewColumn {title: "Mobile Number"; role: "MobileNumber"; width: parent.width/12}
        //TableViewColumn {title: "Gothra"; role: "Gothra"; width: parent.width/12}
        //TableViewColumn {title: "Nakshatra"; role: "Nakshatra"; width: parent.width/12}
        TableViewColumn {title: "Seva Type"; role: "SevaType"; width: parent.width/12}
        TableViewColumn {title: "Seva Name"; role: "SevaName"; width: parent.width/12}
        TableViewColumn {title: "Quantity"; role: "Quantity"; width: parent.width/12}
        TableViewColumn {title: "Receipt Date"; role: "ReceiptDate"; width: parent.width/12}
        TableViewColumn {title: "Seva Date"; role: "SevaDate"; width: parent.width/12}
        TableViewColumn {title: "TotalCost"; role: "TotalCost"; width: parent.width/12}
        TableViewColumn {title: "Cash"; role: "Cash"; width: parent.width/12}
        TableViewColumn {title: "PymntMode"; role: "PaymentMode"; width: parent.width/12}
        TableViewColumn {title: "BANK"; role: "BankName"; width: parent.width/12}
        //TableViewColumn {title: "Reference"; role: "Reference"; width: parent.width/12}
        TableViewColumn{title: "Status";role:"Status";width: parent.width/12}
        //TableViewColumn {title: "Address"; role: "Address"; width: parent.width/9}
        //TableViewColumn {title: "Momento"; role: "Momento"; width: parent.width/12}
        //TableViewColumn {title: "BookedBy"; role: "BookedBy"; width: parent.width/12}

        Menu{
            id: contextMenu
            MenuItem {
                id:_modify
                text: qsTr('Modify')
                onTriggered: {
                    sevaProxy.sevaBookingTV
                    _allViewDataDialog.open()
                }
            }
            MenuItem {
                id: _print
                text: qsTr('Print')
                onTriggered: _allViewDataDialog.open()
            }
            MenuItem{
                id: _cancel
                text: qsTr('Cancel')
                onTriggered: {
                    storeObject = ve;
                    sevaProxy.sevaBookingTV.checkStatus(storeObject.sno);
                }
            }
        }
        DisplayDialog {
            id : _errorDialog
            visible: false
            property var page
            function showmsg(exportmsg,pageno){
                _errorDialog.page = pageno
                _errorDialog.visible = true;
                _errorDialog.text2Display = exportmsg
                _errorDialog.open();
            }
            onYesAction: {
                if(page === 1){
                    console.log("Booked Seva cancel Confirmed---",ve.sno,page)
                    loadvoucher(ve,pageNumber)
                }
                else if(page === 2){
                    console.log("Booked Seva delete Confirmed---",ve.sno)
                    sevaProxy.deletedata(ve.sno)
                }
            }
            onNoAction: {
                _errorDialog.close()
            }
        }
        AllViewDataDialog{
            id:_allViewDataDialog
            anchors.centerIn: parent

            onCloseClicked: {
                resetBaseScreen()
                _allViewDataDialog.close();
            }
            onConfirmClicked: {
                sevaProxy.printBookingReceipt(_sevaBookingElement);
                _allViewDataDialog.close();
                resetBaseScreen();
            }
            onRejected: {
                resetBaseScreen()
            }
        }

        Component.onCompleted: {
            console.log("Seva All view Page is created")
            forceActiveFocus();
        }
        SevaBookingEle{
            id:_sevaBookingElement
        }
        Keys.onEscapePressed: {
            console.log("Keys.onEscapePressed: Seva All view Page ")
            loadSevaBookingView();
        }
        Component.onDestruction: {
            console.log("TableView is destroyed");
        }
    }

    SevaCancelReceipt{
        id: sevaCancelPopup
        visible: false
        width: parent.width/1.5
        height: parent.height/1.5
        anchors.centerIn: parent

        onSevaReceiptcancelClicked:{
            console.log("onSevaReceiptcancelClicked ")
            sevaProxy.setStatusToCancel(storeObject.sno)
            receiptCancel(storeObject.sno,totalCost)
        }
        onVisibleChanged: {
            console.log("SevaCancelReceipt visiblity changed " + sevaCancelPopup.visible)
        }
    }

    DisplayDialog {
        id :_errorDialog2
        visible: false
        rectColor: "lightgreen"
        contentColor: "lightgreen"
        footerVisible:false
        function showError(message){
            console.log("inside show error2")
            _errorDialog2.z = 5
            _errorDialog2.visible = true;
            _errorDialog2.text2Display = message
            _errorDialog2.open();
            _timer.start();
        }
    }

    DisplayDialog {
        id :_errorDialog1
        visible: false
        function showError(message,pageno){
            _errorDialog1.page=pageno
            _errorDialog1.text2Display = message
            _errorDialog1.open();
            if(page===2)
                setButtons=true
            if(page===1)
                setButtons=false
        }
        onYesAction: {
            console.log("SevAllViewPage : yes Clicked")
            if(page===1){
                sevaProxy.setStatusToCancel(storeObject.sno)
                _errorDialog1.close()
            }
            if(page===2){
                _errorDialog1.close()
            }
        }
        onNoAction: {
            console.log("SevAllViewPage : No Clicked")
            _errorDialog1.close()
        }
    }

    Connections
    {
        target: sevaProxy.sevaBookingTV
        onStatusCancelledSuccess:
        {
            console.log("SevAllViewPage : Status set to cancel")
            _errorDialog2.showError("Status Set to Cancel");
        }
        onAlreadyCancelled:{
            console.log("SevAllViewPage : Status already cancelled.")
            _errorDialog1.showError("Status Already Cancelled !",2);
        }
        onLoadCancelPage:{
            console.log("SevAllViewPage : onLoadCancelPage = " + storeObject.sno)
            sevaProxy.cancelReceipt(storeObject.sno);
            sevaCancelPopup.visible = true
        }
        onNotAbleToCancel:{
            console.log("SevaAllViewPage : onNotAbleToCancel = " + storeObject.sno)
            _errorDialog2.showError("Not able to Cancel the Receipt")
        }
    }
    Connections
    {
        target: sevaProxy
        onStatusAlreadyCancelled:
        {
            console.log("SevAllViewPage : Already Cancelled status came to qml loading MyDialogBox")
            _errorDialog2.showError("Status Already Cancelled !");
        }
    }

    Timer{
        id:_timer
        running: false
        interval: 1500
        onTriggered: {
            _errorDialog2.close();
            console.log("timer is triggered #######")
        }
    }

    Keys.onEscapePressed: {
        console.log("Keys.onEscapePressed: Seva All view Page 333")
        loadSevaBookingView()
    }

    function resetBaseScreen()
    {
        _allViewDataDialog.opacity = 1
    }

    Component.onCompleted: {
        console.log("SevaAllViewPage is created...")
    }

    Component.onDestruction: {
        console.log("SevaAllViewPage is destroyed")
        sevaProxy.cleanBookingTableModel()
    }

}
