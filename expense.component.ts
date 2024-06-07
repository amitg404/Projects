import { Component } from '@angular/core';

@Component({
  selector: 'app-expense',
  templateUrl: './expense.component.html',
  styleUrls: ['./expense.component.css']
})
export class ExpenseComponent {
  newExpense = { description: '', amount: 0 };
  expenses = [];

  addExpense() {
    if (this.newExpense.description.trim() !== '' && this.newExpense.amount > 0) {
      this.expenses.push({...this.newExpense});
      this.newExpense = { description: '', amount: 0 };
    }
  }

  removeExpense(index: number) {
    this.expenses.splice(index, 1);
  }

  getTotal() {
    return this.expenses.reduce((total, expense) => total + expense.amount, 0);
  }
}
