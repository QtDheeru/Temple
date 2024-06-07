import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import "../../components"
import ReportElements 1.0
Rectangle{
    id:_root
    signal loadSingleDatePage(string obj);
    signal loadDateWiseForSlectedMonthPage(var obj);
    signal loadDateWiseBookingForSlectedMonthPage(var obj);

    signal generateReportForOneMonth(var obj);
    signal back();

    property var styles : MyStyles{}
    property string fileName: "SevaBookingReportMonthWise.qml";

    // color: "yellow"
    TableView{
        id: _modelTableView
        model: sevaProxy.sevaReport.bookingReportMonthWiseModel
        width:parent.width
        height: parent.height - styles.screenHeight/15
        property var selectedRow;
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
                id:_modelRow
                height:20
                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton
                    propagateComposedEvents: true
                    onClicked: {
                        _modelTableView.selection.clear()
                        _modelTableView.currentRow = styleData.row
                        _modelTableView.selection.select(styleData.row)
                        console.log(fileName + " mouse clicked left styleData.selected "+styleData.selected)
                        mouse.accepted = true
                        if (mouse.button === Qt.LeftButton) {
                            console.log(fileName + " Left "+_modelTableView.currentRow)
                            var obj = sevaProxy.sevaReport.bookingReportMonthWiseModel.getBookingReportMonthRangeElementAt(_modelTableView.currentRow);
                            console.log(fileName + " model object "+obj.month)
                            obj.reportGenerationSource = ReportEnums.CLICK_ON_REPORT;
                            generateReportForOneMonth(obj);
                        }
                    }
                }
            }
            itemDelegate:Rectangle{
                id:_itmdel
                height:20
                color: styleData.selected ? "skyblue" : styleData.row%2 ? "light gray" : "white"
                Text {
                    anchors.fill: parent
                    //  anchors.centerIn: parent
                    text: styleData.value
                    font.pixelSize: 14
                }
            }
        }

        TableViewColumn {
            id:_slNo;title: "Sl No"; role: "SlNo";
            width: _root.width/8.1

            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_sevaName;title: "Month"; role: "month";
            width: (_root.width-_slNo.width)/2.1

            movable: false
            resizable: true
        }
        TableViewColumn {
            id:_cost;title: "Total Seva Count"; role: "totalSevaCount";
            width:  (_root.width-_slNo.width)/2.1
            horizontalAlignment: Text.AlignLeft
            movable: false
            resizable: true
        }

    }
    Button{
        id:_exportCsv
        height:60
        width: 200
        anchors.top: _modelTableView.bottom
        anchors.horizontalCenter: _modelTableView.horizontalCenter
        style: ButtonStyle{
            background: Rectangle{
                id: bg
                border.width: 1
                radius: 3
                color: "cornflowerblue"
                Label{
                    text: "Export Data"
                    anchors.centerIn: parent
                }
            }
        }
        onClicked: {
            console.log(fileName + " export data clicked")
            sevaProxy.sevaReport.bookReportModel.generateBookingReportCSV()

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

    Component.onCompleted:  {
        console.log(fileName + " Component.completed: of SevaBookingReportMonthWise.qml")
        forceActiveFocus();
    }
    Component.onDestruction: {
        console.log(fileName + " Component.onDestruction of SevaBookingReportMonthWise.qml")
    }
    Keys.onEscapePressed: {
        console.log(fileName + "Esc pressed in SevaBookingReportMonthWise")
        back();
    }
}
