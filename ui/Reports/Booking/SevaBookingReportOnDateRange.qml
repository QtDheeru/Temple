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
    signal loadSingleDateBookingPage(string obj);
    signal loadMonthWiseBookingPage();
    signal loadMenuPage();
    signal generateReportForDate(var reportElement);
    signal back();
    property var styles : MyStyles{}
    property string fileName: "SevaBookingReportOnDateRage.qml";
    // color: "yellow"
    TableView{
        id: _modelTableView
        model: sevaProxy.sevaReport.bookingReportDateRangeModel
        width:parent.width
        height: parent.height - styles.screenHeight/15
        property var selectedRow;
        style: TableViewStyle {
            headerDelegate: Rectangle {
                height: 30
                color: "#72FFFF"
                Text {
                    id: headerItem
                    // anchors.centerIn: parent
                    text: styleData.value
                    font.bold: true
                    font.pixelSize: 15
                    font.family: "Helvetica"
                }
            }
            rowDelegate: Rectangle {
                id: _modelRow
                height:20
                // z:5
                color: styleData.selected ? "skyblue"  : "white"

                /*styleData.selected ?*/  /*: "white"*/
                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton
                    propagateComposedEvents: true
                    onClicked: {
                        _modelTableView.selection.clear()
                        _modelTableView.currentRow = styleData.row
                        _modelTableView.selection.select(styleData.row)
                        console.log(fileName + " mouse clicked left styleData.selected "+styleData.selected)
                        console.log(fileName + " clicked cell in table view ",_modelTableView.currentRow)
                        var coordinates = _modelRow.mapToItem(_modelTableView, mouse.x, mouse.y);
                        console.log(fileName + " clicked cell in table view coordinates = ",coordinates)
                        var clickIndex = _modelTableView.__listView.indexAt(0, coordinates.y + _modelTableView.__listView.contentY)
                        console.log(fileName + " clicked cell in table view clickIndex = ",clickIndex)
                        if (clickIndex > -1) {
                            if (_modelTableView.__activateItemOnSingleClick) _modelTableView.activated(clickIndex)
                            _modelTableView.clicked(clickIndex)
                        }
                        mouse.accepted = true
                        if (mouse.button === Qt.LeftButton)
                        {
                            console.log(fileName + " Left "+_modelTableView.currentRow)
                            var accountElement = sevaProxy.sevaReport.bookingReportDateRangeModel.getBookingReportDateRangeElementAt(_modelTableView.currentRow);
                            console.log(fileName + " model object "+accountElement.date);
                            accountElement.reportGenerationSource = ReportEnums.CLICK_ON_REPORT;
                            generateReportForDate(accountElement);
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
                    // anchors.centerIn: parent
                    text: styleData.value
                    // horizontalAlignment: styleData.column === 0? Text.AlignLeft:Text.AlignRight
                    // verticalAlignment: Qt.AlignVCenter

                    font.pixelSize: 14
                }
            }
        }
        onClicked: {
            console.log(fileName + " clicked cell in table view ",row)
            //        var rowItem =  (sevaProxy.sevaBSearchModel).index(row)
            selectedRow = row
            //        (sevaProxy.sevaBSearchModel)
            //         if (mouse.button == Qt.RightButton)
            {
                console.log(fileName + " clicked cell in table view ",row)
            }

        }
        TableViewColumn {
            id:_slNo;title: "Sl No"; role: "SlNo";
            width: _root.width/6.1

            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_sevaName;title: "Date"; role: "date";
            width: (_root.width-_slNo.width)/2.1

            movable: false
            resizable: true
        }
        TableViewColumn {
            id:_cost;title: "Total Seva Count"; role: "totalSevaCount";
            width: (_root.width-_slNo.width)/2.1
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

    Component.onCompleted:  {
        console.log(fileName + " Component.completed: of SevaBookingReportOnDateRange.qml")
        forceActiveFocus();
    }
    Component.onDestruction: {
        console.log(fileName + " Component.onDestruction of SevaBookingReportOnDateRange.qml")
    }
    Keys.onEscapePressed: {
        console.log(fileName + " Esc pressed in  seva booking report on Date Range page")
        back();
    }
    DisplayDialog {
        id :_errorDialog
        visible: false
        width: 600
        function showError(message){
            console.log(fileName + " Show eroor")
            _errorDialog.visible = true
            _errorDialog.text2Display = message
            _errorDialog.open();
            //_errorDialog.visible = false;
        }
        onNoAction: {
            _errorDialog.close()
        }
    }
}
