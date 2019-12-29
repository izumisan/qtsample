#include <QtTest>
#include "fizzbuzz.h"

class BarTest : public QObject
{
    Q_OBJECT

public:
    BarTest();
    ~BarTest();

private slots:
    void fizz_buzz_test_case_5();

};

BarTest::BarTest()
{
}

BarTest::~BarTest()
{
}

void BarTest::fizz_buzz_test_case_5()
{
    QCOMPARE( FizzBuzz::fizzBuzz( 5 ), "Buzz" );
}

QTEST_APPLESS_MAIN(BarTest)

#include "tst_bartest.moc"
