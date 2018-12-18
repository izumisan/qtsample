import Qt3D.Core 2.0
import Qt3D.Input 2.0
import Qt3D.Render 2.0
import Qt3D.Extras 2.0

Entity {
    id: root

    //カメラの設定
    Camera {
        id: camera
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 45
        aspectRatio: 16 / 9
        nearPlane: 0.1
        farPlane : 1000.0
        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
        position: Qt.vector3d( 0.0, 3.0, 5.0 )
        viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 )
    }

    //カメラの移動方法を指定
    OrbitCameraController {
        camera: camera
    }

    components: [
        //描画のための設定
        RenderSettings {
            activeFrameGraph: ForwardRenderer {
                // 背景は白
                clearColor: Qt.rgba(1.0, 1.0, 1.0, 1.0)
                camera: camera
            }
        },
        //[4]　マウス等の入力のための設定
        //@@@ マウス、キーボード操作による移動、拡大・縮小が可能となる
        InputSettings {}
    ]

    //3D モデルを読み込む
//    Mesh {
//        id: object
//        //@@@ teapot.objは下記からダウンロード
//        //@@@ http://inst.eecs.berkeley.edu/~cs184/sp09/assignments/teapot.obj
//        source: "qrc:///teapot.obj"
//    }
    Cube {
        id: object
    }

    //3D モデルの表面の質感を指定
    PhongMaterial {
        id: material
    }

    Entity {
        components: [ object, material ]
    }
}
