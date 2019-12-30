#include <QtTest>
#include "fizzbuzz.h"

class FooTest : public QObject
{
    Q_OBJECT

public:
    FooTest();
    ~FooTest();

private slots:
    void fizz_buzz_test_case_3();
};

FooTest::FooTest()
{
}

FooTest::~FooTest()
{
}

void FooTest::fizz_buzz_test_case_3()
{
    QCOMPARE( FizzBuzz::fizzBuzz( 3 ), "Fizz" );
}

QTEST_APPLESS_MAIN(FooTest)

#include "tst_footest.moc"
