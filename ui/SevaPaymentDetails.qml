import QtQuick 2.0
import "./components"
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as Qt14

Rectangle {
    width: 400;height: 400
    color:"lightblue"
    property alias amount2Pay : _toPay.amount2Pay
    property alias cashPaid : _cash.amount2Pay
    property bool isDataExist : _cash.isDataExist
    property alias bankSelected : _banks._data
    property string paymentMode:"Cash"
    property alias checkOrTransactionId : _bankReference._data;
    property alias note : _note._data;
    property string  empty: ""
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
        Row {
            id:row
            Layout.preferredHeight:20
            Layout.preferredWidth: parent.width
            Layout.alignment: Qt.AlignLeft
            Layout.leftMargin: 20
            spacing: parent.width/8
            RadioButton {
                id: _cash1
                Layout.preferredHeight: parent.height;
                Layout.preferredWidth: parent.width/6
                font.pixelSize: 16
                text: "cash"
                checked: true
                onCheckedChanged: {
                    if(_cash1.checked===true){
                        _toPay.visible = true
                        _bankReference.visible = false
                        _banks.visible = false
                        _cash.visible = true
                        paymentMode= _cash1.text
                        _banks.data = empty
                    }
                }
            }
            RadioButton {
                id: _check
                Layout.preferredHeight: parent.height;
                Layout.preferredWidth: parent.width/6
                font.pixelSize: 16
                text: "Cheque"
                onCheckedChanged: {
                    if(_check.checked===true){
                        _toPay.visible = true
                        _bankReference.visible = true
                        _banks.visible = true
                        _cash.visible = true
                         paymentMode= _check.text
                    }
                }
            }
            RadioButton {
                id: _neft
                Layout.preferredHeight: parent.height;
                Layout.preferredWidth: parent.width/6
                font.pixelSize: 16
                text: "NEFT"
                onCheckedChanged: {
                    if(_neft.checked===true){
                        _toPay.visible = true
                        _bankReference.visible = true
                        _banks.visible = true
                        _cash.visible = true
                         paymentMode= _neft.text
                        _banks._data = ""
                    }
                }
            }
            RadioButton {
                id: _upi
                Layout.preferredHeight: parent.height;
                Layout.preferredWidth: parent.width/6
                font.pixelSize:16
                text: "UPI"
                onCheckedChanged: {
                    if(_upi.checked===true){
                        _toPay.visible = true
                        _bankReference.visible = true
                        _banks.visible = false
                        _cash.visible = true
                         paymentMode= _upi.text
                        _banks.data = empty
                    }
                }
            }
        }
        MyCashEntry{id:_toPay;_labelText:qsTr("Amount to Pay :");_editable : false}
        MyCashEntry{id:_cash;_labelText:qsTr("Enter Amount:")}
        MyBankEntry{id:_banks;_labelText:qsTr("Bank")}
        MyRowEntry{
            id: _bankReference
            Layout.topMargin: 5
            _labelText :_upi.checked==true?qsTr("UPI.Ref.No") :qsTr("ChequeNo/TranscationID");
            myWidth: parent.width/1.4
            myHeight:10
            _labelFontSize:25
        }
        MyRowEntry {id:_note;_labelText :qsTr("Note");
            myWidth: parent.width/1.4
        }
    }
    Component.onCompleted: {
        //setBankList(["UPI","GPay","PonePe","SBI", "CanaraBank", "Karnataka","HDFC","ICICI"]);
        console.log
        setBankList(sevaProxy.getBankList())
        if(_cash1.checked===true){
            _bankReference.visible = false
            _banks.visible = false
            _cash.visible = true
        }
    }
}
