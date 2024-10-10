/// Intro
/*
    Your task for this lab is to write an app that creates an expense report
    for The International Secret Intelligence Service (I.S.I.S.) and print it
    to screen.  Suggested sequence of work:

        1. Include necessary libraries
        2. Write empty main() function
        3. Write the Employee struct
        4. Write the EmployeeList struct
        5. Write create_employee_list() function
        6. Test create_employee_list() in main
        7. Write the read_employees(...)
        8. Test read_employees(...) in main
        9. Write print_employee(...)
        10. Write print_employee_list(...)
        11. Test print_employee_list(...) in main

        *You should be able to read the employees into the list and print it
        to screen.

        12. Write the Expense struct
        13. Write the ExpenseList struct
        14. Write create_expense_list() function
        15. Test create_expense_list() in main
        16. Write the read_expenses(...)
        17. Test read_expenses(...) in main
        18. Write print_expense(...)
        19. Write print_expense_list(...)
        20. Test print_expense_list(...) in main

        *You should be able to read the expenses into the list and print it
        to screen.

        21. Write the calc_expenses(...) function
        22. Text calc_expenses(...) in main

        *You should see the necessary output shown at the end of this file.
*/

/// Preprocessor statements
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define LENGTH_OF_EMPLOYEE_LIST 100
#define LENGTH_OF_NAME 32
#define LENGTH_OF_POSITION 32
#define NUM_OF_ID_DIGITS 10
#define LENGTH_OF_EXPENSE 50
#define LENGTH_OF_EXPENSE_LIST 100

/// Structs
/*
    Note: that terms in '' are suggestions for variable names.
    The Employee struct stores data:
        The employee's 'id' as an integer
        The employee's 'name' as a string
        The employees 'position' (job title) as a string
        The employee's 'salary' as a double

    Also note: that all structs should be declared like:
        Employee e;
        NOT
        struct Employee e;

*/

typedef struct Employee
{
    int id;
    char name[LENGTH_OF_NAME];
    char position[LENGTH_OF_POSITION];
    double salary;
}Employee;

/*
    The EmployeeList struct stores a list of Employee:
        An 'array' of Employee
        The preallocated 'length' of the Employee array as integer
        The 'count' of the Employee inserted into array as integer
*/

typedef struct EmployeeList
{
    Employee employees[LENGTH_OF_EMPLOYEE_LIST];
    int length;
    int count;
}EmployeeList;

/*
    The Expense struct stores data:
        The expense line's 'employee_id' as an integer
        The expense's 'description' as a string
        The expense's 'cost' as a double
*/
typedef struct Expense
{
    // still incomplete
    int employee_id;
    char description[LENGTH_OF_EXPENSE];
    double cost;
}Expense;

/*
    The ExpenseList struct stores a list of Expense:
        An 'array' of Expense
        The preallocated 'length' of the Expense array as integer
        The 'count' of the Expense inserted into array as integer
*/

typedef struct ExpenseList
{
    Expense expenses[LENGTH_OF_EXPENSE_LIST];
    int length;
    int count;
}ExpenseList;


/// Prototypes
EmployeeList create_employee_list();
int read_employees(EmployeeList* el);
void print_employee(Employee);
void print_employee_list(EmployeeList* el);
ExpenseList create_expense_list();
int read_expenses(ExpenseList* el);
void calc_expense(EmployeeList* employee_list, ExpenseList* expense_list);
void print_expense(Expense expense);
void print_expense_list(ExpenseList *expense_list) ;


/// Main
/*
    The main function should:
        Create an EmployeeList by calling create_employee_list()
        Read employees into EmployeeList by calling read_employees(...)
        Print the EmployeeList by calling print_employee_list(...)

        Create an ExpenseList by calling create_expense_list()
        Read expenses into ExpenseList by calling read_expenses(...)
        Print the ExpenseList by calling print_expense_list(...)

        Call calc_expenses(...) to compile and print expense report to screen
*/

int main()
{
    EmployeeList el = create_employee_list();
    int count = read_employees(&el);

    //print_employee(el.employees[0]);
    
    //print_employee_list(&el);
    
    //Expense calculations
    // ExpenseList exl = create_expense_list();
    // int countexp = read_expenses(&exl);
    
    // //print_expense(exl.expenses[0]);
    // print_expense_list(&exl);
    
    // // Calculate all expenses for individuals
    // calc_expense(&el, &exl);
    
    return 0;
}



