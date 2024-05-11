import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4
import "../../components"
import ReportElements 1.0

Rectangle{
    id: root
    width: styles.screenWidth
    height: styles.screenHeight

    property var styles : MyStyles{}

    property string fileName : "SevaReportPage.qml"
    property int footerHeight: root.height/15
    property alias tot : total.text
    property alias isRangeDateSelected : _reportitems.isRangeDateSelected
    property alias isAllselected : _reportitems.isAllselected
    property alias isSingleDateSelected : _reportitems.isSingleDateSelected

    signal startReportGeneration(var date);
    signal reportDisplay(var date);
    signal sendReportImput(var obj);
    signal sendReportMonthRangeImput(var obj);
    signal sendReportDateRangeInput(var obj)
    signal loadMenuPage()
    signal resetAccModel();
    signal sendSingleDateReportInput(var obj)
    signal sendReportDateRangeImputForWholeMonth(var obj);

    ReportFilterItems{
        id: _rip
    }

    Component{
        id : reportFilterComp
        ReportFilterItems{}
    }

    RowLayout{
        anchors.fill: parent
        Rectangle{
            id: _rightpart
            color: "#72FFFF"
            Layout.preferredWidth: parent.width/4
            Layout.preferredHeight: parent.height
            MyReportFilter{
                id: _reportitems
                width: parent.width
                height: parent.height
                border.color: "black"
                border.width: 2
                color: "#576F72"
            }
            Component.onCompleted: {
                console.log("The month and year initial",_reportitems.mnt," ",_reportitems.yr)
            }
        }
        Rectangle{
            id: leftpart
            Layout.preferredWidth: parent.width - _rightpart.width
            Layout.preferredHeight: parent.height

            Rectangle{
                id: _footer
                width: leftpart.width
                height: footerHeight
                anchors.bottom: leftpart.bottom
                Rectangle{
                    id: _grandTotalText
                    width: parent.width/2
                    height: parent.height
                    color: "#72FFFF"
                    Text {
                        text: "Grand Total :" //+ sevaProxy.sevaReport.accReportModel.grandTotal
                        anchors.centerIn: parent
                        font.pixelSize: styles.headerTextFont1
                        font.italic: true
                        font.bold : true
                    }
                }
                Rectangle{
                    width: parent.width/2
                    height: parent.height
                    anchors.left: _grandTotalText.right
                    color: "#72FFFF"
                    Text {
                        id: total
                        text: sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
                        anchors.centerIn: parent
                        font.pixelSize: 30
                        font.italic: true
                        font.bold : true
                        Component.onCompleted: {
                            console.log("In Component.onCompleted: of seva report page total text "+total.text)
                        }
                    }
                }
            }

            StackView{
                id : _reportStackView
                height: parent.height
                width: parent.width
                pushEnter: Transition { XAnimator { duration: 0 } }
                pushExit: Transition { XAnimator { duration: 0 } }
                popEnter: Transition { XAnimator { duration: 0 } }
                popExit: Transition { XAnimator { duration: 0 } }
            }

            Loader{
                id: _load
                height: parent.height
                width: parent.width
                visible: false
                property string isAllSel : root.isAllselected

                Connections{
                    target: _load.item
                    ignoreUnknownSignals: true
                    function onLoadSingleDatePage(dt){
                        console.log(fileName + " -- LoadSingleDatePage(obj.date) "+dt)
                        //_reportitems.setReportFilters(dt);
                    }
                    function onLoadDateWisePage(){
                        console.log("In onLoadDateWisePage")
                        _load.source = "SevaAccountReportOnDateRange.qml"
                    }
                    function onLoadMonthWisePage(){
                        console.log("In onLoadMonthWisePage")
                        _load.source = "SevaAccountReportMonthWise.qml"
                    }
                    function onLoadDateWiseForSlectedMonthPage(obj)
                    {
                        console.log("In  onLoadDateWiseForSlectedMonthPage")
                        _rip.bSevawise = _reportitems.seWise
                        _rip.bDatewise = _reportitems.dtWise
                        _rip.sSingleDate =  "null"
                        _rip.sStartDate =  "null"
                        _rip.sEndDate = "null"
                        _rip.iSelectedType = 1 /*_reportitems.iSelType*/
                        _rip.iSevaType = _reportitems.iSevType
                        _rip.sSevaName = _reportitems.sevNam
                        _rip.sMonth = obj;
                        _rip.sYear = _reportitems.yr;
                        sendReportDateRangeImput(_rip)
                        _load.source = "SevaAccountReportOnDateRange.qml"
                    }
                    function  onLoadMenuPage(){
                        console.log(fileName + "onLoadMenuPage")
                        loadMenuPage();
                    }
                }
                Component.onCompleted: {
                    console.log("In Component.onCompleted: loader srp")
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
        }
    }
    Timer{
        repeat: true
        interval: 5000
        running: true
        onTriggered: {
           console.log(fileName + " - Current StackView Depth =" + _reportStackView.depth)
        }
    }

    function loadAllSevaDetailsOnADay(accountElement){
        console.log( " ***** Print Details of Seva on Day = " + accountElement.date);
        var filterObj = reportFilterComp.createObject();
        filterObj.bSevawise = _reportitems.seWise
        filterObj.bDatewise = _reportitems.dtWise
        filterObj.iSelectedType = ReportEnums.SINGLE_DATE_REPORT;
        filterObj.reportType = ReportEnums.DETAIL_REPORT
        filterObj.iSevaType = accountElement.sevaType;
        filterObj.sSevaName = accountElement.sevaName;
        filterObj.sSingleDate = accountElement.date
        filterObj.sStartDate = "null"
        filterObj.sEndDate = "null"
        filterObj.sMonth = "null"
        filterObj.sYear = "null"
        filterObj.reportGenerationSource = accountElement.reportGenerationSource
        generateReport(filterObj);
    }

    function loadDaySummary(accountElement){
        console.log(" ***** Print Summary of Seva on Day = " + accountElement.date);
        accountElement.print();
        var filterObj = reportFilterComp.createObject();
        filterObj.bSevawise = _reportitems.seWise
        filterObj.bDatewise = _reportitems.dtWise
        filterObj.iSelectedType = ReportEnums.SINGLE_DATE_REPORT;
        filterObj.reportType = ReportEnums.SUMMARY_REPORT
        filterObj.iSevaType = accountElement.sevaType;
        filterObj.sSevaName = accountElement.sevaName;
        filterObj.sSingleDate = accountElement.date
        filterObj.sStartDate = "null"
        filterObj.sEndDate = "null"
        filterObj.sMonth = "null"
        filterObj.sYear = "null"
        filterObj.reportGenerationSource = accountElement.reportGenerationSource
        generateReport(filterObj);
    }
    function loadDaySummaryForMonth(accountElement){
        console.log(" ***** Print Summary of Seva on Day = " + accountElement.date);
        accountElement.print();
        var filterObj = reportFilterComp.createObject();
        filterObj.bSevawise = _reportitems.seWise
        filterObj.bDatewise = _reportitems.dtWise
        filterObj.iSelectedType = ReportEnums.MONTH_REPORT;
        filterObj.reportType = ReportEnums.SUMMARY_REPORT
        filterObj.iSevaType = accountElement.sevaType;
        filterObj.sSevaName = accountElement.sevaName;
        filterObj.sSingleDate = accountElement.date
        filterObj.sStartDate = "null"
        filterObj.sEndDate = "null"
        filterObj.sMonth = accountElement.month
        filterObj.sYear = accountElement.year
        filterObj.reportGenerationSource = accountElement.reportGenerationSource
        generateReport(filterObj);
    }

    function generateReport(filterObject){
        console.log(" Start Generating the report ")
        filterObject.print();
        if (filterObject.reportGenerationSource === ReportEnums.CLICK_ON_LEFT_SELECTION){
            _reportStackView.clear();
        }
        switch(filterObject.reportType)
        {
        case ReportEnums.DETAIL_REPORT :
            root.generateDetailsReport(filterObject)
            break;
        case ReportEnums.SUMMARY_REPORT:
            root.generateSummaryReport(filterObject);
            break;
        }
    }

    function generateDetailsReport(filterObject){
        var selectionType = filterObject.iSelectedType;
        console.log(" Start Generating the Details report =" + selectionType)
        switch(selectionType){
        case ReportEnums.SINGLE_DATE_REPORT: {
             sevaProxy.sevaReport.accountFullReportModel.generateFullAccountReportEachdate(filterObject)
             root.checkForNoRecords();
             var item = _reportStackView.push("qrc:/ui/Reports/Account/AllAccountDetails.qml");
             item.back.connect(root.adjustStackView);
             break;
        }
        case ReportEnums.DATE_RANGE_REPORT:
            sevaProxy.sevaReport.accountFullReportModel.generateFullAccountReportEachdate(filterObject)
            root.checkForNoRecords();
            var item = _reportStackView.push("qrc:/ui/Reports/Account/AllAccountDetails.qml");
            item.back.connect(root.adjustStackView);
            break;
        case ReportEnums.MONTH_REPORT:
            sevaProxy.sevaReport.accountFullReportModel.generateFullAccountReportEachdate(filterObject)
            root.checkForNoRecords();
            var item = _reportStackView.push("qrc:/ui/Reports/Account/AllAccountDetails.qml");
            item.back.connect(root.adjustStackView);
            break;
        }

        sevaProxy.sevaReport.accountFullReportModel.generateFullAccountReportEachdate(filterObject)
        _load.source = "AllAccountDetails.qml";
    }

    function generateSummaryReport(filterObject){
        var selectionType = filterObject.iSelectedType;
        console.log(" Start Generating the Summary report =" + selectionType)
        switch(selectionType){
        case ReportEnums.SINGLE_DATE_REPORT: {
             sevaProxy.sevaReport.generateAccReport(filterObject);
             root.checkForNoRecords();
             var item = _reportStackView.push("qrc:/ui/Reports/Account/SevaAccountReportForSingleDate.qml");
             item.loadSevaDetails.connect(root.loadAllSevaDetailsOnADay)
             item.back.connect(root.adjustStackView);
             break;
        }
        case ReportEnums.DATE_RANGE_REPORT: {
            sevaProxy.sevaReport.generateAccReportForEachDate(filterObject);
            var item1 = _reportStackView.push("qrc:/ui/Reports/Account/SevaAccountReportOnDateRange.qml");
            item1.generateReportForDate.connect(root.loadDaySummary)
            item1.back.connect(root.adjustStackView);
            break;
        }
        case ReportEnums.MONTH_REPORT:{
            // Report for all the months. month=All is 13 Selection all in ComboBox
            if (filterObject.sMonth === "13"){
                sevaProxy.sevaReport.generateAccReportForEachMonth(filterObject)
                var item3 = _reportStackView.push("qrc:/ui/Reports/Account/SevaAccountReportMonthWise.qml");
                item3.generateReportForOneMonth.connect(root.loadDaySummaryForMonth)
                item3.back.connect(root.adjustStackView);
            } else {
                sevaProxy.sevaReport.generateAccReportForEachDateForWholeMonth(filterObject)
                var item2 = _reportStackView.push("qrc:/ui/Reports/Account/SevaAccountReportOnDateRange.qml");
                item2.generateReportForDate.connect(root.loadDaySummary)
                item2.back.connect(root.adjustStackView);
            }
            break;
        }
        }
    }
    function checkForNoRecords(){
        if(sevaProxy.sevaReport.accReportModel.getAccountReportQryListSize()===0){
            total.text = sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
            _errorDialog.showError("No Reports for this Date");
        } else {
            total.text = sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
        }
    }
    function adjustStackView(){
        console.log(fileName + " StackView Depth ="+_reportStackView.depth)
        if (_reportStackView.depth <= 1){
            console.log(fileName + " Clearing StackView. Current Depth ="+_reportStackView.depth)
            _reportStackView.clear();
            loadMenuPage()
            return;
        }
        if (_reportStackView.depth > 1){
            console.log(fileName + " Removing topItem. Current StackView Depth ="+_reportStackView.depth)
            _reportStackView.pop()
        }
    }

    Connections{
        target: _reportitems
        function onReportFilterChanged(filterObject){
            root.generateReport(filterObject);
        }
    }

    Keys.onEscapePressed: {
        console.log(fileName + " --- Esc pressed in SelectSevaReport page")
        root.adjustStackView();
    }
    Component.onCompleted: {
        console.log(fileName + " object is created")
        forceActiveFocus();
    }
    Component.onDestruction: {
        console.log(fileName + "   Closing the report")
        resetAccModel();
    }
}



