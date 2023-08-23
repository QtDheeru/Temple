import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
Rectangle
{
    id: _rect2
    width: parent.width
    height:parent.height
    color:"white"
    border.color: "black"
    border.width: 1

    Loader
    {
        id:ld1
        width:parent.width
        height:parent.height

    }

    Component.onCompleted:
    {
        tv2.currentRow=0;
        tv2.selection.select(tv2.currentRow);
        voucherProxy.set_data(tv2.currentRow);
        ld1.source=""
        ld1.source="qrc:/ui/QmlVoucher/FinalDisplay.qml"
    }


    TableView
    {
        id:tv2
        width :parent.width
        height:parent.height
        backgroundVisible: false
        TableViewColumn
        {
            role: "Vsubid"
            title: "SUB CATEGORYID"
            width: _rect2.width/2
            delegate: MyTextDelegate{}

        }
        TableViewColumn
        {
            role: "Vscn"
            title: "SUB CATEGORY NAME"
            width: _rect2.width/2
            delegate: MyTextDelegate{}

        }
        rowDelegate: MyRowDelegate{}
        headerDelegate: MyHeaderDelegate{}
        onClicked:
        {
            console.log("The id is "+ row )
            voucherProxy.set_data(row);
        }

        model: voucherProxy.voucherSubHeadTableModel
    }
    Connections
    {
        target: voucherProxy
        onMy_update:
        {
            console.log("In updated_data function")
            ld1.source="";
            ld1.source="qrc:/ui/QmlVoucher/FinalDisplay.qml"
        }
    }

}