/// Create employee list
/*
    The create_employee_list() function accepts no arguments and
    returns an EmployeeList to the calling function.
    It should set the 'length' and 'count' to correct values.
*/
EmployeeList create_employee_list()
{
    EmployeeList* el = (EmployeeList*)malloc(sizeof(EmployeeList));
    el->length = LENGTH_OF_EMPLOYEE_LIST;
    el->count = 0;
    return *el;
}


/// Read employees into list
/*
    The read_employees(...) function should accept an EmployeeList reference
    as an argument and return an integer with the correct count of employees
    in the list. The data below needs to be copied to an array of strings
    and then copied to the EmployeeList reference.

    "1|Archer, Malory|CEO|500000.0"
    "2|Archer, Sterling|Agent|250000.0"
    "3|Kane, Lana|Agent|300000.0"
    "4|Figus, Ceril|Accountant|100000.0"
    "5|Tunt, Cheryl|Secretary|65000.0"
    "6|Poovey, Pam|HR|85000.0"
*/

// helper function
int find_next_bar(const char* src, int start)
{
    // find the index of the next '|' in the given arg string src
    // start from the arg start
    // find_next_bar("1|Archer, Malory|CEO|500000.0", 0) -> 1
    // find_next_bar("1|Archer, Malory|CEO|500000.0", 1) -> 1
    // find_next_bar("1|Archer, Malory|CEO|500000.0", 2) -> 16
    // find_next_bar("1|Archer, Malory|CEO|500000.0", 17) -> ?
    // find_next_bar("1|Archer, Malory|CEO|500000.0", 18) -> ?

    int index = -1;
    for(int i = start; src[i] != '\0'; i++)
    {
        if (src[i] == '|')
        {
            index = i;
            break;
        }
    }

    return index;
}

// helper function to find comma
int find_next_comma(const char* src, int start)
{

    int index = -1;
    for(int i = start; src[i] != '\0'; i++)
    {
        if (src[i] == ',')
        {
            index = i;
            break;
        }
    }

    return index;
}




int read_employees(EmployeeList* el)
{
    char el_str_arr[100][100] = 
    {
        "1|Archer, Malory|CEO|500000.0",
        "2|Archer, Sterling|Agent|250000.0",
        "3|Kane, Lana|Agent|300000.0",
        "4|Figus, Ceril|Accountant|100000.0",
        "5|Tunt, Cheryl|Secretary|65000.0",
        "6|Poovey, Pam|HR|85000.0"
    };

    for(int i = 0; el_str_arr[i][0] != '\0'; i++)
    {
        // printf("Reading employee: %dth\n", i);
        // printf("%s\n", el_str_arr[i]);
        // get id
        char id_str[NUM_OF_ID_DIGITS];
        int end_of_id = find_next_bar(el_str_arr[i], 0);
        if (end_of_id - 0 > NUM_OF_ID_DIGITS)
        {
            fputs("The id is too long", stderr);
            return i;
        }
        // char *strncpy(char *dest, const char *src, size_t n)
        //printf("el_str_arr[] + 0 = %s\n", el_str_arr[i] + 0);
        strncpy(id_str, el_str_arr[i] + 0, end_of_id);
        id_str[end_of_id - 0] = '\0';
        int id = atoi(id_str); // #include <stdlib.h>
        // printf("id: %d\n", id);

        // get name
        char name[LENGTH_OF_NAME];
        int end_of_name = find_next_bar(el_str_arr[i], end_of_id+1);
        if (end_of_name - end_of_id > LENGTH_OF_NAME)
        {
            fputs("The name is too long", stderr);
            return i;
        }
        // 012345678, 8-1=7
        // 1|myname|
        strncpy(name, el_str_arr[i] + (end_of_id+1), end_of_name-(end_of_id+1));
        name[end_of_name-(end_of_id+1)] = '\0';
        // printf("name: %s\n", name);

        // get position
        char position[LENGTH_OF_POSITION];
        int end_of_position = find_next_bar(el_str_arr[i], end_of_name+1);
        if (end_of_position - end_of_name > LENGTH_OF_POSITION)
        {
            fputs("The position is too long", stderr);
            return i;
        }
        strncpy(position, el_str_arr[i] + (end_of_name+1), end_of_position-(end_of_name+1));
        position[end_of_position-(end_of_name+1)] = '\0';
        // printf("position: %s\n", position);

        // get salary
        // here you may use atof (similar to atoi)
        double salary;
        char salary_str[NUM_OF_ID_DIGITS];
        int end_of_salary = strlen(el_str_arr[i]);
        //printf("end of salary = %d\n", end_of_salary2);
        if (end_of_salary - end_of_position > NUM_OF_ID_DIGITS)
        {
            fputs("The salary is too long", stderr);
            return i;
        }
        strncpy(salary_str, el_str_arr[i] + (end_of_position+1), end_of_salary-(end_of_position+1));
        //salary_str[end_of_salary-(end_of_position+1)] = '\0';
        salary = atof(salary_str); // #include <stdlib.h>
        // printf("Salary: %f\n", salary);
        
        el->employees[i].id = id;
        strncpy(el->employees[i].name, name, strlen(name));
        strncpy(el->employees[i].position, position, strlen(position));
        el->employees[i].salary = salary;
    }
    return 0;
}



