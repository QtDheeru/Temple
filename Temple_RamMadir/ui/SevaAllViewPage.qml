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
    RowLayout{
        id:searchRow
        width: _root.width
        spacing: 10
        Layout.alignment: Qt.AlignHCenter
        Layout.topMargin: _root.width/20
        SevaComboBox{
            id: _combo
        }
        SevaSearchBar{
            id: _searchBar
            Layout.maximumWidth: 700
            Layout.maximumHeight: 50
            onAccepted: _search.clicked()
            Keys.onDeletePressed: _clear.clicked()
            onTextEdited: {
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
                        console.log("mouse clicked right or left styleData.selected "+styleData.selected)

                        // clear any other selected row
                        lv1.selection.clear()

                        // select this row
                        lv1.currentRow = styleData.row
                        lv1.selection.select(styleData.row)

                        //                    color= styleData.selected ? "skyblue" : "white"
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
                            //                            var ve = sevaProxy.sevaBookingTV.getRowOfData(lv1.currentRow);
                            //                            console.log("///////////////////"+lv1.currentRow)
                            //                            console.log("///////////1////////"+ve.person_id)
                            //                            console.log("////////////2///////"+ve.person.devoteeName)
                            var v = sevaProxy.sevaBSearchModel.getRowOfDataFromTableViewModel(lv1.currentRow);
                            console.log("///////////////////"+v)
                            var ve = sevaProxy.sevaBookingTV.getRowOfData(v);

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
                        }
                        else if (mouse.button == Qt.RightButton)
                        {
                            console.log("Right")
                            contextMenu.popup()
                            // var ve = sevaProxy.sevaBookingTV.getRowOfData(lv1.currentRow);
                            var v = sevaProxy.sevaBSearchModel.getRowOfDataFromTableViewModel(lv1.currentRow);
                            console.log("///////////////////"+v)
                            var ve = sevaProxy.sevaBookingTV.getRowOfData(v);

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

                //styleData.row===selectedRow ? "yellow":
                //color: styleData.row===selectedRow ? "yellow" : "white"
                Text {
                    text: styleData.value
                    // anchors.centerIn: parent
                    leftPadding: 1
                    font.pixelSize: 14
                    // elide: Text.ElideRight
                    //verticalAlignment: Text.AlignLeft
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
                //            MouseArea{
                //                anchors.fill: parent
                //                onClicked: {
                //                    console.log("Clicked cell")
                //                    var selectedRow = 2
                //                    //itemDelRect.color = styleData.row === selectedRow ? "yellow" : "white"
                //                }
                //            }
            }
        }
        onClicked: {
            console.log("clicked cell in table view ",row)
            //        var rowItem =  (sevaProxy.sevaBSearchModel).index(row)
            selectedRow = row
            //        (sevaProxy.sevaBSearchModel)
            //         if (mouse.button == Qt.RightButton)
            {
                console.log("clicked cell in table view ",row)
            }

        }

        TableViewColumn {title: "Serial No"; role: "serialNo"; width: parent.width/12
        }
        TableViewColumn {title: "Person ID"; role: "PersonID"; width: parent.width/12}
        TableViewColumn {title: "Person DbID"; role: "PersonDbID"; width: parent.width/12}
        TableViewColumn {title: "Devotee Name"; role: "DevoteeName"; width: parent.width/12
            //            elideMode: Text.ElideLeft
            //            delegate: Rectangle{
            //                //id:_totalAmountdel
            //                height:40
            //                color: styleData.row%2 ? "light gray":"white"

            //                Text {
            //                    text: styleData.value
            //                    //anchors.centerIn: parent
            //                    // elide: Qt.ElideLeft
            //                    leftPadding: 1
            //                    font.pixelSize: 14

            //                }
            //                Rectangle{
            //                    anchors.right: parent.right
            //                    width:0.5
            //                    color:"gray"
            //                    height:parent.height
            //                }
            //            }
        }
        TableViewColumn {title: "Mobile Number"; role: "MobileNumber"; width: parent.width/12}
        TableViewColumn {title: "Gothra"; role: "Gothra"; width: parent.width/12}
        TableViewColumn {title: "Nakshatra"; role: "Nakshatra"; width: parent.width/12}
        TableViewColumn {title: "Seva Type"; role: "SevaType"; width: parent.width/12}
        TableViewColumn {title: "Seva Name"; role: "SevaName"; width: parent.width/12
            //            elideMode: Text.ElideLeft
            //            delegate: Rectangle{
            //                //id:_totalAmountdel
            //                height:40
            //                color: styleData.row%2 ? "light gray":"white"

            //                Text {
            //                    text: styleData.value
            //                    //anchors.centerIn: parent
            //                    // elide: Qt.ElideLeft
            //                    leftPadding: 1
            //                    font.pixelSize: 14

            //                }
            //                Rectangle{
            //                    anchors.right: parent.right
            //                    width:0.5
            //                    color:"gray"
            //                    height:parent.height
            //                }
            //            }
        }
        TableViewColumn {title: "Quantity"; role: "Quantity"; width: parent.width/12}
        TableViewColumn {title: "Receipt Date"; role: "ReceiptDate"; width: parent.width/12}
        TableViewColumn {title: "Seva Date"; role: "SevaDate"; width: parent.width/12}
        TableViewColumn {title: "TotalCost"; role: "TotalCost"; width: parent.width/12}
        TableViewColumn {title: "Cash"; role: "Cash"; width: parent.width/12}
        TableViewColumn {title: "Bank"; role: "Bank"; width: parent.width/12}
        TableViewColumn {title: "Reference"; role: "Reference"; width: parent.width/12}
        TableViewColumn {title: "Address"; role: "Address"; width: parent.width/9}
        TableViewColumn {title: "Momento"; role: "Momento"; width: parent.width/12}
        TableViewColumn {title: "BookedBy"; role: "BookedBy"; width: parent.width/12}


        Menu{
            id: contextMenu
            MenuItem {
                text: qsTr('Modify')
                onTriggered:
                {
                    sevaProxy.sevaBookingTV
                    _allViewDataDialog.open()
                }
            }
            MenuItem {
                text: qsTr('Print')
                onTriggered:_allViewDataDialog.open()
            }
        }
        //        ShowPrintDetails{
        //            id:showPrintDetails
        //            Keys.onEscapePressed: showPrintDetails.close()

        //        }
        AllViewDataDialog{
            id:_allViewDataDialog
            anchors.centerIn: parent
            // Keys.onEscapePressed: _voucherReceiptDialog.close()
            //                    onPaymentComplete: {
            //                        console.log("Seva is store now..")
            //                        _sevaContoller.bookingComplete();
            //                        saveFullReceipt();
            //                        sevaProxy.printReceipt();
            //                        resetBaseScreen();
            //                        //resetNextControls(true)
            //                        paymentOver();
            //                    }
            onCloseClicked: {
                resetBaseScreen()
                _allViewDataDialog.close();
            }
            onConfirmClicked: {
                sevaProxy.printBookingReceipt(_sevaBookingElement);
                _allViewDataDialog.close();
                resetBaseScreen();
            }

            //                    onPrintClicked: {
            //                        //sevaProxy.printReceipt();
            //                    }
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
            console.log(" Keys.onEscapePressed: Seva All view Page ")
            loadSevaBookingView();
        }
    }
}
