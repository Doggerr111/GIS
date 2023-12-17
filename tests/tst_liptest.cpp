#include <QtTest>

// add necessary includes here

int main(int argc, char *argv[])
{


    return 0;
}

class LIPVectorLayerTest : public QObject
{
    Q_OBJECT

public:
    LIPVectorLayerTest();
    ~LIPVectorLayerTest();

private slots:
    void test_case1();

};

LIPVectorLayerTest::LIPVectorLayerTest()
{

}

LIPVectorLayerTest::~LIPVectorLayerTest()
{

}

void LIPVectorLayerTest::test_case1()
{

}

QTEST_APPLESS_MAIN(LIPVectorLayerTest)

#include "tst_liptest.moc"
