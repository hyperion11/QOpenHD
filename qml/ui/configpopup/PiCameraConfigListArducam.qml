import QtQuick 2.15

ListModel {

    ListElement {
        name: "IMX477(und mini)"
        portrait: "../../resources/cameras/portrait.png"
        raspOverlay: "libcamera_imx477"
    }
    ListElement {
        name: "LowLight"
        portrait: "../../resources/cameras/portrait.png"
        raspOverlay: "libcamera_arducam"
    }
    ListElement {
        name: "IMX519"
        portrait: "../../resources/cameras/portrait.png"
        raspOverlay: "libcamera_imx519"
    }

}
