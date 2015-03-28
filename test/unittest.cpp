#include <QtTest/QtTest>

class UnitTest : public QObject
{
	Q_OBJECT
	private slots:
	void toUpper();
	void algebra();
};

void UnitTest::toUpper()
{
	QString str = "Hello";
	QVERIFY(str.toUpper() == "HELLO");
}

void UnitTest::algebra(){
	int x = 0;
	int a = 1;
	QVERIFY(x == 0);
	QVERIFY(a == 1);
}

QTEST_MAIN(UnitTest)
#include "unittest.moc"