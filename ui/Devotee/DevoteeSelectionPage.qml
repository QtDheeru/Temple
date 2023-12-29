import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import "../components" as Utils
import "../"
Item {
    id : root
    anchors.fill: parent
    signal loadMenuPage()
    property int countIfSevaNamesPresentInSevaTypes:0;
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
                ColumnLayout{
                    width : parent.width
                    anchors.horizontalCenter: parent.horizontalCenter
                    Layout.margins: 10
                    Layout.alignment: Qt.AlignTop

                    Button {
                        text : "Start Seva Booking"
                        Layout.fillWidth: true
                        font.pixelSize: 20
                        onClicked: startSevaBooking();
                    }
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
                        onClicked: addDevotee();
                    }
                    Button {
                        text : "Update Devotee"
                        Layout.fillWidth: true
                        font.pixelSize: 20
                        onClicked: areSureUpdate();
                    }
                    Button {
                        text : "Delete Devotee"
                        Layout.fillWidth: true
                        font.pixelSize: 20
                        onClicked: areSureDelete();
                    }
                    Button {
                        text : "Clear Data"
                        Layout.fillWidth: true
                        font.pixelSize: 20
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
            if(sevaProxy.getSevaTypeModel().getSevaTypeListSize()===0)
            {
                console.log("clicked on Sevabooking if(sevaTypeModel===0)")
                errorOccur("seva types not present");
            }
            for(var i=0;i<sevaProxy.getSevaTypeModel().getSevaTypeListSize();i++)
            {
                if((sevaProxy.getSevaModel(sevaProxy.getSevaTypeModel().sevaTypes[i].sevaTypeId).getSevaListViewSize()===0))
                {
                    console.log("seveListModel  for if((sevaProxy.getSevaModel(100).getSevaListViewModel/*.getSevaListViewModel*/===0))")
                    // errorOccur("SevaNames not present");
                    countIfSevaNamesPresentInSevaTypes++;
                    console.log(" countIfSevaNamesPresentInSevaTypes++ "+countIfSevaNamesPresentInSevaTypes)
                }
            }
            if(countIfSevaNamesPresentInSevaTypes===sevaProxy.getSevaTypeModel().getSevaTypeListSize())
            {
                console.log(" if of === countIfSevaNamesPresentInSevaTypes++ "+countIfSevaNamesPresentInSevaTypes)
                errorOccur("SevaNames not present for any seva types");
            }
            if(countIfSevaNamesPresentInSevaTypes<sevaProxy.getSevaTypeModel().getSevaTypeListSize())
            {
                console.log(" if of <<< countIfSevaNamesPresentInSevaTypes++ "+countIfSevaNamesPresentInSevaTypes)
                 console.log("evening suman1---",_devoteeView.nakshatra)
                console.log("_devoteeView.mobileNo---",_devoteeView.mobileNo)
                var moblist=_devoteeView.mobileNo.split("_");
                var mob= moblist[0];
                loadSevabooking(_devoteeView.devoteeName,mob,_devoteeView.gothra,_devoteeView.nakshatra)
            }
            else{
                console.log("evening suman2---",_devoteeView.nakshatra)
                loadSevabooking(_devoteeView.devoteeName,_devoteeView.mobileNo,_devoteeView.gothra,_devoteeView.nakshatra)
            }
        }
    }

    function addDevotee() {
        console.log(" Mobile    ="+_devoteeView.mobileNo);
        console.log(" Name      = "+_devoteeView.devoteeName);
        console.log(" Nakshatra ="+_devoteeView.nakshatra)
        console.log(" Gothra    ="+_devoteeView.gothra)
        var devotee = {devoteeName : _devoteeView.devoteeName,
            mobileNumber : _devoteeView.mobileNo,
            gothra: _devoteeView.gothra,
            nakshatra:_devoteeView.nakshatra};
        if (!devoteeProxy.devoteeDataModel.addDevoteeJSObject(devotee)) {
            console.log(" Error Adding Devotee ="+devoteeProxy.devoteeDataModel.lastError());
            _errorDialog.text2Display = devoteeProxy.devoteeDataModel.lastError();
            _errorDialog.open();
        } else {
            console.log(" Dheerendra - Add Succesfull......")
            _errorDialog.context = 0;
            _errorDialog.text2Display = " Add successful";
            _errorDialog.visible = true;
            _errorDialog.open();
        }
    }

    function areSureUpdate(){
        _errorDialog.text2Display = " Are you sure you would like to Update ?\n\n Name ="+_devoteeView.devoteeName + "\n\n Mobile ="+_devoteeView.mobileNo;
        _errorDialog.context = 1;
        _errorDialog.open();
    }
    function areSureDelete(){
        _errorDialog.context = 2;
        _errorDialog.text2Display= " Are you sure you would like to Delete ?\n\n Name ="+_devoteeView.devoteeName + "\n\n Mobile ="+_devoteeView.mobileNo;
        _errorDialog.open();
    }

    function updateDevotee(){
        _errorDialog.visible = false;
        console.log(" Mobile    ="+_devoteeView.mobileNo);
        console.log(" Name      = "+_devoteeView.devoteeName);
        console.log(" Nakshatra ="+_devoteeView.nakshatra)
        console.log(" Gothra    ="+_devoteeView.gothra)
        var devotee = {devoteeName : _devoteeView.devoteeName,
            mobileNumber : _devoteeView.mobileNo,
            gothra: _devoteeView.gothra,
            nakshatra:_devoteeView.nakshatra};
        if (!devoteeProxy.devoteeDataModel.updateDevoteeJSObject(devotee)) {
            console.log(" Error Update Devotee ="+peopleDataModel.lastError());
            _errorDialog.context = 0;
            _errorDialog.text2Display = peopleDataModel.lastError();
        } else {
            _errorDialog.context = 0;
            _errorDialog.text2Display = " Update successful";
        }
        _errorDialog.open();
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
        if (!!devoteeProxy.devoteeDataModel.deleteDevoteeJSObject(devotee)) {
            console.log(" Error Delete Devotee ="+peopleDataModel.lastError());
            _errorDialog.text2Display = peopleDataModel.lastError();
            _errorDialog.context = 0;

        }else {
            _errorDialog.context = 0;
            _errorDialog.text2Display = " Delete successful";
        }
        _errorDialog.open();
    }

    function clearData(){
     _devoteeView.clearData()
    }

    function setDevoteeDetails(devotee){
        _devoteeView.mobileNo  = devotee.mobileNumber;
        _devoteeView.devoteeName = devotee.devoteeName;
        _devoteeView.setNakshatraCombo(devotee.nakshatra)
        _devoteeView.setGothraCombo(devotee.gothra);
    }

    Connections{
        target: _devoteeListView
        function onDevoteeSelectionIndex(idx){
            console.log(" Devotee Selected ="+idx)
            var index = devoteeProxy.devoteeSearchModel.getRowOfDataFromTableViewModel(idx);
            var devotee = devoteeProxy.devoteeDataModel.getDevotee(index);
            _devoteeView.setGothras(sevaProxy.getGothras());
            _devoteeView.setNakshatras(sevaProxy.getNakshatras());
            devotee.print();
            setDevoteeDetails(devotee);
        }
    }
    Dialog {
        id: dialog
        title: "Title"
        standardButtons: Dialog.Ok
        visible: false
    }

    Utils.DisplayDialog{
        id : _errorDialog
        width: 500
        height: 300
        visible: false
        onYesAction:{
            console.log( "Yes clicked. Context ="+context)
            root.onYesAction(context)
            console.log( "Yes clicked. Finished.. ="+context)
        }
        onOpened: {
            console.log(" It is opened now..")
        }
        onClosed: {
            console.log(" It is onClosed now..")
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