/// Print employee to screen
/*
    The print_employee(...) function accepts an Employee as an argument and
    returns nothing.  It should prints the data as (for record 1):

        ID:        1
        Name:      Archer, Malory
        Position:  CEO
        Salary:    $500000.00
*/

void print_employee(Employee employee)
{
    printf("%-10s %-32d\n", "ID:", employee.id);
    printf("%-10s %-32s\n", "Name:", employee.name);
    printf("%-10s %-32s\n", "Position:", employee.position);
    printf("%-10s $%-32.2f\n\n", "Salary:", employee.salary);
}


/// Print all employees to screen
/*
    The print_employee_list(...) function accepts an EmployeeList as an argument
    and returns nothing. It should print the list as:

        I.S.I.S. Employees

        ID:        1
        Name:      Archer, Malory
        Position:  CEO
        Salary:    $500000.00

        ID:        2
        Name:      Archer, Sterling
        Position:  Agent
        Salary:    $250000.00

        ID:        3
        Name:      Kane, Lana
        ...
*/
void print_employee_list(EmployeeList *el)
{
    for(size_t i=0; i < (*el).employees[i].id; i++) {
        Employee cur_employee = (*el).employees[i];
        print_employee(cur_employee);
    }
}


/// Create expense list
/*
    The create_expense_list() function accepts no arguments and
    returns an ExpenseList to the calling function.
    It should set the 'length' and 'count' to correct values.
*/
ExpenseList create_expense_list()
{
    ExpenseList* exl = (ExpenseList*)malloc(sizeof(ExpenseList));
    exl->length = LENGTH_OF_EXPENSE_LIST;
    exl->count = 0;
    return *exl;
}


