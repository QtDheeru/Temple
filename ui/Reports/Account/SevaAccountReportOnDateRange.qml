import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import "../../components"
import ReportElements 1.0
Rectangle{
    id: _root

    property var styles : MyStyles{}

    signal loadSingleDatePage(string obj);
    signal generateReportForDate(var reportElement)
    signal loadMonthWisePage();
    signal loadMenuPage();
    signal back();

    TableView{
        id: lv1
        model: sevaProxy.sevaReport.accountReportDateRangeModel
        width: parent.width
        height: parent.height - styles.screenHeight/15
        property var selectedRow;
        style: TableViewStyle {
            headerDelegate: Rectangle {
                height: 30
                color: "#72FFFF"
                Text {
                    id: headerItem
                    text: styleData.value
                    font.bold: true
                    font.pixelSize: 15
                    font.family: "Helvetica"
                }
            }
            rowDelegate: Rectangle {
                id: r1
                height:20
                color: styleData.selected ? "skyblue"  : "white"
                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton
                    propagateComposedEvents: true
                    onClicked: {
                        lv1.selection.clear()
                        lv1.currentRow = styleData.row
                        lv1.selection.select(styleData.row)
                        console.log("mouse clicked left styleData.selected "+styleData.selected)
                        // clear any other selected row

                        // select this row
                        // styleData.selected = true
                        console.log("clicked cell in table view ",lv1.currentRow)

                        // convert mouse position from delegate to tableview coordinates
                        var coordinates = r1.mapToItem(lv1, mouse.x, mouse.y);
                        console.log("clicked cell in table view coordinates = ",coordinates)

                        //   active and click the appropriate items (internal)
                        var clickIndex = lv1.__listView.indexAt(0, coordinates.y + lv1.__listView.contentY)
                        console.log("clicked cell in table view clickIndex = ",clickIndex)
                        if (clickIndex > -1) {
                            if (lv1.__activateItemOnSingleClick) lv1.activated(clickIndex)
                            lv1.clicked(clickIndex)
                        }
                        //       consume the mouse event
                        mouse.accepted = true
                        if (mouse.button === Qt.LeftButton)
                        {
                            console.log(" Generate the report for a Day at Row ="+lv1.currentRow)
                            var accountElement = sevaProxy.sevaReport.accountReportDateRangeModel.getAccountReportDateRangeElementAt(lv1.currentRow);
                            accountElement.reportGenerationSource = ReportEnums.CLICK_ON_REPORT;
                            generateReportForDate(accountElement);
                        }
                    }
                }
            }
            itemDelegate:Rectangle{
                id: _itmdel
                height:20
                color: styleData.selected ? "skyblue" : styleData.row%2 ? "light gray" : "white"
                Text {
                     anchors.fill: parent
                    text: styleData.value
                    font.pixelSize: 14
                }
            }
        }
        onClicked: {
            console.log("clicked cell in table view ",row)
            selectedRow = row
            {
                console.log("clicked cell in table view ",row)
            }
        }
        TableViewColumn {
            id: _slNo;title: "Sl No"; role: "index";
            width: _root.width/8.1
            movable: false
            resizable: false
            delegate: Rectangle {
                width: _slNo.width;height: _slNo.height;
                color: styleData.row%2 ? "light gray" : "white"
                Text{
                    anchors.fill: parent;
                    text : (styleData.value+1);
                    color: "black"
                    horizontalAlignment: Text.AlignVCenter
                }
            }
        }
        TableViewColumn {
            id: _sevaName;title: "Date"; role: "date";
            width: (_root.width-_slNo.width)/8
            movable: false
            resizable: true
        }
        TableViewColumn {
            id: _cost;title: "SevaCount"; role: "totalSevaCount";
            width: (_root.width-_slNo.width)/8
            horizontalAlignment: Text.AlignLeft
            movable: false
            resizable: true
        }
        TableViewColumn {
            id: cash;title: "Cash"; role: "cash";
            width: (_root.width-_slNo.width)/8
            horizontalAlignment: Text.AlignRight
            movable: false
            resizable: true
        }
        TableViewColumn {
            id: _cheque;title: "Cheque"; role: "cheque";
            width: (_root.width-_slNo.width)/8
            horizontalAlignment: Text.AlignRight
            movable: false
            resizable: true
        }
        TableViewColumn {
            id: _upi;title: "UPI"; role: "upi";
            width: (_root.width-_slNo.width)/8
            horizontalAlignment: Text.AlignRight
            movable: false
            resizable: true
        }
        TableViewColumn {
            id: _neft;title: "NEFT"; role: "neft";
            width: (_root.width-_slNo.width)/8
            horizontalAlignment: Text.AlignRight
            movable: false
            resizable: true
        }
        TableViewColumn {
            id: _totalAmount;title: "Total Amount"; role: "totalAmount";
            width:(_root.width-_slNo.width)/8
            movable: false
            resizable: true
            delegate: Rectangle {
                width: _totalAmount.width;height: _totalAmount.height;
                color: styleData.row%2 ? "light gray" : "white"
                Text{
                    anchors.fill: parent;
                    text : styleData.value;
                    color: "black"
                    horizontalAlignment: Text.AlignRight
                }
            }
        }
    }
    ReportFooter{
        id : footer
        width: _root.width
        height:  footerHeight
        cashTotal : sevaProxy.sevaReport.accReportModel.cashTotal
        chequeTotal: sevaProxy.sevaReport.accReportModel.chequeTotal;
        upiTotal: sevaProxy.sevaReport.accReportModel.upiTotal
        neftTotal: sevaProxy.sevaReport.accReportModel.neftTotal
        unknownTotal : sevaProxy.sevaReport.accReportModel.unknownTypeTotal
        grandTotal: sevaProxy.sevaReport.accountReportDateRangeModel.grandTotal
    }

    Keys.onEscapePressed: {
        back()
        console.log("Esc pressed in  seva acc report on Date Range page"+isAllSel)
    }
    Component.onCompleted:  {
        console.log("Component.completed: of SevaAccountReportOnDateRange.qml")
        forceActiveFocus();
    }
    Component.onDestruction: {
        console.log(" Component.onDestruction of SevaAccountReportOnDateRange.qml")
    }
}
