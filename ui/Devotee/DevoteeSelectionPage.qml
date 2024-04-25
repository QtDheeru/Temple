import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4
import "../components" as Utils
import "../"

Item {
    id : root
    anchors.fill: parent
    signal loadMenuPage()
    property int countIfSevaNamesPresentInSevaTypes:0
    signal errorOccur(string errorMsg);
    signal loadSevabooking(string d_name,string d_mobile,string d_gothra,string d_nakshatra)
    signal showAllDataView()
    property int context : 0
    RowLayout {
        anchors.fill: parent
        spacing: 20
        DevoteeDetailsPage{
            id : _devoteeListView
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.rightMargin: 10
            onLoadMenuPage: {
                console.log("loadMenuPage called from DevoteeSelectionPage")
                root.loadMenuPage()
            }
        }
        Rectangle{
            Layout.maximumWidth: 500
            Layout.minimumWidth: 500
            Layout.fillHeight: true
            color: "skyblue"
            border.width: 5
            border.color: "#445566"

            ColumnLayout {
                anchors.fill: parent
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text : "Enter Devotee Details"
                    anchors.top: parent.top
                    anchors.topMargin: 50
                }
                PersonalDetails{
                    id : _devoteeView
                    Layout.minimumWidth: parent.width - 50
                    Layout.minimumHeight: 400
                    Layout.maximumHeight: 500
                    anchors.horizontalCenter: parent.horizontalCenter
                    Layout.margins: 10
                    isRcptvisible:false
                }
                Button {
                    text : "Start Seva Booking"
                    Layout.fillWidth: true
                    Layout.margins: 10
                    font.pixelSize: 20
                    implicitHeight: parent.height/12
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 25
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "red"
                        radius: 4
                    }
                    onClicked: startSevaBooking()
                }

                ColumnLayout{
                    width : parent.width
                    anchors.horizontalCenter: parent.horizontalCenter
                    Layout.margins: 10
                    Layout.alignment: Qt.AlignTop

                    Button {
                        text : "All Data"
                        Layout.fillWidth: true
                        font.pixelSize: 20
                        onClicked: showAllDataView()
                    }
                    Button {
                        text : "Add Devotee"
                        Layout.fillWidth: true
                        font.pixelSize: 20
                        onClicked: addDevotee()
                    }
                    Button {
                        text : "Update Devotee"
                        Layout.fillWidth: true
                        font.pixelSize: 20
                        onClicked: areSureUpdate()
                    }
                    // Button {
                    //     text : "Delete Devotee"
                    //     Layout.fillWidth: true
                    //     font.pixelSize: 20
                    //     onClicked: areSureDelete()
                    // }
                    Button {
                        text : "Clear Data"
                        Layout.fillWidth: true
                        font.pixelSize: 20
                        onClicked: clearData()
                    }
                }
            }
        }
    }

    function startSevaBooking() {
        if (_devoteeView.mobileNo === '' || _devoteeView.devoteeName === ''){
            dialog.title = "Please select the Devote before start booking";
            dialog.open();
            return;
        }
        else{
            console.log(" Mobile    =" + _devoteeView.mobileNo);
            console.log(" Name      = " + _devoteeView.devoteeName);
            console.log(" Nakshatra =" + _devoteeView.nakshatra)
            console.log(" Gothra    =" + _devoteeView.gothra)
            var devotee = {devoteeName : _devoteeView.devoteeName,
                mobileNumber : _devoteeView.mobileNo,
                gothra: _devoteeView.gothra,
                nakshatra:_devoteeView.nakshatra};
            if (!devoteeProxy.devoteeDataModel.addDevoteeJSObject(devotee)) {
                console.log(" Error in Adding Devotee = " + devoteeProxy.devoteeDataModel.lastError());
            }else{
                console.log("Devotee Add Succesfull......")
            }

            if(sevaProxy.getSevaTypeModel().getSevaTypeListSize() === 0)
            {
                console.log("Clicked on Sevabooking sevaTypeModel = 0")
                errorOccur("seva types not present");
            }
            for(var i=0;i < sevaProxy.getSevaTypeModel().getSevaTypeListSize();i++)
            {
                if((sevaProxy.getSevaModel(sevaProxy.getSevaTypeModel().sevaTypes[i].sevaTypeId).getSevaListViewSize() === 0))
                {
                    console.log("seveListModel  is for seva type has 0 seva list" )
                    // errorOccur("SevaNames not present");
                    countIfSevaNamesPresentInSevaTypes++;
                    console.log(" countIfSevaNamesPresentInSevaTypes++ " + countIfSevaNamesPresentInSevaTypes)
                }
            }
            if(countIfSevaNamesPresentInSevaTypes === sevaProxy.getSevaTypeModel().getSevaTypeListSize())
            {
                console.log(" if of === countIfSevaNamesPresentInSevaTypes++ " + countIfSevaNamesPresentInSevaTypes)
                errorOccur("SevaNames not present for any seva types");
            }
            if(countIfSevaNamesPresentInSevaTypes < sevaProxy.getSevaTypeModel().getSevaTypeListSize())
            {
                console.log(" if of <<< countIfSevaNamesPresentInSevaTypes++ " + countIfSevaNamesPresentInSevaTypes)
                console.log("evening ---",_devoteeView.nakshatra)
                console.log("_devoteeView.mobileNo---",_devoteeView.mobileNo)
                //                var moblist = _devoteeView.mobileNo.split("_");
                //                var mob = moblist[0];
                loadSevabooking(_devoteeView.devoteeName,_devoteeView.mobileNo,_devoteeView.gothra,_devoteeView.nakshatra)
            }
            else{
                console.log("evening ---",_devoteeView.nakshatra)
                loadSevabooking(_devoteeView.devoteeName,_devoteeView.mobileNo,_devoteeView.gothra,_devoteeView.nakshatra)
            }
        }
    }

    function addDevotee() {
        console.log(" Mobile    =" + _devoteeView.mobileNo);
        console.log(" Name      = " + _devoteeView.devoteeName);
        console.log(" Nakshatra =" + _devoteeView.nakshatra)
        console.log(" Gothra    =" + _devoteeView.gothra)
        if(_devoteeView.mobileNo == "" || _devoteeView.devoteeName == ""){
            _errorDialog.text2Display = "Devotee Name or Mobile number is empty";
            _errorDialog.open();
            return;
        }

        var devotee = {devoteeName : _devoteeView.devoteeName,
            mobileNumber : _devoteeView.mobileNo,
            gothra: _devoteeView.gothra,
            nakshatra:_devoteeView.nakshatra};
        if (!devoteeProxy.devoteeDataModel.addDevoteeJSObject(devotee)) {
            console.log(" Error Adding Devotee =" + devoteeProxy.devoteeDataModel.lastError());
            _errorDialog.text2Display = devoteeProxy.devoteeDataModel.lastError();
            _errorDialog.open();
        } else {
            console.log("Devotee Add Succesfull......")
            _errorDialog.context = 0;
            _errorDialog.text2Display = " Add successful";
            _errorDialog.visible = true;
            _errorDialog.open();
        }
    }

    function areSureUpdate(){
        if(_devoteeView.mobileNo === '' || _devoteeView.devoteeName === ''){
            dialog.title = "Please select the Devote to update";
            dialog.open();
            return;
        }
        _errorDialog.text2Display = " Are you sure you would like to Update ?\n\n Name ="+_devoteeView.devoteeName + "\n\n Mobile ="+_devoteeView.mobileNo;
        _errorDialog.context = 1;
        _errorDialog.open();
    }
    function areSureDelete(){
        if(_devoteeView.mobileNo === '' || _devoteeView.devoteeName === ''){
            dialog.title = "Please select the Devote to delete";
            dialog.open();
            return;
        }
        _errorDialog.context = 2;
        _errorDialog.text2Display= " Are you sure you would like to Delete ?\n\n Name ="+_devoteeView.devoteeName + "\n\n Mobile ="+_devoteeView.mobileNo;
        _errorDialog.open();
    }

    function updateDevotee(){
        console.log(" Mobile    ="+_devoteeView.mobileNo);
        console.log(" Name      = "+_devoteeView.devoteeName);
        console.log(" Nakshatra ="+_devoteeView.nakshatra)
        console.log(" Gothra    ="+_devoteeView.gothra)
        var devotee = {
            devoteeName : _devoteeView.devoteeName,
            mobileNumber : _devoteeView.mobileNo,
            gothra: _devoteeView.gothra,
            nakshatra:_devoteeView.nakshatra
        };
        if (!devoteeProxy.devoteeDataModel.updateDevoteeJSObject(devotee)) {
            console.log(" Error Update Devotee =" + peopleDataModel.lastError());
            root.showTempDialog(peopleDataModel.lastError());
        } else {
            console.log(" Devotee update successfull ")
            var msg = " Update successful \n\n Name = " + _devoteeView.devoteeName + "\n\n Mobile = "+_devoteeView.mobileNo;
            root.showTempDialog(msg);
        }
        _errorDialog.context = 0
    }

    function showTempDialog(message) {
        var _eDialog = _errorComp.createObject(root);
        _eDialog.closed.connect(_eDialog.destroy);
        _eDialog.context = 0;
        _eDialog.text2Display = message;
        _eDialog.visible = true;
        _eDialog.open();
    }

    function deleteDevotee() {
        console.log(" Mobile    ="+_devoteeView.mobileNo);
        console.log(" Name      = "+_devoteeView.devoteeName);
        console.log(" Nakshatra ="+_devoteeView.nakshatra)
        console.log(" Gothra    ="+_devoteeView.gothra)
        var devotee = {devoteeName : _devoteeView.devoteeName,
            mobileNumber : _devoteeView.mobileNo,
            gothra: _devoteeView.gothra,
            nakshatra:_devoteeView.nakshatra};
        if (!devoteeProxy.devoteeDataModel.deleteDevoteeJSObject(devotee)) {
            console.log(" Error Delete Devotee ="+peopleDataModel.lastError());
            var msg = " Delete Error= "+ peopleDataModel.lastError() + "  \n\n Name = "+_devoteeView.devoteeName + "\n\n Mobile = "+_devoteeView.mobileNo ;
            root.showTempDialog(msg);
        } else {
            msg = " Delete successful \n\n Name = "+_devoteeView.devoteeName + "\n\n Mobile = "+_devoteeView.mobileNo;
            root.showTempDialog(msg);
        }
        _errorDialog.context = 0
    }

    function clearData(){
        _devoteeView.clearData()
    }

    function setDevoteeDetails(devotee){
        _devoteeView.mobileNo  = devotee.mobileNumber
        _devoteeView.devoteeName = devotee.devoteeName
        _devoteeView.setNakshatraCombo(devotee.nakshatra)
        _devoteeView.setGothraCombo(devotee.gothra)
    }

    Connections{
        target: _devoteeListView
        function onDevoteeSelectionIndex(idx){
            console.log(" Devotee Selected =" + idx)
            var index = devoteeProxy.devoteeSearchModel.getRowOfDataFromTableViewModel(idx)
            var devotee = devoteeProxy.devoteeDataModel.getDevotee(index)
            _devoteeView.setGothras(sevaProxy.getGothras())
            _devoteeView.setNakshatras(sevaProxy.getNakshatras())
            devotee.print()
            setDevoteeDetails(devotee)
        }
    }

    Dialog {
        id: dialog
        title: "Title"
        standardButtons: Dialog.Ok
        anchors.centerIn: parent
        visible: false
    }

    Component{
        id : _errorComp
        Utils.DisplayDialog{
            id : _eDialog
        }
    }

    Utils.DisplayDialog{
        id : _errorDialog
        width: 500
        height: 300
        visible: false
        onYesAction:{
            console.log( "Yes clicked. Context ="+context)
            root.onYesAction(context)
            _errorDialog.accept();
            _errorDialog.close();
        }
        onOpened: {
            console.log(" It is opened now..")
        }
        onClosed: {
            console.log(" It is onClosed now..")
            _errorDialog.close();
        }
    }

    function onYesAction(context) {
        console.log( "Yes clicked. Context ="+ context)

        switch (context){
        case 1 :updateDevotee(); break;
        case 2 :deleteDevotee(); break;
        default: _errorDialog.close();break;
        }
    }
    Component.onCompleted:{
        _devoteeView.setGothras(sevaProxy.getGothras());
        _devoteeView.setNakshatras(sevaProxy.getNakshatras());
    }
    Keys.onEscapePressed: {
        console.log("DevoteeSelectionPage :: Esc pressed")
        loadMenuPage()
    }
}
