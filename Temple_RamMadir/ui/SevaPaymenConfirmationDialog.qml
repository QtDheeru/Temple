import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import "./components"

Dialog {
    id : root
    visible: false
    width: 500;
    height: 400;
    closePolicy: Popup.NoAutoClose

    modal: true
    property alias amount2Pay : _sevaPayment.amount2Pay
    property string errorMessage: "Amount To Pay does not \n\n Match with Cash Paid"
    property alias paymentObject : _sevaPayment
    signal paymentComplete();
    signal closeClicked();
    signal printClicked();
    signal errorOccur(string errorMsg);
    function clearData() {
        console.log(" ")
        _sevaPayment.clearData()
    }

    title: "InitiatePayment"
    background: Rectangle{
        anchors.fill: parent
        color:"lightblue"
        border.width: 1;
        border.color: "black"
    }

    header: Rectangle{
        width: parent.width;
        height: 40;color:"#00A4EF"
        border.width: 1;border.color: "black"
        Text { text :" Start the Payment Process";anchors.centerIn: parent;
            font.pixelSize: 20}
    }
    footer: Rectangle {
        width: parent.width
        height: 50;color:"#00A4EF"
        border.width: 1;border.color: "black"
        RowLayout{
            width: parent.width-5;
            height : parent.height
            anchors.centerIn: parent
            spacing: 5
            Layout.margins: 5
            Button{
                Layout.topMargin: 5;Layout.bottomMargin: 5;
                Layout.fillWidth: true;text :"Confirm"
                Layout.maximumHeight: parent.height-15
                font.pixelSize: 20
                enabled: _sevaPayment.isDataExist
                onClicked: {
                  if (checkAmoutPaid()) {
                      paymentComplete();
                      //_sevaPayment.clearData();
                      _paymentDialog.close()
                  } else {
                      _display.text2Display = root.errorMessage
                      _display.visible = true;
                  }
                }
            }
            Button{
                Layout.topMargin: 5;Layout.bottomMargin: 5;
                Layout.fillWidth: true;text :"Print"
                Layout.maximumHeight: parent.height-15
                font.pixelSize: 20
                enabled: _sevaPayment.isDataExist
                visible: false
                onClicked: {
                  printClicked();
                }
            }
            Button{
                Layout.topMargin: 5;Layout.bottomMargin: 5;
                Layout.fillWidth: true;text :"Close"
                Layout.maximumHeight: parent.height-15
                font.pixelSize: 20
                onClicked: {
                    closeClicked();
                    _paymentDialog.close()
                }
            }
        }
    }

    x: (parent.width - width) / 2
    y: (parent.height - height) / 2
    contentItem: SevaPaymentDetails{id:_sevaPayment;Layout.fillWidth: true}

    function checkAmoutPaid(){
         var tempAmount2Pay = _sevaPayment.amount2Pay.trim().substring(4).trim()
         if (tempAmount2Pay === _sevaPayment.cashPaid.trim()){
             console.log("Amount Paid does match. Contine further ="+tempAmount2Pay + " 2BePaid ="+_sevaPayment.cashPaid.trim())
             return true;
         }else {
             console.log("Amount Paid does match. Contine further ="+tempAmount2Pay + " 2BePaid ="+_sevaPayment.cashPaid.trim())
             return false;
         }
    }

    DisplayDialog{
        id :_display
        visible: false
    }
    DisplayDialog {
        id :_errorDialog
        visible: false

        function showError(message){
            console.log("Dialog object is ccreated in SPCD1111");
            _errorDialog.parent= root.parent
            _errorDialog.visible = true;
            _errorDialog.text2Display = message
            _errorDialog.open();
            console.log("Dialog object is ccreated in SPCD2222");
        }
        Component.onCompleted: {
            console.log("Dialog object is ccreated in SPCD");
        }
    }
    Connections{
        target:root
        function onErrorOccur(errorMsg)
        {
            console.log("In connections of on error occur of seva paymen confirmation dialog")
            _errorDialog.showError(errorMsg);
        }
    }
    onOpened: {
        console.log("********* In onOpened: of spcd  *********** ")
        var bankList =  sevaProxy.getBankList();
        console.log("********* In onOpened: of spcd  **bankList.length********* "+bankList.length)
        if(bankList.length===0)
        {
            console.log("********* In if of  onOpened: of spcd  *********** ")
            errorOccur("Banks not found continue with cash");
        }
    }

    Component.onCompleted: {
        console.log("In Component.onCompleted: of SevaPaymenConfirmationDialog");
    }
}