/// Read expenses into list
/*
    The read_expenses(...) function should accept an ExpenseList reference
    as an argument and return an integer with the correct count of expenses
    in the list. The data below needs to be copied to an array if strings
    and then copied to the ExpenseList reference.

    "1,Dinner,456.23"
    "1,Air Travel,692.12"
    "1,Spa Day,725.00"
    "2,Bar Bill,392.34"
    "2,Glenghoulie Blue,320.00"
    "2,Bar Bill,523.54"
    "3,Explosives,550.00"
    "3,Firearms,2343.56"
    "3,Amunition,245.98"
    "4,Lunch,52.45"
    "4,Ledger,23.45"
    "5,Copy Paper,56.23"
    "5,Staples,12.09"
    "6,Milk,4.50"
    "6,Cheese,7.89"
*/
int read_expenses(ExpenseList* el) {
    char exl_str_arr[100][100] = {
    "1,Dinner,456.23",
    "1,Air Travel,692.12",
    "1,Spa Day,725.00",
    "2,Bar Bill,392.34",
    "2,Glenghoulie Blue,320.00",
    "2,Bar Bill,523.54",
    "3,Explosives,550.00",
    "3,Firearms,2343.56",
    "3,Amunition,245.98",
    "4,Lunch,52.45",
    "4,Ledger,23.45",
    "5,Copy Paper,56.23",
    "5,Staples,12.09",
    "6,Milk,4.50",
    "6,Cheese,7.89"
    };
    
    for(int i = 0; exl_str_arr[i][0] != '\0'; i++)
    {
        // get emp id
        char empid_str[NUM_OF_ID_DIGITS];
        int end_of_id = find_next_comma(exl_str_arr[i], 0);
        if (end_of_id - 0 > NUM_OF_ID_DIGITS)
        {
            fputs("The id is too long", stderr);
            return i;
        }
        strncpy(empid_str, exl_str_arr[i] + 0, end_of_id);
        empid_str[end_of_id - 0] = '\0';
        int empid = atoi(empid_str); // #include <stdlib.h>
        //printf("emp id: %d\n", empid);

        // get description
        char description[LENGTH_OF_NAME];
        int end_of_desc = find_next_comma(exl_str_arr[i], end_of_id+1);
        if (end_of_desc - end_of_id > LENGTH_OF_NAME)
        {
            fputs("The name is too long", stderr);
            return i;
        }
        // 012345678, 8-1=7
        // 1|myname|
        strncpy(description, exl_str_arr[i] + (end_of_id+1), end_of_desc-(end_of_id+1));
        description[end_of_desc-(end_of_id+1)] = '\0';
        
        // get cost
        // here you may use atof (similar to atoi)
        double cost;
        char cost_str[NUM_OF_ID_DIGITS];
        int end_of_cost = strlen(exl_str_arr[i]);
        //printf("end of salary = %d\n", end_of_salary2);
        if (end_of_cost - end_of_desc > NUM_OF_ID_DIGITS)
        {
            fputs("The cost is too long", stderr);
            return i;
        }
        strncpy(cost_str, exl_str_arr[i] + (end_of_desc+1), end_of_cost-(end_of_desc+1));
        //salary_str[end_of_salary-(end_of_position+1)] = '\0';
        cost = atof(cost_str); // #include <stdlib.h>
        //printf("Cost: %f\n", cost);
        
        el->expenses[i].employee_id = empid;
        strncpy(el->expenses[i].description, description, strlen(description));
        el->expenses[i].cost = cost;
    }
    return 0;
}


/// Print expense to screen
/*
    The print_expense(...) function accepts an Expense as an argument and
    returns nothing.  It should prints the data as (for record 1):

        Employee ID:  1
        Description:  Air Travel
        Cost:         $692.12
*/
void print_expense(Expense expense) {
    // print the expense information
    printf("%-10s %-32d\n", "Employee ID:", expense.employee_id);
    printf("%-10s %-32s\n", "Description:", expense.description);
    printf("%-10s $%-32.2f\n", "Cost:", expense.cost);
}


/// Print all expenses to screen
/*
    The print_expense_list(...) function accepts an ExpenseList as an argument
    and returns nothing. It should print the list as:

        I.S.I.S. Expenses

        Employee ID:  1
        Description:  Dinner
        Cost:         $456.23

        Employee ID:  1
        Description:  Air Travel
        Cost:         $692.12

        Employee ID:  1
        Description:  Spa Day
        ...
*/
void print_expense_list(ExpenseList *expense_list) {

    printf("I.S.I.S Expenses\n\n");
    // Loop through all the costs and pass info to print_expense
    for(size_t i=0; i < expense_list->expenses[i].cost; i++) {
        print_expense(expense_list->expenses[i]);
        printf("\n");
    }
}


/// Calculate the expenses for each employee
/*
    The calc_expenses(...) function accepts the EmployeeList and ExpenseList as
    arguments and returns nothing. It should print an expense report for each
    employee.  It should loop through each employee, printing the employee's
    stated expenses and the total as shown below:

        1 Archer, Malory CEO $500000.00
                Dinner $456.23
                Air Travel $692.12
                Spa Day $725.00
        Total: $1873.35

        2 Archer, Sterling Agent $250000.00
                Bar Bill $392.34
                Glenghoulie Blue $320.00
                Bar Bill $523.54
        Total: $1235.88

        3 Kane, Lana Agent $300000.00
                Explosives $550.00
        ...
*/

