import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import VoucherElement 1.0
import "./components"

Dialog {
    id : root
    visible: true
    width: 600;
    height: 600;
    closePolicy: Popup.NoAutoClose
    modal: true
    anchors.centerIn: parent
    //   property alias amount2Pay : _sevaPayment.amount2Pay
    //   property string errorMessage: "Amount To Pay does not \n\n Match with Cash Paid"
    // property alias paymentObject : _sevaPayment
    //   signal paymentComplete();
    signal closeClicked();
    signal printClicked();
    signal confirmClicked();
    signal voucherReceiptDialogClosed()
    property alias _vDate : _voucherReceiptDetails._vDate
    property alias _voucherNo:_voucherReceiptDetails._voucherNo
    property alias _voucherName: _voucherReceiptDetails._voucherName
    property alias _mobileNo: _voucherReceiptDetails._mobileNo
    property alias _voucherType:_voucherReceiptDetails._voucherType
    property alias _voucherItem:_voucherReceiptDetails._voucherItem
    property alias _voucherNote: _voucherReceiptDetails._voucherNote
    property alias _voucherCost:_voucherReceiptDetails._voucherCost
    property alias _voucherPaymentMode:_voucherReceiptDetails._voucherPaymentMode
    property alias _paymentReference:_voucherReceiptDetails._paymentReference
    property alias _receiptNumber:_voucherReceiptDetails._receiptNumber
    title: "InitiatePrintVoucher"
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
        Text { text :"Voucher Receipt";anchors.centerIn: parent;
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
                //enabled: _sevaPayment.isDataExist
                onClicked: {
                    //                  if (checkAmoutPaid()) {
                    //                      paymentComplete();
                    //                      //_sevaPayment.clearData();
                    //                      _paymentDialog.close()
                    //                  } else {
                    //                      _display.text2Display = root.errorMessage
                    //                      _display.visible = true;
                    //                  }
                    //                }
                    //confirmClicked();
                    console.log("Current Date:" + voucherProxy.getCurrentDate() + ":: Vouchernumber: " + voucherProxy.getLastVoucherNumber())

                    console.log("_receiptNumber" + _receiptNumber + ":: Vouchernumber: " + voucherProxy.getLastVoucherNumber())
                    _vouEle.receiptNumber = _receiptNumber
                    _vouEle.voucherCost = _voucherCost
                    _vouEle.voucherDate = voucherProxy.getCurrentDate()
                    _vouEle.voucherNo = voucherProxy.getLastVoucherNumber()

                    _vouEle.voucherDate = _vDate
                    _vouEle.voucherName = _voucherName
                    _vouEle.mobileNo = _mobileNo
                    _vouEle.voucherType = _voucherType
                    _vouEle.voucherItem = _voucherItem
                    _vouEle.voucherNote = _voucherNote
                    _vouEle.voucherPaymentMode = _voucherPaymentMode
                    _vouEle.paymentReference = _paymentReference
                    saveVoucher.saveVoucherElements(_vouEle);
                    sevaProxy.printVoucherReceipt(_vouEle);
                    console.log("before voucher receipt dialog close  == "+ _vouEle.receiptNumber);
                    voucherReceiptDialogClosed();
                    root.close();
                }
            }
            Button{
                Layout.topMargin: 5;Layout.bottomMargin: 5;
                Layout.fillWidth: true;text :"Print"
                Layout.maximumHeight: parent.height-15
                font.pixelSize: 20
                //enabled: _sevaPayment.isDataExists
                visible: false
                onClicked:
                {
                    //    printClicked();
                }
            }
            Button{
                Layout.topMargin: 5;Layout.bottomMargin: 5;
                Layout.fillWidth: true;text :"Close"
                Layout.maximumHeight: parent.height-15
                font.pixelSize: 20
                onClicked: {
                    closeClicked();
                    root.close()
                }
            }
        }
    }
    VouEle
    {
        id:_vouEle
        Component.onDestruction : {
            console.log("_vouEle destructed")
        }
    }

    contentItem: VoucherReceiptDetails{id:_voucherReceiptDetails;Layout.fillWidth: true}
    Component.onCompleted: {
        console.log("VoucherReceiptDialog is created........")
        console.log(voucherProxy.getCurrentDate())
        console.log(voucherProxy.getLastVoucherNumber())
        root._vDate = voucherProxy.getCurrentDate()/*_vouEle.voucherDate*/
        root._voucherNo = voucherProxy.getLastVoucherNumber()
    }

}

