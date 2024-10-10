/// Read employees into list (Paste this above function and follow the hints below)
/// This is for the read_employees(...) function
/*
    Comment out all of the code in the function and add code to read the lines
    from a file and copies the data from the read lines into the EmployeeList's
    array.

        1. Comment out all code in function
        2 Declare a char array of sufficient size to contain a record string from
            the file
        3. Declare a File pointer and open the file named "isisStaff.txt" to read
        4. Write a loop to read and print to screen a line from the file
            a. Test that lines are read and printed to screen
            b. There will be a \n in the line read from the file. Add code to
            remove it and test that it has been removed
            b. Tokenize the line into the EmployeeList and test by printing
                the EmployeeList in main
        5. If the data prints correctly, delete the commented code
        6. Make sure to close the file when reading and copying is done

*/

/// Read expenses into list (Paste this above function and follow the hints below)
/// This is for the read_expenses(...) function
/*
    Comment out all of the code in the function and add code to read the lines
    from a file and copies the data from the read lines into the ExpenseList's
    array.

        1. Comment out all code in function
        2 Declare a char array of sufficient size to contain a record string from
            the file
        3. Declare a File pointer and open the file named "isisExp.csv" to read
        4. Write a loop to read and print to screen a line from the file
            a. Test that lines are read and printed to screen
            b. There will be a \n in the line read from the file. Add code to
            remove it and test that it has been removed
            b. Tokenize the line into the ExpenseList and test by printing
                the ExpenseList in main
        5. If the data prints correctly, delete the commented code
        6. Make sure to close the file when reading and copying is done

*/

/// Calculate the expenses for each employee (Paste this above function and follow the hints below)
/// This is for the calc_expenses(...) function
/*
    Change the calc_expenses(...) function to print data to file
    and screen.

    1. Add code to declare and open a file pointer
    2. Add code to write report header to the file
        a. Header is: I.S.I.S. Expense Report
    3. Add code to the outer loop to write employee lines printed to screen
        to file
    4. Add code to the inner loop to write expense lines printed to screen
        to file
    5. Add code to print the total of all employee expenses after the inner
        loop body
    6. Test your app to ensure correct output to file
    7. Make sure to close the file
*/


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

/// Sample output file
/*
I.S.I.S. Expense Report

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

*/

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
#include <fstream.h>

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
int read_books(EmployeeList* el);


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

EmployeeList create_employee_list()
{
    EmployeeList* el = (EmployeeList*)malloc(sizeof(EmployeeList));
    el->length = LENGTH_OF_EMPLOYEE_LIST;
    el->count = 0;
    return *el;
}


/// Read employees into list


// helper function
int find_next_bar(const char* src, int start)
{


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

// read_books function
int read_books(EmployeeList* el)
{
    fstream newfile;
    newfile.open("Lab11isisStaff.txt",ios::out);  // open a file to perform write operation using file object
    // if(newfile.is_open()) //checking whether the file is open
    // {
    //     newfile<<" \n";   //inserting text
    //     newfile.close();    //close the file object
    // }
    // newfile.open("tpoint.txt",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string emp;
        while(getline(newfile, emp)){ //read data from file object and put it into string.
            //cout << emp << "\n"; //print the data of the string
            char* tk = strtok(emp, "|");  
            // now tk is the first token
            int id = atoi(tk);
            el->employees[i].id = id;

            tk = strtok(NULL, " ");
            // now tk is the second token
            strncpy(el->employees[i].name, tk);

            tk = strtok(NULL, " ");
            // now tk is the third token
            strncpy(el->employees[i].position, tk);

            tk = strtok(NULL, " ");
            double salary = atof(tk);
            // now tk is the fourth token
            el->employees[i].salary = salary;
            strncpy(el->employees[i].position, tk);

        }
        newfile.close(); //close the file object.
    }
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


void print_employee(Employee employee)
{
    printf("%-10s %-32d\n", "ID:", employee.id);
    printf("%-10s %-32s\n", "Name:", employee.name);
    printf("%-10s %-32s\n", "Position:", employee.position);
    printf("%-10s $%-32.2f\n\n", "Salary:", employee.salary);
}


/// Print all employees to screen

void print_employee_list(EmployeeList *el)
{
    for(size_t i=0; i < (*el).employees[i].id; i++) {
        Employee cur_employee = (*el).employees[i];
        print_employee(cur_employee);
    }
}


/// Create expense list

ExpenseList create_expense_list()
{
    ExpenseList* exl = (ExpenseList*)malloc(sizeof(ExpenseList));
    exl->length = LENGTH_OF_EXPENSE_LIST;
    exl->count = 0;
    return *exl;
}


/// Read expenses into list

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

void print_expense(Expense expense) {
    // print the expense information
    printf("%-10s %-32d\n", "Employee ID:", expense.employee_id);
    printf("%-10s %-32s\n", "Description:", expense.description);
    printf("%-10s $%-32.2f\n", "Cost:", expense.cost);
}


void print_expense_list(ExpenseList *expense_list) {

    printf("I.S.I.S Expenses\n\n");
    // Loop through all the costs and pass info to print_expense
    for(size_t i=0; i < expense_list->expenses[i].cost; i++) {
        print_expense(expense_list->expenses[i]);
        printf("\n");
    }
}




void calc_expense(EmployeeList* employee_list, ExpenseList* expense_list)
{

    
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


