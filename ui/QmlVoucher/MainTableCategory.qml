import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Rectangle{
    id:rect1
    color: "#FFFFFF"
    border.color:"black"
    border.width: 2
    signal myTableClicked();
    signal refresh();

    Component.onCompleted:
    {
        console.log("Clicked MainTable.qml");
        tv.currentRow=0;
        tv.selection.select(tv.currentRow);
        voucherProxy.loadTbViewInProxy();
        voucherProxy.voucherHeadsTableModel.rowClicked(0);
        voucherProxy.proxyList();
        myTableClicked()
    }

    ColumnLayout{
        anchors.fill: parent
        TableView{
            id:tv
            anchors.fill: parent
            onClicked:
            {
                console.log("Row CLicked="+row);
                voucherProxy.voucherHeadsTableModel.rowClicked(row);
                voucherProxy.listAppendProxy();
                refresh();
            }
            headerDelegate: MyHeaderDelegate{}
            rowDelegate: MyRowDelegate{}

            TableViewColumn{
                role:"serial"
                title: "SL.NO"
                width:rect1.width/3
                delegate: MyTextDelegate{}
            }
            TableViewColumn
            {
                role:"vid"
                title: "CATEGORY ID"
                width:rect1.width/3
                delegate: MyTextDelegate{}

            }
            TableViewColumn
            {
                role:"vcategory"
                title: "CATEGORY NAME"
                width:rect1.width/3
                delegate: MyTextDelegate{}

            }
            model:voucherProxy.voucherHeadsTableModel
        }
    }
    Connections
    {
        target:voucherProxy
        onVouchToQml:
        {
            console.log("serial id ="+a_serial_no);
            console.log("Category id ="+a_voucherId);
            console.log("voucher name="+a_vouch_name);
            voucherProxy.send_Voucher(a_voucherId);
            voucherProxy.clearProxy();

        }
    }
}
