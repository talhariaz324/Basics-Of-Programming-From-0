/*
As you know the manual system which was using the spreadsheets for storing the information for your store. But main issue with that is redundancy.
So, simply we can solve it by dividing the tables into like Customer, Order, Products.
In this way, we can reduce redundancy. And the relation between these tables forms a database. Like big amt of data.
But its difficult to understand the database in programming context, so we have the ERD diagrams. 
There is a tool from where we can import our database and it will generate its erd.
But If you are making database from scratch then make its ERD, It will create your database.

Entities to Tables
Attributrs to Columns
Relationships into coded connections

Tool name is: Lucid's Charts tool
*/





/*
SO we are going to learn the design of database which will be the general.
*/


/*
What is database?
DataBase which store data.
What is data?
Data is anything which have value is called data.

Diffrenece in database and spreadsheets?
SpreadSheets are good for small busineeses but for large scale businesses it is difficult to manage ton of data.
SO we have databases.
SpreadSheet also not good because if we need to show one person some other detail and one person other detail.
It show all the table.
But we can handle the such type of security in the database.

Most Commonly use database is relational.
In which data is store in table.
*/





/*
Relational DataBase:
What is Relation?
Relation is actually a relation between data.
In database we have entity and attributes.
Entity: Data is about to store.
Attribute: In actual Data which is to be store.
e.g; Want to store data about Atif.... So Atif is a entity and its attributes are username, address because these are sepcific to Entity (Atif) etc.
So, Relation is between the entity and the values of attributes actually.
Row/Tuple: Row in table here belongs to whole entity While Column belongs to single attribute for all the entites.

Entity Type: Most General. Not Specific... is called Entity Type. e.g; Employee (store data about employees) here there are many employees can be. SO it is not specific, so it is called as entity type.
Attribute Type: Employee Types are Name, UserName, Phone... Now these are also become general because of entity type.
But When we said that We are going to store data of Employees and Atif Employee then Row of Atif becomes simple Attributes for it. But as general they are attribute type for Entity Type (Employees).
In simple words, you can say that entity is individual row and attributes are column for each employee or ATIF. 
*/



/*
DBMS (Database management system):
As we learned datatbase have ton of data and very similar to spreadsheet. Then What is diffrence.
We can do some cool function whcih is called as query. DBMS use our data to view the user friendly way
it provide manage apperance of data and searching and so forth.

You want to delete a person who is not active more than a year , and you wnat to delte it.
you can do this very easily with the help of query.



Relation Database Management System (RDBMS) : Subtype of the DBMS and use to manage the relational databases
It provide us the view mechnanism which meanns change the surface apperance of our data.

*/