import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import "./components"

Rectangle {
    id : _rootSevaDetails
    width: 250;
    height: styles.firstRowHeight;//150
    color: "lightblue"

    property int subComponentHeight : height/7
    property int subComponentPixelSize : styles.fontSize
    property alias isCountEditable : countID._editable
    property alias isAdditionalCostEditable : r5._editable
    property alias sevaCost: r2._data
    property alias reference : r3._data
    property alias count: countID._data
    property alias sevadate : _sevaDate.selecteddate
    property alias addcost : r5._data
    property string sevatime : "08:00 AM"
    property alias referenceVisbility :r3.visible
    property bool isDataExist : r1.isDataExist &&
                                r2.isDataExist

    ColumnLayout {
        Layout.leftMargin: 10
        width: parent.width
        Rectangle{
            id : _header
            height: _rootSevaDetails.height/10
            color: "#00A2ED"
            Layout.maximumWidth: _root.width
            Layout.fillWidth: true
            Text {
                anchors.centerIn: parent
                text : "Seva Details"
                font.bold : true
                font.italic: true
                font.pixelSize: styles.headerTextFont1
            }
        }
        MyRowEntry{
            id:r1;_labelText : qsTr("Seva Name")
            myHeight:_rootSevaDetails.subComponentHeight
            myWidth: parent.width/1.25
            fontPixelSize: _rootSevaDetails.subComponentPixelSize
            _editable :false
        }
        MyRowEntry{
            id:r2;_labelText : qsTr("Seva Charges")
            myHeight:_rootSevaDetails.subComponentHeight
            myWidth: parent.width/1.25
            fontPixelSize: _rootSevaDetails.subComponentPixelSize
            _editable :false; regExpValidator: RegExpValidator{regExp:/^[0-9]*$/}
        }
        MyRowEntry{
            id:r3;_labelText : qsTr("Reference ")
            myHeight:_rootSevaDetails.subComponentHeight
            myWidth: parent.width/1.25
            fontPixelSize: _rootSevaDetails.subComponentPixelSize
        }
        MyRowEntry{
            id:countID;_labelText : qsTr("Count ")
            myHeight:_rootSevaDetails.subComponentHeight
            fontPixelSize: _rootSevaDetails.subComponentPixelSize
            myWidth: parent.width/1.25
            visible: referenceVisbility ? false:true
            regExpValidator: RegExpValidator{regExp:/^[0-9]*$/}
            _data :"1"
            _editable :true;
        }
        MyDateEntry{
            id: _sevaDate
            myHeight:_rootSevaDetails.subComponentHeight;
            fontPixelSize: _rootSevaDetails.subComponentPixelSize
            myWidth: parent.width/1.25
            _labelText:qsTr("Seva Date")
        }
        MyRowEntry{
            id:r5;_labelText : qsTr("Additional cost ")
            myHeight:_rootSevaDetails.subComponentHeight
            fontPixelSize: _rootSevaDetails.subComponentPixelSize
            myWidth: parent.width/1.25
            regExpValidator: RegExpValidator{regExp:/^[0-9]*$/}
            _data :"0"
            _editable :true;
        }
    }

    function setSevaDetails(seva){
        console.log(" Seva Details =" + seva.sevaCost)
        seva.print();
        r1._data = seva.sevaName;
        r2._data = seva.sevaCost
        if(seva.sevaCost === 0){
            r2._editable = true
            seva.cost = r2._data
        }else{
            r2._editable = false
        }
    }

    function resetPartial(){
        r1.clearData();
        r2.clearData();
        r5.clearData()
        countID.clearData()
        r5._data="0";
        countID._data = "1";
    }

    function clearData() {
        r3.clearData()
        countID.clearData()
        r5.clearData()
        r5._data="0";
        countID._data = "1";
    }

    Connections{
        target: _sevaDate
        onDateChanged:{
            console.log("In Connections of r2 of SDT"+date+sevadate)
        }
    }
}

