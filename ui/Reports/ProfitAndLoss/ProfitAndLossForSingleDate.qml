import QtQuick 2.15
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import "../../components"

Rectangle{
    id: _root
    property var styles : MyStyles{}
    property string fileName : "ProfitAndLossForSingleDate.qml"

    signal back();

    TableView{
        id: tableView
        model: sevaProxy.sevaReport.profitAndLossDataModel
        width: parent.width
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
                height: 20
                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton
                    propagateComposedEvents: true
                    onClicked: {
                        console.log(fileName + " = Row is selected .....")
                        // tableView.selection.clear()
                        // tableView.currentRow = styleData.row
                        // tableView.selection.select(styleData.row)
                        // var coordinates = rowDelegate.mapToItem(tableView, mouse.x, mouse.y);
                        // var clickIndex = tableView.__listView.indexAt(0, coordinates.y + tableView.__listView.contentY)
                        // _root.debugLog (" Clicked Index = " + clickIndex)
                        // if (clickIndex > -1) {
                        //     if (tableView.__activateItemOnSingleClick) tableView.activated(clickIndex)
                        //     tableView.clicked(clickIndex)
                        // }
                        // //       consume the mouse event
                        mouse.accepted = true
                        if (mouse.button === Qt.LeftButton){
                            var accountElement = sevaProxy.sevaReport.profitAndLossDataModel.generateProfitAndLossForADay(clickIndex);
                            console.log(fileName + " accountElement =" + accountElement)
                            accountElement.reportGenerationSource = ReportEnums.CLICK_ON_REPORT;
                            loadSevaDetails(accountElement);
                        }
                    }
                }
            }
            itemDelegate: Rectangle{
                id: _itemdel
                height: 20
                color: styleData.selected ? "skyblue" : styleData.row%2 ? "light gray" : "white"
                Text {
                    anchors.fill: parent
                    text: styleData.value
                    font.pixelSize: 14
                }
            }
        }
        TableViewColumn {
            id: _idx;title: "   No"; role: "SlNo";
            width: _root.width/6
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
            id: _receiptDate;title: "Date "; role: "Date";
            width: _root.width/6
            movable: false
            resizable: false
            delegate: Rectangle {
                width: _loss.width;height: _loss.height;
                color: styleData.row%2 ? "light gray" : "white"
                Text{
                    anchors.fill: parent;
                    text : styleData.value;
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }

        TableViewColumn {
            id: _sevaAmount;title: "Seva Booked Amount"; role: "TotalBookedAmount";
            width: _root.width/6
            movable: false
            resizable: false
            horizontalAlignment: Text.AlignRight
            delegate: Rectangle {
                width: _loss.width;height: _loss.height;
                color: styleData.row%2 ? "light gray" : "white"
                Text{
                    id: _sevaTotal
                    anchors.fill: parent;
                    text : styleData.value;
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }

        TableViewColumn {
            id: _Expenditure;title: "Expenditure"; role: "TotalExpenditure";
            width: _root.width/6
            horizontalAlignment: Text.AlignVCenter
            movable: false
            resizable: false
            delegate: Rectangle {
                width: _loss.width;height: _loss.height;
                color: styleData.row%2 ? "light gray" : "white"
                Text{
                    anchors.fill: parent;
                    text : styleData.value;
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }

        TableViewColumn {
            id: _profit;title: "Profit"; role: "Profit";
            width: _root.width/6
            movable: false
            resizable: false
            horizontalAlignment: Text.AlignVCenter
            delegate: Rectangle {
                width: _loss.width;height: _loss.height;
                color: styleData.row%2 ? "light gray" : "white"
                Text{
                    anchors.fill: parent;
                    text : styleData.value;
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }
        TableViewColumn {
            id: _loss;title: "Loss"; role: "Loss";
            width: _root.width/6
            movable: false
            resizable: false
            horizontalAlignment: Text.AlignVCenter
            delegate: Rectangle {
                width: _loss.width;height: _loss.height;
                color: styleData.row%2 ? "light gray" : "white"
                Text{
                    anchors.fill: parent;
                    text : styleData.value;
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }
    }
}
