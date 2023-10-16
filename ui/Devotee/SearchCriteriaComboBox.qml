import QtQuick 2.0

import QtQuick.Controls 2.5
import QtQml.Models 2.15

ComboBox {
    font.pixelSize: 20
    width: 200
    model: ListModel {
        id: model
        ListElement { text: "D-ID" }
        ListElement { text: "Devotee Name" }
        ListElement { text: "Mobile Number" }
        ListElement { text: "Gothra" }
        ListElement { text: "Nakshatra" }
    }
}
