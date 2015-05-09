#include <QtWidgets>
#include <QtTest/QtTest>

class UnitTest : public QObject
{
	Q_OBJECT

	private slots:

	void logTest();
	void lineEditTest();
	void sliderTest();
	void buttonTest();
	void tabTest();
};

void UnitTest::logTest(){			// tests log function that prints to a Qt text widget
	QPlainTextEdit textEdit;
	QString str = "hello world";
	textEdit.appendPlainText(str);
	QCOMPARE(textEdit.toPlainText(), QString("hello world"));
}

void UnitTest::lineEditTest(){		// tests entering a number into Qt lineEdit fields
	QLineEdit lineEdit;
	QTest::keyClicks(&lineEdit, "5");
	QCOMPARE(lineEdit.text(), QString("5"));
}

void UnitTest::sliderTest(){		// tests clicking on a slider and having its value change
	QSlider slider;

	QTest::mouseClick(&slider, Qt::LeftButton);
	QTest::mouseClick(&slider, Qt::LeftButton);
	QTest::mouseClick(&slider, Qt::LeftButton);		// click 5 times to get to the middle of the slider
	QTest::mouseClick(&slider, Qt::LeftButton);
	QTest::mouseClick(&slider, Qt::LeftButton);

	QCOMPARE(slider.value(), 50);
}

void UnitTest::buttonTest(){		// tests clicking a button
	QPushButton button;
	button.setCheckable(true);
	QTest::mouseClick(&button, Qt::LeftButton);
	QVERIFY(button.isChecked() == true);
	QTest::mouseClick(&button, Qt::LeftButton);
	QVERIFY(button.isChecked() == false);

}

void UnitTest::tabTest(){		// tests a tab widget
	QTabWidget tab;
	QWidget a, b;
	QCOMPARE(tab.addTab(&a, "a"), 0);
	QCOMPARE(tab.addTab(&b, "b"), 1);
}

QTEST_MAIN(UnitTest)
#include "unittest.moc"