// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only
import QtQuick
import QtQuick.Controls

Window {
    id: window
    width: 647
    height: 700
    visible: true
    title: "Example"

    Button {
        id: button
        x: 220
        y: 517
        width: 207
        height: 91
        text: qsTr("Button")
        onClicked: {
            myController.incrementCounter()
        }
    }

    Text {
        id: _text
        y: 167
        text: myModel.counter
        font.pixelSize: 47
        anchors.horizontalCenter: parent.horizontalCenter
    }
    property int clickCounter: 0
}
