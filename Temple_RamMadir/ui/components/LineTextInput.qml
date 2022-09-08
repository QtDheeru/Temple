import QtQuick 2.14

FocusScope{
    id : _root
    width: parent.width;height: 50
    property alias text : _ti.text
    property alias editable : _ti.enabled
    property bool  isDataExist : _ti.text !== "";
    property alias regExpValidator: _ti.validator
    signal editComplete();
    TextInput{
        id:_ti;
        width: parent.width;
        height: _ti.contentHeight
        font.pixelSize: fontPixelSize
        anchors.bottom: _line.top
        anchors.bottomMargin: 2
        verticalAlignment: TextInput.AlignBottom
        focus: true
        color: "blue"
        clip: true
        opacity: text.indexOf("Enter") != 0 ? 0.5 :1
        validator: regExpValidator
        wrapMode: Text.WordWrap
        onEditingFinished: {
            console.log(" LineTxt Input Edit is complete")
            editComplete();
        }
        onFocusChanged: {
            console.log("Focuse chnaged from text input")
        }
    }
    Rectangle{
        id : _line
        width:_root.width;height: 1;color: "green";
        anchors.bottom: _root.bottom
    }
    function clearData(){
        _ti.clear();
    }
    Component.onCompleted: {
        _ti.ensureVisible(0)
    }
}
