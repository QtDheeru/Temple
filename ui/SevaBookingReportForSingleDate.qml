import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import "./components"
//import ReportElements 1.0
Rectangle{
    id:_rr1
    //    property alias thisHeight :_rr1.height
    //    property alias thisWidth : _rr1.width
    // color: "yellow"
    //signal sendReportDateRangeImputAgain();
    signal loadMenuPage();
    signal loadDateWiseBookingPage();
    property var styles : MyStyles{}
    TableView{
        id: lv1
        model: sevaProxy.sevaReport.bookReportModel
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
        //        TableViewColumn {
        //            id:_slNo;title: "Sl No"; role: "SlNo";
        //            width: _rr1.width/8.1

        //            movable: false
        //            resizable: false
        //            //            delegate: Rectangle{
        //            //                id:_slNodel
        //            //                height:20
        //            //                color: styleData.row%2 ? "light gray":"white"
        //            //                Text {
        //            //                  //  anchors.fill: parent
        //            //                      anchors.centerIn: parent
        //            //                    text: styleData.value
        //            //                    horizontalAlignment:Text.AlignLeft
        //            //                    padding: 5
        //            //                    verticalAlignment: Qt.AlignVCenter

        //            //                    font.pixelSize: 14
        //            //                }
        //            //            }
        //        }



        TableViewColumn {
            id:_name;title: "Name"; role: "name";
            width: leftpart.width/7.1
            movable: false
            resizable: false
        }
        TableViewColumn {
            id:_gothra;title: "Gothra"; role: "gothra";
            width: leftpart.width/7.1
            horizontalAlignment: Text.AlignRight
            movable: false
            resizable: false}
        TableViewColumn {
            id:_nakshatra;title: "Nakshatra"; role: "nakshatra";
            width: leftpart.width/7.1
            movable: false
            resizable: false}
        TableViewColumn {
            id:_sevaName;title: "Seva Name"; role: "sevaName";
            width: leftpart.width/7.1
            movable: false
            resizable: false}


        TableViewColumn {
            id:_teerthaPrasada;title: "Tertha Prasada"; role: "teerthaPrasada";
            width: leftpart.width/7.1
            movable: false
            resizable: false
            //            delegate: Rectangle{
            //                id:_teerthaPrasadadel
            //                height:20
            //                color: styleData.row%2 ? "light gray":"white"
            //                Text {
            //                    anchors.fill: parent
            //                    text: styleData.value
            //                    horizontalAlignment:Text.AlignHCenter
            //                    // padding: _cost.width/3
            //                    verticalAlignment: Qt.AlignVCenter

            //                    font.pixelSize: 14
            //                }
            //            }
        }


        TableViewColumn {
            id:_mobileNumber;title: "Mobile Number"; role: "mobileNumber";
            width: leftpart.width/7.1
            movable: true
            resizable: true}


        TableViewColumn {
            id:_note;title: "Note"; role: "note";
            width: leftpart.width/7.1
            movable: true
            resizable: true}

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
            sevaProxy.generateCSV()
        }
    }


    //  }
    //    Rectangle{
    //        id:_footer
    //        width: _rr1.width
    //        height:  styles.screenHeight/15
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
    //            //  color: "Black"
    //            Text {
    //                id:total
    //                text:sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
    //                anchors.centerIn: parent
    //                font.pixelSize: 30
    //                font.italic: true
    //                font.bold : true
    //                Component.onCompleted: {
    //                    console.log("In Component.onCompleted: of seva report page single date total text "+total.text)
    //                    //  total.text = sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"

    //                }
    //            }
    //        }
    //    }
    DisplayDialog {
        id :_errorDialog
        visible: false

        function showError(message){
            _errorDialog.visible = true;
            _errorDialog.text2Display = message
            _errorDialog.open();
            //_errorDialog.visible = false;
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
            loadDateWiseBookingPage();
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

        sevaProxy.sevaReport.resetBookingDateRangeModel();
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
