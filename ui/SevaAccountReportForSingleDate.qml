import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import "./components"
import ReportElements 1.0
Rectangle{
    id:_rr1
    //    property alias thisHeight :_rr1.height
    //    property alias thisWidth : _rr1.width
    // color: "yellow"
    //signal sendReportDateRangeImputAgain();
    signal loadDateWisePage();
    signal loadMenuPage();
    property var styles : MyStyles{}
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
                    //   anchors.centerIn: parent
                    text: styleData.value
                    font.pixelSize: 14
                }
            }
        }
        TableViewColumn {
            id:_slNo;title: "Sl No"; role: "SlNo";
            width: _rr1.width/15

            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_sevaName;title: "Seva Name"; role: "sevaName";
            width: _rr1.width/6

            movable: false
            resizable: false

        }
        TableViewColumn {
            id:_cost;title: "Cost"; role: "cost";
            width: _rr1.width/12
            horizontalAlignment: Text.AlignLeft
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_sevaCount;title: "Seva Count"; role: "personCount";
            width: _rr1.width/12
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_cash;title: "Cash"; role: "Cash";
            width: _rr1.width/12
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_cheque;title: "Cheque"; role: "Cheque";
            width: _rr1.width/12
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_UPI;title: "UPI"; role: "NEFT";
            width: _rr1.width/12
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_neft;title: "NEFT"; role: "UPI";
            width: _rr1.width/12
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_totalAmount;title: "Total Amount"; role: "totalAmount";
            width: _rr1.width/6
            movable: false
            resizable: false
        }
    }

    Rectangle{
        id:_footer
        width: _rr1.width
        height:  styles.screenHeight/15
        anchors.bottom: _rr1.bottom
        Rectangle{
            id:_grandTotalText
            width: parent.width/2
            height: parent.height
            color: "#72FFFF"
            Text {
                text:"Grand Total :" //+ sevaProxy.sevaReport.accReportModel.grandTotal
                anchors.centerIn: parent
                font.pixelSize: styles.headerTextFont1
                font.italic: true
                font.bold : true
            }
        }
        Rectangle{
            width: parent.width/2
            height: parent.height
            anchors.left: _grandTotalText.right
            color: "#72FFFF"
            //  color: "Black"
            Text {
                id:total
                text:sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
                anchors.centerIn: parent
                font.pixelSize: 30
                font.italic: true
                font.bold : true
                Component.onCompleted: {
                    console.log("In Component.onCompleted: of seva report page single date total text "+total.text)
                }
            }
        }
    }
    Button{
        id:_exportCsv
        height:60
        width: 200
        anchors.top: lv1.bottom
        anchors.horizontalCenter: lv1.horizontalCenter
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
            console.log("export data clicked")
            sevaProxy.sevaReport.accReportModel.generateAccountCSV()
        }
    }
    Connections{
        id:connection
        target: sevaProxy.sevaReport.accReportModel
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
        console.log("Esc pressed in SevaAccountReportForSingleDate ")
        if(isSingleDateSelected)
        {
            loadMenuPage();
        }
        else{
            loadDateWisePage();
        }
    }

    Component.onCompleted:  {
        console.log("Component.completed: of SevaAccountReportForSingleDate.qml")
        _rr1.focus = true
    }
    Component.onDestruction: {
        console.log(" Component.onDestruction of SevaAccountReportForSingleDate.qml")
        sevaProxy.sevaReport.resetAccDateRangeModel();
    }
}
