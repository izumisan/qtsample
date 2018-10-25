.pragma library  // ステートレスライブラリ（エレメント間で共有される）

var count = 0

function next() {
    ++count
    return count
}
