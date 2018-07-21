#include <QString>
#include <QtTest>

class QFugaTest : public QObject
{
    Q_OBJECT

public:
    QFugaTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void testCase1();
    void testCase2();
};

QFugaTest::QFugaTest()
{
}

void QFugaTest::initTestCase()
{
}

void QFugaTest::cleanupTestCase()
{
}

void QFugaTest::init()
{
}

void QFugaTest::cleanup()
{
}

void QFugaTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void QFugaTest::testCase2()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(QFugaTest)

#include "tst_qfugatest.moc"
