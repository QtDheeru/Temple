import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

TableView{
    id: _tb
    alternatingRowColors: false
    anchors.fill:  parent
    signal clickedCheckedBox()


    TableViewColumn{
        role: "receiptDate"
        title: "Receipt Date"

        width: parent.width/6
    }
    TableViewColumn{
        role: "checkDate"
        title: "Cheque Date"
        width: parent.width/6
    }
    TableViewColumn{
        role: "bank"
        title: "Bank Name"
        width: parent.width/6
    }
    TableViewColumn{
        role: "receiptNumber"
        title: "Receipt Number"
        width: parent.width/6
    }
    TableViewColumn{
        role: "anount"
        title: "Amount"
        width: parent.width/6
    }
    TableViewColumn{
        id: _tab
        title: "Selection"
        width: parent.width/6
        delegate: Rectangle{
            anchors.fill: parent
            color: styleData.selected ? "grey" : "white"

            Rectangle{
                height: 1
                width: parent.width
                anchors.bottom: parent.bottom
                color: "black"
            }
            CheckBox{id: _checkBox
                anchors.centerIn: parent
                onClicked: {
                    console.log(_checkBox)
                    if(checkedState){
                        console.log("CheckedRowNumber"+model.index)
                        checkEntry.addToList(model.index)
                        clickedCheckedBox()
                    }else{
                        console.log(model.index)
                        checkEntry.removeFromList(model.index)
                    }
                }
                Connections{
                    target: _col1
                    onMyClear:{
                        _checkBox.checked = false
                    }
                }
            }
        }
    }

    rowDelegate: customDelegate
    headerDelegate: _comp

    onClicked: {
        console.log("The id is "+ row )
        console.log("The Receipt date is "+ checkEntry.checklist[0].RECEIPTDATE )
    }

    model: checkEntry

    Component
    {
        id: _comp
        Item {
            width: parent.width
            height: 30

            Rectangle {
                anchors.fill: parent
                color: "lightblue"
                border.color: "lightgrey"
                border.width: 1
                Text
                {
                    text: styleData.value
                    font.bold: true
                    anchors.centerIn: parent
                    font.pixelSize: 16
                }
            }
        }
    }

    Component {
        id: customDelegate
        Rectangle{
            width: parent.width
            height: 40
            color: styleData.selected ? "grey" : "white"
            Rectangle{
                height: 1
                width: parent.width
                anchors.bottom: parent.bottom
                color: "black"
            }
            Text{id: _text
                anchors.centerIn: parent

            }
        }
    }
}
