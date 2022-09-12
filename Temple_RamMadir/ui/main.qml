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
    property var constant: Constants{}
    title: constant.addressText1
    color: "black"
    flags: Qt.Dialog
    
    Component.onCompleted: {
        //        console.log("=====" + confApp.appPath + "/" + confApp.welcomescreenImg );
        //        console.log( confApp.welcomescreenImg);

        console.log("screen height= " + Screen.height)
        console.log("screen width= " + Screen.width)
        console.log("Screen MyStyles-screenWidth size =" + styles.screenWidth)
        console.log("Screen MyStyles-screenHeight size =" + styles.screenHeight)
        console.log("screen density  == " + Screen.pixelDensity)
    }
    Loader{
        id:loader
        anchors.fill: parent
        source: "WelcomeToAppScreen.qml"
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
                loader.source = "WelcomeScreen.qml"
                //        loader.source= "SevaBookingView.qml"
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

        //Login Page Handlers
        function onWrongCred() {
            console.log("Wrong credentials")
        }
        function onLoginSuccess() {
            console.log("Wrong credentials")
            loader.source = "MenuPage.qml"
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
        }
        function onAdmin() {
            console.log("Clicked on Admin")
            //            loader.source = "AddSevas.qml"
        }
        function onCloseProject(){
            console.log("Clicked on CloseProject")
        }
        function onVoucher() {
            console.log("Clicked on Voucher")
        }
        //seva Booking view Handlers
        function onLoadMenuPage() {
            console.log("loading Menu page")
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
}