void calc_expense(EmployeeList* employee_list, ExpenseList* expense_list)
{
    /*
    for each employee in the employee_list
    {
        for each expense in the expense_list
        {
            if the 'exmployee id of this expense' matches
                the 'id of the employee' in the outer loop
            {                
                // print the expense information
                // and accumulate the amount
            }
        }
        
        // print the total amount by the current employee
    }
    */
    
    printf("I.S.I.S Expenses\n\n");
    double total_cost;
   
    for(size_t i = 0; i < employee_list->employees[i].id; i++)
    {
        total_cost = 0;
        Employee cur_employee = employee_list->employees[i];
        // 2 Archer, Sterling Agent $250000.00
        printf("%-3d %-15s %-10s $%-32.2f\n", cur_employee.id, cur_employee.name, cur_employee.position, cur_employee.salary);
        for (size_t j = 0; j < expense_list->expenses[j].cost; j++)
        {
            Expense cur_expense = expense_list->expenses[j];
            //printf("employee = %d ::: expense employee = %d\n", cur_employee.id, cur_expense.employee_id);
            if (cur_expense.employee_id == cur_employee.id)
            {
                // print the expense information
                //printf("     %-10s %-32d\n", "Employee ID:", cur_expense.employee_id);
                //Air Travel $692.12
                printf("     %-10s $%-32.2f\n", cur_expense.description, cur_expense.cost);
                //printf("     %-10s %-32.2f\n", "Cost:", cur_expense.cost);
                
                // and accumulate the amount
                total_cost += cur_expense.cost;
            }
        }

        //print the total amount by the current employee
        printf("%-10s $%-32.2f\n\n", "Total Cost:", total_cost);
    }
}


/// Sample complete output from app
/*
I.S.I.S. Employees

ID:        1
Name:      Archer, Malory
Position:  CEO
Salary:    $500000.00

ID:        2
Name:      Archer, Sterling
Position:  Agent
Salary:    $250000.00

ID:        3
Name:      Kane, Lana
Position:  Agent
Salary:    $300000.00

ID:        4
Name:      Figus, Ceril
Position:  Accountant
Salary:    $100000.00

ID:        5
Name:      Tunt, Cheryl
Position:  Secretary
Salary:    $65000.00

ID:        6
Name:      Poovey, Pam
Position:  HR
Salary:    $85000.00

I.S.I.S. Expenses

Employee ID:  1
Description:  Dinner
Cost:         $456.23

Employee ID:  1
Description:  Air Travel
Cost:         $692.12

Employee ID:  1
Description:  Spa Day
Cost:         $725.00

Employee ID:  2
Description:  Bar Bill
Cost:         $392.34

Employee ID:  2
Description:  Glenghoulie Blue
Cost:         $320.00

Employee ID:  2
Description:  Bar Bill
Cost:         $523.54

Employee ID:  3
Description:  Explosives
Cost:         $550.00

Employee ID:  3
Description:  Firearms
Cost:         $2343.56

Employee ID:  3
Description:  Amunition
Cost:         $245.98

Employee ID:  4
Description:  Lunch
Cost:         $52.45

Employee ID:  4
Description:  Ledger
Cost:         $23.45

Employee ID:  5
Description:  Copy Paper
Cost:         $56.23

Employee ID:  5
Description:  Staples
Cost:         $12.09

Employee ID:  6
Description:  Milk
Cost:         $4.50

Employee ID:  6
Description:  Cheese
Cost:         $7.89

1 Archer, Malory CEO $500000.00
        Dinner $456.23
        Air Travel $692.12
        Spa Day $725.00
Total: $1873.35

2 Archer, Sterling Agent $250000.00
        Bar Bill $392.34
        Glenghoulie Blue $320.00
        Bar Bill $523.54
Total: $1235.88

3 Kane, Lana Agent $300000.00
        Explosives $550.00
        Firearms $2343.56
        Amunition $245.98
Total: $3139.54

4 Figus, Ceril Accountant $100000.00
        Lunch $52.45
        Ledger $23.45
Total: $75.90

5 Tunt, Cheryl Secretary $65000.00
        Copy Paper $56.23
        Staples $12.09
Total: $68.32

6 Poovey, Pam HR $85000.00
        Milk $4.50
        Cheese $7.89
Total: $12.39


Process returned 0 (0x0)   execution time : 1.642 s
Press any key to continue.

*/
