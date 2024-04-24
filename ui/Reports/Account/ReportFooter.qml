import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Rectangle{
    id:root
    anchors.bottom: parent.bottom
    implicitWidth: 400;
    implicitHeight: 80
    property int wid : 100
    property double totalSevaCount : 0
    property double cashTotal : 0
    property double chequeTotal : 0
    property double neftTotal : 0
    property double upiTotal : 0
    property double grandTotal : 0
    property double unknownTotal : 0
    signal exportClicked();

    RowLayout {
        anchors.fill: parent
        spacing:  0
        Rectangle{
            id:_totalSevaCount
            color: "#72FFFF"
            Layout.fillWidth: true
            Layout.minimumWidth: root.wid
            Layout.minimumHeight: parent.height
            Text {
                text:"Total Sevas : \n" + root.totalSevaCount
                anchors.centerIn: parent
                font.pixelSize: styles.headerTextFont4
                font.italic: true
                font.bold : true
            }
        }
        Rectangle{
            id:_cashTotalText
            color: "#72FFFF"
            Layout.fillWidth: true
            Layout.minimumWidth: root.wid
            Layout.minimumHeight: parent.height
            Text {
                text:"Cash : \n" + root.cashTotal + ".00 ₹"
                anchors.centerIn: parent
                font.pixelSize: styles.headerTextFont4
                font.italic: true
                font.bold : true
            }
        }
        Rectangle{
            id:_chqTotalText
            color: "#72FFFF"
            Layout.fillWidth: true
            Layout.minimumWidth: root.wid
            Layout.minimumHeight: parent.height
            Text {
                text:"Cheque : \n" + root.chequeTotal + ".00 ₹"
                anchors.centerIn: parent
                font.pixelSize: styles.headerTextFont4
                font.italic: true
                font.bold : true
            }
        }
        Rectangle{
            id:_upiTotalText
            color: "#72FFFF"
            Layout.fillWidth: true
            Layout.minimumWidth: root.wid
            Layout.minimumHeight: parent.height
            Text {
                text:"UPI : \n" + root.upiTotal + ".00 ₹"
                anchors.centerIn: parent
                font.pixelSize: styles.headerTextFont4
                font.italic: true
                font.bold : true
            }
        }
        Rectangle{
            id:_neftTotalText
            color: "#72FFFF"
            Layout.fillWidth: true

            Layout.minimumWidth: root.wid
            Layout.minimumHeight: parent.height
            Text {
                text:"NEFT: \n" + root.neftTotal + ".00 ₹"
                anchors.centerIn: parent
                font.pixelSize: styles.headerTextFont4
                font.italic: true
                font.bold : true
            }
        }
        Rectangle{
            id:_unknownTotal
            color: "#72FFFF"
            Layout.fillWidth: true

            Layout.minimumWidth: root.wid
            Layout.minimumHeight: parent.height
            visible: (root.unknownTotal != 0)
            Text {
                text:"Unknown: \n" + root.unknownTotal + ".00 ₹"
                anchors.centerIn: parent
                font.pixelSize: styles.headerTextFont4
                font.italic: true
                font.bold : true
            }
        }
        Rectangle{
            id:_grandTotalText
            color: "#72FFFF"
            Layout.fillWidth: true
            Layout.minimumWidth: root.wid
            Layout.minimumHeight: parent.height
            height: 40
            Text {
                text:"Grand Total : \n" + root.grandTotal + ".00 ₹"
                anchors.centerIn: parent
                font.pixelSize: styles.headerTextFont4
                font.italic: true
                font.bold : true
            }
        }
        Button{
            id:_exportCsv
            text: "Export Data"
            Layout.fillWidth: true
            Layout.minimumWidth: root.wid
            Layout.minimumHeight: parent.height
            onClicked: exportClicked();
        }
    }
}
