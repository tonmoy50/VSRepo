using System;
using System.Collections.Concurrent;
using System.Collections.Generic;

namespace C_sharp_practice
{
    class Program
    {
        static void Main(string[] args)
        {

            var acnt1 = new BankAccount("Tonmoy", 10000000);
            acnt1.Makewithdrawal(50000, DateTime.Now, "Withdraw");
            acnt1.MakeDeposit(999, DateTime.Now, "Deposited Money");
            Console.WriteLine($"{acnt1.Number} {acnt1.Owner} {acnt1.Balance}");
            Console.WriteLine(acnt1.GetTransactionHistory());
            

            var acnt2 = new BankAccount("Halder", 100000);
            Console.WriteLine($"{acnt2.Number} {acnt2.Owner} {acnt2.Balance}");

        }
    }
}
