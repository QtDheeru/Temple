import QtQuick 2.15
import ReportElements 1.0
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.15
import "../../components"

Rectangle{
    id: root
    width: styles.screenWidth
    height: styles.screenHeight

    property var styles : MyStyles{}
    property string fileName : "SevaReportPage.qml"
    property int footerHeight: root.height/15

    signal loadMenuPage()

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
            id: leftPart
            color: "#72FFFF"
            Layout.preferredWidth: parent.width/4
            Layout.preferredHeight: parent.height
            MyReportFilter{
                id: _myreportFilter
                width: parent.width
                height: parent.height
                border.color: "black"
                border.width: 2
                color: "#576F72"
                allDetailButtonVisibility : false
            }
            Component.onCompleted: {
                console.log(fileName + "The month and year initial",_myreportFilter.mnt," ",_myreportFilter.yr)
            }
        }
        Rectangle{
            id: rightPart
            Layout.preferredWidth: parent.width - _myreportFilter.width
            Layout.preferredHeight: parent.height

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

                Connections{
                    target: _load.item
                    ignoreUnknownSignals: true
                    function onLoadSingleDatePage(dt){
                        console.log(fileName + " -- LoadSingleDatePage(obj.date) "+dt)
                        //_myreportFilter.setReportFilters(dt);
                    }
                    function onLoadDateWisePage(){
                        console.log(fileName + "In onLoadDateWisePage")
                        _load.source = "ProfitAndLossForSingleDate.qml"
                    }
                    function onLoadMonthWisePage(){
                        console.log(fileName + "In onLoadMonthWisePage")
                        _load.source = "ProfitAndLossForSingleDate.qml"
                    }
                    function onLoadDateWiseForSlectedMonthPage(obj)
                    {
                        console.log(fileName + "In  onLoadDateWiseForSlectedMonthPage")
                        _rip.bSevawise = _myreportFilter.seWise
                        _rip.bDatewise = _myreportFilter.dtWise
                        _rip.sSingleDate =  "null"
                        _rip.sStartDate =  "null"
                        _rip.sEndDate = "null"
                        _rip.iSelectedType = 1 /*_myreportFilter.iSelType*/
                        _rip.iSevaType = _myreportFilter.iSevType
                        _rip.sSevaName = _myreportFilter.sevNam
                        _rip.sMonth = obj;
                        _rip.sYear = _myreportFilter.yr;
                        sendReportDateRangeImput(_rip)
                        _load.source = "ProfitAndLossForSingleDate.qml"
                    }
                    function  onLoadMenuPage(){
                        console.log(fileName + "onLoadMenuPage")
                        loadMenuPage();
                    }
                }
                Component.onCompleted: {
                    console.log(fileName + "In Component.onCompleted: loader srp")
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

    function loadAllSevaDetailsOnADay(accountElement){
        console.log(fileName +  " ***** Print Details of Seva on Day = " + accountElement.date);
        var filterObj = reportFilterComp.createObject();
        filterObj.bSevawise = _myreportFilter.seWise
        filterObj.bDatewise = _myreportFilter.dtWise
        filterObj.iSelectedType = ReportEnums.SINGLE_DATE_REPORT;
        filterObj.reportType = ReportEnums.DETAIL_REPORT
        filterObj.sevaType = accountElement.sevaTypeName;
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
        console.log(fileName + " ***** Print Summary of Seva on Day = " + accountElement.date);
        accountElement.print();
        var filterObj = reportFilterComp.createObject();
        filterObj.bSevawise = _myreportFilter.seWise
        filterObj.bDatewise = _myreportFilter.dtWise
        filterObj.iSelectedType = ReportEnums.SINGLE_DATE_REPORT;
        filterObj.reportType = ReportEnums.SUMMARY_REPORT
        filterObj.iSevaType = accountElement.sevaType;
        filterObj.sevaType = accountElement.sevaTypeName;
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
        console.log(fileName + " ***** Print Summary of Seva on Day = " + accountElement.date);
        accountElement.print();
        var filterObj = reportFilterComp.createObject();
        filterObj.bSevawise = _myreportFilter.seWise
        filterObj.bDatewise = _myreportFilter.dtWise
        filterObj.iSelectedType = ReportEnums.MONTH_REPORT;
        filterObj.reportType = ReportEnums.SUMMARY_REPORT
        filterObj.iSevaType = accountElement.sevaType;
        filterObj.sevaType = accountElement.sevaTypeName;
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
        console.log(fileName + " Start Generating the report ")

        filterObject.print();
        sevaProxy.sevaReport.profitAndLossDataModel.resetModel()
        if (filterObject.reportGenerationSource === ReportEnums.CLICK_ON_LEFT_SELECTION){
            _reportStackView.clear();
        }
        switch(filterObject.reportType)
        {
        case ReportEnums.DETAIL_REPORT :
            break;
            root.generateDetailsReport(filterObject)
            break;
        case ReportEnums.SUMMARY_REPORT:
            root.generateSummaryReport(filterObject);
            break;
        }
    }

    function generateDetailsReport(filterObject){
        var selectionType = filterObject.iSelectedType;
        console.log(fileName + " Start Generating the Details report =" + selectionType)
        switch(selectionType){
        case ReportEnums.SINGLE_DATE_REPORT: {
             sevaProxy.sevaReport.profitAndLossDataModel.generateProfitAndLossForADay(filterObject)
             var item = _reportStackView.push("qrc:/ui/Reports/ProfitAndLoss/ProfitAndLossForSingleDate.qml");
             item.back.connect(root.adjustStackView);
             break;
        }
        case ReportEnums.DATE_RANGE_REPORT:
            sevaProxy.sevaReport.profitAndLossDataModel.generateProfitAndLossForADay(filterObject)
            var item = _reportStackView.push("qrc:/ui/Reports/Account/AllAccountDetails.qml");
            item.back.connect(root.adjustStackView);
            break;
        case ReportEnums.MONTH_REPORT:
            sevaProxy.sevaReport.profitAndLossDataModel.generateProfitAndLossForADay(filterObject)
            var item = _reportStackView.push("qrc:/ui/Reports/Account/AllAccountDetails.qml");
            item.back.connect(root.adjustStackView);
            break;
        }

        // sevaProxy.sevaReport.accountFullReportModel.generateFullAccountReportEachdate(filterObject)
        // _load.source = "AllAccountDetails.qml";
    }

    function generateSummaryReport(filterObject){
        var selectionType = filterObject.iSelectedType;
        console.log(fileName + " Start Generating the Summary report =" + selectionType)
        switch(selectionType){
        case ReportEnums.SINGLE_DATE_REPORT: {
             sevaProxy.sevaReport.profitAndLossDataModel.generateProfitAndLossForADay(filterObject);
             var item = _reportStackView.push("qrc:/ui/Reports/ProfitAndLoss/ProfitAndLossForSingleDate.qml");
             // item.loadSevaDetails.connect(root.loadAllSevaDetailsOnADay)
             item.back.connect(root.adjustStackView);
             break;
        }
        case ReportEnums.DATE_RANGE_REPORT: {
            sevaProxy.sevaReport.profitAndLossDataModel.generateProfitAndLossForADay(filterObject)
            var item1 = _reportStackView.push("qrc:/ui/Reports/ProfitAndLoss/ProfitAndLossForSingleDate.qml");
            //item1.generateReportForDate.connect(root.loadDaySummary)
            item1.back.connect(root.adjustStackView);
            break;
        }
        case ReportEnums.MONTH_REPORT:{
            // Report for all the months. month=All is 13 Selection all in ComboBox
            if (filterObject.sMonth === "13"){
                sevaProxy.sevaReport.profitAndLossDataModel.generateProfitAndLossForADay(filterObject)
                var item3 = _reportStackView.push("qrc:/ui/Reports/ProfitAndLoss/ProfitAndLossForSingleDate.qml");
                item3.generateReportForOneMonth.connect(root.loadDaySummaryForMonth)
                item3.back.connect(root.adjustStackView);
            } else {
                sevaProxy.sevaReport.profitAndLossDataModel.generateProfitAndLossForADay(filterObject)
                var item2 = _reportStackView.push("qrc:/ui/Reports/ProfitAndLoss/ProfitAndLossForSingleDate.qml");
                // item2.generateReportForDate.connect(root.loadDaySummary)
                item2.back.connect(root.adjustStackView);
            }
            break;
        }
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
        target: _myreportFilter
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
        sevaProxy.sevaReport.profitAndLossDataModel.resetModel()
    }

}
