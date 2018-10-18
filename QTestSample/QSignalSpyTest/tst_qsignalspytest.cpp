#include <QString>
#include <QSignalSpy>
#include <QtTest>

#include "fizzbuzz.h"

class QSignalSpyTest : public QObject
{
    Q_OBJECT

public:
    QSignalSpyTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void fizz_signal_test_data();
    void fizz_signal_test();

    void should_be_sent_buzz_signal();
};

QSignalSpyTest::QSignalSpyTest()
{
}

void QSignalSpyTest::initTestCase()
{
}

void QSignalSpyTest::cleanupTestCase()
{
}

void QSignalSpyTest::init()
{
}

void QSignalSpyTest::cleanup()
{
}
//------------------------------------------------------------------------------
/*!
*/
void QSignalSpyTest::fizz_signal_test_data()
{
    QTest::addColumn<int>("_input");
    QTest::addColumn<bool>("_expected");
    QTest::newRow("test:3") << 3 << true;
    QTest::newRow("test:4") << 4 << false;
    QTest::newRow("test:5") << 5 << false;
    QTest::newRow("test:6") << 6 << true;
    QTest::newRow("test:15") << 15 << false;
}
//---
void QSignalSpyTest::fizz_signal_test()
{
    QFETCH( int, _input );
    QFETCH( bool, _expected );

    auto* fizzBuzz = new FizzBuzz();

    QSignalSpy spy( fizzBuzz, SIGNAL( fizz() ) );  // fizzシグナルリスナー

    fizzBuzz->exec( _input );

    bool emitted = spy.count() != 0;

    //QCOMPARE( spy.isValid(), _expected );
    QCOMPARE( emitted, _expected );
}
//------------------------------------------------------------------------------
/*!
*/
void QSignalSpyTest::should_be_sent_buzz_signal()
{
    auto* fizzBuzz = new FizzBuzz();

    QSignalSpy spy( fizzBuzz, &FizzBuzz::buzz );  // buzzシグナルリスナー

    for ( int i = 0; i < 30; ++i )
    {
        fizzBuzz->exec( i );
    }

    QCOMPARE( spy.count(), 4 );  // 5, 10, 20, 25
}

QTEST_APPLESS_MAIN(QSignalSpyTest)

#include "tst_qsignalspytest.moc"
