import Qt3D.Render 2.0

// カスタムの図形を描画する
GeometryRenderer {
    id: root
    // 描画の方法を選ぶ（今回は線で描画）
    primitiveType: GeometryRenderer.Lines

    // 頂点データのバッファ。今回は頂点データ(x, y, z)のみ。色は法線、インデックスなど混在させることもできます
    Buffer {
        id: vertexBuffer
        type: Buffer.VertexBuffer
        data: createGeometry()
    }

    geometry: Geometry{
        Attribute{
            name: defaultPositionAttributeName
            attributeType: Attribute.VertexAttribute
            vertexBaseType: Attribute.Float
            vertexSize: 3     // x, y, z
            byteOffset: 0
            byteStride: 3 * 4 // (x, y, z) * sizeof(float)
            count: 24         // 頂点座標の数
            buffer: vertexBuffer
        }
    }

    // 頂点座標のデータを用意します
    function createGeometry() {
        var array = [
                 // x,  y,  z
                    1,  1,  1,
                    1,  1, -1,
                   -1,  1,  1,
                   -1,  1, -1,

                    1, -1,  1,
                    1, -1, -1,
                   -1, -1,  1,
                   -1, -1, -1,

                    1,  1,  1,
                   -1,  1,  1,
                    1,  1, -1,
                   -1,  1, -1,

                    1, -1,  1,
                   -1, -1,  1,
                    1, -1, -1,
                   -1, -1, -1,

                    1,  1,  1,
                    1, -1,  1,
                    1,  1, -1,
                    1, -1, -1,

                   -1,  1,  1,
                   -1, -1,  1,
                   -1,  1, -1,
                   -1, -1, -1,
                ];

        var position = new Float32Array(array.length);
        for (var i=0; i<array.length; i++) {
            position[i] = array[i];
        }
        return position;
    }
}
