import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import "../../components"
import ReportElements 1.0
Rectangle{
    id:_root
    anchors.fill: parent
    property alias model : _modelTableView.model
    property var styles : MyStyles{}
    property string fileName: "SevaBookingReportForSingleDate.qml";

    signal loadMenuPage();
    signal loadDateWiseBookingPage();
    signal back()
    TableView{
        id: _modelTableView
        model: sevaProxy.sevaReport.bookReportModel
        width:parent.width
        height: parent.height - styles.screenHeight/15
        style: TableViewStyle {
            headerDelegate: Rectangle {
                height: 30
                color: "#72FFFF"
                Text {
                    id: headerItem
                    //anchors.centerIn: parent
                    text: styleData.value
                    font.bold: true
                    font.pixelSize: 15
                    font.family: "Helvetica"
                }
            }
            rowDelegate: Rectangle {
                height:20
                // color: styleData.selected ? "skyblue" : "white"
            }
            itemDelegate:Rectangle{
                id:_itmdel
                height:20
                color: styleData.selected ? "skyblue" : styleData.row%2 ? "light gray" : "white"
                Text {
                    anchors.fill: parent
                    text: styleData.value
                    font.pixelSize: 14
                }
            }
        }

        TableViewColumn {
            id:_name;title: "Name"; role: "name";
            width: _root.width/7.1
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_gothra;title: "Gothra"; role: "gothra";
            width: _root.width/7.1
            horizontalAlignment: Text.AlignRight
            movable: false
            resizable: false}
        TableViewColumn {
            id:_nakshatra;title: "Nakshatra"; role: "nakshatra";
            width: _root.width/7.1
            movable: false
            resizable: false}
        TableViewColumn {
            id:_sevaName;title: "Seva Name"; role: "sevaName";
            width: _root.width/7.1
            movable: false
            resizable: false}

        TableViewColumn {
            id:_sevaDate;title: "Seva Date"; role: "sDate";
            width: _root.width/7.1
            movable: false
            resizable: false}

        TableViewColumn {
            id:_teerthaPrasada;title: "SevaCount"; role: "sevaCount";
            width: _root.width/7.1
            movable: false
            resizable: false
        }


        TableViewColumn {
            id:_mobileNumber;title: "Mobile Number"; role: "mobileNumber";
            width: _root.width/7.1
            movable: true
            resizable: true}


        TableViewColumn {
            id:_note;title: "Note"; role: "note";
            width: _root.width/7.1
            movable: true
            resizable: true}

    }
    Row{
        anchors.top: _modelTableView.bottom
        anchors.horizontalCenter: _modelTableView.horizontalCenter
        spacing: parent.width/6
        Button{
            id:_exportCsv
            height:60
            width: 200
            anchors.verticalCenter: parent.verticalCenter
            style: ButtonStyle{
                background: Rectangle{
                    id: bg
                    border.width: 1
                    radius: 3
                    color: "cornflowerblue"
                    Label{
                        text: "Export Data"
                        anchors.centerIn: parent
                        font.pixelSize: 16
                    }
                }
            }
            onClicked: {
                console.log(fileName + " export data clicked")
                sevaProxy.sevaReport.bookReportModel.generateBookingReportCSV()
            }
        }
        Button{
            id:_exportALL
            height:60
            width: 200
            anchors.verticalCenter: parent.verticalCenter
            style: ButtonStyle{
                background: Rectangle{
                    id: bgall
                    border.width: 1
                    radius: 3
                    color: "cornflowerblue"
                    Label{
                        text: "Export All Data"
                        anchors.centerIn: parent
                        font.pixelSize: 16
                    }
                }
            }
            onClicked: {
                console.log(fileName + " export data clicked")
                sevaProxy.generateCSVSevaBookingReport()
            }
        }
    }
    Connections{
        id:connection
        target:  sevaProxy.sevaReport.bookReportModel
        onSuccessMessage:{
            _errorDialog.showmsg(exportmsg)
        }
    }
    DisplayDialog {
        id :_errorDialog
        visible: false

        function showmsg(exportmsg){
            _errorDialog.visible = true;
            _errorDialog.text2Display = exportmsg
            _errorDialog.open();
        }
        onNoAction: {
            _errorDialog.close()
        }
    }

    Keys.onEscapePressed: {
        console.log(fileName + " Esc pressed in SevaAccountReportForSingleDate ")
        back();
    }

    Component.onCompleted:  {
        console.log(fileName + " Component.completed: of SevaAccountReportForSingleDate.qml")
        _root.focus = true
    }
    Component.onDestruction: {
        console.log(fileName + " Component.onDestruction of SevaAccountReportForSingleDate.qml")
    }
}
