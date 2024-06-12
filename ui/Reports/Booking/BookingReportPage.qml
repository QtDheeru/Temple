import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4
import "../../components"
import ReportElements 1.0
Rectangle{
    id: _root
    width: styles.screenWidth
    height: styles.screenHeight

    property var styles : MyStyles{}

    property string fileName : "BookingReportPage.qml"
    property int footerHeight: _root.height/15
    property alias isRangeDateSelected : _bookitems.isRangeDateSelected
    property alias isAllselected : _bookitems.isAllselected
    property alias isSingleDateSelected : _bookitems.isSingleDateSelected

    signal loadMenuPage()
    signal resetBookingModel();
    signal sendBookingReportDateRangeImput(var obj);
    signal sendSingleDateBookingReportInput(var obj);
    signal sendBookingReportDateRangeImputForWholeMonth(var obj);
    signal sendBookingReportMonthRangeImput(var obj);
    signal startReportGeneration(var date);
    signal reportDisplay(var date);

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
            id:leftPart
            color: "#72FFFF"
            Layout.preferredWidth: parent.width/4
            Layout.preferredHeight: parent.height
            MyBookingFilter{
                id:_bookitems
                width: parent.width
                height: parent.height
                border.color: "black"
                border.width: 2
                color: "#576F72"
            }
            Component.onCompleted: {
                console.log(fileName + " The month and year initial",_bookitems.mnt," ",_bookitems.yr)
            }
        }

        Rectangle{
            id: rightPart
            Layout.preferredWidth:  parent.width - leftPart.width
            Layout.preferredHeight:  parent.height

            StackView{
                id : _bookingReportStackView
                height: parent.height
                width: parent.width
                pushEnter: Transition { XAnimator { duration: 0 } }
                pushExit: Transition { XAnimator { duration: 0 } }
                popEnter: Transition { XAnimator { duration: 0 } }
                popExit: Transition { XAnimator { duration: 0 } }
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

    function loadDaySummary(accountElement){
        console.log(fileName + " ***** Print Summary of Seva on Day = " + accountElement.date);
        var filterObj = reportFilterComp.createObject();
        filterObj.bSevawise = _bookitems.seWise
        filterObj.bDatewise = _bookitems.dtWise
        filterObj.iSelectedType = ReportEnums.SINGLE_DATE_REPORT;
        filterObj.reportType = ReportEnums.SUMMARY_REPORT
        filterObj.sevaType = accountElement.sevaTypeName;
        filterObj.iSevaType = accountElement.sevaType;
        filterObj.sSevaName = accountElement.sevaName;
        filterObj.sSingleDate = accountElement.date
        filterObj.sStartDate = "null"
        filterObj.sEndDate = "null"
        filterObj.sMonth = "null"
        filterObj.sYear = "null"
        filterObj.reportGenerationSource = accountElement.reportGenerationSource
        console.log(fileName + "Seva Type Name : " + accountElement.sevaTypeName)
        console.log(fileName + "Seva Name : " + accountElement.sevaName)
        console.log(fileName + "Seva Type : " + accountElement.sevaType)
        console.log(fileName + "load summary for a month filter object")
        generateReport(filterObj);
    }

    function loadDaySummaryForMonth(accountElement){
        console.log(fileName + " ***** Print Summary of Seva on Day = " + accountElement.date);
        var filterObj = reportFilterComp.createObject();
        filterObj.bSevawise = _bookitems.seWise
        filterObj.bDatewise = _bookitems.dtWise
        filterObj.iSelectedType = ReportEnums.MONTH_REPORT;
        filterObj.reportType = ReportEnums.SUMMARY_REPORT
        filterObj.sevaType = accountElement.sevaTypeName;
        filterObj.iSevaType = accountElement.sevaType;
        filterObj.sSevaName = accountElement.sevaName;
        filterObj.sSingleDate = "null"
        filterObj.sStartDate = "null"
        filterObj.sEndDate = "null"
        filterObj.sMonth = accountElement.month
        filterObj.sYear = accountElement.year
        filterObj.reportGenerationSource = accountElement.reportGenerationSource
        console.log(fileName + "Seva Type Name : " + accountElement.sevaTypeName)
        console.log(fileName + "Seva Name : " + accountElement.sevaName)
        console.log(fileName + "Seva Type : " + accountElement.sevaType)
        console.log(fileName + "Month : " + accountElement.month)
        console.log(fileName + "Year : " + accountElement.year)
        console.log(fileName + "load summary for a month filter object")
        generateReport(filterObj);
    }

    function generateReport(filterObject){
        console.log(fileName + " Start Generating the booking report")
        filterObject.print();
        if (filterObject.reportGenerationSource === ReportEnums.CLICK_ON_LEFT_SELECTION){
            _bookingReportStackView.clear();
        }
        switch(filterObject.reportType)
        {
        case ReportEnums.SUMMARY_REPORT:
            console.log(fileName + " " + filterObject + " Generate report filter object")
            _root.generateSummaryReport(filterObject);
            break;
        }
    }

    function generateSummaryReport(filterObject){
        var selectionType = filterObject.iSelectedType;
        console.log(fileName + " Start Generating the Summary report =" + selectionType)
        switch(selectionType){
        case ReportEnums.SINGLE_DATE_REPORT: {
             sevaProxy.sevaReport.generateBookReport(filterObject);
             var item = _bookingReportStackView.push("qrc:/ui/Reports/Booking/SevaBookingReportForSingleDate.qml");
             item.back.connect(_root.adjustStackView);
             break;
        }
        case ReportEnums.DATE_RANGE_REPORT: {
            sevaProxy.sevaReport.generateBookingReportForEachDate(filterObject);
            var item1 = _bookingReportStackView.push("qrc:/ui/Reports/Booking/SevaBookingReportOnDateRange.qml");
            item1.generateReportForDate.connect(_root.loadDaySummary)
            item1.back.connect(_root.adjustStackView);
            break;
        }
        case ReportEnums.MONTH_REPORT:{
            // Report for all the months. month=All is 13 Selection all in ComboBox
            if (filterObject.sMonth === "13"){
                sevaProxy.sevaReport.generateBookingReportForEachMonth(filterObject)
                var item3 = _bookingReportStackView.push("qrc:/ui/Reports/Booking/SevaBookingReportMonthWise.qml");
                item3.generateReportForOneMonth.connect(_root.loadDaySummaryForMonth)
                item3.back.connect(_root.adjustStackView);
            } else {
                sevaProxy.sevaReport.generateBookingReportForEachDateForWholeMonth(filterObject)
                var item2 = _bookingReportStackView.push("qrc:/ui/Reports/Booking/SevaBookingReportOnDateRange.qml");
                item2.generateReportForDate.connect(_root.loadDaySummary)
                item2.back.connect(_root.adjustStackView);
            }
            break;
        }
        }
    }

    function adjustStackView(){
        console.log(fileName + " StackView Depth ="+_bookingReportStackView.depth)
        if (_bookingReportStackView.depth <= 1){
            console.log(fileName + " Clearing StackView. Current Depth ="+_bookingReportStackView.depth)
            _bookingReportStackView.clear();
            loadMenuPage()
            return;
        }
        if (_bookingReportStackView.depth > 1){
            console.log(fileName + " Removing topItem. Current StackView Depth ="+_bookingReportStackView.depth)
            _bookingReportStackView.pop()
        }
    }

    Connections{
        target: _bookitems
        function onReportFilterChanged(filterObject){
            _root.generateReport(filterObject);
        }
    }

    Keys.onEscapePressed: {
        console.log(fileName + "Esc pressed in select booking report page")
        _root.adjustStackView();
    }
    Component.onCompleted: {
        console.log(fileName + " on completed")
        forceActiveFocus();
    }
    Component.onDestruction: {
        console.log(fileName + " Closing the booking report")
        resetBookingModel();
    }
}
