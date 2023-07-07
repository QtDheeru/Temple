import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import "./components"
import ReportElements 1.0
Rectangle{
    id:_rr1
    signal loadSingleDatePage(string obj);
    signal loadDateWiseForSlectedMonthPage(var obj);
     signal loadDateWiseBookingForSlectedMonthPage(var obj);
    property var styles : MyStyles{}

    // color: "yellow"
    TableView{
        id: lv1
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
                id:r1
                height:20
                // z:5
               // color: styleData.selected ? "skyblue"  : "white"


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

//                        // select this row
//                        // styleData.selected = true
//                        //                    color= styleData.selected ? "skyblue" : "white"
//                        console.log("clicked cell in table view ",lv1.currentRow)

//                        // convert mouse position from delegate to tableview coordinates
//                        var coordinates = r1.mapToItem(lv1, mouse.x, mouse.y);
//                        console.log("clicked cell in table view coordinates = ",coordinates)

//                        //   active and click the appropriate items (internal)
//                        var clickIndex = lv1.__listView.indexAt(0, coordinates.y + lv1.__listView.contentY)
//                        console.log("clicked cell in table view clickIndex = ",clickIndex)
//                        if (clickIndex > -1) {
//                            if (lv1.__activateItemOnSingleClick) lv1.activated(clickIndex)
//                            lv1.clicked(clickIndex)
//                        }
//                        //       consume the mouse event
                        mouse.accepted = true

                        if (mouse.button === Qt.LeftButton)
                        {
                            console.log("Left "+lv1.currentRow)
                            var obj = sevaProxy.sevaReport.bookingReportMonthWiseModel.getBookingReportMonthRangeElementAt(lv1.currentRow);
                            console.log("/////////////////////////////"+obj.month)
                            loadDateWiseBookingForSlectedMonthPage(obj.month);
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
                //    x:_itmdel.x+25
                    // horizontalAlignment: styleData.column === 0? Text.AlignLeft:Text.AlignRight
                    // verticalAlignment: Qt.AlignVCenter

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
//        onClicked: {
//            console.log("clicked cell in table view ",row)
//            //        var rowItem =  (sevaProxy.sevaBSearchModel).index(row)
//            selectedRow = row
//            //        (sevaProxy.sevaBSearchModel)
//            //         if (mouse.button == Qt.RightButton)
//            {
//                console.log("clicked cell in table view ",row)
//            }

//        }
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
            id:_sevaName;title: "Month"; role: "month";
            width: (_rr1.width-_slNo.width)/2.1

            movable: false
            resizable: true
            //            delegate: Rectangle{
            //                id:_sevaNamedel
            //                height:20
            //                color: styleData.row%2 ? "light gray":"white"
            //                Text {
            //                    anchors.fill: parent
            //                    text: styleData.value
            //                    horizontalAlignment:Text.AlignLeft
            //                    padding: 5
            //                    verticalAlignment: Qt.AlignVCenter

            //                    font.pixelSize: 14
            //                }
            //            }
        }
        TableViewColumn {
            id:_cost;title: "Total Seva Count"; role: "totalSevaCount";
            width:  (_rr1.width-_slNo.width)/2.1
            horizontalAlignment: Text.AlignLeft
            movable: false
            resizable: true
            //            delegate: Rectangle{
            //                id:_costdel
            //                height:20
            //                color: styleData.row%2 ? "light gray":"white"
            //                Text {
            //                    anchors.fill: parent
            //                    text: styleData.value
            //                    horizontalAlignment:Text.AlignRight
            //                    padding: _cost.width/3
            //                    verticalAlignment: Qt.AlignVCenter

            //                    font.pixelSize: 14
            //                }
            //            }
        }

//        TableViewColumn {
//            id:_totalAmount;title: "Total Amount"; role: "totalAmount";
//            width:  (_rr1.width-_slNo.width)/3.1
//            movable: false
//            resizable: true
            //            delegate: Rectangle{
            //                id:_totalAmountdel
            //                height:20
            //                color: styleData.row%2 ? "light gray":"white"

            //                Text {
            //                    anchors.fill: parent
            //                    text: styleData.value
            //                    horizontalAlignment:Text.AlignRight
            //                    padding: _totalAmount.width/3
            //                    verticalAlignment: Qt.AlignVCenter

            //                    font.pixelSize: 14
            //                }
            //            }
     //   }

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
            sevaProxy.sevaReport.bookReportModel.generateBookingReportCSV()

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
//    Rectangle{
//        id:_footer
//        width: _rr1.width
//        height: styles.screenHeight/15
//        anchors.bottom: _rr1.bottom
//        Rectangle{
//            id:_grandTotalText
//            width: parent.width/2
//            height: parent.height
//            color: "#72FFFF"
//            Text {
//                text:"Grand Total :" //+ sevaProxy.sevaReport.accReportModel.grandTotal
//                anchors.centerIn: parent
//                font.pixelSize: styles.headerTextFont1
//                font.italic: true
//                font.bold : true
//            }
//        }
//        Rectangle{
//            width: parent.width/2
//            height: parent.height
//            anchors.left: _grandTotalText.right
//            color: "#72FFFF"
//            Text {
//                id:total
//                text:sevaProxy.sevaReport.accountReportMonthRangeModel.grandTotal + ".00 ₹"
//                anchors.centerIn: parent
//                font.pixelSize: 30
//                font.italic: true
//                font.bold : true
//            }
//        }
//    }
    //    ReportFilterItems{
    //        id:_rip
    //    }

    Component.onCompleted:  {
        console.log("Component.completed: of SevaBookingReportMonthWise.qml")
  forceActiveFocus();
        // sevaProxy.sevaReport.resetAccDateRangeModel();
        //sevaProxy.sevaReport.generateAccReportForEachDate(obj);
    }
    Component.onDestruction: {
        console.log(" Component.onDestruction of SevaBookingReportMonthWise.qml")
        // resetAccModel();
        // sevaProxy.sevaReport.resetAccDateRangeModel();
    }
    Keys.onEscapePressed: {
        console.log("Esc pressed in SevaBookingReportMonthWise")
        loadMenuPage()
    }
}
