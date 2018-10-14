#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include "fizzbuzz.h"
#include "monitor1.h"
#include "monitor2.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FizzBuzz fizzBuzz;
    Monitor1 monitor1;
    Monitor2 monitor2;

    // 1. SIGNALマクロ, SLOTマクロによるコネクト
    //--------------------------------------------------------------------------
    // SIGNALマクロ、SLOTマクロで、"()"を忘れないように注意
    // シグナルとスロットは実行時に解決されるため、誤ったシグナル名、スロット名を指定した場合でもコンパイルエラーにはならない
    // QML側と接続する場合は、この形式でコネクトする必要がある
    QObject::connect( &fizzBuzz, SIGNAL( fizz() ), &monitor1, SLOT( fizzMonitor() ) );  // 引数なし
    QObject::connect( &fizzBuzz, SIGNAL( valueChanged(int) ), &monitor1, SLOT( outputValue(int) ) );  // 引数あり

    // 2. 関数オブジェクトによるコネクト
    //--------------------------------------------------------------------------
    // スロットメソッドに"slots"指定は不要
    QObject::connect( &fizzBuzz, &FizzBuzz::fizz, &monitor2, &Monitor2::fizzMonitor );  // 引数なし
    QObject::connect( &fizzBuzz, &FizzBuzz::valueChanged, &monitor2, &Monitor2::outputValue );  // 引数あり

    // 3. ラムダ式によるコネクト
    //--------------------------------------------------------------------------
    // スロットメソッドに"slots"指定は不要
    QObject::connect( &fizzBuzz, &FizzBuzz::fizz, &monitor2, [&monitor2]{ monitor2.fizzMonitor(); } );  // 引数なし
    QObject::connect( &fizzBuzz, &FizzBuzz::valueChanged, &monitor2, [&monitor2](int x){ monitor2.outputValue( x ); } );  // 引数あり

    for ( int i = 0; i < 20; ++i )
    {
        qDebug() << "---";
        fizzBuzz.next();
    }

    return a.exec();
}
