#include "bank.h"
#include <stdbool.h>
#include <stdio.h>

Bank* CreateBank(double money, double maxLoan, double loanInterest, double transferFeeRate) {
    // Allocate bank
    Bank *bank = malloc(sizeof(Bank));
    assert(bank);
    // No accounts yet
    
    bank->accounts = NULL;
    bank->nAcc = 0;
    // Assign inputs
    bank->money = money;
    bank->maxLoan = maxLoan;
    bank->loanInterest = loanInterest;
    bank->transferFeeRate = transferFeeRate;

    return bank;
}

Account* OpenAccount(Bank *bank) { // DONE
    struct Account *newAccount = malloc(sizeof(struct Account)); 
    newAccount->active = true; 
    newAccount->balance = 0.00; 
    newAccount->bank = bank; 
    newAccount->id = bank->nAcc+1;
    newAccount->loan.interest = bank->loanInterest;
    
    bank->accounts = realloc(bank->accounts, (sizeof(int)*(bank->nAcc+1)));
    bank->accounts[bank->nAcc] = newAccount;
    bank->nAcc++;
    return newAccount;
}

void Deposit(double amount, Account *account) { // DONE
    if (account->active == true){ account->balance = account->balance + amount; } 
}

bool Withdraw(double amount, Account *account) { // DONE
    if (account->balance >= amount){ account->balance -= amount;  return true; } 
    return false;
}

bool TakeLoan(double amount, Account *account) { // DONE
    if (account->active == true && account->loan.active == false){
        if (amount <= account->bank->maxLoan){
            if (account->bank->money >= amount){
                account->bank->money -= amount;
                account->balance += amount;
                account->loan.active = true;
                account->loan.amount = amount;
                return true;
            }
        }
    }
    return false;   
}

bool PayLoan(Account *account) { // DONE
    if (account->active == true && account->loan.active == true){
        if (account->balance >= (account->loan.amount*account->loan.interest)){
            account->bank->money += (account->loan.amount*account->loan.interest);
            account->balance -= (account->loan.amount*account->loan.interest);
            account->loan.active = false;
            return true;
        }
    }
    return false;
}

bool Transfer(double amount, Account *sender, Account *receiver) { // DONE
    if (sender->bank == receiver->bank){
        Withdraw(amount, sender);
        Deposit(amount, receiver);
    }
    else{
        float interestAmount = sender->bank->transferFeeRate*amount;
        Withdraw(amount+interestAmount, sender);
        Deposit(amount, receiver);
        sender->bank->money += interestAmount;
    }
}

bool CollectLoanPayments(Bank *bank) { // DONE
    for (int i = 0; i < bank->nAcc; i++){
        if (bank->accounts[i]->loan.active == false || PayLoan(bank->accounts[i])){
            continue;
        }
        else{
            return false;
        }
    return true;
    }
}

bool CloseAccount(Account *account) { // DONE
    if (account->loan.active == false || PayLoan(account)){
        account->active = false;
        account->balance = 0.00;
        return true;
    }
    return false;
}

Bank* ForceDestroyBank(Bank *bank) { // DONE
    // Check if bank exists
    if (!bank)
        return NULL;
    // Just free the memory
    for (int i = 0; i < bank->nAcc; i++) {
                  free(bank->accounts[i]);
    }
    free(bank->accounts);
        
    free(bank);
    bank = NULL;
    return NULL;
}

void ShowAccount(Account *account) { // DONE
    printf("Account #%d:\n", account->id);
    if (account->active) {
        printf("Balance: %.3f\n", account->balance);
        if (account->loan.active) {
            printf("Loaned %.3f with interest %f\n",
                account->loan.amount, account->loan.interest);
        }
    } else {
        printf("Inactive account\n");
    }
}

void ShowBank(Bank *bank) { // DONE
    printf("BANK:\n");
    printf("Total money in bank: %.3f\n", bank->money);
    printf("Maximum loan offered: %.3f\n", bank->maxLoan);
    printf("Interest for loans: %f\n", bank->loanInterest);
    printf("Fee for a money transfer: %f\n", bank->transferFeeRate);
    //printf("----------------\n");
    for (int i = 0; i < bank->nAcc; i++) {
        ShowAccount(bank->accounts[i]);
        printf("----------------\n");
    }
}

// int main(void) {
//     printf("creating b0\n");
//     Bank *b0 = CreateBank(1000, 100, 1.0001, 0.0001);
//     assert(b0);
//     printf("creating b1\n");
//     Bank *b1 = CreateBank(2000, 300, 1.0001, 0.0001);
//     assert(b1);

//     printf("adding a0 to b0\n");
//     Account *a0 = OpenAccount(b0);
//     assert(a0);
//     printf("adding a1 to b1\n");
//     Account *a1 = OpenAccount(b1);
//     assert(a1);
//     printf("adding a2 to b1\n");
//     Account *a2 = OpenAccount(b1);
//     assert(a2);
//     printf("deposit 200 in a0\n");
//     Deposit(200, a0);
//     ShowAccount(a0);
//     printf("loan 100 for a0\n");
//     TakeLoan(100, a0);
//     ShowAccount(a0);
//     printf("deposit 500 in a1\n");
//     Deposit(500, a1);
//     ShowAccount(a1);
//     printf("deposit 400 in a2\n");
//     Deposit(400, a2);
//     ShowAccount(a2);
   
// // Deposit
//     printf("deposit 300 in a0\n");
//     Deposit(300, a0);
//     printf("deposit 300 in a1\n");
//     Deposit(300, a1);
//     printf("deposit 100 in a2\n");
//     Deposit(100, a2);

//     ShowBank(b0);
//     printf("*********\n");
//     ShowBank(b1);
// // Withdraw
//     printf("withdraw 200 from a0\n");
//     Withdraw(200, a0);
    
//     ShowBank(b0);
//     printf("*********\n");
//     ShowBank(b1);
// // Take Loan
//     printf("100 loan to a0\n");
//     TakeLoan(100, a0);

// // Transfer
//     printf("100 transfer from a1 to a0\n");
//     Transfer(100, a1, a0);  // No fee same bank
//     printf("50 transfer from a1 to a2\n");
//     Transfer(50, a1, a2);   // Fee applied - different banks

//     ShowBank(b0);
//     printf("*********\n");
//     ShowBank(b1);
// // Pay Loan
//     printf("collect loan payment b0\n");
//     CollectLoanPayments(b0);

//     ShowBank(b0);
//     printf("*********\n");
//     ShowBank(b1);

//     Withdraw(5000, a1);
//     ShowAccount(a1);
//     printf("close a1\n");

//     CloseAccount(a1);
//     ShowBank(b0);
//     printf("*********\n");
//     ShowBank(b1);
//     printf("the end\n");
    
// // Force Destroy 
//     ForceDestroyBank(b0);
//     ForceDestroyBank(b1);
//     return 0;
// }