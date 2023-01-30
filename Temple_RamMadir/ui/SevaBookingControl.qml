import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Rectangle {
    color: "lightBlue"
    property int fontSize : 25
    property alias startNextReceipt : _next.enabled
    signal startPayment();
    signal addMoreSeva();
    signal nextReceipt();
    signal clearReceipt();
    signal showAllData();
    signal errorOccur(string errorMsg);
    signal showLast10Transaction();
    property bool enablePaymentButton: false
    property alias nextButtonFocus:_next.focus
    GridLayout{
        anchors.fill: parent
        columns: 3
        Layout.fillWidth: true
        Button {
            id : _addMoreSevabutton
            width: 100
            Layout.minimumWidth: 100
            Layout.preferredWidth: 100
            Layout.fillWidth: true;
            Layout.fillHeight: true
            text : "Add Seva"
            Layout.maximumHeight: 40
            font.pixelSize: fontSize
            onClicked: {
                console.log(" Adding Seva")//SevaBookingControl.qml
                var s1 = selectedReceiptDate.split("-")
                var s2 = selectedSevaDate.split("-");
                if((s1[0]>s2[0])||(s1[1]>s2[1])||(s1[2]>s2[2]))
                {
                    errorOccur("select proper seva date");
                }
                else
                {
                    addMoreSeva()
                }
            }
        }
        Button {
            id:_payButton
            Layout.fillWidth: true;text : "Payment"
            Layout.maximumHeight: 40
            font.pixelSize: fontSize
            //enabled: false
            onClicked: {
                startPayment();
            }
        }
        Button {
            id : _next
            Layout.fillWidth: true;text : "Next"
            Layout.maximumHeight: 40
            font.pixelSize: fontSize
            onClicked: {
                nextReceipt();
            }
        }
        Button {
            id : _clear
            Layout.fillWidth: true;text : "Clear"
            Layout.maximumHeight: 40
            font.pixelSize: fontSize
            onClicked: {
                clearReceipt();
            }
        }
        Button {
            id : _showData
            Layout.fillWidth: true;text : "All Data"
            Layout.maximumHeight: 40
            font.pixelSize: fontSize
            onClicked: {
                console.log("show all button clicked")
                showAllData();
            }
        }
        Button {
            id : _last10Trans
            Layout.fillWidth: true;text : "Last Transaction"
            Layout.maximumHeight: 40
            font.pixelSize: fontSize
            enabled: false              //Not implemented
            onClicked: {
                showLast10Transaction()
            }
        }
    }
    function setButtons(val){
        //        _addMoreSevabutton.enabled = val
        //        _payButton.enabled = val
        //        _next.enabled = !val;
    }

    onEnablePaymentButtonChanged: {
        if (enablePaymentButton == true){
            state = "payOrAddSeva"
        }else {
            state = "initial"
        }
    }

    function bookingComplete(){
        state = "sevaBookCompleted"
    }

    function paymentComplete(){
        state = "paymentComplete"
    }

    function startNextBooking(){
        state = "next"
    }

    state : "initial"
    states:[
        State{
            name:"initial";
            PropertyChanges{target: _addMoreSevabutton;enabled : false}
            PropertyChanges{target: _payButton;enabled : true}
            PropertyChanges{target: _next;enabled : false}
        },
        State{
            name:"sevaBookCompleted";
            PropertyChanges{target: _addMoreSevabutton;enabled : false}
            PropertyChanges{target: _payButton;enabled : true}
            PropertyChanges{target: _next;enabled : true}
        },
        State{
            name:"payOrAddSeva";
            PropertyChanges{target: _addMoreSevabutton;enabled : true}
            PropertyChanges{target: _payButton;enabled : true}
            PropertyChanges{target: _next;enabled : false}
        },
        State{
            name:"next";
          /*  PropertyChanges{target: _addMoreSevabutton;enabled : true} revert if nece*/
            PropertyChanges{target: _addMoreSevabutton;enabled : false}
            PropertyChanges{target: _payButton;enabled : true}
            PropertyChanges{target: _next;enabled : false}
        },
        State{
            name:"paymentComplete";
            PropertyChanges{target: _addMoreSevabutton;enabled : false}
            PropertyChanges{target: _payButton;enabled : false}
            PropertyChanges{target: _next;enabled : true}
        }
    ]

}
