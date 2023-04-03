import QtQuick 2.0
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.3
import "./components"

Rectangle {
    id : _root
    width: 250;
    Layout.fillWidth: true
    height: styles.firstRowHeight;//150
    property int subComponentHeight : height/8
    property int subComponentPixelSize : styles.fontSize

    color: "lightblue"
    property alias sevaCount : _bookedView.count
    property alias _dataModel : _bookedView.model
    property double _total  : 0.00


    DisplayDialog{
        id : _deleteDialog
        visible: false
        modal: true
        function deleteConfirm(message){
            _errorDialog.visible = true;
            _errorDialog.text2Display = message
            _errorDialog.open();

        }
        onYesAction :{
            console.log("Deleting the seva")
            //sevaProxy.deleteSeva(sevaid,sevaName1);
        }
        onNoAction: {
            console.log("Not deleting the seva")
            //sevaProxy.deleteSeva(sevaid,sevaName1);
        }
    }

    function deleteSeva(idx,sevaid,sevaName1){
        console.log(" Deleting the seva. Please confirm Index ="+idx +  "Seva Name ="+sevaName1 + " Seva Id="+sevaid)
        var b = sevaProxy.deleteSeva(sevaid,sevaName1);
        if(b===true)
        {
            _deleteDialog.deleteConfirm("Seva Deleted")
            sevaProxy.deleteSeva(sevaid,sevaName1);
        }
        else{
            errorOccur("seva not deleted")
        }
    }

    Rectangle{
        id : _header
        width: _root.width
        height: _root.height/10
        color: "#00A2ED"
        anchors.top: parent.top
        RowLayout {
            width: parent.width
            height: parent.height
            spacing: 15
            Text {
                Layout.leftMargin: 10;
                // Layout.preferredWidth:20;
                Layout.fillWidth: true;
                text : "No"
                font.bold : true
                font.italic: true
                font.pixelSize: styles.headerTextFont1
            }
            Text {
                Layout.fillWidth: true;
                // Layout.preferredWidth: 120
                Layout.leftMargin: 50
                text : "SevaName"
                font.bold : true
                font.italic: true
                font.pixelSize: styles.headerTextFont1
            }
            Text {
                Layout.leftMargin: 90;
                Layout.fillWidth: true;
                //Layout.preferredWidth: 40
                text : "SevaCost"
                font.bold : true
                font.italic: true
                font.pixelSize: styles.headerTextFont1
            }
            Text {
                Layout.fillWidth: true;
                Layout.leftMargin: 10
                //Layout.preferredWidth: 70
                text : "Additional Cost"
                font.bold : true
                font.italic: true
                font.pixelSize: styles.headerTextFont1
            }
            //            Text {
            //                Layout.fillWidth: true;text : "Delete ?"
            //                font.bold : true
            //                font.italic: true
            //                font.pixelSize: 12
            //            }
        }
    }

    Component{
        id : _c1
        Rectangle{
            width: _root.width
            height: 35
            color: (index%2) == 0 ? "#889977":"#227755"
            signal deleteEntry(int index,int sevaid,string sevaName)
            RowLayout {
                width: parent.width
                height: parent.height

                Text {
                    // Layout.fillWidth: true;
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin: 10;
                    // elide: Text.ElideLeft
                    Layout.preferredWidth: parent.width/12.5;
                    text : (index+1)
                }
                Text {
                    //  Layout.fillWidth: true;
                    Layout.alignment: Qt.AlignLeft
                    //Layout.leftMargin: 10
                    font.pixelSize:20;
                    text : sevaname
                    Layout.preferredWidth: parent.width/3
                    elide: Qt.ElideRight
                    //wrapMode: Text.WordWrap
                }
                Text {
                    Layout.alignment: Qt.AlignLeft
                    //Layout.leftMargin: 10
                    text : sevacost
                    // Layout.fillWidth: true;
                    // elide: Text.ElideLeft
                    Layout.preferredWidth: parent.width/6.25
                }
                Text {
                    Layout.alignment: Qt.AlignLeft
                    // Layout.leftMargin: 10
                    text : additionalcost
                    //Layout.fillWidth: true;
                    Layout.preferredWidth: parent.width/8.3333333
                    // elide: Text.ElideLeft
                }
                //                CheckBox{
                //                    checked: true
                //                    height: 15
                //                    width: 15
                //                    onClicked: {
                //                        deleteEntry(index,sevaid,sevaname)
                //                    }
                //                }
                Component.onCompleted: {
                    deleteEntry.connect(deleteSeva)
                }
            }
        }
    }

    ListView{
        id :_bookedView
        anchors.top: _header.bottom
        width: parent.width
        height: parent.height - 50
        model : sevaProxy.getBookedView();
        delegate: _c1
    }

    function clearData(){
        var b = sevaProxy.resetBookView();
        if(b===false)
        {
            errorOccur("Data not cleared")
        }
    }
}

