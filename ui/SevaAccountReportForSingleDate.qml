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
                //                        Rectangle {
                //                            anchors.right: parent.right
                //                            anchors.top: parent.top
                //                            anchors.bottom: parent.bottom
                //                            width: 1
                //                            color: "black"
                //                        }
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
                    //                    horizontalAlignment: styleData.column === 0? Text.AlignLeft:Text.AlignRight
                    //                    verticalAlignment: Qt.AlignVCenter

                    font.pixelSize: 14
                }

                //                Rectangle{
                //                    anchors.right: parent.right
                //                    width:1
                //                    color:"black"
                //                    height:parent.height
                //                }
            }
        }
        TableViewColumn {
            id:_slNo;title: "Sl No"; role: "SlNo";
            width: _rr1.width/8.1

            movable: false
            resizable: false
            //            delegate: Rectangle{
            //                id:_slNodel
            //                height:20
            //                color: styleData.row%2 ? "light gray":"white"
            //                Text {
            //                  //  anchors.fill: parent
            //                      anchors.centerIn: parent
            //                    text: styleData.value
            //                    horizontalAlignment:Text.AlignLeft
            //                    padding: 5
            //                    verticalAlignment: Qt.AlignVCenter

            //                    font.pixelSize: 14
            //                }
            //            }
        }
        TableViewColumn {
            id:_sevaName;title: "Seva Name"; role: "sevaName";
            width: _rr1.width/3.1

            movable: false
            resizable: false
            //            delegate: Rectangle{
            //                id:_sevaNamedel
            //                height:20
            //                color: styleData.row%2 ? "light gray":"white"
            //                Text {
            //                 //   anchors.fill: parent
            //                      anchors.centerIn: parent
            //                    text: styleData.value
            //                    horizontalAlignment:Text.AlignLeft
            //                    padding: 5
            //                    verticalAlignment: Qt.AlignVCenter
            //                    font.pixelSize: 14
            //                }
            //            }
        }
        TableViewColumn {
            id:_cost;title: "Cost"; role: "cost";
            width: _rr1.width/6.1
            horizontalAlignment: Text.AlignLeft
            movable: false
            resizable: false
            //            delegate: Rectangle{
            //                id:_costdel
            //                height:20
            //                color: styleData.row%2 ? "light gray":"white"
            //                Text {
            //                   // anchors.fill: parent
            //                      anchors.centerIn: parent
            //                    text: styleData.value
            //                    horizontalAlignment:Text.AlignRight
            //                    padding: _cost.width/3
            //                    verticalAlignment: Qt.AlignVCenter

            //                    font.pixelSize: 14
            //                }
            //            }
        }
        TableViewColumn {
            id:_sevaCount;title: "Seva Count"; role: "personCount";
            width: _rr1.width/6.1
            movable: false
            resizable: false
            //            delegate: Rectangle{
            //                id:_sevaCountdel
            //                height:20
            //                color: styleData.row%2 ? "light gray":"white"
            //                Text {
            //                    //anchors.fill: parent
            //                      anchors.centerIn: parent
            //                    text: styleData.value
            //                    horizontalAlignment:Text.AlignHCenter
            //                    // Layout.rightMargin: 30
            //                    verticalAlignment: Qt.AlignVCenter

            //                    font.pixelSize: 14
            //                }
            //            }
        }
        TableViewColumn {
            id:_totalAmount;title: "Total Amount"; role: "totalAmount";
            width: _rr1.width/4.1
            movable: false
            resizable: false
            //            delegate: Rectangle{
            //                id:_totalAmountdel
            //                height:20
            //                color: styleData.row%2 ? "light gray":"white"

            //                Text {
            //                   // anchors.fill: parent
            //                      anchors.centerIn: parent
            //                    text: styleData.value
            //                    horizontalAlignment:Text.AlignRight
            //                    padding: _totalAmount.width/3
            //                    verticalAlignment: Qt.AlignVCenter

            //                    font.pixelSize: 14
            //                }
            //            }
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
                    //  total.text = sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
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
    }
    Keys.onEscapePressed: {
        console.log("Esc pressed in SevaAccountReportForSingleDate ")
        //sendReportDateRangeImputAgain();
        // sevaProxy.sevaReport.resetAccDateRangeModel();
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
        //        sevaProxy.sevaReport.accReportModel.setGrandTotalToZero();
        //sevaProxy.sevaReport.resetAccModel();
    }
    Component.onDestruction: {
        console.log(" Component.onDestruction of SevaAccountReportForSingleDate.qml")
        // resetAccModel();
        //          _rr1.focus = false

        sevaProxy.sevaReport.resetAccDateRangeModel();
    }
    //    Connections
    //    {
    //        target: sevaProxy.sevaReport.accReportModel
    //        function onGrandTotalChanged()
    //        {
    //          total.text = sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
    //        }
    //    }
}
