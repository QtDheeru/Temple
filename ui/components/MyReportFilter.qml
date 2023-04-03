import QtQuick 2.0

import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import ReportElements 1.0
Rectangle {
    id :_rootReportFilter
    //width: parent.width
    property var styles : MyStyles{}
    //height: styles.firstRowHeight;//150
    property int subComponentHeight : height/20
    property int subComponentPixelSize : styles.fontSize
    property var currentSevaType
    property var currentSevaName
    property alias seWise: _sevawise.checked
    property alias dtWise : _datewise.checked
    property alias iSelType: _rip.iSelectedType
    property alias iSevType: _rip.iSevaType
    property alias  sevNam: _rip.sSevaName
    property alias  mnt: _rip.sMonth
    property alias  yr: _rip.sYear
    property alias  isRangeDateSelected: _rangeSelectedRadio.checked
    property alias  isSingleDateSelected: _selectDateRadio.checked
    //property alias  repItm: _rip
    property alias isAllselected:_month._data
    // property alias repEle: _rip
    signal dateRangeSelected();
    signal monthWiseSelected();
    //color: "lightblue"
    signal sendReportInput(var obj)
    signal sendBookReportInput(var obj)
    signal bookingDateRangeSelected();
    signal sendReportDateRangeInput(var obj)
    signal sendBookingReportDateRangeInput(var obj)
    signal sendReportMonthRangeInput(var obj)
    signal loadDateWisePage();
    signal loadSingleDatePage();
    signal sendReportDateRangeInputForWholeMonth(var obj)
    signal sendBookingReportDateRangeInputForWholeMonth(var obj)
    signal sendBookingReportMonthRangeInput(var obj)
    signal bookingMonthWiseSelected();
    signal loadDateWiseBookingPage();
    signal sendError(string err);
    property string sevatime : "08:00 AM"
    ColumnLayout {
        //        anchors.fill: parent
        width: parent.width
        id : _c1
        spacing: 5
        //Layout.alignment: Qt.AlignTop
        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight:_rootReportFilter.subComponentHeight*1.5
            color: "#00A2ED"
            border.width: 1
            border.color: "black"
            Layout.topMargin: 5
            Layout.alignment: Qt.AlignTop

            RowLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: 10
                RadioButton {
                    id: _sevawise
                    Layout.preferredHeight: _rootReportFilter.subComponentHeight;
                    Layout.preferredWidth: _rootReportFilter.width/2
                    font.pixelSize:  _rootReportFilter.subComponentPixelSize
                    text: "Seva wise"
                    checked: true
                }
                RadioButton {
                    id: _datewise
                    Layout.preferredHeight: _rootReportFilter.subComponentHeight;
                    Layout.preferredWidth: _rootReportFilter.width/2
                    font.pixelSize:  _rootReportFilter.subComponentPixelSize
                    text: "Date wise"
                    visible: false
                    checked: false
                }
            }
        }
        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight: (_rootReportFilter.subComponentHeight+_comboboxLayout.spacing + _sevatypeCheck.height)*2.3
            color: "#00A2ED"
            border.width: 1
            border.color: "black"
            Layout.alignment: Qt.AlignTop
            ColumnLayout{
                id: _comboboxLayout
                width: parent.width
                height:  parent.height/1.1
                spacing: _rootReportFilter.subComponentHeight/4
                CheckBox{
                    id:_sevatypeCheck
                    checked: true
                    text: qsTr("All Seva Types")
                    font.pixelSize:  _rootReportFilter.subComponentPixelSize
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin:   parent.width*0.33
                    onCheckedChanged: {
                        if(checked==false)
                        {
                            _rip.iSevaType=  currentSevaType;
                            console.log("SevaType unchecked")
                            _sevaType.enabled = true
                            if(_sevanameCheck.checked == false)
                                _sevaName.enabled = true
                            else
                                _sevaName.enabled = false
                            _sevanameCheck.enabled = true
                        }
                        else
                        {
                            _rip.iSevaType=  0;
                            console.log("SevaType checked")
                            _sevaType.enabled = false
                            _sevaName.enabled = false
                            _sevanameCheck.enabled = false
                        }
                    }
                }

                MyComboEntry{id:_sevaType;
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight:_rootReportFilter.subComponentHeight;
                    myWidth: _rootReportFilter.width/1.1
                    fontPixelSize: _rootReportFilter.subComponentPixelSize
                    enabled: false
                    _labelText :qsTr("Seva Type")
                }
                Rectangle{
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: 2
                    color: "black"
                }

                CheckBox{
                    id:_sevanameCheck
                    enabled: false
                    checked: true
                    font.pixelSize:  _rootReportFilter.subComponentPixelSize
                    text: qsTr("All Seva Names")
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin:   parent.width*0.33
                    onCheckedChanged: {
                        if(checked==false)
                        {
                            _rip.sSevaName=  currentSevaName
                            _sevaName.enabled = true
                        }
                        else
                        {
                            _rip.sSevaName=  "All";
                            _sevaName.enabled = false
                        }
                    }
                }

                MyComboEntry{id:_sevaName;
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight:_rootReportFilter.subComponentHeight;
                    myWidth: _rootReportFilter.width/1.1
                    fontPixelSize: _rootReportFilter.subComponentPixelSize
                    enabled: false
                    _labelText :qsTr("Seva Name")
                }
            }
        }

        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight: (_rootReportFilter.subComponentHeight + _singleDateLayout.spacing ) *2.5
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
                    Layout.preferredHeight: _rootReportFilter.subComponentHeight;
                    Layout.preferredWidth: parent.width
                    font.pixelSize:  _rootReportFilter.subComponentPixelSize
                    text: "Select Date"
                    checked: true
                    onCheckedChanged: {
                        if(checked==false)
                            r1.enabled = false
                        else{
                            r1.enabled = true
                            _rip.iSelectedType = 0

                        }
                        //                        if(sevaProxy.sevaReport.accReportModel.getAccountReportQryListSize()===0)
                        //                        {
                        //                            tot = sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
                        //                        }
                        //                        else{
                        //                            tot = sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
                        //                        }
                    }
                }
                MyDateEntry{

                    id:r1;
                    anchors.right: parent.right
                    enabled: true
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight:_rootReportFilter.subComponentHeight;
                    myWidth: _rootReportFilter.width/1.1
                    fontPixelSize: _rootReportFilter.subComponentPixelSize
                    _labelText:qsTr(" Select Date")
                }
            }
        }

        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight: (_rootReportFilter.subComponentHeight +_rangeDateLayout.spacing)*3.5
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
                    Layout.preferredHeight: _rootReportFilter.subComponentHeight;
                    Layout.preferredWidth: parent.width
                    font.pixelSize:  _rootReportFilter.subComponentPixelSize
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
                    myHeight:_rootReportFilter.subComponentHeight;
                    myWidth: _rootReportFilter.width/1.1
                    fontPixelSize: _rootReportFilter.subComponentPixelSize
                    _labelText:qsTr(" Start Date")
                }
                MyDateEntry{
                    id:r3;
                    enabled: false
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    myHeight:_rootReportFilter.subComponentHeight;
                    myWidth: _rootReportFilter.width/1.1
                    fontPixelSize: _rootReportFilter.subComponentPixelSize
                    _labelText:qsTr("End Date")
                }
            }
        }

        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight: (_rootReportFilter.subComponentHeight +_rangeDateLayout.spacing)*3.5
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
                    Layout.preferredHeight: _rootReportFilter.subComponentHeight;
                    Layout.preferredWidth: parent.width
                    font.pixelSize:  _rootReportFilter.subComponentPixelSize
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
                            //                            _rip.bSevawise = _sevawise.checked
                            //                            _rip.bDatewise = _datewise.checked
                            //                            _rip.sSingleDate =  "null"
                            //                            _rip.sStartDate =  "null"
                            //                            _rip.sEndDate = "null"
                            console.log("_month.currentIndex+1 "+_month.currentIndex+1)
                            console.log("_year._data "+_year._data)
                        }
                    }
                }
                MyComboEntry{id:_month;
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight:_rootReportFilter.subComponentHeight;
                    myWidth: _rootReportFilter.width/1.1
                    fontPixelSize: _rootReportFilter.subComponentPixelSize
                    enabled: false
                    _labelText :qsTr("Month")
                    _dataModel:["January","February","March","April","May","June","July","August","September","October","November","December","All"]
                }
                MyComboEntry{id:_year;
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight:_rootReportFilter.subComponentHeight;
                    myWidth: _rootReportFilter.width/1.1
                    fontPixelSize: _rootReportFilter.subComponentPixelSize
                    enabled: false
                    _labelText :qsTr("Year")
                    _dataModel:["2015","2016","2017","2018","2019","2020","2021","2022","2023","2024","2025","2026","2027","2028","2029","2030"]
                }
            }
        }
        Button{
            id:_button
            text: "Generate Report"
            font.pixelSize: _rootReportFilter.subComponentPixelSize
            font.bold: true
            Layout.preferredWidth: parent.width-20
            Layout.preferredHeight: _rootReportFilter.subComponentHeight;
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
            onClicked: {
                if((_rip.sMonth==="13")&&(_monthYearRadio.checked))
                {
                    console.log("rip.sMonth===All")
                    sendReportMonthRangeInput(_rip)
                    monthWiseSelected();
                    if(sevaProxy.sevaReport.accountReportMonthRangeModel.getAccountReportMonthWiseQryListSize()===0)
                    {
                        console.log("if of sevaProxy.sevaReport.accountReportMonthRangeModel.getAccountReportMonthWiseQryListSize()===0 ")
                        sendError("No Reports for this Year");
                    }
//                    sendBookingReportMonthRangeInput(_rip)
//                    bookingMonthWiseSelected();
//                    if(sevaProxy.sevaReport.bookingReportMonthWiseModel.getBookingReportMonthWiseQryListSize()===0)
//                    {
//                        console.log("  if( _selectDateRadio.checked) if of mft.qml")
//                        if(sevaProxy.sevaReport.accountReportMonthRangeModel.getAccountReportMonthWiseQryListSize()!==0)
//                        {
//                            sendError("No Reports for this Year");
//                        }
//                    }
                }

                if(_rangeSelectedRadio.checked == true)
                {
                    console.log("---------a----------------")
                    var date1 = Date.fromLocaleString(Qt.locale(), r2.selecteddate, "dd-MM-yyyy")
                    var date2 = Date.fromLocaleString(Qt.locale(), r3.selecteddate, "dd-MM-yyyy")

                    console.log("comparing dates : " +date1 +" "+date2)
                    if(date1 > date2)
                        _errorDialog.showError("Date Range Invalid")
                    else
                    {
                        console.log("---------b----------------")
                        _rip.bSevawise = _sevawise.checked
                        _rip.bDatewise = _datewise.checked
                        _rip.sSingleDate =  "null"
                        _rip.sStartDate =  r2.selecteddate
                        _rip.sEndDate = r3.selecteddate
                        sendReportDateRangeInput(_rip)
                        if((sevaProxy.sevaReport.accountReportDateRangeModel.getAccountReportDateRangeQryListSize()===0))
                        {
                            console.log("---------b1----------------")
                            console.log("  if( _selectDateRadio.checked) if of mft.qml")
                            sendError("No Reports for this Date Range");
                        }
                      //  sendBookingReportDateRangeInput(_rip)
//                        if((sevaProxy.sevaReport.bookingReportDateRangeModel.getBookingReportDateRangeQryList()===0)&&(sevaProxy.sevaReport.accountReportDateRangeModel.getAccountReportDateRangeQryListSize()===0))
//                        {
//                            console.log("---------b2----------------")
//                            console.log("  if( _selectDateRadio.checked) if of mft.qml")
                            //                            if(sevaProxy.sevaReport.accountReportDateRangeModel.getAccountReportDateRangeQryListSize()!==0)
                            //                            {
                            //                                  console.log("---------b2----------------")
                            //                                sendError("No Reports for this Date Range");
                            //                            }
                            //sendError("No Reports for this Date Range");
                       // }
                    }
                    //  _load.source = "SevaAccountReportOnDateRange.qml"
                    dateRangeSelected();
                   // bookingDateRangeSelected();
                }
                //else
                if( _selectDateRadio.checked)
                {
                    console.log("---------c----------------")
                    _rip.bSevawise = _sevawise.checked
                    _rip.bDatewise = _datewise.checked
                    _rip.sSingleDate = r1.selecteddate
                    _rip.sStartDate =  "null"
                    _rip.sEndDate = "null"
                    console.log("  _rip.sSingleDate 1 "+ _rip.sSingleDate)
                    console.log("-------------------------------------")
                    sendReportInput(_rip)
                    if( sevaProxy.sevaReport.accReportModel.getAccountReportQryListSize()===0)
                    {
                        console.log(" if of sevaProxy.sevaReport.accountReportModel.getAccountReportQryListSize()===0")
                        sendError("No Reports for this Date");
                    }
//                    console.log("-------------------------------------")
//                    sendBookReportInput(_rip)
//                    // loadSingleDatePage();
//                    if(sevaProxy.sevaReport.bookReportModel.getBookingReportQryListSize()===0)
//                    {
//                        console.log("  if( _selectDateRadio.checked) if of mft.qml")
//                        if( sevaProxy.sevaReport.accReportModel.getAccountReportQryListSize()!==0)
//                        {
//                            sendError("No Reports for this Date");
//                        }
//                    }
//                    console.log("-------------------------------------")
                }
                if(( _rip.sMonth!="13")&&(_monthYearRadio.checked))
                {
                    console.log("I am hereeee")
                    _rip.bSevawise = _sevawise.checked
                    _rip.bDatewise = _datewise.checked
                    _rip.sSingleDate = r1.selecteddate
                    _rip.sStartDate =  "null"
                    _rip.sEndDate = "null"
                    // sendReportInput(_rip)
                    loadDateWisePage();
                    console.log("---------11----------------")
                   // loadDateWiseBookingPage();
                    console.log("---------12----------------")
                    sendReportDateRangeInputForWholeMonth(_rip)
                    if((sevaProxy.sevaReport.accountReportDateRangeModel.getAccountReportDateRangeQryListSize()===0))
                    {
                        console.log("  if ov sevaProxy.sevaReport.accountReportDateRangeModel.getAccountReportDateRangeQryListSize()===0)")
                        sendError("No Reports for this  Month & Year");
                    }
//                    sendBookingReportDateRangeInputForWholeMonth(_rip)
//                    if((sevaProxy.sevaReport.bookingReportDateRangeModel.getBookingReportDateRangeQryList()===0)&&(sevaProxy.sevaReport.accountReportDateRangeModel.getAccountReportDateRangeQryListSize()===0))
//                    {
//                        console.log("  if( _selectDateRadio.checked) if of mft.qml")
//                        //                        if(sevaProxy.sevaReport.accountReportDateRangeModel.getAccountReportDateRangeQryListSize()!==0)
//                        //                        {
//                        //                           // sendError("No Reports for this Month & Year");
//                        //                        }
//                        sendError("No Reports for this Month & Year");
//                    }
                }
                if(sevaProxy.sevaReport.accReportModel.getAccountReportQryListSize()===0)
                {
                    console.log("---------d----------------")
                    tot = sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
                }
                else{
                    console.log("---------e----------------")
                    tot = sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
                }
            }
        }
    }
    function clearData(){
        console.log(" Clear all the selection")
        // r4.clearData()
    }
    Component.onCompleted: {
        console.log(" Trying to get the list category")
        if( sevaProxy.getSevaTypeModel()===null)
        {
            errorOccur("seva type model not found");
        }
        else{
            _sevaType._dataModel = sevaProxy.getSevaTypeModel()
            _sevaType._dataModelRole = "sevaTypeName"

            _sevaName._dataModel = sevaProxy.getSevaModel(0);
            _sevaName._dataModelRole = "SevaName"
            _rip.iSevaType=  0;
            _rip.sSevaName=  "All";
            _rip.iSelectedType = 0
            _rip.sSingleDate =  Qt.formatDate(new Date(), "dd-MM-yyyy")
            sevaProxy.sevaReport.generateAccReport(_rip)
            var li =  _rip.sSingleDate.split("-");
            console.log("******** "+li[2]+"-"+li[1]+"-"+li[0])
            _rip.sSingleDate = li[2]+"-"+li[1]+"-"+li[0]
            console.log("  _rip.sSingleDate 2"+ _rip.sSingleDate)
            //sevaProxy.sevaReport.generateBookReport(_rip)
            if(sevaProxy.sevaReport.accReportModel.getAccountReportQryListSize()===0)
            {
                console.log("Component.completed:if of sevaProxy.sevaReport.accReportModel.getAccountReportQryListSize()===0")
                sendError("No Reports for today");
            }
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
    }
    ReportFilterItems{
        id:_rip

    }
    Connections{
        target:_sevaType
        function onIndexChanged(i){

            _rip.iSevaType=  i.model.sevaTypeId
            currentSevaType =  _rip.iSevaType
            _sevaName._dataModel = sevaProxy.getSevaModel(i.model.sevaTypeId);
            console.log("Seva type selected in report filter : "+_rip.iSevaType)
        }
    }

    Connections{
        target:_sevaName
        function onIndexChanged(i){

            _rip.sSevaName=  i.model.SevaName
            currentSevaName = _rip.sSevaName
            console.log("Seva name selected : "+_rip.sSevaName)
        }
    }
    Connections{
        target:_sevaType
        function onIndexChanged(i){

            _rip.iSevaType=  i.model.sevaTypeId
            console.log(_rip.iSevaType)
        }
    }

    Connections{
        target:_month
        function onMonthChanged(mon){

            _rip.sMonth = mon
            console.log("Selected month"+ _rip.sMonth)
        }
    }
    Connections{
        target:_year
        function onYearChanged(yr){

            _rip.sYear = yr
            console.log("Selected year"+ _rip.sYear)
        }
    }
    ButtonGroup { id: radioGroup }

}
