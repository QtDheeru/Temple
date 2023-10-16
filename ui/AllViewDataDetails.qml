import QtQuick 2.0
import "./components"
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as Qt14

Rectangle {
    width: 450;height: 450
    color:"lightblue"
//       property alias amount2Pay : _date._labelText
//        property alias cashPaid : _cash.amount2Pay
//        property bool isDataExist : _cash.isDataExist
//        property alias bankSelected : _banks._data
//        property alias checkOrTransactionId : _bankReference._data;
//        property alias note : _note._data;
//        function setBankList(bankList){
//                 _banks._datamodel = bankList;
//                 //_banks._datamodel =["SBI", "CanaraBank", "Karnataka","HDFC","ICICI"]
//        }

//        function clearData() {
//            _toPay.amount2Pay = 0;
//            _cash.amount2Pay = 0;
//            _bankReference.clearData()
//            _note.clearData();
//        }
    //    property alias _vDate: _date._data
    //    property alias _voucherNo: _voucherNo._data
    //    property alias _voucherName: _name._data
    //    property alias _mobileNo: _phoneNo._data
    //    property alias _voucherType:_voucherType._data
    //    property alias _voucherItem:_itm._data
    //    property alias _voucherNote: _note._data
    //    property alias _voucherCost:_cost._data
    //    property alias _voucherPaymentMode:_paymentMode._data
    //    property alias _paymentReference:_paymentRef._data
    //    property alias _vDate: _date._data
     // property alias _allViewSerialNo: _serialNo._data
    property alias _allViewPersonId: _personId._data
    property alias _allViewDevoteeName: _devoteeName._data
    property alias _allViewMobileNo: _mobileNo._data
    property alias _allViewGothra:_gothra._data
    property alias _allViewNakshatra:_nakshatra._data
    property alias _allViewSevaType: _sevaType._data
    property alias _allViewSevaName:_sevaName._data
    property alias _allViewQuantity:_quantity._data
    property alias _allViewReceiptDate:_receiptDate._data
    property alias _allViewSevaDate:_sevaDate._data
    property alias _allViewTotalCost:_totalCost._data
    property alias _allViewCash:_cash._data
    property alias _allViewBank:_bank._data
    ColumnLayout {
        anchors.fill: parent
        //        ButtonGroup {
        //            id: radGroup
        //            buttons: [_cash._radButton,_banks.radButton]
        //        }
        //  MyCashEntry{id:_toPay;_labelText:qsTr("Amount to Pay :");_editable : false}
        //        MyCashEntry{id:_cash;_labelText:qsTr("Cash")}
        //        MyBankEntry{id:_banks;_labelText:qsTr("Online")}
//        MyRowEntry {
//            id: _voucherNo
//            Layout.topMargin: 5
//            _labelText :qsTr("Voucher No :");
//            myWidth: parent.width/1.4
//            _editable : false
//            //myHeight:10
//            //  _labelFontSize:15
//        }
       // MyRowEntry {id:_serialNo;_labelText :qsTr("Serial No :");myWidth: parent.width/1.4;myHeight:parent.height/15;_editable : false}
        MyRowEntry {id:_personId;_labelText :qsTr("Person Id :");myWidth: parent.width/1.4;myHeight:parent.height/15;_editable : false}
        MyRowEntry {id:_devoteeName;_labelText :qsTr("Devotee Name :");myWidth: parent.width/1.4;myHeight:parent.height/15;_editable : false}
        MyRowEntry {id:_mobileNo;_labelText :qsTr("Phone No :");myWidth: parent.width/1.4;myHeight:parent.height/15;_editable : false}
        MyRowEntry {id:_gothra;_labelText :qsTr("Gothra :");myWidth: parent.width/1.4;myHeight:parent.height/15;_editable : false}
        MyRowEntry {id:_nakshatra;_labelText :qsTr("Nakshatra :");myWidth: parent.width/1.4;myHeight:parent.height/15;_editable : false}
        MyRowEntry {id:_sevaType;_labelText :qsTr("SevaType :");myWidth: parent.width/1.4;myHeight:parent.height/15;_editable : false}
        MyRowEntry {id:_sevaName;_labelText :qsTr("SevaName :");myWidth: parent.width/1.4;myHeight:parent.height/15;_editable : false}
        MyRowEntry {id:_quantity;_labelText :qsTr("Quantity :");myWidth: parent.width/1.4;myHeight:parent.height/15;_editable : false}
        MyRowEntry {id:_receiptDate;_labelText :qsTr("ReceiptDate :");myWidth: parent.width/1.4;myHeight:parent.height/15;_editable : false}
        MyRowEntry {id:_sevaDate;_labelText :qsTr("SevaDate :");myWidth: parent.width/1.4;myHeight:parent.height/15;_editable : false}
        MyRowEntry {id:_totalCost;_labelText :qsTr("TotalCost :");myWidth: parent.width/1.4;myHeight:parent.height/15;_editable : false}
        MyRowEntry {id:_cash;_labelText :qsTr("Cash :");myWidth: parent.width/1.4;myHeight:parent.height/15;_editable : false}
        MyRowEntry {id:_bank;_labelText :qsTr("Bank :");myWidth: parent.width/1.4;myHeight:parent.height/15;_editable : false}
        //   MyRowEntry {id:_note;_labelText :qsTr("Note");myWidth: parent.width/1.4}
    }
    Component.onCompleted: {
        console.log("Hello suman Alldata get")
        //setBankList(["UPI","GPay","PonePe","SBI", "CanaraBank", "Karnataka","HDFC","ICICI"]);
        //        console.log
        //        setBankList(sevaProxy.getBankList())
    }
}
