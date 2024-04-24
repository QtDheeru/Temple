import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4
import "../../components"
import ReportElements 1.0

Rectangle{
    id:root
    property var styles : MyStyles{}
    width: styles.screenWidth
    height: styles.screenHeight
    property string fileName : "SevaReportPage.qml"

    signal startReportGeneration(var date);
    signal reportDisplay(var date);
    signal sendReportImput(var obj);

    signal sendReportMonthRangeImput(var obj);
    signal sendReportDateRangeInput(var obj)
    signal loadMenuPage()
    signal resetAccModel();
    signal sendSingleDateReportInput(var obj)
    signal sendReportDateRangeImputForWholeMonth(var obj);
    property int footerHeight: root.height/15
    property alias tot :total.text
    property alias  isRangeDateSelected :_reportitems.isRangeDateSelected
    property alias isAllselected : _reportitems.isAllselected
    property alias  isSingleDateSelected :_reportitems.isSingleDateSelected

    function loadAllSevaDetailsOnADay(accountElement){
        console.log( " ***** Print Details of Seva on Day = "+accountElement.date);
        var filterObj = reportFilterComp.createObject();
        filterObj.bSevawise = _reportitems.seWise
        filterObj.bDatewise = _reportitems.dtWise
        filterObj.iSelectedType = ReportFilterEnum.SINGLE_DATE_REPORT;
        filterObj.reportType = ReportFilterEnum.DETAIL_REPORT
        filterObj.iSevaType = accountElement.sevaType;
        filterObj.sSevaName = accountElement.sevaName;
        filterObj.sSingleDate = accountElement.date
        filterObj.sStartDate =  "null"
        filterObj.sEndDate = "null"
        filterObj.sMonth = "null"
        filterObj.sYear  = "null"
        generateReport(filterObj);
    }

    function loadDaySummary(accountElement){
        console.log( " ***** Print Summary of Seva on Day = "+accountElement.date);
        accountElement.print();
        var filterObj = reportFilterComp.createObject();
        filterObj.bSevawise = _reportitems.seWise
        filterObj.bDatewise = _reportitems.dtWise
        filterObj.iSelectedType = ReportFilterEnum.SINGLE_DATE_REPORT;
        filterObj.reportType = ReportFilterEnum.SUMMARY_REPORT
        filterObj.iSevaType = accountElement.sevaType;
        filterObj.sSevaName = accountElement.sevaName;
        filterObj.sSingleDate = accountElement.date
        filterObj.sStartDate =  "null"
        filterObj.sEndDate = "null"
        filterObj.sMonth = "null"
        filterObj.sYear  = "null"
        generateReport(filterObj);
    }
    function loadDaySummaryForMonth(accountElement){
        console.log( " ***** Print Summary of Seva on Day = "+accountElement.date);
        accountElement.print();
        var filterObj = reportFilterComp.createObject();
        filterObj.bSevawise = _reportitems.seWise
        filterObj.bDatewise = _reportitems.dtWise
        filterObj.iSelectedType = ReportFilterEnum.MONTH_REPORT;
        filterObj.reportType = ReportFilterEnum.SUMMARY_REPORT
        filterObj.iSevaType = accountElement.sevaType;
        filterObj.sSevaName = accountElement.sevaName;
        filterObj.sSingleDate = accountElement.date
        filterObj.sStartDate =  "null"
        filterObj.sEndDate = "null"
        filterObj.sMonth = accountElement.month
        filterObj.sYear  = accountElement.year
        generateReport(filterObj);
    }

    function generateReport(filterObject){
        console.log(" Start Generating the report ")
        filterObject.print();
        if (filterObject.reportGenerationSource === 0){
            _reportStackView.clear();
        }
        switch(filterObject.reportType)
        {
        case ReportFilterEnum.DETAIL_REPORT :
            root.generateDetailsReport(filterObject)
            break;
        case ReportFilterEnum.SUMMARY_REPORT:
            root.generateSummaryReport(filterObject);
            break;
        }
    }

    function generateDetailsReport(filterObject){
        var selectionType = filterObject.iSelectedType;
        console.log(" Start Generating the Details report ="+selectionType)
        switch(selectionType){
        case ReportFilterEnum.SINGLE_DATE_REPORT: {
             sevaProxy.sevaReport.accountFullReportModel.generateFullAccountReportEachdate(filterObject)
             root.checkForNoRecords();
             var item = _reportStackView.push("qrc:/ui/Reports/Account/AllAccountDetails.qml");
             item.back.connect(root.adjustStackView);
             break;
        }
        case ReportFilterEnum.DATE_RANGE_REPORT:
            sevaProxy.sevaReport.accountFullReportModel.generateFullAccountReportEachdate(filterObject)
            root.checkForNoRecords();
            var item = _reportStackView.push("qrc:/ui/Reports/Account/AllAccountDetails.qml");
            item.back.connect(root.adjustStackView);
            break;
        case ReportFilterEnum.MONTH_REPORT:
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
        console.log(" Start Generating the Summary report ="+selectionType)
        switch(selectionType){
        case ReportFilterEnum.SINGLE_DATE_REPORT: {
             sevaProxy.sevaReport.generateAccReport(filterObject);
             root.checkForNoRecords();
             var item = _reportStackView.push("qrc:/ui/Reports/Account/SevaAccountReportForSingleDate.qml");
             item.loadSevaDetails.connect(root.loadAllSevaDetailsOnADay)
             item.back.connect(root.adjustStackView);
             break;
        }
        case ReportFilterEnum.DATE_RANGE_REPORT: {
            sevaProxy.sevaReport.generateAccReportForEachDate(filterObject);
            //root.checkForNoRecords();
            var item1 = _reportStackView.push("qrc:/ui/Reports/Account/SevaAccountReportOnDateRange.qml");
            item1.generateReportForDate.connect(root.loadDaySummary)
            item1.back.connect(root.adjustStackView);
            break;
        }
        case ReportFilterEnum.MONTH_REPORT:{
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

    Connections{
        target: _reportitems

        function onReportFilterChanged(filterObject){
            root.generateReport(filterObject);
        }

        // function onSendReportInput(obj){
        //     _load.source = "";
        //     console.log(" Start Generating the report "+obj.sSingleDate)
        //     // Following will send signal to backend to generate the report
        //     sevaProxy.sevaReport.generateAccReport(obj)
        //     console.log(" Report Generation Initiated .."+obj.sSingleDate)
        //     if(sevaProxy.sevaReport.accReportModel.getAccountReportQryListSize()===0){
        //         total.text = sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
        //         sendError("No Reports for this Date");
        //     } else {
        //         total.text = sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
        //     }
        //     //_load.source = "SevaAccountReportForSingleDate.qml"
        //     var item = _reportStackView.push("qrc:/ui/SevaAccountReportForSingleDate.qml");
        //     item.loadSevaDetails.connect(root.loadAllSevaDetailsOnADay)
        // }

        // function onDateRangeSelected(){
        //     console.log("In onDateRangeSelected")
        //     _load.source = "SevaAccountReportOnDateRange.qml"
        // }

        // function onMonthWiseSelected(){
        //     console.log("In onDateRangeSelected")
        //     _load.source = "SevaAccountReportMonthWise.qml"

        // }
        // function onLoadDateWisePage()
        // {
        //     console.log("In onLoadDateWisePage")
        //     _load.source = "SevaAccountReportOnDateRange.qml"
        // }

        // function onSendReportDateRangeInput(obj){
        //     console.log("In onSendReportDateRangeInput")
        //     //sevaProxy.sevaReport.generateAccReportForEachDate(obj)
        // }
        // function onSendReportMonthRangeInput(obj)
        // {
        //     console.log("In onSendReportMonthRangeInput")
        //     sendReportMonthRangeImput(obj);
        //     //  isAllselected = true;
        // }
        // function onSendReportDateRangeInputForWholeMonth(obj)
        // {
        //     console.log("In onSendReportDateRangeInputForWholeMonth")
        //     sendReportDateRangeImputForWholeMonth(obj);
        //     //isAllselected = false;
        // }
        // function   onSendError(err){
        //     console.log("In onSendError")
        //     _errorDialog.showError(err);
        // }
        // function onSendAllDetailsReportDateRangeInput(obj){
        //     console.log("Suman onSendAllDetailsReportDateRangeInput")
        //     _load.source = ""
        //     sevaProxy.sevaReport.accountFullReportModel.generateFullAccountReportForDateRange(obj)
        //     _load.source = "AllAccountDetails.qml";
        // }
        // function onSendAllDetailsReportMonthRangeInput(obj){
        //     console.log("Suman onSendAllDetailsReportMonthRangeInput")
        //     _load.source = ""
        //     sevaProxy.sevaReport.accountFullReportModel.generateFullAccountReportForMonth(obj)
        //     _load.source = "AllAccountDetails.qml";
        // }
        // function onSendAlldetailsReportDateRangeInputForWholeMonth(obj){
        //     console.log("Suman onSendAlldetailsReportDateRangeInputForWholeMonth")
        //     _load.source = ""
        //     sevaProxy.sevaReport.accountFullReportModel.generateFullAccountReportForMonth(obj)
        //     _load.source = "AllAccountDetails.qml";
        // }
        // function onSendAllReportInputEachDate(obj){
        //     console.log("Suman onSendAllReportInputEachDate")
        //     _load.source = ""
        //     sevaProxy.sevaReport.accountFullReportModel.generateFullAccountReportEachdate(obj)
        //     _load.source = "AllAccountDetails.qml";
        // }
    }
    ReportFilterItems{
        id:_rip
    }

    Component{
        id : reportFilterComp
        ReportFilterItems{}
    }

    RowLayout{
        anchors.fill: parent
        Rectangle{
            id:_rightpart
            color: "#72FFFF"
            Layout.preferredWidth: parent.width/4
            Layout.preferredHeight: parent.height
            MyReportFilter{
                id:_reportitems
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
            id:leftpart
            Layout.preferredWidth:  parent.width - _rightpart.width
            Layout.preferredHeight:  parent.height

            Rectangle{
                id:_footer
                width: leftpart.width
                height: footerHeight
                anchors.bottom: leftpart.bottom
                Rectangle{
                    id:_grandTotalText
                    width: parent.width/2
                    height: parent.height
                    color: "#72FFFF"
                    Text {
                        text:"Grand Total :" //+ sevaProxy.sevaReport.accReportModel.grandTotal
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
                        id:total
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
                height:parent.height
                width:parent.width
                pushEnter: Transition { XAnimator { duration: 0 } }
                pushExit: Transition { XAnimator { duration: 0 } }
                popEnter: Transition { XAnimator { duration: 0 } }
                popExit: Transition { XAnimator { duration: 0 } }
            }

            Loader{
                id:_load
                height:parent.height
                width:parent.width
                property  string isAllSel : root.isAllselected
                visible: false

                Connections{
                    target: _load.item
                    ignoreUnknownSignals: true
                    function  onLoadSingleDatePage(dt){
                        console.log(fileName + " -- LoadSingleDatePage(obj.date) "+dt)
                        //_reportitems.setReportFilters(dt);
                    }

                    function  onLoadDateWisePage(){
                        console.log("In onLoadDateWisePage")
                        _load.source = "SevaAccountReportOnDateRange.qml"
                    }
                    function  onLoadMonthWisePage(){
                        console.log("In onLoadMonthWisePage")
                        _load.source = "SevaAccountReportMonthWise.qml"
                    }
                    function  onLoadDateWiseForSlectedMonthPage(obj)
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
                        console.log("In onLoadMenuPage")
                        loadMenuPage();
                    }
                }
                Component.onCompleted: {
                    console.log("In  Component.onCompleted: loader srp")
                    // total.text = tot;
                }
            }
            DisplayDialog {
                id :_errorDialog
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

    function adjustStackView(){
        if (_reportStackView.depth <= 1){
            _reportStackView.clear();
            loadMenuPage()
            return;
        }
        if (_reportStackView.depth > 1){
            _reportStackView.pop()
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



