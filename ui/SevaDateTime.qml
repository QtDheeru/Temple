import QtQuick 2.0
import "./components"
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Rectangle {
    id :_rootSevaDateTime
    width: 250;
    height: styles.firstRowHeight;//150
    color: "lightblue"

    property var styles : MyStyles{}
    property int subComponentHeight : height/8
    property int subComponentPixelSize : styles.fontSize
    property alias receiptdate : _receiptDate.text
    property var momento;// : _momento._data
    property alias bookedby : _bookedBy._data
    property string sevatime : _time._data
    property var today : new Date()

    signal errorOccur(string errorMsg);

    ColumnLayout {
        id : _c1
        Rectangle{
            id : _header
            height: _rootSevaDateTime.height/8
            color: "#00A2ED"
            Layout.maximumWidth: _root.width
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop
            Text {
                Layout.fillWidth: true;
                text : qsTr("Receipts Details")
                font.bold : true
                font.italic: true
                font.pixelSize: styles.headerTextFont1
                anchors.centerIn: parent
            }
        }
        Layout.leftMargin: 10
        width: parent.width
        height: parent.height
        // MyDateEntry{
        //     id:r1;
        //     myHeight:_rootSevaDateTime.subComponentHeight ;
        //     fontPixelSize: _rootSevaDateTime.subComponentPixelSize
        //     myWidth: parent.width/1.25
        //     _labelText:qsTr("Reciept Date")
        //     calendarEnabled:false
        //     showPopup: sevaProxy.userManagement.rolenum === 1
        // }
        Rectangle{
            id: _receiptDateComp
            height : _rootSevaDateTime.subComponentHeight
            width: parent.width/1.25
            color: "transparent"
            // anchors.horizontalCenter: parent.horizontalCenter
            RowLayout{
                anchors.fill: parent
                Layout.leftMargin: parent.width/10
                spacing: parent.width/2

                Text {
                    id: _receiptText
                    text: " Receipt Date   "
                    font.pixelSize: _rootSevaDateTime.subComponentPixelSize
                }
                Text {
                    id: _receiptDate
                    text: Qt.formatDateTime(new Date(), "dd-MM-yyyy")
                    font.pixelSize: styles.receiptDateFontSize
                    color: "red"
                }
            }
        }

        // MyComboEntry{
        //     id:_momento;
        //     myHeight:_rootSevaDateTime.subComponentHeight - 10;
        //     fontPixelSize: _rootSevaDateTime.subComponentPixelSize
        //     myWidth: parent.width/1.25
        //     Layout.topMargin: 8;
        //     _labelText :qsTr("Momento")
        // }
        MyRowEntry {
            id:_time;_labelText :qsTr("Seva Time")
            myWidth: parent.width/1.25
            myHeight:_rootSevaDateTime.subComponentHeight-10;
            fontPixelSize: _rootSevaDateTime.subComponentPixelSize
        }
        MyRowEntry {
            id:_bookedBy;_labelText :qsTr("Booked By")
            myWidth: parent.width/1.25
            myHeight:_rootSevaDateTime.subComponentHeight-10;
            fontPixelSize: _rootSevaDateTime.subComponentPixelSize
        }
    }

    function clearData(){
        console.log(" Clear all the selection")
        r4.clearData()
    }


    Connections{
        target: r1
        onDateChanged:{
            console.log("In Connections of r1 of SDT"+date+receiptdate);
        }
    }
    Connections{
        target: _rootSevaDateTime
        onDefaultDates:{
            console.log("In Connections of onDefaultDates of SDT"+receiptdate);
            console.log("In Connections of onDefaultDates of SDT"+sevadate);
        }
    }

    Component.onCompleted: {
        console.log(" Trying to get the list category")
        // _momento._dataModel = sevaProxy.getMomentoCategory();
        if(momento.length===0)
        {
            console.log("********* In if of momento.length===0  *********** = 0")
            errorOccur("momentos not found");
        }
        defaultDates(receiptdate,sevadate);
    }
}
