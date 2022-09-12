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

    //color: "lightblue"
    signal sendReportInput(var obj)
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
                    // font.pixelSize:  _rootReportFilter.subComponentPixelSize
                    Layout.alignment: Qt.AlignRight
                    onCheckedChanged: {
                        if(checked==false)
                        {
                            _rip.iSevaType=  currentSevaType;
                            console.log("SevaType unchecked")
                            _sevaType.enabled = true
                            _sevaName.enabled = true
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
                    myHeight:_rootReportFilter.subComponentHeight;
                    fontPixelSize: _rootReportFilter.subComponentPixelSize
                    myWidth: parent.width/1.25
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
                    // font.pixelSize:  _rootReportFilter.subComponentPixelSize
                    text: qsTr("All Seva Names")
                    Layout.alignment: Qt.AlignRight
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
                    myHeight:_rootReportFilter.subComponentHeight;
                    fontPixelSize: _rootReportFilter.subComponentPixelSize
                    myWidth: parent.width/1.25
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
                        else
                            r1.enabled = true
                    }
                }
                MyDateEntry{

                    id:r1;
                    anchors.right: parent.right
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
        Button{
            id:_button
            text: "Generate Report"
            font.pixelSize: _rootReportFilter.subComponentPixelSize
            font.bold: true
            Layout.preferredWidth: parent.width-20
            Layout.preferredHeight: _rootReportFilter.subComponentHeight;
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
            onClicked: {
                if(_rangeSelectedRadio.checked == true)
                {
                    var date1 = Date.fromLocaleString(Qt.locale(), r2.selecteddate, "dd-MM-yyyy")
                    var date2 = Date.fromLocaleString(Qt.locale(), r3.selecteddate, "dd-MM-yyyy")

                    console.log("comparing dates : " +date1 +" "+date2)
                    if(date1 > date2)
                         _errorDialog.showError("Date Range Invalid")
                    else
                    {
                        console.log("sending start date : " +r2.selecteddate)
                        console.log("sending end date : " +r3.selecteddate)
                        console.log("seva type ID : " +_rip.iSevaType)
                        _rip.bSevawise = _sevawise.checked
                        _rip.bDatewise = _datewise.checked
                        _rip.sSingleDate =  "null"
                        _rip.sStartDate =  r2.selecteddate
                        _rip.sEndDate = r3.selecteddate
                        //yet to implement
                        _rip.sMonth = "null"
                        _rip.sYear = "null"
                        sendReportInput(_rip)
                    }
                }
                else
                {
                    console.log(" selected date : " +r2.selecteddate)
                    _rip.bSevawise = _sevawise.checked
                    _rip.bDatewise = _datewise.checked
                    _rip.sSingleDate = r1.selecteddate
                    _rip.sStartDate =  "null"
                    _rip.sEndDate = "null"
                    //yet to implement
                    _rip.sMonth = "null"
                    _rip.sYear = "null"
                    sendReportInput(_rip)
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
    ButtonGroup { id: radioGroup }

}
