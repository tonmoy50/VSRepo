using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;
using System.Threading;

namespace C_sharp_practice
{
    public class BankAccount
    {

        public string Number { get; }
        public string Owner { get; set; }
        public decimal Balance { 
            get 
            {
                decimal balance = 0;
               foreach ( var items in allTransactions)
                {
                    balance += items.Amount;
                }

                return balance;
            } 
        }

        private static int accountnumberseed = 1234567890;

        private List<Transaction> allTransactions = new List<Transaction>();


        public BankAccount(string name, decimal balance)
        {
            this.Owner = name;
            MakeDeposit(balance, DateTime.Now, "Initial Balance");

            this.Number = accountnumberseed.ToString();
            accountnumberseed++;
        }

        public void MakeDeposit(decimal amount, DateTime date, string notes)
        {
            if( amount <= 0)
            {
                throw new ArgumentOutOfRangeException(nameof(amount), "Deposited amount can't be less than or equal to zero");
            }

            var deposit = new Transaction(amount, date, notes);
            allTransactions.Add(deposit);
        }

        public void Makewithdrawal(decimal amount, DateTime date, string notes)
        {
            if (amount <= 0)
            {
                throw new ArgumentOutOfRangeException(nameof(amount), "Deposited amount can't be less than or equal to zero");
            }

            if ((Balance - amount) < 0)
            {
                throw new InvalidOperationException("Insufficient Balance");
            }

            var withdrawal = new Transaction(-amount, date, notes);
            allTransactions.Add(withdrawal);
        }

        public string GetTransactionHistory()
        {
            var history = new StringBuilder();

            history.AppendLine("Date\t\t\tAmount\tNote");

            foreach (var items in allTransactions)
            {
                history.AppendLine($"{items.Date} {items.Amount}\t {items.Notes}");
            }

            return history.ToString();
        }


    }
}
