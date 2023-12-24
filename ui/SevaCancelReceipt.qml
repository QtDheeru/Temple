import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import "./components"

Item {
    property real myTotalAmount :0
    signal backClicked()
    signal cancelClicked()

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
            width:parent.width/1.5
            height:parent.height/1.5
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

                    ListModel{
                        id:_model
                        ListElement{name:"Sam";txt:"1000"}
                        ListElement{name:"Mark";txt:"2000"}
                        ListElement{name:"Alen";txt:"3000"}
                        ListElement{name:"Alex";txt:"3000"}
                        ListElement{name:"Alex";txt:"1000"}
                    }

//                    function setAmount(){
//                        console.log("came inside")
//                        myTotalAmount = 0;
//                        for (var i = 0; i < _model.count; ++i) {
//                            if (_model.get(i).checked)
//                                myTotalAmount += parseInt(_model.get(i).txt);
//                        }
//                    }

                    ListView{
                        anchors.fill:parent
                        model: _model
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
                                                text: name
                                                color: "black"
                                                Layout.leftMargin: 10
                                                font{
                                                    pixelSize: 18
                                                    bold:true
                                                }
                                            }
                                            CheckBox {
                                                checked: model.checked
                                                Layout.alignment: Qt.AlignRight
                                                onClicked: {
                                                    model.checked = checked;
                                                    myTotalAmount += checked ? +parseInt(model.txt) : -parseInt(model.txt);
                                                }
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
                                            text: txt
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
                                text: myTotalAmount.toString()
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
                                cancelClicked()
                            }
                        }
                        MyButton{
                            myFillHeight: true
                            myFillWidth: true
                            myText: "Back"
                            fontSize: 18
                            onMyClick: {
                                backClicked()
                            }
                        }
                    }
                }
            }
        }
    }
}
