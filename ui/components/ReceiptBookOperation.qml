import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.15

Rectangle {
    width: 400
    height: 600
    color: "#f0f0f0"
    radius: 10
    border.color: "#d0d0d0"

    focus: true

    signal loadMenuPage()

    ColumnLayout {
        spacing: 10
        anchors.fill: parent
        anchors.margins: 10

        // Book ID Input
        Row{
            width: parent.width
            Text {
                width: parent.width * 0.5
                text: "Book ID:"
            }
            TextField {
                id: bookId
                width: parent.width * 0.5
                text : receiptBookManager.bookId;
                onTextChanged: receiptBook.bookId = text
                enabled: receiptBookManager.isFreshBook
            }
        }

        // Book Start No Input
        Row{
            width: parent.width
            Text {
                width: parent.width * 0.5
                text: "Book Start No:"
            }
            TextField {
                id: bookStartNo
                width: parent.width * 0.5
                text : receiptBookManager.startReceiptNumber
                onTextChanged: receiptBook.bookStartNo = parseInt(text)
                enabled: receiptBookManager.isFreshBook
            }
        }

        // Receipt End No Input
        Row{
            width: parent.width
            Text {
                width: parent.width * 0.5
                text: "Receipt End No:"
            }
            TextField {
                id: receiptEndNo
                width: parent.width * 0.5
                text : receiptBookManager.endReceiptNumber
                onTextChanged: receiptBook.receiptEndNo = parseInt(text)
                enabled: receiptBookManager.isFreshBook
            }
        }

        // Current Receipt No Input
        Row{
            width: parent.width
            Text {
                width: parent.width * 0.5
                text: "Current Receipt No:"
            }
            TextField {
                id: currentReceiptNo
                width: parent.width * 0.5
                text :receiptBookManager.startReceiptNumber
                onTextChanged: receiptBook.currentReceiptNo = parseInt(text)
                enabled: receiptBookManager.isFreshBook
            }
        }

        // Book Created By Input
        Row{
            width: parent.width
            Text {
                width: parent.width * 0.5
                text: "Book Created By:"
            }
            TextField {
                id: bookCreatedBy
                width: parent.width * 0.5
                onTextChanged: receiptBook.bookCreatedBy = text
            }
        }

        // Creation Date (Disabled)
        Row {
            width: parent.width
            Text {
                width: parent.width * 0.5
                text: "Creation Date:"
            }
            TextField {
                width: parent.width * 0.5
                text: receiptBook.creationDate.toString("dd/MM/yyyy")
                enabled: false
            }
        }

        // Closing Date Input
        Row {
            width: parent.width
            Text {
                width: parent.width * 0.5
                text: "Closing Date:"
            }
            TextField {
                id: closingDate
                width: parent.width * 0.5
                text: receiptBook.closingDate.toString("dd/MM/yyyy")
                enabled: false
            }
        }

        // Open Date Input
        Row{
            width: parent.width
            Text {
                width: parent.width * 0.5
                text: "Open Date:"
            }
            TextField {
                id: openDate
                width: parent.width * 0.5
                text: receiptBook.openDate.toString("dd/MM/yyyy")
                enabled: false
            }
        }

        Row{
            spacing: 10
            width: parent.width

            Rectangle {
                width: 150
                height: 50
                color: "green"

                Text {
                    anchors.fill: parent
                    text: "SUBMIT"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        receiptBook.print();
                        console.log(receiptBook);
                        addReceiptBook();
                    }
                }
            }

            Rectangle {
                width: 150
                height: 50
                color: "red"

                Text {
                    anchors.fill: parent
                    text: "UPDATE"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        receiptBook.print();
                        receiptBookManager.updateBook(receiptBook);
                    }
                }
            }

            Rectangle {
                width: 150
                height: 50
                color: "blue"

                Text {
                    anchors.fill: parent
                    text: "Next Receipt No"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        receiptBookManager.getNextReceiptNumber();
                    }
                }
            }
        }
    }

    function addReceiptBook() {
         receiptBook.bookId = bookId.text
         receiptBook.bookStartNo = bookStartNo.text
         receiptBook.receiptEndNo = receiptEndNo.text
         receiptBook.currentReceiptNo = currentReceiptNo.text
         receiptBookManager.addBook(receiptBook);
    }

    Keys.onEscapePressed: {
        console.log("Esc pressed in receipt book page")
        loadMenuPage()
    }
}
