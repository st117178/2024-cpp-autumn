#include <gtest/gtest.h>
#include <iostream>
#include "Bank_src/Bank.h"
#include "Bank_src/BankAccount.h"
#include "Text-editor_src/txt-editor.h"

TEST(Text_editor, Test_Constructor)
{
    TxtEditor txt;
    ASSERT_EQ(txt.getCursorPos(), 0);
    ASSERT_EQ(txt.getTxt(), "");
}

TEST(Text_editor, Test__Function_Add_Txt)
{
    TxtEditor txt;
    txt.addText("Artem");
    std::string text = "Artem";
    ASSERT_EQ(txt.getTxt(), text);
}

TEST(Text_editor, Test__Function_Cursor_Move)
{
    TxtEditor txt;
    txt.addText("Artem");
    std::string text = "Artem";
    txt.cursorLeft(3);
    int pos = text.length() - 3;
    txt.cursorRight(1);
    pos += 1;
    ASSERT_EQ(txt.getCursorPos(), pos);
}

TEST(Text_editor, Test__Function_Delete_And_Cursor_Move)
{
    TxtEditor txt;

    txt.addText("Artem");

    std::string text = "Artem";
    int pos = text.length();

    txt.deleteText(2);

    text.erase(text.length() - 2);
    pos -= 2;

    txt.cursorLeft(1);

    pos -= 1;

    ASSERT_EQ(txt.getCursorPos(), pos);
    ASSERT_EQ(txt.getTxt(), text);
}

TEST(Text_editor, Test__Function_Ostream)
{
    TxtEditor txt;

    txt.addText("Artem");
    std::stringstream stream_txt;
    stream_txt << txt;

    std::string text = "Artem";
    std::stringstream stream_text;
    stream_text << text;

    ASSERT_EQ(stream_txt.str(), stream_text.str());
}

TEST(Bank_Account, Test_Constructor)
{
    BankAccount account("1", 123.123, "Artem");

    std::string number = "1";
    double balance = 123.123;
    std::string holder = "Artem";

    ASSERT_EQ(account.GetAccountHolder(), holder);
    ASSERT_EQ(account.GetAccountNumber(), number);
    ASSERT_EQ(account.GetBalance(), balance);
}

TEST(Bank_Account, Test_Function_Deposit)
{
    BankAccount account("1", 0, "Artem");

    double balance = 0;

    account.Deposit(100);

    balance += 100;
    ASSERT_EQ(account.GetBalance(), balance);
}

TEST(Bank_Account, Test_Function_Withdraw)
{
    BankAccount account("1", 1000.01, "Artem");

    double balance = 1000.01;

    account.Withdraw(1000);

    balance -= 1000;
    ASSERT_EQ(account.GetBalance(), balance);
}

TEST(Bank_Account, Test_Function_Withdraw_Error)
{
    BankAccount account("1", 1000.01, "Artem");

    double balance = 1000.01;

    account.Withdraw(1000.2);

    ASSERT_EQ(account.GetBalance(), balance);
}

TEST(Bank_H, Test_Function_Total_Bal)
{
    BankAccount bankAcc1("1", 12346.12, "Artem");

    double balance = 12346.12;

    BankAccount bankAcc2("2", 666.777, "Ilya");

    balance += 666.777;

    BankAccount bankAcc3("3", 228.1337, "Zahar");

    balance += 228.1337;

    Bank bank;
    bank.AddAccount(&bankAcc1);
    bank.AddAccount(&bankAcc2);
    bank.AddAccount(&bankAcc3);

    ASSERT_EQ(bank.GetTotalBalnce(), balance);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
