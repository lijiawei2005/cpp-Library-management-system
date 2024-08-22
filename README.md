# cpp-Library-management-system
入门编程的一个项目作业cpp
# C++ 图书管理系统  
  
## Book 类  
Book类用于表示图书的信息，包含以下字段（字段仅为示例，具体实现可能有所不同）：  
  
- 书名（Title）  
- 作者（Author）  
- 出版日期（PublishDate）  
- ISBN（国际标准书号）  
- 库存数量（StockQuantity）  
  
## BookList 类  
BookList类以链表的形式存放图书信息，并提供以下功能：  
  
- 增加图书（AddBook）  
- 删除图书（DeleteBook）  
- 修改图书信息（UpdateBook）  
- 查询图书（SearchBook）  
  
## BookManager 类  
BookManager类管理图书的整体操作，包括但不限于：  
  
- 增删改查图书信息（通过BookList类实现）  
- 借书操作（BorrowBook）  
- 用户登录（Login）  
  
## Reader 类  
Reader类表示读者信息，包含以下功能：  
  
- 查找图书（SearchBook）  
- 借书（BorrowBook）  
- 用户登录（Login）  
  





