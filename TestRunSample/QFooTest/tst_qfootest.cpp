#include <QString>
#include <QtTest>

class QFooTest : public QObject
{
    Q_OBJECT

public:
    QFooTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void testCase1();
    void testCase2();
};

QFooTest::QFooTest()
{
}

void QFooTest::initTestCase()
{
}

void QFooTest::cleanupTestCase()
{
}

void QFooTest::init()
{
}

void QFooTest::cleanup()
{
}

void QFooTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void QFooTest::testCase2()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(QFooTest)

#include "tst_qfootest.moc"
