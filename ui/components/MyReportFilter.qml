import QtQuick 2.0

import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import ReportElements 1.0
Rectangle {
    id :root
    property var styles : MyStyles{}
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

    property string defaultSevaName : "All";
    property int defaultSevaType : 0
    property string fileName : "MyReportFilter.qml"

    property int dETAIL_REPORT  : ReportEnums.DETAIL_REPORT
    property int sUMMARY_REPORT : ReportEnums.SUMMARY_REPORT

    property alias isAllselected:_month._data
    property var currentMonth;
    property string sevatime : "08:00 AM"

    signal reportFilterChanged(var filterObject)
    signal singleDateReportFilterChanged(var filterObject)
    signal rangeDateReportFilterChanged(var filterObject)
    signal monthReportFilterChanged(var filterObject)

    signal dateRangeSelected();
    signal monthWiseSelected();
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

    signal sendAllDetailsReportDateRangeInput(var obj)      //suman
    signal sendAllDetailsReportMonthRangeInput(var obj)     //Suman
    signal sendAllReportInputEachDate(var obj)             //Suman
    signal sendAlldetailsReportDateRangeInputForWholeMonth(var obj)   //suman
    signal sendError(string err);

    ColumnLayout {
        //        anchors.fill: parent
        width: parent.width
        id : _c1
        spacing: 5
        //Layout.alignment: Qt.AlignTop
        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight:root.subComponentHeight*1.5
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
                    Layout.preferredHeight: root.subComponentHeight;
                    Layout.preferredWidth: root.width/2
                    font.pixelSize:  root.subComponentPixelSize
                    text: "Seva wise"
                    checked: true
                }
                RadioButton {
                    id: _datewise
                    Layout.preferredHeight: root.subComponentHeight;
                    Layout.preferredWidth: root.width/2
                    font.pixelSize:  root.subComponentPixelSize
                    text: "Date wise"
                    visible: false
                    checked: false
                }
            }
        }
        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight: (root.subComponentHeight+_comboboxLayout.spacing + _sevatypeCheck.height)*2.3
            color: "#00A2ED"
            border.width: 1
            border.color: "black"
            Layout.alignment: Qt.AlignTop
            ColumnLayout{
                id: _comboboxLayout
                width: parent.width
                height:  parent.height/1.1
                spacing: root.subComponentHeight/4
                CheckBox{
                    id:_sevatypeCheck
                    checked: true
                    text: qsTr("All Seva Types")
                    font.pixelSize:  root.subComponentPixelSize
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin:   parent.width*0.33
                    onCheckedChanged: {
                        if(checked==false)
                        {
                            _rip.iSevaType=  currentSevaType;
                            console.log("SevaType unchecked")
                            _sevaType.enabled = true
                            if(_sevanameCheck.checked == false){
                                _sevaName.enabled = true
                            }else{
                                _sevaName.enabled = false
                            }
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

                MyComboEntry{
                    id:_sevaType;
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight:root.subComponentHeight;
                    myWidth: root.width/1.1
                    fontPixelSize: root.subComponentPixelSize
                    enabled: false
                    _labelText :qsTr("Seva Type")
                }
                Rectangle{
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: 2
                    color: "black"
                }

                CheckBox{
                    id: _sevanameCheck
                    enabled: false
                    checked: true
                    font.pixelSize: root.subComponentPixelSize
                    text: qsTr("All Seva Names")
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin:   parent.width*0.33
                    onCheckedChanged: {
                        if(checked==false)
                        {
                            _rip.sSevaName=  currentSevaName
                            _sevaName.enabled = true
                        }else{
                            _rip.sSevaName=  defaultSevaName;
                            _sevaName.enabled = false
                        }
                    }
                }

                MyComboEntry{
                    id: _sevaName;
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight:root.subComponentHeight;
                    myWidth: root.width/1.1
                    fontPixelSize: root.subComponentPixelSize
                    enabled: false
                    _labelText :qsTr("Seva Name")
                }
            }
        }

        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight: (root.subComponentHeight + _singleDateLayout.spacing ) *2.5
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
                    Layout.preferredHeight: root.subComponentHeight;
                    Layout.preferredWidth: parent.width
                    font.pixelSize: root.subComponentPixelSize
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
                    id: r1;
                    anchors.right: parent.right
                    enabled: true
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight: root.subComponentHeight;
                    myWidth: root.width/1.1
                    fontPixelSize: root.subComponentPixelSize
                    _labelText: qsTr(" Select Date")
                }
            }
        }

        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight: (root.subComponentHeight +_rangeDateLayout.spacing)*3.5
            color: "#00A2ED"
            border.width: 1
            border.color: "black"
            Layout.alignment: Qt.AlignTop
            ColumnLayout{
                width: parent.width
                height: parent.height/1.1
                id:_rangeDateLayout
                RadioButton{
                    ButtonGroup.group: radioGroup
                    id: _rangeSelectedRadio
                    Layout.preferredHeight: root.subComponentHeight;
                    Layout.preferredWidth: parent.width
                    font.pixelSize: root.subComponentPixelSize
                    text: "Select Date Range"
                    checked: false
                    onCheckedChanged: {
                        if(checked == false){
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
                    myHeight: root.subComponentHeight;
                    myWidth: root.width/1.1
                    fontPixelSize: root.subComponentPixelSize
                    _labelText: qsTr(" Start Date")
                }
                MyDateEntry{
                    id:r3;
                    enabled: false
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    myHeight: root.subComponentHeight;
                    myWidth: root.width/1.1
                    fontPixelSize: root.subComponentPixelSize
                    _labelText: qsTr("End Date")
                }
            }
        }

        Rectangle{
            Layout.preferredWidth: parent.width -5
            Layout.preferredHeight: (root.subComponentHeight +_rangeDateLayout.spacing)*3.5
            color: "#00A2ED"
            border.width: 1
            border.color: "black"
            Layout.alignment: Qt.AlignTop
            ColumnLayout{
                id: _monthYearLayout
                width: parent.width
                height:  parent.height/1.1
                RadioButton{
                    ButtonGroup.group: radioGroup
                    id: _monthYearRadio
                    Layout.preferredHeight: root.subComponentHeight;
                    Layout.preferredWidth: parent.width
                    font.pixelSize: root.subComponentPixelSize
                    text: "Select Month Year"
                    checked: false
                    onCheckedChanged: {
                        if(checked == false){
                            _month.enabled = false
                            _year.enabled = false
                        }
                        else{
                            _month.enabled = true
                            _year.enabled = true
                            _rip.iSelectedType = 2
                        }
                    }
                }
                MyComboEntry{
                    id: _month;
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight: root.subComponentHeight;
                    myWidth: root.width/1.1
                    fontPixelSize: root.subComponentPixelSize
                    enabled: false
                    _labelText : qsTr("Month")
                    _dataModel: ["January","February","March","April","May","June","July","August","September","October","November","December","All"]
                }
                MyComboEntry{
                    id: _year;
                    anchors.right: parent.right
                    anchors.rightMargin: 7
                    Layout.preferredWidth: parent.width
                    myHeight: root.subComponentHeight;
                    myWidth: root.width/1.1
                    fontPixelSize: root.subComponentPixelSize
                    enabled: false
                    _labelText : qsTr("Year")
                    _dataModel: ["2015","2016","2017","2018","2019","2020","2021","2022","2023","2024","2025","2026","2027","2028","2029","2030"]
                }
            }
        }
        Button{
            id: _button
            text: "Summary"
            font.pixelSize: root.subComponentPixelSize
            font.bold: true
            Layout.preferredWidth: parent.width-20
            Layout.preferredHeight: root.subComponentHeight;
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
            onClicked: {
                root.collectCurrentFilterOptions(sUMMARY_REPORT);
                if((_rip.sMonth === "13") && (_monthYearRadio.checked))
                {
                    console.log("rip.sMonth === All")
                    sendReportMonthRangeInput(_rip)
                    monthWiseSelected();
                    if(sevaProxy.sevaReport.accountReportMonthRangeModel.getAccountReportMonthWiseQryListSize() === 0)
                    {
                        console.log("if of sevaProxy.sevaReport.accountReportMonthRangeModel.getAccountReportMonthWiseQryListSize()===0 ")
                        sendError("No Reports for this Year");
                    }
                }
            }
        }
        Button{
            id: _allDetails
            text: "Details"
            font.pixelSize: root.subComponentPixelSize
            font.bold: true
            Layout.preferredWidth: parent.width-20
            Layout.preferredHeight: root.subComponentHeight;
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
            onClicked:{
                root.collectCurrentFilterOptions(dETAIL_REPORT);
                if((_rip.sMonth === "13") && (_monthYearRadio.checked))
                {
                    console.log("rip.sMonth===All")
                    sendAllDetailsReportMonthRangeInput(_rip)
                    if(sevaProxy.sevaReport.accountFullReportModel.getaccountFullreportElementListSize() === 0)
                    {
                        console.log("if of sevaProxy.sevaReport.accountReportMonthRangeModel.getAccountReportMonthWiseQryListSize()===0 ")
                        sendError("No Reports for this Year");
                    }
                }
                if(( _rip.sMonth != "13") && (_monthYearRadio.checked))
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
                    sendAlldetailsReportDateRangeInputForWholeMonth(_rip)
                    if(sevaProxy.sevaReport.accountFullReportModel.getaccountFullreportElementListSize() === 0)
                    {
                        console.log("  if ov sevaProxy.sevaReport.accountReportDateRangeModel.getAccountReportDateRangeQryListSize()===0)")
                        sendError("No Reports for this  Month & Year");
                    }

                }
                if(sevaProxy.sevaReport.accReportModel.getAccountReportQryListSize() === 0)
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

    DisplayDialog {
        id : _errorDialog
        visible: false

        function showError(message){
            _errorDialog.visible = true;
            _errorDialog.text2Display = message
            _errorDialog.open();
        }
        onNoAction: {
            _errorDialog.close()
        }
    }
    ReportFilterItems{
        id: _rip
    }

    Connections{
        target: _sevaType
        function onIndexChanged(i){
            _rip.iSevaType = i.model.sevaTypeId
            currentSevaType = _rip.iSevaType
            checkSevaNameAndTypeStatus();
            _sevaName._dataModel = sevaProxy.getSevaModel(_rip.iSevaType);
            console.log("Seva type selected in report filter : " + _rip.iSevaType)
        }
    }

    Connections{
        target: _sevaName
        function onIndexChanged(i){
            _rip.sSevaName = i.model.SevaName
            currentSevaName = _rip.sSevaName
            checkSevaNameAndTypeStatus();
            console.log("Seva name selected : " + _rip.sSevaName)
        }
    }

    Connections{
        target: _sevaType
        function onIndexChanged(i){
            _rip.iSevaType = i.model.sevaTypeId
            console.log(_rip.iSevaType)
        }
    }

    Connections{
        target: _month
        function onSendCurrentMonth(mIndex){
            _month.currentIndex = mIndex
        }
        function onMonthChanged(mon){
            _rip.sMonth = mon
            console.log("Selected month = " + _rip.sMonth)
        }
    }
    Connections{
        target: _year
        function onSendCurrentYear(yIndex){
            _year.currentIndex = yIndex
        }
        function onYearChanged(yr){
            _rip.sYear = yr
            console.log("accont report Selected year" + _rip.sYear)
        }
    }
    ButtonGroup { id: radioGroup }

    function fillDefaultFilterValue(){
        _rip.bSevawise = root.seWise
        _rip.bDatewise = root.dtWise
        _rip.sSingleDate = Qt.formatDate(new Date(), "dd-MM-yyyy");
        _rip.sStartDate = "null"
        _rip.sEndDate = "null"
        _rip.iSelectedType = 0
        _rip.iSevaType = root.defaultSevaType
        _rip.sSevaName = root.defaultSevaName
    }

    function setReportFilters(date1){
        _rip.bSevawise = root.seWise
        _rip.bDatewise = root.dtWise
        _rip.sSingleDate = date1;
        _rip.sStartDate =  "null"
        _rip.sEndDate = "null"
        _rip.iSelectedType = 0
        _rip.iSevaType = root.defaultSevaType
        _rip.sSevaName = root.defaultSevaName
        sendReportInput(_rip);
    }

    function collectCurrentFilterOptions(typeOfReport) {
        _rip.reportType = typeOfReport;
        _rip.reportGenerationSource = ReportEnums.CLICK_ON_LEFT_SELECTION;
        if (_sevatypeCheck.checked == true){
            // Report for all seva types & all seva names.
            _rip.iSevaType = root.defaultSevaType
            _rip.sSevaName = root.defaultSevaName
        } else if (_sevanameCheck.checked == true) {
             // Report for all seva for selected seva type
            _rip.sevaType = _sevaType._enteredText;
            _rip.iSevaType = _sevaName.currentIndex;
            _rip.sSevaName = root.defaultSevaName
        } else {
            _rip.iSevaType = _sevaName.currentIndex;
            _rip.sevaType = _sevaType._enteredText;
            _rip.sSevaName = _sevaName._enteredText;
            _rip.sevaNameIndex = _sevaName.currentIndex
        }

        _rip.bSevawise = _sevawise.checked
        _rip.bDatewise = _datewise.checked
        if (_selectDateRadio.checked){
            console.log(" Single Date Selection ")
            _rip.iSelectedType = ReportEnums.SINGLE_DATE_REPORT;
            _rip.sSingleDate = r1.selecteddate
            _rip.sStartDate = "null"
            _rip.sEndDate = "null"
            _rip.sMonth = "null"
            _rip.sYear = "null"
        }

        if (_rangeSelectedRadio.checked){
            console.log(" Date Range Selection ")
            _rip.iSelectedType = ReportEnums.DATE_RANGE_REPORT;
            _rip.sSingleDate = "null"
            _rip.sStartDate = r2.selecteddate
            _rip.sEndDate = r3.selecteddate
            _rip.sMonth = "null"
            _rip.sYear = "null"
        }

        if (_monthYearRadio.checked){
            console.log(" Month Selection ")
            _rip.iSelectedType = ReportEnums.MONTH_REPORT;
            _rip.sSingleDate = "null";
            _rip.sStartDate = "null"
            _rip.sEndDate = "null"
            _rip.sMonth = _month.currentIndex+1
            _rip.sYear = _year._enteredText
        }
        reportFilterChanged(_rip);
    }

    function checkSevaNameAndTypeStatus() {
        if (_sevatypeCheck.checked == true){
             _rip.iSevaType = 0;
        }
        if (_sevanameCheck.checked == true ){
            _rip.sSevaName = defaultSevaName;
        }
    }
    function clearData(){
        console.log(" Clear all the selection")
        // r4.clearData()
    }

    Component.onCompleted: {
        console.log(" Trying to get the list category")
        if( sevaProxy.getSevaTypeModel() === null) {
            errorOccur("seva type model not found");
        } else {
            _sevaType._dataModel = sevaProxy.getSevaTypeModel()
            _sevaType._dataModelRole = "sevaTypeName"

            _sevaName._dataModel = sevaProxy.getSevaModel(0);
            _sevaName._dataModelRole = "SevaName"
            collectCurrentFilterOptions(ReportEnums.SUMMARY_REPORT);
        }
    }
}
