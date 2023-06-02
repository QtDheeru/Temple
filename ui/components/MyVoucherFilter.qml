import QtQuick 2.0

import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import VoucherFilterElement 1.0
Rectangle {
    id :_rootVoucherFilter
    //width: parent.width
    property var styles : MyStyles{}
    //height: styles.firstRowHeight;//150
    property int subComponentHeight : height/20
    property int subComponentPixelSize : styles.fontSize
    signal sendVoucherReportInput(var obj)
    //  signal sendError(string err);
    property alias  isSingleDateSelected: _selectDateRadio.checked
    signal sendError(string err);
    VouFilElem{
        id:_rip
    }

    ColumnLayout {
        //        anchors.fill: parent
        width: parent.width
        id : _c1
        spacing: 5
        //Layout.alignment: Qt.AlignTop
        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight: _rootVoucherFilter.subComponentHeight;
            color: "#576F72"
            border.width: 1
            border.color: "black"
            Layout.alignment: Qt.AlignTop
            Text {
                anchors.centerIn: parent
                id: _header
                text: qsTr("Filter Options")
                font.bold: true
                font.pixelSize:  _rootVoucherFilter.subComponentPixelSize
            }
        }

        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight: (_rootVoucherFilter.subComponentHeight+_comboboxLayout.spacing + _vouchertypeCheck.height)*2.3
            color: "#00A2ED"
            border.width: 1
            border.color: "black"
            Layout.alignment: Qt.AlignTop
            ColumnLayout{
                id: _comboboxLayout
                width: parent.width
                height:  parent.height/1.1
                spacing: _rootVoucherFilter.subComponentHeight/4
                CheckBox{
                    id:_vouchertypeCheck
                    checked: true
                    text: qsTr("All Voucher Types")
                    font.pixelSize:  _rootVoucherFilter.subComponentPixelSize
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin:   parent.width*0.33
                    onCheckedChanged: {
                        if(checked==false)
                        {
                            console.log("SevaType unchecked")
                            _vouchertype.enabled = true
                            // _rip.sVoucherType = _vouchertype._data
                            console.log(_rip.sVoucherType)

                        }
                        else
                        {
                            //  _rip.sVoucherType = "ALL"
                            console.log("SevaType checked")
                            _vouchertype.enabled = false

                        }
                    }
                }

                MyComboEntry{id:_vouchertype;
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight:_rootVoucherFilter.subComponentHeight;
                    myWidth: _rootVoucherFilter.width/1.1
                    fontPixelSize: 15
                    enabled: false
                    _labelText :qsTr("Voucher Type")
                    _dataModel:["Financial","Groceries","Vegetables","Fruits and Flowers","Dairy Items","Computers & Digital","Misc","Others"]

                }
                Rectangle{
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: 2
                    color: "black"
                }

                CheckBox{
                    id:_paymentModeCheck
                    checked: true
                    font.pixelSize:  _rootVoucherFilter.subComponentPixelSize
                    text: qsTr("All Payment Modes")
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin:   parent.width*0.33
                    onCheckedChanged: {
                        if(checked==false)
                        {
                            // _rip.sPaymentMode = _paymentMode._data
                            console.log(" _rip.sPaymentMode")
                            console.log( _rip.sPaymentMode)
                            _paymentMode.enabled = true
                        }
                        else
                        {
                            //  _rip.sPaymentMode = "ALL"
                            _paymentMode.enabled = false
                        }
                    }
                }

                MyComboEntry{id:_paymentMode;
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight:_rootVoucherFilter.subComponentHeight;
                    myWidth: _rootVoucherFilter.width/1.1
                    fontPixelSize: 15
                    enabled: false
                    _labelText :qsTr("Payment Mode")
                    _dataModel:["Cash","Cheque","NEFT","UPI"]
                }
            }
        }

        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight: (_rootVoucherFilter.subComponentHeight + _singleDateLayout.spacing ) *2.5
            color: "#00A2ED"
            border.width: 1
            border.color: "black"
            Layout.alignment: Qt.AlignTop
            ColumnLayout{
                width: parent.width
                height:  parent.height/1.1
                anchors.horizontalCenter: parent.horizontalCenter
                id: _singleDateLayout
                RadioButton{
                    ButtonGroup.group: radioGroup
                    id : _selectDateRadio
                    Layout.preferredHeight: _rootVoucherFilter.subComponentHeight;
                    Layout.preferredWidth: parent.width
                    font.pixelSize:  _rootVoucherFilter.subComponentPixelSize
                    text: "Select Date"
                    checked: true
                    onCheckedChanged: {
                        if(checked==false)
                            r1.enabled = false
                        else{
                            r1.enabled = true
                            _rip.iSelectedType = 0


                        }
                    }
                }
                MyDateEntry{

                    id:r1;
                    anchors.right: parent.right
                    enabled: true
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight:_rootVoucherFilter.subComponentHeight;
                    myWidth: _rootVoucherFilter.width/1.1
                    fontPixelSize: _rootVoucherFilter.subComponentPixelSize
                    _labelText:qsTr(" Select Date")
                }
            }
        }

        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight: (_rootVoucherFilter.subComponentHeight +_rangeDateLayout.spacing)*3.5
            color: "#00A2ED"
            border.width: 1
            border.color: "black"
            Layout.alignment: Qt.AlignTop
            ColumnLayout{
                width: parent.width
                height:  parent.height/1.1
                id:_rangeDateLayout
                RadioButton{
                    ButtonGroup.group: radioGroup
                    id: _rangeSelectedRadio
                    Layout.preferredHeight: _rootVoucherFilter.subComponentHeight;
                    Layout.preferredWidth: parent.width
                    font.pixelSize:  _rootVoucherFilter.subComponentPixelSize
                    text: "Select Date Range"
                    checked: false
                    onCheckedChanged: {
                        if(checked==false){
                            r2.enabled = false
                            r3.enabled = false
                        }
                        else{
                            r2.enabled = true
                            r3.enabled = true
                            _rip.iSelectedType = 1
                        }
                    }
                }
                MyDateEntry{
                    id:r2;
                    enabled: false
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    myHeight:_rootVoucherFilter.subComponentHeight;
                    myWidth: _rootVoucherFilter.width/1.1
                    fontPixelSize: _rootVoucherFilter.subComponentPixelSize
                    _labelText:qsTr(" Start Date")

                }
                MyDateEntry{
                    id:r3;
                    enabled: false
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    myHeight:_rootVoucherFilter.subComponentHeight;
                    myWidth: _rootVoucherFilter.width/1.1
                    fontPixelSize: _rootVoucherFilter.subComponentPixelSize
                    _labelText:qsTr("End Date")
                }
            }
        }

        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight: (_rootVoucherFilter.subComponentHeight +_rangeDateLayout.spacing)*3.5
            color: "#00A2ED"
            border.width: 1
            border.color: "black"
            Layout.alignment: Qt.AlignTop
            ColumnLayout{
                width: parent.width
                height:  parent.height/1.1
                id:_monthYearLayout
                RadioButton{
                    ButtonGroup.group: radioGroup
                    id: _monthYearRadio
                    Layout.preferredHeight: _rootVoucherFilter.subComponentHeight;
                    Layout.preferredWidth: parent.width
                    font.pixelSize:  _rootVoucherFilter.subComponentPixelSize
                    text: "Select Month Year"
                    checked: false
                    onCheckedChanged: {
                        if(checked==false){
                            _month.enabled = false
                            _year.enabled = false
                        }
                        else{
                            _month.enabled = true
                            _year.enabled = true
                            _rip.iSelectedType = 2
                            //                            _rip.sMonth = 1
                            //                            _rip.sYear = "2015"
                            _rip.sMonth = _month.currentIndex+1
                            _rip.sYear = _year._data
                            console.log("_month.currentIndex+1 "+_month.currentIndex+1)
                            console.log("_year._data "+_year._data)
                        }
                    }
                }
                MyComboEntry{id:_month;
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight:_rootVoucherFilter.subComponentHeight;
                    myWidth: _rootVoucherFilter.width/1.1
                    fontPixelSize: _rootVoucherFilter.subComponentPixelSize
                    enabled: false
                    _labelText :qsTr("Month")
                    _dataModel:["January","February","March","April","May","June","July","August","September","October","November","December"]
                }
                MyComboEntry{id:_year;
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight:_rootVoucherFilter.subComponentHeight;
                    myWidth: _rootVoucherFilter.width/1.1
                    fontPixelSize: _rootVoucherFilter.subComponentPixelSize
                    enabled: false
                    _labelText :qsTr("Year")
                    _dataModel:["2015","2016","2017","2018","2019","2020","2021","2022","2023","2024","2025","2026","2027","2028","2029","2030"]
                }
            }
        }
        Button{
            id:_button
            text: "Generate Report"
            font.pixelSize: _rootVoucherFilter.subComponentPixelSize
            font.bold: true
            Layout.preferredWidth: parent.width-20
            Layout.preferredHeight: _rootVoucherFilter.subComponentHeight;
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
            onClicked: {
                if(_paymentModeCheck.checked == true)
                {
                    _rip.sPaymentMode = "ALL"
                    console.log("_paymentMode checked")
                }
                else
                {
                    _rip.sPaymentMode = _paymentMode._data
                    console.log("_paymentMode Unchecked")
                }

                if(_vouchertypeCheck.checked == true)
                {
                    _rip.sVoucherType = "ALL"
                    console.log("_voucherType checked")
                }
                else
                {
                    _rip.sVoucherType = _vouchertype._data
                    console.log("_voucherType Unchecked")
                }

                if(_rangeSelectedRadio.checked == true)
                {
                    var date1 = Date.fromLocaleString(Qt.locale(), r2.selecteddate, "dd-MM-yyyy")
                    var date2 = Date.fromLocaleString(Qt.locale(), r3.selecteddate, "dd-MM-yyyy")

                    console.log("comparing dates : " +date1 +" "+date2)
                    if(date1 > date2)
                        _errorDialog.showError("Date Range Invalid")
                    else
                    {
                        _rip.sSingleDate =  "null"
                        _rip.sStartDate =  r2.selecteddate
                        _rip.sEndDate = r3.selecteddate
                        sendVoucherReportInput(_rip)
                        if((voucherReportModel.getVoucherReportQryListSize()===0))
                        {
                            console.log("---------b1----------------")
                            sendError("No Reports for this Date Range");
                        }

                    }
                }
                else
                {
                    _rip.sSingleDate = r1.selecteddate
                    _rip.sStartDate =  "null"
                    _rip.sEndDate = "null"
                    sendVoucherReportInput(_rip)
                    if((voucherReportModel.getVoucherReportQryListSize()===0)&&(_monthYearRadio.checked))
                    {
                        console.log("---------b21----------------")
                        sendError("No Reports for this Month & Year");
                    }
                    if((voucherReportModel.getVoucherReportQryListSize()===0)&&(_selectDateRadio.checked))
                    {
                        console.log("---------b22----------------")
                        sendError("No Reports for this Date ");
                    }
                }
                if(voucherReportModel.getVoucherReportQryListSize()===0)
                {
                    tot = voucherReportModel.grandTotal + ".00 ₹"
                }
                else{
                    tot = voucherReportModel.grandTotal + ".00 ₹"
                }
            }
        }

    }
    function clearData(){
        console.log(" Clear all the selection")
        // r4.clearData()
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
        target:_month
        function onSendCurrentMonth(mIndex){
            _month.currentIndex = mIndex
        }

        function onMonthChanged(mon){
            _rip.sMonth = mon
            console.log("Selected month"+ _rip.sMonth)
        }
    }
    Connections{
        target:_year
        function onSendCurrentYear(yIndex){
            _year.currentIndex = yIndex
        }
        function onYearChanged(yr){
            _rip.sYear = yr
            console.log("voucher Selected year"+ _rip.sYear)
        }
    }
    ButtonGroup { id: radioGroup }

    Component.onCompleted: {
        console.log(" Trying to get the list category")
        _rip.sSingleDate =  Qt.formatDate(new Date(), "dd-MM-yyyy")
        _rip.iSelectedType = 0
        _rip.sPaymentMode = "ALL"
        _rip.sVoucherType = "ALL"
        //sendVoucherReportInput(_rip)
        voucherReportModel.generateVoucherReport(_rip)
        if(voucherReportModel.getVoucherReportQryListSize()===0)
        {
            console.log("Component.completed:if of mvf.qml")
            sendError("No Reports for today");
        }
    }
}
