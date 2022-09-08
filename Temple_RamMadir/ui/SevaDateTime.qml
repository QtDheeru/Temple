import QtQuick 2.0
import "./components"
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Rectangle {
    id :_rootSevaDateTime
    width: 200;
    property var styles : MyStyles{}
    height: styles.firstRowHeight;//150
    property int subComponentHeight : height/8
    property int subComponentPixelSize : styles.fontSize

    color: "lightblue"
    property alias receiptdate : r1.selecteddate
    property alias sevadate : r2.selecteddate
    property alias momento : _momento._data
    property alias bookedby : r4._data
    property string sevatime : "08:00 AM"
    ColumnLayout {
        id : _c1
        //spacing: styles.verticalSpacing
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
                font.pixelSize: styles.headerTextFont1//_rootSevaDateTime.height/15
                anchors.centerIn: parent
            }
        }
        Layout.leftMargin: 10
        width: parent.width
        height: parent.height
        MyDateEntry{
            id:r1;Layout.topMargin: _rootSevaDateTime.height/100
            myHeight:_rootSevaDateTime.subComponentHeight;
            fontPixelSize: _rootSevaDateTime.subComponentPixelSize
            Layout.preferredWidth: parent.width
            myWidth: _rootSevaDateTime.width/1.2
            _labelText:qsTr("Reciept Date")
        }
        MyDateEntry{
            id:r2;
            Layout.topMargin: _rootSevaDateTime.height/100
            myHeight:_rootSevaDateTime.subComponentHeight;
            fontPixelSize: _rootSevaDateTime.subComponentPixelSize
            myWidth: _rootSevaDateTime.width/1.2
            _labelText:qsTr("Seva Date")
        }
        MyComboEntry{id:_momento;
            myHeight:_rootSevaDateTime.subComponentHeight;
            fontPixelSize: _rootSevaDateTime.subComponentPixelSize
            myWidth: parent.width/1.25
            Layout.topMargin: 8;
            _labelText :qsTr("Momento")
        }
        MyRowEntry {
            id:r4;_labelText :qsTr("Booked By")
            myHeight:_rootSevaDateTime.subComponentHeight;
            fontPixelSize: _rootSevaDateTime.subComponentPixelSize
        }
    }
    function clearData(){
        console.log(" Clear all the selection")
        r4.clearData()
    }
    Component.onCompleted: {
        console.log(" Trying to get the list category")
        _momento._dataModel = sevaProxy.getMomentoCategory();
    }
}
