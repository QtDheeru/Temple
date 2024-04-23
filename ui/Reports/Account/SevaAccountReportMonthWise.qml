import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import "../../components"
import ReportElements 1.0
Rectangle{
    id:_rr1

    property string fileName : "SevaAccountReportMonthWise.qml";
    signal loadSingleDatePage(string obj);
    signal loadDateWiseForSlectedMonthPage(var obj);

    signal generateReportForOneMonth(var obj);
    signal back();
    property var styles : MyStyles{}

    TableView{
        id: lv1
        model: sevaProxy.sevaReport.accountReportMonthRangeModel
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
                id:r1
                height:20
                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton
                    propagateComposedEvents: true
                    onClicked: {
                        lv1.selection.clear()
                        lv1.currentRow = styleData.row
                        lv1.selection.select(styleData.row)
                        console.log("mouse clicked left styleData.selected "+styleData.selected)
                        mouse.accepted = true
                        if (mouse.button === Qt.LeftButton) {
                            console.log(fileName + " Row Clicked = "+lv1.currentRow)
                            var obj = sevaProxy.sevaReport.accountReportMonthRangeModel.getAccountReportMonthRangeElementAt(lv1.currentRow);
                            console.log(fileName +  " Generate Report for Month="+obj.month)
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
            width: _rr1.width/8.1

            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_sevaName;title: "Month"; role: "month";
            width: (_rr1.width-_slNo.width)/8

            movable: false
            resizable: true
        }
        TableViewColumn {
            id:_cost;title: "Total Seva Count"; role: "totalSevaCount";
            width:  (_rr1.width-_slNo.width)/8
            horizontalAlignment: Text.AlignLeft
            movable: false
            resizable: true
        }

        TableViewColumn {
            id:cash;title: "Cash"; role: "cash";
            width: (_rr1.width-_slNo.width)/8
            horizontalAlignment: Text.AlignRight
            movable: false
            resizable: true
        }
        TableViewColumn {
            id:_cheque;title: "Cheque"; role: "cheque";
            width: (_rr1.width-_slNo.width)/8
            horizontalAlignment: Text.AlignRight
            movable: false
            resizable: true
        }
        TableViewColumn {
            id:_upi;title: "UPI"; role: "upi";
            width: (_rr1.width-_slNo.width)/8
            horizontalAlignment: Text.AlignRight
            movable: false
            resizable: true
        }
        TableViewColumn {
            id:_neft;title: "NEFT"; role: "neft";
            width: (_rr1.width-_slNo.width)/8
            horizontalAlignment: Text.AlignRight
            movable: false
            resizable: true
        }

        TableViewColumn {
            id:_totalAmount;title: "Total Amount"; role: "totalAmount";
            width:  (_rr1.width-_slNo.width)/3.1
            movable: false
            resizable: true
        }
    }

    ReportFooter{
        id : footer
        width: _rr1.width
        height:  footerHeight
        totalSevaCount:sevaProxy.sevaReport.accountReportMonthRangeModel.totalSevaCount
        cashTotal : sevaProxy.sevaReport.accountReportMonthRangeModel.cashTotal
        chequeTotal: sevaProxy.sevaReport.accountReportMonthRangeModel.chequeTotal;
        upiTotal: sevaProxy.sevaReport.accountReportMonthRangeModel.upiTotal
        neftTotal: sevaProxy.sevaReport.accountReportMonthRangeModel.neftTotal
        unknownTotal : sevaProxy.sevaReport.accountReportMonthRangeModel.unknownTypeTotal
        grandTotal: sevaProxy.sevaReport.accountReportMonthRangeModel.grandTotal
    }

    Component.onCompleted:  {
        console.log("Component.completed: of SevaAccountReportMonthWise.qml")
        forceActiveFocus();
    }
    Component.onDestruction: {
        console.log(" Component.onDestruction of SevaAccountReportMonthWise.qml")
    }
    Keys.onEscapePressed: {
        console.log("Esc pressed in seva Account month wise report page")
        back()
    }
}
