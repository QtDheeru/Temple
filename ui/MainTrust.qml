import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.5
import "./components"

Rectangle{
    id:win
    property var styles: MyStyles{}
    signal errorOccur(string errorMsg);
    width: styles.screenWidth
    height: styles.screenHeight
    visible: true
    focus: true
    color: styles.backgroundcolorOfApp
    // activeFocus: true
    signal loadTrustQml(var s1,var s2,var i3);
    property string trustName;
    property string trustCode;
    property string trustIndex;
    //property alias mainTrust: win
    signal loadWelcome();
    function abhishek(){
        console.log("abhishek");
        loadWelcome();
    }
    GridLayout{
        id:gridLayoutOfTrust
        height:parent.height/1.5
        width:parent.width/1.5
        focus: true
        columnSpacing: 5
        rowSpacing: 5
        rows: 4
        columns: 3
        anchors.centerIn: parent
        Repeater{
            id:r1
            model : trustListModel
            delegate : TrustDelegate{
                id: tstDel
                Component.onCompleted: {
                    tstDel.loadLoginPage.connect(abhishek)
                }
            }
            Component.onCompleted: {
                console.log("Repeater of Grid LayOut of Main Trust");
                if(trustListModel.getTrustListSize()===0)
                {
                    errorOccur("Trusts not present");
                }
            }
        }
    }
    Keys.onEscapePressed: {
        console.log("Escape pressed in Main Trust");
    }
    Component.onCompleted: {
        console.log(" Component.onCompleted:" + gridLayoutOfTrust.activeFocus);
    }
}

