import QtQuick 2.0

import QtQuick.Controls 2.5
import QtQml.Models 2.15

ComboBox {
    font.pixelSize: 15
    width: 200
    model: ListModel {
        id: model
        ListElement { text: "Serial No" }
        ListElement { text: "Person ID" }
        ListElement { text: "Person DbID" }
        ListElement { text: "Devotee Name" }
        ListElement { text: "Mobile Number" }
        ListElement { text: "Gothra" }
        ListElement { text: "Nakshatra" }
        ListElement { text: "Seva Type" }
        ListElement { text: "Seva Name" }
        ListElement { text: "Quantity" }
        ListElement { text: "Receipt Date" }
        ListElement { text: "Seva Date" }
        ListElement { text: "Total Cost" }
        ListElement { text: "Cash" }
        ListElement { text: "Bank" }
        ListElement { text: "Reference" }
        ListElement { text: "Address" }
        ListElement { text: "Momento" }
        ListElement { text: "Booked By" }
    }
}
