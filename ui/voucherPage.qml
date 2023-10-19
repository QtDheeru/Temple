import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import VoucherElement 1.0
import "./components"

Rectangle{
    id:_r1
    property var styles : MyStyles{}
    width: styles.screenWidth
    height: styles.screenHeight
    property int subComponentHeight : height/20
    property int subComponentPixelSize : styles.fontSize
    signal loadMenuPage()
    signal resetVouModel()
    property var bookingElement
    property int  pageNumber
    signal  sendVoucherReportInput(var obj)
    // focus: true
    VouEle
    {
        id:_vouEle
    }
    RowLayout
    {
        anchors.fill: parent
        Rectangle{
            height: parent.height
            width: parent.width/3.5
            color: "#72FFFF"
            ColumnLayout {
                //        anchors.fill: parent
                width: parent.width
                id : _c1
                spacing: 5
                anchors.margins: 5
                MyDateEntry{
                    id:r1;
                    myHeight:_r1.subComponentHeight;
                    fontPixelSize: _r1.subComponentPixelSize
                    myWidth: parent.width/1.25
                    _labelText:qsTr("Reciept Date")
                    showPopup: true
                }
                MyRowEntry{
                    id:_voucherNo;
                    _data:saveVoucher.nextVoucherNumber
                    myHeight:_r1.subComponentHeight;
                    myWidth: parent.width/1.25
                    fontPixelSize: _r1.subComponentPixelSize
                    _labelText:qsTr("Voucher Number")
                    _editable:false
                }
                MyRowEntry
                {id:_name;
                    myHeight:subComponentHeight;
                    myWidth: parent.width/1.25
                    fontPixelSize: _r1.subComponentPixelSize
                    _labelText:qsTr("Name");regExpValidator: RegExpValidator{regExp:/^[a-zA-Z ]*$/}
                    focus: true
                    KeyNavigation.tab: _mobileNo
                }

                MyRowEntry
                {
                    id:_mobileNo;
                    myHeight:subComponentHeight;
                    myWidth: parent.width/1.25
                    fontPixelSize: _r1.subComponentPixelSize
                    _labelText:qsTr("Mobile No"); regExpValidator : RegExpValidator{regExp:/[0-9]{10}/}
                    focus: true
                    KeyNavigation.tab: _voucherType
                }

                MyComboEntry
                {
                    id:_voucherType;
                    myHeight:_r1.subComponentHeight;
                    fontPixelSize: _r1.subComponentPixelSize
                    myWidth: parent.width/1.25
                    Layout.topMargin: 10;_labelText :qsTr("Voucher type")
                    //                    KeyNavigation.tab: _item
                    _dataModel:voucherProxy.voucherHeadsTableModel
                    _dataModelRole:"vcategory"
                    Component.onCompleted:
                    {
                        voucherProxy.voucherHeadsTableModel.rowClicked(0);
                        voucherProxy.proxyList();
                        console.log("voucherTypemodel---",voucherProxy.voucherHeadsTableModel)
                    }
                    onCurrentIndexChanged:
                    {
                        console.log("my current Index",currentIndex)

                        voucherProxy.voucherHeadsTableModel.rowClicked(currentIndex);
                        voucherProxy.listAppendProxy();

                        // console.log("my current Index",currentIndex)
                    }

                    //                    _dataModel:["Financial","Groceries","Vegetables","Fruits and Flowers","Dairy Items","Computers & Digital","Misc","Others"]

                }

                Connections
                {
                    target:voucherProxy
                    onVouchToQml:
                    {
                        console.log("serial id ="+a_serial_no);
                        console.log("Category id ="+a_voucherId);
                        console.log("voucher name="+a_vouch_name);
                        voucherProxy.send_Voucher(a_voucherId);
                        voucherProxy.clearProxy();

                        myitem.currentIndex = 0 ;

                    }
                }


                MyComboEntry
                {
                    id:myitem
                    myHeight:_r1.subComponentHeight;
                    fontPixelSize: _r1.subComponentPixelSize
                    myWidth: parent.width/1.25
                    Layout.topMargin: 10;_labelText :qsTr("Item")
                    isEditable: true
                    _dataModel : voucherProxy.voucherSubHeadTableModel
                    _dataModelRole:"Vscn"
                    onCurrentIndexChanged: {
                        console.log("Changedddddddddddddddd  ", currentIndex)
                    }
                }

                MyRowEntry{id:_note;
                    myHeight:subComponentHeight;
                    myWidth: parent.width/1.25
                    fontPixelSize: _r1.subComponentPixelSize
                    _labelText:qsTr("Note");
                    focus: true
                    KeyNavigation.tab: _voucherType
                }
                MyRowEntry{id:_cost;
                    myHeight:subComponentHeight;
                    myWidth: parent.width/1.25
                    fontPixelSize: _r1.subComponentPixelSize
                    _labelText:qsTr("Cost");regExpValidator: RegExpValidator{regExp:/^[0-9 ]*$/}
                    focus: true
                    KeyNavigation.tab: _voucherType
                }
                MyComboEntry{
                    id:_paymentMode
                    myHeight:_r1.subComponentHeight;
                    fontPixelSize: _r1.subComponentPixelSize
                    myWidth: parent.width/1.25
                    Layout.topMargin: 10;_labelText :qsTr("Payment Mode")
                    isEditable: false
                    _dataModel:["Cash","Cheque","NEFT","UPI"]
                }

                MyRowEntry{id:_reference;
                    myHeight:subComponentHeight;
                    myWidth: parent.width/1.25
                    fontPixelSize: _r1.subComponentPixelSize
                    _labelText:qsTr("Reference No");
                    focus: true
                    KeyNavigation.tab: _voucherType
                    visible: false
                }

                Button{
                    id:_button
                    text: "Submit"
                    font.pixelSize: _r1.subComponentPixelSize
                    font.bold: true
                    Layout.preferredWidth: parent.width-20
                    Layout.preferredHeight: _r1.subComponentHeight;
                    Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                    onClicked: {
                        console.log("submit cutton clicked in voucher page")
                        console.log(_name._data.length)
                        console.log(_cost._data.length)
                        if((_name._data=="") || (_cost._data=="") ||(_mobileNo._data.length !=10) ||(_reference.visible==true && _reference._data=="") )
                        {
                            _errorDialog.showError("Insufficient Data")
                            console.log("data missing")
                        }
                        else
                        {
                            _vouEle.voucherDate = r1.selecteddate
                            _vouEle.voucherNo = _voucherNo._data
                            _vouEle.voucherName = _name._data
                            _vouEle.mobileNo = _mobileNo._data
                            _vouEle.voucherType = _voucherType._data
                            _vouEle.voucherItem = myitem._data
                            _vouEle.voucherNote = _note._data
                            _vouEle.voucherCost = _cost._data
                            _vouEle.voucherPaymentMode = _paymentMode._data
                            _vouEle.paymentReference = _reference._data
                            //_voucherNo.clearData()
                            _name.clearData()
                            _mobileNo.clearData()
                            _note.clearData()
                            _cost.clearData()
                            _reference.clearData()
                            saveVoucher.saveVoucherElements(_vouEle);
                            var li =  _vouEle.voucherDate.split("-");
                            var str = li[2]+"-"+li[1]+"-"+li[0];
                            _voucherReceiptDialog._vDate = str/*_vouEle.voucherDate*/
                            _voucherReceiptDialog._voucherNo = _vouEle.voucherNo
                            _voucherReceiptDialog._voucherName= _vouEle.voucherName
                            _voucherReceiptDialog._mobileNo= _vouEle.mobileNo
                            _voucherReceiptDialog._voucherType= _vouEle.voucherType
                            _voucherReceiptDialog._voucherItem= _vouEle.voucherItem
                            _voucherReceiptDialog._voucherNote= _vouEle. voucherNote
                            _voucherReceiptDialog._voucherCost= _vouEle.voucherCost
                            _voucherReceiptDialog._voucherPaymentMode= _vouEle.voucherPaymentMode
                            _voucherReceiptDialog._paymentReference= _vouEle.paymentReference
                            _voucherReceiptDialog.open();
                            _r1.opacity = 0.3;
                            console.log("Done")
                        }
                    }
                }

                Button{
                    id:_reportButton
                    text: "Report"
                    font.pixelSize: _r1.subComponentPixelSize
                    font.bold: true
                    Layout.preferredWidth: parent.width-20
                    Layout.preferredHeight: _r1.subComponentHeight;
                    Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                    onClicked: {
                        _load.source = "VoucherReportPage.qml"
                        console.log("Report button clicked in voucher page")
                    }
                }

            }
        }
        //        Image {
        //            id: voucherImage
        //            source: "qrc:/ui/assets/Images/voucher.jpg"
        //        }
    }

    Loader{
        id:_load
        //  focus: true

    }
    Connections{
        target: _load.item
        function onSendVoucherReportInput(obj)
        {
            console.log("signal emitted from voucher report page in voucherPage.qml")
            sendVoucherReportInput(obj)
        }
        function onLoadMenuPage()
        {
            loadMenuPage()
        }
        function onResetVouModel()
        {
            resetVouModel()
        }
        function onLoadVoucherPage()
        {
            console.log("In onLoadVoucherPage")
            _load.source = "voucherPage.qml"
        }
    }

    Connections{
        target:_voucherType
        function onItemChanged(j){

            console.log("Index Changed : "+j)
            if(j===0)
                _item._dataModel= ["Salary","Brahmana Dakshine"]
            else if(j===1)
                _item._dataModel= ["Daily use food items","Bale ele","Plastic/paper cups","Steel items/vessels","Other groceries"]
            else if(j===2)
                _item._dataModel= ["Daily use vegetables","Vratha vegetables","Special vegetables","Other vegetables"]
            else if(j===3)
                _item._dataModel= ["Bananas","Apples","Oranges","Bidi hoovu","Pushpa Maale","Daily pooja flowers","Other"]
            else if(j===4)
                _item._dataModel= ["Milk","Curd","Ghee","Butter","Other dairy items"]
            else if(j===5)
                _item._dataModel= ["Sheets, pens and papers","Printer related","Hardware related","Others"]
            else if(j===6)
                _item._dataModel= ["Miscellaneous","Misc2"]
            else
                _item._dataModel= ["Other Expenditure","Other small expenditure"]
        }
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

    Connections
    {
        target: _paymentMode
        function onItemChanged(j){
            if(j===0)

                _reference.visible = false
            else
                _reference.visible=true
        }
    }
    Keys.onEscapePressed: {
        console.log("Esc pressed in voucher page")
        loadMenuPage()
    }

    VoucherReceiptDialog{
        id:_voucherReceiptDialog
        anchors.centerIn: parent
        // Keys.onEscapePressed: _voucherReceiptDialog.close()
        //                    onPaymentComplete: {
        //                        console.log("Seva is store now..")
        //                        _sevaContoller.bookingComplete();
        //                        saveFullReceipt();
        //                        sevaProxy.printReceipt();
        //                        resetBaseScreen();
        //                        //resetNextControls(true)
        //                        paymentOver();
        //                    }
        onCloseClicked: {
            resetBaseScreen()
        }
        onConfirmClicked: {
            sevaProxy.printVoucherReceipt(_vouEle);
        }

        //onPrintClicked: {
        ////sevaProxy.printReceipt();
        //}
        onRejected: {
            resetBaseScreen()
        }
    }
    function resetBaseScreen(){
        _r1.opacity = 1;
    }
    Component.onCompleted: {
        console.log("In Component.onCompleted: of ")
        //forceActiveFocus();
        if(pageNumber == 1){
            loadConfirmationDailog(bookingElement)
        }
        else{
            console.log("Inside Default")
        }
    }
    function loadConfirmationDailog(bookingElem){

        _voucherReceiptDialog._vDate = voucherProxy.getCurrentDate()/*_vouEle.voucherDate*/
        _voucherReceiptDialog._voucherNo = voucherProxy.getLastVoucherNumber()
        _voucherReceiptDialog._voucherName= bookingElem.person.devoteeName
        _voucherReceiptDialog._mobileNo= bookingElem.person.mobileNumber
        _voucherReceiptDialog._voucherType=sevaProxy.getSevaTypeModel().getSevaTypeName(bookingElem.sevatype)
        _voucherReceiptDialog._voucherItem= bookingElem.sevaname
        _voucherReceiptDialog._voucherCost= bookingElem.totalCost
        _voucherReceiptDialog._voucherPaymentMode= bookingElem.bank

        _vouEle.voucherNo= _voucherReceiptDialog._voucherNo
        _vouEle.voucherDate = voucherProxy.getCurrentDate()
        _vouEle.voucherName = bookingElem.person.devoteeName
        _vouEle.mobileNo = bookingElem.person.mobileNumber
        _vouEle.voucherType = sevaProxy.getSevaTypeModel().getSevaTypeName(bookingElem.sevatype)
        _vouEle.voucherItem = bookingElem.sevaname
        _vouEle.voucherNote = _voucherReceiptDialog._voucherNote
        _vouEle.voucherCost = bookingElem.totalCost
        _vouEle.voucherPaymentMode = _voucherReceiptDialog._voucherPaymentMode
        _vouEle.paymentReference =_voucherReceiptDialog._paymentReference
        saveVoucher.saveVoucherElements(_vouEle);

        _voucherReceiptDialog.open();


    }
}

