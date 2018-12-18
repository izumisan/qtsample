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
        // 上をx, y, zのどれにするかを指定します
        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
        // カメラの位置を指定します
        position: Qt.vector3d( 0.0, 5.0, 8.0 )
        //　3D データの中心点が底面であり、ちょっとだけ画面上側に描画されるので位置調整
        viewCenter: Qt.vector3d( 0.0, 1.0, 0.0 )
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
    Mesh {
        id: object
        //@@@ teapot.objは下記からダウンロード
        //@@@ http://inst.eecs.berkeley.edu/~cs184/sp09/assignments/teapot.obj
        source: "qrc:///teapot.obj"
    }

    //3D モデルの表面の質感を指定
    PhongMaterial {
        id: material
        diffuse: "lightgreen"
        ambient: "green"
    }

    Entity {
        components: [ object, material ]
    }
}
