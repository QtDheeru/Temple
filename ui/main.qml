import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Window 2.12
import "./components"
import "Reports/Account"
import "Reports/Booking"

ApplicationWindow {
    id :_root
    visible: true
    title: constant.addressText1
    color: "black"
    width: styles.screenWidth
    height: styles.screenHeight

    property var styles : MyStyles{}
    property var constant: Constants{}
    property var storeObject
    property string fileName: "main.qml "

    signal errorOccur(string errorMsg);

    Loader{
        id:loader
        anchors.fill: parent
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
        }
        onNoAction: {
            _errorDialog.close()
        }
    }

    Connections{
        target: loader.item
        //ignoreUnknownSignals: true

        function onWelcomeToAppTimeTriggered(){
            if(trustListModel.getTrustListSize()>1)
            {
                console.log(fileName + "trustListModel.getTrustListSize()"+trustListModel.getTrustListSize())
                loader.source= "MainTrust.qml"
            }
            if(trustListModel.getTrustListSize() === 1){
                console.log(fileName + "in else--------------");
                var trust= trustListModel.trustList[0];
                var trustName = trust.trustName;
                var trustCode = trust.trustCode;
                console.log(fileName + "in else------trustName--------"+trustName);
                console.log(fileName + "in else-------trustCode-------"+trustCode);
                trustListModel.trustCodeForConfig = trustCode;
                trustListModel.trustCodeForData = trustCode;
                trustListModel.currentTrust = trustName;
                var str1 = trustListModel.getConfigLocation();
                var str2 =trustListModel.getDataLocation();
                console.log(fileName + "str1 = --" + str1);
                console.log(fileName + "str2 = --" + str2);
                loader.source = "Login.qml"
                // loader.source = "qrc:/ui/Admin/DayExpenditure.qml"
            }
            if(trustListModel.getTrustListSize() === 0){
                console.log(fileName + "trustListModel.getTrustList===0");
                // loader.source= "MainTrust.qml"
                errorOccur("Trust not present");
            }
        }
        function onTimerTriggered() {
            console.log(fileName + "Welcome screen TimeTriggered");
            loader.source = "Login.qml"
        }
        function onDateClicked(date)
        {
            console.log(fileName + "date clicked " +date )
            var b = sevaProxy.sevaReport.onDateSelected(date)
            if(b === false)
            {
                errorOccur("date selected failed");
            }
            else{
                loader.source = "SevaReportOnDateView.qml"
            }
        }
        function onStartReportGeneration(date1){
            console.log(fileName + "Send Report Generation request to Backend")
            //sevaProxy.sevaReport.generateAccReport(obj)
        }
        function onSendReportImput(obj)
        {
            console.log(fileName + "Send Report Generation request to Backend")
            sevaProxy.sevaReport.generateAccReport(obj)
        }
        function onSendBookReportImput(obj)
        {
            console.log(fileName + "In main")
            sevaProxy.sevaReport.generateBookReport(obj)
        }

        function onSendBookingReportDateRangeImput(obj)
        {
            console.log(fileName + "In main")
            sevaProxy.sevaReport.generateBookingReportForEachDate(obj)
        }
        function onSendReportDateRangeImputForWholeMonth(obj)
        {
            // Every month report
            console.log(fileName + "In main")
            sevaProxy.sevaReport.generateAccReportForEachDateForWholeMonth(obj)
        }
        function onSendBookingReportDateRangeImputForWholeMonth(obj)
        {
            console.log(fileName + "In main")
            sevaProxy.sevaReport.generateBookingReportForEachDateForWholeMonth(obj)
        }
        function onSendReportMonthRangeImput(obj)
        {
            console.log(fileName + "In main")
            sevaProxy.sevaReport.generateAccReportForEachMonth(obj)
        }
        function onSendBookingReportMonthRangeImput(obj)
        {
            console.log(fileName + "In main")
            sevaProxy.sevaReport.generateBookingReportForEachMonth(obj)
        }
        function onSendBookReportInput(obj)
        {
            console.log(fileName + "In main")
            sevaProxy.sevaReport.generateBookReport(obj)
        }
        function onSendSingleDateReportInput(obj)
        {
            console.log(fileName + "In main")
            sevaProxy.sevaReport.generateAccReport(obj)
        }
        function onSendSingleDateBookingReportInput(obj)
        {
            console.log(fileName + "In main")
            sevaProxy.sevaReport.generateBookReport(obj)
        }
        function onResetAccModel(){
            console.log(fileName + "reset Model")
            sevaProxy.sevaReport.resetAccModel()
        }
        function onResetBookingModel(){
            console.log(fileName + "reset DateRangeModel")
            sevaProxy.sevaReport.resetBookingModel()
        }

        //Login Page Handlers
        function onWrongCred() {
            console.log(fileName + "Wrong credentials")
        }
        function onLoginSuccess(pcount) {
            console.log(fileName + "Login Success",pcount)
            if(pcount === 0){
                loader.source = "MenuPage.qml"}
            if(pcount === 2){
                console.log(fileName + "Inside pcount 2")
                loader.source = "qrc:/ui/Reports/Account/SevaReportPage.qml"
            }
            if (pcount === 4){
                console.log(fileName + "Inside pcount 4")
                loader.source = "qrc:/ui/Admin/AdminRights.qml"
            }
        }
        function onLoadWelcome() {
            console.log(fileName + "Correct credentials")
            loader.source = "WelcomeScreen.qml"
        }
        //Menu Page handlers
        function onSevabooking() {
            console.log(fileName + "clicked on Sevabooking")
            loader.source = "SevaBookingView.qml"

        }
        function onAccountDetails() {
            console.log(fileName + "Clicked on AccountDetails")
            loader.source = "qrc:/ui/Reports/Account/SevaReportPage.qml"
        }
        function onBookingreport() {
            console.log("Clicked on Bookingreport")
            loader.source = "qrc:/ui/Reports/Booking/BookingReportPage.qml"
        }
        function onAdmin() {
            console.log(fileName + "Clicked on Admin")
            loader.source = "";
            loader.source = "qrc:/ui/Admin/AdminPage.qml"
            loader.item.width = _root.width
            loader.item.height = _root.height
        }

        function onCloseProject(){
            console.log(fileName + "Clicked on CloseProject")
        }
        function onVoucher() {
            console.log(fileName + "Clicked on Voucher")
            loader.source = "VoucherPage.qml"
        }
        function onSendVoucherReportInput(obj)
        {
            console.log(fileName + "signal emitted from voucher report page in main.qml")
            voucherReportModel.generateVoucherReport(obj)
        }
        function onResetVouModel()
        {
            voucherReportModel.resetVouModel()
        }

        //seva Booking view Handlers
        function onLoadMenuPage() {
            console.log(fileName + "loading Menu page from main")
            loader.source = "";
            loader.source = "MenuPage.qml"
        }
        function onCloseAddSeva(){
            console.log(fileName + "closing add seva page")
            loader.source = "MenuPage.qml"
        }
        function onLoadTrustsPage(){
            console.log(fileName + "closing add seva page")
            loader.source = "MainTrust.qml"
        }
        function onErrorOccur(errorMsg)
        {
            console.log(fileName + "In onErrorOccured of main")
            _errorDialog.showError(errorMsg);
        }
        function onLoadUserManagement(){
            console.log(fileName + "User Management loading")
            loader.source = "qrc:/ui/Admin/UserManagement.qml"
        }
        function onLoadAdminrights(){
            console.log(fileName + "loading from main")
            loader.source = "qrc:/ui/Admin/AdminRights.qml"
        }
        function onLoadLogOut(){
            console.log(fileName + "loading loagout from main")
            loader.source = "qrc:/ui/Login.qml";
        }
        function onLoadDevoteeSelection(){
            loader.source = "";
            loader.source = "qrc:/ui/Devotee/DevoteeSelectionPage.qml";
        }
        function onLoadSevabooking( d_name,d_mobile,d_gothra,d_nakshatra){
            loader.source = "";
            loader.setSource("SevaBookingView.qml",{dname:d_name,dmobile:d_mobile,dgothra:d_gothra,dNakshtra:d_nakshatra})
        }
        function onLoadBankRegistration(){
            console.log(fileName + "Clicked on Bank Registration")
            loader.source = ""
            loader.source = "qrc:/ui/BankRegistration/IntegrateFile.qml"
        }
        function onLoadVoucherAdministration(){
            console.log(fileName + "Clicked on Voucher Registration")
            loader.source = ""
            loader.source = "qrc:/ui/QmlVoucher/VoucherApplication.qml"
        }
        function onShowAllDataView(){
            console.log(fileName + "Clicked on show all data")
            var b = sevaProxy.showAllData();
            if(b === false)
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
        function onBackClicked(){
            loader.source = ""
            loader.source = "qrc:/ui/SevaAllViewPage.qml"
        }
        function onReceiptCancel(receiptNo,amount){
            console.log(fileName + "onReceiptCancel :: receipt No: " + receiptNo + ":: total cost: " + amount)
            var currentDate = new Date().toLocaleDateString(Qt.locale(),"dd-MM-yyyy")
            _ld.z = 10
            _ld.setSource("qrc:/ui/VoucherReceiptDialog.qml",{_receiptNumber:receiptNo,pageNumber:1,_voucherCost:amount,_vDate : currentDate})
        }
        function onLoadProfitAndLossBasePage(){
            console.log(fileName + "onLoadProfitAndLossBasePage")
            loader.source = ""
            loader.source = "qrc:/ui/Reports/ProfitAndLoss/ProfitAndLossBasePage.qml"
        }

    }
    Loader{
        id:_ld
        anchors.fill: parent
        z:10
        opacity: 0
    }
    Connections{
        target: _ld.item
        function onVoucherReceiptDialogClosed(){
            console.log(fileName + "onVoucherReceiptDialogClosed ")
            _ld.z = 0
            loader.item.forceActiveFocus();
        }
    }

    Connections{
        target: _root
        function onErrorOccur(errorMsg)
        {
            console.log(fileName + "In onErrorOccured of main")
            _errorDialog.showError(errorMsg);
            console.log(fileName + "In onErrorOccured of main2222")
        }
    }

    Component.onCompleted: {
        console.log(fileName + "screen height= " + Screen.height)
        console.log(fileName + "screen width= " + Screen.width)
        console.log(fileName + "Screen MyStyles-screecnWidth size =" + styles.screenWidth)
        console.log(fileName + "Screen MyStyles-screenHeight size =" + styles.screenHeight)
        console.log(fileName + "screen density  == " + Screen.pixelDensity)
    }
}
