import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import Utils 1.0

Popup{
    id:showDetailsPopup
    width: parent.width
    height: parent.height
//    color: "lightgray"

    ColumnLayout{
        spacing:10
        Row{
            spacing: 60
            Text {
                id:receipt
                text: qsTr("serialNo :")
                font.pixelSize: 20
            }
            TextField{
                id:receipttf
                font.pixelSize: 15
                width:200
                height:30
            }
        }
        Row{
            spacing: 105
            Text {
                id: t3
                text: "PersonID :"
                font.pixelSize: 20
            }
            TextField{
                id:datetf
                placeholderText: qsTr("PersonID")
                width:200
                height:30
            }
        }
        Row{
            spacing:55
            Text{
                id:t5
                text:"PersonDbID:"
                font.pixelSize: 20
            }
            TextField{
                id:sevanametf
                font.pixelSize: 15
                placeholderText: qsTr("PersonDbID");
                width:200
                height:30
            }
        }
        Row{
            spacing:95
            Text{
                id:t7
                text:"DevoteeName:"
                font.pixelSize: 20
            }
            TextField{
                id:mobiletf
                placeholderText: qsTr("DevoteeName")
                width:200
                height:30
            }
        }
        Row{
            spacing:95
            Text{
                id:t9
                text:"MobileNumber :"
                font.pixelSize: 20
            }
            TextField{
                id:nametf
                placeholderText: qsTr("MobileNumber")
                width:200
                height:30
            }
        }
        Row{
            spacing: 55
            Text{
                id:t10
                text:"Gothra :"
                font.pixelSize: 20
            }
            TextField{
                id:nakshatratf
                placeholderText: qsTr("Gothra")
                width:200
                height:30
            }
        }
        Row{
            spacing:95
            Text{
                text:"Nakshatra :"
                font.pixelSize: 20
            }
            TextField{
                id:gothratf
                placeholderText: qsTr("Nakshatra")
                width:200
                height:30
            }
        }
        Row{
            spacing:28
            Text{
                text:"SevaType :"
                font.pixelSize: 20
            }
            TextField{
                id:sevachargetf
                placeholderText: qsTr("SevaType")
                width:200
                height:30
            }
        }
        Row{
            spacing:90
            Text{
                text:"SevaName :"
                font.pixelSize: 20
            }
            TextField{
                id:counttf
                placeholderText: qsTr("SevaName")
                width:200
                height:30
            }
        }
        Row{
            spacing: 95
            Text{
                text:"Quantity :"
                font.pixelSize: 20
            }
            TextField{
                id:extratf
                placeholderText: qsTr("Quantity")
                width:200
                height:30
            }
        }
        Row{
            spacing:98
            Text{
                text:"ReceiptDate :"
                font.pixelSize: 20
            }
            TextField{
                id:cashtf
                placeholderText: qsTr("ReceiptDate")
                width:200
                height:30
            }
        }
        Row{
            spacing: 97
            Text{
                text:"SevaDate :"
                font.pixelSize: 20
            }
            TextField{
                id:banktf
                width:200
                height:30
                text: ""
                placeholderText: "SevaDate"
            }
        }
        Row{
            spacing:65
            Text{
                text:"TotalCost"
                font.pixelSize: 20
            }
            TextField{
                id:banklisttf
                width:200
                height:30
                text: ""
                placeholderText: "TotalCost"
            }
        }
        Row{
            spacing:55
            Text{
                text:"Cash"
                font.pixelSize: 20
            }
            TextField{
                id:sevadatetf
                placeholderText: qsTr("Cash")
                width:200
                height:30
            }
        }
        Row{
            spacing: 53
            Text{
                text:"Reference"
                font.pixelSize: 20
            }
            TextField{
                id:sevatimetf
                placeholderText: qsTr("Reference");
                width:200
                height:30
            }
        }
        Row{
            spacing:100
            Text{
                text:"Address"
                font.pixelSize: 20
            }
            TextField{
                id:notetf
                width:200
                height:30
                placeholderText: "Address"

            }
        }
        Row{
            spacing:100
            Text{
                text:"Momento"
                font.pixelSize: 20
            }
            TextField{
                id:moment
                width:200
                height:30
                placeholderText: "Momento"

            }
        }
        Row{
            spacing:100
            Text{
                text:"BookedBy"
                font.pixelSize: 20
            }
            TextField{
                id:bookedBy
                width:200
                height:30
                placeholderText: "BookedBy"

            }
        }
    }
    Button{
        id:_submitbutton
        anchors.left: parent.left
        anchors.leftMargin: 50
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        text:"Print"
        onClicked: {
            console.log("Print button Clicked")
            //sevaProxy.printReceipt()
            //sevaProxy.saveReceipt(_sevaReceipt);

        }
    }
    SevaReceipt{
        id : _sevaReceipt
    }
    Button{
        id:_AddButton
        anchors.left: _submitbutton.right
        anchors.leftMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        text:"Cancel"
        onClicked: {
            console.log("Cancel Clicked");
            showDetailsPopup.close()
        }
    }
}
