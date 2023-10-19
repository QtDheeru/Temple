import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import "./components"

Dialog {
    id : root
    visible: false
    width: 600;
    height: 600;
    //    width: Screen.width/2
    //    height: Screen.height/1.5
    closePolicy: Popup.NoAutoClose
    //y:20
    modal: true
    //   property alias amount2Pay : _sevaPayment.amount2Pay
    //   property string errorMessage: "Amount To Pay does not \n\n Match with Cash Paid"
    // property alias paymentObject : _sevaPayment
    //   signal paymentComplete();
    signal closeClicked();
    signal printClicked();
    signal confirmClicked();
    //   signal errorOccur(string errorMsg);
    //    function clearData() {
    //        console.log(" ")
    //        _sevaPayment.clearData()
    //    }
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
                enabled: _sevaPayment.isDataExist
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
                    confirmClicked();
                }
            }
            Button{
                Layout.topMargin: 5;Layout.bottomMargin: 5;
                Layout.fillWidth: true;text :"Print"
                Layout.maximumHeight: parent.height-15
                font.pixelSize: 20
                enabled: _sevaPayment.isDataExists
                visible: false
                onClicked: {
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
                    _voucherReceiptDialog.close()
                }
            }

        }
    }

    //    x: (parent.width - width) / 2
    //   y: (parent.height - height) / 2
    contentItem: VoucherReceiptDetails{id:_voucherReceiptDetails;Layout.fillWidth: true}





}

