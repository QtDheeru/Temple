import QtQuick 2.14
import QtQuick.Controls 2.5

Rectangle {
    id: root
    anchors.fill: parent
    color: "#F4C430"
    TableView {
        anchors.fill: parent
//        TableViewColumn {title: "NewFlag"; role: "NewFlag"; width: 70 }
//        TableViewColumn {title: "Title"; role: "Title"; width: 70   }
//        TableViewColumn {title: "Time"; role: "Time"; width: 70 }
//        TableViewColumn {title: "ImageSouce"; role: "ImageSouce"; width: 70   }
//        TableViewColumn {title: "TrendNum"; role: "TrendNum"; width: 70 }
//        TableViewColumn {title: "TrendUp"; role: "TrendUp"; width: 70   }
//        TableViewColumn {title: "Singer"; role: "Singer"; width: 70 }
        model: tablemodel
    }
}

