#include <QString>
#include <QtTest>
#include <QDebug>
#include <QThread>

class SampleTest : public QObject
{
    Q_OBJECT

public:
    SampleTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void fooTest();

    void fugaTest_data();
    void fugaTest();

    void benchMarkTest_data();
    void benchMarkTest();
};

SampleTest::SampleTest()
{
    qDebug() << "ctor";
}

void SampleTest::initTestCase()
{
    qDebug() << "initTestCase";
}

void SampleTest::cleanupTestCase()
{
    qDebug() << "cleanupTestCase";
}

void SampleTest::init()
{
    qDebug() << "init";
}

void SampleTest::cleanup()
{
    qDebug() << "cleanup";
}
//------------------------------------------------------------------------------
/*!
  @brief  fooテスト
*/
void SampleTest::fooTest()
{
    qDebug() << QTest::currentTestFunction();

    QVERIFY2( true, "Failure fooTest" );
}
//------------------------------------------------------------------------------
/*!
  @brief  fugaテストデータ
*/
void SampleTest::fugaTest_data()
{
    QTest::addColumn<double>("input");
    QTest::addColumn<double>("expected");
    QTest::newRow("test:0") << 0.0 << 0.0;
    QTest::newRow("test:1") << 1.0 << 1.0;
    QTest::newRow("test:2") << 2.0 << 4.0;
}
/*!
  @brief  fugaテスト
*/
void SampleTest::fugaTest()
{
    qDebug() << QTest::currentTestFunction() << QTest::currentDataTag();

    QFETCH( double, input );
    QFETCH( double, expected );

    double actual = input * input;

    QCOMPARE( actual, expected );
}
//------------------------------------------------------------------------------
/*!
  @brief  ベンチマークテストデータ
*/
void SampleTest::benchMarkTest_data()
{
    QTest::addColumn<int>( "data" );
    QTest::newRow("1msec") << 1;
    QTest::newRow("10msec") << 10;
    QTest::newRow("100msec") << 100;
    QTest::newRow("1sec") << 1000;
}
/*!
  @brief  ベンチマークテスト
*/
void SampleTest::benchMarkTest()
{
    qDebug() << QTest::currentTestFunction() << QTest::currentDataTag();

    QFETCH( int, data );

    QBENCHMARK
    {
        QThread::msleep( data );
    }

    QVERIFY2( true, "Failure benchMarkTest" );
}

QTEST_APPLESS_MAIN(SampleTest)

#include "tst_sampletest.moc"
