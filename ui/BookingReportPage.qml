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
    signal sendBookReportImput(var obj);
    signal loadMenuPage()
    signal resetBookingModel();
    signal sendBookingReportDateRangeImput(var obj);
    signal sendSingleDateBookingReportInput(var obj);
    signal sendBookingReportDateRangeImputForWholeMonth(var obj);
    signal sendBookingReportMonthRangeImput(var obj);
    // property var styles : MyStyles{}
    property var footerHeight: _r1.height/15
    // property alias tot :total.text
    property alias  isRangeDateSelected :_reportitems.isRangeDateSelected
    property alias isAllselected : _reportitems.isAllselected
    property alias  isSingleDateSelected :_reportitems.isSingleDateSelected
    Connections{
        target: _reportitems
        function onSendBookReportInput(obj){
            console.log("sendBookReportInputEmitted")
            sendBookReportImput(obj)
            _load.sourceComponent = undefined
            _load.source = "SevaBookingReportForSingleDate.qml"
        }
        function onSendBookingReportDateRangeInput(obj){
            console.log("In  onsendBookingReportDateRangeInput;")
            sendBookingReportDateRangeImput(obj);
        }
        function onBookingDateRangeSelected(){
            console.log("In onBookingDateRangeSelected")
            _load.source = "SevaBookingReportOnDateRange.qml"

        }
        function onSendBookingReportDateRangeInputForWholeMonth(obj)
        {
            console.log("In onSendBookingReportDateRangeInputForWholeMonth")
            sendBookingReportDateRangeImputForWholeMonth(obj);
            //isAllselected = false;
        }
        function onSendBookingReportMonthRangeInput(obj)
        {
            console.log("In onSendBookingReportMonthRangeInput")
            sendBookingReportMonthRangeImput(obj);
            //  isAllselected = true;
        }
        function onBookingMonthWiseSelected(){
            console.log("In onBookingMonthWiseSelected")
            _load.source = "SevaBookingReportMonthWise.qml"

        }
        function   onLoadDateWiseBookingPage(){
            console.log("In onLoadDateWiseBookingPage")
            _load.source = "SevaBookingReportOnDateRange.qml"
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
        resetBookingModel();
    }
    RowLayout{
        anchors.fill: parent
        Rectangle{
            id:_rightpart
            color: "#72FFFF"
            Layout.preferredWidth: parent.width/4
            Layout.preferredHeight: parent.height
            MyBookingFilter{
                id:_reportitems
                width: parent.width
                height: parent.height
                border.color: "black"
                border.width: 2
                color: "#576F72"
            }
        }
        Rectangle{
            id:leftpart
            Layout.preferredWidth:  parent.width - _rightpart.width
            Layout.preferredHeight:  parent.height

            TableView{
                id: lv1
                model: sevaProxy.sevaReport.bookReportModel
                width:parent.width
                height: parent.height
                style: TableViewStyle {
                    headerDelegate: Rectangle {
                        height: 30
                        color: "#72FFFF"
                        Text {
                            id: headerItem
                            anchors.centerIn: parent
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
                    itemDelegate:Rectangle{
                        id:_itmdel
                        height:20
                        color: styleData.row%2 ? "light gray":"white"
                        Text {
                            anchors.fill: parent
                            // anchors.centerIn: parent
                            text: styleData.value
                            padding: 5
                            elide: Text.ElideRight
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Qt.AlignVCenter

                            font.pixelSize: 14
                        }

                        //                        Rectangle{
                        //                            anchors.right: parent.right
                        //                            width:1
                        //                            color:"black"
                        //                            height:parent.height
                        //                        }
                    }
                }

                TableViewColumn {
                    id:_name;title: "Name"; role: "name";
                    width: leftpart.width/7.1

                    movable: false
                    resizable: false}
                TableViewColumn {
                    id:_gothra;title: "Gothra"; role: "gothra";
                    width: leftpart.width/7.1
                    horizontalAlignment: Text.AlignRight
                    movable: false
                    resizable: false}
                TableViewColumn {
                    id:_nakshatra;title: "Nakshatra"; role: "nakshatra";
                    width: leftpart.width/7.1
                    movable: false
                    resizable: false}
                TableViewColumn {
                    id:_sevaName;title: "Seva Name"; role: "sevaName";
                    width: leftpart.width/7.1
                    movable: false
                    resizable: false}


                TableViewColumn {
                    id:_teerthaPrasada;title: "Tertha Prasada"; role: "teerthaPrasada";
                    width: leftpart.width/7.1
                    movable: false
                    resizable: false
                    delegate: Rectangle{
                        id:_teerthaPrasadadel
                        height:20
                        color: styleData.row%2 ? "light gray":"white"
                        Text {
                            anchors.fill: parent
                            text: styleData.value
                            horizontalAlignment:Text.AlignHCenter
                            // padding: _cost.width/3
                            verticalAlignment: Qt.AlignVCenter

                            font.pixelSize: 14
                        }
                    }
                }


                TableViewColumn {
                    id:_mobileNumber;title: "Mobile Number"; role: "mobileNumber";
                    width: leftpart.width/7.1
                    movable: true
                    resizable: true}


                TableViewColumn {
                    id:_note;title: "Note"; role: "note";
                    width: leftpart.width/7.1
                    movable: true
                    resizable: true
                }
                Component.onCompleted: {
                    console.log("In  Component.onCompleted: of table view of brp "+sevaProxy.sevaReport.bookReportModel.getBookingReportQryListSize)
                    // total.text = tot;

                }

            }

            Loader{
                id:_load
                height:parent.height
                width:parent.width
                property  string isAllSel : _r1.isAllselected
                Connections{
                    target: _load.item
                    function  onLoadSingleDateBookingPage(dt){
                        console.log("In   1111111111onLoadSingleDateBookingPage(obj.date) "+dt)
                        _load.source = "SevaBookingReportForSingleDate.qml"
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
                        console.log("In Loader of booking report page _rip.bSevawise"+ _rip.bSevawise)
                        console.log("In Loader of booking report page _rip.bDatewise"+ _rip.bDatewise)
                        console.log("In Loader of booking report page _rip.sSingleDate"+  _rip.sSingleDate)
                        console.log("In Loader of booking report page  _rip.sStartDate"+  _rip.sStartDate)
                        console.log("In Loader of booking report page    _rip.sEndDate "+    _rip.sEndDate)
                        console.log("In Loader of booking report page     _rip.iSelectedType"+ _rip.iSelectedType)
                        console.log("In Loader of booking report page    _rip.iSevaType "+ _rip.iSevaType)
                        console.log("In Loader of booking report page    _rip.sSevaName"+    _rip.sSevaName)
                        sendSingleDateBookingReportInput(_rip);
                        // loadReportForSingleDate(date);

                    }

                    function   onLoadDateWiseBookingPage(){
                        console.log("In onLoadDateWiseBookingPage")
                        _load.source = "SevaBookingReportOnDateRange.qml"
                    }
                    function  onLoadMonthWiseBookingPage(){
                        console.log("In onLoadMonthWiseBookingPage")
                        _load.source = "SevaBookingReportMonthWise.qml"
                    }
                    function  onLoadDateWiseBookingForSlectedMonthPage(obj)
                    {
                        console.log("In  onLoadDateWiseBookingForSlectedMonthPage")
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
                        sendBookingReportDateRangeImput(_rip)
                        _load.source = "SevaBookingReportOnDateRange.qml"
                    }
                    function  onLoadMenuPage(){
                        console.log("In onLoadMenuPage")
                        loadMenuPage();
                    }
                }
                Component.onCompleted: {
                    console.log("In  Component.onCompleted: loader brp")
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
        console.log("Esc pressed in select booking report page")
        loadMenuPage()
    }
    Component.onCompleted: {
        console.log("In Component.onCompleted: of booking report page")
        //        _r1.focus = true

        forceActiveFocus();
    }
}


//roles[1] ="name";
//roles[2] = "gothra";
//roles[3] = "nakshatra";
//roles[4] = "savaName";
//roles[5] = "teerthaPrasada";
//roles[6] = "mobileNumber";
//roles[7] = "note";
