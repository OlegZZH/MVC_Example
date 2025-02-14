import QtQuick
import QtQuick.Controls

Item {
    id: _item
    width: 647
    height: 700
    Button {
        id: button
        x: 220
        y: 517
        width: 207
        height: 91
        text: qsTr("Button")
        onClicked: {
            myController.buttonAction()
        }
    }

    Text {
        id: _text
        x: 106
        y: 167
        text: myModel.counter
        font.pixelSize: 47
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
