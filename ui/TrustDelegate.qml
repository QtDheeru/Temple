import QtQuick 2.12
import "./components"
Rectangle
{
    id:trustDelegateRect
    height:win.height/8
    width:win.width/6
    color: "#00ffff"
    property alias trustDelegate: trustDelegateRect
    property int idx;
   signal loadLoginPage();
    Text{
        id:trustText
        anchors.centerIn:parent
        text: TrustName
        font.pixelSize: parent.height/5
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log("clicked "+trustText.text)
            console.log(" clicked -- "+TrustCode + "code = " );
            trustListModel.trustCodeForConfig = TrustCode;
            trustListModel.trustCodeForData = TrustCode;
            trustListModel.currentTrust = TrustName;
            console.log("index clicked --"+index);
            var str1 = trustListModel.getConfigLocation();
            var str2 =trustListModel.getDataLocation();
            console.log("str1 = --"+str1);
            console.log("str2 = --"+str2);
           // loadTrustQml(trustText.text,TrustCode,index);
           loadLoginPage();
        }
    }
}
