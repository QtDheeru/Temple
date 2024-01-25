import QtQuick 2.0
import "./components"
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as Qt14

Rectangle {
    width: 450;height: 450
    color: "lightblue"
    //   property alias amount2Pay : _date._labelText
    //    property alias cashPaid : _cash.amount2Pay
    //    property bool isDataExist : _cash.isDataExist
    //    property alias bankSelected : _banks._data
    //    property alias checkOrTransactionId : _bankReference._data;
    //    property alias note : _note._data;
    //    function setBankList(bankList){
    //             _banks._datamodel = bankList;
    //             //_banks._datamodel =["SBI", "CanaraBank", "Karnataka","HDFC","ICICI"]
    //    }

    //    function clearData() {
    //        _toPay.amount2Pay = 0;
    //        _cash.amount2Pay = 0;
    //        _bankReference.clearData()
    //        _note.clearData();
    //    }
    property alias _vDate: _date._data
    property alias _voucherNo: _voucherNo._data
    property alias _voucherName: _name._data
    property alias _mobileNo: _phoneNo._data
    property alias _voucherType:_voucherType._data
    property alias _voucherItem:_itm._data
    property alias _voucherNote: _note._data
    property alias _voucherCost:_cost._data
    property alias _voucherPaymentMode:_paymentMode._data
    property alias _paymentReference:_paymentRef._data
    property alias _receiptNumber:_recNo._data
    ColumnLayout {
        anchors.fill: parent
        //        ButtonGroup {
        //            id: radGroup
        //            buttons: [_cash._radButton,_banks.radButton]
        //        }
        //  MyCashEntry{id:_toPay;_labelText:qsTr("Amount to Pay :");_editable : false}
        //        MyCashEntry{id:_cash;_labelText:qsTr("Cash")}
        //        MyBankEntry{id:_banks;_labelText:qsTr("Online")}
        MyRowEntry {
            id: _voucherNo
            Layout.topMargin: 5
            _labelText :qsTr("Voucher No :");
            myWidth: parent.width/1.4
            _editable : false
            //myHeight:10
            //  _labelFontSize:15
        }
        MyRowEntry {id:_date;_labelText :qsTr("Date :");myWidth: parent.width/1.4;_editable : false}
        MyRowEntry {id:_name;_labelText :qsTr("Name :");myWidth: parent.width/1.4;_editable : false}
        MyRowEntry {id:_phoneNo;_labelText :qsTr("Phone No :");myWidth: parent.width/1.4;_editable : false}
        MyRowEntry {id:_cost;_labelText :qsTr("Cost :");myWidth: parent.width/1.4;_editable : true}
        MyRowEntry {id:_voucherType;_labelText :qsTr("Voucher Type :");myWidth: parent.width/1.4;_editable : false}
        MyRowEntry {id:_paymentMode;_labelText :qsTr("Payment Mode :");myWidth: parent.width/1.4;_editable : true}
        MyRowEntry {id:_paymentRef;_labelText :qsTr("Payment Ref :");myWidth: parent.width/1.4;_editable : true}
        MyRowEntry {id:_note;_labelText :qsTr("Note :");myWidth: parent.width/1.4;_editable : true}
        MyRowEntry {id:_itm;_labelText :qsTr("Item :");myWidth: parent.width/1.4;_editable : false}
        MyRowEntry {id:_recNo;_labelText:qsTr("Receipt No. :");myWidth: parent.width/1.4;_editable : false}
        //   MyRowEntry {id:_note;_labelText :qsTr("Note");myWidth: parent.width/1.4}
    }
    Component.onCompleted: {
        console.log("VoucherReceiptDetails is created...")
        //setBankList(["UPI","GPay","PonePe","SBI", "CanaraBank", "Karnataka","HDFC","ICICI"]);
        //        console.log
        //        setBankList(sevaProxy.getBankList())
    }
}
