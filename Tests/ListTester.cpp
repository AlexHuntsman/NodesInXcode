/* ListTester.cpp
 *  Created on: Mar 2, 2016
 *  Author: cody.henrichsen
 */
#include "ListTester.h"
using namespace std;


ListTester::ListTester()
{
	cout << "Tester Loaded" << endl;
	passCount = 0;
	passMessage = "☜(ﾟヮﾟ☜) (◕‿◕✿) ಥ‿ಥ (❀◦‿◦)  ٩(^ᴗ^)۶ \n ┌(° ͜ʖ͡°)┘ (⁎❛ᴗ❛⁎) ( ͡ᵔ ͜ʖ ͡ᵔ ) ᕕ( ಠ‿ಠ)ᕗ (◡‿◡✿) \n ᕦ(ò_óˇ)ᕤ (•̀ᴗ•́)و (⁎⚈᷀᷁ᴗ⚈᷀᷁⁎) (☞ﾟヮﾟ)☞";
}

void ListTester::setUp()
{
	testIntList = new CTECList<int>();
	testStringList = new CTECList<string>();
}

void ListTester::tearDown()
{
	testIntList = nullptr;
	testStringList = nullptr;
}

void ListTester::allTests()
{
	cout << "Beginning all tests!" << endl;
	cout << "Have a nice day!" << endl;
	testConstructor();
	testSize();
	testAdds();
	testRemoves();
	testGets();
	testSet();
	if (passCount > 15)
	{
		for (int repeat = 0; repeat < passCount; repeat++)
		{
			cout << passMessage << endl;
		}
	}
	cout << "Your tests are finished! ٩(^ᴗ^)۶" << endl;
	cout << "You passed " << passCount << " tests"<< endl;
	cout << "Cheers!" << endl;

}

void ListTester::testConstructor()
{
	cout << "Beginning Constructor tests!" << endl;
	setUp();
	if (testIntList->getSize() == 0 && testStringList->getSize() == 0)
	{
		cout << "Constructor initialized size properly! ( ͡° ͜ʖ ͡°)" << endl;
		passCount++;
	}
	else
	{
		cout << " :( Constructor initialized size poorly ಠ_ಠ " << endl;
	}
	tearDown();
}

void ListTester::testAdds()
{
	cout << "Beginning Add tests!" << endl;
	setUp();
	testIntList->addToFront(7);
	testIntList->addToEnd(9);
	testIntList->addAtIndex(0, -230);
	if (testIntList->getFront() == -230)
	{
		cout << "The addAtIndex worked properly! ( ͡° ͜ʖ ͡°)" << endl;
		passCount++;
	}
	else
	{
		cout << "The addAtIndex did not work properly. ಠ_ಠ " << endl;
		cout << "-230 should have been at the front you have: " << testIntList->getFront() << endl;
	}
	tearDown();
	setUp();
	testStringList->addToEnd("this");
	testStringList->addToEnd("sequence");
	testStringList->addToEnd("of");
	testStringList->addToEnd("words");
	if (testStringList->getFront().compare("this") == 0)
	{
		cout << "The addToEnd worked properly! ( ͡° ͜ʖ ͡°)" << endl;
		passCount++;
	}
	else
	{
		cout << "The addToEnd did not work properly. ಠ_ಠ " << endl;
		cout << "'this' should have been at the front you have: " << testStringList->getFront() << endl;
	}
	tearDown();
	setUp();
	testStringList->addToFront("this");
	testStringList->addToFront("sequence");
	testStringList->addToFront("of");
	testStringList->addToFront("words");
	if (testStringList->getEnd().compare("this") == 0)
	{
		cout << "The addToFront worked properly! ( ͡° ͜ʖ ͡°)" << endl;
		passCount++;
	}
	else
	{
		cout << "The addToFront did not work properly. ಠ_ಠ " << endl;
		cout << "'this' should have been at the end you have: " << testStringList->getEnd() << endl;
	}

	tearDown();
}

void ListTester::testGets()
{
	cout << "Beginning Get tests!" << endl;
	setUp();
	testStringList->addToFront("this");
	testStringList->addToFront("sequence");
	testStringList->addToFront("of");
	testStringList->addToFront("words");
	if (testStringList->getEnd().compare("this") == 0)
	{
		cout << "Your getEnd() method works properly!" << endl;
		passCount++;
	}
	else
	{
		cout << "Your getEnd() method works poorly! 눈_눈" << endl;
		cout << "'this' should be at the end and you have " << testStringList->getEnd() << endl;
	}
	if (testStringList->getFront().compare("words") == 0)
	{
		cout << "Your getEnd() method works properly!" << endl;
		passCount++;
	}
	else
	{
		cout << "Your getFront() method works poorly! 눈_눈" << endl;
		cout << "'words' should be at the front and you have " << testStringList->getFront() << endl;

	}
	if (testStringList->getFromIndex(2).compare("sequence") == 0)
	{
		cout << "Your getEnd() method works properly!" << endl;
		passCount++;
	}
	else
	{
		cout << "Your getFromIndex(int) method works poorly! ಠ ∩ ಠ" << endl;
		cout << "'sequence' should be at the front and you have " << testStringList->getFromIndex(2) << endl;
	}
	tearDown();
}

