import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import "./components"
import ReportElements 1.0
Rectangle{
    id:_r1
    property var styles : MyStyles{}
    width: styles.screenWidth
    height: styles.screenHeight
    //  color: "#72FFFF"
    signal reportDisplay(var date);
    signal sendReportImput(var obj);
    signal sendReportDateRangeImput(var obj);
    signal sendReportMonthRangeImput(var obj);
    signal sendReportDateRangeInput(var obj)
    signal loadMenuPage()
    signal resetAccModel();
    signal  sendSingleDateReportInput(var obj)
    signal sendReportDateRangeImputForWholeMonth(var obj);
    // property var styles : MyStyles{}
    property var footerHeight: _r1.height/15
    property alias tot :total.text
    property alias  isRangeDateSelected :_reportitems.isRangeDateSelected
    property alias isAllselected : _reportitems.isAllselected
    property alias  isSingleDateSelected :_reportitems.isSingleDateSelected

    Connections{
        target: _reportitems
        function onSendReportInput(obj){
            console.log("sendReportInputEmitted")
            sendReportImput(obj)
            if(sevaProxy.sevaReport.accReportModel.getAccountReportQryListSize()===0)
            {
                console.log("---------d1----------------")
                total.text = sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
            }
            else{
                console.log("---------e1----------------")
                total.text = sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
            }
            _load.sourceComponent = undefined
            _load.source = "SevaAccountReportForSingleDate.qml"
        }
        function onDateRangeSelected(){
            console.log("In onDateRangeSelected")
            _load.source = "SevaAccountReportOnDateRange.qml"

        }
        //        function onBookingDateRangeSelected(){
        //            console.log("In onBookingDateRangeSelected")
        //            _load.source = "SevaBookingReportOnDateRange.qml"

        //        }
        function onMonthWiseSelected(){
            console.log("In onDateRangeSelected")
            _load.source = "SevaAccountReportMonthWise.qml"

        }
        function onLoadDateWisePage()
        {
            console.log("In onLoadDateWisePage")
            _load.source = "SevaAccountReportOnDateRange.qml"
        }
        //        function onLoadSingleDatePage()
        //        {
        //            console.log("In onLoadSingleDatePage")
        //            _load.source = "SevaAccountReportForSingleDate.qml"
        //            console.log("  ---------------1----------------------");
        //           // -------------------------------------
        //        }
        function onSendReportDateRangeInput(obj){
            console.log("In onSendReportDateRangeInput")
            sendReportDateRangeImput(obj);
        }
        function onSendReportMonthRangeInput(obj)
        {
            console.log("In onSendReportMonthRangeInput")
            sendReportMonthRangeImput(obj);
            //  isAllselected = true;
        }
        function onSendReportDateRangeInputForWholeMonth(obj)
        {
            console.log("In onSendReportDateRangeInputForWholeMonth")
            sendReportDateRangeImputForWholeMonth(obj);
            //isAllselected = false;
        }
        function   onSendError(err){
            console.log("In onSendError")
            _errorDialog.showError(err);
        }
    }
    ReportFilterItems{
        id:_rip
    }
    Component.onDestruction: {
        console.log("Closing the report")
        resetAccModel();
        //resetAccDateRangeModel();
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
                color: "#576F72"}
        }
        Rectangle{
            id:leftpart
            Layout.preferredWidth:  parent.width - _rightpart.width
            Layout.preferredHeight:  parent.height

            TableView{
                id: lv1
                model: sevaProxy.sevaReport.accReportModel
                width:parent.width
                height: parent.height - footerHeight
                style: TableViewStyle {
                    headerDelegate: Rectangle {
                        height: 30
                        color: "#72FFFF"
                        Text {
                            id: headerItem
                            // anchors.centerIn: parent
                            text: styleData.value
                            font.bold: true
                            font.pixelSize: 15
                            font.family: "Helvetica"
                        }
                        //                        Rectangle {
                        //                            anchors.right: parent.right
                        //                            anchors.top: parent.top
                        //                            anchors.bottom: parent.bottom
                        //                            width: 1
                        //                            color: "black"
                        //                        }
                    }
                    rowDelegate: Rectangle {
                        height:20
                    }
                    //                    itemDelegate:Rectangle{
                    //                        id:_itmdel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"
                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment: styleData.column === 0? Text.AlignLeft:Text.AlignRight
                    //                            verticalAlignment: Qt.AlignVCenter

                    //                            font.pixelSize: 14
                    //                        }

                    //                        Rectangle{
                    //                            anchors.right: parent.right
                    //                            width:1
                    //                            color:"black"
                    //                            height:parent.height
                    //                        }
                    //                    }

                    itemDelegate:Rectangle{
                        id:_itmdel
                        height:20
                        color: styleData.selected ? "skyblue" : styleData.row%2 ? "light gray" : "white"
                        Text {
                            anchors.fill: parent
                            //   anchors.centerIn: parent
                            text: styleData.value
                            //                    horizontalAlignment: styleData.column === 0? Text.AlignLeft:Text.AlignRight
                            //                    verticalAlignment: Qt.AlignVCenter

                            font.pixelSize: 14
                        }

                        //                Rectangle{
                        //                    anchors.right: parent.right
                        //                    width:1
                        //                    color:"black"
                        //                    height:parent.height
                        //                }
                    }
                }
                TableViewColumn {
                    id:_slNo;title: "Sl No"; role: "SlNo";
                    width: leftpart.width/8.1

                    movable: false
                    resizable: false
                    //                    delegate: Rectangle{
                    //                        id:_slNodel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"
                    //                        Text {
                    //                            anchors.fill: parent
                    //                           // anchors.centerIn: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignLeft
                    //                            padding: 5
                    //                            verticalAlignment: Qt.AlignVCenter

                    //                            font.pixelSize: 14
                    //                        }
                    //                    }
                }
                TableViewColumn {
                    id:_sevaName;title: "Seva Name"; role: "sevaName";
                    width: (leftpart.width-_slNo.width)/3.1

                    movable: false
                    resizable: false
                    //                    delegate: Rectangle{
                    //                        id:_sevaNamedel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"
                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignLeft
                    //                            padding: 5
                    //                            verticalAlignment: Qt.AlignVCenter

                    //                            font.pixelSize: 14
                    //                        }
                    //                    }
                }
                TableViewColumn {
                    id:_cost;title: "Cost"; role: "cost";
                    width: (leftpart.width-_slNo.width)/6.1
                    horizontalAlignment: Text.AlignLeft
                    movable: false
                    resizable: false
                    //                    delegate: Rectangle{
                    //                        id:_costdel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"
                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignRight
                    //                            padding: _cost.width/3
                    //                            verticalAlignment: Qt.AlignVCenter

                    //                            font.pixelSize: 14
                    //                        }
                    //                    }
                }
                TableViewColumn {
                    id:_sevaCount;title: "Seva Count"; role: "personCount";
                    width: (leftpart.width-_slNo.width)/6.1
                    movable: false
                    resizable: false
                    //                    delegate: Rectangle{
                    //                        id:_sevaCountdel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"
                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignHCenter
                    //                            // Layout.rightMargin: 30
                    //                            verticalAlignment: Qt.AlignVCenter

                    //                            font.pixelSize: 14
                    //                        }
                    //                    }
                }
                TableViewColumn {
                    id:_totalAmount;title: "Total Amount"; role: "totalAmount";
                    width: (leftpart.width-_slNo.width)/4.1
                    movable: false
                    resizable: false
                    //                    delegate: Rectangle{
                    //                        id:_totalAmountdel
                    //                        height:20
                    //                        color: styleData.row%2 ? "light gray":"white"

                    //                        Text {
                    //                            anchors.fill: parent
                    //                            text: styleData.value
                    //                            horizontalAlignment:Text.AlignRight
                    //                            padding: _totalAmount.width/3
                    //                            verticalAlignment: Qt.AlignVCenter

                    //                            font.pixelSize: 14
                    //                        }
                    //                    }
                }

            }

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

            Loader{
                id:_load
                height:parent.height
                width:parent.width
                property  string isAllSel : _r1.isAllselected
                Connections{
                    target: _load.item
                    function  onLoadSingleDatePage(dt){
                        console.log("In   1111111111onLoadSingleDatePage(obj.date) "+dt)
                        _load.source = "SevaAccountReportForSingleDate.qml"
                        var li = dt.split("-");
                        console.log("******** "+li[2]+"-"+li[1]+"-"+li[0])
                        // dat
                        _rip.bSevawise = _reportitems.seWise
                        _rip.bDatewise = _reportitems.dtWise
                        _rip.sSingleDate = li[2]+"-"+li[1]+"-"+li[0];
                        _rip.sStartDate =  "null"
                        _rip.sEndDate = "null"
                        _rip.iSelectedType = 0 /*_reportitems.iSelType*/
                        _rip.iSevaType = _reportitems.iSevType
                        _rip.sSevaName = _reportitems.sevNam
                        console.log("In Loader of seva report page _rip.bSevawise"+ _rip.bSevawise)
                        console.log("In Loader of seva report page _rip.bDatewise"+ _rip.bDatewise)
                        console.log("In Loader of seva report page _rip.sSingleDate"+  _rip.sSingleDate)
                        console.log("In Loader of seva report page  _rip.sStartDate"+  _rip.sStartDate)
                        console.log("In Loader of seva report page    _rip.sEndDate "+    _rip.sEndDate)
                        console.log("In Loader of seva report page     _rip.iSelectedType"+ _rip.iSelectedType)
                        console.log("In Loader of seva report page    _rip.iSevaType "+ _rip.iSevaType)
                        console.log("In Loader of seva report page    _rip.sSevaName"+    _rip.sSevaName)
                        sendSingleDateReportInput(_rip);
                        // loadReportForSingleDate(date);

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
                    //_errorDialog.visible = false;
                }
            }
        }
    }
    Keys.onEscapePressed: {
        console.log("Esc pressed in select seva report page")
        loadMenuPage()
    }
    Component.onCompleted: {
        console.log("In Component.onCompleted: of seva report page")
        //        _r1.focus = true
        forceActiveFocus();
    }
}



