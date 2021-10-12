import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: view.currentItem.title

    Connections{
        target:yukleme
        function onYolGonder(yol){
            textField.text=yol
        }
        function onSureGonder(sure){
            progressBar.value=sure
            text4.text=sure
        }
    }

    SwipeView {
        id: view
        anchors.fill: parent



        Page {
            id: page
            title: qsTr("Basit FTP")

            Text {
                id: text1
                x: 309
                y: 211
                text: qsTr("Hoşgeldiniz!")
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 100
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.verticalCenterOffset: -77
                anchors.horizontalCenterOffset: 1
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: text2
                x: 303
                y: 208
                text: qsTr("Dosya Yüklemek İçin Sağa Kaydırınız! ---->")
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 30
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.verticalCenterOffset: 200
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.horizontalCenterOffset: 0
            }
        }

        Page {
            id: page1
            title: qsTr("Dosya Yükleme")

            Text {
                id: text3
                x: 12
                y: 135
                width: 194
                height: 36
                text: qsTr("Seçilen Dosya:")
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 30
            }

            TextField {
                id: textField
                x: 207
                y: 135
                width: 297
                height: 40
                anchors.verticalCenter: parent.verticalCenter
                placeholderText: qsTr("Seçilen Dosya Yolu")
            }

            Button {
                id: button
                x: 530
                y: 135
                text: qsTr("...")
                anchors.verticalCenter: parent.verticalCenter
                onClicked: fileDialog.open()
            }

            ProgressBar {
                id: progressBar
                y: 335
                height: 53
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: 100
                anchors.rightMargin: 100
                value: 0.0
                from:0
                to:100
            }

            FileDialog {
                id: fileDialog
                title: "Dosya Seç"
                folder: shortcuts.desktop
                onAccepted: {
                    yukleme.dosyaSec(fileDialog.fileUrls)
                }
                onRejected: {
                    console.log("Canceled")
                }
            }

            Button {
                id: button1
                x: 270
                y: 289
                text: qsTr("Yükle")
                onClicked: yukleme.dosyaYukle()
            }

            Text {
                id: text4
                x: 223
                y: 138
                width: 194
                height: 36
                text: qsTr("...")
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 10
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.verticalCenterOffset: 155
            }
        }


        Page {
            id: page2
            title: qsTr("Dosya İndirme")

            ListView {
                id: listView
                width: 110
                height: 346
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                clip: true
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 45
                model: myModel
                spacing: 10
                delegate: Item {
                    x:50
                    width: 110
                    height: 40
                    Row {
                        id: row1
                        Text {
                            text:"Dosya Adı: "+filesnameRole
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                            font.pixelSize: 20
                            MouseArea{
                                property int mouseButtonClicked: Qt.NoButton

                                id: mouseArea1
                                anchors.fill: parent
                                hoverEnabled: true
                                acceptedButtons: Qt.LeftButton | Qt.RightButton

                                onPressed: {
                                    if (pressedButtons & Qt.LeftButton) {
                                        mouseButtonClicked = Qt.LeftButton
                                    } else if (pressedButtons & Qt.RightButton) {
                                        mouseButtonClicked = Qt.RightButton
                                    }
                                }

                                onClicked: {

                                    if(mouseButtonClicked === Qt.RightButton){
                                        popup.open()
                                    }else if(mouseButtonClicked === Qt.LeftButton){

                                    }
                                }
                            }
                        }
                        Popup {
                            id: popup
                            width: 100
                            height: 40
                            modal: true
                            focus: true
                            anchors.centerIn: Overlay.overlay
                            closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
                            contentItem: Text {
                                text: "İndir"
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter

                                MouseArea{
                                    id:mouseArea2
                                    anchors.fill:parent
                                    onClicked: {
                                        indirme.sectin(filesnameRole)
                                        popup.close()
                                        messageDialog.open()
                                    }
                                }
                            }
                        }
                        MessageDialog {
                            id: messageDialog
                            title: "İndirme Başarılı!"
                            text: "Masaüstünüzü kontrol ediniz."
                        }
                    }
                }
            }

            Button {
                id: button2
                x: 270
                y: 405
                text: qsTr("Yenile")
                onClicked: myModel.modelGuncelle()
            }
        }

    }

}
