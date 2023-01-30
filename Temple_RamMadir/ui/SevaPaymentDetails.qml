import QtQuick 2.0
import "./components"
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as Qt14

Rectangle {
    width: 250;height: 250
    color:"lightblue"
    property alias amount2Pay : _toPay.amount2Pay
    property alias cashPaid : _cash.amount2Pay
    property bool isDataExist : _cash.isDataExist
    property alias bankSelected : _banks._data
    property alias checkOrTransactionId : _bankReference._data;
    property alias note : _note._data;
    function setBankList(bankList){
             _banks._datamodel = bankList;
             //_banks._datamodel =["SBI", "CanaraBank", "Karnataka","HDFC","ICICI"]
    }

    function clearData() {
        _toPay.amount2Pay = 0;
        _cash.amount2Pay = 0;
        _bankReference.clearData()
        _note.clearData();
    }

    ColumnLayout {
        anchors.fill: parent
        ButtonGroup {
            id: radGroup
            buttons: [_cash._radButton,_banks.radButton]
        }
        MyCashEntry{id:_toPay;_labelText:qsTr("Amount to Pay :");_editable : false}
        MyCashEntry{id:_cash;_labelText:qsTr("Cash")}
        MyBankEntry{id:_banks;_labelText:qsTr("Online")}
        MyRowEntry {
            id: _bankReference
            Layout.topMargin: 5
            _labelText :qsTr("ChequeNo/TranscationID");
            myWidth: parent.width/1.4
            myHeight:10
            _labelFontSize:15
        }
        MyRowEntry {id:_note;_labelText :qsTr("Note");myWidth: parent.width/1.4}
    }
    Component.onCompleted: {
        //setBankList(["UPI","GPay","PonePe","SBI", "CanaraBank", "Karnataka","HDFC","ICICI"]);
        console.log
        setBankList(sevaProxy.getBankList())
    }
}
