import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

ColumnLayout{
    property string typetransaction:"credit"
    property var selectedOption
    DialogMyBox{
        id:dlog
        anchors.centerIn: parent
        visible: false
    }
    Rectangle {
        Layout.alignment: Qt.AlignTop
        color: "lightblue"
        Layout.fillWidth:true
        Layout.minimumHeight:parent.height/10
        Text {
            anchors.centerIn: parent
            text: "CASH ENTRY"
            font.pixelSize:(parent.width+parent.height)/25
            font.bold: true
            color:"black"
        }
    }
    GridLayout{
        id:grid
        columns:1
        rowSpacing:parent.height/30
        Layout.alignment:Qt.AlignCenter

        MyLabelText{
            id:datetext
            labeltext: "Date :"
            textField: Qt.formatDateTime(cale.selectedDate, "dd-MM-yyyy")
            calender: true
            navigate: receipt
            space:parent.width/2.97
        }
        MyLabelText{
            id:receipt
            labeltext: "Last Receipt :"
            textField:myModel.receiptNumber
            navigate: cashinhand
            space:parent.width/6.22
        }
        MyLabelText{
            id:cashinhand
            labeltext: "Cash In Hand :"
            textField:myModel.cashInHand
            navigate:tobank
            space: parent.width/6.73
        }
        MyLabelText{
            id:tobank
            labeltext: "Cash To Bank :"
            navigate:person
            space:parent.width/6.9
            inputType:  Qt.ImhDigitsOnly
            validate: IntValidator {
                bottom: 0
                top: 9999999
            }
        }
        RowLayout{
            spacing:parent.width/20.55
            Label{
                text: "Transaction Type :"
                font.pixelSize:20
                font.bold: true
                color:"black"
            }
            RowLayout{
                RadioButton{
                    id:debit
                    text: "Credit"
                    font.pixelSize:20
                    checked: true
                    onClicked: {
                        typetransaction="credit"
                    }
                    UnderLine{
                    }
                }
                RadioButton{
                    id:credit
                    text: "Debit"
                    font.pixelSize:20
                    onClicked: {
                        typetransaction="debit"
                    }
                }
            }
        }
        RowLayout{
            spacing:parent.width/3.09
            Label{
                text: "Bank :"
                font.pixelSize:20
                font.bold: true
                color:"black"
            }
            ComboBox{
                id:bank
                Layout.minimumWidth:220
                font.pixelSize:20
                model: myModel.banksList
                selectTextByMouse: true
                onCurrentIndexChanged: {
                    selectedOption = bank.textAt(currentIndex)
                    console.log("Selected item:", selectedOption)
                }
                UnderLine{
                }
            }
        }
        MyLabelText{
            id:person
            labeltext: "Person :"
            navigate:notes
            space:parent.width/3.63
        }
        MyLabelText{
            id:notes
            labeltext: "Notes :"
            space:parent.width/3.34
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
                radius:30
                color:"lightblue"
                MouseArea{
                    anchors.fill: parent
                    onEntered: parent.color = "white"
                    onExited: parent.color = "lightBlue"
                    onClicked: {
                        console.log("submit cashentry clicked")
                        myModel.dataFromQml(datetext.textField,receipt.textField,cashinhand.textField,tobank.textField.toString(),typetransaction,selectedOption,person.textField,notes.textField)
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
                radius:30
                color:"lightblue"
                MouseArea{
                    anchors.fill: parent
                    onEntered: parent.color = "white"
                    onExited: parent.color = "lightBlue"
                    onClicked: {
                        person.text.clear()
                        notes.text.clear()
                        tobank.text.clear()
                    }
                }
            }
        }
    }
    Connections{
        target: myModel
        onToBankEmpty:{
            dlog.visible=true
            dlog.dTxt="Cash To Bank is Empty"
            setImageForFail()

        }
        onLowBalance:{
            dlog.visible=true
            dlog.dTxt="Cash In Hand Is Low"
            setImageForFail()
        }
        onAddedData:{
            dlog.visible=true
            dlog.dTxt="Cash Entry Successfull"
            setImageForSuccess()
        }
    }
    function setImageForSuccess(){
        dlog.dImage="qrc:/Images/good.png"
    }
    function setImageForFail(){
        dlog.dImage="qrc:/Images/fail.png"
    }
}


