import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtQuick.Window 2.12
import Utils 1.0
import QtQuick.Controls 1.4
import "./components"
import "././QmlVoucher"
import SevaTypeNamesDataModel 1.0
import SevaBookingConformationDataModel 1.0

Rectangle{
    id : root
    property var styles : MyStyles{}
    width: styles.screenWidth
    height: styles.screenHeight
    property int sevaType :-1
    property int myHeight : 30
    property int fontPixelSize : 20
    property alias selectedReceiptDate: _sevaDate.receiptdate
    property alias selectedSevaDate: _sevaDate.sevadate

    signal loadMenuPage()
    signal loadDevoteeSelection()

    property var storeObject

    property string sevaname
    property string sevatype
    property string sevaid
    property var sevaObject
    property string d_Nakshtra: _personal.nakshatra
    property alias dname: _personal.devoteeName
    property alias dmobile: _personal.mobileNo
    property alias dgothra: _personal.gothra
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
                Layout.fillHeight: parent.height
                focus: false
                fontPixelSize : root.fontPixelSize
            }
            ColumnLayout{
                spacing: root.height/100
                height: parent.height
                Layout.alignment: Qt.AlignTop
                RowLayout{
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
                        isRcptvisible: true
                        devoteeNameEditable: false
                        mobileNoEditable: false
                    }
                    SevaDateTime{id:_sevaDate;Layout.fillWidth: true
                        KeyNavigation.tab: _sevaD}
                }
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
            console.log(" Seva Object = " + sevaObject)
            if(sevaObject === null)
            {
                console.log("Inside if of seva object")
            }
            _sevaD.setSevaDetails(sevaObject)
        }
        function onSevaSelectedByIndex(idx){
            console.log(" Seva Selected ="+idx)
            if (idx < 0 ) idx = 0;
            sevaObject = sevaProxy.getSevaByIndex(idx);
            if(sevaObject === null)
            {
                console.log("Inside if of seva object")
            }
            _sevaD.setSevaDetails(sevaObject)
            console.log("seva name  = " + sevaObject.sevaName + " Seva cost = " + sevaObject.sevaCost)
        }
    }

    Timer{
        id:_timer
        running: false
        interval: 1500
        onTriggered: {
            _errorDialog2.close();
            _ld.setSource("voucherPage.qml",{bookingElement:storeObject,pageNumber:1})
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
            paymentOver();
        }
        onCloseClicked: {
            resetBaseScreen()
        }
        onPrintClicked: {
            sevaProxy.printReceipt();
        }
        onRejected: {
            resetBaseScreen()
        }
    }

    function resetBaseScreen(){
        r1.opacity = 1;
    }

    DisplayDialog {
        id :_errorDialog
        visible: false

        function showError(message){
            console.log("inside show error")
            _errorDialog.visible = true;
            _errorDialog.text2Display = message
            _errorDialog.open();
        }
        onYesAction: {
            _errorDialog.close()
        }

        onNoAction: {
            _errorDialog.close()
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
            _errorDialog2.visible = true;
            _errorDialog2.text2Display = message
            _errorDialog2.open();
            _timer.start();
        }
    }


    Connections{
        target: _sevaContoller
        //    target: _ld.item
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
            // _paymentDialog.b = true;
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

        function onShowAllDataFromSevBControl(){
            console.log("SevaControll : Show all Data")
            //            progressBar.visible = true;
            //            progressBar.opacity = 0.1;
            var b = sevaProxy.showAllData();
            if(b===false)
            {
                errorOccur("cannot fetch data")
            }

            //_ld.source = "SevaBookedDetailView.qml";
            _ld.source = "SevaAllViewPage.qml"
            //            while(_ld.status===Loader.Loading)
            //            {
            //                console.log("Show all Data  while(_ld.status===Loader.Loading)")
            //                progressBar.visible = true;
            //                progressBar.opacity = 0.1;
            //                pb.value = _ld.progress*10
            //                console.log(pb.value);
            //            }
        }


        function onNextReceipt() {
            console.log("In onNextReceipt of sbv")
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
                //nextReceipt();
                //               _sevaD.isCountEditable =  false;
                //                _sevaD.isAddressEditable = false;
                //                _sevaD.isAdditionalCostEditable = false;
                //                _personal.devoteeNameEditable = true //ch
                //        _personal.mobileNoEditable = true  //ch
                root.clearData();
                //root.resetNextControls(false);
                _sevaContoller.startNextBooking();
                _sevaListView.selectFirstSeva();

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
        var b = sevaProxy.saveReceipt(_sevaReceipt);
        if(b === false)
        {
            errorOccur("Cannot store seva receipt details into db");
        }
    }

    function saveOnlySeva() {
        printSevaObject();
        var retVal = sevaProxy.addSevaOnly(sevaObject.sevaType,
                                           sevaObject.sevaId,
                                           sevaObject.sevaName,
                                           _sevaD.sevaCost,
                                           _sevaDate.sevadate,
                                           _sevaDate.sevatime,
                                           _sevaD.addcost,
                                           _sevaD.count);
        if (retVal === false ){
            console.log ("Seva already exist. Add another")
            _errorDialog.showError("Seva Already added. Add another")
            return;
        }

        _sevaPriceSummary.addTotal(_sevaD.sevaCost,_sevaD.count)
        _sevaPriceSummary.addTotal(_sevaD.addcost)
        sevaObject = null;
    }
    function clearData(){
        console.log(" Data is getting cleared")
        _sevaD.clearData();
        _sevaD.isCountEditable =  true;
        _sevaD.isAddressEditable = true;
        _sevaD.isAdditionalCostEditable = true;

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
        _sevaReceipt.sevatime = _sevaDate.sevatime.trim();
        _sevaReceipt.bookedBy = _sevaDate.bookedby.trim()
        _sevaReceipt.cash =  _paymentDialog.paymentObject.cashPaid.trim()
        _sevaReceipt.bank =  _paymentDialog.paymentObject.bankSelected.trim()
        _sevaReceipt.paymentMode = _paymentDialog.paymentObject.paymentMode.trim()
        _sevaReceipt.bookingStatus =_paymentDialog.status
        _sevaReceipt.onlineRef =  _paymentDialog.paymentObject.checkOrTransactionId.trim()
        _sevaReceipt.note = _paymentDialog.paymentObject.note
    }

    function disableControls(){
        _sevaContoller.setButtons(false);
    }
    function resetNextControls(value){
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
        _sevaP.clearData();
        loadMenuPage()
    }
    SevaReceipt{
        id : _sevaReceipt
    }
    Loader{
        id : _ld
        anchors.fill: parent
        Connections{
            target: _ld.item
            function onLoadSevaBookingView()
            {
                console.log(" In onLoadSevaBookingView")
                _ld.source = "SevaBookingView.qml"
            }
            function onLoadMenuPage()
            {
                console.log(" In onLoadMenuPage")
                loadMenuPage();
            }
            function onLoadvoucher(ve,pageNo){
                console.log("hellooooooon suman",ve," ",pageNo)
                sevaProxy.cancelReceipt(ve.sno);
                _ld.setSource("voucherPage.qml",{bookingElement:ve,pageNumber:pageNo})
            }
        }
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

    Connections{
        target:_sevaListView
        function onErrorOccur(errorMsg)
        {
            console.log("In connections of on error occur of seva booking view")
            _errorDialog.showError(errorMsg);
        }
    }
    Connections{
        target:_personal
        function onErrorOccur(errorMsg)
        {
            console.log("In connections of on error occur of seva booking view")
            _errorDialog.showError(errorMsg);
        }
    }
    Connections{
        target:_sevaDate
        function onErrorOccur(errorMsg)
        {
            console.log("In connections of on error occur of seva booking view")
            _errorDialog.showError(errorMsg);
        }
    }
    Connections{
        target:_sevaContoller
        function onErrorOccur(errorMsg)
        {
            console.log("In connections of on error occur of seva booking view")
            _errorDialog.showError(errorMsg);
        }
    }

    Component.onCompleted: {
        console.log("Component.onCompleted: of seva booking view",dgothra,d_Nakshtra)
        _personal.setGothras(sevaProxy.getGothras());
        _personal.setNakshatras(sevaProxy.getNakshatras());
        _personal.setNakshatraCombo(d_Nakshtra)
        _personal.setGothraCombo(dgothra)
        forceActiveFocus()
        _sevaDate.bookedby = sevaProxy.userManagement.signIn_Name
        console.log("SevaBookingView is created...")
    }
    Component.onDestruction: {
        console.log("Seva Booking view Destructed !!!")
    }
}
