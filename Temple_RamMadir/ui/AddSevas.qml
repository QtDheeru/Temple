import QtQuick 2.0
import "./components"
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Rectangle{
    id:_root
    anchors.fill: parent
    property int sevaType :-1
    property int subComponentHeight : 40    //height/8
    property int subComponentPixelSize :15
    signal closeAddSeva()
    color: "#F4C430"
    Rectangle {
        id :_rootSevaDateTime
        property var styles : MyStyles{}
        width: 500
        height: 500
        // styles.fontSize
        anchors.centerIn: parent
        color: "lightblue"
        property string sevatime : "08:00 AM"
        ColumnLayout {
            id : _c1
            spacing: styles.verticalSpacing
            width: parent.width
            height: parent.height
            //            Layout.leftMargin: 10
            Rectangle{
                id : _header
                height: 25
                color: "#00A2ED"
                Layout.maximumWidth: _root.width
                Layout.fillWidth: true
                Text {
                    Layout.fillWidth: true;
                    text : qsTr("Adding Seva Details")
                    font.bold : true
                    font.italic: true
                    font.pixelSize: 15
                    anchors.centerIn: parent
                }
            }
            ComboBox{
                id : _sevaTypes
                width: 200
                //            Layout.fillHeight: true
                Layout.minimumWidth: 35
                Layout.preferredWidth: parent.width/2
                model : sevaProxy.getSevaTypeModel()
                textRole: "sevaTypeName"
                font.pixelSize: _root.fontPixelSize
                anchors.horizontalCenter: parent.horizontalCenter
                onCurrentIndexChanged: {
                    console.log(" Index =" + currentIndex)
                    console.log(" Current Text =" + sevaProxy.getSevaTypeModel())
                    var currentItem = delegateModel.items.get(currentIndex)
                    console.log("Model SevaType: " + currentItem.model.sevaTypeName);
                    console.log("Model SevaType: " + currentItem.model.sevaTypeId);
                    _root.sevaType = currentItem.model.sevaTypeId;
                }
                editable: true
                Component.onCompleted: {
                    console.log(" combobox created")
                    var currentItem = delegateModel.items.get(currentIndex)
                    console.log("Model SevaType: " + currentItem.model.sevaTypeName);
                    console.log("Model SevaType: " + currentItem.model.sevaTypeId);
                    _root.sevaType = currentItem.model.sevaTypeId;
                }
            }
            Text {
                id: sevaID
                text: qsTr("sevaID        " + sevaProxy.getNextSevaId())
                anchors.horizontalCenter: parent.horizontalCenter
            }
            MyRowEntry {
                id:sevaNameID;_labelText :qsTr("Seva Name")
                myHeight:_rootSevaDateTime.subComponentHeight;
                myWidth: parent.width/1.25
                fontPixelSize: _rootSevaDateTime.subComponentPixelSize
                anchors.horizontalCenter: parent.horizontalCenter
            }
            MyRowEntry {
                id:sevaCostID;_labelText :qsTr("Seva Cost")
                myHeight:_rootSevaDateTime.subComponentHeight
                myWidth: parent.width/1.25
                fontPixelSize: _rootSevaDateTime.subComponentPixelSize
                anchors.horizontalCenter: parent.horizontalCenter
            }
            RowLayout{
                //                Layout.fillWidth: true
                width: parent.width
                Layout.preferredWidth: 300
                Layout.leftMargin: width/4
                Button{
                    id:saveBtn
                    height: _rootSevaDateTime/7
                    width: _rootSevaDateTime/9
                    text: "Save"
                    enabled: (sevaNameID._data != "" && sevaCostID._data != "")? true : false

                }
                Button{
                    id:closeBtn
                    height: _rootSevaDateTime/7
                    width: _rootSevaDateTime/9
                    text: "Close"
                    onClicked: {
                        closeAddSeva();
                    }
                }
            }
        }
        Connections{
            target: saveBtn
            function onClicked(){
                sevaProxy.addNewSeva(_root.sevaType,sevaNameID._data,sevaCostID._data)
                console.log("seva is adding in to DB " + sevaNameID._data)
                console.log( "edit text == > " + _sevaTypes.editText );
                //                if(_sevaTypes.editText == "");
                //                sevaProxy.addNewSevaType("","");
            }
        }

        function onEditText(){

        }



        Component.onCompleted: {
            console.log("Add seva Details")
        }
    }
}
