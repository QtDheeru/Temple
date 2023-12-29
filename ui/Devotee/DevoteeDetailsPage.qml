import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.15 as Q215

Rectangle{
    id:_root
    width: parent.width
    height: parent.height
    signal loadSevaBookingView();
    signal loadMenuPage()
    signal devoteeSelectionIndex(int index)
    color: "lightblue"
    ColumnLayout {
        anchors.fill: parent
        spacing: 15
        RowLayout{
            id:searchRow
            Layout.minimumWidth: parent.width
            Layout.minimumHeight: 50
            Layout.alignment: Qt.AlignHCenter
            Layout.leftMargin: 20
            Layout.topMargin: 10
            spacing: 10
            Q215.Label{
                id:searchDevotee;
                Layout.maximumHeight: 100;
                Layout.minimumHeight: 45;
                Layout.minimumWidth: 150
                font.pixelSize: 20
                text: "Search Devotee By ->";
                font.bold: true
                verticalAlignment: Qt.AlignVCenter
            }
            SearchCriteriaComboBox{
                id: _combo
                Layout.minimumWidth: 200
                Layout.minimumHeight: 50
                currentIndex: 2
            }
            SevaSearchBar{
                id: _searchBar
                Layout.fillWidth: true
                Layout.maximumHeight: 50
                Layout.minimumHeight: 50
                onAccepted: _search.clicked()
                Keys.onDeletePressed: _clear.clicked()
                placeholderText: "Enter "+_combo.currentText + " for Search"
                onTextChanged: devoteeProxy.devoteeSearchModel.updateTableModel(txt, _combo.currentText);
            }
        }
        Rectangle{
            id : _seperator
            Layout.minimumWidth: parent.width
            Layout.fillWidth: true
            height: 3
            color: "blue"
        }
        TableView{
            id: lv1
            model: devoteeProxy.devoteeSearchModel
            Layout.minimumWidth: parent.width
            Layout.fillHeight: true
            anchors.top: _seperator.bottom
            anchors.topMargin: 10
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

            TableViewColumn {title: "S-NO"; role: "SerialNo"; width: parent.width/12}
            TableViewColumn {title: "D-ID"; role: "PersonDbID"; width: parent.width/12}
            TableViewColumn {title: "Mobile Number"; role: "MobileNumber"; width: parent.width/8}
            TableViewColumn {title: "Devotee Name"; role: "DevoteeName"; width: parent.width/8}
            TableViewColumn {title: "Gothra"; role: "Gothra"; width: parent.width/8}
            TableViewColumn {title: "Nakshatra"; role: "Nakshatra"; width: parent.width/8}
        }

        Menu{
            id: contextMenu
            MenuItem {
                text: qsTr('Modify')
                onTriggered:
                {
                    sevaProxy.sevaBookingTV
                    _allViewDataDialog.open()
                }
            }
            MenuItem {
                text: qsTr('Print')
                onTriggered:_allViewDataDialog.open()
            }
            MenuItem{
                text: qsTr('Cancel')
                onTriggered: {
                    _errorDialog.showmsg("Are you sure to cancel the reciept?")
                }
            }
        }
        //        DisplayDialog {
        //            id :_errorDialog
        //            visible: false

        //            function showmsg(exportmsg){
        //                _errorDialog.visible = true;
        //                _errorDialog.text2Display = exportmsg
        //                _errorDialog.open();
        //            }
        //            onYesAction: {
        //                console.log("reciept has to be delete");
        //            }
        //        }
        //        AllViewDataDialog{
        //            id:_allViewDataDialog
        //            anchors.centerIn: parent

        //            onCloseClicked: {
        //                resetBaseScreen()
        //                _allViewDataDialog.close();
        //            }
        //            onConfirmClicked: {
        //                sevaProxy.printBookingReceipt(_sevaBookingElement);
        //                _allViewDataDialog.close();
        //                resetBaseScreen();
        //            }

        //            onRejected: {
        //                resetBaseScreen()
        //            }
        //        }

        Component.onCompleted: {
            console.log("Seva All view Page is created")
            forceActiveFocus();
        }
        //    SevaBookingEle{
        //        id:_sevaBookingElement
        //    }
        Keys.onEscapePressed: {
            console.log("DevoteeDetailsPage :: Keys.onEscapePressed ")
            loadMenuPage();
        }
    }
}
