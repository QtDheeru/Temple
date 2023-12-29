import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Window 2.12
import "./components"

ApplicationWindow {
    id :_root
    visible: true
    property var styles : MyStyles{}
    signal errorOccur(string errorMsg);

    width: styles.screenWidth
    height: styles.screenHeight
    //property var tot ;
    property var constant: Constants{}
    property var storeObject
    title: constant.addressText1
    color: "black"
    flags: Qt.WindowSystemMenuHint
    Component.onCompleted: {
        //        console.log("=====" + confApp.appPath + "/" + confApp.welcomescreenImg );
        //        console.log( confApp.welcomescreenImg);

        console.log("screen height= " + Screen.height)
        console.log("screen width= " + Screen.width)
        console.log("Screen MyStyles-screecnWidth size =" + styles.screenWidth)
        console.log("Screen MyStyles-screenHeight size =" + styles.screenHeight)
        console.log("screen density  == " + Screen.pixelDensity)
    }
    Loader{
        id:loader
        //anchors.fill: parent
        height: parent.height
        width: parent.width
        source: "WelcomeToAppScreen.qml"
        signal accountDetails();
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

    Connections{
        target: loader.item
        ignoreUnknownSignals: true

        function onWelcomeToAppTimeTriggered(){
            if(trustListModel.getTrustListSize()>1)
            {
                console.log("trustListModel.getTrustListSize()"+trustListModel.getTrustListSize())
                loader.source= "MainTrust.qml"
            }
            if(trustListModel.getTrustListSize()===1){
                console.log("in else--------------");
                var trust= trustListModel.trustList[0];
                var trustName = trust.trustName;
                var trustCode = trust.trustCode;
                console.log("in else------trustName--------"+trustName);
                console.log("in else-------trustCode-------"+trustCode);
                trustListModel.trustCodeForConfig = trustCode;
                trustListModel.trustCodeForData = trustCode;
                trustListModel.currentTrust = trustName;
                var str1 = trustListModel.getConfigLocation();
                var str2 =trustListModel.getDataLocation();
                console.log("str1 = --" + str1);
                console.log("str2 = --" + str2);
                //   loader.source = "WelcomeScreen.qml"
                //  loader.source= "SevaBookingView.qml"
                loader.source = "Login.qml"
            }
            if(trustListModel.getTrustListSize()===0){
                console.log("trustListModel.getTrustList===0");
                // loader.source= "MainTrust.qml"
                errorOccur("Trust not present");
            }

            //            function onLoadWelcome() {
            //                console.log("Correct credentials")
            //                loader.source = "WelcomeScreen.qml"
            //            }
        }
        function onTimerTriggered() {
            console.log("Welcome screen TimeTriggered");
            loader.source= "Login.qml"
        }
        /*      function onLoadLogin(pagecount)
        {
            console.log("Login Page loaded");
            loader.setSource("Login.qml",{pageNumber:pagecount,loginPageImage:"",height:300,width:300})
        }*/
        function onDateClicked(date)
        {
            console.log("date clicked " +date )
            //            sevaDetailsonDateCount.onDateSelected(date)
            var b = sevaProxy.sevaReport.onDateSelected(date)
            if(b===false)
            {
                errorOccur("date selected failed");
            }
            else{
                loader.source = "SevaReportOnDateView.qml"
            }
        }
        function onSendReportImput(obj)
        {
            console.log("In main")
            sevaProxy.sevaReport.generateAccReport(obj)
        }
        function onSendBookReportImput(obj)
        {
            console.log("In main")
            sevaProxy.sevaReport.generateBookReport(obj)
        }
        function onSendReportDateRangeImput(obj)
        {
            console.log("In main")
            sevaProxy.sevaReport.generateAccReportForEachDate(obj)
        }
        function onSendBookingReportDateRangeImput(obj)
        {
            console.log("In main")
            sevaProxy.sevaReport.generateBookingReportForEachDate(obj)
        }
        function onSendReportDateRangeImputForWholeMonth(obj)
        {
            console.log("In main")
            sevaProxy.sevaReport.generateAccReportForEachDateForWholeMonth(obj)
        }
        function onSendBookingReportDateRangeImputForWholeMonth(obj)
        {
            console.log("In main")
            sevaProxy.sevaReport.generateBookingReportForEachDateForWholeMonth(obj)
        }
        function onSendReportMonthRangeImput(obj)
        {
            console.log("In main")
            sevaProxy.sevaReport.generateAccReportForEachMonth(obj)
        }
        function onSendBookingReportMonthRangeImput(obj)
        {
            console.log("In main")
            sevaProxy.sevaReport.generateBookingReportForEachMonth(obj)
        }
        function onSendBookReportInput(obj)
        {
            console.log("In main")
            sevaProxy.sevaReport.generateBookReport(obj)
        }
        function onSendSingleDateReportInput(obj)
        {
            console.log("In main")
            sevaProxy.sevaReport.generateAccReport(obj)
        }
        function onSendSingleDateBookingReportInput(obj)
        {
            console.log("In main")
            sevaProxy.sevaReport.generateBookReport(obj)
        }
        function onResetAccModel(){
            console.log("reset Model")
            sevaProxy.sevaReport.resetAccModel()
        }
        //        function onResetAccDateRangeModel(){
        //            console.log("reset Model")
        //            sevaProxy.sevaReport.resetAccDateRangeModel()
        //        }
        function onResetBookingModel(){
            console.log("reset DateRangeModel")
            sevaProxy.sevaReport.resetBookingModel()
        }

        //Login Page Handlers
        function onWrongCred() {
            console.log("Wrong credentials")
        }
        function onLoginSuccess(pcount) {
            console.log("Wrong credentials",pcount)
            if(pcount===0){
                loader.source = "MenuPage.qml"}
            if(pcount===2){
                console.log("Inside pcount 2")
                loader.source = "SevaReportPage.qml"
            }
            if (pcount === 4){
                console.log("Inside pcount 4")
                loader.source = "qrc:/ui/Admin/AdminRights.qml"
            }
        }
        function onLoadWelcome() {
            console.log("Correct credentials")
            loader.source = "WelcomeScreen.qml"
        }
        //Menu Page handlers
        function onSevabooking() {
            console.log("clicked on Sevabooking")
            //            loader.source= "SelectSevaTypeMenu.qml"
            loader.source= "SevaBookingView.qml"

        }
        function onAccountDetails() {
            console.log("Clicked on AccountDetails")
            loader.source = "SevaReportPage.qml"
        }
        function onBookingreport() {
            console.log("Clicked on Bookingreport")
            loader.source = "BookingReportPage.qml"
        }
        function onAdmin() {
            console.log("Clicked on Admin")
            loader.source = "";
            loader.source= "qrc:/ui/Admin/AdminPage.qml"
            loader.item.width = _root.width
            loader.item.height = _root.height
        }

        function onCloseProject(){
            console.log("Clicked on CloseProject")
        }
        function onVoucher() {
            console.log("Clicked on Voucher")
            loader.source = "voucherPage.qml"
        }
        //        function onLoadVoucherPage()
        //        {
        //            console.log("In onLoadVoucherPage")
        //            loader.source = "voucherPage.qml"
        //        }

        function onSendVoucherReportInput(obj)
        {
            console.log("signal emitted from voucher report page in main.qml")
            voucherReportModel.generateVoucherReport(obj)
        }
        function onResetVouModel()
        {
            voucherReportModel.resetVouModel()
        }

        //seva Booking view Handlers
        function onLoadMenuPage() {
            console.log("loading Menu page from main")
            loader.source = "MenuPage.qml"
        }
        function onCloseAddSeva(){
            console.log("closing add seva page")
            loader.source = "MenuPage.qml"
        }
        function onLoadTrustsPage(){
            console.log("closing add seva page")
            loader.source = "MainTrust.qml"
        }
        function onErrorOccur(errorMsg)
        {
            console.log("In onErrorOccured of main")
            _errorDialog.showError(errorMsg);
            console.log("In onErrorOccured of main2222")
        }
        function onLoadUserManagement(){
            console.log("User Management loading")
            loader.source = "qrc:/ui/Admin/UserManagement.qml"
        }
        function onLoadAdminrights(){
            console.log("loading from main")
            loader.source = "qrc:/ui/Admin/AdminRights.qml"
        }
        function onLoadLogOut(){
            console.log("loading loagout from main")
            loader.source = "qrc:/ui/Login.qml";
        }
        function onLoadDevoteeSelection(){
            loader.source = "";
            loader.source = "qrc:/ui/Devotee/DevoteeSelectionPage.qml";
        }
        function onLoadSevabooking( d_name,d_mobile,d_gothra,d_nakshatra){
            console.log("main loadSevabooking-----",d_nakshatra)
            loader.source = "";
            loader.setSource("SevaBookingView.qml",{dname:d_name,dmobile:d_mobile,dgothra:d_gothra,d_Nakshtra:d_nakshatra})
        }
        function onLoadBankRegistration(){
            console.log("Clicked on Bank Registration")
            loader.source = ""
            loader.source = "qrc:/ui/BankRegistration/IntegrateFile.qml"
//            myModel.initial();
        }
        function onLoadVoucherAdministration(){
            console.log("Clicked on Voucher Registration")
            loader.source = ""
            loader.source = "qrc:/ui/QmlVoucher/VoucherApplication.qml"
        }
        function onShowAllDataView(){
            console.log("Clicked on show all data")

            console.log("Show all Data")
            //            progressBar.visible = true;
            //            progressBar.opacity = 0.1;
            var b = sevaProxy.showAllData();
            if(b===false)
            {
                errorOccur("cannot fetch data")
            }

            loader.source = ""
            loader.source = "qrc:/ui/SevaAllViewPage.qml"

        }
        function onLoadSevaBookingView(){

            loader.source = ""
            loader.source = "qrc:/ui/Devotee/DevoteeSelectionPage.qml";
        }
        function onGetCancelReceiptDetails(canceledObj){
            console.log("canceeled came here")
            storeObject=canceledObj
            sevaProxy.sevaBookingTV.checkStatus(canceledObj.sno);
        }
        function onBackClicked(){
            _ld.source=""
        }
        function onCancelClicked(){
            _errorDialog1.showError("Confirm to Cancel?",1);
        }
    }
    Connections{
        target: _root
        function onErrorOccur(errorMsg)
        {
            console.log("In onErrorOccured of main")
            _errorDialog.showError(errorMsg);
            console.log("In onErrorOccured of main2222")
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
            if(page===1){
                sevaProxy.setStatusToCancel(storeObject.sno)
                _errorDialog1.close()
            }
            if(page===2){
                _errorDialog1.close()
            }
        }

        onNoAction: {
            _errorDialog1.close()
        }
    }
    Connections
    {
        target:sevaProxy
        onStatusAlreadyCancelled:
        {
            console.log("Already Cancelled status came to qml loading MyDialogBox")
            _errorDialog2.showError("Status Already Cancelled !");
        }
    }

    Connections
    {
        target:sevaProxy.sevaBookingTV
        onStatusCancelledSuccess:
        {
            console.log("Status set to cancel")
            _errorDialog2.showError("Status Set to Cancel");
        }
        onAlreadyCancelled:{
            _errorDialog1.showError("Status Already Cancelled !",2);
        }
        onLoadCancelPage:{
            sevaProxy.cancelReceipt(storeObject.sno);
            loader.source="qrc:/ui/SevaCancelReceipt.qml"
        }
    }

    Timer{
        id:_timer
        running: false
        interval: 1500
        onTriggered: {
            _errorDialog2.close();
            loader.setSource("voucherPage.qml",{bookingElement:storeObject,pageNumber:1})
        }
    }
}