void ListTester::testRemoves()
{
	cout << "Beginning Remove tests!" << endl;
	setUp();
	testIntList->addToFront(7);
	testIntList->addToEnd(9);
	testIntList->addAtIndex(0, -230);
	testIntList->addAtIndex(1, -290);
	testIntList->addAtIndex(2, -330);
	testIntList->addAtIndex(3, -3450);
	if (testIntList->removeFromEnd() == 9)
	{
		cout << "The removal of removeFromEnd worked properly! ( ͡° ͜ʖ ͡°)" << endl;
		passCount++;
	}
	else
	{
		cout << "The removal of removeFromEnd worked poorly) ಠ ∩ ಠ" << endl;
	}
	if (testIntList->getSize() == 5)
	{
		cout << "The size adjustment of removeFromEnd worked properly! ( ͡° ͜ʖ ͡°)" << endl;
		passCount++;
	}
	else
	{
		cout << "The size adjustment of removeFromEnd worked poorly) ಠ෴ಠ" << endl;
		cout << "The size should be 5 and is " << testIntList->getSize() << endl;
	}
	if (testIntList->removeFromFront() == -230)
	{
		cout << "The removal of removeFromFront worked properly! ( ͡° ͜ʖ ͡°)" << endl;
		passCount++;
	}
	else
	{
		cout << "The removal of removeFromFront worked poorly) ಠ෴ಠ" << endl;
	}
	if (testIntList->getSize() == 4)
	{
		cout << "The size adjustment of removeFromFront worked properly! ( ͡° ͜ʖ ͡°)" << endl;
		passCount++;
	}
	else
	{
		cout << "The size adjustment of removeFromFront worked poorly) (ಠ,,,ಠ)" << endl;
		cout << "The size should be 4 and is " << testIntList->getSize() << endl;
	}
	if (testIntList->removeFromIndex(2) == 9)
	{
		cout << "The removal of removeFromEnd worked properly! ( ͡° ͜ʖ ͡°)" << endl;
		passCount++;
	}
	else
	{
		cout << "The removal of removeFromEnd worked poorly (ಠ,,,ಠ)" << endl;
	}
	if (testIntList->getSize() == 3)
	{
		cout << "The size adjustment of removeFromIndex worked properly! ( ͡° ͜ʖ ͡°)" << endl;
		passCount++;
	}
	else
	{
		cout << "The size adjustment of removeFromIndex worked poorly סּ_סּ" << endl;
		cout << "The size should be 3 and is " << testIntList->getSize() << endl;
	}
	tearDown();
}

void ListTester::testSet()
{
	cout << "Beginning set test!" << endl;
	setUp();
	testStringList->addToEnd("more");
	testStringList->addToEnd("things");
	testStringList->addToEnd("are");
	testStringList->addToEnd("words");
	int testSize = testStringList->getSize();
	if (testStringList->set(3, "stuff").compare("words") == 0)
	{
		cout << "The set method worked properly! ( ͡° ͜ʖ ͡°)" << endl;
		passCount++;
	}
	else
	{
		cout << "The set method worked poorly סּ_סּ" << endl;
	}
	if (testStringList->getSize() == testSize)
	{
		cout << "The set method did not affect size! ( ͡° ͜ʖ ͡°)" << endl;
		passCount++;
	}
	else
	{
		cout << "The set method size worked poorly ಠಿ_ಠ" << endl;
	}
	tearDown();
}


void ListTester::testSize()
{
	cout << "Beginning size tests!" << endl;
	setUp();
	testStringList->addToEnd("more");
	testStringList->addToEnd("things");
	testStringList->addToEnd("are");
	testStringList->addToEnd("words");
	if (testStringList->getSize() == 4)
	{
		testStringList->removeFromEnd();
		if (testStringList->getSize() == 3)
		{
			testStringList->removeFromEnd();
			if (testStringList->getSize() == 2)
			{
				testStringList->removeFromEnd();
				testStringList->addAtIndex(0, "");
				testStringList->removeFromEnd();
				if (testStringList->getSize() == 1)
				{
					cout << "Sizes are adjusted properly!!!!" << endl;
					passCount++;
				}}}}
	else
	{
		cout << "Sizes are adjusted poorly ಠಿ_ಠ" << endl;
	}
	tearDown();
}
