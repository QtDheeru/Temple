import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import "../../components"
import ReportElements 1.0

Rectangle {
    id:_rr1
    signal loadDateWisePage();
    signal loadMenuPage();
    signal back();
    property var styles : MyStyles{}
    property int footerHeight : styles.screenHeight/20

    TableView{
        id: lv1
        model: sevaProxy.sevaReport.bookReportModel
        width:parent.width
        height: parent.height
        style: TableViewStyle {
            headerDelegate: Rectangle {
                height: 30
                color: "#72FFFF"
                Text {
                    id: headerItem
                    anchors.centerIn: parent
                    text: styleData.value
                    font.bold: true
                    font.pixelSize: 15
                    font.family: "Helvetica"
                }
            }
            rowDelegate: Rectangle {
                height:20
            }
            itemDelegate:Rectangle{
                id:_itmdel
                height:20
                color: styleData.row%2 ? "light gray":"white"
                Text {
                    anchors.fill: parent
                    // anchors.centerIn: parent
                    text: styleData.value
                    padding: 5
                    elide: Text.ElideRight
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Qt.AlignVCenter
                    font.pixelSize: 14
                }
            }
        }

        TableViewColumn {
            id:_name;title: "Name"; role: "name";
            width: _rr1.width/7.1
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_gothra;title: "Gothra"; role: "gothra";
            width: _rr1.width/7.1
            horizontalAlignment: Text.AlignRight
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_nakshatra;title: "Nakshatra"; role: "nakshatra";
            width: _rr1.width/7.1
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_sevaName;title: "Seva Name"; role: "sevaName";
            width: _rr1.width/7.1
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_teerthaPrasada;title: "SevaCount"; role: "SevaCount";
            width: _rr1.width/7.1
            movable: false
            resizable: false
            delegate: Rectangle{
                id:_teerthaPrasadadel
                height:20
                color: styleData.row%2 ? "light gray":"white"
                Text {
                    anchors.fill: parent
                    text: styleData.value
                    horizontalAlignment:Text.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                    font.pixelSize: 14
                }
            }
        }
        TableViewColumn {
            id:_mobileNumber;title: "Mobile Number"; role: "mobileNumber";
            width: _rr1.width/7.1
            movable: true
            resizable: true
        }
        TableViewColumn {
            id:_note;title: "Note"; role: "note";
            width: _rr1.width/7.1
            movable: true
            resizable: true
        }
        Component.onCompleted: {
            console.log("In  Component.onCompleted: of table view of brp "+sevaProxy.sevaReport.bookReportModel.getBookingReportQryListSize)
        }
    }

    Connections{
        id: connection
        target: sevaProxy.sevaReport.bookReportModel.sevaCSVProcessor
        function onSuccessMessage(exportmsg){
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
        console.log("Esc pressed in AllAccountDetails.qml ")
        back();
    }

    Component.onCompleted:  {
        console.log("Component.completed: AllAccountDetails ")
        _rr1.focus = true
    }
    Component.onDestruction: {
        console.log(" Component.onDestruction of AllAccountDetails ")
        sevaProxy.sevaReport.bookingReportModel.resetBookingModel();
    }
}
