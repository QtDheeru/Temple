import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import Utils 1.0
import "./components"

Rectangle {
    id : _r1
    width: 250
    height: styles.firstRowHeight;//150
    property int subComponentHeight : height/8
    property int subComponentPixelSize : styles.fontSize
    color: "lightblue"
    signal errorOccur(string errorMsg);
    property alias receiptNumber :_receipt._data
    property alias devoteeName : _name._data
    property alias mobileNo : _mobile._data
    property alias isRcptvisible: _receipt.visible
    property alias devoteeNameEditable : _name._editable
    property alias mobileNoEditable : _mobile._editable

    property alias nakshatra : _nakshatra._data
    property string gothra :  ((_gotra._enteredText == "")?_gotra._data:_gotra._enteredText)
    property bool  isDataExist : _receipt.isDataExist &&
                                 _name.isDataExist &&
                                 _mobile.isDataExist && _name._data.length!=0
    onIsDataExistChanged: {
        console.log("********** is Data exist changed ***********")
    }
    clip: true

    function setGothras(gothraList){
        console.log("********* In setGothras function  *********** = 0")
        if(gothraList.length===0)
        {
            console.log("********* In if of setGothras function  *********** = 0")
            errorOccur("gothras not found");
        }
        else{
            _gotra._dataModel = gothraList;
        }
    }
    function setNakshatras(nakshatraList){
        console.log("********* In set nakshatra function  *********** = 0")
        if(nakshatraList.length===0)
        {
            console.log("********* In if of set nakshatra function  *********** = 0")
            errorOccur("Nakshtras not found");
        }
        else{
            _nakshatra._dataModel = nakshatraList;
        }
    }
    function setNakshatraCombo(nakshatra){
         _nakshatra.currentIndex = _nakshatra.findTextInComboBox(nakshatra);
    }
    function setGothraCombo(gothra){
        _gotra.currentIndex = _gotra.findTextInComboBox(gothra);
    }
    ColumnLayout {
        Layout.leftMargin: 10
        width: parent.width
        Layout.fillWidth: true
        //height: parent.height
        Rectangle{
            id : _header
            height: _root.height/20
            color: "#00A2ED"
            Layout.maximumWidth: _root.width
            Layout.fillWidth: true
            Text {
                anchors.centerIn: parent
                text : qsTr("Devotee Details")
                font.bold : true
                font.italic: true
                font.pixelSize: styles.headerTextFont1
            }
        }
        MyRowEntry{
            id:_receipt;
            myHeight:_r1.subComponentHeight;
            myWidth: parent.width/1.25
            fontPixelSize: _r1.subComponentPixelSize
            _labelText:qsTr("Reciept Number")
            _editable:false
        }
        MyRowEntry{
            id:_mobile;
            myHeight:_r1.subComponentHeight;
            myWidth: parent.width/1.25
            fontPixelSize: _r1.subComponentPixelSize
            _labelText:qsTr("Mobile Number")

            KeyNavigation.tab: _name
            regExpValidator : RegExpValidator{regExp:/[0-9]{10}/}
            onEditDone: {
                var devoteeDet = sevaProxy.searchMobile(_mobile._data);
                if (devoteeDet.devoteeName === "") {
                    console.log("Devotee does not exist");
                    _name.clearData();
                    return;
                }
                console.log(" Devotee Details ="+devoteeDet.devoteeName)
                console.log(" Devotee nakshtra Details ="+devoteeDet.nakshatra)

                console.log(" nakthatra Details ="+(_nakshatra.findTextInComboBox(devoteeDet.nakshatra)));

                _name._data = devoteeDet.devoteeName;
                _nakshatra.currentIndex = _nakshatra.findTextInComboBox(devoteeDet.nakshatra);
                _gotra.currentIndex = _gotra.findTextInComboBox(devoteeDet.gothra);
                console.log(' Gothra Index ='+_gotra.currentIndex)
                console.log(' Nakshatra Index ='+_nakshatra.currentIndex)
            }
        }

        MyRowEntry{id:_name;
            myHeight:subComponentHeight;
            myWidth: parent.width/1.25
            fontPixelSize: _r1.subComponentPixelSize
            _labelText:qsTr("Name");regExpValidator: RegExpValidator{regExp:/^[a-zA-Z ]*$/}
            focus: true
            KeyNavigation.tab: _nakshatra
        }
        MyComboEntry{id:_nakshatra;
            myHeight:_r1.subComponentHeight;
            fontPixelSize: _r1.subComponentPixelSize
            myWidth: parent.width/1.25
            isEditable: true
            Layout.topMargin: 10;_labelText :qsTr("Nakshatra")
            KeyNavigation.tab: _gotra}
        MyComboEntry{
            id:_gotra
            myHeight:_r1.subComponentHeight;
            fontPixelSize: _r1.subComponentPixelSize
            myWidth: parent.width/1.25
            Layout.topMargin: 10;_labelText :qsTr("Gotra")
            isEditable: true
        }
    }

    Connections{
        target: _name
        function onIsDataExistChanged(){
            console.log(" Name Status ="+_name.isDataExist)
            console.log(" Mobile Status ="+_mobile.isDataExist)
        }
    }

    function clearData(){
        _name.clearData();
        _mobile.clearData()
        //_receipt.clearData();
    }
    Component.onCompleted: {
        console.log(" Name Status ="+_name.isDataExist)
        console.log(" Mobile Status ="+_mobile.isDataExist)
    }
}
//}
