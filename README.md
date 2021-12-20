This is a C++ wrapper for SQLite C API database engine.
It was written to simplify and speedup coding of local database access.

This fork is modified for <b>Cocos2dx</b> engine and cross platform games :)

Old repository https://code.google.com/p/easysqlite/

Why easySQLite solution is better than others ?

  * elegant, objective solution
  * explicit naming and calling
  * uses exceptions or methods return values
  * clear, understandable usage
  * flexible and expandable
  * strongly tested (tests included)
  * Just take a look at sample code.

Find more information in included html file and usage examples in project package.


Platform:

Architecture:        x86_64
CPU op-mode(s):      32-bit, 64-bit
Byte Order:          Little Endian
CPU(s):              4
Model name:          Intel(R) Xeon(R) Platinum 8269CY CPU @ 2.50GHz
CPU MHz:             2500.002

Test in memory mode

insert 
collume_size   insert_count   delay_ms_1(逐条插入)   delay_ms_2(批量插入)  
2                 100W          12987                 11537
3                 100W          14665                 13428   
4                 100W          18587                 15953          
5                 100W          20515                 17970      
6                 100W          22600                 21847    
7                 100W          24936                 23528       
8                 100W          27675                 25995       





对于插入100W条数句，每增加一列数据， 平均增加延迟 2448 ms。





 
 
 
 
 
 
 
 
 
 
 
 





