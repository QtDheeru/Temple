import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import "./components"

Item {
    id:root
    signal backClicked()
    signal sevaReceiptcancelClicked(var totalCost)

    Rectangle{
        anchors.fill: parent
        color: "lightblue"
        Label{
            text:"Cancel Receipt"
            font.pixelSize: 30
            anchors.bottom: _rect.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 10
        }

        Rectangle{
            id:_rect
            width: parent.width/1.5
            height: parent.height/1.5
            anchors.centerIn: parent
            ColumnLayout{
                anchors.fill: parent
                spacing: 0
                Rectangle{
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.maximumWidth: parent.width
                    Layout.maximumHeight: parent.height/8
                    Layout.alignment: Qt.AlignTop
                    border.color: "red"
                    RowLayout{
                        anchors.fill: parent
                        spacing: 0
                        Item{
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            Label{
                                text: "SevaName"
                                color: "blue"
                                Layout.leftMargin: 10
                                anchors.centerIn: parent
                                font{
                                    pixelSize: 18
                                    bold:true
                                }
                            }
                        }
                        Rectangle{
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            Layout.maximumWidth: 1
                            color: "black"
                        }
                        Item{
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            Label{
                                text: "Amount"
                                anchors.centerIn: parent
                                color: "blue"
                                font{
                                    pixelSize: 18
                                    bold:true
                                }
                            }
                        }
                    }
                }
                Rectangle{
                    id:_rect2
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.maximumWidth: parent.width
                    Layout.maximumHeight: parent.height

                    ListView{
                        anchors.fill:parent
                        model: sevaProxy.mysevacancelmodel
                        delegate: _comp
                        clip:true
                    }

                    Component{
                        id:_comp
                        RowLayout{
                            width:_rect2.width
                            height:_rect2.height/7
                            Rectangle{
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                                border.color: "black"
                                RowLayout{
                                    anchors.fill: parent
                                    Item{
                                        Layout.fillHeight: true
                                        Layout.fillWidth: true
                                        RowLayout{
                                            anchors.fill: parent
                                            Label{
                                                text: SevaName
                                                color: "black"
                                                Layout.leftMargin: 10
                                                font{
                                                    pixelSize: 18
                                                    bold:true
                                                }
                                            }
                                            CheckBox {
                                                id: _checkBox
                                                checked: SevaChecked
                                                Layout.alignment: Qt.AlignRight
                                                onClicked: {
                                                    SevaChecked = checked;
                                                    myTotalAmount += checked ? +parseInt(SevaAmount) : -parseInt(SevaAmount);
                                                }
                                                enabled: false
                                            }
                                        }
                                    }
                                    Rectangle{
                                        Layout.fillHeight: true
                                        Layout.fillWidth: true
                                        Layout.maximumWidth: 1
                                        color: "black"
                                    }
                                    Item{
                                        Layout.fillHeight: true
                                        Layout.fillWidth: true
                                        Label{
                                            text: SevaAmount + " X " + Quantity
                                            anchors.centerIn: parent
                                            color: "black"
                                            font{
                                                pixelSize: 18
                                                bold:true
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                Rectangle{
                    id:_rect3
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.maximumWidth: parent.width
                    Layout.maximumHeight: parent.height/9
                    Layout.bottomMargin: 5
                    RowLayout{
                        anchors.fill: parent
                        Rectangle{
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            border.color: "#9370db"
                            Label{
                                text: "Total"
                                anchors.centerIn: parent
                                color: "black"
                                font{
                                    pixelSize: 18
                                    bold:true
                                }
                            }
                        }
                        Rectangle{
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            border.color: "#9370db"
                            Label{
                                text: sevaProxy.mysevacancelmodel.totalAmount
                                anchors.centerIn: parent
                                color: "black"
                                font{
                                    pixelSize: 18
                                    bold:true
                                }
                            }
                        }
                    }
                }
                Rectangle{
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.maximumWidth: parent.width
                    Layout.maximumHeight: parent.height/9
                    Layout.alignment: Qt.AlignBottom
                    RowLayout{
                        anchors.fill: parent
                        MyButton{
                            myFillHeight: true
                            myFillWidth: true
                            myText: "Proceed To Cancel"
                            fontSize: 18
                            onMyClick:{
                                console.log("SevaCancelReceipt :: Cancel clicked")
                                _confirmationDialog.open();

                            }
                        }
                        MyButton{
                            myFillHeight: true
                            myFillWidth: true
                            myText: "Back"
                            fontSize: 18
                            onMyClick: {
                                root.visible = false
                            }
                        }
                    }
                }
            }
        }
    }

    DisplayDialog {
        id :_confirmationDialog
        visible: false
        text2Display: "Confirm cancelling the receipt."
        onYesAction: {
            console.log("SevaCancelReceipt : yes clicked")
            sevaReceiptcancelClicked(sevaProxy.mysevacancelmodel.totalAmount)
            sevaProxy.setStatusToCancel(sevaProxy.mysevacancelmodel.sevaReceiptNumber)
            _confirmationDialog.close()
            root.visible = false
        }
        onNoAction: {
            console.log("SevaCancelReceipt : No clicked")
            _confirmationDialog.close()
        }
    }
    Component.onCompleted: {
        console.log("SevaCancelReceipt is created");
    }
}
