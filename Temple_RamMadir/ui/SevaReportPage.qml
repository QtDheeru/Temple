import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14
import "./components"

Rectangle{
    id:_r1
    anchors.fill: parent
    signal reportDisplay(var date);
    signal sendReportImput(var obj);
    signal loadMenuPage()
    property var styles : MyStyles{}
    property var footerHeight: _r1.height/15
    Connections{
        target: _reportitems
        function onSendReportInput(obj){
            console.log("sendReportInputEmitted")
            sendReportImput(obj)
        }
    }
    RowLayout{
        anchors.fill: parent
        Rectangle{
            id:_rightpart
            color: "#72FFFF"
            Layout.preferredWidth: parent.width/4
            Layout.preferredHeight: parent.height
            MyReportFilter{
                id:_reportitems
                width: parent.width
                height: parent.height
                border.color: "black"
                border.width: 2
                color: "#576F72"}
        }
        Rectangle{
            id:leftpart
            visible: true
            Layout.preferredWidth: parent.width - _rightpart.width
            Layout.preferredHeight: parent.height
            Rectangle{
                id : _header
                width: parent.width
                height: parent.height/30
                color: "#00A2ED"
                anchors.top: parent.top
                RowLayout {
                    anchors.fill: parent
                    Item{
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredWidth: parent.width/4
                        Layout.maximumWidth: parent.width/4
                        Text {
                            text:"Seva Name"
                            anchors.verticalCenter:  parent.verticalCenter
                            anchors.right: parent.right
                            anchors.rightMargin: parent.width/2
                            font.bold : true
                            font.pixelSize: styles.headerTextFont3
                        }
                    }
                    Item{
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredWidth: parent.width/4
                        Layout.maximumWidth: parent.width/4
                        Text {
                            text:"Cost"
                            anchors.verticalCenter:  parent.verticalCenter
                            anchors.right: parent.right
                            anchors.rightMargin: parent.width/2
                            font.bold : true
                            font.pixelSize: styles.headerTextFont3
                        }
                    }
                    Item{
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredWidth: parent.width/4
                        Layout.maximumWidth: parent.width/4
                        Text {
                            text:"Seva Count"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.right: parent.right
                            anchors.rightMargin: parent.width/2
                            font.bold : true
                            font.pixelSize: styles.headerTextFont3
                        }
                    }
                    Item{
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredWidth: parent.width/4
                        Layout.maximumWidth: parent.width/4
                        Text {
                            text:"Total Amount"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.right: parent.right
                            anchors.rightMargin: parent.width/2
                            font.bold : true
                            font.pixelSize: styles.headerTextFont3
                        }
                    }
                }
            }
            ListView{
                width: parent.width
                height: parent.height - _header.height - _footer.height
                anchors.top: _header.bottom
                id:accountReportList
                model: sevaProxy.sevaReport.accReportModel
                spacing: 2
                delegate:_comp1
            }
            Rectangle{
                id:_footer
                width: leftpart.width
                height: footerHeight
                anchors.bottom: leftpart.bottom
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
                    Text {
                        text: sevaProxy.sevaReport.accReportModel.grandTotal + ".00 ₹"
                        anchors.centerIn: parent
                        font.pixelSize: 30
                        font.italic: true
                        font.bold : true
                    }
                }
            }
        }
    }
    Component{
        id: _comp1
        Button {
            id: _b1
            width: leftpart.width
            height: 30
            palette {
                button: (index%2 ==0)?"#FCF8E8":"lightgray"
            }
            RowLayout{
                anchors.fill: parent
                Item{
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredWidth: parent.width/4
                    Layout.maximumWidth: parent.width/4
                    Layout.minimumWidth: parent.width/4
                    Text{
                        text:sevaName
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
                Item{
                    Layout.alignment: Qt.AlignRight
                    //Layout.leftMargin: 20
                    Layout.preferredWidth: parent.width/4
                    Layout.maximumWidth: parent.width/4
                    Layout.minimumWidth: parent.width/4
                    Text{
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.right: parent.right
                        anchors.rightMargin: parent.width/2
                        text:cost +".00 ₹"
                    }
                }
                Item{
                    Layout.alignment: Qt.AlignRight
                    //Layout.leftMargin: 20
                    Layout.preferredWidth: parent.width/4
                    Layout.maximumWidth: parent.width/4
                    Layout.minimumWidth: parent.width/4
                    Text{
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.right: parent.right
                        anchors.rightMargin: parent.width/2
                        text:personCount
                    }
                }
                Item{
                    Layout.alignment: Qt.AlignRight
                    //Layout.leftMargin: 20
                    Layout.preferredWidth: parent.width/4
                    Layout.maximumWidth: parent.width/4
                    Layout.minimumWidth: parent.width/4
                    Text{
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.right: parent.right
                        anchors.rightMargin: parent.width/2
                        text:totalAmount +".00 ₹"   }
                }
            }
            onClicked:{
                console.log("button clicked")
            }
        }
    }
    Keys.onEscapePressed: {
        console.log("Esc pressed in select seva report page")
        loadMenuPage()
    }
}



