import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.15 as Q215
import "../components"
import ReportElements 1.0
Rectangle{
    id:_root
    anchors.fill: parent
    property alias model : lv1.model
    property var styles : MyStyles{}
    property string fileName: "ReceiptBookView.qml ";

    TableView{
        id: lv1
        anchors.fill: parent
        model: sevaProxy.receiptBooksProxy.receiptBookModel
        Layout.minimumWidth: parent.width
        Layout.fillHeight: true
        anchors.top: _seperator.bottom
        anchors.margins: 20
        Layout.leftMargin: 20
        backgroundVisible: false

        property int selectedRow : 0;
        style: TableViewStyle {
            headerDelegate: Rectangle {
                height: 30
                color: "lightsteelblue"
                Text {
                    id: headerItem
                    anchors.centerIn: parent
                    text: styleData.value
                    font.bold: true
                    font.pixelSize: 20
                    font.family: "Helvetica"
                }
                Rectangle {
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    width: 1
                    color: "black"
                }
            }
            rowDelegate: Rectangle {
                id:r1
                height:36
                color: styleData.selected ? "transparent" : "lightblue"
                //border.width:  styleData.selected ? 2 : 0
                //border.color: styleData.selected ? "yellow" : "transparent"
                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton | Qt.RightButton
                    propagateComposedEvents: true
                    onClicked: {
                        console.log("mouse clicked right or left styleData.selected "+styleData.selected)

                        // clear any other selected row
                        lv1.selection.clear()

                        // select this row
                        lv1.currentRow = styleData.row
                        lv1.selection.select(styleData.row)

                        //                    color= styleData.selected ? "skyblue" : "white"
                        console.log("clicked cell in table view ",lv1.currentRow)

                        // convert mouse position from delegate to tableview coordinates
                        var coordinates = r1.mapToItem(lv1, mouse.x, mouse.y);
                        console.log("clicked cell in table view coordinates = ",coordinates)

                        // active and click the appropriate items (internal)
                        var clickIndex = lv1.__listView.indexAt(0, coordinates.y + lv1.__listView.contentY)
                        console.log("clicked cell in table view clickIndex = ",clickIndex)
                        if (clickIndex > -1) {
                            if (lv1.__activateItemOnSingleClick) lv1.activated(clickIndex)
                            lv1.clicked(clickIndex)
                        }
                        // consume the mouse event
                        mouse.accepted = true
                        if (mouse.button == Qt.LeftButton) {
                            console.log(" Item has been selected...="+lv1.currentRow)
                            devoteeSelectionIndex(lv1.currentRow)
                        } else if (mouse.button == Qt.RightButton) {}
                    }
                }
            }
            itemDelegate:Rectangle{
                id:itRect
                height:40
                color: styleData.selected ? "#FF8800CC" : styleData.row%2 ? "light gray" : "skyblue"
                Text {
                    text: styleData.value
                    // anchors.centerIn: parent
                    leftPadding: 1
                    font.pixelSize: 20
                    // elide: Text.ElideRight
                    //verticalAlignment: Text.AlignLeft
                    anchors.verticalCenter:  parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 5
                }
                Rectangle{
                    anchors.right: parent.right
                    width:0.5
                    color:"gray"
                    height:parent.height
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

        TableViewColumn {title: "BookID"; role: "BOOK_ID"; width: parent.width/12}
        TableViewColumn {title: "Start"; role: "START_BOOK_NO"; width: parent.width/12}
        TableViewColumn {title: "End"; role: "RECEIPT_BOOK_NO"; width: parent.width/12}
        TableViewColumn {title: "Current"; role: "CURRENT_RECEIPT_NO"; width: parent.width/12}
        TableViewColumn {title: "Creation Date"; role: "CREATION_DATE"; width: parent.width/7}
        TableViewColumn {title: "Closed Date"; role: "CLOSING_DATE"; width: parent.width/7}
        TableViewColumn {title: "OpenDate"; role: "ACTIVE_DATE"; width: parent.width/7}
        TableViewColumn {title: "CreatedBy"; role: "BOOKED_BY"; width: parent.width/8}
        TableViewColumn {title: "BookStatus"; role: "BOOK_STATUS"; width: parent.width/10}
    }
}
