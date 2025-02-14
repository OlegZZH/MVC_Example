// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: window
    width: 647
    height: 700
    visible: true
    title: "Example"

    TabBar {
        id: bar
        width: parent.width
        TabButton {
            text: qsTr("Page1")
        }

        TabButton {
            text: qsTr("Page2")
        }
    }
    StackLayout {
        width: parent.width
        currentIndex: bar.currentIndex
        My_item {
            id: page1
        }
        My_item {
            id: page2
            Text {
                id: buttonActionLabel
                text: myModel.decrementEnabled ? "-1" : "+1"
                anchors.bottom: changeBehaviorButton.top
                anchors.bottomMargin: 20
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Button {
                id: changeBehaviorButton
                text: qsTr("Change Behavior")
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 200
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    myController.changeBehavior()
                }
            }
        }
    }
}
