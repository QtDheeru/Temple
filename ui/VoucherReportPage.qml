import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import VoucherElement 1.0
import "./components"
Rectangle{
    id:_r1
    property var styles : MyStyles{}
    width: styles.screenWidth
    height: styles.screenHeight
    //  color: "#72FFFF"
    signal reportDisplay(var date);
    signal sendVoucherReportInput(var obj);
    signal loadVoucherPage();
    signal resetVouModel();
    property var footerHeight: _r1.height/15
    property alias tot :total.text
    //focus: activeFocus
    // property alias vDate:lv1.dt
    //  signal dt(string d);
    Connections{
        target: _reportitems
        function onSendVoucherReportInput(obj)
        {
            console.log("signal emitted from voucher report page")
            sendVoucherReportInput(obj)
        }
        function   onSendError(err){
            console.log("In onSendError")
            _errorDialog.showError(err);
        }
    }
    Component.onDestruction: {
        console.log("Closing the report")

        resetVouModel();
    }
    RowLayout{
        anchors.fill: parent
        Rectangle{
            id:_rightpart
            color: "#72FFFF"
            Layout.preferredWidth: parent.width/4
            Layout.preferredHeight: parent.height
            MyVoucherFilter{
                id:_reportitems
                width: parent.width
                height: parent.height
                border.color: "black"
                border.width: 2
                color: "#576F72"
            }
        }
        Rectangle{
            id:leftpart
            Layout.preferredWidth:  parent.width - _rightpart.width
            Layout.preferredHeight:  parent.height

            TableView{
                id: lv1
                model: voucherReportModel
                width:parent.width
                height: parent.height - footerHeight
                property var selectedRow;
                //  property var dt;
                style: TableViewStyle {
                    headerDelegate: Rectangle {
                        height: 30
                        color: "#72FFFF"
                        Text {
                            id: headerItem
                            anchors.centerIn: parent
                            text: styleData.value
                            font.bold: trues
                            font.pixelSize: 15
                            font.family: "Helvetica"
                        }

                    }
                    rowDelegate: Rectangle {
                        id:r1
                        height:20
                        color: styleData.selected ? "skyblue" : "white"

                        //  z:1
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
                                // styleData.selected = true
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
                                    var ve = voucherReportModel.getVoucherReportAt(lv1.currentRow);
                                    console.log("////////////"+ve.voucherDate)

                                    _voucherReceiptDialog._vDate = ve.voucherDate
                                    _voucherReceiptDialog._voucherNo = ve.voucherNo
                                    _voucherReceiptDialog._voucherName= ve.voucherName
                                    _voucherReceiptDialog._mobileNo= ve.mobileNo
                                    _voucherReceiptDialog._voucherType= ve.voucherType
                                    _voucherReceiptDialog._voucherItem= ve.voucherItem
                                    _voucherReceiptDialog._voucherNote= ve. voucherNote
                                    _voucherReceiptDialog._voucherCost= ve.voucherCost
                                    _voucherReceiptDialog._voucherPaymentMode= ve.voucherPaymentMode
                                    _voucherReceiptDialog._paymentReference= ve.paymentReference

                                    _voucherElement.voucherDate = ve.voucherDate
                                    _voucherElement.voucherNo  = ve.voucherNo
                                    _voucherElement.voucherName= ve.voucherName
                                    _voucherElement.mobileNo= ve.mobileNo
                                    _voucherElement.voucherType= ve.voucherType
                                    _voucherElement.voucherItem= ve.voucherItem
                                    _voucherElement.voucherNote= ve. voucherNote
                                    _voucherElement.voucherCost= ve.voucherCost
                                    _voucherElement.voucherPaymentMode= ve.voucherPaymentMode
                                    _voucherElement.paymentReference= ve.paymentReference
                                }
                                else if (mouse.button == Qt.RightButton)
                                {
                                    console.log("Right")

                                    contextMenu.popup()
                                    var ve = voucherReportModel.getVoucherReportAt(lv1.currentRow);
                                    console.log("////////////"+ve.voucherDate)

                                    _voucherReceiptDialog._vDate = ve.voucherDate
                                    _voucherReceiptDialog._voucherNo = ve.voucherNo
                                    _voucherReceiptDialog._voucherName= ve.voucherName
                                    _voucherReceiptDialog._mobileNo= ve.mobileNo
                                    _voucherReceiptDialog._voucherType= ve.voucherType
                                    _voucherReceiptDialog._voucherItem= ve.voucherItem
                                    _voucherReceiptDialog._voucherNote= ve. voucherNote
                                    _voucherReceiptDialog._voucherCost= ve.voucherCost
                                    _voucherReceiptDialog._voucherPaymentMode= ve.voucherPaymentMode
                                    _voucherReceiptDialog._paymentReference= ve.paymentReference

                                    _voucherElement.voucherDate = ve.voucherDate
                                    _voucherElement.voucherNo  = ve.voucherNo
                                    _voucherElement.voucherName= ve.voucherName
                                    _voucherElement.mobileNo= ve.mobileNo
                                    _voucherElement.voucherType= ve.voucherType
                                    _voucherElement.voucherItem= ve.voucherItem
                                    _voucherElement.voucherNote= ve. voucherNote
                                    _voucherElement.voucherCost= ve.voucherCost
                                    _voucherElement.voucherPaymentMode= ve.voucherPaymentMode
                                    _voucherElement.paymentReference= ve.paymentReference
                                }

                            }
                        }
                    }
                    itemDelegate:Rectangle{
                        height:20
                        color: styleData.selected ? "skyblue" : styleData.row%2 ? "light gray" : "white"
                        //styleData.row===selectedRow ? "yellow":
                        //color: styleData.row===selectedRow ? "yellow" : "white"
                        Text {
                            text: styleData.value
                            anchors.centerIn: parent
                            leftPadding: 1
                            font.pixelSize: 14
                        }
//                        Rectangle{
//                            anchors.right: parent.right
//                            width:0.5
//                            color:"gray"
//                            height:parent.height
//                        }
                        //                                    MouseArea{
                        //                                        anchors.fill: parent
                        //                                        onClicked: {
                        //                                            console.log("I am style data value "+ styleData.value)
                        //                                           // var selectedRow = 2
                        //                                            //itemDelRect.color = styleData.row === selectedRow ? "yellow" : "white"
                        //                                        }
                        //                                    }

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
                TableViewColumn {
                    id:_voucherNo;title: "Voucher No"; role: "voucherNo";
                    width: leftpart.width/8.1

                    movable: false
                    resizable: true
                    //                    delegate: Rectangle{
                    //                        id:_voucherNodel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"
                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignHCenter

                    //                            verticalAlignment: Qt.AlignVCenter


                    //                            font.pixelSize: 14
                    //                        }

                    //                    }
                }
                TableViewColumn {
                    id:_voucherDate;title: "Date"; role: "voucherDate";
                    width: leftpart.width/8.1
                    horizontalAlignment: Text.AlignLeft
                    movable: false
                    resizable: false
                    //                    delegate: Rectangle{
                    //                        id:_voucherDatedel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"
                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignHCenter
                    //                            padding: _cost.width/3
                    //                            verticalAlignment: Qt.AlignVCenter

                    //                            font.pixelSize: 14
                    //                        }
                    //                    }
                }
                TableViewColumn {
                    id:_voucherName;title: "Name"; role: "voucherName";
                    width: leftpart.width/8.1
                    movable: false
                    resizable: true
                    //                    delegate: Rectangle{
                    //                        id:_voucherNamedel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"
                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignHCenter
                    //                            elide:Text.ElideRight
                    //                            verticalAlignment: Qt.AlignVCenter

                    //                            font.pixelSize: 14
                    //                        }
                    //                    }
                }
                TableViewColumn {
                    id:_phoneNo;title: "Phone No"; role: "mobileNo";
                    width: leftpart.width/8.1
                    movable: false
                    resizable: false
                    //                    delegate: Rectangle{
                    //                        id:_phoneNodel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"

                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignHCenter
                    //                            padding: _totalAmount.width/3
                    //                            verticalAlignment: Qt.AlignVCenter

                    //                            font.pixelSize: 14
                    //                        }
                    //                    }
                }
                TableViewColumn {
                    id:_cost;title: "Cost"; role: "voucherCost";
                    width: leftpart.width/8.1
                    movable: false
                    resizable: false
                    //                    delegate: Rectangle{
                    //                        id:_costdel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"

                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignRight
                    //                            padding: _cost.width/3
                    //                            verticalAlignment: Qt.AlignVCenter

                    //                            font.pixelSize: 14
                    //                        }
                    //                    }
                }
                TableViewColumn {
                    id:_voucherType;title: "Voucher Type"; role: "voucherType";
                    width: leftpart.width/8.1
                    movable: false
                    resizable: true
                    //                    delegate: Rectangle{
                    //                        id:_voucherTypedel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"

                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignHCenter
                    //                            verticalAlignment: Qt.AlignVCenter
                    //                            elide:Text.ElideRight
                    //                            font.pixelSize: 14
                    //                        }
                    //                    }
                }
                TableViewColumn {
                    id:_voucherItem;title: "Item"; role: "voucherItem";
                    width: leftpart.width/8.1
                    movable: false
                    resizable: true
                    //                    delegate: Rectangle{
                    //                        id:_voucherItemdel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"

                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignHCenter
                    //                            verticalAlignment: Qt.AlignVCenter
                    //                            elide:Text.ElideRight
                    //                            font.pixelSize: 14
                    //                        }
                    //                    }
                }
                TableViewColumn {
                    id:_voucherPaymentMode;title: "Payment Mode"; role: "voucherPaymentMode";
                    width: leftpart.width/8.1
                    movable: false
                    resizable: false
                    //                    delegate: Rectangle{
                    //                        id:_voucherPaymentModedel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"

                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignHCenter
                    //                            verticalAlignment: Qt.AlignVCenter

                    //                            font.pixelSize: 14
                    //                        }
                    //                    }
                }
                TableViewColumn {
                    id:_paymentReference;title: "Payment Ref"; role: "paymentReference";
                    width: leftpart.width/8.1
                    movable: false
                    resizable: true
                    //                    delegate: Rectangle{
                    //                        id:_paymentReferencedel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"

                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignHCenter
                    //                            verticalAlignment: Qt.AlignVCenter
                    //                            elide:Text.ElideRight
                    //                            font.pixelSize: 14
                    //                        }
                    //                    }
                }
                TableViewColumn {
                    id:_voucherNote;title: "Note"; role: "voucherNote";
                    width: leftpart.width/8.1
                    movable: false
                    resizable: true
                    //                    delegate: Rectangle{
                    //                        id:_voucherNotedel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"

                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignHCenter
                    //                            verticalAlignment: Qt.AlignVCenter
                    //                            elide:Text.ElideRight
                    //                            font.pixelSize: 14
                    //                        }
                    //                    }
                }
                Menu{
                    id: contextMenu
                    MenuItem {
                        text: qsTr('Modify')
                        onTriggered:
                        {
                            //  sevaProxy.sevaBookingTV
                            _voucherReceiptDialog.open()
                        }
                    }
                    MenuItem {
                        text: qsTr('Print')
                        onTriggered:{
                            //showPrintDetails.open()
                            _r1.opacity = 0.3;
                            _voucherReceiptDialog.open();
                        }
                    }
                }
                VoucherReceiptDialog{
                    id:_voucherReceiptDialog
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
                    }
                    onConfirmClicked: {
                        sevaProxy.printVoucherReceipt(_voucherElement);
                        _voucherReceiptDialog.close();
                        resetBaseScreen();
                    }

                    onPrintClicked: {
                        //sevaProxy.printReceipt();
                    }
                    onRejected: {
                        resetBaseScreen()
                    }
                }

            }

            Rectangle{
                id:_footer
                width: leftpart.width
                height: footerHeight
                anchors.bottom: leftpart.bottom
                Rectangle{
                    id:_grandTotalText
                    width: parent.width/2
                    height: parent.height
                    color: "#72FFFF"
                    Text {
                        text:"Grand Total :" //+ sevaProxy.sevaReport.accReportModel.grandTotal
                        anchors.centerIn: parent
                        font.pixelSize: styles.headerTextFont1
                        font.italic: true
                        font.bold : true
                    }
                }
                Rectangle{
                    width: parent.width/2
                    height: parent.height
                    anchors.left: _grandTotalText.right
                    color: "#72FFFF"
                    Text {
                        id:total
                        text: voucherReportModel.grandTotal + ".00 ₹"
                        anchors.centerIn: parent
                        font.pixelSize: 30
                        font.italic: true
                        font.bold : true
                        //                        Component.onCompleted: {
                        //                            if(voucherReportModel.getVoucherReportQryListSize()===0)
                        //                            {
                        //                                total.text =  "0.00 ₹"
                        //                            }
                        //                        }
                    }
                }
            }
            Button{
                id:_exportCsv
                height:60
                width: 200
                anchors.top: lv1.bottom
                anchors.horizontalCenter: lv1.horizontalCenter
                style: ButtonStyle{
                    background: Rectangle{
                        id: bg
                        border.width: 1
                        radius: 3
                        color: "cornflowerblue"
                        Label{
                            text: "Export Data"
                            anchors.centerIn: parent
                        }
                    }
                }
                onClicked: {
                    console.log("export data clicked")
                    voucherReportModel.generateVoucherReportCSV()
                }
            }
            Connections{
                id:_connection
                target:voucherReportModel
                onSuccessMessage:{
                    console.log("OnSuccess Message");
                    _errorDialog.showError(exportmsg)
                }
            }
            DisplayDialog {
                id :_errorDialog
                visible: false

                function showError(message){
                    _errorDialog.visible = true;
                    _errorDialog.text2Display = message
                    _errorDialog.open();
                    //_errorDialog.visible = false;
                }
                onNoAction: {
                    _errorDialog.close()
                }
            }
        }
    }
    Keys.onEscapePressed: {
        console.log("Esc pressed in voucher report page")
        loadVoucherPage();
    }
    function resetBaseScreen(){
        _r1.opacity = 1;
    }
    VouEle{
        id:_voucherElement
    }
    Component.onCompleted: {
         console.log("VoucherReportPage is created...")
         forceActiveFocus();
    }
}



//roles[1] = "voucherDate";
//roles[2] = "voucherNo";
//roles[3] = "voucherName";
//roles[4] = "mobileNo";
//roles[5] = "voucherType";
//roles[6] = "voucherItem";
//roles[7] = "voucherNote";
//roles[8] = "voucherCost";
//roles[9] = "voucherPaymentMode";
//roles[10] = "paymentReference";
