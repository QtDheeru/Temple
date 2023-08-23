import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

ColumnLayout
{
    signal myClear();
    id: _col1
    anchors.fill: parent
    anchors.centerIn: parent
    property bool checkBoxCheckedOrNot: false
//    opacity: dialog2.visible ? 0.3 : 1.0 & dialog.visible ? 0.3 : 1.0

    Rectangle{
        id: _rec1
//        Layout.fillWidth: parent
//        anchors.top: parent.top
//        height: 100
        Layout.alignment: Qt.AlignTop
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.maximumHeight: 100
        color: "lightblue"
        Text {
            text: "CHEQUE LIST"
            font.pixelSize: 40
            anchors.centerIn: parent
            font.bold: true
        }
    }


    Rectangle
    {
        id: _rec2
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.maximumHeight:500
        Layout.maximumWidth:800
        Layout.minimumWidth: 100
        Layout.minimumHeight: 100
//        width: parent.width / 1.2
//        height: parent.height /2
        anchors.centerIn: parent
        color:  "lightgrey"

        Rectangle{id:_rect1
            width: parent.width
            height: parent.height / 1.5
            color: "orange"
            CheckListTable
            {
                id: _check_List_Table
                anchors.fill: parent
            }
        }
        Rectangle
        {
            anchors.top:_rect1.bottom
            color:  "lightblue"
            width: parent.width
            height: parent.height / 3

            GridLayout{
                columns:2
                columnSpacing:40
                anchors.centerIn: parent
                Label{
                    text: "Person :"
                    font.pixelSize:17
                    font.bold: true
                    color:"black"
                }

                TextField{
                    id:_person
                    font.pixelSize:13
                    Layout.maximumWidth:220
                    placeholderTextColor:"gray"
                    placeholderText: "Enter Person Name"
                    color:"black"
                    focus: true
                    activeFocusOnTab :true
                    background: Rectangle {
                        color: "lightblue"
                    }
                    UnderLine{
                    }
                }
                Label{
                    text: "Notes :"
                    font.pixelSize:17
                    font.bold: true
                    color:"black"
                }

                TextField{
                    id:_notes
                    font.pixelSize:13
                    Layout.maximumWidth:220
                    placeholderTextColor:"gray"
                    placeholderText: "Enter Your Notes"
                    color:"black"
                    focus: true
                    activeFocusOnTab :true
                    background: Rectangle {
                        color: "lightblue"
                    }
                    UnderLine{

                    }
                }
            }
        }

    }

    RowLayout{
        Layout.alignment: Qt.AlignBottom
        Button{
            id:submit
            text:"Submit To Bank"
            Layout.preferredWidth:300
            Layout.fillWidth:true
            Layout.preferredHeight:100
            font.pixelSize:30
            font.bold: true
            background:Rectangle{
                color:"lightblue"
                radius: 30
                MouseArea{
                    hoverEnabled: true
                    anchors.fill: parent
                    onEntered: parent.color = "#4d99db"
                    onExited: parent.color = "lightBlue"
                    onClicked: {myClear()
                        if(checkBoxCheckedOrNot){
                            checkEntry.submitToBank()
                            checkBoxCheckedOrNot = false
                        }
                        else{
                            dialog2.visible = true
                        }

                    }
                }
            }
        }
        Button{
            id:clear
            text:"Clear"
            font.pixelSize:30
            Layout.preferredWidth:300
            Layout.fillWidth:true
            Layout.preferredHeight:100
            font.bold: true
            background:Rectangle{
                color:"lightblue"
                radius: 30
                MouseArea{
                    hoverEnabled: true
                    anchors.fill: parent
                    onEntered: parent.color = "#4d99db"
                    onExited: parent.color = "lightBlue"
                    onClicked:{ myClear()
                        checkBoxCheckedOrNot = false
                        checkEntry.emptyList()
                    }
                }
            }
        }
    }
    DialogMyBox
    {
        id: dialog
        dTxt: "Selected Items Added to DataBase"
        anchors.centerIn: parent

    }
    DialogMyBox
    {
        id: dialog2
        dTxt: "Select any one"
        anchors.centerIn: parent
    }
    Connections{
        target: _check_List_Table
        onClickedCheckedBox:{
            console.log("Checkbox Clicked in table")
            checkBoxCheckedOrNot = true
        }
    }
    Connections
    {
        target: checkEntry
        onAddedToDataBase:{
            dialog.visible = true
        }
    }
}
