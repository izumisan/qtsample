import Qt3D.Render 2.0

// カスタムの図形を描画する
GeometryRenderer {
    id: root
    property int idx

    // 描画の方法を選ぶ（今回は線で描画）
    primitiveType: GeometryRenderer.Lines

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
            byteStride: 6 * 4   // (x, y, z, R, G, B) * sizeof(float)
            count: root.idx
            buffer: vertexBuffer
        }

        Attribute{
            name: defaultColorAttributeName
            attributeType: Attribute.VertexAttribute
            vertexBaseType: Attribute.Float
            vertexSize: 3       // R, G, B
            byteOffset: 3 * 4   // 次のRGBデータまでのオフセット(x, y, zをスキップ)
            byteStride: 6 * 4   // (x, y, z, R, G, B) * sizeof(float)
            count: root.idx
            buffer: vertexBuffer
        }
    }

    // 頂点座標のデータを用意します
    function createGeometry() {
        var array = [
                    // x,  y,  z,   R,  G,  B
                       1,  1,  1,   1,  0,  0,
                       1,  1, -1,   1,  0,  0,
                       1,  1,  1,   1,  0,  0,
                      -1,  1,  1,   1,  0,  0,

                      -1,  1,  1,   1,  0,  0,
                      -1,  1, -1,   1,  0,  0,
                       1,  1, -1,   1,  0,  0,
                      -1,  1, -1,   1,  0,  0,

                       1, -1,  1,   0,  1,  0,
                       1, -1, -1,   0,  1,  0,
                       1, -1,  1,   0,  1,  0,
                      -1, -1,  1,   0,  1,  0,

                      -1, -1,  1,   0,  1,  0,
                      -1, -1, -1,   0,  1,  0,
                       1, -1, -1,   0,  1,  0,
                      -1, -1, -1,   0,  1,  0,

                       1,  1,  1,   0,  0,  1,
                       1, -1,  1,   0,  0,  1,
                      -1,  1,  1,   0,  0,  1,
                      -1, -1,  1,   0,  0,  1,

                      -1,  1, -1,   0,  0,  1,
                      -1, -1, -1,   0,  0,  1,
                       1,  1, -1,   0,  0,  1,
                       1, -1, -1,   0,  0,  1,
                   ];


        var position = new Float32Array(array.length);
        for (var i=0; i<array.length; i++) {
            position[i] = array[i];
        }
        return position;
    }
}
