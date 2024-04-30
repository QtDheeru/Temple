import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import "../../components"
import ReportElements 1.0

Rectangle{
    id:_rr1
    signal back();
    signal loadDateWisePage();
    signal loadMenuPage();
    property string fileName : "SevaAccountReportForSingleDate.qml"
    property var styles : MyStyles{}

    signal loadSevaDetails(var obj)

    function debugLog(msg) {
        console.log(fileName + " = " + msg);
    }

    TableView{
        id: lv1
        model: sevaProxy.sevaReport.accReportModel
        width:parent.width
        height: parent.height - styles.screenHeight/15
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
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                }

            }
            rowDelegate: Rectangle {
                id : rowDelegate
                height:20
                // color: styleData.selected ? "skyblue" : "white"
                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton
                    propagateComposedEvents: true
                    onClicked: {
                        console.log(fileName +" = Row is selected .....")
                        lv1.selection.clear()
                        lv1.currentRow = styleData.row
                        lv1.selection.select(styleData.row)
                        var coordinates = rowDelegate.mapToItem(lv1, mouse.x, mouse.y);
                        var clickIndex = lv1.__listView.indexAt(0, coordinates.y + lv1.__listView.contentY)
                        _rr1.debugLog (" Clicked Index = " + clickIndex)
                        if (clickIndex > -1) {
                            if (lv1.__activateItemOnSingleClick) lv1.activated(clickIndex)
                            lv1.clicked(clickIndex)
                        }
                        //       consume the mouse event
                        mouse.accepted = true
                        if (mouse.button === Qt.LeftButton){
                            var accountElement = sevaProxy.sevaReport.accReportModel.getAccountReportElement(clickIndex);
                            accountElement.reportGenerationSource = ReportEnums.CLICK_ON_REPORT;
                            loadSevaDetails(accountElement);
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
                    text: styleData.value
                    font.pixelSize: 14
                }
            }
        }
        TableViewColumn {
            id:_idx;title: "   No"; role: "index";
            width: _rr1.width/15
            movable: false
            resizable: false
            delegate: Rectangle {
                width: _idx.width;height: _idx.height;
                color: styleData.row%2 ? "light gray" : "white"
                Text{
                    anchors.fill: parent;
                    text : (styleData.value + 1);
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }
        TableViewColumn {
            id:_sevaName;title: "Seva Name"; role: "sevaName";
            width: _rr1.width/6
            movable: false
            resizable: false
        }

        TableViewColumn {
            id:_sevaCount;title: "Seva Count"; role: "personCount";
            width: _rr1.width/12
            movable: false
            resizable: false
            horizontalAlignment: Text.AlignRight
        }

        TableViewColumn {
            id:_cost;title: "Cost"; role: "cost";
            width: _rr1.width/12
            horizontalAlignment: Text.AlignVCenter
            movable: false
            resizable: false
            delegate: Rectangle {
                width: _cash.width;height: _cash.height;
                color: styleData.row%2 ? "light gray" : "white"
                Text{
                    anchors.fill: parent;
                    text : styleData.value;
                    color: "black"
                    horizontalAlignment: Text.AlignRight
                }
            }
        }

        TableViewColumn {
            id:_cash;title: "Cash"; role: "Cash";
            width: _rr1.width/12
            movable: false
            resizable: false
            horizontalAlignment: Text.AlignVCenter
            delegate: Rectangle {
                width: _cash.width;height: _cash.height;
                color: styleData.row%2 ? "light gray" : "white"
                Text{
                    anchors.fill: parent;
                    text : styleData.value;
                    color: "black"
                    horizontalAlignment: Text.AlignRight
                }
            }
        }
        TableViewColumn {
            id:_cheque;title: "Cheque"; role: "Cheque";
            width: _rr1.width/12
            movable: false
            resizable: false
            horizontalAlignment: Text.AlignVCenter
            delegate: Rectangle {
                width: _cheque.width;height: _cheque.height;
                color: styleData.row%2 ? "light gray" : "white"
                Text{
                    anchors.fill: parent;
                    text : styleData.value;
                    color: "black"
                    horizontalAlignment: Text.AlignRight
                }
            }
        }
        TableViewColumn {
            id:_UPI;title: "UPI"; role: "UPI";
            width: _rr1.width/12
            movable: false
            resizable: false
            horizontalAlignment: Text.AlignVCenter
            delegate: Rectangle {
                width: _UPI.width;height: _UPI.height;
                color: styleData.row%2 ? "light gray" : "white"
                Text{
                    anchors.fill: parent;
                    text : styleData.value;
                    color: "black"
                    horizontalAlignment: Text.AlignRight
                }
            }
        }
        TableViewColumn {
            id:_neft;title: "NEFT"; role: "NEFT";
            width: _rr1.width/12
            movable: false
            resizable: false
            horizontalAlignment: Text.AlignVCenter
            delegate: Rectangle {
                width: _neft.width;height: _neft.height;
                color: styleData.row%2 ? "light gray" : "white"
                Text{
                    anchors.fill: parent;
                    text : styleData.value;
                    color: "black"
                    horizontalAlignment: Text.AlignRight
                }
            }
        }
        TableViewColumn {
            id:_totalAmount;title: "Total Amount"; role: "totalAmount";
            width: _rr1.width/6
            movable: false
            resizable: false
            horizontalAlignment: Text.AlignVCenter
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
        width: _rr1.width
        height:  footerHeight
        cashTotal : sevaProxy.sevaReport.accReportModel.cashTotal
        chequeTotal: sevaProxy.sevaReport.accReportModel.chequeTotal;
        upiTotal: sevaProxy.sevaReport.accReportModel.upiTotal
        neftTotal: sevaProxy.sevaReport.accReportModel.neftTotal
        unknownTotal : sevaProxy.sevaReport.accReportModel.unknownTypeTotal
        grandTotal: sevaProxy.sevaReport.accReportModel.iGrandTotal
    }
    Connections {
        target : footer
        function onExportClicked() {
            sevaProxy.sevaReport.accReportModel.generateAccountCSV()
        }
    }

    Connections{
        id:connection
        target: sevaProxy.sevaReport.accReportModel
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
        console.log("Esc pressed in SevaAccountReportForSingleDate ")
        back();
    }

    Component.onCompleted:  {
        console.log("Component.completed: of SevaAccountReportForSingleDate.qml")
        _rr1.focus = true
    }
    Component.onDestruction: {
        console.log(" Component.onDestruction of SevaAccountReportForSingleDate.qml")
        //sevaProxy.sevaReport.resetAccModel();
    }
}
