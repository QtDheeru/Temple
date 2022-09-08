import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtQuick.Window 2.12
import Utils 1.0
import "./components"

Rectangle{
    id : root
    property var styles : MyStyles{}
    width: styles.screenWidth
    height: styles.screenHeight
    property int sevaType :-1
    property int myHeight : 30
    property int fontPixelSize : 20

    signal loadMenuPage()
    focus: true
    property string sevaname
    property string sevatype
    property string sevaid
    property var sevaObject

    onSevaTypeChanged: {
        console.log(" Popup - Seva Type ="+sevaType)
        _sevaListView.sevaType = sevaType;
    }

    Rectangle {
        id : r1
        width: parent.width
        height: parent.height
        color: styles.sevaBookingPagebackgroundcolor//"#445566"
        focus: true
        RowLayout {
            anchors.fill: parent
            spacing: root.height/100
            SevaListView{
                id :_sevaListView
                Layout.topMargin: root.height/100
                Layout.fillHeight: true
                focus: false
                fontPixelSize : root.fontPixelSize
            }
            ColumnLayout{
                spacing: root.height/100
                height: parent.height
                Layout.alignment: Qt.AlignTop
                RowLayout{
                    //Layout.fillHeight: true
                    spacing: root.height/200
                    Layout.topMargin: root.height/100
                    Layout.rightMargin: root.height/100
                    Layout.fillWidth: true
                    PersonalDetails{
                        id:_personal;Layout.fillWidth: true
                        receiptNumber: sevaProxy.receiptNumber
                        KeyNavigation.tab: _sevaDate
                        Layout.alignment: Qt.AlignTop
                        focus: true
                    }
                    SevaDateTime{id:_sevaDate;Layout.fillWidth: true
                        KeyNavigation.tab: _sevaD}
                }
//                RowLayout{
//                    //Layout.fillHeight: true
//                    visible: false
//                    Layout.fillWidth: true
//                    Layout.topMargin: root.height/100
//                    Layout.rightMargin: root.height/100
//                    //SevaDetails{id:_sevaD;Layout.fillWidth: true}
//                }
                RowLayout{
                    //Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.topMargin: root.height/100
                    Layout.rightMargin: root.height/100
                    SevaDetails{id:_sevaD;Layout.fillWidth: true;referenceVisbility :false}
                    SevaBookingProgressView{id:_sevaP;Layout.fillWidth: true}
                }
                RowLayout{
                    Layout.fillWidth: true
                    Layout.rightMargin: root.height/100
                    Layout.alignment: Qt.AlignTop
                    Layout.fillHeight: true
                    SevaBookingControl{
                        id : _sevaContoller
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignTop
                        Layout.rightMargin: 1
                        enablePaymentButton: _personal.isDataExist &&
                                             _sevaD.isDataExist && (_personal.mobileNo.length==10)
                        onEnablePaymentButtonChanged: {
                            enableControls(true)
                            console.log(" ******* Enabled Button changed......."+enablePaymentButton)
                        }
                    }
                    SevaPriceSummary{
                        id : _sevaPriceSummary
                        Layout.fillWidth: true
                        //                            Layout.fillHeight: true
                        Layout.rightMargin: 0
                    }
                }
            }
        }
    }
    //    }
    Connections{
        target: _sevaListView
        function onSevaSelected(idx, sevaType, sevaId){
            console.log(" SBV - Index =" + idx + " SevaType =" + sevaType + " SevaID=" + sevaId)
            sevaObject = sevaProxy.getSeva(sevaType,sevaId);
            _sevaD.setSevaDetails(sevaObject)
            _personal.setGothras(sevaProxy.getGothras());
            _personal.setNakshatras(sevaProxy.getNakshatras());
            //_sevaP.setBankList(sevaProxy.getBankList())
        }
        function onSevaSelectedByIndex(idx){
            console.log(" Seva Selected ="+idx)
            if (idx < 0 ) idx = 0;
            sevaObject = sevaProxy.getSevaByIndex(idx);
            _sevaD.setSevaDetails(sevaObject)
            console.log("seva name  = " + sevaObject.sevaName + " Seva cost = " + sevaObject.sevaCost)
            _personal.setGothras(sevaProxy.getGothras());
            _personal.setNakshatras(sevaProxy.getNakshatras());
            //_sevaP.setBankList(sevaProxy.getBankList())
            //_personal.receiptNumber = sevaProxy.getNextReceiptNumber();
        }
    }
    SevaPaymenConfirmationDialog{
        id : _paymentDialog
        onPaymentComplete: {
            console.log("Seva is store now..")
            _sevaContoller.bookingComplete();
            saveFullReceipt();
            sevaProxy.printReceipt();
            resetBaseScreen();
            //resetNextControls(true)
            paymentOver();
        }
        onCloseClicked: {
            resetBaseScreen()
        }
        onPrintClicked: {
            sevaProxy.printReceipt();
        }
        onRejected: {
            resetBaseScreen
        }
    }
    function resetBaseScreen(){
        r1.opacity = 1;
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
    }

    Connections{
        target: _sevaContoller
        function onStartPayment(){
            console.log(" Payment started ")
            if (_sevaP.sevaCount==0){
                console.log(" No sevas Booked. Please add Seva");
                _errorDialog.showError("Sevas Not added. Please Add Seva");
                return;
            }

            //saveOnlySeva();// Don't add seva to list as it is not confirmed
            _paymentDialog.amount2Pay = _sevaPriceSummary.amout2Pay
            r1.opacity = 0.3;
            _paymentDialog.open();
        }
        function onAddMoreSeva(){
            console.log(" Add more seva")
            saveOnlySeva();
            resetPartial();
            _sevaListView.selectFirstSeva();
        }
        function onClearReceipt() {
            console.log(" Clear Receipt Data")
            clearData();
        }
        function onShowAllData(){
            console.log("Show all Data")
            sevaProxy.showAllData();
            //_ld.source = "SevaBookedDetailView.qml";
        }
        function onNextReceipt() {
            root.clearData();
            //root.resetNextControls(false);
            _sevaContoller.startNextBooking();
            _sevaListView.selectFirstSeva();
        }
        function onStateChanged()
        {
            console.log("state changed" + _sevaContoller.state)
            if(_sevaContoller.state === "paymentComplete")
            {
                _personal.enabled = false
//                _sevaContoller.nextButtonFocus = true
//                root.focus = true
                r1.forceActiveFocus();
            }else
                _personal.enabled = true
        }
    }

    function saveFullReceipt(){
        console.log(" Save all the recept data")
        console.log(" ReceiptNo ="+_personal.receiptNumber)
        console.log(" Name ="+_personal.devoteeName)
        console.log(" Mobile ="+_personal.mobileNo)
        console.log(" Nakshatra ="+_personal.nakshatra)
        console.log(" Gotra ="+_personal.gotra)
        buildSevaReceipt();
        sevaProxy.saveReceipt(_sevaReceipt);
    }

    function saveOnlySeva() {
        printSevaObject();
        var retVal = sevaProxy.addSevaOnly(sevaObject.sevaType,
                                           sevaObject.sevaId,
                                           sevaObject.sevaName,
                                           sevaObject.sevaCost,
                                           _sevaDate.sevadate,
                                           _sevaDate.sevatime,
                                           _sevaD.addcost,
                                           _sevaD.count);
        if (retVal === false ){
            console.log ("Seva already exist. Add another")
            _errorDialog.showError("Seva Already added. Add another")
            return;
        }

        _sevaPriceSummary.addTotal(sevaObject.sevaCost,_sevaD.count)
        _sevaPriceSummary.addTotal(_sevaD.addcost)
        sevaObject = null;
    }
    function clearData(){
        console.log(" Data is getting cleared")
        _personal.clearData()
        _sevaD.clearData();
        _sevaDate.clearData();
        _sevaP.clearData();
        _sevaPriceSummary.clearData();
        _paymentDialog.clearData();
    }

    function resetPartial(){
        _sevaD.resetPartial();
    }

    function buildSevaReceipt() {
        _sevaReceipt.receiptNo = _personal.receiptNumber.trim();
        _sevaReceipt.devoteeName = _personal.devoteeName.trim();
        _sevaReceipt.mobileNo = _personal.mobileNo.trim();
        _sevaReceipt.gothra = _personal.gothra.trim();
        _sevaReceipt.nakshtra = _personal.nakshatra.trim()
        console.log("gothra ===== > " + _personal.gothra.trim())
        _sevaReceipt.reference = _sevaD.reference.trim();
        _sevaReceipt.address = _sevaD.address.trim();

        _sevaReceipt.receiptDate = _sevaDate.receiptdate.trim();
        _sevaReceipt.momento = _sevaDate.momento.trim()
        _sevaReceipt.bookedBy = _sevaDate.bookedby.trim()

        _sevaReceipt.cash =  _paymentDialog.paymentObject.cashPaid.trim()
        _sevaReceipt.bank =  _paymentDialog.paymentObject.bankSelected.trim()
        _sevaReceipt.onlineRef =  _paymentDialog.paymentObject.checkOrTransactionId.trim()
        _sevaReceipt.note = _paymentDialog.paymentObject.note
    }

    function disableControls(){
        _sevaContoller.setButtons(false);
    }
    function resetNextControls(value){
        //_sevaContoller.startNextReceipt = value;
        _sevaContoller.nextReceipt();
    }

    function paymentOver(){
        _sevaContoller.paymentComplete()
    }

    function enableControls(){
        _sevaContoller.setButtons(true);
    }

    Keys.onEscapePressed: {
        console.log("Esc pressed in select seva type view")
        loadMenuPage()
    }
    SevaReceipt{
        id : _sevaReceipt
    }
    Loader{
        id : _ld
        anchors.fill: parent
    }

    function printSevaObject(){
        console.log(" Seva Id    ="+sevaObject.sevaId)
        console.log(" Seva Type  ="+sevaObject.sevaType)
        console.log(" Seva Name  ="+sevaObject.sevaName)
        console.log(" Seva Cost  ="+sevaObject.sevaCost)
        console.log(" Seva addition cost ="+_sevaD.addcost)
        console.log(" Seva count ="+_sevaD.count)
        console.log(" Receipt Date ="+_sevaDate.receiptdate)
        console.log(" Seva    Date ="+_sevaDate.sevadate)
        console.log(" Seva sevatime ="+_sevaDate.sevatime)
        console.log(" Seva bookedby ="+_sevaDate.bookedby)
    }
}