import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import "../../components"
import ReportElements 1.0

Rectangle{
    id:_rr1
    signal loadDateWisePage();
    signal loadMenuPage();
    signal back();
    property var styles : MyStyles{}
    property int footerHeight : styles.screenHeight/20
    TableView{
        id: lv1
        model: sevaProxy.sevaReport.accountFullReportModel
        width: parent.width
        height: parent.height - footerHeight

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
                    horizontalAlignment: Text.AlignVCenter
                }
            }
            rowDelegate: Rectangle {
                height:20
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
            id:no;title: "No"; role: "index";
            width: _rr1.width/15
            movable: false
            resizable: false
            horizontalAlignment: Text.AlignBottom
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
            id:_slNo;title: "Recpt No"; role: "recieptnumber";
            width: _rr1.width/15
            movable: false
            resizable: false
            horizontalAlignment: Text.AlignBottom
        }
        TableViewColumn {
            id:_sevaName;title: "ReceiptDate"; role: "recptDate";
            width: _rr1.width/12
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_cost;title: "SevaDate"; role: "sevadate";
            width: _rr1.width/12
            horizontalAlignment: Text.AlignLeft
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_sevaCount;title: "SevaName"; role: "sevaname";
            width: _rr1.width/8
            movable: false
            resizable: false
            elideMode: Text.ElideMiddle
        }
        TableViewColumn {
            id:_cash;title: "Count"; role: "sevaCount";
            width: _rr1.width/25
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_cheque;title: "SevaCost"; role: "sevacost";
            width: _rr1.width/12
            movable: false
            resizable: false
            horizontalAlignment : Text.AlignRight
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
            id:_UPI;title: "DevoteeName"; role: "devoteeName";
            width: _rr1.width/5
            movable: false
            resizable: false
            elideMode: Text.ElideMiddle
        }
        TableViewColumn {
            id:_neft;title: "Mobile"; role: "mobile";
            width: _rr1.width/12
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_paymode;title: "Pay-Mode"; role: "paymentmode";
            width: _rr1.width/15
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_additionalCost;title: "Extra"; role: "additionalCost";
            width: _rr1.width/10
            movable: false
            resizable: false
            horizontalAlignment : Text.AlignRight
            delegate: Rectangle {
                width: _additionalCost.width;height: _additionalCost.height;
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
            id: _totalAmount;
            title: "Total"; role: "total";
            width: _rr1.width/10
            movable: false
            resizable: false
            horizontalAlignment : Text.AlignLeft
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
        TableViewColumn {
            id:_status;title: "Status"; role: "status";
            width: _rr1.width/12
            movable: false
            resizable: false
        }
    }

    ReportFooter{
        id : footer
        width: _rr1.width
        height:  footerHeight
        cashTotal : sevaProxy.sevaReport.accountFullReportModel.cashTotal
        chequeTotal: sevaProxy.sevaReport.accountFullReportModel.chequeTotal;
        upiTotal: sevaProxy.sevaReport.accountFullReportModel.upiTotal
        neftTotal: sevaProxy.sevaReport.accountFullReportModel.neftTotal
        unknownTotal : sevaProxy.sevaReport.accountFullReportModel.unknownTypeTotal
        grandTotal: sevaProxy.sevaReport.accountFullReportModel.iGrandTotal
    }
    Connections {
        target : footer
        function onExportClicked() {
            sevaProxy.sevaReport.accountFullReportModel.generateFullAccountDataCSV()
        }
    }

    Connections{
        id:connection
        target: sevaProxy.sevaReport.accountFullReportModel.accountCSVProcessor
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
        console.log("Esc pressed in AllAccountDetails.qml ")
        back();
    }

    Component.onCompleted:  {
        console.log("Component.completed: AllAccountDetails ")
        _rr1.focus = true
    }
    Component.onDestruction: {
        console.log(" Component.onDestruction of AllAccountDetails ")
        sevaProxy.sevaReport.accountFullReportModel.resetAccModel();
    }
}
